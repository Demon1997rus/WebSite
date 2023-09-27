#pragma once

#include <QObject>
#include <QSqlDatabase>

class LoginBase : public QObject
{
    Q_OBJECT
public:
    explicit LoginBase(QObject* parent = nullptr);

public:
    bool addUser(const QString& username, const QString& password) const;
    bool authentication(const QString& username, const QString& password) const;

private:
    bool checkUser(const QString& username) const;

private:
    QSqlDatabase db;
};
