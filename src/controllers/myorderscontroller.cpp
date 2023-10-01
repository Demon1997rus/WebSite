#include "myorderscontroller.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "../global/global.h"

MyOrdersController::MyOrdersController(QObject* parent) : HttpRequestHandler(parent) {}

void MyOrdersController::service(HttpRequest& request, HttpResponse& response)
{
    QList<Order> myOrders = mapOrder.values(currentUser);
    QJsonArray arrayOrder;
    for (const auto& order : myOrders)
    {
        QJsonObject orderObject;
        orderObject["serviceType"] = order.getServiceType();
        orderObject["location"] = order.getLocation();
        orderObject["date"] = order.getDate().toString();
        orderObject["details"] = order.getDetails();
        arrayOrder.append(orderObject);
    }
    QJsonObject responseObject;
    responseObject["orders"] = arrayOrder;
    response.setHeader("Content-Type", "application/json; charset=UTF-8");
    response.write(QJsonDocument(responseObject).toJson(), true);
}
