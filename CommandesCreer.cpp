#include "CommandesCreer.h"
#include "CommandesMenu.h"

CommandesCreer::CommandesCreer(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Commander, &QPushButton::clicked, this, &CommandesCreer::on_Commander_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &CommandesCreer::on_Quitter_triggered);
	connect(ui.MedicamentData, &QLineEdit::textChanged, this, &CommandesCreer::on_Medicament_triggered);
	connect(ui.QuantiteeData, &QSpinBox::textChanged, this, &CommandesCreer::on_Quantitee_triggered);
	connect(ui.NomData, &QLineEdit::textChanged, this, &CommandesCreer::on_Nom_triggered);
}
CommandesCreer::~CommandesCreer()
{
}
void CommandesCreer::on_Commander_triggered()
{
	return;
}
void CommandesCreer::on_Quitter_triggered()
{
	CommandesMenu* fenetreCommandesMenu = new CommandesMenu(this);
	fenetreCommandesMenu->show();
	this->hide();

	connect(fenetreCommandesMenu, &CommandesMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void CommandesCreer::on_Medicament_triggered()
{
	return;
}
void CommandesCreer::on_Quantitee_triggered()
{
	return;
}
void CommandesCreer::on_Nom_triggered()
{
	return;
}