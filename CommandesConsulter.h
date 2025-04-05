#pragma once

#include "ui_CommandesConsulter.h"

class CommandesConsulter : public QMainWindow
{
	Q_OBJECT

public:
	explicit CommandesConsulter(QWidget* parent = nullptr);
	~CommandesConsulter();

private slots:
	// Slots pour les actions CommandesConsulter
	void on_Recherche_triggered();
	void on_EnAttente_triggered();
	void on_EnCours_triggered();
	void on_Termine_triggered();
	void on_Quitter_triggered();
	void on_BDD_triggered();

private:
	Ui::CommandesConsulter ui;
};