cmake_minimum_required(VERSION 3.26)
project(PrOS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")

set(CMAKE_PREFIX_PATH "F:\\Qt\\6.5.3\\mingw_64\\lib\\cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_executable(PrOS main.cpp
        src/Essentials/MainWindow.cpp
        src/Essentials/MainWindow.h
        src/Essentials/CustomClass/ImageButton/ImageButton.cpp
        src/Essentials/CustomClass/ImageButton/ImageButton.h
        src/Essentials/CustomClass/TaskbarThemes/TaskBarThemes.cpp
        src/Essentials/CustomClass/TaskbarThemes/TaskBarThemes.h
        src/Essentials/CustomClass/TextLabel/TextLabel.cpp
        src/Essentials/CustomClass/TextLabel/TextLabel.h
        src/Essentials/Utils/GetTimeDate.cpp
        src/Essentials/Utils/GetTimeDate.h
        src/Essentials/CustomClass/ImageLabel/ImageLabel.cpp
        src/Essentials/CustomClass/ImageLabel/ImageLabel.h)

target_link_libraries(PrOS
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()