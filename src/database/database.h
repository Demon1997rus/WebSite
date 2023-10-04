#pragma once

#include <QObject>
#include <QSqlDatabase>

#include "../utils/order.h"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject* parent = nullptr);

public:
    bool addUser(const QString& username, const QString& password) const;
    bool authentication(const QString& username, const QString& password) const;
    bool addOrder(const QString& username, const Order& order);
    QList<QStringList> getOrdersByUsername(const QString& username);
    bool deleteOrder(int orderId);

private:
    bool checkUser(const QString& username) const;

private:
    QSqlDatabase db;
};
