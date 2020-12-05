import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import "../Component" as Controls

Pane {

    id: footer
    background: Rectangle {
        color: "#f2f6f9"
    }

    RowLayout {

        anchors.fill: parent

        Item { width: 10; }

        Text {
            width: parent.width
            Layout.fillWidth: true
            font.family: fontSystem.getContentFontLight.name
            font.pixelSize: 12
            font.weight: Font.Light
            font.bold: false
            verticalAlignment: Text.AlignVCenter
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            text: qsTr("Copyright © 2020 Hi Calendar Pro ™, All Right Reserved.")
            color: "#515c6d"
        }

        Controls.HorizontalSpacer { }
    }
}
