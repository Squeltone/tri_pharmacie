#include "BDDCreer.h"
#include "BDDMenu.h"

BDDCreer::BDDCreer(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Creer, &QPushButton::clicked, this, &BDDCreer::on_Creer_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &BDDCreer::on_Quitter_triggered);
}
BDDCreer::~BDDCreer()
{
}
void BDDCreer::on_Creer_triggered()
{
	return;
}
void BDDCreer::on_Quitter_triggered()
{
	BDDMenu* fenetreBDDMenu = new BDDMenu(this);
	fenetreBDDMenu->show();
	this->hide();

	connect(fenetreBDDMenu, &BDDMenu::destroyed, [this]() {
		this->deleteLater();
		});
}