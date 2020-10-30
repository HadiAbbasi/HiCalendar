import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQml 2.14
import "hi"

Window {
    id: mainwindow
    visible: true
    width: 900
    height: 600
    title: qsTr("Hi Calendar")
    ////signal daySelectSi(HiCalendarSelectedDayData date)

    Button{
        id: showCalendarBtn
        x: mainwindow.width - showCalendarBtn.width - 5
        text: "Show Calendar"
        onClicked: mainContainer.visible =  !mainContainer.visible
    }

    Rectangle {
        id: mainContainer
        x: 0
        y:0

        Row {
            id: rowHeader

            ComboBox {
                id: combo
                x: 5
                width: 200
                model: [ "Us Calendar", "Euro Calendar", "Jalali Calendar" ]
                onCurrentIndexChanged: {
                    if (combo.currentIndex == 0)
                    {
                        calendar_context.renewCalendar("us");
                    }
                    else if (combo.currentIndex == 1)
                    {
                        calendar_context.renewCalendar("euro");
                    }
                    else if(combo.currentIndex == 2)
                    {
                        calendar_context.renewCalendar("jalali");
                    }
                    calendar_context.calendar_ctrl.showCurrentSelectedYearMonthDay();
                    calendar.weeks.drawWeekDays()
                }
            }

            CheckBox {
                    id: chk
                    x: 5
                    text: qsTr("24 Hours")
                    anchors.left: combo.right
                    anchors.margins: 10
                    onCheckStateChanged:
                    {
                        console.log(chk.checked);
                        if (chk.checked)
                        {
                            row12.visible = false;
                            row24.visible = true;
                        }
                        else
                        {
                            row12.visible = true;
                            row24.visible = false;
                        }
                    }
            }
        }

        FontMetrics {
            id: fontMetrics
        }

        function formatText(count, modelData) {
            var data = count === 12 ? modelData + 1 : modelData;
            return data.toString().length < 2 ? "0" + data : data;
        }

        Component {
                id: delegateComponent
                Label {
                    text: mainContainer.formatText(Tumbler.tumbler.count, modelData)
                    opacity: 1.0 - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: fontMetrics.font.pixelSize * 1.25
                }
        }

        Row
        {
            y:  45
            x: 5
            Frame {
                    id: frame
                    padding: 0
                    width: mainwindow.width/3 + 5
                    height: mainwindow.height/2 - 55

                    Row {
                        id: row12

                        Tumbler {
                            id: hoursTumbler12
                            model: 12
                            delegate: delegateComponent
                        }

                        Tumbler {
                            id: minutesTumbler12
                            model: 60
                            delegate: delegateComponent
                        }

                        Tumbler {
                            id: amPmTumbler12
                            model: ["AM", "PM"]
                            delegate: delegateComponent
                        }
                    }

                    Row {
                        id: row24
                        visible: false

                        Tumbler {
                            id: hoursTumbler24
                            model: 24
                            delegate: delegateComponent
                        }

                        Tumbler {
                            id: minutesTumbler24
                            model: 60
                            delegate: delegateComponent
                        }
                    }
                }
            Button {
                id: addTaskBtn
                anchors.left: frame.right
                anchors.margins: 10
                text:  "Add Task"
            }
            ListView {
                width: 30
                height: frame.height
                anchors.left: frame.right
            }
        }

        HiCalendarView {
            id: calendar
            visible: true
            calendarWidth: mainwindow.width-10
            calendarHeight: mainwindow.height/2
            x: 5
            y: mainwindow.height/2
        }
    }
}
