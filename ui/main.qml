import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

import hi 1.0

import "./View/hi"
import "./View/Component" as Controls

ApplicationWindow {
    id: appRoot
    width: 500
    height: 650
    title: qsTr("Hi Calendar")
    visible: true

    Controls.FontSystem {
        id: fontSystem
    }

    background: Rectangle {
        color: "#ffffff"
    }

    Drawer {
        id: settingDrawer
        width: appRoot.width
        height: 160
        edge: Qt.TopEdge

        contentData: ColumnLayout {
            width: parent.width
            Layout.fillWidth: true

            Item { height: 5; }

            Text {
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.family: fontSystem.getContentFont.name
                font.pixelSize: settingDrawer.height/12
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
                    }
                }

                Controls.RadioCheck {
                    id: radioEuro
                    text: "Georgian (Euro)"
                    onClicked: {
                        calendar_context.renewCalendar("euro");
                    }
                }

                Controls.RadioCheck {
                    id: radioIr
                    text: "Jalali (فارسی)"
                    onClicked: {
                        calendar_context.renewCalendar("jalali");
                    }
                }
            }
        }
    }

    header: Controls.Header {
        id: header
        height: 70
        onClick: {
            settingDrawer.open();
        }
    }


    HiCalendarView {
        id: calendar
        calendarWidth: appRoot.width
        calendarHeight: appRoot.height - header.height - footer.height
        visible: true
        //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    }

    footer: Controls.Footer {
        id:  footer
        height: 40;
    }
}
