import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import Imagepro 1.1
Rectangle {

    id: rect_MenuBar;
    z:0.6;
    Image
    {
        id: imageBG_menuBar;
        anchors.fill: parent;
        source: "images/Toolbar/ToolbarBG.png";
    }

    Row
    {
        id: row_menuBarButtonList;

        anchors.left: parent.left;
        anchors.leftMargin: 1;
        anchors.top: parent.top;
        height: parent.height;
        spacing: 1;


        MyMenuButton
        {
            id:fileButton_Menu;
            width: 76;
            height: 40;
            nTextSize: 18;
            sTextText: "文件"
            state: "normal";
            nIndex: 0;

        }
        MyMenuButton
        {
            id:editButton_Menu;
            width: 76;
            height: 40;
            nTextSize: 18;
            sTextText: "编辑"
            state: "normal";
            nIndex: 1;
        }
        MyMenuButton
        {
            id:helpButton_Menu;
            width: 76;
            height: 40;
            nTextSize: 18;
            sTextText: "帮助"
            state: "normal";
            nIndex: 2;
        }


    }

    Rectangle
    {
        id: rect_MenuFile;
        visible: false;

        x:fileButton_Menu.x + 4;
        y:fileButton_Menu.y + menuBar_mainWin.height;
        width: 200;
        height: 30 * 4 +6;
        color: "transparent";

        Column
        {
            id: colum_File;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;

            MyMenuButton
            {
                width: 200;
                height: 30;
                nTextSize: 16;
                sTextText: "打开";
                state: "normal";
                nIndex: 4;
                onMenuButtonIndexBack:
                {
                    //            qDebug("clicked");
                    //                    imageItem.openImage();
                    imageItem.openImage();
                    //            imageItem.processImage();
                }
            }
            MyMenuButton
            {
                width: 200;
                height: 30;
                nTextSize: 16;
                sTextText: "保存";
                state: "normal";
                nIndex: 5;
            }
            MyMenuButton
            {
                width: 200;
                height: 30;
                nTextSize: 16;
                sTextText: "另存为";
                state: "normal";
                nIndex: 6;
            }
            MyMenuButton
            {
                width: 200;
                height: 30;
                nTextSize: 16;
                sTextText: "退出";
                state: "normal";
                nIndex: 7;
            }
        }
    }


    Rectangle
    {
        id: rect_MenuEdit;
        visible: false;

        x:editButton_Menu.x + 4;
        y:editButton_Menu.y + menuBar_mainWin.height;
        width: 200;
        height: 30 * 4 +6;
        color: "transparent";

        Column
        {
            id: colum_Edit;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;

            MyMenuButton
            {
                width: 200;
                height: 30;
                nTextSize: 16;
                sTextText: "撤销";
                state: "normal";
                nIndex: 8;

                MouseArea{
                    id:maForUndo
                    anchors.fill:parent
                    onClicked: imageItem.undo()
                }
            }
            MyMenuButton
            {
                width: 200;
                height: 30;
                nTextSize: 16;
                sTextText: "重做";
                state: "normal";
                nIndex: 9;
                MouseArea{
                    id:maForClear
                    anchors.fill:parent
                    onClicked: imageItem.clear()
                }
            }
        }
    }

    Rectangle
    {
        id: rect_MenuTool;
        visible: false;

        x:helpButton_Menu.x +4;
        y:helpButton_Menu.y + menuBar_mainWin.height;
        width: 200;
        height: 30 * 3 +6;
        color: "transparent";

        Column
        {
            id: colum_Tool;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;

            MyMenuButton
            {
                width: 200;
                height: 30;
                nTextSize: 16;
                sTextText: "软件使用说明";
                state: "normal";
                nIndex: 12;
            }
            MyMenuButton
            {
                width: 200;
                height: 30;
                nTextSize: 16;
                sTextText: "版本信息";
                state: "normal";
                nIndex: 13;
            }

        }
    }


    MouseArea
    {
        id:menuAllMouseArea;
        visible: false;
        z:-1;


        width: mainW.width;
        height: mainW.height;

        onClicked:
        {
            console.log("visible");
            rect_MenuFile.visible = false;
            rect_MenuEdit.visible = false;
            rect_MenuTool.visible = false;
            //            rect_MenuHelp.visible = false;
            menuAllMouseArea.visible = false;
            console.log("set success");
            menuAllMouseArea.visible = false
        }

    }


}
