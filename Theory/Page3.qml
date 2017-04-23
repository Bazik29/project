import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page3
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
            "<h2>Способы задания алгоритма</h2>


            <p>На практике наиболее распространены следующие способы задания алгоритмов:<p>

                — словесный<br>

                — графический<br>

                — псевдокоды<br>

                — на языке программирования<br>

            <h4>Словесный способ</h4>

             Словесный способ записи алгоритмов представляет собой описание последовательных этапов обработки данных.
             Алгоритм задаётся в произвольном изложении на естественном языке.<br>

            <h4>Графический способ</h4>

             При графическом представлении алгоритм изображается в виде по-следовательности связанных между собой функциональных блоков, каждый из которых соответствует выполнению одного или нескольких действий.
             Такое графическое представление называется схемой алгоритма, или блок-схемой.
             В блок-схеме каждому типу действий соответствует геометрическая фигура, представленная в виде блочного символа.<br>
            <img src='images/p3.png'>


             <h4>Псевдокод</h4>
            В псевдокоде не приняты строгие синтаксические правила для записи команд, присущие формальным языкам, что облегчает запись алгоритма на стадии его проектирования.
            Однако в псевдокоде обычно имеются некоторые конструкции, присущие формальным языкам.
            В псевдокоде, так же, как и в формальных языках, есть служебные слова, смысл которых однозначно определён.<br>


             <h4>Программный способ записи алгоритмов</h4>
            Алгоритм, предназначенный для исполнения на компьютере, должен быть записан на понятном ему языке.
            В этом случае язык для записи алгоритмов должен быть формализован.
            Такой язык принято называть языком программирования, а запись алгоритма на этом языке — программой.
            Далее мы будем рассматривать способ задания алгоритма блок-схемой и на алгоритмическом языке.<br>
            "
        }
        ScrollBar.vertical: ScrollBar { }
    }
}
