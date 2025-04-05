#pragma once

#include "ui_CommandesModifier.h"

class CommandesModifier : public QMainWindow
{
	Q_OBJECT

public:
	explicit CommandesModifier(QWidget* parent = nullptr);
	~CommandesModifier();

private slots:
	// Slots pour les actions CommandesModifier
	void on_Quitter_triggered();

private:
	Ui::CommandesModifier ui;
};
