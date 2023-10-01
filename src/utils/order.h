#pragma once

#include <QDate>
#include <QString>

class Order
{
public:
    Order(const QString& _serviceType, const QString& _location, const QDate& _date, const QString& _details);

public:
    void print() const;
    QString getServiceType() const;
    QString getLocation() const;
    QDate getDate() const;
    QString getDetails() const;

private:
    QString serviceType;
    QString location;
    QDate date;
    QString details;
};
