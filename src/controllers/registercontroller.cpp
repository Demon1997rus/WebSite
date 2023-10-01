#include "registercontroller.h"

#include "../global/global.h"

RegisterController::RegisterController(QObject* parent) : HttpRequestHandler(parent) {}

void RegisterController::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray username = request.getParameter("username");
    QByteArray password = request.getParameter("password");
    QByteArray email = request.getParameter("email");

    if (!username.isEmpty() && !password.isEmpty() && !email.isEmpty())
    {
        if (loginBase->addUser(username, password))
        {
            response.redirect("/login");
        }
        else
        {
            response.setStatus(401, "Such a user already exists");
            response.write("Such a user already exists", true);
        }
        return;
    }
    QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-type", "text/html; charset=UTF-8");
    Template t = templateCache->getTemplate("registration", language);
    response.write(t.toUtf8(), true);
}
