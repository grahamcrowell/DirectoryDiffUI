import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2


    ListView {
        width: 300; height: 500
        visible: true
        model: myModel
        delegate: Rectangle {
            height: 25
            width: 100
            color: qsTr("red")
            Text { text: generic_string }
        }
    }

//    menuBar: MenuBar {
//        Menu {
//            title: qsTr("File")
//            MenuItem {
//                text: qsTr("&Open")
//                onTriggered: console.log("Open action triggered");
//            }
//            MenuItem {
//                text: qsTr("Exit")
//                onTriggered: Qt.quit();
//            }
//        }
//    }

//    MainForm {
//        anchors.fill: parent
//        button1.onClicked: messageDialog.show(qsTr("Button 1 pressed"))
//        button2.onClicked: messageDialog.show(qsTr("Button 2 pressed"))
//    }

//    MessageDialog {
//        id: messageDialog
//        title: qsTr("May I have your attention, please?")

//        function show(caption) {
//            messageDialog.text = caption;
//            messageDialog.open();
//        }
//    }
//}
