#pragma once

#include "ui_CommandesMenu.h"

class CommandesMenu : public QMainWindow
{
	Q_OBJECT

public:
	explicit CommandesMenu(QWidget* parent = nullptr);
	~CommandesMenu();

private slots:
	// Slots pour les actions Commandes
	void on_Creer_triggered();
	void on_Modifier_triggered();
	void on_Supprimer_triggered();
	void on_Consulter_triggered();
	void on_Quitter_triggered();

private:
	Ui::CommandesMenu ui;
};