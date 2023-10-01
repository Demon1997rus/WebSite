#include "aboutcontroller.h"

#include "../global/global.h"

AboutController::AboutController(QObject* parent) : HttpRequestHandler(parent) {}

void AboutController::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-type", "text/html; charset=UTF-8");
    Template t = templateCache->getTemplate("about", language);
    response.write(t.toUtf8(), true);
}
