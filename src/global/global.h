#pragma once

#include "httpsessionstore.h"
#include "staticfilecontroller.h"
#include "templatecache.h"
#include "filelogger.h"
#include "../database/database.h"

using namespace stefanfrings;

/** Хранилище для сессионных файлов cookie */
extern HttpSessionStore* sessionStore;

/** Контроллер для статических файлов */
extern StaticFileController* staticFileController;

/** Кэш для файлов шаблонов */
extern TemplateCache* templateCache;

/** Перенаправляет сообщения журнала в файл */
extern FileLogger* logger;

/** База данных */
extern DataBase* dataBase;

/** Текущий пользователь */
extern QString currentUser;
