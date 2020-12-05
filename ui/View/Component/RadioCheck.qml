import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

RadioButton {
    id: control
//    property var setIcon : ""
    text: qsTr("RadioButton")
    font.family: fontSystem.getContentFont.name
//    font.pixelSize: 14
    checked: false

//    indicator: Rectangle {
//        implicitWidth: 26
//        implicitHeight: 26
//        x: control.leftPadding
//        y: parent.height / 2 - height / 2
//        radius: 13
//        border.color: control.checked ? "#5774ee" : "#a9b6c6"
//        Behavior on color { ColorAnimation { duration: 200} }
//        color: "#ffffff"

//        Rectangle {
//            width: 14
//            height: 14
//            x: 6
//            y: 6
//            radius: 7
//            color: control.checked ? "#5774ee" : "#434344"
//            visible: control.checked
//            Behavior on color { ColorAnimation { duration: 200} }

//        }
//    }

//    contentItem: RowLayout {

//        width: parent.width
//        Layout.fillWidth: true


//        Text {
//            text: setIcon
//            font.family: fontSystem.getAwesomeRegular.name
//            font.pixelSize: 14
//            font.weight: Font.Light
//            opacity: enabled ? 1.0 : 0.3
//            color: control.checked ? "#5774ee" : "#555"
//            horizontalAlignment: Text.AlignHCenter
//            verticalAlignment: Text.AlignVCenter
//            elide: Text.ElideRight
//            visible: setIcon ? true : false
//        }

//        Text {
//            text: control.text
//            font: control.font
//            fontSizeMode: Text.Fit
//            opacity: enabled ? 1.0 : 0.3
//            color: control.checked ? "#5774ee" : "#555"
//            verticalAlignment: Text.AlignVCenter
//            leftPadding: control.indicator.width + control.spacing
//            wrapMode: Text.WordWrap
//            Behavior on color { ColorAnimation { duration: 200} }

//        }

//        HorizontalSpacer { visible: setIcon ? true : false }
//    }
}
