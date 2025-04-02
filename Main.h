#ifndef MAIN_H
#define MAIN_H

#include <QtWidgets/QMainWindow>

class Main : public QMainWindow
{
	Q_OBJECT

public:
	Main();
	~Main();

private slots:
	// Slots pour les actions Accueil
	void on_AccueilBaseDeDonnees_triggered();
	void on_AccueilMedicaments_triggered();
	void on_AccueilCommandes_triggered();
	void on_AccueilQuitter_triggered();
	
	// Slots pour les actions Medicaments
	void 

}

#endif // MAIN_H