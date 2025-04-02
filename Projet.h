#ifndef PROJET_H
#define PROJET_H

#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>
#include "ui_Projet.h"
#include "DatabaseManager.h"

class Projet : public QMainWindow
{
	Q_OBJECT

public:
	Projet(QWidget* parent = nullptr);
	~Projet();

private slots:
	void on_testConnectionButton_clicked();
	void on_resetButton_clicked();
	void loadTableData(const QString& tableName);

private:
	Ui::ProjetClass ui;
	DatabaseManager* dbManager;
	QStandardItemModel* tableModel;
};
#endif // !PROJET_H
