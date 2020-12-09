import QtQuick 2.0

Rectangle {

    id: leftToolBar;
    anchors.rightMargin: 10;

    //左边工具栏列表
    Column
    {
        id: left_cToolButtonList;

        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        height: parent.height;
        spacing: 4;
        function setChildrenState(nIndex)
        {
            for(var i = 0 ; i < left_cToolButtonList.children.length; i++)
            {
                if(nIndex === i)
                {
                    left_cToolButtonList.children[i].state = "pressed";
                }
                else
                {
                    left_cToolButtonList.children[i].state = "normal";
                }
            }
        }
        function setChildrenColor(nIndex)
        {
            for(var i = 0 ; i < left_cToolButtonList.children.length; i++)
            {
                if(nIndex === i)
                {
                    left_cToolButtonList.children[i].color = "#212121";
                }
                else
                {
                    left_cToolButtonList.children[i].color = "#404040";
                }
            }
        }
        CommonToolButton       //矩形工具
        {   id:rectTool;
            width: 50;
            height: 54;
            sPressedImage: "images/Main/Rectangle tool2_@2x.png";
            sNormalImage: "images/Main/Rectangle tool_@2x.png";
            sHoverImage: "images/Main/Rectangle tool2_@2x.png";
            state: "normal";
            sTextText: "矩形工具";
            nIndex: 0;
            onCToolButtonIndexBack: {
              left_cToolButtonList.setChildrenState(nIndex)
              left_cToolButtonList.setChildrenColor(nIndex)

            }
        }
        CommonToolButton
        {
            id:brushTool;
            width: 50;
            height: 54;
            sPressedImage: "images/Main/brush2_@2x.png";
            sNormalImage: "images/Main/brush_@2x.png";
            sHoverImage: "images/Main/brush2_@2x.png";
            state: "normal";
            sTextText: "标记前景";
            nIndex: 1;
            onCToolButtonIndexBack: {
              left_cToolButtonList.setChildrenState(nIndex)
              left_cToolButtonList.setChildrenColor(nIndex)
            }
        }
        CommonToolButton
        {
            id:tagTool;
            width: 50;
            height: 54;
            sPressedImage: "images/Main/brush2_@2x.png";
            sNormalImage: "images/Main/brush_@2x.png";
            sHoverImage: "images/Main/brush2_@2x.png";
            state: "normal";
            sTextText: "标记背景";
            nIndex: 2;
            onCToolButtonIndexBack: {
              left_cToolButtonList.setChildrenState(nIndex)
              left_cToolButtonList.setChildrenColor(nIndex)
            }
        }
   }
}
