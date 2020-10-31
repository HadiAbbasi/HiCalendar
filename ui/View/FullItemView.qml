import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../Component" as Controls

Rectangle {
    id: dayItem

    property int index: 0;

    width: 64
    height: 64

    x: (calendar_context.calendar_ctrl.calendartype >= 3)?(7-calendar_context.calendar_ctrl.daysofcurrentmonth[index].getDayOfCustomWeek()) * (dayOfCalendar.width + 3):
                                                           (calendar_context.calendar_ctrl.daysofcurrentmonth[index].getDayOfCustomWeek()-1) * (dayOfCalendar.width + 3)
    y: (calendar_context.calendar_ctrl.daysofcurrentmonth[index].getDayInCustomWeekNOfMonth()-1) * (dayOfCalendar.height+3)


    border.width: ((calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday()) ? 0 : ((calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) ? 2 : 0))
    radius: width
    color: (calendar_context.calendar_ctrl.daysofcurrentmonth[index].is_holiday === true) ? "#f8f8f8" : ((calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())?"#5774ee": ((calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay())?"transparent":"#ffffff"))
    border.color: ((calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())?"#5774ee": ((calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay())?"#dde3fb":"#000000"))
    opacity: ((calendar_context.calendar_ctrl.daysofcurrentmonth[index].isDayOver())?0.5:1)

    Behavior on color {
        ColorAnimation {
            duration: 200;
            easing.type: Easing.Linear;
        }
    }

    Controls.TextView   {
        id: daynumtxt
        anchors.centerIn: parent
        color: {
            if((calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) && !(calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())) {
                "#5774ee"
            } else {
                (calendar_context.calendar_ctrl.daysofcurrentmonth[index].is_holiday === true) ? "#f00" : (calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday()) ? "#ffffff" : "#4c4c4c";
            }
        }
        font.pixelSize: (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) ? 18 : 14
        font.weight: (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) ? Font.ExtraBold : Font.Normal
        text: qsTr(calendar_context.calendar_ctrl.daysofcurrentmonth[index].getDayOfCustomMonth().toString())
    }

    Controls.TextView   {
        id: georgianText
        x:35
        y:40
        color: {
            if((calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) && !(calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())) {
                "#5774ee"
            } else {
                (calendar_context.calendar_ctrl.daysofcurrentmonth[index].is_holiday === true) ? "#f00" : (calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday()) ? "#ffffff" : "#4c4c4c";
            }
        }
        font.pixelSize: (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) ? 10 : 8
        font.weight: (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) ? Font.ExtraBold : Font.Normal
        text: qsTr(calendar_context.calendar_ctrl.daysofcurrentmonth[index].getGeorgianDay().toString())
    }

    Controls.TextView   {
        id: islamicText
        x:15
        y:10
        color: {
            if((calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) && !(calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())) {
                "#5774ee"
            } else {
                (calendar_context.calendar_ctrl.daysofcurrentmonth[index].is_holiday === true) ? "#f00" : (calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday()) ? "#ffffff" : "#4c4c4c";
            }
        }
        font.pixelSize: (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) ? 9 : 7
        font.weight: (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay()) ? Font.ExtraBold : Font.Normal
        text: qsTr(calendar_context.calendar_ctrl.daysofcurrentmonth[index].getIslamicDay().toString())
    }


    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            calendar_context.calendar_ctrl.selectDayByClick(calendar_context.calendar_ctrl.daysofcurrentmonth[index]);
        }
    }
}
