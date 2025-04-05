#include "CommandesConsulter.h"
#include "CommandesMenu.h"

CommandesConsulter::CommandesConsulter(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Recherche, &QLineEdit::textChanged, this, &CommandesConsulter::on_Recherche_triggered);
	connect(ui.EnAttente, &QRadioButton::toggled, this, &CommandesConsulter::on_EnAttente_triggered);
	connect(ui.EnCours, &QRadioButton::toggled, this, &CommandesConsulter::on_EnCours_triggered);
	connect(ui.Terminer, &QRadioButton::toggled, this, &CommandesConsulter::on_Termine_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &CommandesConsulter::on_Quitter_triggered);
	connect(ui.BDD, &QTableView::clicked, this, &CommandesConsulter::on_BDD_triggered);
}
CommandesConsulter::~CommandesConsulter()
{
}
void CommandesConsulter::on_Recherche_triggered()
{
	return;
}
void CommandesConsulter::on_EnAttente_triggered()
{
	return;
}
void CommandesConsulter::on_EnCours_triggered()
{
	return;
}
void CommandesConsulter::on_Termine_triggered()
{
	return;
}
void CommandesConsulter::on_Quitter_triggered()
{
	CommandesMenu* fenetreCommandesMenu = new CommandesMenu(this);
	fenetreCommandesMenu->show();
	this->hide();

	connect(fenetreCommandesMenu, &CommandesMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void CommandesConsulter::on_BDD_triggered()
{
	return;
}