import QtQuick 2.14
import QtQuick.Layouts 1.14

import "../Component" as Controls

Rectangle {
    id: dayItem

    property int index: 0;

    width: Math.min(calendarMain.width/7 , calendarMain.height/6);
    height: width
    radius: width/2

    x: {
        if(calendar_context.calendar_ctrl.calendartype >= 3)
        {
            (7-calendar_context.calendar_ctrl.daysofcurrentmonth[index].getDayOfCustomWeek()) * (calendarMain.width/7)+((calendarMain.width/7) - width)/2
        }
        else
        {
            (calendar_context.calendar_ctrl.daysofcurrentmonth[index].getDayOfCustomWeek()-1) * (calendarMain.width/7)+((calendarMain.width/7) - width)/2;
        }
    }

    y: (calendar_context.calendar_ctrl.daysofcurrentmonth[index].getDayInCustomWeekNOfMonth()-1) * (calendarMain.height/6) + ((calendarMain.height/6) - width)/2

    border.width: {
        if (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay())
        {
            4
        }
        else if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())
        {
            2
        }
        else if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].is_holiday === true)
        {
            1
        }
        else
        {
            1
        }
    }

    color: updateColor();
    function updateColor(){ 
        if (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay())
        {
            return "#5774ee";
        }
        else if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())
        {
            return "#ccffcc";
        }
        else if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].is_holiday === true)
        {
            return "#ffcccc";
        }
        else
        {
            return "#eeeeee";
        }
    }

    border.color: {
        if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())
        {
            "#22ff22"
        }
        else if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].is_holiday === true)
        {
            "#ff0000"
        }
        else
        {
            "#aaaaaa"
        }
    }

    opacity: {
        if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].isDayOver())
        {
            0.5
        }
        else
        {
            1
        }
    }

    Behavior on color {
        id:rootBehavior
        enabled:false;
        ColorAnimation {
            id:colorAnim
            duration: 200;
            easing.type: Easing.Linear;
        }
    }

    Controls.TextView   {
        id: georgianText
        anchors.centerIn: parent
        color: {
            if (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay())
            {
                "#ffffff"
            }
            else if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].isToday())
            {
                "#222222"
            }
            else if (calendar_context.calendar_ctrl.daysofcurrentmonth[index].is_holiday === true)
            {
                "#ff0000"
            }
            else
            {
                "#222222"
            }
        }
        font.pixelSize: {
            if (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay())
            {
                dayItem.width/2
            }
            else
            {
                dayItem.width/3
            }
        }
        font.family: {
            if (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay())
            {
                fontSystem.getContentFont.name
            }
            else
            {
                fontSystem.getContentFontLight.name
            }
        }
        font.weight: {
            if (calendar_context.calendar_ctrl.daysofcurrentmonth[index] === calendar_context.calendar_ctrl.getCurrentSelectedDay())
            {
                Font.Bold
            }
            else
            {
                Font.Light
            }
        }
        text: qsTr(calendar_context.calendar_ctrl.daysofcurrentmonth[index].getDayOfCustomMonth().toString())
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            calendar_context.calendar_ctrl.selectDayByClick(calendar_context.calendar_ctrl.daysofcurrentmonth[index]);
        }
    }

    function enableBehaviorOnColor()
    {
        if(calendar_context.calendar_ctrl.daysofcurrentmonth[index] ===
                calendar_context.calendar_ctrl.getCurrentSelectedDay())
        {
            dayItem.color.a = 0.1;
            rootBehavior.enabled=true;
            dayItem.color = updateColor();
        }
        else{
            rootBehavior.enabled=false;
        }
    }
}
