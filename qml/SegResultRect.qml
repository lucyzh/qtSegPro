import QtQuick 2.0
import Imagepro 1.1

Rectangle{

    id:segResultRect       //分割结果显示框
    color: "#C1C1C1";
    border.color: "white";
    height: parent.height - 100;
    width: parent.width/2-70;
//    Text
//    {
//        id: vTextContent;   //内容
//        color:"#ffffff";
//        width: parent.width;
//        height: 50;
//        anchors.top: parent.top;
//        anchors.topMargin: 25;
//        anchors.left: parent.left;
//        anchors.leftMargin: 130;
//        horizontalAlignment: Text.AlignCenter;
//        verticalAlignment: Text.AlignVCenter;
//        wrapMode: Text.WordWrap;
//        font.family: "微软雅黑";
//        font.pixelSize: 20;
//        font.letterSpacing: 1;
//        font.bold: true;
//        text: "分割结果显示区域";
//    }
    ImageProItem{
        id:imageSeg
    }

    Image   //显示图片
    {
        id: segRes;
        cache: false;
        height: parent.height*0.8;
        width: parent.width;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top :parent.top
        source: "image://imgProvider/seg"
    }

    Timer
    {
        interval: 10;
        running: true;
        repeat: true;
        onTriggered:
        {
            segRes.source = "";
            segRes.source = "image://imgProvider/seg"
        }
    }
}
