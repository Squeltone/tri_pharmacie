#include "Projet.h"
#include "DatabaseManager.h"
#include <QMessageBox>

Projet::Projet(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	dbManager = new DatabaseManager();
	tableModel = new QStandardItemModel(this);
	ui.bddinfo->setModel(tableModel);
	ui.bddinfo->verticalHeader()->setVisible(false);
	connect(ui.testConnectionButton, &QPushButton::clicked, this, &Projet::on_testConnectionButton_clicked);
	connect(ui.reset, &QPushButton::clicked, this, &Projet::on_resetButton_clicked);
}

Projet::~Projet()
{
	delete dbManager;
}

void Projet::on_testConnectionButton_clicked()
{
	QString host = ui.hotetxt->text();
	QString user = ui.utilisateurtxt->text();
	QString password = ui.motdepassetxt->text();
	QString dbName = ui.nombddtxt->text();

	ui.infoconnexion->setText("Connexion en cours à " + host + " à la base de donnée " + dbName + " sous le nom de " + user + "...");

	dbManager->connect(host, user, password, dbName);

	bool connectionResult = dbManager->isConnected();

	if (connectionResult) {
		ui.statusLabel->setText("Status: Connexion réussie " + dbManager->getLastError());
		ui.statusLabel->setStyleSheet("color: green;");
		loadTableData(dbName);
	}
	else {
		ui.statusLabel->setText("Status: Échec de connexion :" + dbManager->getLastError());
		ui.statusLabel->setStyleSheet("color: red;");
	}
}
void Projet::on_resetButton_clicked()
{
	ui.hotetxt->clear();
	ui.utilisateurtxt->clear();
	ui.motdepassetxt->clear();
	ui.nombddtxt->clear();
	ui.infoconnexion->setText("Entrez les informations de connexion...");
	ui.statusLabel->setText("Status: Non testé");
	ui.statusLabel->setStyleSheet("");
	dbManager->disconnect();
}
void Projet::loadTableData(const QString& tableName)
{
	// Récupération de la connexion MySQL
	MYSQL* conn = dbManager->getConnection();
	if (!conn) {
		ui.infoconnexion->setText("Erreur: Pas de connexion active");
		return;
	}

	// Création de la requête
	QString query = "SELECT * FROM " + tableName;

	// Exécution de la requête
	if (mysql_query(conn, query.toStdString().c_str())) {
		ui.infoconnexion->setText("Erreur de requête: " + QString(mysql_error(conn)));
		return;
	}

	// Récupération des résultats
	MYSQL_RES* result = mysql_store_result(conn);
	if (!result) {
		ui.infoconnexion->setText("Erreur de récupération des résultats: " + QString(mysql_error(conn)));
		return;
	}

	// Récupération des informations sur les colonnes
	int numFields = mysql_num_fields(result);
	MYSQL_FIELD* fields = mysql_fetch_fields(result);

	// Configuration des en-têtes du modèle
	tableModel->clear();
	QStringList headers;
	for (int i = 0; i < numFields; i++) {
		headers << QString(fields[i].name);
	}
	tableModel->setHorizontalHeaderLabels(headers);

	// Récupération des données
	int rowCount = 0;
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
		for (int i = 0; i < numFields; i++) {
			QString value = row[i] ? QString(row[i]) : "NULL";
			QStandardItem* item = new QStandardItem(value);
			tableModel->setItem(rowCount, i, item);
		}
		rowCount++;
	}

	// Libération des ressources
	mysql_free_result(result);

	ui.infoconnexion->setText("Données chargées depuis la table " + tableName);
}