import QtQuick 2.0
import Imagepro 1.1

Rectangle {    //右侧工具栏

    id: rightToolBar;
    anchors.leftMargin: 10;

    Column   //右边工具栏列表
    {
        id: right_cToolButtonList;

        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        height: parent.height;
        spacing: 4;
        function setChildrenState(nIndex)
        {
            for(var i = 0 ; i < right_cToolButtonList.children.length; i++)
            {
                if(nIndex === i)
                {
                    right_cToolButtonList.children[i].state = "pressed";
                }
                else
                {
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
                    right_cToolButtonList.children[i].color = "#212121";
                }
                else
                {
                    right_cToolButtonList.children[i].color = "#404040";
                }
            }
        }
        CommonToolButton       //开始分割
        {
            width: 50;
            height: 54;
            sPressedImage: "images/Main/Start2_@2x.png";
            sNormalImage: "images/Main/Start_@2x.png";
            sHoverImage: "images/Main/Start2_@2x.png";
            state: "normal";
            sTextText: "开始分割";
            nIndex: 0;
            onCToolButtonIndexBack: {
              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)
              //imageItem.startSeg()
              imageItem.startSeg()
            }
        }

        CommonToolButton
        {
            width: 50;
            height: 54;
            sPressedImage: "images/Main/save2_@2x.png";
            sNormalImage: "images/Main/save_@2x.png";
            sHoverImage: "images/Main/save2_@2x.png";
            state: "normal";
            sTextText: "保存分割";
            nIndex: 1;
            onCToolButtonIndexBack: {
              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)
              imageItem.saveLabel();
            }
        }

        CommonToolButton
        {
            width: 50;
            height: 54;
            sPressedImage: "images/Main/load2_@2x.png";
            sNormalImage: "images/Main/load_@2x.png";
            sHoverImage: "images/Main/load2_@2x.png";
            state: "normal";
            sTextText: "保存标签";
            nIndex: 2;
            onCToolButtonIndexBack: {
              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)
            }
        }
        CommonToolButton
        {
            width: 50;
            height: 54;
            sPressedImage: "images/Main/Update label2_@2x.png";
            sNormalImage: "images/Main/Update label_@2x.png";
            sHoverImage: "images/Main/Update label2_@2x.png";
            state: "normal";
            sTextText: "加载标签";
            nIndex: 3;
            onCToolButtonIndexBack: {
              right_cToolButtonList.setChildrenState(nIndex)
              right_cToolButtonList.setChildrenColor(nIndex)
              imageItem.openLabel();
            }
        }

   }
}
