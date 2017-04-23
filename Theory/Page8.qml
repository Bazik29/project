import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page8
    background: TFrameBackgroung{}
    anchors.fill: parent
    property bool test: true

    function check() {
      if(input.text==="кон")
         {
              return 1
         }
    }

    function reset() {

        input.text=""
    }

    Column {
        anchors.fill: parent
        spacing: 35

            Text {
                width: parent.width
                wrapMode:Text.WordWrap
                text: qsTr("<h3>Впишите недостающий блок псевдокода.</h3>")
                font.pointSize: 10
            }
            Text {
                font.pointSize:12
                color: "black"
                width: parent.width
                wrapMode:Text.WordWrap
                text:
                "
                алг ПриветМир
                нач
                вывод ('ПриветМир!')
                (...) алг ПриветМир

                "

            }
            TextField {
                id:input
                text:""
            }
        }

}
