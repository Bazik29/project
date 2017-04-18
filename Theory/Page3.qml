import QtQuick 2.7
import QtQuick.Controls 2.1

Item {
    Pane {
        id: firstPaged
        padding: 12
        GroupBox {  // уберем рамку если что для теории
            property int answer: 0
            title: "Теория.Способы задания алгоритма"
            anchors.horizontalCenter: parent.horizontalCenter

            Column {
                spacing: 20
                width: 300

            Text {
                    font.pointSize:12
                    color: "black"
                    text:
                     "На практике наиболее распространены следующие способы задания алгоритмов:\n"+
                     "— словесный\n"+

                     "— графический\n"+

                     "— псевдокоды\n"+

                     "— на языке программирования"

                 }

            }
        }
    }
}
