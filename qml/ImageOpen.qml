import QtQuick 2.0
import Imagepro 1.1
Rectangle{

    id:imageOpen       //打开图片显示框
    color: "#C1C1C1";
    //border.color: "white";
    height: parent.height - 100;
    width: parent.width / 2-70;
    ImageProItem{
        id:imageItem

    }
    Image   //显示图片
    {
        id: imgRes;
        cache: false;
        height: parent.height/2;
        width: parent.width/2;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        source: "image://colors/hello"
    }



    Timer
    {
        interval: 1000;
        running: true;
        repeat: true;
        onTriggered:
        {
            imgRes.source = "";
            imgRes.source = "image://colors/hello"
            console.log("<<<<<<<<<<<<<<<<<<<<<<<<<<<Fresh");
            imageItem.processImage();
            console.log("---------------------------Fresh");
        }
    }
}
