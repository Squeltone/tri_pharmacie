#pragma once

#include "ui_CommandesCreer.h"

class CommandesCreer : public QMainWindow
{
	Q_OBJECT

public:
	explicit CommandesCreer(QWidget* parent = nullptr);
	~CommandesCreer();

private slots:
	// Slots pour les actions CommandesCreer
	void on_Commander_triggered();
	void on_Quitter_triggered();
	void on_Medicament_triggered();
	void on_Quantitee_triggered();
	void on_Nom_triggered();

private:
	Ui::CommandesCreer ui;
};


