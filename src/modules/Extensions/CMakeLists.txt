cmake_minimum_required(VERSION 3.1)
project(Extensions)

set(Extensions_HDR
    Extensions.hpp
    YouTube.hpp
    Downloader.hpp
    Radio.hpp
    Radio/RadioBrowserModel.hpp
)

set(Extensions_SRC
    Extensions.cpp
    YouTube.cpp
    Downloader.cpp
    Radio.cpp
    Radio/RadioBrowserModel.cpp
)

set(Extensions_FORMS
    Radio/Radio.ui
)

set(Extensions_RESOURCES
    icons.qrc
)

if(USE_MPRIS2)
    list(APPEND Extensions_HDR MPRIS2.hpp)
    list(APPEND Extensions_SRC MPRIS2.cpp)
    add_definitions(-DUSE_MPRIS2)
    set(DBUS Qt5::DBus)
endif()

if(USE_LASTFM)
    list(APPEND Extensions_HDR LastFM.hpp)
    list(APPEND Extensions_SRC LastFM.cpp)
    add_definitions(-DUSE_LASTFM)
endif()

if(USE_TEKSTOWO)
    list(APPEND Extensions_HDR Tekstowo.hpp)
    list(APPEND Extensions_SRC Tekstowo.cpp)
    add_definitions(-DUSE_TEKSTOWO)
endif()

if(USE_MYFREEMP3)
    list(APPEND Extensions_HDR MediaBrowser/MyFreeMp3.hpp)
    list(APPEND Extensions_SRC MediaBrowser/MyFreeMp3.cpp)
    add_definitions(-DUSE_MYFREEMP3)
endif()
if(USE_ANIMEODCINKI)
    list(APPEND Extensions_HDR MediaBrowser/AnimeOdcinki.hpp)
    list(APPEND Extensions_SRC MediaBrowser/AnimeOdcinki.cpp)
    add_definitions(-DUSE_ANIMEODCINKI)
endif()
if(USE_WBIJAM)
    list(APPEND Extensions_HDR MediaBrowser/Wbijam.hpp)
    list(APPEND Extensions_SRC MediaBrowser/Wbijam.cpp)
    add_definitions(-DUSE_WBIJAM)
endif()
if(USE_MYFREEMP3 OR USE_ANIMEODCINKI OR USE_WBIJAM)
    list(APPEND Extensions_HDR MediaBrowser.hpp MediaBrowser/Common.hpp)
    list(APPEND Extensions_SRC MediaBrowser.cpp MediaBrowser/Common.cpp)
    add_definitions(-DUSE_MEDIABROWSER)
endif()

qt5_wrap_ui(Extensions_FORM_HDR ${Extensions_FORMS})
set_property(SOURCE ${Extensions_FORM_HDR} PROPERTY SKIP_AUTOMOC ON)

include_directories(../../qmplay2/headers)

add_library(${PROJECT_NAME} ${QMPLAY2_MODULE}
    ${Extensions_HDR}
    ${Extensions_SRC}
    ${Extensions_FORM_HDR}
    ${Extensions_RESOURCES}
)

target_link_libraries(${PROJECT_NAME}
    ${DBUS}
    libqmplay2
)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${MODULES_INSTALL_PATH})
