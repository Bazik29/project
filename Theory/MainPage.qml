import QtQuick 2.7
import QtQuick.Controls 2.1

// TheoryScreen

Item {
    Image {
        id: back
        anchors.fill: parent
        source: "images/background.png"
    }
    id: theory
    // Проверка превышения максимума страниц
    property int maxpageopen: (TheoryScreen.getPage() < 11) ? TheoryScreen.getPage() : 0

    function updateMaxPage(){
        if (view.currentIndex > maxpageopen) maxpageopen = view.currentIndex;
        TheoryScreen.setPage(maxpageopen);
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
                        uncorrect.state = "show";
                        butBack.visible = true;
                    }
                }
                else
                    nextpage();

            }
        }
        else {      // Повторить
            uncorrect.state = "hide";
            butBack.visible = false;
            butnext.bNext = true;
            resetAnswerOnCurrentPage();
        }
    }

    function resetAnswerOnCurrentPage(){
        if (view.currentItem.item && view.currentItem.item.test){
            view.currentItem.item.reset()
        }
    }

    Image {
        id: butMenu
        width: 100
        height: 40

        anchors.left: parent.left
        anchors.leftMargin: 36
        anchors.top: parent.top
        anchors.topMargin: 8
        state: "normal"
        source: "controls/menu_normal.png"
        states: [
            State {
                name: "normal"
                PropertyChanges {
                    target: butMenu
                    source: "controls/menu_normal.png"
                }
            },
            State {
                name: "hover"
                PropertyChanges {
                    target: butMenu
                    source: "controls/menu_hover.png"
                }
            },
            State {
                name: "cliked"
                PropertyChanges {
                    target: butMenu
                    source: "controls/menu_clicked.png"
                }
            }
        ]
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: butMenu.state = "hover"
            onExited: butMenu.state = "normal"
            onPressed: {
                TheoryScreen.setPage(maxpageopen);
                resetAnswerOnCurrentPage();
                uncorrect.state = "hide";
                butnext.bNext = true;
                butnext.state = "normal-next";
                butnext.visible = true;
                view.currentIndex = 0;
                TheoryScreen.to_menu();
            }
            onReleased: butMenu.state = "hover"
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
            active: view.currentIndex == 9 || view.currentIndex == 10
            source: "Page11.qml" //end slide
        }

    }


    PageIndicator {
        width: 268
        height: 34
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: view.bottom
        anchors.topMargin: 16

        interactive: true
        count: view.count
        currentIndex: view.currentIndex

        delegate:
            Image {
            id: indic
            width: 22; height: 22;
            anchors.verticalCenter: parent.verticalCenter
            source: "controls/indic_2_current.png"
            state: if (index % 2)
                       (index === view.currentIndex) ? "test-current" : (index > maxpageopen) ? "test-future" : "test"
                   else
                       (index === view.currentIndex) ? "theory-current" : (index > maxpageopen) ? "theory-future" : "theory"
            states: [
                State {
                    name: "theory"
                    PropertyChanges {
                        target: indic
                        source: "controls/indic_2.png"
                    }
                },
                State {
                    name: "theory-current"
                    PropertyChanges {
                        target: indic
                        source: "controls/indic_2_current.png"
                    }
                },
                State {
                    name: "theory-future"
                    PropertyChanges {
                        target: indic
                        source: "controls/indic_2_future.png"
                    }
                },
                State {
                    name: "test"
                    PropertyChanges {
                        target: indic
                        source: "controls/indic_1.png"
                    }
                },
                State {
                    name: "test-current"
                    PropertyChanges {
                        target: indic
                        source: "controls/indic_1_current.png"
                    }
                },
                State {
                    name: "test-future"
                    PropertyChanges {
                        target: indic
                        source: "controls/indic_1_future.png"
                    }
                }
            ]
            MouseArea {
                anchors.fill: parent
                onClicked: if (uncorrect.state !== "show") changePage(index)
            }
        }
    }

    Image {
        id: butnext
        property bool bNext: true
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 11
        anchors.right: parent.right
        anchors.rightMargin: 36
        width: 100
        height: 40
        state: "normal-next"
        source: "controls/next_normal.png"
        states: [
            State {
                name: "normal-next"
                PropertyChanges {
                    target: butnext
                    source: "controls/next_normal.png"
                }
            },
            State {
                name: "hover-next"
                PropertyChanges {
                    target: butnext
                    source: "controls/next_hover.png"
                }
            },
            State {
                name: "cliked-next"
                PropertyChanges {
                    target: butnext
                    source: "controls/next_clicked.png"
                }
            },
            State {
                name: "normal-retry"
                PropertyChanges {
                    target: butnext
                    source: "controls/retry_normal.png"
                }
            },
            State {
                name: "hover-retry"
                PropertyChanges {
                    target: butnext
                    source: "controls/retry_hover.png"
                }
            },
            State {
                name: "cliked-next"
                PropertyChanges {
                    target: butnext
                    source: "controls/retry_clicked.png"
                }
            }
        ]
        MouseArea {
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            hoverEnabled: true
            onEntered: butnext.state = butnext.bNext ? "hover-next" : "hover-retry"
            onExited: butnext.state = butnext.bNext ? "normal-next" : "normal-retry"
            onPressed: {
                butnext.state = butnext.bNext ? "cliked-next" : "cliked-retry"
                checkAndNext()
            }
            onReleased: butnext.state = butnext.bNext ? "hover-next" : "hover-retry"
        }
    }

    Image {
        id: uncorrect
        x: 1036
        y: 599
        width: 244
        height: 46
        source: "controls/wrong_answer.png"
        state: "hide"
        states: [
            State {
                name: "show"
                PropertyChanges {
                    target: uncorrect
                    x: 1036
                }
            },
            State {
                name: "hide"
                PropertyChanges {
                    target: uncorrect
                    x: 1281
                }
            }
        ]
        transitions:
            Transition {
               from: "hide"; to: "show"; reversible: true
               PropertyAnimation {
                   target: uncorrect
                   properties: "x"
                   duration: 200
               }
           }
    }
    Image {
        id: butBack
        x: 1036
        y: 669
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 11
        anchors.right: parent.right
        anchors.rightMargin: 144
        width: 100
        height: 40
        visible: false
        state: "normal"
        states: [
            State {
                name: "normal"
                PropertyChanges {
                    target: butBack
                    source: "controls/back_normal.png"
                }
            },
            State {
                name: "hover"
                PropertyChanges {
                    target: butBack
                    source: "controls/back_hover.png"
                }
            },
            State {
                name: "cliked"
                PropertyChanges {
                    target: butBack
                    source: "controls/back_clicked.png"
                }
            }
        ]
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: butBack.state = "hover"
            onExited: butBack.state = "normal"
            onPressed: {
                butBack.visible = false;
                resetAnswerOnCurrentPage();
                changePage(view.currentIndex-1);
                butBack.visible = false;
                butnext.bNext = true;
                butnext.state = "normal-next";
                uncorrect.state = "hide"
            }
            onReleased: butBack.state = "hover"
        }
    }
}
