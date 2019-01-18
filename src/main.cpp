// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "Game/Game.hpp"
#include "Engine/Utils/Exceptions/GameLoadResourcesException.hpp"
#include "Engine/Utils/Exceptions/GameRuntimeException.hpp"
int main()
{
    std::unique_ptr<LogManager> logManager = std::make_unique<LogManager>("Main");
    std::unique_ptr<Game> game = std::make_unique<Game>("Bizarre Tale");

    try
    {
        game->prepare();
        game->run();
    } catch (const GameLoadResourcesException &ex)
    {
        logManager->logging(ProjectorMessage(ex.what(), ProjectorMessage::Type::ERROR));
    } catch (const GameRuntimeException &ex)
    {
        logManager->logging(ProjectorMessage("this exception not realise", ProjectorMessage::Type::WARNING));
    }

    game->exitProcess();
    logManager->showLog();
    return 0;
}