cmake_minimum_required(VERSION 3.13)
project(Projector)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# ToDo: add settings for Windows

add_executable(Projector
        src/main.cpp
        src/Game/Game.cpp
        src/Engine/Utils/ProjectorMessage.cpp
        src/Engine/Utils/Logger/LogManager.cpp
        src/Engine/Utils/Exceptions/GameLoadResourcesException.cpp
        src/Engine/Utils/Exceptions/GameRuntimeException.cpp
        src/Engine/Utils/GameSettings.cpp
        src/Engine/Utils/Ini/INIReader.cpp
        src/Engine/Utils/Ini/ini.cpp
        src/Engine/Level/Level.cpp
        src/Engine/Level/LevelManager.cpp
        src/Engine/Utils/Exceptions/LevelException.cpp
        src/Game/TestLevel.cpp
        src/Engine/Entity/Entity.cpp
        src/Engine/Entity/DrawableEntity.cpp
        src/Game/Daedalus.cpp
        )

target_link_libraries(Projector -lsfml-graphics -lsfml-window -lsfml-system -ltgui)