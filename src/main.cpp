/*
  The MIT License (MIT)
  Copyright (c) 2020 Hadi Abbasi & Kambiz Asadzadeh
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 */

#include <iostream>
using namespace std;

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QQmlContext>
#include <QDebug>
#include <QDateTime>

#include "include/assetsmanager.hpp"
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
    QObject::connect(calendar_context,&HiCalendarContext::calendarChangedSi,[calendar_context]() {
        QObject::connect(calendar_context->getCalendar(),&HiCalendarController::daySelectedSi,[]( HiCalendarDayModel* selected_day) {
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
    calendar_context->renewCalendar(HiCalendarController::CalendarTypes::UsGeorgian);//default calendar is us georgian
    engine.rootContext()->setContextProperty("ASSETS", AssetsManager::getAssetsAddress(AssetsManager::file_asset));
    engine.rootContext()->setContextProperty("calendar_context", calendar_context);//QVariant::fromValue(calendar_context)
    engine.load(QUrl(AssetsManager::getAssetsAddress(AssetsManager::qrc_asset,"ui/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    // QObject *item = engine.rootObjects()[0];

    return app.exec();
}
