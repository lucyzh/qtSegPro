import QtQuick 2.0
import Imagepro 1.1

Rectangle{

    id:segResultRect       //分割结果显示框
    color: "#C1C1C1";
    border.color: "white";
    height: parent.height-100;
    width: parent.width/2-70;
    anchors.bottom: parent.bottom;
    anchors.bottomMargin: 20;

    ImageProItem{
        id:imageSeg
    }

    Image   //显示图片
    {
        id: segRes;
        cache: false;
        height: parent.height*0.8;
        width: parent.width;
        fillMode: Image.PreserveAspectFit;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top :parent.top
        anchors.topMargin: 5;
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
