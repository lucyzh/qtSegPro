QT += quick
QT += widgets
CONFIG += c++11
RC_ICONS = IPFWIcon.ico
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# add compile option
QMAKE_CXXFLAGS += -std=libstdc++

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        colorimageprovider.cpp \
        convert.cpp \
        externalvar.cpp \
        imageprocess.cpp \
        main.cpp

RESOURCES += qml.qrc \
    image.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

#macOS version
QMAKE_MAC_SDK = macosx10.15
CONFIT+=sdk_no_version_check

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    colorimageprovider.h \
    convert.h \
    externalvar.h \
    imageprocess.h

# Configure opencv env
# <!---https://blog.csdn.net/computerme/article/details/52986413--->
INCLUDEPATH += /usr/local/Cellar/opencv/4.0.1/include
INCLUDEPATH += /usr/local/Cellar/opencv/4.0.1/include/opencv4
INCLUDEPATH += /usr/local/Cellar/opencv/4.0.1/include/opencv4/opencv2
LIBS += -L/usr/local/lib \
 -lopencv_core \
 -lopencv_highgui \
 -lopencv_imgproc \
 -lopencv_imgcodecs \
