#ifndef BDDMENU_H
#define BDDMENU_H

#include "BDDConsulter.h"
#include "BDDCreer.h"
#include "BDDSauvegarder.h"
#include "BDDSupprimer.h"
#include "BDDRestaurer.h"
#include "Accueil.h"
#include "ui_BDDMenu.h"

class BDDMenu : public QMainWindow
{
	Q_OBJECT

public:
	explicit BDDMenu(QWidget* parent = nullptr);
	~BDDMenu();

private slots:
	// Slots pour les actions BDDMenu
	void on_BDDCreerBDD_triggered();
	void on_BDDSupprimerBDD_triggered();
	void on_BDDSauvegarderBDD_triggered();
	void on_BDDRestaurerBDD_triggered();
	void on_BDDConsulterBDD_triggered();
	void on_BDDQuitter_triggered();

private:
	Ui::BDDMenu ui;
};
#endif // BDDMENU_H