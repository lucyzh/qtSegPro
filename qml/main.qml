import QtQuick 2.12
import QtQuick.Window 2.12
import Imagepro 1.1

Window {

    id:mainW

    visible: true;
    width: 1280;
    height: 720;
    minimumWidth: 640;
    minimumHeight: 360;
    title: qsTr("IPFW");
   // color: "transparent"

    //    color: "#272727";
    ImageProItem{
        id:imageItem;

    }



    flags: Qt.CursorShape |  Qt.WindowSystemMenuHint |Qt.FramelessWindowHint |  Qt.WindowMinimizeButtonHint | Qt.Window;


    TitleBar    //软件标题title
    {
        id: titleBar_mainWin;
        anchors.top: parent.top;
        width: parent.width;
        height: 90;
       // color: "#373737"
    }

    MyMenuBar    //打开、编辑、帮助工具栏
    {
        id: menuBar_mainWin;
        z:0.3
        anchors.left: parent.left;
        anchors.top: parent.top;
        anchors.topMargin: 90;
        width: parent.width;
        height: 40;
        color: "#999999"
    }

    ImageOpen  //打开图片后，图片显示的区域
    {  //
        id: imageOpen;
        z:0.1;
        anchors.left: parent.left;
        anchors.top: parent.top;
        anchors.topMargin: 120;
        anchors.leftMargin: 70;

        MouseArea
        {
            id:maforpaintingrec
            visible:  false
            anchors.fill:  parent
            onPressed:
            {
                imageItem.getqmlmessage(imageOpen.width , imageOpen.height);
                console.log("ready2paintrec")
                imageItem.setStartPnt(Qt.point(mouseX,mouseY))
            }
            onPressAndHold:
            {
                console.log("painting")
                imageItem.setEndPnt(Qt.point(mouseX,mouseY))
                imageItem.recrealtimeshow()
            }
            onReleased:
            {
                console.log("ready2finsihrecpaint")
                imageItem.setEndPnt(Qt.point(mouseX,mouseY))
                imageItem.recpaint()
            }

        }



        MouseArea
        {
//            Timer
//            {
//                id: timerforpntpaint
//                interval: 1;
//                running: false
//                repeat: true
//                onTriggered: {
//                    console.log("painting")
//                    imageItem.setStartPnt(Qt.point(mouseX,mouseY))
//                    imageItem.setEndPnt(Qt.point(mouseX,mouseY))
//                    imageItem.pntpainting()
//                }
//            }

            id:maforpaintingpnt
            visible:  false
            anchors.fill:  parent
            onPressed:
            {
                imageItem.getqmlmessage(imageOpen.width , imageOpen.height);
                console.log("ready2paintpnt")
                imageItem.setStartPnt(Qt.point(mouseX,mouseY))
                imageItem.setEndPnt(Qt.point(mouseX,mouseY))
                imageItem.pntpaintingstart()
//                imageItem.startpntpaint()
            }
            onPositionChanged:
            {
                console.log("painting")
                imageItem.setStartPnt(Qt.point(mouseX,mouseY))
                imageItem.setEndPnt(Qt.point(mouseX,mouseY))
                imageItem.pntpaint()
            }
//            onPressAndHold:
//            {
//                console.log("its onPressAndHold")

//                timerforpntpaint.running = true
//            }
            onReleased:
            {
                timerforpntpaint.running = false
                console.log("ready2finsihpntpaint")
                imageItem.setEndPnt(Qt.point(mouseX,mouseY))
//                imageItem.recpaint()
            }

        }
    }
    SegResultRect
    {  //  分割结果显示区域
        id: segResultRect;
        z:0.1;
        anchors.left: parent.left;
        anchors.top: parent.top;
        anchors.topMargin: 120;
        anchors.leftMargin:  parent.width / 2 ;


    }
    ParameterRect{  //第一个参数框
        id: parameterRect;
        z:0.2;
        width: 240;
        height: 40;
        anchors.left: parent.left;
        anchors.top: parent.top;
        anchors.topMargin: parent.height-135;
        anchors.leftMargin: parent.width/2-250;
    }
    ParameterRectTwo{    //第二个参数框
        id: parameterRectTwo;
        z:0.2;
        width: 240;
        height: 40;
        anchors.left: parent.left;
        anchors.top: parent.top;
        anchors.topMargin: parent.height-85;
        anchors.leftMargin: parent.width/2-250;
    }
    LeftToolBar       //矩形工具、画笔工具等工具栏
    {
        id: leftToolBar;
        z:0.2;
        anchors.left:parent.left;
        anchors.top: parent.top;
        anchors.topMargin: 90;
        width: 70;
        height: parent.height;
        color: "#404040";

    }
    RightToolBar       //开始分割、更新分割等按钮
    {
        id: rightToolBar;
        z:0.2;
        anchors.right:parent.right;
        anchors.top: parent.top;
        anchors.topMargin: 90;
        width: 70;
        height: parent.height;
        color: "#404040";
    }


    StateBar
    {
        id: stateBar_mainWin;

        z:0.3;
        anchors.bottom: parent.bottom;
        width: parent.width;
        height: 30;
        color: "#777777";
    }


    //BackGround
    Image
    {
        id: imageBG;

        anchors.fill: parent;
        source: "images/Main/WindowBG.png";
    }

    MouseArea {

        id:allMouseArea

        //        property bool closeAll: false;

        acceptedButtons: Qt.LeftButton
        hoverEnabled: true
        anchors.fill: parent
        property var window: mainW;

        property int borderWidth: 8
        property int minimumWidth: mainW.minimumWidth
        property int minimumHeight: mainW.minimumHeight
        property int maximumWidth: 0
        property int maximumHeight: 0

        property int resizing: 0
        property real firstWidth: 0
        property real firstHeight: 0
        property real firstMouseX: 0
        property real firstMouseY: 0

        function getValidWidth(width) {
            if (minimumWidth > 0 && width < minimumWidth)
                return minimumWidth;

            if (maximumWidth > minimumWidth && width > maximumWidth)
                return maximumWidth;

            return width;
        }

        function getValidHeight(height) {
            if (minimumHeight > 0 && height < minimumHeight)
                return minimumHeight;

            if (maximumHeight > minimumHeight && height > maximumHeight)
                return maximumHeight;

            return height;
        }

        function getMousePosition(window, mouseX, mouseY) {
            if (mouseX < borderWidth) {
                if (mouseY < borderWidth) {
                    return 1; // left top
                } else if (mouseY < window.height - borderWidth) {
                    return 2; // left
                } else {
                    return 3; // left bottom
                }
            } else if (mouseX < window.width - borderWidth) {
                if (mouseY < borderWidth) {
                    return 4; // top
                } else if (mouseY < window.height - borderWidth) {
                    return 5; // center
                } else {
                    return 6; // bottom
                }
            } else {
                if (mouseY < borderWidth) {
                    return 7; // right top
                } else if (mouseY < window.height - borderWidth) {
                    return 8; // right
                } else {
                    return 9; // right bottom
                }
            }
        }

        function getCursorShape(window, mouseX, mouseY) {
            switch (getMousePosition(window, mouseX, mouseY)) {
            case 1: return Qt.SizeFDiagCursor;
            case 2: return Qt.SizeHorCursor;
            case 3: return Qt.SizeBDiagCursor;
            case 4: return Qt.SizeVerCursor;
            case 5: return Qt.ArrowCursor;
            case 6: return Qt.SizeVerCursor;
            case 7: return Qt.SizeBDiagCursor;
            case 8: return Qt.SizeHorCursor;
            case 9: return Qt.SizeFDiagCursor;
            default: break;
            }

            return Qt.ArrowCursor;
        }

        function resizeLeftTop(window, mouseX, mouseY) {
            var offsetX = mouseX - firstMouseX;
            var offsetY = mouseY - firstMouseY;

            var x = window.x + offsetX;
            var y = window.y + offsetY;
            var width = window.width - offsetX;
            var height = window.height - offsetY;

            // Lock-in maximum and minimum
            offsetX = width - getValidWidth(width);
            offsetY = height - getValidHeight(height);
            x = x + offsetX;
            width = width - offsetX;
            y = y + offsetY;
            height = height - offsetY;

            window.x = x;
            window.y = y;
            window.width = width;
            window.height = height;
        }

        function resizeLeft(window, mouseX, mouseY) {
            var offsetX = mouseX - firstMouseX;

            var x = window.x + offsetX;
            var width = window.width - offsetX;

            // Lock-in maximum and minimum
            offsetX = width - getValidWidth(width);
            x = x + offsetX;
            width = width - offsetX;

            window.x = x;
            window.width = width;
        }

        function resizeLeftBottom(window, mouseX, mouseY) {
            var offsetX = mouseX - firstMouseX;
            var offsetY = mouseY - firstMouseY;

            var x = window.x + offsetX;
            var width = window.width - offsetX;
            var height = firstHeight + offsetY;

            // Lock-in maximum and minimum
            offsetX = width - getValidWidth(width);
            x = x + offsetX;
            width = width - offsetX;
            height = getValidHeight(height);

            window.x = x;
            window.width = width;
            window.height = height;
        }

        function resizeTop(window, mouseX, mouseY) {
            var offsetY = mouseY - firstMouseY;

            var y = window.y + offsetY;
            var height = window.height - offsetY;

            // Lock-in maximum and minimum
            offsetY = height - getValidHeight(height);
            y = y + offsetY;
            height = height - offsetY;

            window.y = y;
            window.height = height;
        }

        function resizeBottom(window, mouseX, mouseY) {
            var offsetY = mouseY - firstMouseY;

            var height = firstHeight + offsetY;

            // Lock-in maximum and minimum
            height = getValidHeight(height);

            window.height = height;
        }

        function resizeRightTop(window, mouseX, mouseY) {
            var offsetX = mouseX - firstMouseX;
            var offsetY = mouseY - firstMouseY;

            var y = window.y + offsetY;
            var width = firstWidth + offsetX;
            var height = window.height - offsetY;

            // Lock-in maximum and minimum
            offsetY = height - getValidHeight(height);
            y = y + offsetY;
            width = getValidWidth(width);
            height = height - offsetY;

            window.y = y;
            window.width = width;
            window.height = height;
        }

        function resizeRight(window, mouseX, mouseY) {
            var offsetX = mouseX - firstMouseX;

            var width = firstWidth + offsetX;

            // Lock-in maximum and minimum
            width = getValidWidth(width);

            window.width = width;
        }

        function resizeRightBottom(window, mouseX, mouseY) {
            var offsetX = mouseX - firstMouseX;
            var offsetY = mouseY - firstMouseY;
            var width = firstWidth + offsetX;
            var height = firstHeight + offsetY;

            // Lock-in maximum and minimum
            width = getValidWidth(width);
            height = getValidHeight(height);

            window.width = width;
            window.height = height;
        }

        function move(window, mouseX, mouseY) {
            window.x = window.x + (mouseX - firstMouseX);
            window.y = window.y + (mouseY - firstMouseY);
        }

        function resize(window, mouseX, mouseY) {
            switch (resizing) {
            case 1:
                resizeLeftTop(window, mouseX, mouseY);
                break;
            case 2:
                resizeLeft(window, mouseX, mouseY);
                break;
            case 3:
                resizeLeftBottom(window, mouseX, mouseY);
                break;
            case 4:
                resizeTop(window, mouseX, mouseY);
                break;
            case 5:
                //                move(window, mouseX, mouseY);
                break;
            case 6:
                resizeBottom(window, mouseX, mouseY);
                break;
            case 7:
                resizeRightTop(window, mouseX, mouseY);
                break;
            case 8:
                resizeRight(window, mouseX, mouseY);
                break;
            case 9:
                resizeRightBottom(window, mouseX, mouseY);
                break;
            default:
                break;
            }
        }

        onPositionChanged: {
            if (resizing == 0) {
                cursorShape = getCursorShape(window, mouse.x, mouse.y);
            } else {
                resize(window, mouse.x, mouse.y);
            }
        }

        onPressed: {
            resizing = getMousePosition(window, mouseX, mouseY);
            firstWidth = window.width;
            firstHeight = window.height;
            firstMouseX = mouseX;
            firstMouseY = mouseY;
        }

        onReleased: {
            resizing = 0;
        }

        onClicked:
        {
            if(mouseX>500 || mouseY>200)
            {

                //                closeAll = true;
                //                console.log("closeAll");


                //                MyMenuBar.rect_MenuFile.visible = false;
                //                rect_MenuFile.visible = false;
                //                rect_MenuEdit.visible = false;
                //                rect_MenuTool.visible = false;
                //                rect_MenuHelp.visible = false;
            }

        }

    }


}
