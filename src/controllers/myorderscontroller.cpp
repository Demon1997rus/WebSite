#include "myorderscontroller.h"

#include "../global/global.h"

MyOrdersController::MyOrdersController(QObject* parent) : HttpRequestHandler(parent) {}

void MyOrdersController::service(HttpRequest& request, HttpResponse& response)
{
    QList<QStringList> orderList = dataBase->getOrdersByUsername(currentUser);
    QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-Type", "text/html; charset=UTF-8");
    Template t = templateCache->getTemplate("myorder", language);
    t.setVariable("name", currentUser);
    t.loop("row", orderList.size());
    for (int i = 0; i < orderList.size(); ++i)
    {
        const QStringList& order = orderList.at(i);
        QString number = QString::number(i);
        QString serviceType = order.at(0);
        QString location = order.at(1);
        QString date = order.at(2);
        QString details = order.at(3);
        t.setVariable("row" + number + ".number", QString::number(i + 1));
        t.setVariable("row" + number + ".serviceType", serviceType);
        t.setVariable("row" + number + ".location", location);
        t.setVariable("row" + number + ".date", date);
        t.setVariable("row" + number + ".details", details);
    }
    response.write(t.toUtf8(), true);
}
