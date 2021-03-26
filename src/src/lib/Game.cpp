#include "lib/Game.hpp"

Game::Game()
{
}

void Game::startGame()
{
    this->round = 1;
}

void Game::quitGame()
{
}

void Game::advanceRound()
{
    this->round++;
    // TODO : Kalau turn mod sesuatu == 0, wild engimon gerak
}

string Game::askCommand()
{
    vector<string> availableCommand = {"w", "a", "s", "d", "battle", "interact", "learn", "cut"};

    while (true)
    {
        string command;
        cout << "Masukkan command: ";
        cin >> command;
        for (string com : availableCommand)
        {
            if (com == command)
            {
                return command;
            }
        }
        cout << "Command lu salah cuk ...." << endl;
    }
}

void Game::processCommand(string command)
{
    if (command == "w" || command == "a" || command == "s" || command == "d")
    {
        movePlayer(command);
        return;
    }

    // switch (command)
    // {
    // case "battle":
    //     battle();
    //     return;
    // case "interact":
    //     interact();
    //     return;
    // case "learn":
    //     learn();
    //     return;
    // case "cut":
    //     cut();
    //     return;
    // }
}

void Game::movePlayer(string command)
{
    // switch (command)
    // {
    // case "w":
    //     gameMap.movePlayer(Direction::NORTH);
    //     break;
    // case "a":
    //     gameMap.movePlayer(Direction::WEST);
    //     break;
    // case "s":
    //     gameMap.movePlayer(Direction::SOUTH);
    //     break;
    // case "d":
    //     gameMap.movePlayer(Direction::EAST);
    //     break;
    // default:
    //     cout << "Invalid Move Command" << endl;
    // }
}

void Game::battle()
{
    pair<int, int> playerLocation = gameMap.getPlayerLocation();
    map<pair<int, int>, Engimon> surroundingEngimon = gameMap.getSurroundingEngimon(playerLocation.first, playerLocation.second);
    if (surroundingEngimon.empty()) // Gak ada yang bisa dibattle
    {
        cout << "No surrounding Engimon to battle" << endl;
        return;
    }
}

void Game::interact()
{
    this->gameMap.getPlayer().getActiveEngimon().sendMessage();
    //harusnya yg baris di atas dh bener
    //Udah
}

void Game::learn()
{
    //blom ada skillnya
}

void Game::cut()
{
    //elemen air, bs water cutter :V, HEM subur pohonnya nanti, industrial water cutter sadis woy wwkwk, limbah pump
}