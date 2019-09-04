import QtQuick 2.0
import Imagepro 1.1

Rectangle{  //参数1
    id: parameterRect;
    color: "transparent";

//    ImageProItem{
//        id:imageItem
//    }

    Text {
        id: menuButtonText;
        width: 50;
        height: parent.height;
        anchors.left: parent.left;
        verticalAlignment: Text.AlignVCenter;
        wrapMode: Text.WordWrap;
        color: "#ffffff";
        font.family: "微软雅黑";
        font.pixelSize: 15;
        font.letterSpacing: 1;
        text: "参数1: ";
    }
    Rectangle{
        id: mytextone;
        color: "white";
        height: 40
        width: 150
        anchors.left: parent.left;
        anchors.leftMargin: 60;

    TextInput{
        id:parameterone;
        width: parent.width;
        height: parent.height;
        //anchors.centerIn: parent
        color: "black"
        font.pixelSize: 15
        maximumLength: 3  //最大输入长度，单位是字符，默认32767
        font.bold: false //加粗，默认false
        font.italic: false //是否用斜体,默认false
        font.letterSpacing: 0 //字母之间距离，正表示增加，负表示缩小，0表示默认距离
        font.wordSpacing: 0 //单词之间的距离，说明同上行
        font.strikeout: false //设置字体是否有删除线，默认false
        font.underline: false //设置字体是否有下划线，默认false
        activeFocusOnPress: true //默认true,鼠标点击是否能输入。
        autoScroll: true //文本长度大于宽度时是否滚动，默认true
        //readOnly: true  //设置只读
        //inputMask: "you" //替代输入，相当text显示you，个人理解
        //cursorDelegate: comp_text//光标也就是输入区域的高显，该委托起点是输入的终点
        //cursorVisible: false
        //cursorPosition: 200
        //echoMode: TextInput.Password //显示密码符而不是输入的字符
        //echoMode: TextInput.Normal //默认的显示输入的字符
        //echoMode: TextInput.NoEcho //什么都不显示
        //echoMode: TextInput.PasswordEchoOnEdit
        //passwordCharacter: "*k" //设置模式为密码时显示的字符，第一个字母有效
        //设置文本的大小写
        //font.capitalization: Font.MixedCase //不使用大小写改变
        //font.capitalization: Font.AllUppercase //所有的都大写
        //font.capitalization: Font.AllLowercase //所有的都小写
        //font.capitalization: Font.SmallCaps //使用小大写，
        //font.capitalization: Font.Capitalize  //单词的第一个字母大写
        //font.weight: Font.Light
        //font.weight: Font.Normal
        //font.weight: Font.DemiBold
        //font.weight: Font.Bold
        //font.weight: Font.Black
        //文本的对齐方式，顾名思义
         //horizontalAlignment: TextInput.AlignHCenter
         verticalAlignment: TextInput.AlignVCenter
         horizontalAlignment: TextInput.AlignLeft
        //horizontalAlignment: TextInput.AlignRight
        selectByMouse: true //是否可以选择文本
        //选择文本的方式，只有selectByMouse为真才有效
        //mouseSelectionMode: TextInput.SelectCharacters //一个字符为单位选择，默认
        //mouseSelectionMode: TextInput.SelectWords      //一个单词为单位选择
        selectedTextColor: "black" //设置选择文本的字体颜色
        selectionColor: "white"    //设置选择框的颜色
        text:"2" //输入文本默认显示的，可以修改和增加
        onAccepted: console.log("accepted") //当按下回车键触发该信号
        //需要注意的是当设置了验证器validator或者掩码inputMask时，只有在输入被接受的情况下才能触发
        //validator: IntValidator{bottom: 5;top:120}
        //只接受1-20之内的整数
        validator: DoubleValidator{
            bottom: 0.0
            top:1.0
            decimals: 0 //保留小数点位数
            //notation: DoubleValidator.StandardNotation
            //notation: DoubleValidator.ScientificNotation
        }
        onTextChanged: {
            imageItem.getModelParam(parameterone.text);
        }
    }
}
    Image    //增加按钮
    {
        id: increaseone;
        width: 28;
        height: 18.5;
        anchors.right: parent.right;
        source: "images/Main/increase_@2x.png";
    }
    Image    //减少按钮
    {
        id: minusone;
        width: 28;
        height: 18.5;
        anchors.right: parent.right;
        anchors.top:parent.top;
        anchors.topMargin: 20;
        source: "images/Main/minus_@2x.png";
    }



}
