#include "order.h"

#include <QDebug>

Order::Order(const QString& _serviceType, const QString& _location, const QDate& _date, const QString& _details)
  : serviceType(_serviceType), location(_location), date(_date), details(_details)
{
}

void Order::print() const
{
    qDebug() << "service type = " << serviceType;
    qDebug() << "location = " << location;
    qDebug() << "date = " << date;
    qDebug() << "details" << details << endl;
}

QString Order::getServiceType() const { return serviceType; }

QString Order::getLocation() const { return location; }

QDate Order::getDate() const { return date; }

QString Order::getDetails() const { return details; }
