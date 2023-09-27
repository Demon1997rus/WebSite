#pragma once

#include "httprequesthandler.h"

using namespace stefanfrings;

class LoginController : public HttpRequestHandler
{
public:
    LoginController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};
