#ifndef Game_hpp
#define Game_hpp

#include "player.hpp"
#include <vector>
#include <string>

class Game {
public:
    Game(Player& p1, Player& p2);
    Player& getP1();
    Player& getP2();
    void playTurn();
    void playAll();
    Player* getWinner() const;
    std::vector<std::string> getLog() const;
private:
    Player& m_p1;
    Player& m_p2;
    std::vector<std::string> m_log;
};

#endif 