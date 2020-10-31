import QtQuick 2.15
import QtQuick.Layouts 1.15

Text {
    property var isDefault : true
    text: text
    font.family: calendar_context.calendar_ctrl.calendartype === 3 ? fontSystem.getContentFontFarsi.name : fontSystem.getContentFontLight.name
    font.pixelSize: 12
    font.weight: Font.Light
    font.bold: false
    color: isDefault ? "#8592a3" : "#3081fb"
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
}
