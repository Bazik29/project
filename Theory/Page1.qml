import QtQuick 2.7
import QtQuick.Controls 2.1

Item {
    Pane {
        id: firstPaged
        padding: 12
        GroupBox {
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
                }
                RadioButton {
                    id: buttond
                    text: "Дискретность"
                    width: parent.width
                }
                RadioButton {
                    text: "Массовость"
                    width: parent.width
                }
            }
        }
    }
}
