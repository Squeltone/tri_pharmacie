#include "BDDMenu.h"
#include "BDDCreer.h"
#include "BDDSupprimer.h"
#include "BDDSauvegarder.h"
#include "BDDRestaurer.h"
#include "BDDConsulter.h"
#include "Accueil.h"

BDDMenu::BDDMenu(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->showMaximized();

	connect(ui.CreerBDD, &QPushButton::clicked, this, &BDDMenu::on_CreerBDD_triggered);
	connect(ui.SupprimerBDD, &QPushButton::clicked, this, &BDDMenu::on_SupprimerBDD_triggered);
	connect(ui.SauvegarderBDD, &QPushButton::clicked, this, &BDDMenu::on_SauvegarderBDD_triggered);
	connect(ui.RestaurerBDD, &QPushButton::clicked, this, &BDDMenu::on_RestaurerBDD_triggered);
	connect(ui.ConsulterBDD, &QPushButton::clicked, this, &BDDMenu::on_ConsulterBDD_triggered);
	connect(ui.Quitter, &QPushButton::clicked, this, &BDDMenu::on_Quitter_triggered);
}
BDDMenu::~BDDMenu()
{
}
void BDDMenu::on_CreerBDD_triggered()
{
	BDDCreer* fenetreBDDCreer = new BDDCreer(this);
	fenetreBDDCreer->show();
	this->hide();

	connect(fenetreBDDCreer, &BDDCreer::destroyed, [this]() {
		this->deleteLater();
		});
}
void BDDMenu::on_SupprimerBDD_triggered()
{
	BDDSupprimer* fenetreBDDSupprimer = new BDDSupprimer(this);
	fenetreBDDSupprimer->show();
	this->hide();

	connect(fenetreBDDSupprimer, &BDDSupprimer::destroyed, [this]() {
		this->deleteLater();
		});
}
void BDDMenu::on_SauvegarderBDD_triggered()
{
	BDDSauvegarder* fenetreBDDSauvegarderBDD = new BDDSauvegarder(this);
	fenetreBDDSauvegarderBDD->show();
	this->hide();

	connect(fenetreBDDSauvegarderBDD, &BDDSauvegarder::destroyed, [this]() {
		this->deleteLater();
		});
}
void BDDMenu::on_RestaurerBDD_triggered()
{
	BDDRestaurer* fenetreBDDRestaurerBDD = new BDDRestaurer(this);
	fenetreBDDRestaurerBDD->show();
	this->hide();

	connect(fenetreBDDRestaurerBDD, &BDDRestaurer::destroyed, [this]() {
		this->deleteLater();
		});
}
void BDDMenu::on_ConsulterBDD_triggered()
{
	BDDConsulter* fenetreBDDConsulter = new BDDConsulter(this);
	fenetreBDDConsulter->show();
	this->hide();

	connect(fenetreBDDConsulter, &BDDConsulter::destroyed, [this]() {
		this->deleteLater();
		});
}
void BDDMenu::on_Quitter_triggered()
{
	Accueil* accueil = new Accueil(this);
	accueil->show();
	this->hide();

	connect(accueil, &Accueil::destroyed, [this]() {
		this->deleteLater();
		});
}