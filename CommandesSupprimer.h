#pragma once

#include "ui_CommandesSupprimer.h"

class CommandesSupprimer : public QMainWindow
{
	Q_OBJECT

public:
	explicit CommandesSupprimer(QWidget* parent = nullptr);
	~CommandesSupprimer();

private slots:
	// Slots pour les actions CommandesSupprimer
	void on_Quitter_triggered();

private:
	Ui::CommandesSupprimer ui;
};
