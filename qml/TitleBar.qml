import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle{

    id: rect_titleBar;
    z: 0.1;

    Image
    {
        id: vImageBackGround;
        height: parent.height;
        width: parent.width;
        source: "images/Main/title.png";
    }
    Text {
        id: text_titleBar;
        height: parent.height;
        width: parent.width
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        color: "#eeeeee";
        font.family: "楷体";
        font.pixelSize: 16;
        font.letterSpacing: 1;
        font.bold: true;
        text: "中华文化元素交互分割软件";
    }

    Row
    {
        id: row_titleBarButtonList;
        anchors.right: parent.right;
        anchors.rightMargin: 20;
        anchors.verticalCenter: parent.verticalCenter;
        height: parent.height;
        spacing: 30;

        // 最小化按钮
        TitleButton
        {
            width: 12;
            height: 2;
            anchors.verticalCenter: parent.verticalCenter;
            sPressedImage: "images/Main/minimize2_@2x.png";
            sNormalImage: "images/Main/minimize_@2x.png";
            sHoverImage: "images/Main/minimize2_@2x.png";
            state: "normal";
            nIndex: 0;
        }

        // 最大化按钮
        TitleButton
        {
            width: 12;
            height: 12;
            anchors.verticalCenter: parent.verticalCenter;
            sPressedImage: "images/Main/maximize2_@2x.png";
            sNormalImage: "images/Main/maximize_@2x.png";
            sHoverImage: "images/Main/maximize2_@2x.png";
            state: "normal";
            nIndex: 1;
        }

        // 关闭按钮
        TitleButton
        {
            width:12;
            height: 12;
            anchors.verticalCenter: parent.verticalCenter;
            sPressedImage: "images/Main/close2_@2x.png";
            sNormalImage: "images/Main/close_@2x.png";
            sHoverImage: "images/Main/close2_@2x.png";
            state: "normal";
            nIndex: 2;
        }

    }


    MouseArea
    {
        anchors.right: parent.right;
        anchors.rightMargin: 120;

        height: parent.height;
        width: parent.width - 120;


        acceptedButtons: Qt.LeftButton //只处理鼠标左键
        property point clickPos: "0,0"
        onPressed:
        {
            //接收鼠标按下事件
            clickPos  = Qt.point(mouse.x,mouse.y)
        }
        onPositionChanged:
        {
            //鼠标按下后改变位置
            //鼠标偏移量
            var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)

            //如果mainwindow继承自QWidget,用setPos
            mainW.setX(mainW.x+delta.x)
            mainW.setY(mainW.y+delta.y)
        }

        onDoubleClicked:
        {
            mainW.visibility == Window.Windowed ?
                        mainW.visibility = Window.Maximized :mainW.visibility = Window.Windowed;
        }
    }
}
