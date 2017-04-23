import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page11
    background: TFrameBackgroung{}
    anchors.fill: parent
    clip:true
    property bool test: false

    Flickable {
        anchors.fill: parent
        contentHeight: textt.height

        Text {
            id:textt
            font.pointSize:12
            color: "black"
            width: parent.width
            wrapMode:Text.WordWrap
            text:
                "<h2>END SLIDE</h2>


            "
        }

        Button {
            id: resetbut
            x: 258
            y: 208
            text: qsTr("Сбросить")
            onClicked: {
                theory.maxpageopen = 0;
                view.currentIndex = 0;
                TheoryScreen.resetProgress();
                butnext.visible = true;
            }
        }
        ScrollBar.vertical: ScrollBar {}
    }
}

