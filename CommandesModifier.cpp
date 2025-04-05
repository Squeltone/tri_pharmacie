#include "CommandesModifier.h"
#include "CommandesMenu.h"

CommandesModifier::CommandesModifier(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Quitter, &QPushButton::clicked, this, &CommandesModifier::on_Quitter_triggered);
}
CommandesModifier::~CommandesModifier()
{
}
void CommandesModifier::on_Quitter_triggered()
{
	CommandesMenu* fenetreCommandes = new CommandesMenu(this);
	fenetreCommandes->show();
	this->hide();

	connect(fenetreCommandes, &CommandesMenu::destroyed, [this]() {
		this->deleteLater();
		});
}