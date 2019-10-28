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

@RestController
public class HelloController {

    @GetMapping(
            value = "/main.qml",
            produces = MediaType.APPLICATION_OCTET_STREAM_VALUE)
    public byte[] mainQml() throws IOException {
        ClassPathResource resource = new ClassPathResource("main.qml");
        return IOUtils.toByteArray(resource.getInputStream());
    }

    @GetMapping(
            value = "/getProperties",
            produces = MediaType.APPLICATION_JSON_VALUE)
    public Object getProperties() {
        return "{\"textValue\": \"Hello World!\"}";
    }
}