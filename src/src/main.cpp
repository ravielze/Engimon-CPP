#include "lib/Game.hpp"

int main()
{
    srand(time(NULL) % getpid());
    Game g;
    g.startGame();
}