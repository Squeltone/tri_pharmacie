#include "BDDSupprimer.h"
#include "BDDMenu.h"

BDDSupprimer::BDDSupprimer(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Supprimer, &QPushButton::clicked, this, &BDDSupprimer::on_Supprimer_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &BDDSupprimer::on_Quitter_triggered);
}
BDDSupprimer::~BDDSupprimer()
{
}
void BDDSupprimer::on_Supprimer_triggered()
{
	return;
}
void BDDSupprimer::on_Quitter_triggered()
{
	BDDMenu* fenetreBDDMenu = new BDDMenu(this);
	fenetreBDDMenu->show();
	this->hide();

	connect(fenetreBDDMenu, &BDDMenu::destroyed, [this]() {
		this->deleteLater();
		});
}