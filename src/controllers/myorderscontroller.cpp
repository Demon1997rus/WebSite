#include "myorderscontroller.h"

#include "../global/global.h"

MyOrdersController::MyOrdersController(QObject* parent) : HttpRequestHandler(parent) {}

void MyOrdersController::service(HttpRequest& request, HttpResponse& response)
{
    QList<QStringList> orderList = dataBase->getOrdersByUsername(currentUser);
    qDebug() << Q_FUNC_INFO << orderList << "<--------orderList";
}
