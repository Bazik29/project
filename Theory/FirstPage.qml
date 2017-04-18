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
        id: view
        spacing: 40
        anchors.rightMargin: 40
        anchors.leftMargin: 40
        anchors.topMargin: 80
        anchors.bottomMargin: 150
        //interactive: false
        currentIndex: 0
        anchors.fill: parent

        // ТУТ ДОЛЖЕН БЫТЬ LOADER загружающий страницы

        // Страницы меню
        Pane {
            id: firstPage
            padding: 12
            Text{
                text:"Решение задачи при помощи ЭВМ начинается с составления алгоритма. Что же такое алгоритм?\n"+
    "Алгоритм – это точное предписание, определяющее вычислительный процесс, ведущий от варьируемых начальных данных к искомому результату.\n"+
    "Основные особенности алгоритмов:\n"+
    "1.	Массовость  – алгоритм разрабатывается для решения некоторого класса задач, различающихся исходными данными\n"+
    "2.	Однозначность – каждый шаг алгоритма должен быть четко определен и не должен допускать произвольной трактовки исполнителем\n"+
    "3.	Дискретность – алгоритм должен состоять из конкретных действий, следующих в определенном порядке\n"+
    "4.	Конечность – исполнение алгоритма должно закончиться за конечное число шагов\n"+
    "5.	Корректность – алгоритм должен задавать правильное решение задачи\n"+
    "6.	Эффективность – алгоритм должен выполняться за разумное конечное время. При этом выбирается наиболее простой и короткий способ решения задачи при соблюдении, естественно, всех ограничений и требований к алгоритму\n"
            }
        }
        Pane {
            id: firstPaged
            padding: 12
            GroupBox {
                id: test_1d
                property int answer: 0
                title: "Свойство, когда по данному алгоритму должна решаться не одна, а целый класс подобных задач"
                anchors.horizontalCenter: parent.horizontalCenter

                Column {
                    spacing: 20
                    width: 300

                    RadioButton {
                        text: "Результативность"
                        checked: true
                        width: parent.width
                        onClicked: {
                            test_1d.answer = 1
                        }
                    }
                    RadioButton {
                        id: buttond
                        text: "Дискретность"
                        width: parent.width
                        onClicked: {
                            test_1d.answer = 2
                        }
                    }
                    RadioButton {
                        text: "Массовость"
                        width: parent.width
                        onClicked: {
                            test_1d.answer = 3
                        }
                    }
                }
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
