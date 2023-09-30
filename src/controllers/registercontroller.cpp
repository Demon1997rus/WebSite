#include "registercontroller.h"

#include "../global/global.h"

RegisterController::RegisterController(QObject* parent) : HttpRequestHandler(parent) {}

void RegisterController::service(HttpRequest& request, HttpResponse& response)
{
    HttpSession session = sessionStore->getSession(request, response, true);
    QByteArray username = request.getParameter("username");
    QByteArray password = request.getParameter("password");
    QByteArray email = request.getParameter("email");

    qDebug() << Q_FUNC_INFO << "username----->" << username.constData();
    qDebug() << Q_FUNC_INFO << "password----->" << password.constData();
    qDebug() << Q_FUNC_INFO << "email----->" << email.constData();

    if (!username.isEmpty() && !password.isEmpty() && !email.isEmpty())
    {
        loginBase->addUser(username, password);
        response.redirect("/login");
        return;
    }

    QByteArray language = request.getHeader("Accept-Language");

    response.setHeader("Content-type", "text/html; charset=UTF-8");

    Template t = templateCache->getTemplate("registration", language);
    response.write(t.toUtf8(), true);
}
