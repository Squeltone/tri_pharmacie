#pragma once

#include "ui_BDDConsulter.h"

class BDDConsulter : public QMainWindow
{
	Q_OBJECT

public:
	explicit BDDConsulter(QWidget* parent = nullptr);
	~BDDConsulter();

private slots:
	// Slots pour les actions BDDConsulter
	void on_BDD_triggered();
	void on_Recherche_triggered();
	void on_Quitter_triggered();
	void on_Stock_triggered();

private:
	Ui::BDDConsulter ui;
};
