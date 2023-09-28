#pragma once

#include "httprequesthandler.h"

using namespace stefanfrings;

class TransportController : public HttpRequestHandler
{
public:
    TransportController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};
