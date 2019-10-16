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
            if(nIndex == 0)
            {
                console.log("click ready to paint rec")
               // menuAllMouseArea.visible = false
                maforpaintingrec.visible = true
                maforpaintingpnt.visible = false
                mabgpaintingpnt.visible = false
                //allMouseArea.visible = false
            }
            else if(nIndex == 1)
            {
                console.log("click ready to use brush")
               // menuAllMouseArea.visible = false
                maforpaintingrec.visible = false
                maforpaintingpnt.visible = true
                mabgpaintingpnt.visible = false
                //allMouseArea.visible = false
            }
            else if(nIndex == 2)
            {
                maforpaintingrec.visible = false
                maforpaintingpnt.visible = false
                mabgpaintingpnt.visible = true
            }
            else
            {
                console.log("nIndex out of range")
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
