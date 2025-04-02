#include "DatabaseManager.h"
#include <iostream>
#include <mysql.h>

DatabaseManager::DatabaseManager()
{
	conn = mysql_init(nullptr);
	if (!conn) {
		lastError = "Erreur d'initialisation de MySQL";
	}
}

DatabaseManager::~DatabaseManager()
{
	disconnect();
}

bool DatabaseManager::connect(const QString& host, const QString& user, const QString& password, const QString& dbName, unsigned int port)
{
	if (host.isEmpty() || user.isEmpty() || dbName.isEmpty()) {
		lastError = "Un ou plusieurs paramètres de connexion sont vides.";
		return false;
	}

	if (!conn) return false;

	disconnect();
	
	mysql_options(conn, MYSQL_OPT_SSL_KEY, "SSL\\connexion-key.pem");
	mysql_options(conn, MYSQL_OPT_SSL_CERT, "SSL\\connexion-cert.pem");
	mysql_options(conn, MYSQL_OPT_SSL_CA, "SSL\\ca-cert.pem");
	int verify = 0;
	mysql_options(conn, MYSQL_OPT_SSL_VERIFY_SERVER_CERT, &verify);

	if (!mysql_real_connect(conn, host.toStdString().c_str(), user.toStdString().c_str(),
		password.toStdString().c_str(), dbName.toStdString().c_str(), port, NULL, 0))
	{
		lastError = mysql_error(conn);
		return false;
	}

	if (mysql_ping(conn) != 0) {
		lastError = mysql_error(conn);
		return false;
	}

	return true;
}

void DatabaseManager::disconnect()
{
	if (conn) {
		mysql_close(conn);
		conn = mysql_init(nullptr);
	}
}

bool DatabaseManager::isConnected() const
{
	return conn != nullptr && mysql_ping(conn) == 0;
}

QString DatabaseManager::getLastError() const
{
	return lastError;
}

MYSQL* DatabaseManager::getConnection()
{
	if (conn && mysql_ping(conn) == 0) {
		return conn;
	}
	else {
		lastError = "La connexion MySQL n'est pas valide.";
		return nullptr;
	}
}

