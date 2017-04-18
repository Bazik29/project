import QtQuick 2.7
import QtQuick.Controls 2.1

Item {
    Pane {
        id: firstPaged
        padding: 12
        GroupBox {
            property int answer: 0
            title: "Выбирите свойства, характерные для алогритма."
            anchors.horizontalCenter: parent.horizontalCenter

            Column {
                spacing: 20
                width: 300

                    CheckBox
                    {
                        text: "Дискретность"
                        checked: false
                    }
                    CheckBox
                    {
                        text: "Упругость"
                        checked: false
                    }
                    CheckBox
                    {
                        text: "Детерминированность"
                        checked:false
                    }
                    CheckBox
                    {
                        text: "Гибкость"
                        checked:false
                    }


            }
        }
    }
}
