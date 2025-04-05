#include "MedicamentsModifier.h"
#include "MedicamentsMenu.h"

MedicamentsModifier::MedicamentsModifier(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();
	connect(ui.Quitter, &QPushButton::clicked, this, &MedicamentsModifier::on_Quitter_triggered);
}
MedicamentsModifier::~MedicamentsModifier()
{
}
void MedicamentsModifier::on_Quitter_triggered()
{
	MedicamentsMenu* fenetreMedicaments = new MedicamentsMenu(this);
	fenetreMedicaments->show();
	this->hide();

	connect(fenetreMedicaments, &MedicamentsMenu::destroyed, [this]() {
		this->deleteLater();
		});
}