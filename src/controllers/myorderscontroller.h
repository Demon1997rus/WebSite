#pragma once

#include "httprequesthandler.h"

using namespace stefanfrings;

class MyOrdersController : public HttpRequestHandler
{
public:
    MyOrdersController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};
