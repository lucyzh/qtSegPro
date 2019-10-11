import QtQuick 2.0
import Imagepro 1.1

Rectangle {    //右侧工具栏

    id: rightToolBar;

// 分割线是否有必要？？？
//    Image   //右侧工具栏分割线
//    {   z:0.2
//        id: rightDivide;
//        width: 60;
//        height: 2;
//        anchors.left: parent.left;
//        anchors.leftMargin: 5;
//        anchors.top: parent.top;
//        anchors.topMargin: 210;
//        source: "images/Main/Functional dividing line_@2x.png";
//    }

    Column   //右边工具栏列表
    {
        id: right_cToolButtonList;

        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        //anchors.topMargin: 40;
        height: parent.height;
        spacing: 4;
        function setChildrenState(nIndex)
        {
            for(var i = 0 ; i < right_cToolButtonList.children.length; i++)
            {
                if(nIndex === i)
                {
                    console.log("111")
                    right_cToolButtonList.children[i].state = "pressed";
                }
                else
                {
                    console.log("222")
                    right_cToolButtonList.children[i].state = "normal";
                }
            }
        }
        function setChildrenColor(nIndex)
        {
            for(var i = 0 ; i < right_cToolButtonList.children.length; i++)
            {
                if(nIndex === i)
                {
                    console.log("111")
                    right_cToolButtonList.children[i].color = "#212121";
                }
                else
                {
                    console.log("222")
                    right_cToolButtonList.children[i].color = "#404040";
                }
            }
        }
        CommonToolButton       //开始分割
        {
            width: 70;
            height: 54;
            sPressedImage: "images/Main/Start2_@2x.png";
            sNormalImage: "images/Main/Start_@2x.png";
            sHoverImage: "images/Main/Start2_@2x.png";
            state: "normal";
            sTextText: "开始分割";
            nTextSize: 12;
            nIndex: 0;
            onCToolButtonIndexBack: {
              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)
              imageItem.startSeg()
            }
        }
        CommonToolButton
        {
            width: 70;
            height: 54;
            sPressedImage: "images/Main/Update2_@2x.png";
            sNormalImage: "images/Main/Update_@2x.png";
            sHoverImage: "images/Main/Update2_@2x.png";
            state: "normal";
            sTextText: "更新分割";
            nTextSize: 12;
            nIndex: 1;
            onCToolButtonIndexBack: {

              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)

            }
        }
        CommonToolButton
        {
            width: 70;
            height: 54;
            sPressedImage: "images/Main/save2_@2x.png";
            sNormalImage: "images/Main/save_@2x.png";
            sHoverImage: "images/Main/save2_@2x.png";
            state: "normal";
            sTextText: "保存分割";
            nTextSize: 12;
            nIndex: 2;
            onCToolButtonIndexBack: {

              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)

            }
        }

        CommonToolButton
        {
            width: 70;
            height: 54;
            sPressedImage: "images/Main/load2_@2x.png";
            sNormalImage: "images/Main/load_@2x.png";
            sHoverImage: "images/Main/load2_@2x.png";
            state: "normal";
            sTextText: "加载标签";
            nTextSize: 12;
            nIndex: 3;
            onCToolButtonIndexBack: {
              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)
            }
        }
        CommonToolButton
        {
            width: 70;
            height: 54;
            sPressedImage: "images/Main/Update label2_@2x.png";
            sNormalImage: "images/Main/Update label_@2x.png";
            sHoverImage: "images/Main/Update label2_@2x.png";
            state: "normal";
            sTextText: "更新标签";
            nTextSize: 12;
            nIndex: 4;
            onCToolButtonIndexBack: {

              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)

            }
        }
        CommonToolButton
        {
            width: 70;
            height: 54;
            sPressedImage: "images/Main/Clear label2_@2x.png";
            sNormalImage: "images/Main/Clear label_@2x.png";
            sHoverImage: "images/Main/Clear label2_@2x.png";
            state: "normal";
            sTextText: "清除标签";
            nTextSize: 12;
            nIndex: 5;
            onCToolButtonIndexBack: {

              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)

            }
        }

   }
}
