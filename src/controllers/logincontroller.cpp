#include "logincontroller.h"

#include "../global/global.h"

LoginController::LoginController(QObject* parent) : HttpRequestHandler(parent) {}

void LoginController::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray username = request.getParameter("username");
    QByteArray password = request.getParameter("password");

    if (!username.isEmpty() && !password.isEmpty())
    {
        if (loginBase->authentication(username, password))
        {
            currentUser = username;
            response.redirect("/transport");
        }
        else
        {
            response.setStatus(401, "Неверное имя пользователя и пароль");
            response.write("Invalid username or password");
        }
        return;
    }
    QByteArray language = request.getHeader("Accept-Language");
    Template t = templateCache->getTemplate("login", language);
    response.setHeader("Content-type", "text/html; charset=UTF-8");
    response.write(t.toUtf8(), true);
}
