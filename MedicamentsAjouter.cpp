#include "MedicamentsAjouter.h"
#include "MedicamentsMenu.h"

MedicamentsAjouter::MedicamentsAjouter(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.Quitter, &QPushButton::clicked, this, &MedicamentsAjouter::on_Quitter_triggered);
	connect(ui.Ajouter, &QPushButton::clicked, this, &MedicamentsAjouter::on_Ajouter_triggered);
	connect(ui.NomData, &QLineEdit::textChanged, this, &MedicamentsAjouter::on_NomData_triggered);
	connect(ui.DescriptionData, &QLineEdit::textChanged, this, &MedicamentsAjouter::on_DescriptionData_triggered);
	connect(ui.CategorieData, &QLineEdit::textChanged, this, &MedicamentsAjouter::on_CategorieData_triggered);
	connect(ui.PrixData, &QDoubleSpinBox::textChanged, this, &MedicamentsAjouter::on_PrixData_triggered);
	connect(ui.StockData, &QSpinBox::textChanged, this, &MedicamentsAjouter::on_StockData_triggered);
}
MedicamentsAjouter::~MedicamentsAjouter()
{
}
void MedicamentsAjouter::on_Quitter_triggered()
{
	MedicamentsMenu* fenetreMedicaments = new MedicamentsMenu(this);
	fenetreMedicaments->show();
	this->hide();

	connect(fenetreMedicaments, &MedicamentsMenu::destroyed, [this]() {
		this->deleteLater();
		});
}
void MedicamentsAjouter::on_Ajouter_triggered()
{
	return;
}
void MedicamentsAjouter::on_NomData_triggered()
{
	return;
}
void MedicamentsAjouter::on_DescriptionData_triggered()
{
	return;
}
void MedicamentsAjouter::on_CategorieData_triggered()
{
	return;
}
void MedicamentsAjouter::on_PrixData_triggered()
{
	return;
}
void MedicamentsAjouter::on_StockData_triggered()
{
	return;
}