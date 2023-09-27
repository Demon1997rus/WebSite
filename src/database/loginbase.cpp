#include "loginbase.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

LoginBase::LoginBase(QObject* parent) : QObject(parent), db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("../WebSite/data/auth");
    if (db.open())
    {
        QSqlQuery query(db);
        query.exec(
            "CREATE TABLE IF NOT EXISTS Users ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "username TEXT,"
            "password TEXT)");
    }
    else
    {
        qCritical() << db.lastError().text();
        qFatal("Login base no open");
    }
}

bool LoginBase::addUser(const QString& username, const QString& password) const
{
    if (checkUser(username))
    {
        return false;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO Users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    return query.exec();
}

bool LoginBase::authentication(const QString& username, const QString& password) const
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    return query.exec() && query.next();
}

bool LoginBase::checkUser(const QString& username) const
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Users WHERE username = :username");
    query.bindValue(":username", username);
    return query.exec() && query.next();
}
