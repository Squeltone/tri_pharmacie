#include "MainWindow.h"
#include "DatabaseManager.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QCheckBox>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent), tableModel(new QStandardItemModel(this))
{
	ui.setupUi(this);
	this->showMaximized();
	ui.stackedWidget->setCurrentWidget(ui.page_);

	dbManager = new DatabaseManager();
	tableModel = new QStandardItemModel(this);
	ui.TableauBDDConsultation->setModel(tableModel);
	ui.TableauBDDConsultation->verticalHeader()->setVisible(false);

	// Initialisation du timer pour le debounce
	searchTimer = new QTimer(this);
	searchTimer->setSingleShot(true); // Le timer s'exécute une seule fois
	connect(searchTimer, &QTimer::timeout, this, &MainWindow::performFilteringSearch);

	// Connexion des actions du menu Base de données
	connect(ui.actionBDDCreation, &QAction::triggered, this, &MainWindow::on_actionBDDCreation_triggered);
	connect(ui.actionBDDSuppression, &QAction::triggered, this, &MainWindow::on_actionBDDSuppression_triggered);
	connect(ui.actionBDDSauvegarde, &QAction::triggered, this, &MainWindow::on_actionBDDSauvegarde_triggered);
	connect(ui.actionBDDRestauration, &QAction::triggered, this, &MainWindow::on_actionBDDRestauration_triggered);
	connect(ui.actionBDDConsultation, &QAction::triggered, this, &MainWindow::on_actionBDDConsultation_triggered);
	connect(ui.BoxStockBDDConsultation, &QCheckBox::checkStateChanged, this, &MainWindow::on_BoxStockBDDConsultation_stateChanged);

	// Connexion des actions du menu Médicaments
	connect(ui.actionMedicamentsAjouter, &QAction::triggered, this, &MainWindow::on_actionMedicamentsAjouter_triggered);
	connect(ui.actionMedicamentsSupprimer, &QAction::triggered, this, &MainWindow::on_actionMedicamentsSupprimer_triggered);
	connect(ui.actionMedicamentsModifier, &QAction::triggered, this, &MainWindow::on_actionMedicamentsModifier_triggered);

	// Connexion des actions du menu Commande
	connect(ui.actionCommandeCreation, &QAction::triggered, this, &MainWindow::on_actionCommandeCreation_triggered);
	connect(ui.actionCommandeSuppression, &QAction::triggered, this, &MainWindow::on_actionCommandeSuppression_triggered);
	connect(ui.actionCommandeModification, &QAction::triggered, this, &MainWindow::on_actionCommandeModification_triggered);
	connect(ui.actionCommandeConsultation, &QAction::triggered, this, &MainWindow::on_actionCommandeConsultation_triggered);

	// Connexion des actions du menu Accueil
	connect(ui.actionAccueilBilanfinancier, &QAction::triggered, this, &MainWindow::on_actionAccueilBilanfinancier_triggered);
	connect(ui.actionAccueilEtatdutapis, &QAction::triggered, this, &MainWindow::on_actionAccueilEtatdutapis_triggered);
	connect(ui.actionAccueilDeconnexion, &QAction::triggered, this, &MainWindow::on_actionAccueilDeconnexion_triggered);

	// Autres connexions
	connect(ui.BDDRecherce, &QLineEdit::textChanged, this, &MainWindow::on_BDDRecherce_textChanged);
	connect(ui.stackedWidget, &QStackedWidget::currentChanged, this, &MainWindow::on_stackedWidget_currentChanged);
	connect(ui.BoutonBBDCreation, &QPushButton::clicked, this, &MainWindow::on_BoutonBBDCreation_clicked);
}

MainWindow::~MainWindow()
{
	delete dbManager;
}

// Slots pour les actions de menu Base de données
void MainWindow::on_actionBDDCreation_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageBDDCreation);
	ui.statusbar->showMessage("Création d'une base de données");
}

