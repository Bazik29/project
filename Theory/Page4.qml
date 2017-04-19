import QtQuick 2.7
import QtQuick.Controls 2.1

Frame {
    id: page4
    anchors.fill: parent
    property int answer: 444
    GroupBox {
    property int answer: 0
    title: "Какие бывают способы представления алгоритма(выберите один вариант из представленных)? "
    anchors.horizontalCenter: parent.horizontalCenter

    Column {
        spacing: 20
        width: 300

             RadioButton
             {
                text: "Графический"
                checked: true
                width: parent.width
             }
             RadioButton
             {
                id: buttond
                text: "Псевдокод"
                width: parent.width
             }
             RadioButton
             {
                text: "на Языке программирования"
                width: parent.width
             }
             RadioButton
             {
                text: "все вышеперечисленное"
                width: parent.width
             }
        }
    }
}
