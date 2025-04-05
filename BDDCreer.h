#pragma once

#include "ui_BDDCreer.h"

class BDDCreer : public QMainWindow
{
	Q_OBJECT

public:
	explicit BDDCreer(QWidget* parent = nullptr);
	~BDDCreer();

private slots:
	// Slots pour les actions BDDCreer
	void on_Creer_triggered();
	void on_Quitter_triggered();

private:
	Ui::BDDCreer ui;
};