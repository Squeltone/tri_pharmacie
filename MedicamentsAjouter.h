#pragma once

#include "ui_MedicamentsAjouter.h"


class MedicamentsAjouter : public QMainWindow
{
	Q_OBJECT

public:
	explicit MedicamentsAjouter(QWidget* parent = nullptr);
	~MedicamentsAjouter();

private slots:
	// Slots pour les actions MedicamentsAjouter
	void on_Quitter_triggered();
	void on_Ajouter_triggered();
	void on_NomData_triggered();
	void on_DescriptionData_triggered();
	void on_CategorieData_triggered();
	void on_PrixData_triggered();
	void on_StockData_triggered();

private:
	Ui::MedicamentsAjouter ui;
};