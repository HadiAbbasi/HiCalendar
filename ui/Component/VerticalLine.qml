import QtQuick 2.12
import QtQuick.Layouts 1.12

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