void MainWindow::on_actionBDDSuppression_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageBDDSuppression);
	ui.statusbar->showMessage("Suppression d'une base de données");
}

void MainWindow::on_actionBDDSauvegarde_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageBDDSauvegarde);
	ui.statusbar->showMessage("Sauvegarde de la base de données");
}

void MainWindow::on_actionBDDRestauration_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageBDDRestauration);
	ui.statusbar->showMessage("Restauration de la base de données");
}

void MainWindow::on_actionBDDConsultation_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageBDDConsultation);
	ui.statusbar->showMessage("Consultation de la base de données");
	loadTableData("Entrepot");
}

void MainWindow::on_BoxStockBDDConsultation_stateChanged(int state)
{
	// Recharger les données en fonction de l'état de la checkbox
	loadTableData(currentTableName);
}

// Slots pour les actions de menu Médicaments
void MainWindow::on_actionMedicamentsAjouter_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageMedicamentsAjouter);
	ui.statusbar->showMessage("Ajout de médicaments");
}

void MainWindow::on_actionMedicamentsSupprimer_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageMedicamentsSupprimer);
	ui.statusbar->showMessage("Suppression de médicaments");
}

void MainWindow::on_actionMedicamentsModifier_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageMedicamentsModifier);
	ui.statusbar->showMessage("Modification de médicaments");
}

// Slots pour les actions de menu Commande
void MainWindow::on_actionCommandeCreation_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageCommandeCreation);
	ui.statusbar->showMessage("Création d'une commande");
}

void MainWindow::on_actionCommandeSuppression_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageCommandeSuppression);
	ui.statusbar->showMessage("Suppression d'une commande");
}

void MainWindow::on_actionCommandeModification_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageCommandeModification);
	ui.statusbar->showMessage("Modification d'une commande");
}

void MainWindow::on_actionCommandeConsultation_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageCommandeConsultation);
	ui.statusbar->showMessage("Consultation des commandes");
	loadTableData("Commandes");
}

// Slots pour les actions de menu Accueil
void MainWindow::on_actionAccueilBilanfinancier_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageAccueilBilanfinancier);
	ui.statusbar->showMessage("Bilan financier");
}

void MainWindow::on_actionAccueilEtatdutapis_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageAccueilEtatdutapis);
	ui.statusbar->showMessage("État du tapis en cours de chargement");
}

void MainWindow::on_actionAccueilDeconnexion_triggered()
{
	ui.stackedWidget->setCurrentWidget(ui.pageAccueilDeconnexion);
	ui.statusbar->showMessage("Déconnexion");
}

// Autres slots
void MainWindow::on_stackedWidget_currentChanged(int index)
{
	if (ui.stackedWidget->widget(index)->objectName() == "pageBDDConsultation") {
		loadTableData("Entrepot");
	}
}

void MainWindow::on_BDDRecherce_textChanged(const QString& text)
{
	// Le nom de la table à afficher dépend de la page actuelle
	currentTableName = "Entrepot"; // Table par défaut

	// Si nous sommes sur la page de consultation des commandes
	if (ui.stackedWidget->currentWidget() == ui.pageCommandeConsultation) {
		currentTableName = "Commandes";
	}

	// Stockage du texte actuel
	currentSearchText = text;

	// Mettre à jour la barre d'état pour indiquer que la recherche est en cours
	if (!text.isEmpty()) {
		ui.statusbar->showMessage("Saisie en cours... " + text);
	}

	// Arrêter le timer s'il est en cours
	if (searchTimer->isActive()) {
		searchTimer->stop();
	}

	// Si le texte est vide, charger toutes les données immédiatement
	if (text.isEmpty()) {
		loadTableData(currentTableName);
	}
	else {
		// Sinon, démarrer le timer (300 ms est un délai raisonnable)
		searchTimer->start(300);
	}
}

