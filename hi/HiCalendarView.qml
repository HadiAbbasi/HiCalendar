import QtQuick 2.0
import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQml 2.14
import hi 1.0

Rectangle{
    id: calendar
    //us->  1:Sun , 2:Mon , 3:Tue , 4:Wed , 5:Thu , 6:Fri , 7:Sat
    //euro->1:Mon , 2:Tue , 3:Wed , 4:Thu , 5:Fri , 6:Sat , 7:Sun
    //jalali->1:Sat , 2:Sun , 3:Mon , 4:Tue , 5:Wed , 6:Thu , 7:Fri
    property int calendarWidth: 640
    property int calendarHeight: 240
    property alias weeks: weeks;
    width: calendarWidth
    height: calendarHeight
    color: "#888888"
     FontLoader { id: persianFont; source: ASSETS+"b_yekan.ttf"}
     FontLoader { id: englishFont; source: ASSETS+"verdana.ttf"}

    Component.onCompleted: {
        calendar_context.calendar_ctrl.showCurrentSelectedYearMonthDay();
    }

    Loader
    {
        id: header
        source: (calendar_context.calendar_ctrl.calendartype >= 3) ? "HiCalendarJalaliHeader.qml" : "HiCalendarGeorgianHeader.qml";
        anchors.horizontalCenter: calendar.horizontalCenter
    }

    Button
    {
        id: prevYear
        text:  (calendar_context.calendar_ctrl.calendartype < 3)?"<<< prev year": "<<< سال قبل";
        font: persianFont.name
        width: (calendar.width - header.width)/6-7
        height: 20
        LayoutMirroring.enabled: (calendar_context.calendar_ctrl.calendartype < 3)?false:true;
        x: (calendar_context.calendar_ctrl.calendartype < 3)?1:((calendar.width - header.width)*5.0/6.0+6 + header.width)
        y:(header.height - 20)/2;
        onClicked: {
            calendar_context.calendar_ctrl.prevYear();
        }
    }

    Button
    {
       id: prevMonth
       text:  (calendar_context.calendar_ctrl.calendartype < 3)?"<< prev month": "<< ماه قبل"
       font: persianFont.name
       width: (calendar.width - header.width)/6-7
       height: 20
       LayoutMirroring.enabled: (calendar_context.calendar_ctrl.calendartype < 3)?false:true;
       x: (calendar_context.calendar_ctrl.calendartype < 3)?((calendar.width - header.width)/6 + 2)  :  ((calendar.width - header.width)*2.0/3.0+5 + header.width);
       y:(header.height - 20)/2;
       onClicked: {
            calendar_context.calendar_ctrl.prevMonth();
       }
    }

    Button
    {
       id: prevDay
        text:  (calendar_context.calendar_ctrl.calendartype < 3)?"< prev day" : "< روز قبل"
        font: persianFont.name
        width: (calendar.width - header.width)/6-7
        height: 20
        LayoutMirroring.enabled: (calendar_context.calendar_ctrl.calendartype < 3)?false:true;
        x: (calendar_context.calendar_ctrl.calendartype < 3)?((calendar.width - header.width)/3 + 3) : ((calendar.width - header.width)/2+4 + header.width);
        y:(header.height - 20)/2;
        onClicked: {
            calendar_context.calendar_ctrl.prevDay();
        }
    }

    Button
    {
        id: nextDay
        text:  (calendar_context.calendar_ctrl.calendartype < 3)?"next day >": "روز بعد >"
        font: persianFont.name
        width: (calendar.width - header.width)/6-7
        height: 20
        LayoutMirroring.enabled: (calendar_context.calendar_ctrl.calendartype < 3)?false:true;
        x: (calendar_context.calendar_ctrl.calendartype < 3)?((calendar.width - header.width)/2+4 + header.width)  :  ((calendar.width - header.width)/3 + 3);
        y:(header.height - 20)/2;
        onClicked: {
            calendar_context.calendar_ctrl.nextDay();
        }
    }

    Button
    {
        id: nextMonth
        text:  (calendar_context.calendar_ctrl.calendartype < 3)? "next month >>": "ماه بعد >>"
        font: persianFont.name
        width: (calendar.width - header.width)/6-7
        height: 20
        LayoutMirroring.enabled: (calendar_context.calendar_ctrl.calendartype < 3)?false:true;
        x: (calendar_context.calendar_ctrl.calendartype < 3)?((calendar.width - header.width)*2.0/3.0+5 + header.width) : ((calendar.width - header.width)/6 + 2);
        y:(header.height - 20)/2;
        onClicked: {
            calendar_context.calendar_ctrl.nextMonth();
        }
    }

    Button
    {
        id: nextYear
        text:  (calendar_context.calendar_ctrl.calendartype < 3)?"next year >>>": "سال بعد >>>"
        font: persianFont.name
        width: (calendar.width - header.width)/6-7
        height: 20
        LayoutMirroring.enabled: (calendar_context.calendar_ctrl.calendartype < 3)?false:true;
        x: (calendar_context.calendar_ctrl.calendartype < 3)?((calendar.width - header.width)*5.0/6.0+6 + header.width):1;
        y:(header.height - 20)/2;
        onClicked: {
            calendar_context.calendar_ctrl.nextYear();
        }
    }

    Row
    {
        id: weeks
        spacing: 1
        x: 1
        y: (calendar_context.calendar_ctrl.calendartype >= 3) ? 90 : 30;
        width: calendar.width
        height: 20
        Repeater
        {
            id: weeksrepeater
            model: 7
            Rectangle{
                id: weekday
                color: "#111111"
                width: (calendar.width-8)/7
                height: 20

                Text {
                    id: weekdaytxt
                    color: "#ffffff"
                    text: "";
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
        Component.onCompleted: weeks.drawWeekDays()

        function drawWeekDays()
        {
            if (calendar_context.calendar_ctrl.calendartype === 1) //us
            {
                weeksrepeater.itemAt(0).children[0].text = "Sun"
                weeksrepeater.itemAt(1).children[0].text = "Mon"
                weeksrepeater.itemAt(2).children[0].text = "Tue"
                weeksrepeater.itemAt(3).children[0].text = "Wed"
                weeksrepeater.itemAt(4).children[0].text = "Thu"
                weeksrepeater.itemAt(5).children[0].text = "Fri"
                weeksrepeater.itemAt(6).children[0].text = "Sat"
            }
            else if (calendar_context.calendar_ctrl.calendartype === 2)//euro
            {
                weeksrepeater.itemAt(0).children[0].text = "Mon"
                weeksrepeater.itemAt(1).children[0].text = "Tue"
                weeksrepeater.itemAt(2).children[0].text = "Wed"
                weeksrepeater.itemAt(3).children[0].text = "Thu"
                weeksrepeater.itemAt(4).children[0].text = "Fri"
                weeksrepeater.itemAt(5).children[0].text = "Sat"
                weeksrepeater.itemAt(6).children[0].text = "Sun"
            }
            else if (calendar_context.calendar_ctrl.calendartype === 3)//jalali
            {
                weeksrepeater.itemAt(6).children[0].text = "شنبه"
                weeksrepeater.itemAt(5).children[0].text = "یکشنبه"
                weeksrepeater.itemAt(4).children[0].text = "دوشنبه"
                weeksrepeater.itemAt(3).children[0].text = "سه شنبه"
                weeksrepeater.itemAt(2).children[0].text = "چهارشنبه"
                weeksrepeater.itemAt(1).children[0].text = "پنجشنبه"
                weeksrepeater.itemAt(0).children[0].text = "جمعه"
            }
        }
    }

    Rectangle
    {
        id: calendarMain
        width: calendarWidth-4
        height: calendarHeight - header.height - weeks.height
        x: 2
        y: header.height + weeks.height + 1
        color: "#eeeeee"

        Repeater {
            id: daysArrangement
            model: calendar_context.calendar_ctrl.daysofcurrentmonth.length

            Loader
            {
                id: dayOfCalendar
                source: (calendar_context.calendar_ctrl.calendartype >= 3)?"HiCalendarFullDayItemView.qml":"HiCalendarMinDayItemView.qml";
                onLoaded:
                {
                    dayOfCalendar.item.index = index
                }
            }
        }
    }
}
