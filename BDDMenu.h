#pragma once

#include "ui_BDDMenu.h"

class BDDMenu : public QMainWindow
{
	Q_OBJECT

public:
	explicit BDDMenu(QWidget* parent = nullptr);
	~BDDMenu();

private slots:
	// Slots pour les actions BDDMenu
	void on_CreerBDD_triggered();
	void on_SupprimerBDD_triggered();
	void on_SauvegarderBDD_triggered();
	void on_RestaurerBDD_triggered();
	void on_ConsulterBDD_triggered();
	void on_Quitter_triggered();

private:
	Ui::BDDMenu ui;
};