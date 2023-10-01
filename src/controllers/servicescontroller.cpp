#include "servicescontroller.h"

#include "../global/global.h"

ServicesController::ServicesController(QObject* parent) : HttpRequestHandler(parent) {}

void ServicesController::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-type", "text/html; charset=UTF-8");
    Template t = templateCache->getTemplate("services", language);
    response.write(t.toUtf8(), true);
}
