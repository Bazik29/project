import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page7
    background: TFrameBackgroung{}
    anchors.fill: parent
    clip:true
    property bool test: false

    Flickable {
        anchors.fill: parent
        contentHeight: text.height

        Text {
            id:text
            font.pointSize:12
            color: "black"
            width: parent.width
            wrapMode:Text.WordWrap
            text:
            "<h2>Основные обозначения Псевдокода</h2>
             <img src='images/p7.png'>
             <h3>Общий вид алгоритма на псевдокоде:</h3>

                    <u>алг</u> название алгоритма (аргументы и результаты)<br>
                    <u>дано</u> условия применимости алгоритма<br>
                    <u>надо</u> цель выполнения алгоритма<br>
                    <u>нач</u> описание промежуточных величин<br>
                    - последовательность команд (тело алгоритма)<br>
                    <u>кон алг</u> название алгоритма<br>


            "
        }
        ScrollBar.vertical: ScrollBar {}
    }
}




