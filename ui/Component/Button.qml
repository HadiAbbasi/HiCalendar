import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

Button {
    id: control


    property string setTitle: "Title"
    property bool isEnable : true
    property bool isDefault : true

    Layout.fillWidth: true

    enabled: isEnable

    implicitHeight: Qt.platform.os === "android" || Qt.platform.os === "ios" ? 56 : 48

    text: setTitle

    contentItem: RowLayout {

        width: parent.width
        Layout.fillWidth: true

        spacing: 0

        Item { width: 5; }

        Text {
            text: control.text
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: false
            font.family: fontSystem.getContentFont.name
            font.pixelSize: appStyle.t1
            font.weight: Font.Normal
            color: isDefault ? "#ffffff" : "#3081fb"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
            scale: control.pressed ? 0.9 : 1.0
            Behavior on scale { NumberAnimation { duration: 200; } }
        }

        Item { width: 5; }
    }


    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        Layout.fillWidth: true
        opacity: enabled ? 1 : 0.3
        color: isDefault ? "#1c74fb" : "#e8f1ff"
        Behavior on color {
            ColorAnimation {
                duration: 400;
                easing.type: Easing.Linear;
            }
        }
        border.width: isDefault ? 0 : 1
        border.color: isDefault ? "#e8f1ff" : "#1c74fb"

        radius: 5
    }
}
