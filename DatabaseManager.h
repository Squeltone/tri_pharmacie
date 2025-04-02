#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <mysql.h>
#include <QString>

class DatabaseManager
{
public:
	DatabaseManager();
	~DatabaseManager();

	bool connect(const QString& host, const QString& user, const QString& password, const QString& dbName, unsigned int port = 3306);
	void disconnect();
	bool isConnected() const;
	QString getLastError() const;
	MYSQL* getConnection();

private:
	MYSQL* conn;
	QString lastError;
};
#endif