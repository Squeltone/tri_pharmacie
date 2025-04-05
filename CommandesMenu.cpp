#include "CommandesMenu.h"
#include "Accueil.h"
#include "CommandesCreer.h"
#include "CommandesConsulter.h"
#include "CommandesModifier.h"
#include "CommandesSupprimer.h"

CommandesMenu::CommandesMenu(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Creer, &QPushButton::clicked, this, &CommandesMenu::on_Creer_triggered);
	connect(ui.Modifier, &QPushButton::clicked, this, &CommandesMenu::on_Modifier_triggered);
	connect(ui.Supprimer, &QPushButton::clicked, this, &CommandesMenu::on_Supprimer_triggered);
	connect(ui.Consulter, &QPushButton::clicked, this, &CommandesMenu::on_Consulter_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &CommandesMenu::on_Quitter_triggered);
}
CommandesMenu::~CommandesMenu()
{
}
void CommandesMenu::on_Creer_triggered()
{
	CommandesCreer* fenetreCommandesCreer = new CommandesCreer(this);
	fenetreCommandesCreer->show();
	this->hide();

	connect(fenetreCommandesCreer, &CommandesCreer::destroyed, [this]() {
		this->show();
		});
}
void CommandesMenu::on_Modifier_triggered()
{
	CommandesModifier* fenetreCommandesModifier = new CommandesModifier(this);
	fenetreCommandesModifier->show();
	this->hide();

	connect(fenetreCommandesModifier, &CommandesModifier::destroyed, [this]() {
		this->show();
		});
}
void CommandesMenu::on_Supprimer_triggered()
{
	CommandesSupprimer* fenetreCommandesSupprimer = new CommandesSupprimer(this);
	fenetreCommandesSupprimer->show();
	this->hide();

	connect(fenetreCommandesSupprimer, &CommandesSupprimer::destroyed, [this]() {
		this->show();
		});
}
void CommandesMenu::on_Consulter_triggered()
{
	CommandesConsulter* fenetreCommandesConsulter = new CommandesConsulter(this);
	fenetreCommandesConsulter->show();
	this->hide();

	connect(fenetreCommandesConsulter, &CommandesConsulter::destroyed, [this]() {
		this->show();
		});
}
void CommandesMenu::on_Quitter_triggered()
{
	Accueil* accueil = new Accueil(this);
	accueil->show();
	this->hide();

	connect(accueil, &Accueil::destroyed, [this]() {
		this->deleteLater();
		});
}