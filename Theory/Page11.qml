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
        Image {
            id: butRes
            width: 163
            height: 69

            anchors.left: parent.left
            anchors.leftMargin: 119
            anchors.top: parent.top
            anchors.topMargin: 204
            state: "normal"
            source: "controls/clear_normal.png"
            states: [
                State {
                    name: "normal"
                    PropertyChanges {
                        target: butRes
                        source: "controls/clear_normal.png"
                    }
                },
                State {
                    name: "hover"
                    PropertyChanges {
                        target: butRes
                        source: "controls/clear_hover.png"
                    }
                },
                State {
                    name: "cliked"
                    PropertyChanges {
                        target: butRes
                        source: "controls/clear_clicked.png"
                    }
                }
            ]
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: butRes.state = "hover"
                onExited: butRes.state = "normal"
                onPressed: {
                    butRes.state = "hover"
                    theory.maxpageopen = 0;
                    view.currentIndex = 0;
                    TheoryScreen.resetProgress();
                    butnext.visible = true;
                }
                onReleased: butRes.state = "hover"
            }
        }
        ScrollBar.vertical: ScrollBar {}
    }
}

