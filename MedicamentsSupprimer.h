#pragma once

#include "ui_MedicamentsSupprimer.h"

class MedicamentsSupprimer : public QMainWindow
{
	Q_OBJECT

public:
	explicit MedicamentsSupprimer(QWidget* parent = nullptr);
	~MedicamentsSupprimer();

private slots:
	// Slots pour les actions MedicamentsSupprimer
	void on_Quitter_triggered();
	void on_Supprimer_triggered();
	void on_SupprimerData_triggered();

private:
	Ui::MedicamentsSupprimer ui;
};