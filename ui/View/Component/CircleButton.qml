import QtQuick 2.14

Rectangle {

    width: 46
    height: 46
    radius: width

    property bool hasBorder : false
    property var setIcon : "\uf073"
    property var textColor: "#566071"
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
        color: textColor
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: click();
    }
}
