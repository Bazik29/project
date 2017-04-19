import QtQuick 2.7
import QtQuick.Controls 2.1

Frame {
    id: page3
    anchors.fill: parent
    property bool test: false
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
