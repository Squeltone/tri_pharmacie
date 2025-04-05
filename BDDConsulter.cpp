#include "BDDConsulter.h"
#include "BDDMenu.h"

BDDConsulter::BDDConsulter(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.BDD, &QTableView::clicked, this, &BDDConsulter::on_BDD_triggered);
	connect(ui.Recherche, &QLineEdit::textChanged, this, &BDDConsulter::on_Recherche_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &BDDConsulter::on_Quitter_triggered);
	connect(ui.Stock, &QCheckBox::toggled, this, &BDDConsulter::on_Stock_triggered);
}
BDDConsulter::~BDDConsulter()
{
}
void BDDConsulter::on_BDD_triggered()
{
	return;
}
void BDDConsulter::on_Recherche_triggered()
{
	return;
}
void BDDConsulter::on_Quitter_triggered()
{
	BDDMenu* fenetreBDDMenu = new BDDMenu(this);
	fenetreBDDMenu->show();
	this->hide();

	connect(fenetreBDDMenu, &BDDMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void BDDConsulter::on_Stock_triggered()
{
	return;
}