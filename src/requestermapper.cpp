#include "requestermapper.h"

#include "global/global.h"

RequesterMapper::RequesterMapper(QObject* parent) : HttpRequestHandler(parent) {}

RequesterMapper::~RequesterMapper() {}

void RequesterMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path = request.getPath();
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
    else if (path == "/services")
    {
        servicesController.service(request, response);
    }
    else if (path == "/about")
    {
        aboutController.service(request, response);
    }
    else if (path == "/contacts")
    {
        contactsController.service(request, response);
    }
    else if (path == "/create-order")
    {
        orderController.service(request, response);
    }
    else if (path == "/my-orders")
    {
        myOrdersController.service(request, response);
    }
    else
    {
        response.setStatus(404, "Not found");
        response.write("The URL is wrong, no such document", true);
    }
}
