import QtQuick 2.7

Rectangle {
        id: custbutton

        property string text
        signal clicked

        color: "yellow"
        radius: 5
        border {
            color: "grey"
            width: 2
        }


        //Ширина и высота кнопки по умолчанию
        implicitWidth: buttonText.width + radius
        implicitHeight: buttonText.height + radius

        Text {
            id: buttonText
            anchors.centerIn: parent
            padding: 5
            text: custbutton.text
            font.pointSize: 14
        }
        MouseArea{
            hoverEnabled: true
            anchors.fill: parent
            onClicked: custbutton.clicked()
            onPressed: {
                custbutton.color = "red"
                custbutton.border.color = "blue"
            }
            onReleased:{
                custbutton.color = "lightgreen"
                custbutton.border.color = "blue"
            }
            onEntered: {
                custbutton.color = "lightgreen"
                custbutton.border.color = "blue"
            }
            onExited: {
                custbutton.color = "yellow"
                custbutton.border.color = "grey"
            }
        }
}
