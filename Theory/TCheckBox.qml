import QtQuick 2.0
import QtQuick.Controls 2.1

Item {
    id: item1
    property bool checked: false
    property string text: ""
    height: image.height
    Image {
        id: image
        y: 0
        width: 40
        height: 35
        source: "controls/check_unchecked.png"
        state: checked ? "checked" : "unchecked"
        states: [
            State {
                name: "unchecked"
                PropertyChanges {
                    target: image
                    source: "controls/check_unchecked.png"
                }
            },
            State {
                name: "checked"
                PropertyChanges {
                    target: image
                    source: "controls/check_checked.png"
                }
            }
        ]
        MouseArea{
            anchors.fill: parent
            onPressed: checked = !checked
        }
    }
    Text {
        id: t
        text: item1.text
        font.pointSize: 13
        anchors.leftMargin: 7
        anchors.verticalCenter: image.verticalCenter
        anchors.left: image.right
    }
}
 