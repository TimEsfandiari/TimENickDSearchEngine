TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    AVLIndexer.cpp \
    IndexDriver.cpp \
    QueryProcessor.cpp \
    StopWorder.cpp \
    uniqueWords.cpp \
    VirtualIndexer.cpp \
    WordInfo.cpp \
    XMLparser.cpp \
    XMLPasser.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    AVLIndexer.h \
    AVLTree.hpp \
    IndexDriver.h \
    QueryProcessor.h \
    rapidxml.hpp \
    rapidxml_iterators.hpp \
    rapidxml_print.hpp \
    rapidxml_utils.hpp \
    StopWorder.h \
    uniqueWords.h \
    VirtualIndexer.h \
    WordInfo.h \
    XMLparser.h \
    XMLPasser.h

