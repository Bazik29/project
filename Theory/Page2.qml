import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page2
    background: TFrameBackgroung{}
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
        id: column
        anchors.fill: parent
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id: qwe
            width: parent.width
            wrapMode:Text.WordWrap
            text: qsTr("<h3>Выбирите свойства, характерные для алогритма:</h3>")
            font.pointSize: 10
        }
        TCheckBox
        {
            id: ans1
            anchors.top: qwe.bottom
            text: "Дискретность"
            checked: false
        }
        TCheckBox
        {
            id: ans2
            anchors.top: ans1.bottom
            text: "Упругость"
            anchors.topMargin: 5
            checked: false
        }
        TCheckBox
        {
            id: ans3
            anchors.top: ans2.bottom
            text: "Детерминированность"
            anchors.topMargin: 5
            checked:false
        }
        TCheckBox
        {
            id: ans4
            anchors.top: ans3.bottom
            text: "Гибкость"
            anchors.topMargin: 5
            checked:false
        }
    }
}