void MainWindow::performFilteringSearch()
{
	// Cette méthode est appelée quand le timer expire
	if (currentSearchText.isEmpty()) {
		loadTableData(currentTableName);
	}
	else {
		// Filtrer les données selon le texte saisi
		filterTableData(currentTableName, currentSearchText);
		ui.statusbar->showMessage("Recherche: " + currentSearchText);
	}
}

void MainWindow::filterTableData(const QString& tableName, const QString& filterText)
{
	// Vider le modèle actuel
	tableModel->clear();

	// Connexion à la base de données
	if (!dbManager->connect("192.168.64.177", "pharmacie", "root", "PHARMACIE")) {
		QMessageBox::critical(this, "Erreur de connexion",
			"Impossible de se connecter à la base de données: " + dbManager->getLastError());
		return;
	}

	// Exécuter la requête pour récupérer les données filtrées
	MYSQL* conn = dbManager->getConnection();
	if (!conn) {
		QMessageBox::critical(this, "Erreur de connexion",
			"Connexion MySQL invalide: " + dbManager->getLastError());
		return;
	}

	// Échapper les caractères spéciaux dans le texte de recherche pour éviter les injections SQL
	char* escapedText = new char[filterText.length() * 2 + 1];
	mysql_real_escape_string(conn, escapedText, filterText.toUtf8().constData(), filterText.length());
	QString safeFilterText = QString::fromUtf8(escapedText);
	delete[] escapedText;

	// Récupération des informations sur les colonnes pour construire la clause WHERE
	QString columnsQuery = "SHOW COLUMNS FROM " + tableName;
	if (mysql_query(conn, columnsQuery.toStdString().c_str())) {
		QMessageBox::critical(this, "Erreur de requête",
			"Erreur lors de la récupération des colonnes: " + QString(mysql_error(conn)));
		return;
	}

	MYSQL_RES* columnsResult = mysql_store_result(conn);
	if (!columnsResult) {
		QMessageBox::critical(this, "Erreur de résultat",
			"Erreur lors de la récupération des colonnes: " + QString(mysql_error(conn)));
		return;
	}

	// Construction de la clause WHERE pour rechercher dans toutes les colonnes
	QStringList conditions;
	MYSQL_ROW columnRow;
	while ((columnRow = mysql_fetch_row(columnsResult))) {
		QString columnName = columnRow[0];
		// Convertir la colonne en chaîne de caractères pour la recherche
		if (columnName == "disponibilite") {
			if (safeFilterText == "en stock") {
				conditions.append("CAST(" + columnName + " AS CHAR) LIKE '1'");
			}
			else if (safeFilterText == "plus de stock") {
				conditions.append("CAST(" + columnName + " AS CHAR) LIKE '0'");
			}
			else {
				conditions.append("CAST(" + columnName + " AS CHAR) LIKE '%" + safeFilterText + "%'");
			}
		}
		else {
			conditions.append("CAST(" + columnName + " AS CHAR) LIKE '%" + safeFilterText + "%'");
		}
	}
	mysql_free_result(columnsResult);

	// Assemblage de la requête finale
	QString query = "SELECT * FROM " + tableName + " WHERE " + conditions.join(" OR ");
	if (ui.BoxStockBDDConsultation->isChecked()) {
		query += " AND disponibilite = 1";
	}

	if (mysql_query(conn, query.toStdString().c_str())) {
		QMessageBox::critical(this, "Erreur de requête",
			"Erreur lors de l'exécution de la requête: " + QString(mysql_error(conn)));
		return;
	}

	// Récupération des résultats
	MYSQL_RES* result = mysql_store_result(conn);
	if (!result) {
		QMessageBox::critical(this, "Erreur de résultat",
			"Erreur lors de la récupération des résultats: " + QString(mysql_error(conn)));
		return;
	}

	// Récupération des informations sur les colonnes
	int numFields = mysql_num_fields(result);
	MYSQL_FIELD* fields = mysql_fetch_fields(result);

	// Configuration des en-têtes de colonne
	QStringList headers;
	for (int i = 0; i < numFields; ++i) {
		headers.append(QString::fromUtf8(fields[i].name));
	}
	tableModel->setHorizontalHeaderLabels(headers);

	// Remplissage du tableau avec les données
	int row = 0;
	MYSQL_ROW mysqlRow;
	while ((mysqlRow = mysql_fetch_row(result))) {
		for (int col = 0; col < numFields; ++col) {
			QString value = mysqlRow[col] ? QString::fromUtf8(mysqlRow[col]) : "NULL";
			if (fields[col].name == std::string("disponibilite")) {
				if (value == "1") {
					value = "en stock";
				}
				else if (value == "0") {
					value = "plus de stock";
				}
			}
			QStandardItem* item = new QStandardItem(value);
			tableModel->setItem(row, col, item);
		}
		row++;
	}

	// Libération de la mémoire
	mysql_free_result(result);

	// Ajuster la taille des colonnes
	ui.TableauBDDConsultation->resizeColumnsToContents();

	// Message de statut
	ui.statusbar->showMessage(QString("Recherche \"%1\" dans %2: %3 enregistrements trouvés")
		.arg(filterText).arg(tableName).arg(row));
}


