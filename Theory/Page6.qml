import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page2
    background: TFrameBackgroung{}
    anchors.fill: parent
    property bool test: true
    function check() {
        return radioGroup1.selected === ans1;
    }
    function reset() {
        radioGroup1.selected = null
    }

    Text {
        id: title
        wrapMode:Text.WordWrap
        text: qsTr("<h3>Какой символ обозначает блок 'ввод-вывод' в блок-схеме?</h3>")
        verticalAlignment: Text.AlignTop
        font.pointSize: 10
    }
    TRadioGroup{
        id: radioGroup1
    }
    TRadioButton {
        id: ans4
        x: 198
        y: 230
        radioGroup: radioGroup1
        anchors.verticalCenterOffset: 0
        anchors.left: img3.right
        anchors.leftMargin: 14
        anchors.verticalCenter: img3.verticalCenter
    }

    Text {
        id: img4
        x: 13
        y: 290
        text: "<img src='images/p6.4.PNG'>"
        anchors.horizontalCenterOffset: 0
        anchors.top: img3.bottom
        anchors.topMargin: 16
        anchors.horizontalCenter: img3.horizontalCenter
    }

    TRadioButton {
        id: ans3
        x: 198
        y: 300
        radioGroup: radioGroup1
        anchors.verticalCenterOffset: 0
        anchors.left: img4.right
        anchors.leftMargin: 14
        anchors.verticalCenter: img4.verticalCenter
    }

    Text {
        id: img3
        x: 13
        y: 220
        text: "<img src='images/p6.3.png'>"
        anchors.top: img2.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: img2.horizontalCenter
    }

    TRadioButton {
        radioGroup: radioGroup1
        id: ans2
        x: 198
        y: 146
        anchors.verticalCenterOffset: 0
        anchors.verticalCenter: img2.verticalCenter
        anchors.left: img2.right
        anchors.leftMargin: 20
    }

    Text {
        id: img2
        x: 19
        y: 121
        text: "<img src='images/p6.2.PNG'>"
        anchors.horizontalCenter: img1.horizontalCenter
        anchors.top: img1.bottom
        anchors.topMargin: 10
    }

    TRadioButton {
        id: ans1
        x: 198
        y: 60
        radioGroup: radioGroup1
        anchors.left: img1.right
        anchors.leftMargin: 21
        anchors.verticalCenter: img1.verticalCenter
    }

    Text {
        id: img1
        x: 7
        y: 39
        text: "<img src='images/p6.1.png'>"
    }

}

