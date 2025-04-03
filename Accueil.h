#ifndef ACCUEIL_H
#define ACCUEIL_H

#include "ui_Accueil.h"
#include "BDDMenu.h"
#include "CommandesMenu.h"
#include "MedicamentMenu.h"

class Accueil : public QMainWindow
{
	Q_OBJECT

public:
	explicit Accueil(QWidget* parent = nullptr);
	~Accueil();

private slots:
	// Slots pour les actions Accueil
	void on_AccueilBaseDeDonnees_triggered();
	void on_AccueilMedicaments_triggered();
	void on_AccueilCommandes_triggered();
	void on_AccueilQuitter_triggered();

private:
	Ui::Accueil ui;
};
#endif // !ACCUEIL_H
