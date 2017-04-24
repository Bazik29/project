import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page11
    background: TFrameBackgroung{}
    anchors.fill: parent
    clip:true
    property bool test: false

    Flickable {
        id: flickable
        anchors.rightMargin: 15
        anchors.bottomMargin: 15
        anchors.leftMargin: 15
        anchors.topMargin: 15
        anchors.fill: parent
        contentHeight: textt.height

        Text {
            id:textt
            font.pointSize:12
            color: "black"
            width: parent.width
            wrapMode:Text.WordWrap
            text:
            "<h2>Поздравляем с завершением теоретического курса</h2><br>
                Не забудьте посетить интересные тренировочные режимы, чтобы закрепить полученные знания.
                <br><h6>Вы можете сбросить сохраненный прогресс изучения теоритического материала нажав соответсвующию кнопку.</h6>
            "
        }
        Image {
            id: butRes
            width: 163
            height: 69
            anchors.top: parent.top
            anchors.topMargin: 124
            anchors.left: parent.left
            anchors.leftMargin: 0

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

