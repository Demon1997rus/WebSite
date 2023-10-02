#include "ordercontroller.h"

#include "../global/global.h"

OrderController::OrderController(QObject* parent) : HttpRequestHandler(parent) {}

void OrderController::service(HttpRequest& request, HttpResponse& response)
{
    QString serviceType = request.getParameter("service");
    QString location = request.getParameter("location");
    QString date = request.getParameter("date");
    QString details = request.getParameter("details");

    if (!serviceType.isEmpty() && !location.isEmpty() && !date.isEmpty())
    {
        QStringList splitDate = date.split("-");
        int year = splitDate.value(0).toInt();
        int month = splitDate.value(1).toInt();
        int day = splitDate.value(2).toInt();
        Order order(serviceType, location, QDate(year, month, day), details);
        dataBase->addOrder(currentUser, order);
        response.redirect("/my-orders");
        return;
    }

    QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-type", "text/html; charset=UTF-8");
    Template t = templateCache->getTemplate("order", language);
    response.write(t.toUtf8(), true);
}
