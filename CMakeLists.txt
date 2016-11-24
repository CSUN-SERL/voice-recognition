
cmake_minimum_required(VERSION 2.8.12)

project(voice_recognition)

find_package(Qt5Widgets REQUIRED)
find_package(catkin REQUIRED COMPONENTS
                        roscpp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(voice_recognition_INCLUDE_DIRECTORIES
        src
        include
        resources
	/usr/lib/jvm/java-8-openjdk-amd64/include
	/usr/lib/jvm/java-8-openjdk-amd64/include/linux
)

include_directories(${voice_recognition_INCLUDE_DIRECTORIES}
                    ${Qt5Widgets_INCLUDE_DIRS}
                    ${catkin_INCLUDE_DIRS} )

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS roscpp
    DEPENDS Qt5Widgets )

file(GLOB voice_recognition_SRCS src/myVoce/*.cpp src/qt/*.cpp)
#list(REMOVE_ITEM voice_recognition_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )
file(GLOB voice_recognition_HDRS include/qt/*.h)
file(GLOB voice_recognition_UIS resources/*.ui)
file(GLOB voice_recognition_QRSCS resources/qrc/*.qrc)

qt5_add_resources(voice_recognition_VFS ${voice_recognition_QRSCS}) #VFS = Virtual File System
qt5_wrap_cpp(voice_recognition_MOCS ${voice_recognition_HDRS}) #makes meta objects compile file
qt5_wrap_ui(voice_recognition_UI_HDRS ${voice_recognition_UIS} )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(${Qt5Widgets_DEFINITIONS}
                ${catkin_DEFINITIONS} )

add_library(_voice_recognition
            ${voice_recognition_SRCS}
            ${voice_recognition_MOCS}
            ${voice_recognition_UI_HDRS}
            ${voice_recognition_VFS} )

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
                        _voice_recognition
                        Qt5::Widgets
                        ${catkin_LIBRARIES}

/usr/lib/jvm/java-8-openjdk-amd64/jre/lib/amd64/server/libjvm.so

 )
