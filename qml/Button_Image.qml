import QtQuick 2.0

Rectangle
{
    id: vButton_Image;

    color: "transparent";

    //------------------------------------------------------------//

    property var sPressedImage: "";
    property var sNormalImage: "";
    property var sHoverImage: "";
    property var sTextText: "";
    property var nTextSize: 12;

    property var nIndex: 0;

    //定义一个信号，这个信号用于返回某些参数
    signal back(var nIndex);

    //------------------------------------------------------------//

    //button image
    Image
    {
        id: vButtonImage;

        anchors.fill: parent;
        source: sNormalImage;
    }

    //------------------------------------------------------------//

    //button text
    Text
    {
        id: vButtonText;

        x: 0;
        y: 0;
        width: parent.width;
        height: parent.height;
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        wrapMode: Text.WordWrap;
        color: "#000000";/*color: "black";*/
        font.family: "微软雅黑";
        font.pixelSize: nTextSize;
        font.letterSpacing: 1;
        font.bold: true;
        text: sTextText;

    }

    //------------------------------------------------------------//

    //button mousearea
    MouseArea
    {
        id: vButtonMouseArea;

        anchors.fill: parent;
        //说明当前接受鼠标的哪些按键事件，左键，右键，中键
        acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MidButton;
        //说明鼠标悬停事件时候可被触发，默认为false；当为false时onEntered和onExited将会无效。
        hoverEnabled: true;
        onPressed:
        {
            //当前鼠标按钮，将当前按钮的状态设置为按下状态
            vButton_Image.state === "pressed" ? vButton_Image.state = "hover" : vButton_Image.state = "pressed";
        }
        onReleased:
        {
            //鼠标按下释放掉了，返回一个信号，告诉我的上层父亲，我被按下了，需要执行相应操作
            back(nIndex);
        }

        onEntered:
        {
            if(vButton_Image.state === "normal")
            {
                vButton_Image.state = "hover";
            }

            /* state === "normal" ? state = "hover" : state = "pressed"; */
        }
        onExited:
        {
            if(vButton_Image.state === "hover")
            {
                vButton_Image.state = "normal";
            }

            /* state === "hover" ? state = "normal" : state = "pressed"; */
        }
        onWheel:
        {

        }
    }

    //------------------------------------------------------------//

    //状态机，用于根据state的值来修改某些参数。
    states: [
        State
        {
            name: "normal";
            PropertyChanges
            {
                //表示当该button的state变为normal时，target指目标即vButtonImage这个ID的对象，
                //他的source属性将赋值为sNormalImage；同比类推下面的
                target: vButtonImage;
                source: sNormalImage;
            }
        },
        State
        {
            name: "pressed";
            PropertyChanges
            {
                target: vButtonImage;
                source: sPressedImage;
            }
        },
        State
        {
            name: "hover";
            PropertyChanges
            {
                target: vButtonImage;
                source: sHoverImage;
            }
        }
    ]
}
