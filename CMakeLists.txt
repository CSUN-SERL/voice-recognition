
cmake_minimum_required(VERSION 2.8.12)

project(voice_recognition)

set( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake_Modules;${CMAKE_MODULE_PATH}")

find_package(catkin REQUIRED COMPONENTS
                        roscpp
                        roslib
)

find_package(jvm REQUIRED)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(voice_recognition_INCLUDE_DIRS
        src
        include
        resources
        nodes
)

include_directories(${voice_recognition_INCLUDE_DIRS}
                    ${catkin_INCLUDE_DIRS}
                    ${JVM_INCLUDE_DIRS} )

catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS roscpp roslib
     )


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions( ${catkin_DEFINITIONS} )


add_executable( ${PROJECT_NAME}_node 
                nodes/voice_recognition_node.cpp
                src/VoiceRecognition.cpp
                include/voice_recognition/VoiceRecognition.h)


add_dependencies(${PROJECT_NAME}_node ${catkin_EXPORTED_TARGETS})


target_link_libraries(${PROJECT_NAME}_node
                        ${catkin_LIBRARIES}
                        ${JVM_LIBRARY})

