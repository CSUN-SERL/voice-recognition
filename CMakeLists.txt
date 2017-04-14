
cmake_minimum_required(VERSION 2.8.12)

project(voice_recognition)

find_package(Qt5Widgets REQUIRED)
find_package(catkin REQUIRED COMPONENTS
                        roscpp
                        roslib
                        eigen_conversions
                        image_transport
                        cv_bridge
                        lcar_msgs
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(voice_recognition_INCLUDE_DIRS
        src
        include
        resources
        nodes
	/usr/lib/jvm/java-6-openjdk-amd64/include
	/usr/lib/jvm/java-6-openjdk-amd64/include/linux
)

include_directories(${voice_recognition_INCLUDE_DIRS}
                    ${catkin_INCLUDE_DIRS} )

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS roscpp roslib lcar_msgs
     )

file(GLOB voice_recognition_SRCS src/*.cpp)
list(REMOVE_ITEM voice_recognition_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/qt/UAVAdapter.cpp )
file(GLOB voice_recognition_HDRS include/voice-recognition/*.h)


qt5_wrap_cpp(voice_recognition_MOCS ${voice_recognition_HDRS}) #makes meta objects compile file


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
add_definitions(${Qt5Widgets_DEFINITIONS}
                ${catkin_DEFINITIONS} )

add_library(${PROJECT_NAME}
            ${voice_recognition_SRCS}
            ${voice_recognition_MOCS}
            ${voice_recognition_HDRS}
            )


add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}
                        Qt5::Widgets
                        ${catkin_LIBRARIES}
/usr/lib/jvm/java-6-openjdk-amd64/jre/lib/amd64/server/libjvm.so )
