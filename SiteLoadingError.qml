import QtQuick 2.12
import QtQuick.Layouts 1.12

RowLayout {
    anchors.fill: parent

    Text {
        Layout.maximumWidth: 400
        Layout.maximumHeight: 200
        Layout.alignment: Qt.AlignCenter
        text: "This site can’t be reached"
        font.pixelSize: 30
        wrapMode: Text.WordWrap
    }

}
