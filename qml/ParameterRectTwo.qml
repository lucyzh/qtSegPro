import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{   //参数2
    id: parameterRectTwo;
    color: "#e1e1e1";
    GroupBox
    {
        title: "保存结果功能区";
        id: saveBtnArea;
        z: 0.2;
        width: 180;
        height: 100;

        // 自动分割模式功能按钮区
        Rectangle {
            id: funcBtns;
            anchors.left: gbMode.right;
            anchors.top: gbMode.top;
//            anchors.leftMargin: 10;
//            anchors.topMargin: 10;
            color: "transparent";
            width: 100;
            height: 80;

            // 加载掩膜
            Button {
                id: loadMaskBtn;
                anchors.top: parent.top+10;
                anchors.left: segResultRect.left;
                width: 80;
                height: 30;

                Text {
                    text: "加载掩膜";
                    font.pixelSize: 12;
                    anchors.top: parent.top;
                    anchors.left: parent.left;
                    anchors.topMargin: 8;
                    anchors.leftMargin: 15;
                    horizontalAlignment: Text.AlignHCenter;
                    verticalAlignment: Text.AlignVCenter;
                }
            }

            // 保存掩膜
            Button {
                id: saveMaskBtn;
                anchors.top: loadMaskBtn.bottom;
                anchors.left: parent.left;
                width: 80;
                height: 30;
                Text {
                    text: "保存掩膜";
                    font.pixelSize: 12;
                    anchors.top: parent.top;
                    anchors.left: parent.left;
                    anchors.topMargin: 8;
                    anchors.leftMargin: 15;
                    horizontalAlignment: Text.AlignHCenter;
                    verticalAlignment: Text.AlignVCenter;
                }
            }

            // 保存显著图
            Button {
                id: saveSalMapBtn;
                anchors.top: loadMaskBtn.top;
                anchors.left: loadMaskBtn.right;
                width: 80;
                height: 30;
                Text {
                    text: "保存显著图";
                    font.pixelSize: 12;
                    anchors.top: parent.top;
                    anchors.left: parent.left;
                    anchors.topMargin: 8;
                    anchors.leftMargin: 8;
                    horizontalAlignment: Text.AlignHCenter;
                    verticalAlignment: Text.AlignVCenter;
                }
            }

            // 保存分割结果
            Button {
                id: saveSegBtn;
                anchors.top: saveMaskBtn.top;
                anchors.left: saveSalMapBtn.left;
                width: 80;
                height: 30;
                Text {
                    text: "保存分割结果";
                    font.pixelSize: 12;
                    anchors.top: parent.top;
                    anchors.left: parent.left;
                    anchors.topMargin: 8;
                    anchors.leftMargin: 3;
                    horizontalAlignment: Text.AlignHCenter;
                    verticalAlignment: Text.AlignVCenter;
                }
            }
        }
    }

    /*
       date: 2020.12.09
       auth: lei zhao
       comment: comment the code of manual seg params rect,
       and change the control for both manual and auto seg.
   */
//    Text {
//        id: menuButtonText;
//        width: 50;
//        height: parent.height;
//        anchors.left: parent.left;
//        verticalAlignment: Text.AlignVCenter;
//        wrapMode: Text.WordWrap;
//        color: "#ffffff";
//        font.family: "微软雅黑";
//        font.pixelSize: 15;
//        font.letterSpacing: 1;
////        font.bold: true;
//        text: "参数2: ";
//    }
//    Rectangle{
//        id: mytexttwo;
//        color: "white";
//        height: 40
//        width: 150
//        anchors.left: parent.left;
//        anchors.leftMargin: 60;

//    TextInput{
//        id:parametertwo;
//        width: parent.width;
//        height: parent.height;
//        //anchors.centerIn: parent
//        color: "black"
//        font.pixelSize: 15
//        maximumLength: 3  //最大输入长度，单位是字符，默认32767
//        font.bold: false //加粗，默认false
//        font.italic: false //是否用斜体,默认false
//        font.letterSpacing: 0 //字母之间距离，正表示增加，负表示缩小，0表示默认距离
//        font.wordSpacing: 0 //单词之间的距离，说明同上行
//        font.strikeout: false //设置字体是否有删除线，默认false
//        font.underline: false //设置字体是否有下划线，默认false
//        activeFocusOnPress: true //默认true,鼠标点击是否能输入。
//        autoScroll: true //文本长度大于宽度时是否滚动，默认true
//        //readOnly: true  //设置只读
//        //inputMask: "you" //替代输入，相当text显示you，个人理解
//        //cursorDelegate: comp_text//光标也就是输入区域的高显，该委托起点是输入的终点
//        //cursorVisible: false
//        //cursorPosition: 200
//        //echoMode: TextInput.Password //显示密码符而不是输入的字符
//        //echoMode: TextInput.Normal //默认的显示输入的字符
//        //echoMode: TextInput.NoEcho //什么都不显示
//        //echoMode: TextInput.PasswordEchoOnEdit
//        //passwordCharacter: "*k" //设置模式为密码时显示的字符，第一个字母有效
//        //设置文本的大小写
//        //font.capitalization: Font.MixedCase //不使用大小写改变
//        //font.capitalization: Font.AllUppercase //所有的都大写
//        //font.capitalization: Font.AllLowercase //所有的都小写
//        //font.capitalization: Font.SmallCaps //使用小大写，
//        //font.capitalization: Font.Capitalize  //单词的第一个字母大写
//        //font.weight: Font.Light
//        //font.weight: Font.Normal
//        //font.weight: Font.DemiBold
//        //font.weight: Font.Bold
//        //font.weight: Font.Black
//        //文本的对齐方式，顾名思义
//        //horizontalAlignment: TextInput.AlignHCenter
//        //horizontalAlignment: TextInput.AlignHCenter
//        verticalAlignment: TextInput.AlignVCenter
//        horizontalAlignment: TextInput.AlignLeft
//        //horizontalAlignment: TextInput.AlignRight
//        selectByMouse: true //是否可以选择文本
//        //选择文本的方式，只有selectByMouse为真才有效
//        //mouseSelectionMode: TextInput.SelectCharacters //一个字符为单位选择，默认
//        //mouseSelectionMode: TextInput.SelectWords      //一个单词为单位选择
//        selectedTextColor: "black" //设置选择文本的字体颜色
//        selectionColor: "white"    //设置选择框的颜色
//        text:"0.5" //输入文本默认显示的，可以修改和增加
//        onAccepted: console.log("accepted") //当按下回车键触发该信号
//        //需要注意的是当设置了验证器validator或者掩码inputMask时，只有在输入被接受的情况下才能触发
//        //validator: IntValidator{bottom: 5;top:120}
//        //只接受5-120之内的值，当输入为4按回车时没有触发onAccepted。
//        //            validator: DoubleValidator{
//        //                bottom: 10.00
//        //                top:150.01
//        //                decimals: 3 //保留小数点位数
//        //                //notation: DoubleValidator.StandardNotation
//        //                //notation: DoubleValidator.ScientificNotation
//        //            }
//    }
//}
//    Image    //增加按钮
//    {
//        id: increasetwo;
//        width: 28;
//        height: 18.5;
//        anchors.right: parent.right;
//        source: "images/Main/increase_@2x.png";
//    }
//    Image    //减少按钮
//    {
//        id: minustwo;
//        width: 28;
//        height: 18.5;
//        anchors.right: parent.right;
//        anchors.top:parent.top;
//        anchors.topMargin: 20;
//        source: "images/Main/minus_@2x.png";
//    }
}
