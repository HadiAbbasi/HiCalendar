import QtQuick 2.12
import QtQuick.Layouts 1.12

RowLayout {

    property string setTitle : "Unknown"
    property string setIcon : "\uf053"
    property int setFontSize : 18
    property color setColor : "#b0b0b0"
    property bool isBrand : false
    property bool reverse : false
    property int count : 0

    signal click

    spacing: 5

    layoutDirection: reverse ? Qt.RightToLeft : Qt.LeftToRight

    Text {
        id: textIcon
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        text: setIcon
        font.family: isBrand ? fontSystem.getAwesomeBrand.name : getMouseArea.containsPress ? fontSystem.getAwesomeSolid.name : fontSystem.getAwesomeRegular.name
        font.pixelSize: setFontSize
        font.bold: true
        color: enabled ? "#8592a3" : "#d9dfe7"

        Behavior on scale { NumberAnimation { duration: 100; } }
        scale: getMouseArea.containsPress ? 0.9 : 1.0

        MouseArea {
            id:getMouseArea
            anchors.fill: parent
            onClicked: click();
        }

        Behavior on text {
            SequentialAnimation {
                NumberAnimation { target: textIcon; property: "opacity"; to: 0; duration: 100; }
                NumberAnimation { target: textIcon; property: "scale"; to: 0.6; duration: 100; }
                //PropertyAction {}
                NumberAnimation { target: textIcon; property: "opacity"; to: 1; duration: 100; }
                NumberAnimation { target: textIcon; property: "scale"; to: 1.0; duration: 100; }

            }
        }
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: textTitle
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        text: setTitle
        font.family: calendar_context.calendar_ctrl.calendartype === 3 ? fontSystem.getContentFont.name : fontSystem.getContentFont.name
        font.pixelSize: 13
        font.bold: true
        color: enabled ? "#8592a3" : "#d9dfe7"

        Behavior on scale { NumberAnimation { duration: 100; } }
        scale: getMouseAreaInner.containsPress ? 0.9 : 1.0

        MouseArea {
            id:getMouseAreaInner
            anchors.fill: parent
            onClicked: click();
        }

        Behavior on text {
            SequentialAnimation {
                NumberAnimation { target: textIcon; property: "opacity"; to: 0; duration: 100; }
                NumberAnimation { target: textIcon; property: "scale"; to: 0.6; duration: 100; }
                //PropertyAction {}
                NumberAnimation { target: textIcon; property: "opacity"; to: 1; duration: 100; }
                NumberAnimation { target: textIcon; property: "scale"; to: 1.0; duration: 100; }

            }
        }
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

}
