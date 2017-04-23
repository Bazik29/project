import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page4
    background: TFrameBackgroung{}
    anchors.fill: parent
    property bool test: true
    function check() {
        return radioGroup1.selected === ans4;
    }
    function reset() {
        radioGroup1.selected = null
    }
    TRadioGroup{
        id: radioGroup1
    }

    Column {
        id: column
        anchors.horizontalCenterOffset: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id: qwe
            width: parent.width
            wrapMode:Text.WordWrap
            text: qsTr("<h3>Какие бывают способы представления алгоритма?</h3>")
            font.pointSize: 10
        }
         TRadioButton
         {
            id:ans1
            text: "Графический"
            anchors.top: qwe.bottom
            radioGroup: radioGroup1
         }
         TRadioButton
         {
            id:ans2
            text: "Псевдокод"
            anchors.top: ans1.bottom
            radioGroup: radioGroup1
         }
         TRadioButton
         {
            id:ans3
            text: "На языке программирования"
            anchors.top: ans2.bottom
            radioGroup: radioGroup1
         }
         TRadioButton
         {
            id:ans4
            text: "Все вышеперечисленное"
            anchors.top: ans3.bottom
            radioGroup: radioGroup1
         }
    }
}

