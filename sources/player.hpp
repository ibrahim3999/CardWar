#ifndef Player_hpp
#define Player_hpp
#include <string>
#include<queue>
#include "card.hpp"

namespace ariel {
    class Player {
public:
    Player(std::string name);
    ~Player();
    int getCardCount();
    int  stacksize();
    int  cardesTaken();
    std::string getTopCard();
    std::string getName();
    std::queue<Card> getVictoriesQueue();
private:
    std::string m_name;
    int m_cardCount;
    std::string topCard;
    std::queue<Card> victoriesQueue;
    };
}
#endif 