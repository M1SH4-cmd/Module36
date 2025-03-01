cmake_minimum_required(VERSION 3.25)
project(Note3)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES main.cpp)

add_executable(Note3 ${SOURCES})

target_link_libraries(Note3 PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)