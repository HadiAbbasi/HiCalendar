import QtQuick 2.0

Item {
    id: georgianHeader
    width: rect.width
    height: rect.height
    Rectangle {
        id: rect
        width: georgianTxt.width + 10
        height: 30
        color: "#eeeeee"

        Text {
            id: georgianTxt
            height: rect.height
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.Center
            verticalAlignment:  Text.Center
            text: calendar_context.calendar_ctrl.headerinfo
            font.pixelSize: 25
            font.family: englishFont.name
        }
    }
}
