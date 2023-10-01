#pragma once

#include "httprequesthandler.h"

using namespace stefanfrings;

class OrderController : public HttpRequestHandler
{
public:
    OrderController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};
