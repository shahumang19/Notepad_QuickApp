import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1
import QtQuick.Window 2.1
import documenthandler 1.0

ApplicationWindow {
    id: window
    width: 500
    height: 500
    visible: true

    FileDialog{
        id : fileDialog
        nameFilters: ["Text files (*.txt)"]
        onAccepted:{
            if (fileDialog.selectExisting)
                document.fileUrl = fileUrl
            else
                document.saveAs(fileUrl, selectedNameFilter)
        }
    }

    Action {
        id: openFile
        text : "Open File"
        shortcut: "ctrl+o"
        onTriggered: {
            fileDialog.selectExisting = true
            fileDialog.open()
        }
    }

    Action{
        id:saveFile
        text: "Save"
        shortcut: StandardKey.Save
        onTriggered:{
            if (document.fileUrl == ""){
                saveasFile.trigger()
            }
            else{
                document.save(document.fileUrl)
            }
        }
    }

    Action{
        id:saveasFile
        text: "SaveAs"
        shortcut: StandardKey.SaveAs
        onTriggered: {
            fileDialog.selectExisting = false
            fileDialog.open()
        }
    }

    Action {
        id: newFile
        text : "New File"
        shortcut: "ctrl+n"
        onTriggered:{
            document.fileUrl = ""
            if (document.text == "")
                textArea.text = document.text
            document.text = ""
        }
    }

    Action {
        id: cutText
        text : "Cut"
        shortcut: "ctrl+x"
        onTriggered: textArea.cut()
    }

    Action {
        id: copyText
        text : "Copy"
        shortcut: "ctrl+c"
        onTriggered: textArea.copy()
    }

    Action {
        id: pasteText
        text : "Paste"
        shortcut: "ctrl+v"
        onTriggered: textArea.paste()
    }

    TextArea{
        Accessible.name: "document"
        id: textArea
        frameVisible: false
        anchors.fill: parent
        baseUrl: "qrc:/"
        text: document.text
        transformOrigin: Item.Center
        textFormat: Qt.RichText
        Component.onCompleted: forceActiveFocus()
    }

    menuBar: MenuBar{
        Menu{
            title : "&File"
            MenuItem {action: newFile}
            MenuItem {action: openFile}
            MenuItem {action: saveFile}
            MenuItem {action: saveasFile}
            MenuSeparator{}
            MenuItem {text: "Quit"; onTriggered: Qt.quit()}
        }
        Menu{
            title : "&Edit"
            MenuItem {action: cutText}
            MenuItem {action: copyText}
            MenuItem {action: pasteText}
        }
    }

    DocumentHandler {
        id: document
        target: textArea
        fileUrl: ""
    }

}
