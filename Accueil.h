#pragma once

#include "ui_Accueil.h"

class Accueil : public QMainWindow
{
	Q_OBJECT

public:
	explicit Accueil(QWidget* parent = nullptr);
	~Accueil();

private slots:
	// Slots pour les actions Accueil
	void on_BDD_triggered();
	void on_Medicaments_triggered();
	void on_Commandes_triggered();
	void on_Quitter_triggered();

private:
	Ui::Accueil ui;
};