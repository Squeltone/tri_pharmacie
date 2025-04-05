#pragma once

#include "ui_MedicamentsModifier.h"

class MedicamentsModifier : public QMainWindow
{
	Q_OBJECT

public:
	explicit MedicamentsModifier(QWidget* parent = nullptr);
	~MedicamentsModifier();

private slots:
	// Slots pour les actions MedicamentsModifier
	void on_Quitter_triggered();

private:
	Ui::MedicamentsModifier ui;
};