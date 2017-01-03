TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    qhash_path.cpp \
    qfile_system.cpp \
    hash_path.cpp \
    qfile_system_builder_adapter.cpp \
    file_system_builder.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD../../DirectoryDiff/DirectoryDiff

HEADERS += \
    qhash_path.h \
    qfile_system.h \
    hash_path.h \
    stdafx.h \
    gc_file_system.h \
    qfile_system_builder_adapter.h \
    file_system_builder.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/ -lboost_thread-vc140-mt-1_62
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/ -lboost_thread-vc140-mt-1_62d

INCLUDEPATH += $$PWD/../../../../../../boost_1_62_0
DEPENDPATH += $$PWD/../../../../../../boost_1_62_0

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/libboost_thread-vc140-mt-1_62.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/libboost_thread-vc140-mt-1_62d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/boost_thread-vc140-mt-1_62.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/boost_thread-vc140-mt-1_62d.lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/ -lboost_filesystem-vc140-mt-1_62
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/ -lboost_filesystem-vc140-mt-1_62d

INCLUDEPATH += $$PWD/../../../../../../boost_1_62_0
DEPENDPATH += $$PWD/../../../../../../boost_1_62_0

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/libboost_filesystem-vc140-mt-1_62.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/libboost_filesystem-vc140-mt-1_62d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/boost_filesystem-vc140-mt-1_62.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../boost_1_62_0/lib64-msvc-14.0/boost_filesystem-vc140-mt-1_62d.lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../OpenSSL-Win64/lib/VC/ -llibcrypto64MT
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../OpenSSL-Win64/lib/VC/ -llibcrypto64MTd

INCLUDEPATH += $$PWD/../../../../../../OpenSSL-Win64/include
DEPENDPATH += $$PWD/../../../../../../OpenSSL-Win64/lib/VC

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../OpenSSL-Win64/lib/VC/liblibcrypto64MT.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../OpenSSL-Win64/lib/VC/liblibcrypto64MTd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../OpenSSL-Win64/lib/VC/libcrypto64MT.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../OpenSSL-Win64/lib/VC/libcrypto64MTd.lib
