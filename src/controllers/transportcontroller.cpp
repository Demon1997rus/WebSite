#include "transportcontroller.h"

#include "../global/global.h"

TransportController::TransportController(QObject* parent) : HttpRequestHandler(parent) {}

void TransportController::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-type", "text/html; charset=UTF-8");
    Template t = templateCache->getTemplate("main", language);
    response.write(t.toUtf8(), true);
}
