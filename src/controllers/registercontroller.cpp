#include "registercontroller.h"

#include "../global/global.h"

RegisterController::RegisterController(QObject* parent) : HttpRequestHandler(parent) {}

void RegisterController::service(HttpRequest& request, HttpResponse& response)
{
    HttpSession session = sessionStore->getSession(request, response, true);
    QByteArray username = request.getParameter("username");
    QByteArray password = request.getParameter("password");
    QByteArray email = request.getParameter("email");

    if (!username.isEmpty() && !password.isEmpty() && !email.isEmpty())
    {
        // TODO::ЛОГИКА РЕГИСТРАЦИЙ ЕСЛИ ПОЛЯ НЕ ПУСТЫЕ!ц
    }

    qDebug() << Q_FUNC_INFO << "username----->" << username.constData();
    qDebug() << Q_FUNC_INFO << "password----->" << password.constData();
    qDebug() << Q_FUNC_INFO << "email----->" << email.constData();

    QByteArray language = request.getHeader("Accept-Language");

    response.setHeader("Content-type", "text/html; charset=UTF-8");

    Template t = templateCache->getTemplate("registration", language);
    response.write(t.toUtf8(), true);
}
