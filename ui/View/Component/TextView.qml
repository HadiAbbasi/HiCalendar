import QtQuick 2.14
import QtQuick.Layouts 1.14

Text {
    id: txtView
    text: ""
    font.family: calendar_context.calendar_ctrl.calendartype === 3 ? fontSystem.getContentFontFarsi.name : fontSystem.getContentFontLight.name
    font.pixelSize: 12 //16
    font.weight: Font.Light
    font.bold: false
    color: "#8592a3"
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
}
