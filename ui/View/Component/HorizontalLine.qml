import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {

    Layout.fillWidth: true;

    property var setColor : "#f0f4f9"

    Item { height: 1; }

    Rectangle {

        property int widthSize : parent.width
        property int lineSize : 2

        Layout.fillWidth: true;

        width: widthSize
        height: lineSize
        color: "#f0f4f9"
    }

    Item { height: 1; }

}
