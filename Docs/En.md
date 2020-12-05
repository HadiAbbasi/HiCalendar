# HiCalendar

![Language iso: C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Version](https://img.shields.io/badge/Version-0.7-lightgrey)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux%20%7C%20iOS%20%7C%20Android%20%7C%20Web-lightgrey)

Hi Calendar Pro Component based on C++ and Qt Quick technology.

It supports:
    Us Georgian calendar    (weeks start with sunday).
    Euro Georgian calendar  (weeks start with monday)
    Persian Jalali calendar (weeks starts with saturday).

# Description:
-------------------------------
The project is still in its early stages and it may have some bugs and errors!

**HiCalendarController::CalendarTypes contains these 3 types:**

HiCalendarController::CalendarTypes::UsGeorgian
HiCalendarController::CalendarTypes::EuroGeorgian
HiCalendarController::CalendarTypes::Jalali

As we need to renew calendar depended on user clendar type changing, there is a hicalendarcontext class which is the container for our main hicalendarcontroller!
here is main.cpp codes on this example!

```cpp
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QQmlContext>
#include <QDebug>

#include "assetsmanager.hpp"
#include "include/hi/hicalendar.hpp"
#include "include/common.hpp"

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
    
    return app.exec();
}
```

**Building**
You need CMake or QMake tool for building source code based on Qt 5.15 series.

**Contribution**
Bug fixes, docs, and enhancements welcome! Please let us know hadi.abbasi.programmer@gmail.com or kambiz.ceo@gmail.com

**Screen Shots**
![Image of Georgian 1](https://github.com/HadiAbbasi/HiCalendar/blob/main/Docs/Georgian-01.png)
![Image of Georgian 2](https://github.com/HadiAbbasi/HiCalendar/blob/main/Docs/Georgian-02.png)
![Image of Jalali](https://github.com/HadiAbbasi/HiCalendar/blob/main/Docs/Jalali.png)
