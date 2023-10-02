#include <QCoreApplication>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QSettings>

#include "global/global.h"
#include "httplistener.h"
#include "requestermapper.h"

/*!
 * \brief searchConfigFile - Выполняет поиск в файла конфигурации.
 *
 * Прерывает работу приложения, если оно не найдено.
 * \return возвращает допустимое имя файла
 */
QString searchConfigFile()
{
    QString binDir = QCoreApplication::applicationDirPath();
    QString appName = QCoreApplication::applicationName();
    QString fileName("website.ini");

    QStringList searchList;
    searchList.append(binDir);
    searchList.append(binDir + "/etc");
    searchList.append(binDir + "/../etc");
    searchList.append(binDir + "/../" + appName + "/etc");  // для разработки с помощью shadow build (Linux)
    searchList.append(binDir + "/../../" + appName + "/etc");  // для разработки с помощью shadow build (Windows)
    searchList.append(QDir::rootPath() + "etc/opt");
    searchList.append(QDir::rootPath() + "etc");

    foreach (QString dir, searchList)
    {
        QFile file(dir + "/" + fileName);
        if (file.exists())
        {
            fileName = QDir(file.fileName()).canonicalPath();
            qDebug("Using config file %s", qPrintable(fileName));
            return fileName;
        }
    }

    foreach (QString dir, searchList)
    {
        qWarning("%s/%s not found", qPrintable(dir), qPrintable(fileName));
    }
    qFatal("Cannot find config file %s", qPrintable(fileName));
    return nullptr;
}

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QString configPath = searchConfigFile();

    //Инициализация база данных
    dataBase = new DataBase(&app);

    // Настройка введения журнала ошибок
    QSettings* logSettings = new QSettings(configPath, QSettings::IniFormat, &app);
    logSettings->beginGroup("logging");
    logger = new FileLogger(logSettings, 10000, &app);

    //Регистрация версии библиотеки
    qDebug("QtWebApp has version %s", getQtWebAppLibVersion());

    //Хранилище сеансов
    QSettings* sessionSettings = new QSettings(configPath, QSettings::IniFormat, &app);
    sessionSettings->beginGroup("sessions");
    sessionStore = new HttpSessionStore(sessionSettings, &app);

    //Статический файловый контроллер
    QSettings* fileSettings = new QSettings(configPath, QSettings::IniFormat, &app);
    fileSettings->beginGroup("files");
    staticFileController = new StaticFileController(fileSettings, &app);

    //Настройка кэша шаблонов HTML
    QSettings* templateSettings = new QSettings(configPath, QSettings::IniFormat, &app);
    templateSettings->beginGroup("templates");
    templateCache = new TemplateCache(templateSettings, &app);

    //Запускаем HTTP сервер
    QSettings* listenerSettings = new QSettings(configPath, QSettings::IniFormat, &app);
    listenerSettings->beginGroup("listener");
    new HttpListener(listenerSettings, new RequesterMapper(&app), &app);

    return app.exec();
}
