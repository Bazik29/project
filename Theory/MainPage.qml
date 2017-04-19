import QtQuick 2.7
import QtQuick.Controls 2.1


Item {
    id: theory
    Connections {
        target: TheoryScreen
    }
    Button {
        x: 36
        y: 8
        text: "Меню"
        onClicked: TheoryScreen.to_menu()
    }
    SwipeView {
        id:view
        anchors.fill: parent
        anchors.rightMargin: 36
        anchors.leftMargin: 36
        anchors.topMargin: 63
        anchors.bottomMargin: 63
        spacing: 40

        Loader {
            id: load1
            active: view.currentIndex == 0 || view.currentIndex == 1
            source: "Page1.qml"
        }
        Loader {
            active: view.currentIndex == 0 || view.currentIndex == 1 || view.currentIndex == 2
            source: "Page2.qml"
        }
        Loader {
            active: view.currentIndex == 1 || view.currentIndex == 2 || view.currentIndex == 3
            source: "Page3.qml"
        }
        Loader {
            active: view.currentIndex == 2 || view.currentIndex == 3// || view.currentIndex == 4
            source: "Page4.qml"
        }
        /*
        Loader {
            active: view.currentIndex == 3 || view.currentIndex == 4 || view.currentIndex == 5
            source: "Page5.qml"
        }
        Loader {
            active: view.currentIndex == 4 || view.currentIndex == 5 || view.currentIndex == 6
            source: "Page6.qml"
        }
        Loader {
            active: view.currentIndex == 5 || view.currentIndex == 6 || view.currentIndex == 7
            source: "Page7.qml"
        }
        Loader {
            active: view.currentIndex == 6 || view.currentIndex == 7 || view.currentIndex == 8
            source: "Page8.qml"
        }
        Loader {
            active: view.currentIndex == 7 || view.currentIndex == 8 || view.currentIndex == 9
            source: "Page9.qml"
        }
        Loader {
            active: view.currentIndex == 8 || view.currentIndex == 9 || view.currentIndex == 10
            source: "Page10.qml"
        }
        */
    }
    PageIndicator {
        x: 47
        y: 553
        width: 54
        anchors.horizontalCenterOffset: 0
        anchors.bottomMargin: 27

        interactive: true
        count: view.count
        currentIndex: view.currentIndex
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        delegate: Rectangle{
            width: 20
            height: 20
            radius: 10
            color: switch(index){
                       case 0: "red"; break;
                       case 1: "green"; break;
                       default: "blue"; break;
                   }
            opacity: index === view.currentIndex ? 0.95 : pressed ? 0.7 : 0.45

            Behavior on opacity {
                OpacityAnimator {
                    duration: 100
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if(index !== view.currentIndex) {
                        view.setCurrentIndex(index);
                    }
                }
            }
        }
    }

    Button {
        id: button
        x: 664
        y: 543
        text: qsTr("Продолжить")
        onClicked: {
            if (view.currentItem.item) {
                if (view.currentItem.item.test) {
                    if (view.currentItem.item.check()) {view.currentIndex++; test.text = "";}
                    else test.text = "Не Угадал!";
                }
                else {
                    view.currentIndex++;
                }
            }
        }

    }

    Text {
        id: test
        x: 293
        y: 18
        text: qsTr("")
        font.pixelSize: 25
    }
}
