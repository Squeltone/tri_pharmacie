#include "MedicamentsSupprimer.h"
#include "MedicamentsMenu.h"

MedicamentsSupprimer::MedicamentsSupprimer(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Quitter, &QPushButton::clicked, this, &MedicamentsSupprimer::on_Quitter_triggered);
	connect(ui.Supprimer, &QPushButton::clicked, this, &MedicamentsSupprimer::on_Supprimer_triggered);
	connect(ui.SupprimerData, &QLineEdit::textChanged, this, &MedicamentsSupprimer::on_SupprimerData_triggered);
}
MedicamentsSupprimer::~MedicamentsSupprimer()
{
}
void MedicamentsSupprimer::on_Quitter_triggered()
{
	MedicamentsMenu* fenetreMedicaments = new MedicamentsMenu(this);
	fenetreMedicaments->show();
	this->hide();

	connect(fenetreMedicaments, &MedicamentsMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void MedicamentsSupprimer::on_Supprimer_triggered()
{
	return;
}
void MedicamentsSupprimer::on_SupprimerData_triggered()
{
	return;
}