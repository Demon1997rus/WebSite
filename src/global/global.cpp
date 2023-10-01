#include "global.h"

HttpSessionStore* sessionStore;
StaticFileController* staticFileController;
TemplateCache* templateCache;
FileLogger* logger;
LoginBase* loginBase;
QMultiMap<QString, Order> mapOrder;
QString currentUser;
