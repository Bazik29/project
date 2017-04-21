import QtQuick 2.7
import QtQuick.Controls 2.1

// TheoryScreen

Item {
    id: theory
    property int maxpageopen: TheoryScreen.getPage()

    function updateMaxPage(){
        if (view.currentIndex > maxpageopen) maxpageopen = view.currentIndex;
    }

    function changePage(ind){
        if (ind < 0) return;
        if(ind <= maxpageopen && ind !== view.currentIndex) {
            view.setCurrentIndex(ind);
            if (ind+1 != view.count) butnext.visible = true;
            else butnext.visible = false;
        }
    }

    function nextpage(){
        if (view.currentIndex+1 != view.count)
            if (view.currentIndex+2 == view.count){
                view.currentIndex++;
                updateMaxPage()
                butnext.visible = false;
            }
            else {
                view.currentIndex++;
                updateMaxPage();
            }
    }

    function checkAndNext(){
        if (butnext.bNext) {    // Продолжить
            if (view.currentItem.item) {
                if (view.currentItem.item.test) {
                    if (view.currentItem.item.check()) {
                        nextpage();
                    }
                    else { // Неправильный ответ
                        butnext.bNext = false;
                        uncorrect.visible = true;
                        butnext.text = "Повторить";
                    }
                }
                else
                    nextpage();
            }
        }
        else {      // Повторить
            butnext.text = "Продолжить";
            uncorrect.visible = false;
            resetAnswerOnCurrentPage();
            butnext.bNext = true;
        }
    }

    function resetAnswerOnCurrentPage(){
        if (view.currentItem.item && view.currentItem.item.test){
            view.currentItem.item.reset()
        }
    }

    Button {
        text: "Меню"
        anchors.left: parent.left
        anchors.leftMargin: 36
        anchors.top: parent.top
        anchors.topMargin: 8
        onClicked: {
            TheoryScreen.setPage(maxpageopen);
            TheoryScreen.to_menu();
            view.currentIndex = 0;
        }
    }
    SwipeView {
        id:view
        anchors.fill: parent
        anchors.rightMargin: 36
        anchors.leftMargin: 36
        anchors.topMargin: 63
        anchors.bottomMargin: 63
        spacing: 40
        currentIndex: 0
        interactive: false
        Loader {
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
            active: view.currentIndex == 2 || view.currentIndex == 3 || view.currentIndex == 4
            source: "Page4.qml"
        }

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
        Loader {
            active: view.currentIndex == 9 || view.currentIndex == 10|| view.currentIndex == 11
            source: "Page11.qml" //end slide
        }

    }

    PageIndicator {
        x: 47
        width: 148
        height: 34
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: view.bottom
        anchors.topMargin: 16

        interactive: true
        count: view.count
        currentIndex: view.currentIndex

        delegate: Rectangle{
            anchors.verticalCenter: parent.verticalCenter
            width: (index === view.currentIndex) ? 22 : 18
            height: (index === view.currentIndex) ? 22 : 18
            radius: (index === view.currentIndex) ? 11 : 9
            color: (index % 2 == 0) ? "blue" : "green"
            border {
                width: (index === view.currentIndex) ? 1 : 1;
                color: "silver";
            }

            opacity: {
                if (index === view.currentIndex) 1
                else
                    if (index < maxpageopen) 0.7
                    else 0.4

            }
            Behavior on opacity {
                OpacityAnimator {
                    duration: 100
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: if (!uncorrect.visible) changePage(index)
            }
        }
    }

    Button {
        id: butnext
        property bool bNext: true
        x: 664
        y: 549
        text: "Продолжить"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 11
        anchors.right: parent.right
        anchors.rightMargin: 36
        onClicked: checkAndNext()
    }
    Frame {
        id: uncorrect
        x: 527
        y: 490
        width: 215
        height: 35
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 75
        anchors.right: parent.right
        anchors.rightMargin: 58
        enabled: true
        padding: 1
        visible: false
        focus: true
        Text {
            color: "red"
            text: "Неправильно"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            font.pixelSize: 20
        }

        Button {
            x: 163
            width: 73
            text: "Назад"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            onClicked: {
                resetAnswerOnCurrentPage();
                changePage(view.currentIndex-1);
                uncorrect.visible = false;
                butnext.text = "Продолжить";
                butnext.bNext = true;
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
