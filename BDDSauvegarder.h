#pragma once

#include "ui_BDDSauvegarder.h"

class BDDSauvegarder : public QMainWindow
{
	Q_OBJECT

public:
	explicit BDDSauvegarder(QWidget* parent = nullptr);
	~BDDSauvegarder();

private slots:
	// Slots pour les actions BDDSauvegarder
	void on_Sauvegarder_triggered();
	void on_Quitter_triggered();

private:
	Ui::BDDSauvegarder ui;
};