#ifndef MAIN_H
#define MAIN_H

#include <QtWidgets/QMainWindow>
#include "ui_Accueil.h"

class MedicamentsMenu : public QMainWindow
{
	Q_OBJECT

public:
	explicit MedicamentsMenu(QWidget* parent = nullptr);
	~MedicamentsMenu();

private:
	Ui::Accueil ui;
};

class BaseDeDonnees : public QMainWindow
{
	Q_OBJECT

public:
	explicit BaseDeDonnees(QWidget* parent = nullptr);
	~BaseDeDonnees();

private:
	Ui::Accueil ui;
};

class Commandes : public QMainWindow
{
	Q_OBJECT

public:
	explicit Commandes(QWidget* parent = nullptr);
	~Commandes();

private:
	Ui::Accueil ui;
};


class Main : public QMainWindow
{
	Q_OBJECT

public:
	Main(QWidget* parent = nullptr);
	~Main();

private slots:
	// Slots pour les actions Accueil
	void on_AccueilBaseDeDonnees_triggered();
	void on_AccueilMedicaments_triggered();
	void on_AccueilCommandes_triggered();
	void on_AccueilQuitter_triggered();

	//// Slots relatif aux actions Medicaments
	//	// Slots pour les actions MedicamentsMenu
	//void on_MenuMedicamentAjouterMedicament_triggered();
	//void on_MenuMedicamentModifierMedicament_triggered();
	//void on_MenuMedicamentSupprimerMedicament_triggered();
	//void on_MenuMedicamentQuitter_triggered();

	//// Slots pour les actions MedicamentsAjouter
	//void on_AjouterMedicamentAjouterMedicament_triggered();
	//void on_AjouterMedicamentNomData();
	//void on_AjouterMedicamentDescriptionData();
	//void on_AjouterMedicamentCategorieData();
	//void on_AjouterMedicamentPrixData();
	//void on_AjouterMedicamentStockData();
	//void on_AjouterMedicamentAjouterMedicament();
	//void on_AjouterMedicamentQuitter_triggered();

	//// Slots pour les actions MedicamentsModifier
	//void on_ModifierMedicamentQuitter_triggered();

	//// Slots pour les actions MedicamentsSupprimer
	//void on_SupprimerMedicamentsSupprimerMedicament_triggered();
	//void on_SupprimerMedicamentsQuitter_triggered();
	//void on_SupprimerMedicamentSuppressionData();

	//// Slots relatif aux actions Commandes
	//	// Slots pour les actions CommandesMenu
	//void on_CommandesMenuCreer_triggered();
	//void on_CommandesMenuSupprimer_triggered();
	//void on_CommandesMenuModifier_triggered();
	//void on_CommandesMenuConsutler_triggered();
	//void on_CommandesMenuQuitter_triggered();

	//// Slots pour les actions CommandesCreer
	//void on_CommandesCreerNomData();
	//void on_CommandesCreerDescriptionData();
	//void on_CommandesCreerCategorieData();
	//void on_CommandesCreerPrixData();
	//void on_CommandesCreerQuantiteData();
	//void on_CommandesCreerAjouterCommande();
	//void on_CommandesCreerQuitter_triggered();

	//// Slots pour les actions CommandesModifier
	//void on_CommandesModifierQuitter_triggered();

	//// Slots pour les actions CommandesSupprimer
	//void on_CommandesSupprierQuitter_triggered();

	//// Slots pour les actions CommandesConsulter
	//void on_CommandeConsulterRechercheData();
	//void on_CommandeConsulterEnAttente_triggered();
	//void on_CommandeConsulterEnCours_triggered();
	//void on_CommandeConsulterTerminer_triggered();
	//void on_CommandeConsulterQuitter_triggered();

	//// Slots relatif aux actions BDD
	//	// Slots pour les actions BDDMenu
	//void on_BDDCreerBDD_triggered();
	//void on_BDDSupprimerBDD_triggered();
	//void on_BDDSauvegarderBDD_triggered();
	//void on_BDDRestaurerBDD_triggered();
	//void on_BDDConsulterBDD_triggered();
	//void on_BDDQuitter_triggered();

	//// Slots pour les actions BDDCreer
	//void on_BDDCreerCreer_triggered();
	//void on_BDDCreerQuitter_triggered();

	//// Slots pour les actions BDDSauvegarder
	//void on_BDDSauvegarderSauvegarder_clicked();
	//void on_BDDSauvegarderQuitter_clicked();

	//// Slots pour les actions BDDRestaurer
	//void on_BDDRestaurerRestaurer_clicked();
	//void on_BDDRestaurerQuitter_clicked();

	//// Slots pour les actions BDDSupprimer
	//void on_BDDSupprimerSupprimer_clicked();
	//void on_BDDSupprimerQuitter_clicked();

	//// Slots pour les actions BDDConsulter
	//void on_BDDConsulterRecherche_textChanged(const QString& text);
	//void on_BDDConsulterQuitter_clicked();
	//void on_Stock_stateChanged(int state);

private:
	Ui::Accueil ui;
};

#endif // MAIN_H;