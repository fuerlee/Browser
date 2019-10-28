import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import com.drako 1.0


ColumnLayout {
    id: tabLayout
    spacing: 0

    Rectangle {
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignTop
        Layout.margins: 5

        height: 30
        border.color: "#ddd"

        TextInput {
            id: addressIpt
            anchors.margins: 5
            anchors.fill: parent
            font.pixelSize: 20

            onAccepted: {
                var result = siteLoader.loadSite(addressIpt.text)
                if (result === LoadResultType.SUCCESS) {
                    var strProps = siteLoader.loadProperties(addressIpt.text)
                    var props = JSON.parse(strProps)
                    var qmlPath = siteLoader.getMainQmlPath(addressIpt.text)
                    pageLoader.setSource(qmlPath, props)
                    tabLayout.parent.title = addressIpt.text
                } else {
                    pageLoader.setSource("SiteLoadingError.qml")
                }
            }
        }
    }

    Loader {
        id: pageLoader
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.topMargin: 0
    }
}
