#include "lib/Map.hpp"

int main()
{
    srand(time(NULL) % getpid());
    Map m;
    m.show();
    //m.movePlayer(Direction::EAST);
}