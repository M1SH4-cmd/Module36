cmake_minimum_required(VERSION 3.20)
project(Task1)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake") #Для Windows


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(SOURCES main.cpp)

add_executable(Task1 ${SOURCES})

target_link_libraries(Task1 PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)