#ifndef Game_hpp
#define Game_hpp
#include "player.hpp"
#include <vector>
#include <string>

namespace ariel {

class Game {

public:
    Game(Player& player1, Player& player2);
    void playTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    void printLastTurn();
    
};
}
#endif 