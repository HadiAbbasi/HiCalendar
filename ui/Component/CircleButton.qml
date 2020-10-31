import QtQuick 2.15

Rectangle {

    width: 48
    height: 48
    radius: width

    property bool hasBorder : false
    property var setIcon : "\uf073"
    signal click

    border.width: hasBorder ? 1 : 0
    border.color: hasBorder ? "#eef3f7" : "transparent"

    Text {
        font.family: fontSystem.getAwesomeSolid.name
        text: setIcon
        font.pixelSize: 16
        anchors.centerIn: parent
        font.bold: true
        scale: mouseArea.containsPress ? 0.9 : 1.0
        Behavior on scale { NumberAnimation { duration: 200; } }
        color: "#566071"
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: click();
    }
}
