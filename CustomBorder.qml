import QtQuick 2.12

Rectangle {

    property bool commonBorder : true

    property int leftWidth : 0
    property int rightWidth : 0
    property int topWidth : 0
    property int bottomWidth : 0

    property int commonWidth : 0

    z : -1

    property string borderColor : "white"

    color: borderColor

    anchors {
        left: parent.left
        right: parent.right
        top: parent.top
        bottom: parent.bottom

        topMargin    : commonBorder ? -commonWidth : -topWidth
        bottomMargin : commonBorder ? -commonWidth : -bottomWidth
        leftMargin   : commonBorder ? -commonWidth : -leftWidth
        rightMargin  : commonBorder ? -commonWidth : -rightWidth
    }
}