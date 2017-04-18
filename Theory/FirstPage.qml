import QtQuick 2.7
import QtQuick.Controls 2.1


Item {
    id: theory


    Connections {
           target: TheoryScreen
    }
    Button {
        x: 0
        y: 0
        text: "Меню"
        onClicked: TheoryScreen.to_menu()
    }
    SwipeView {
        id:view
        spacing: 10
        anchors.rightMargin: 40
        anchors.leftMargin: 40
        anchors.topMargin: 80
        anchors.bottomMargin: 150
        interactive: true
        currentIndex: 0
        anchors.fill: parent
        Repeater {
            model: 4 // число страниц
            Loader {
                active: SwipeView.isCurrentItem || SwipeView.isNextItem || SwipeView.isPreviousItem
                source: "Page"+ (view.currentIndex + 1) +".qml"
            }
        }
    }
    PageIndicator {
        x: 47
        y: 526
        width: 54
        anchors.horizontalCenterOffset: -5
        anchors.bottomMargin: 54
        interactive: true

        count: view.count
        currentIndex: view.currentIndex
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

}
