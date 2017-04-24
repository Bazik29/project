import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page10
    background: TFrameBackgroung{}
    anchors.fill: parent
    property bool test: true
    padding: 12
    function check() {
        return !ans1.checked && !ans3.checked && !ans4.checked && ans2.checked;
    }
    function reset() {
        ans1.checked = false;
        ans2.checked = false;
        ans3.checked = false;
        ans4.checked = false;
    }

    Column {
        id: column
        anchors.bottomMargin: 10
        anchors.fill: parent
        spacing: 10

        Text {
            id: qwe
            width: parent.width
            wrapMode:Text.WordWrap
            text: qsTr("<h3>Алгоритм структуры «ветвление» предусматривает:</h3>")
            font.pointSize: 10
        }
        TCheckBox
        {
           id:ans1
           text: "Выбор алгоритмов"
           anchors.top: qwe.bottom
        }
        TCheckBox
        {
           id:ans2
           text: "Выбор команд (действий)" //true
           anchors.top: ans1.bottom
           anchors.topMargin: 5
        }

        TCheckBox
        {
           id:ans3
           text: "Выбор данных"
           anchors.top: ans2.bottom
           anchors.topMargin: 5
        }
        TCheckBox
        {
           id:ans4
           text: "Выбор обхода"
           anchors.top: ans3.bottom
           anchors.topMargin: 5
        }
    }
    }

