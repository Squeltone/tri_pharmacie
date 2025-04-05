#include "BDDRestaurer.h"
#include "BDDMenu.h"

BDDRestaurer::BDDRestaurer(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Restaurer, &QPushButton::clicked, this, &BDDRestaurer::on_Restaurer_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &BDDRestaurer::on_Quitter_triggered);
}
BDDRestaurer::~BDDRestaurer()
{
}
void BDDRestaurer::on_Restaurer_triggered()
{
	return;
}
void BDDRestaurer::on_Quitter_triggered()
{
	BDDMenu* fenetreBDDMenu = new BDDMenu(this);
	fenetreBDDMenu->show();
	this->hide();

	connect(fenetreBDDMenu, &BDDMenu::destroyed, [this]() {
		this->deleteLater();
		});
}