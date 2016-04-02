import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    ColumnLayout {
        id: mainLayout
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        anchors.fill: parent
        spacing: 0
        clip: false

        GroupBox {
            id: inputGroupBox
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: qsTr("Expression")

            TextArea {
                id: inputTextArea
                objectName: "inputTextArea"
                visible: true
                anchors.fill: parent

                signal gotInput()
                onTextChanged: gotInput()
            }
        }

        GroupBox {
            id: outputGroupBox
            width: 360
            height: 300
            Layout.fillHeight: true
            title: qsTr("Result")
            checked: false
            Layout.fillWidth: true

            Label {
                id: outputLabel
                objectName: "outputLabel"
                text: qsTr("0")
                font.bold: false
                font.pointSize: 28
                wrapMode: Text.WordWrap
                anchors.fill: parent
                textFormat: Text.PlainText
            }
        }

    }

}
