import QtQuick 2.0

Rectangle {
    color: "lightgray"
    property alias textValue: helloText.text

    Text {
        id: helloText
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 24
    }
}