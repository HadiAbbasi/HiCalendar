import QtQuick 2.14
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.14

import hi 1.0

import "../Component" as Controls

Page {
    id: hiCalendarView
    title: "Hi Calendar View"

    property int calendarWidth: 500
    property int calendarHeight: 500
    property int calendarSpacings: 5
    property alias weeks: weeks;

    background: Rectangle {
        color: "transparent"
        width: calendarWidth
        height: calendarHeight
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: hiCalendarView.calendarSpacings

        Rectangle {
            id: controlBtns
            width: hiCalendarView.calendarWidth
            height: 50
            color: "#daefff"

            Controls.CircleButton {
                id: nextYear
                setIcon: (calendar_context.calendar_ctrl.calendartype === 3)?"+Y":"Y+"
                hasBorder: true
                color: "#6da6c0"
                textColor: "#ffffff"
                x:(calendar_context.calendar_ctrl.calendartype === 3)?calendarSpacings:calendarWidth-calendarSpacings-nextYear.width;
                y: 2
                onClick: {
                    calendar_context.calendar_ctrl.nextYear();
                }
            }

            Controls.CircleButton {
                id: nextMonth
                 setIcon: (calendar_context.calendar_ctrl.calendartype === 3)?"+M":"M+"
                 hasBorder: true
                 color: "#6da6c0"
                 textColor: "#ffffff"
                 x:(calendar_context.calendar_ctrl.calendartype === 3)?nextYear.x + nextYear.width + calendarSpacings : nextYear.x - calendarSpacings - nextMonth.width;
                 y: 2
                 onClick: {
                     calendar_context.calendar_ctrl.nextMonth();
                 }
            }

            Controls.CircleButton {
                id:  nextDay
                 setIcon: (calendar_context.calendar_ctrl.calendartype === 3)?"+D":"D+"
                 hasBorder: true
                 color: "#6da6c0"
                 textColor: "#ffffff"
                 x:(calendar_context.calendar_ctrl.calendartype === 3)?nextMonth.x + nextMonth.width + calendarSpacings : nextMonth.x - calendarSpacings - nextDay.width;
                 y: 2
                 onClick: {
                     calendar_context.calendar_ctrl.nextDay();
                 }
            }

            Controls.TextView {
                id: headerText
                width: calendarWidth - 8*calendarSpacings - 6*nextYear.width
                anchors.centerIn: parent
                text: calendar_context.calendar_ctrl.headerinfo;

            }

            Controls.CircleButton {
                 id: prevDay
                 setIcon: (calendar_context.calendar_ctrl.calendartype === 3)?"D-":"-D"
                 hasBorder: true
                 color: "#6da6c0"
                 textColor: "#ffffff"
                 x:(calendar_context.calendar_ctrl.calendartype === 3)?prevMonth.x-calendarSpacings-prevMonth.width : prevMonth.x + prevMonth.width + calendarSpacings
                 y: 2
                 onClick: {
                     calendar_context.calendar_ctrl.prevDay();
                 }
            }

            Controls.CircleButton {
                id: prevMonth
                 setIcon: (calendar_context.calendar_ctrl.calendartype === 3)?"M-":"-M"
                 hasBorder: true
                 color: "#6da6c0"
                 textColor: "#ffffff"
                 x:(calendar_context.calendar_ctrl.calendartype === 3)?prevYear.x-calendarSpacings-prevYear.width : prevYear.x + prevYear.width + calendarSpacings
                 y: 2
                 onClick: {
                     calendar_context.calendar_ctrl.prevMonth();
                 }
            }

            Controls.CircleButton {
                id: prevYear
                setIcon: (calendar_context.calendar_ctrl.calendartype === 3)?"Y-":"-Y"
                hasBorder: true
                color: "#6da6c0"
                textColor: "#ffffff"
                x:(calendar_context.calendar_ctrl.calendartype === 3)?calendarWidth-calendarSpacings-prevYear.width : calendarSpacings
                y: 2
                onClick: {
                    calendar_context.calendar_ctrl.prevYear();
                }
            }
        }

        ////-----------------------------------------------weeks title row
        //us->  1:Sun , 2:Mon , 3:Tue , 4:Wed , 5:Thu , 6:Fri , 7:Sat
        //euro->1:Mon , 2:Tue , 3:Wed , 4:Thu , 5:Fri , 6:Sat , 7:Sun
        //jalali->1:Sat , 2:Sun , 3:Mon , 4:Tue , 5:Wed , 6:Thu , 7:Fri
        RowLayout {
            id: weeks
            spacing: hiCalendarView.calendarSpacings
            width: hiCalendarView.calendarWidth

            Repeater {
                id: weeksrepeater
                model: 7

                Rectangle {
                    id: weekday
                    color: "transparent"
                    width: (calendarWidth - 8* hiCalendarView.calendarSpacings ) / 7
                    height: 50
                    radius: 5

                    Controls.TextView
                    {
                        id: weekdaytxt
                        text: ""
                        anchors.centerIn: parent
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
                    weeksrepeater.itemAt(6).children[0].text = "ش"
                    weeksrepeater.itemAt(5).children[0].text = "ی"
                    weeksrepeater.itemAt(4).children[0].text = "د"
                    weeksrepeater.itemAt(3).children[0].text = "س"
                    weeksrepeater.itemAt(2).children[0].text = "چ"
                    weeksrepeater.itemAt(1).children[0].text = "پ"
                    weeksrepeater.itemAt(0).children[0].text = "ج"
                }
            }
        }

        RowLayout {////-------------------------------------main part

            Item { width: hiCalendarView.calendarSpacings; }

            Item {
                id: calendarMain
                width: hiCalendarView.calendarWidth - 2 * hiCalendarView.calendarSpacings
                height: hiCalendarView.calendarHeight - 100

                Rectangle {
                    anchors.fill: parent
                    color: "transparent"
                    //border.color: "#2222ff"

                    Repeater {
                        id: daysArrangement
                        model: calendar_context.calendar_ctrl.daysofcurrentmonth.length
                        Loader{
                            id: dayOfCalendar
                            source: {
                                switch(calendar_context.calendar_ctrl.calendartype) {
                                    case 1:
                                        "/ui/View/hi/MinDayView.qml"
                                        break;
                                    case 2:
                                        "/ui/View/hi/MinDayView.qml"
                                        break;
                                    case 3:
                                        "/ui/View/hi/FullItemView.qml"
                                        break;
                                }
                            }
                            onLoaded:
                            {
                                dayOfCalendar.item.index = index
                            }
                        }
                    }
                }
            }

            Item { width: hiCalendarView.calendarSpacings; }
        }
    }

    Connections {
        target: calendar_context
        onCalendarChangedSi:
        {
            weeks.drawWeekDays()
        }
    }
}
