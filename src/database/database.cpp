#include "database.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

DataBase::DataBase(QObject* parent) : QObject(parent), db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("../WebSite/data/database.db");
    if (db.open())
    {
        QSqlQuery query(db);
        query.exec(
            "CREATE TABLE IF NOT EXISTS Users ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "username TEXT,"
            "password TEXT)");
        query.exec(
            "CREATE TABLE IF NOT EXISTS Orders ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "username TEXT,"
            "serviceType TEXT,"
            "location TEXT,"
            "date TEXT,"
            "details TEXT"
            ")");
    }
    else
    {
        qCritical() << Q_FUNC_INFO << db.lastError().text();
        qFatal("Database no open");
    }
}

bool DataBase::addUser(const QString& username, const QString& password) const
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

bool DataBase::authentication(const QString& username, const QString& password) const
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    return query.exec() && query.next();
}

bool DataBase::addOrder(const QString& username, const Order& order)
{
    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO Orders (username, serviceType, location, date, details) "
        "VALUES (:username, :serviceType, :location, :date, :details)");
    query.bindValue(":username", username);
    query.bindValue(":serviceType", order.getServiceType());
    query.bindValue(":location", order.getLocation());
    query.bindValue(":date", order.getDate().toString());
    query.bindValue(":details", order.getDetails());
    return query.exec();
}

QList<QStringList> DataBase::getOrdersByUsername(const QString& username)
{
    QList<QStringList> ordersList;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Orders WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec())
    {
        while (query.next())
        {
            QStringList order;
            order << query.value("serviceType").toString();
            order << query.value("location").toString();
            order << query.value("date").toString();
            order << query.value("details").toString();
            ordersList.append(order);
        }
    }
    else
    {
        qCritical() << Q_FUNC_INFO << query.lastError().text();
    }
    return ordersList;
}

bool DataBase::deleteOrder(int orderId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Orders WHERE id = :orderId");
    query.bindValue(":orderId", orderId);
    return query.exec();
}

bool DataBase::checkUser(const QString& username) const
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Users WHERE username = :username");
    query.bindValue(":username", username);
    return query.exec() && query.next();
}
