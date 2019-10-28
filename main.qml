import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import com.drako 1.0

Window {
    id: window
    visible: true
    visibility: "Maximized"
    title: qsTr("Drako Web Browser")

    Action {
            id: newTabAction
            text: "New Tab"
            shortcut: "Ctrl+T"
            onTriggered: {
                var component = Qt.createComponent("TabComponent.qml")
                mainTabView.addTab("New Tab", component)
                mainTabView.currentIndex = mainTabView.count - 1
            }
            tooltip: "Open a New Tab"
        }

    SiteLoader {
        id: siteLoader
    }

    TabView {
        id: mainTabView
        anchors.fill: parent

        style: TabViewStyle {
            property color frameColor: "#ddd"
            property color fillColor: "#f9f9f9"
            frameOverlap: 1
            frame: Rectangle {
                color: "#f9f9f9"
                border.color: frameColor
            }
            tabBar: Rectangle {
                color: "#ddd"
            }
            tab: Rectangle {
                color: styleData.selected ? fillColor : frameColor
                implicitWidth: Math.max(tabText.width + 30, 80)
                implicitHeight: 30

                Rectangle { height: 1 ; width: parent.width ; color: frameColor}
                Rectangle { height: parent.height ; width: 1; color: frameColor}
                Rectangle { x: parent.width -1; height: parent.height ; width: 1; color: frameColor}

                Text {
                    id: tabText
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.margins: 5
                    text: styleData.title
                }

                Rectangle {
                    id: closeBtn
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 5
                    anchors.rightMargin: 5
                    implicitWidth: 16
                    implicitHeight: 16
                    radius: width/2
                    color: styleData.selected ? "#f9f9f9" : "#ddd"
                    opacity: 0.6

                    Text {
                        text: "✕"
                        anchors.centerIn: parent
                        font.pixelSize: 14
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: closeBtn.opacity = 1
                        onExited: closeBtn.opacity = 0.6
                        onClicked: {
                            if (mainTabView.count === 1) {
                                Qt.quit()
                            } else {
                                mainTabView.removeTab(styleData.index)
                            }
                        }
                    }
                }
            }
        }

        Tab {
            title: "New Tab"
            TabComponent {}
        }
    }
}