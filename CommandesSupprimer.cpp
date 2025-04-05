#include "CommandesSupprimer.h"
#include "CommandesMenu.h"

CommandesSupprimer::CommandesSupprimer(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Quitter, &QPushButton::clicked, this, &CommandesSupprimer::on_Quitter_triggered);
}
CommandesSupprimer::~CommandesSupprimer()
{
}
void CommandesSupprimer::on_Quitter_triggered()
{
	CommandesMenu* fenetreCommandes = new CommandesMenu(this);
	fenetreCommandes->show();
	this->hide();

	connect(fenetreCommandes, &CommandesMenu::destroyed, [this]() {
		this->deleteLater();
		});
}