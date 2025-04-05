#include "BDDSauvegarder.h"
#include "BDDMenu.h"

BDDSauvegarder::BDDSauvegarder(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Sauvegarder, &QPushButton::clicked, this, &BDDSauvegarder::on_Sauvegarder_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &BDDSauvegarder::on_Quitter_triggered);
}
BDDSauvegarder::~BDDSauvegarder()
{
}
void BDDSauvegarder::on_Quitter_triggered()
{
	BDDMenu* fenetreBDDMenu = new BDDMenu(this);
	fenetreBDDMenu->show();
	this->hide();

	connect(fenetreBDDMenu, &BDDMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void BDDSauvegarder::on_Sauvegarder_triggered()
{
	return;
}