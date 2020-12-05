import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import "../Component" as Controls

Pane {
    id: header

    background: Rectangle {
        color: "#f2f6f9"
    }

    signal click;

    RowLayout {
        width: parent.width
        Layout.fillWidth: true
        height: 48

        Item { width: 10; }

        Text {
            font.family: fontSystem.getAwesomeSolid.name
            text: "\uf073"
            font.pixelSize: 24
            font.bold: true
            color: "#5774ee"
            scale: mouseArea.containsPress ? 0.9 : 1.0
            Behavior on scale { NumberAnimation { duration: 200; } }
        }

        Item { width: 5; }

        Text {
            width: parent.width
            Layout.fillWidth: true
            font.family: fontSystem.getContentFont.name
            font.pixelSize: 16
            text: qsTr("Hi Calendar Pro ™")
            color: "#5774ee"
        }

        Controls.HorizontalSpacer { }

        Rectangle {

            width: 48
            height: 48
            radius: width

            Text {
                font.family: fontSystem.getAwesomeSolid.name
                text: "\uf0c9"
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

        Item { width: 5; }
    }
}
