#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>
#include <QTimer>
#include "ui_MainWindow.h"
#include "DatabaseManager.h"
#include <QCheckBox>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private slots:
	// Slots pour les actions de base de données
	void on_actionBDDCreation_triggered();
	void on_actionBDDSuppression_triggered();
	void on_actionBDDSauvegarde_triggered();
	void on_actionBDDRestauration_triggered();
	void on_actionBDDConsultation_triggered();
	void on_BoxStockBDDConsultation_stateChanged(int state);

	// Slots pour les actions de médicaments
	void on_actionMedicamentsAjouter_triggered();
	void on_actionMedicamentsSupprimer_triggered();
	void on_actionMedicamentsModifier_triggered();

	// Slots pour les actions de commande
	void on_actionCommandeCreation_triggered();
	void on_actionCommandeSuppression_triggered();
	void on_actionCommandeModification_triggered();
	void on_actionCommandeConsultation_triggered();

	// Slots pour les actions d'accueil
	void on_actionAccueilBilanfinancier_triggered();
	void on_actionAccueilEtatdutapis_triggered();
	void on_actionAccueilDeconnexion_triggered();

	// Autres slots
	void on_stackedWidget_currentChanged(int index);
	void on_BDDRecherce_textChanged(const QString& text);
	void on_BoutonBBDCreation_clicked();
	void performFilteringSearch();

private:
	Ui::MainWindow ui;
	QStandardItemModel* tableModel;
	DatabaseManager* dbManager;
	QTimer* searchTimer;
	QString currentSearchText;
	QString currentTableName;

	void loadTableData(const QString& tableName);
	void filterTableData(const QString& tableName, const QString& filterText);
};
//class bdd : public bdd
//{
//	Q_OBJECT
//
//public:
//	bdd();
//	~bdd();
//
//private slots:
//	// Slots pour les actions de base de données
//	void on_actionBDDCreation_triggered();
//	void on_actionBDDSuppression_triggered();
//	void on_actionBDDSauvegarde_triggered();
//	void on_actionBDDRestauration_triggered();
//	void on_actionBDDConsultation_triggered();
//	void on_BoxStockBDDConsultation_stateChanged(int state);
//};



#endif // !MAINWINDOW_H