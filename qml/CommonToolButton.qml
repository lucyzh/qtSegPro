import QtQuick 2.0

Rectangle {

    id: cTool_Button;
    color: "transparent";

    property var sPressedImage: "";
    property var sNormalImage: "";
    property var sHoverImage: "";
    property var sTextText: "";
    property var nTextSize: 12;
    property var nIndex: 0;

    signal cToolButtonIndexBack(var nIndex);


    Image
    {
        id: cToolButtonImage;
        width: 24;
        height: 24;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        source: sNormalImage;
    }

    Text {
        id: cToolButtonText;
        width: parent.width;
        height: 70;
        anchors.top: parent.top;
        anchors.topMargin: 10;
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        wrapMode: Text.WordWrap;
        color: "#ffffff";
        font.family: "微软雅黑";
        font.pixelSize: nTextSize;
        font.letterSpacing: 1;
        text: sTextText;
    }

    MouseArea
    {
        id: cToolButtonMouseArea;

        anchors.fill: parent;
        acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MidButton;
        hoverEnabled: true;
        onPressed:
        {
            if(mouse.button === Qt.LeftButton)
            {
//                console.log("leftMouse->MenuButton");
            }else if(mouse.button === Qt.RightButton)
            {
//                console.log("rightMouse->MenuButton");
            }else if(mouse.button === Qt.MidButtonn)
            {
//                console.log("midMouse->MenuButton");
            }
            cTool_Button.state = "pressed";

        }
        onReleased:
        {
            cTool_Button.state = "normal";
            //cTool_Button.color = "#404040"
            cToolButtonIndexBack(nIndex);
//            console.log("release->menuButton");
        }
        onEntered:
        {
            if(cTool_Button.state === "normal")
            {
                cTool_Button.state = "hover";
                //cTool_Button.color = "#212121"
            }
//            console.log("enter->menuButton");
        }
        onExited:
        {
            if(cTool_Button.state === "hover"){
                cTool_Button.state = "normal";
               // cTool_Button.color = "#404040"
            }
//            console.log("exit->menuButton");
        }
        onWheel:
        {
//            console.log("wheel->menuButton");
        }

    }


    states: [
        State {
            name: "normal";
            PropertyChanges {
                target: cToolButtonImage;
                source: sNormalImage;
            }
        },
        State {
            name: "pressed";
            PropertyChanges {
                target: cToolButtonImage;
                source: sPressedImage;
            }
        },
        State {
            name: "hover";
            PropertyChanges {
                target: cToolButtonImage;
                source: sHoverImage;
            }
        }
    ]


}
