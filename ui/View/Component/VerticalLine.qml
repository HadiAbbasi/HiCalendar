import QtQuick 2.14
import QtQuick.Layouts 1.14

ColumnLayout {
    Layout.fillHeight: true;
    Item { width: 1; }
    Rectangle {

        property int heightSize : parent.height
        property int lineSize : 2

        Layout.fillHeight: true;
        height: heightSize
        width: lineSize
        color: "#f0f4f9"
    }

    Item { width: 1; }
}
