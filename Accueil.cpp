#include "Accueil.h"
#include "BDDMenu.h"
#include "CommandesMenu.h"
#include "MedicamentMenu.h"

Accueil::Accueil(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.AccueilBaseDeDonnees, &QPushButton::clicked, this, &Accueil::on_AccueilBaseDeDonnees_triggered);
	connect(ui.AccueilCommandes, &QPushButton::clicked, this, &Accueil::on_AccueilCommandes_triggered);
	connect(ui.AccueilMedicaments, &QPushButton::clicked, this, &Accueil::on_AccueilMedicaments_triggered);
	connect(ui.AccueilQuitter, &QPushButton::clicked, this, &Accueil::on_AccueilQuitter_triggered);
	
	void on_AccueilBaseDeDonnees_triggered();
	{
		FenetreBDD* fenetreBDD = new FenetreBDD(this);
		fenetreBDD->show();
		this->close();
	}
	void on_AccueilCommandes_triggered();
	{
		FenetreCommandes* fenetreCommandes = new FenetreCommandes(this);
		fenetreCommandes->show();
		this->close();
	}
	void on_AccueilMedicaments_triggered();
	{
		FenetreMedicaments* fenetreMedicaments = new FenetreMedicaments(this);
		fenetreMedicaments->show();
		this->close();
	}
	void on_AccueilQuitter_triggered();
	{
		QApplication::quit();
	}
}