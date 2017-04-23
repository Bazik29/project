import QtQuick 2.0

Item {
    id: radioButton
    property bool checked: false
    property string text: ""
    property TRadioGroup radioGroup
    height: image.height
    Image {
        id: image
        y: 0
        width: 40
        height: 40
        source: "controls/radio_empty.png"
        state: radioGroup.selected === radioButton  ? "checked" : "unchecked"
        states: [
            State {
                name: "unchecked"
                PropertyChanges {
                    target: image
                    source: "controls/radio_empty.png"
                }
            },
            State {
                name: "checked"
                PropertyChanges {
                    target: image
                    source: "controls/radio_full.png"
                }
            }
        ]
        MouseArea {
            width: 40
            height: 40
            anchors.fill: parent
            onPressed: {
                radioButton.radioGroup.selected = radioButton;
            }
        }
    }
    Text {
        id: t
        text: radioButton.text
        font.pointSize: 13
        anchors.leftMargin: 10
        anchors.verticalCenter: image.verticalCenter
        anchors.left: image.right
    }
}
