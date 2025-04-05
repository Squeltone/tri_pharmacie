#include "MedicamentsMenu.h"
#include "Accueil.h"
#include "MedicamentsAjouter.h"
#include "MedicamentsModifier.h"
#include "MedicamentsSupprimer.h"

MedicamentsMenu::MedicamentsMenu(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Quitter, &QPushButton::clicked, this, &MedicamentsMenu::on_Quitter_triggered);
	connect(ui.Ajouter, &QPushButton::clicked, this, &MedicamentsMenu::on_Ajouter_triggered);
	connect(ui.Modifier, &QPushButton::clicked, this, &MedicamentsMenu::on_Modifier_triggered);
	connect(ui.Supprimer, &QPushButton::clicked, this, &MedicamentsMenu::on_Supprimer_triggered);
}
MedicamentsMenu::~MedicamentsMenu()
{
}
void MedicamentsMenu::on_Quitter_triggered()
{
	Accueil* fenetreAccueil = new Accueil(this);
	fenetreAccueil->show();
	this->hide();

	connect(fenetreAccueil, &Accueil::destroyed, [this]() {
		this->deleteLater();
		});
}
void MedicamentsMenu::on_Ajouter_triggered()
{
	MedicamentsAjouter* fenetreMedicamentsAjouter = new MedicamentsAjouter(this);
	fenetreMedicamentsAjouter->show();
	this->hide();

	connect(fenetreMedicamentsAjouter, &MedicamentsAjouter::destroyed, [this]() {
		this->deleteLater();
		});
}
void MedicamentsMenu::on_Modifier_triggered()
{
	MedicamentsModifier* fenetreMedicamentsModifier = new MedicamentsModifier(this);
	fenetreMedicamentsModifier->show();
	this->hide();

	connect(fenetreMedicamentsModifier, &MedicamentsModifier::destroyed, [this]() {
		this->deleteLater();
		});
}
void MedicamentsMenu::on_Supprimer_triggered()
{
	MedicamentsSupprimer* fenetreMedicamentsSupprimer = new MedicamentsSupprimer(this);
	fenetreMedicamentsSupprimer->show();
	this->hide();

	connect(fenetreMedicamentsSupprimer, &MedicamentsSupprimer::destroyed, [this]() {
		this->deleteLater();
		});
}