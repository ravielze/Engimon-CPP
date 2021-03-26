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
    else if (command == "battle")
    {
        battle();
    }
    else if (command == "interact")
    {
        interact();
    }
    else if (command == "learn")
    {
        learn();
    }
    else if (command == "swap")
    {
        swap();
    }
    else if (command == "cut")
    {
        cut();
    }
    else if (command == "breed")
    {
        breed();
    }
    else
    {
        cout << "Command lu salah cuk ...." << endl;
    }
}

void Game::movePlayer(string command)
{
    if (command == "w")
    {
        gameMap.movePlayer(Direction::NORTH);
    }
    else if (command == "a")
    {
        gameMap.movePlayer(Direction::WEST);
    }
    else if (command == "s")
    {
        gameMap.movePlayer(Direction::SOUTH);
    }
    else if (command == "d")
    {
        gameMap.movePlayer(Direction::EAST);
    }
    else
    {
        cout << "Invalid Move Command" << endl;
    }
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
    cout << "Choose engimon to battle : " << endl;
    int index = 1;
    for (auto itr = surroundingEngimon.begin(); itr != surroundingEngimon.end(); itr++)
    {
        cout << index << "\t";
        itr->second.show();
        index++;
    }
    cin >> index;
    pair<int, int> choosenEngimonLocation;
    Engimon choosenEngimon;
    auto itr = surroundingEngimon.begin();
    advance(itr, index - 1);
    choosenEngimonLocation = itr->first;
    choosenEngimon = itr->second;
    bool isWinning = this->gameMap.getPlayer().battle(choosenEngimon);
    if (isWinning)
    {
        // TODO: Hilangkan engimon dari map
    }
}

void Game::interact()
{
    this->gameMap.getPlayer().interact();
}

void Game::learn()
{
}

void Game::swap()
{
    this->gameMap.getPlayer().switchActiveEngimon();
}

void Game::cut()
{
}
