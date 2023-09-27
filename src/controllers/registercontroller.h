#pragma once

#include "httprequesthandler.h"

using namespace stefanfrings;

class RegisterController : public HttpRequestHandler
{
public:
    RegisterController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};
