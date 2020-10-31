import QtQuick 2.15
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.15

import hi 1.0

import "Component" as Controls

Page {
    id: page

    background: Rectangle {
        color: "transparent"
    }

    //    //us->  1:Sun , 2:Mon , 3:Tue , 4:Wed , 5:Thu , 6:Fri , 7:Sat
    //    //euro->1:Mon , 2:Tue , 3:Wed , 4:Thu , 5:Fri , 6:Sat , 7:Sun
    //    //jalali->1:Sat , 2:Sun , 3:Mon , 4:Tue , 5:Wed , 6:Thu , 7:Fri

    property int calendarWidth: 640
    property int calendarHeight: 240
    property alias weeks: weeks;

    title: "Calendar View"

    ColumnLayout {
        anchors.fill: parent
        spacing: 5

        Row {
            id: weeks
            spacing: 5

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Repeater {
                id: weeksrepeater
                model: 7

                Rectangle {
                    id: weekday
                    color: "transparent"
                    width: 58
                    height: 48
                    radius: 5

                    Controls.TextView {
                        id: weekdaytxt
                        color: "#a9b6c6"
                        font.pixelSize: 16
                        text: "";
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

        RowLayout {
            width: parent.width
            Layout.fillWidth: true

            Item { width: 5; }

            Rectangle {
                id: calendarMain
                Repeater {
                    id: daysArrangement
                    model: calendar_context.calendar_ctrl.daysofcurrentmonth.length
                    Loader
                    {
                        id: dayOfCalendar
                        source: {

                            switch(calendar_context.calendar_ctrl.calendartype) {
                            case 1:
                                calSimpleMode.checked ? "View/MinDayView.qml" : "View/FullItemView.qml"
                                break;
                            case 2:
                                calSimpleMode.checked ? "View/MinDayView.qml" : "View/FullItemView.qml"
                                break;
                            case 3:
                                calSimpleMode.checked ? "View/MinDayView.qml" : "View/FullItemView.qml"
                                break;
                            }
                        }
                        onLoaded: dayOfCalendar.item.index = index
                    }
                }
            }

            Item { width: 5; }
        }
    }
}
