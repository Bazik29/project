import QtQuick 2.7
import QtQuick.Controls 2.1
//import ":/Theory/"
//import ":/Theory/TheoryScript.js" as Logic

Item {
    id: theory

    Button{
        x: 17
        y: 8
        text: "Меню"
        onClicked: mainloader.source = "MainMenuPage.qml"
    }


    SwipeView {
        id: view
        Repeater {
            model: 6
            Loader {
                active: SwipeView.isCurrentItem || SwipeView.isNextItem || SwipeView.isPreviousItem
                sourceComponent: Text {
                    text: index
                    Component.onCompleted: console.log("created:", index)
                    Component.onDestruction: console.log("destroyed:", index)
                }
            }
        }
    }
    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
