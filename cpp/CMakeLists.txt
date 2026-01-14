cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0.0)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Опции компилятора
add_compile_options(-Wall -Wextra -pedantic -g)

# Добавление исполняемого файла
add_executable(${PROJECT_NAME}
    1бл/main.cpp
    2бл/main.cpp
    3бл/main.cpp
    4бл/main.cpp
    5бл/main.cpp
    6бл/main.cpp
    7бл/main.cpp
    7бл/matrix.cpp
)

# Подключение заголовков
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Настройка для VS Code
if(CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()