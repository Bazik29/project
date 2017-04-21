import QtQuick 2.7
import QtQuick.Controls 2.1


Frame {
    id: page11
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
            "<h2>END SLIDE</h2>


            "
        }
        ScrollBar.vertical: ScrollBar {}
    }
}


