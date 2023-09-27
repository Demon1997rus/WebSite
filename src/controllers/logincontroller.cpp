#include "logincontroller.h"

#include "../global/global.h"

LoginController::LoginController(QObject* parent) : HttpRequestHandler(parent) {}

void LoginController::service(HttpRequest& request, HttpResponse& response)
{
    HttpSession session = sessionStore->getSession(request, response, true);
    QByteArray username = request.getParameter("username");
    QByteArray password = request.getParameter("password");

    qDebug() << Q_FUNC_INFO << "username----->" << username.constData();
    qDebug() << Q_FUNC_INFO << "password----->" << password.constData();

    QByteArray language = request.getHeader("Accept-Language");

    response.setHeader("Content-type", "text/html; charset=UTF-8");

    Template t = templateCache->getTemplate("login", language);
    response.write(t.toUtf8(), true);
}
