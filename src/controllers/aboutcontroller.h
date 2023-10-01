#pragma once

#include "httprequesthandler.h"

using namespace stefanfrings;

class AboutController : public HttpRequestHandler
{
public:
    AboutController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};
