import QtQuick 2.0

Item {
    id: jalaliHeader
    width: rect.width;
    height: rect.height;
    Rectangle {
        id: rect
        width: jalaliTxt.width + 10
        height: 90
        color: "#eeeeee"

        Text {
            id: jalaliTxt
            height: rect.height
            text: calendar_context.calendar_ctrl.headerinfo
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.Center
            verticalAlignment:  Text.Center
            font.family: persianFont.name
            font.pixelSize: 18
        }
    }
}


