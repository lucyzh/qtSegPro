import QtQuick 2.0
import Imagepro 1.1
Rectangle{

    id:imageOpen       //打开图片显示框
    color: "#C1C1C1";
    border.color: "white";
    height: parent.height-200;
    width: parent.width / 2 - 50;
    anchors.bottom: parent.bottom-200;

    ImageProItem{
        id:imageItem
    }

    Image   //显示图片
    {
        id: imgRes;
        cache: false;
        height: parent.height*0.8;
        width: parent.width;
        fillMode: Image.PreserveAspectFit;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top :parent.top
        anchors.topMargin: 5;
        source: "image://imgProvider/img"
    }

    Timer
    {
        interval: 10;
        running: true;
        repeat: true;
        onTriggered:
        {
            imgRes.source = "";
            imgRes.source = "image://imgProvider/img"
        }
    }
}
