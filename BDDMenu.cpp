#include "BDDMenu.h"
#include "BDDCreer.h"
#include "BDDSauvegarder.h"
#include "BDDSupprimer.h"
#include "BDDRestaurer.h"
#include "Accueil.h"
#include "ui_BDDMenu.h"

BDDMenu::BDDMenu(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.BDDCreerBDD, &QPushButton::clicked, this, &BDDMenu::on_BDDCreerBDD_triggered);
	connect(ui.BDDSupprimerBDD, &QPushButton::clicked, this, &BDDMenu::on_BDDSupprimerBDD_triggered);
	connect(ui.BDDSauvegarderBDD, &QPushButton::clicked, this, &BDDMenu::on_BDDSauvegarderBDD_triggered);
	connect(ui.BDDRestaurerBDD, &QPushButton::clicked, this, &BDDMenu::on_BDDRestaurerBDD_triggered);
	connect(ui.BDDConsulterBDD, &QPushButton::clicked, this, &BDDMenu::on_BDDConsulterBDD_triggered);
	connect(ui.BDDQuitter, &QPushButton::clicked, this, &BDDMenu::on_BDDQuitter_triggered);
}

BDDMenu::~BDDMenu()
{
}

void BDDMenu::on_BDDCreerBDD_triggered()
{
	FenetreBDDCreerBDD* fenetreBDDCreerBDD = new FenetreBDDCreerBDD(this);
	fenetreBDDCreerBDD->show();
	this->close();
}

void BDDMenu::on_BDDSupprimerBDD_triggered()
{
	FenetreBDDSupprimerBDD* fenetreBDDSupprimerBDD = new FenetreBDDSupprimerBDD(this);
	fenetreBDDSupprimerBDD->show();
	this->close();
}

void BDDMenu::on_BDDSauvegarderBDD_triggered()
{
	FenetreBDDSauvegarderBDD* fenetreBDDSauvegarderBDD = new FenetreBDDSauvegarderBDD(this);
	fenetreBDDSauvegarderBDD->show();
	this->close();
}

void BDDMenu::on_BDDRestaurerBDD_triggered()
{
	FenetreBDDRestaurerBDD* fenetreBDDRestaurerBDD = new FenetreBDDRestaurerBDD(this);
	fenetreBDDRestaurerBDD->show();
	this->close();
}

void BDDMenu::on_BDDConsulterBDD_triggered()
{
	FenetreBDDConsulterBDD* fenetreBDDConsulterBDD = new FenetreBDDConsulterBDD(this);
	fenetreBDDConsulterBDD->show();
	this->close();
}

void BDDMenu::on_BDDQuitter_triggered()
{
	Accueil* accueil = new Accueil(this);
	accueil->show();
	this->close();
}