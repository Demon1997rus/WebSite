#include "contactscontroller.h"

#include "../global/global.h"

ContactsController::ContactsController(QObject* parent) : HttpRequestHandler(parent) {}

void ContactsController::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-type", "text/html; charset=UTF-8");
    Template t = templateCache->getTemplate("contacts", language);
    response.write(t.toUtf8(), true);
}
