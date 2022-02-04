import QtQuick 2.14

Rectangle {
    id: rootCircleRect
    width: 46
    height: 46
    radius: width*0.1

    property bool hasBorder : false
    property var setIcon : "\uf073"
    required property color defaultTextColor; //: "#566071"
    required property color defaultColor;
    signal click

    border.width: hasBorder ? 1 : 0
    border.color: hasBorder ? "#eef3f7" : "transparent"

    Text {
        id:circleTitle
        font.family: fontSystem.getAwesomeSolid.name
        text: setIcon
        font.pixelSize: 16
        anchors.centerIn: parent
        font.bold: true
        scale: mouseArea.containsPress ? 0.9 : 1.0
        Behavior on scale { NumberAnimation { duration: 5000; } }
        color: defaultTextColor
    }
    states: [
        State {
            name: "defultState"
            PropertyChanges { target: rootCircleRect; color: rootCircleRect.defaultColor }
            PropertyChanges { target: circleTitle; color: rootCircleRect.defaultTextColor}
        },
        State {
            name: "pressedState"
            PropertyChanges { target: rootCircleRect; color: "gray" }
            PropertyChanges { target: circleTitle; color: "black" }
        }
    ]
    color:defaultColor;

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: click();
        onPressed: {
            rootCircleRect.state = "pressedState";
        }
        onReleased: {
            rootCircleRect.state = "defultState";
        }
    }
}
