cmake_minimum_required(VERSION 3.13)
project(Projector)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# ToDo: add detecting OS
# ToDo: add settings for Windows

add_executable(Projector
        src/main.cpp
        src/Game/Game.cpp
        src/Game/Game.hpp
        src/Engine/Utils/ProjectorMessage.cpp
        src/Engine/Utils/ProjectorMessage.hpp
        src/Engine/Utils/Logger/LogManager.cpp
        src/Engine/Utils/Logger/LogManager.hpp
        src/Engine/Utils/getClassName.hpp
        src/Engine/Utils/Exceptions/GameLoadException.cpp
        src/Engine/Utils/Exceptions/GameLoadException.hpp
        src/Engine/Utils/Exceptions/GameRuntimeException.cpp
        src/Engine/Utils/Exceptions/GameRuntimeException.hpp
        src/Engine/Utils/GameSettings.cpp
        src/Engine/Utils/GameSettings.hpp
        src/Engine/Utils/CONST_DEFINITIONS.hpp
        src/Engine/Utils/Ini/INIReader.cpp
        src/Engine/Utils/Ini/INIReader.hpp
        src/Engine/Utils/Ini/ini.hpp
        src/Engine/Utils/Ini/ini.cpp src/Engine/Level/Level.cpp src/Engine/Level/Level.hpp src/Engine/Level/LevelManager.cpp src/Engine/Level/LevelManager.hpp src/Engine/Utils/Exceptions/LevelException.cpp src/Engine/Utils/Exceptions/LevelException.hpp src/Game/TestLevel.cpp src/Game/TestLevel.hpp)

target_link_libraries(Projector -lsfml-graphics -lsfml-window -lsfml-system)