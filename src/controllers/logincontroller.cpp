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

    if (!username.isEmpty() && !password.isEmpty())
    {
        if (loginBase->authentication(username, password))
        {
            // TODO::Тут должна быть реализована логика работы если пользователь правильно ввел свои данные
            qDebug() << Q_FUNC_INFO << "Вы верно ввели свои данные";
            response.redirect("/transport");
            return;
        }
        else
        {
            // TODO::Тут должна быть реализована логика работы если пользователь ошибся в данных
            qDebug() << Q_FUNC_INFO << "Вы неверно ввели свои данные";
        }
    }

    QByteArray language = request.getHeader("Accept-Language");

    response.setHeader("Content-type", "text/html; charset=UTF-8");

    Template t = templateCache->getTemplate("login", language);
    response.write(t.toUtf8(), true);
}