void MainWindow::on_BoutonBBDCreation_clicked()
{
	// Implémentation à venir
	return;
}

void MainWindow::loadTableData(const QString& tableName)
{
	// Vider le modèle actuel
	tableModel->clear();

	// Connexion à la base de données
	if (!dbManager->connect("192.168.64.177", "pharmacie", "root", "PHARMACIE")) {
		QMessageBox::critical(this, "Erreur de connexion",
			"Impossible de se connecter à la base de données: " + dbManager->getLastError());
		return;
	}

	// Exécuter la requête pour récupérer toutes les données de la table
	MYSQL* conn = dbManager->getConnection();
	if (!conn) {
		QMessageBox::critical(this, "Erreur de connexion",
			"Connexion MySQL invalide: " + dbManager->getLastError());
		return;
	}

	// Création de la requête SQL
	QString query = "SELECT * FROM " + tableName;
	if (ui.BoxStockBDDConsultation->isChecked()) {
		query += " WHERE disponibilite = 1";
	}
	if (mysql_query(conn, query.toStdString().c_str())) {
		QMessageBox::critical(this, "Erreur de requête",
			"Erreur lors de l'exécution de la requête: " + QString(mysql_error(conn)));
		return;
	}

	// Récupération des résultats
	MYSQL_RES* result = mysql_store_result(conn);
	if (!result) {
		QMessageBox::critical(this, "Erreur de résultat",
			"Erreur lors de la récupération des résultats: " + QString(mysql_error(conn)));
		return;
	}

	// Récupération des informations sur les colonnes
	int numFields = mysql_num_fields(result);
	MYSQL_FIELD* fields = mysql_fetch_fields(result);

	// Configuration des en-têtes de colonne
	QStringList headers;
	for (int i = 0; i < numFields; ++i) {
		headers.append(QString::fromUtf8(fields[i].name));
	}
	tableModel->setHorizontalHeaderLabels(headers);

	// Remplissage du tableau avec les données
	int row = 0;
	MYSQL_ROW mysqlRow;
	while ((mysqlRow = mysql_fetch_row(result))) {
		for (int col = 0; col < numFields; ++col) {
			QString value = mysqlRow[col] ? QString::fromUtf8(mysqlRow[col]) : "NULL";
			if (fields[col].name == std::string("disponibilite")) {
				if (value == "1") {
					value = "en stock";
				}
				else if (value == "0") {
					value = "plus de stock";
				}
			}
			QStandardItem* item = new QStandardItem(value);
			tableModel->setItem(row, col, item);
		}
		row++;
	}

	// Libération de la mémoire
	mysql_free_result(result);

	// Ajuster la taille des colonnes
	ui.TableauBDDConsultation->resizeColumnsToContents();

	// Message de statut
	ui.statusbar->showMessage(QString("Table %1: %2 enregistrements trouvés").arg(tableName).arg(row));
}