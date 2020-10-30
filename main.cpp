/**
  * @ Developed By Hadi Abbasi Programmer
  * @ Email:     (hadi.abbasi.programmer@gmail.com)
  * @ Linked In: https://www.linkedin.com/in/hadi-abbasi-59902145/
  * @ Telegram:  @Hadi_Abbasi_Programmer
  * */
#include <iostream>
using namespace std;

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QQmlContext>
#include <QDebug>
#include <QDateTime>
#include "assetsmanager.h"
#include "hi/hicalendar.h"

#define QML_REGISTER(classname,packagename,MAJORVERSION,minorversion) \
    qmlRegisterType<classname>(packagename, MAJORVERSION, minorversion, #classname);

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QML_REGISTER(YearMonthDay,"hi",1,0)
    QML_REGISTER(HiCalendarDayModel,"hi",1,0)
    QML_REGISTER(HiCalendarController,"hi",1,0)

    QQmlApplicationEngine engine;
    HiCalendarContext* calendar_context = new HiCalendarContext();
    QObject::connect(calendar_context,&HiCalendarContext::CalendarChangedSi,[calendar_context]()
    {
        QObject::connect(calendar_context->getCalendar(),&HiCalendarController::daySelectedSi,[]( HiCalendarDayModel* selected_day)
        {
            qDebug()<<"-------> "<<selected_day->toString();
//            selected_day->isToday();
//            selected_day->isDayOver();
//            selected_day->getJalaloDay();
//            selected_day->getJalaliMonth();
//            selected_day->getJalaliYear();
//            selected_day->getGeorgianDay();
//            selected_day->getGeorgianMonth();
//            selected_day->getGeorgianYear();
//            selected_day->getIslamicDay();
//            selected_day->getIslamicMonth();
//            selected_day->getIslamicYear();
        });
    });
    calendar_context->renewCalendar(HiCalendarController::CalendarTypes::UsGeorgian);//
    engine.rootContext()->setContextProperty("ASSETS", AssetsManager::getAssetsAddress(AssetsManager::file_asset));
    engine.rootContext()->setContextProperty("calendar_context", QVariant::fromValue(calendar_context));
    engine.load(QUrl(AssetsManager::getAssetsAddress(AssetsManager::qrc_asset,"hi/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    QObject *item = engine.rootObjects()[0];

    return app.exec();
}
