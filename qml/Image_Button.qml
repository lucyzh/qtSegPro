import QtQuick 2.0

Rectangle {

    id: cImage_Button;
    color: "transparent";

    property var sPressedImage: "";
    property var sNormalImage: "";
    property var sHoverImage: "";
    property var sTextText: "";
    property var nTextSize: 12;
    property var nIndex: 0;

    signal cImageButtonIndexBack(var nIndex);


    Image
    {
        id: cButtonImage;
        width: 30;
        height: 24;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter
        source: sNormalImage;
    }

    Text {
        id: cButtonText;
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
        id: cImageButtonMouseArea;

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
            cImage_Button.state = "pressed";

        }
        onReleased:
        {
            cImage_Button.state = "normal";
            cToolButtonIndexBack(nIndex);
//            console.log("release->menuButton");
        }
        onEntered:
        {
            if(cImage_Button.state === "normal")
            {
                cImage_Button.state = "hover";
                //cImage_Button.color = "#212121"
            }
        }
        onExited:
        {
            if(cImage_Button.state === "hover"){
                cImage_Button.state = "normal";
            }
        }
        onWheel:
        {
        }

    }


    states: [
        State {
            name: "normal";
            PropertyChanges {
                target: cButtonImage;
                source: sNormalImage;
            }
        },
        State {
            name: "pressed";
            PropertyChanges {
                target: cButtonImage;
                source: sPressedImage;
            }
        },
        State {
            name: "hover";
            PropertyChanges {
                target: cButtonImage;
                source: sHoverImage;
            }
        }
    ]


}
