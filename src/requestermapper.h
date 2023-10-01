#pragma once

#include "httprequesthandler.h"
#include "controllers/logincontroller.h"
#include "controllers/registercontroller.h"
#include "controllers/transportcontroller.h"
#include "controllers/servicescontroller.h"
#include "controllers/aboutcontroller.h"
#include "controllers/contactscontroller.h"

using namespace stefanfrings;

class RequesterMapper : public HttpRequestHandler
{
public:
    RequesterMapper(QObject* parent = nullptr);
    virtual ~RequesterMapper();

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;

private:
    LoginController loginController;
    RegisterController registerController;
    TransportController transportController;
    ServicesController servicesController;
    AboutController aboutController;
    ContactsController contactsController;
};
