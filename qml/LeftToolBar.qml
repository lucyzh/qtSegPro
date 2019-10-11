import QtQuick 2.0

Rectangle {

    id: leftToolBar;   //左侧工具栏

    Column   //左边工具栏列表
    {
        id: left_cToolButtonList;

        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 10;
        height: parent.height;
        spacing: 4;
        function setChildrenState(nIndex)
        {
            for(var i = 0 ; i < left_cToolButtonList.children.length; i++)
            {
                if(nIndex === i)
                {
                    console.log("111")
                    left_cToolButtonList.children[i].state = "pressed";
                }
                else
                {
                    console.log("222")
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
                    console.log("111")
                    left_cToolButtonList.children[i].color = "#212121";
                }
                else
                {
                    console.log("222")
                    left_cToolButtonList.children[i].color = "#404040";
                }
            }
        }
        CommonToolButton       //矩形工具
        {   id:rectTool;
            width: 70;
            height: 54;
            sPressedImage: "images/Main/Rectangle tool2_@2x.png";
            sNormalImage: "images/Main/Rectangle tool_@2x.png";
            sHoverImage: "images/Main/Rectangle tool2_@2x.png";
            state: "normal";
            sTextText: "矩形工具";
            nTextSize: 12;
            nIndex: 0;
            onCToolButtonIndexBack: {
              left_cToolButtonList.setChildrenState(nIndex)
              left_cToolButtonList.setChildrenColor(nIndex)

            }
        }
        CommonToolButton
        {
            id:brushTool;
            width: 70;
            height: 54;
            sPressedImage: "images/Main/brush2_@2x.png";
            sNormalImage: "images/Main/brush_@2x.png";
            sHoverImage: "images/Main/brush2_@2x.png";
            state: "normal";
            sTextText: "标记前景";
            nTextSize: 12;
            nIndex: 1;
            onCToolButtonIndexBack: {

              left_cToolButtonList.setChildrenState(nIndex)
              left_cToolButtonList.setChildrenColor(nIndex)
            }
        }
        CommonToolButton
        {
            id:tagTool;
            width: 70;
            height: 54;
            sPressedImage: "images/Main/brush2_@2x.png";
            sNormalImage: "images/Main/brush_@2x.png";
            sHoverImage: "images/Main/brush2_@2x.png";
            state: "normal";
            sTextText: "标记背景";
            nTextSize: 12;
            nIndex: 2;
            onCToolButtonIndexBack: {
              left_cToolButtonList.setChildrenState(nIndex)
              left_cToolButtonList.setChildrenColor(nIndex)
            }
        }
   }
}
