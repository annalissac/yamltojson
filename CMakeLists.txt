cmake_minimum_required(VERSION 2.8.9)
project(yamltojson)
 
include_directories(include)
include_directories(src/ytj)
 
file(GLOB_RECURSE SOURCES_LAB ${PROJECT_SOURCE_DIR}/src/ytj/*.cpp)
file(GLOB_RECURSE SOURCES_TEST ${PROJECT_SOURCE_DIR}/src/test/*.cpp)
file(GLOB_RECURSE SOURCES_MAIN_SERVER ${PROJECT_SOURCE_DIR}/src/mains/yamltojson.cpp)
file(GLOB_RECURSE SOURCES_MAIN_CATCHTEST ${PROJECT_SOURCE_DIR}/src/mains/catch_main.cpp)

message(STATUS ${SOURCES})
 
add_executable(yamltojson ${SOURCES_LAB} ${SOURCES_MAIN_SERVER})
add_executable(ytjtest ${SOURCES_LAB} ${SOURCES_MAIN_CATCHTEST} ${SOURCES_TEST})
TARGET_LINK_LIBRARIES(yamltojson yaml-cpp)
TARGET_LINK_LIBRARIES(ytjtest yaml-cpp)
