import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page2
    anchors.fill: parent
    property bool test: true
    function check() {
        return ans1.checked && !ans2.checked && ans3.checked && !ans4.checked;
    }
    function reset() {
        ans1.checked = false;
        ans2.checked = false;
        ans3.checked = false;
        ans4.checked = false;
    }

    Column {
        anchors.fill: parent
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            width: parent.width
            wrapMode:Text.WordWrap
            text: qsTr("<h3>Выбирите свойства, характерные для алогритма</h3>")
        }
        CheckBox
        {
            id: ans1
            text: "Дискретность"
            checked: false
        }
        CheckBox
        {
            id: ans2
            text: "Упругость"
            checked: false
        }
        CheckBox
        {
            id: ans3
            text: "Детерминированность"
            checked:false
        }
        CheckBox
        {
            id: ans4
            text: "Гибкость"
            checked:false
        }
    }
}
