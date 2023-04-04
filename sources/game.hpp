#ifndef Game_hpp
#define Game_hpp
#include "player.hpp"
#include "card.hpp"
#include <string>
#include <vector>

namespace ariel {

class Game {

public:
    Game(Player& player1, Player& player2);
    ~Game();
    void playTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    void printLastTurn();
    int getCurrentRound();
    std::string getWinner();
    void initializeCards();
    void randomDistribution();
    //  Player getPlayer1();
    //  Player getPlayer2();

private: 
    std::string winner;
    std::string lastTrun;
    std::string gameLog;
    std::vector<Card> initialCards;
    Player &player1;
    Player &player2;
    std::vector<Card> Cards;// Cards of the current game;
    
};
}
#endif 