// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifdef __linux__
    #define OS "LINUX"
#elif __WIN32__
    #ifdef __WIN64__
            #define OS "WIN64"
        #else
            #define OS "WIN32"
        #endif
    #else
        #define OS "UNSUPPORTED OS"
#endif

#include <iostream>
#include <sys/stat.h>
#include "Game/Game.hpp"
#include "Engine/Utils/Exceptions/GameLoadResourcesException.hpp"
#include "Engine/Utils/Exceptions/GameRuntimeException.hpp"

void prepare();

int main()
{
    prepare();
    auto logManager = std::make_unique<LogManager>("Main");
    LogManager::fileName = "";
    auto game = std::make_unique<Game>("Bizarre Tale");

    try
    {
        game->prepare();
        game->run();
    } catch (const GameLoadResourcesException &ex)
    {
        logManager->logging(ProjectorMessage(ex, ProjectorMessage::Type::ERROR));
    } catch (const GameRuntimeException &ex)
    {
        logManager->logging(ProjectorMessage("this exception not realise", ProjectorMessage::Type::WARNING));
    }

    game->exitProcess();
    logManager->showLog();
    return 0;
}

void prepare()
{
    if (OS == "LINUX")
    {
        auto now = std::chrono::system_clock::now();
        auto tt = std::chrono::system_clock::to_time_t(now);
        std::string t1 = ctime(&tt);
        std::replace(t1.begin(), t1.end(), ' ', '_');
        std::string filesPath = "Log/";

        const int dirErr = mkdir("Log", S_IRWXU | S_IRWXG | S_IROTH | S_IWOTH);
        if (!dirErr)
        {
            std::cout << "Log folder is created" << std::endl;
        }
    } else if (OS == "WIN32" || OS == "WIN64")
    {
        std::cout << "ToDo: add method for create folder on WIN OS" << std::endl;
    }
}