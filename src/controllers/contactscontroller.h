#pragma once

#include "httprequesthandler.h"

using namespace stefanfrings;

class ContactsController : public HttpRequestHandler
{
public:
    ContactsController(QObject* parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest& request, HttpResponse& response) override;
};
