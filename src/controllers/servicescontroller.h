#pragma once

#include "httprequesthandler.h"

using namespace stefanfrings;

class ServicesController : public HttpRequestHandler
{
public:
    ServicesController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};
