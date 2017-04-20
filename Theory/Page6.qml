import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page2
    anchors.fill: parent
    property bool test: true
    function check() {
        return ans3.checked;
    }
    function reset() {
        ans1.checked = false;
        ans2.checked = false;
        ans3.checked = false;
        ans4.checked = false;
    }

    Column {
        anchors.fill: parent
        spacing: 35
        //anchors.horizontalCenter: parent.horizontalCenter
        Text {
            width: parent.width
            wrapMode:Text.WordWrap
            text: qsTr("<h3>Какой символ обозначает блок 'ввод-вывод' в блок-схеме?</h3>")
        }
        RadioButton {
            id:ans1
            width: parent.width
            anchors.left: parent.left
            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: "<img src='images/p6.4.PNG'>"
            }
        }
        RadioButton {
            id:ans2
            width: parent.width
            anchors.left: parent.left
            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: "<img src='images/p6.3.png'>"
            }
        }
        RadioButton {
            id:ans3
            width: parent.width
            anchors.left: parent.left
            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: "<img src='images/p6.1.png'>"
            }
        }
        RadioButton {
            id:ans4
            width: parent.width
            anchors.left: parent.left
            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: "<img src='images/p6.2.PNG'>"
            }
        }
    }
}

