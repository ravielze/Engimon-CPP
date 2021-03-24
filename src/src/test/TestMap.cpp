#include "lib/Map.hpp"

int main()
{
    Map m;
    Player p;
    m.show();
    m.movePlayer(Direction::EAST);
}