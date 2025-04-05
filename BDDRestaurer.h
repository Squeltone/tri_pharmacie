#pragma once

#include "ui_BDDRestaurer.h"

class BDDRestaurer : public QMainWindow
{
	Q_OBJECT

public:
	explicit BDDRestaurer(QWidget* parent = nullptr);
	~BDDRestaurer();

private slots:
	// Slots pour les actions BDDRestaurer
	void on_Restaurer_triggered();
	void on_Quitter_triggered();

private:
	Ui::BDDRestaurer ui;
};