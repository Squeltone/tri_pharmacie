#include "Accueil.h"
#include "BDDMenu.h"
#include "MedicamentsMenu.h"
#include "CommandesMenu.h"

Accueil::Accueil(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.BDD, &QPushButton::clicked, this, &Accueil::on_BDD_triggered);
	connect(ui.Commandes, &QPushButton::clicked, this, &Accueil::on_Commandes_triggered);
	connect(ui.Medicaments, &QPushButton::clicked, this, &Accueil::on_Medicaments_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &Accueil::on_Quitter_triggered);
}
Accueil::~Accueil()
{
}
void Accueil::on_BDD_triggered()
{
	BDDMenu* fenetreBDD = new BDDMenu(nullptr);
	fenetreBDD->show();
	this->hide();

	connect(fenetreBDD, &BDDMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void Accueil::on_Commandes_triggered()
{
	CommandesMenu* fenetreCommandes = new CommandesMenu(nullptr);
	fenetreCommandes->show();
	this->hide();

	connect(fenetreCommandes, &CommandesMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void Accueil::on_Medicaments_triggered()
{
	MedicamentsMenu* fenetreMedicaments = new MedicamentsMenu(nullptr);
	fenetreMedicaments->show();
	this->hide();

	connect(fenetreMedicaments, &MedicamentsMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void Accueil::on_Quitter_triggered()
{
	QApplication::quit();
}