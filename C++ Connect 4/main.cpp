#include <bits/stdc++.h>
#include "Game.h"

using namespace std;

int main()
{
    Game *game = new Game();
    
    game->start();

    cout << game->getMoves() << endl;
    delete game;
    return 0;
}
