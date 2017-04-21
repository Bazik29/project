import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page2
    anchors.fill: parent
    property bool test: true
    function check() {
        return ans1.checked;
    }
    function reset() {
        ans1.checked = false;
        ans2.checked = false;
        ans3.checked = false;
        ans4.checked = false;
    }

    Text {
        id: title
        wrapMode:Text.WordWrap
        text: qsTr("<h3>Какой символ обозначает блок 'ввод-вывод' в блок-схеме?</h3>")
        verticalAlignment: Text.AlignTop
    }

    RadioButton {
        id: ans4
        x: 198
        y: 230
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

    RadioButton {
        id: ans3
        x: 198
        y: 300
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

    RadioButton {
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

    RadioButton {
        id: ans1
        x: 198
        y: 60
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

