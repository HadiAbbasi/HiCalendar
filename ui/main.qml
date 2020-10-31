import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import hi 1.0

import "./Component" as Controls

ApplicationWindow {
    id: appRoot
    visible: true
    width: 500
    height: 650
    title: qsTr("Hi Calendar")

    property alias calSimpleMode : radioSimple

    background: Rectangle {
        color: "#ffffff"
    }

    FontSystem {
        id: fontSystem
    }

    Drawer {
        id: settinDrawer
        width: appRoot.width
        height: appRoot.height / 2.5
        edge: Qt.TopEdge

        contentData: ColumnLayout {
            width: parent.width
            Layout.fillWidth: true

            Item { height: 5; }

            Text {
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.family: fontSystem.getContentFont.name
                font.pixelSize: 18
                text: qsTr("Calendar Type")
                color: "#4b5668"
            }

            Controls.HorizontalLine { }

            RowLayout {

                width: parent.width
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                Controls.RadioCheck {
                    id: radioUS
                    text: "Georgian (US)"
                    checked: true
                    onClicked: {
                        calendar_context.renewCalendar("us");
                        calendar_context.calendar_ctrl.showCurrentSelectedYearMonthDay();
                        calendar.weeks.drawWeekDays()
                    }
                }

                Controls.RadioCheck {
                    id: radioEuro
                    text: "Georgian (Euro)"
                    onClicked: {
                        calendar_context.renewCalendar("euro");
                        calendar_context.calendar_ctrl.showCurrentSelectedYearMonthDay();
                        calendar.weeks.drawWeekDays()
                    }
                }

                Controls.RadioCheck {
                    id: radioIr
                    text: "Jalali (فارسی)"
                    onClicked: {
                        calendar_context.renewCalendar("jalali");
                        calendar_context.calendar_ctrl.showCurrentSelectedYearMonthDay();
                        calendar.weeks.drawWeekDays()
                    }
                }
            }

            Controls.HorizontalLine { }

            Item { height: 5; }

            Text {
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.family: fontSystem.getContentFont.name
                font.pixelSize: 18
                text: qsTr("Calendar Mode")
                color: "#4b5668"
            }

            Controls.HorizontalLine { }

            RowLayout {

                width: parent.width
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                Controls.RadioCheck {
                    id: radioSimple
                    text: "Simple Mode"
                    checked: true
                    onClicked: {

                    }
                }

                Controls.RadioCheck {
                    id: radioFull
                    text: "Full Mode"
                    onClicked: {

                    }
                }
            }
        }
    }

    header: Header {
        onClick: {
            settinDrawer.open();
        }
    }

    contentData: ColumnLayout {

        width: parent.width
        Layout.fillWidth: true
        spacing: 5

        Item { height: 15; }

        RowLayout {

            width: parent.width
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Item { width: 25; }

            Controls.CircleButton {
                setIcon:  "\uf053"
                hasBorder: true
                onClick: {
                    calendar_context.calendar_ctrl.prevMonth();
                }
            }

            Controls.HorizontalSpacer { }

            Controls.TextView {
                width: parent.width
                Layout.fillWidth: true
                font.pixelSize: 16
                text: calendar_context.calendar_ctrl.headerinfo
            }

            Controls.HorizontalSpacer { }

            Controls.CircleButton {
                setIcon:  "\uf054"
                hasBorder: true
                onClick: {
                    calendar_context.calendar_ctrl.nextMonth();
                }
            }

            Item { width: 25; }
        }


        Item { height: 5; }


        Controls.HorizontalLine { }

        Component.onCompleted: {
            calendar_context.renewCalendar("us");
            calendar_context.calendar_ctrl.showCurrentSelectedYearMonthDay();
            calendar.weeks.drawWeekDays()
        }

        Item { height: 5; }

        HiCalendarView {
            id: calendar
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            visible: true
        }

        Item { height: 5; }

    }

    footer: Footer { height: 48; }
}
