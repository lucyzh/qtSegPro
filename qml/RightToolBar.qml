import QtQuick 2.0

Rectangle {    //右侧工具栏

    id: rightToolBar;

    Image   //右侧工具栏分割线
    {   z:0.2
        id: rightDivide;
        width: 60;
        height: 2;
        anchors.left: parent.left;
        anchors.leftMargin: 5;
        anchors.top: parent.top;
        anchors.topMargin: 211;
        source: "images/Main/Functional dividing line_@2x.png";
    }


//    Row
//    {
//        id: row_cToolButtonList;

//        anchors.horizontalCenter: parent.horizontalCenter;
//        anchors.top: parent.top;
//        anchors.topMargin: 4;

//        height: parent.height;
//        spacing: 4;

//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/FilePressed.png";
//            sNormalImage: "images/Toolbar/FileNormal.png";
//            sHoverImage: "images/Toolbar/FilePressed.png";
//            state: "normal";
//            nIndex: 0;
//        }
//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/PositioningPressed.png";
//            sNormalImage: "images/Toolbar/PositioninNormal.png";
//            sHoverImage: "images/Toolbar/PositioningPressed.png";
//            state: "normal";
//            nIndex: 1;
//        }
//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/DelPressed.png";
//            sNormalImage: "images/Toolbar/DelNormal.png";
//            sHoverImage: "images/Toolbar/DelPressed.png";
//            state: "normal";
//            nIndex: 2;
//        }

//        Image {
//            id: speratorImage;
//            source: "images/Toolbar/ToolbarLine.png";
//        }


//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/BackPressed.png";
//            sNormalImage: "images/Toolbar/BackNormal.png";
//            sHoverImage: "images/Toolbar/BackPressed.png";
//            state: "normal";
//            nIndex: 3;
//        }
//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/ForwardPressed.png";
//            sNormalImage: "images/Toolbar/ForwardNormal.png";
//            sHoverImage: "images/Toolbar/ForwardPressed.png";
//            state: "normal";
//            nIndex: 4;
//        }
//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/AmplificationPressed.png";
//            sNormalImage: "images/Toolbar/AmplificationNormal.png";
//            sHoverImage: "images/Toolbar/AmplificationPressed.png";
//            state: "normal";
//            nIndex: 5;
//        }
//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/NarrowPressed.png";
//            sNormalImage: "images/Toolbar/NarrowNormal.png";
//            sHoverImage: "images/Toolbar/NarrowPressed.png";
//            state: "normal";
//            nIndex: 6;
//        }
//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/LeftPressed.png";
//            sNormalImage: "images/Toolbar/LeftNormal.png";
//            sHoverImage: "images/Toolbar/LeftPressed.png";
//            state: "normal";
//            nIndex: 7;
//        }
//        CommonToolButton
//        {
//            width: 40;
//            height: 36;
//            sPressedImage: "images/Toolbar/RightPressed.png";
//            sNormalImage: "images/Toolbar/RightNormal.png";
//            sHoverImage: "images/Toolbar/RightPressed.png";
//            state: "normal";
//            nIndex: 8;
//        }

//    }
    Column   //右边工具栏列表
    {
        id: right_cToolButtonList;

        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 40;
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
            nTextSize: 7;
            nIndex: 0;
            onCToolButtonIndexBack: {

              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)

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
            nTextSize: 7;
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
            nTextSize: 7;
            nIndex: 2;
            onCToolButtonIndexBack: {

              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)

            }
        }

//        Image {
//            id: speratorImage;
//            source: "images/Toolbar/ToolbarLine.png";
//        }


        CommonToolButton
        {
            width: 70;
            height: 54;
            sPressedImage: "images/Main/load2_@2x.png";
            sNormalImage: "images/Main/load_@2x.png";
            sHoverImage: "images/Main/load2_@2x.png";
            state: "normal";
            sTextText: "加载标签";
            nTextSize: 7;
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
            nTextSize: 7;
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
            nTextSize: 7;
            nIndex: 5;
            onCToolButtonIndexBack: {

              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)

            }
        }

   }
}
