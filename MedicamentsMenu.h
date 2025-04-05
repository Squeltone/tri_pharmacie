#pragma once

#include "ui_MedicamentsMenu.h"

class MedicamentsMenu : public QMainWindow
{
	Q_OBJECT

public:
	explicit MedicamentsMenu(QWidget* parent = nullptr);
	~MedicamentsMenu();

private slots:
	// Slots pour les actions Medicaments
	void on_Ajouter_triggered();
	void on_Modifier_triggered();
	void on_Supprimer_triggered();
	void on_Quitter_triggered();

private:
	Ui::MedicamentsMenu ui;
};