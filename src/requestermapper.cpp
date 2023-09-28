#include "requestermapper.h"

#include "global/global.h"

RequesterMapper::RequesterMapper(QObject* parent) : HttpRequestHandler(parent) {}

RequesterMapper::~RequesterMapper() {}

void RequesterMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path = request.getPath();
    HttpSession session = sessionStore->getSession(request, response, false);
    QString username = session.get("username").toString();
    QByteArray sessionId = sessionStore->getSessionId(request, response);

    qDebug() << Q_FUNC_INFO << "path--------------------->" << path.data();
    qDebug() << Q_FUNC_INFO << "sessionId--------------------->" << sessionId.data();
    qDebug() << Q_FUNC_INFO << "username--------------------->" << username;

    if (path == "/login")
    {
        loginController.service(request, response);
    }
    else if (path == "/registration")
    {
        registerController.service(request, response);
    }
    else if (path == "/styles.css")
    {
        staticFileController->service(request, response);
    }
    else if (path == "/transport")
    {
        transportController.service(request, response);
    }
    else
    {
        response.setStatus(404, "Not found");
        response.write("The URL is wrong, no such document", true);
    }
    qDebug() << Q_FUNC_INFO << "RequestMapper: finished request" << endl;
}
