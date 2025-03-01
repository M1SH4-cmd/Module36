cmake_minimum_required(VERSION 3.20)
project(Note1)

# Укажи путь к Qt
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")  # Для Windows

# Найди Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Включи автоматическую работу с MOC, UIC и RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Добавь исходные файлы
set(SOURCES main.cpp)

# Создай исполняемый файл
add_executable(Note1 ${SOURCES})

# Подключи Qt к проекту
target_link_libraries(Note1 PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)