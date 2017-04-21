import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page10
    anchors.fill: parent
    property bool test: true
    function check() {
        return !ans1.checked && ans2.checked && !ans3.checked && !ans4.checked;
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

        Text {
            width: parent.width
            wrapMode:Text.WordWrap
            text: qsTr("<h3>Алгоритм структуры «ветвление» предусматривает?</h3>")
        }
        RadioButton
        {
           id:ans1
           text: "Dыбор алгоритмов"
           width: parent.width
        }
        RadioButton
        {
           id:ans2
           text: "Выбор команд(действий)" //true
           width: parent.width
        }

        RadioButton
        {
           id:ans3
           text: "Выбор данных"
           width: parent.width
        }
        RadioButton
        {
           id:ans4
           text: "Выбор обхода"
           width: parent.width
        }
        }
    }

