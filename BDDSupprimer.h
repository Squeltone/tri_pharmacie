#pragma once

#include "ui_BDDSupprimer.h"

class BDDSupprimer : public QMainWindow
{
	Q_OBJECT

public:
	explicit BDDSupprimer(QWidget* parent = nullptr);
	~BDDSupprimer();

private slots:
	// Slots pour les actions BDDSupprimer
	void on_Supprimer_triggered();
	void on_Quitter_triggered();

private:
	Ui::BDDSupprimer ui;
};