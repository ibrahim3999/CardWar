#ifndef Player_hpp
#define Player_hpp
#include <string>
#include "card.hpp"


namespace ariel {
    class Player {
public:
    Player(std::string name);
    int getCardCount();
    int  stacksize();
    int  cardesTaken();
    std::string getTopCard();
    std::string getName();
private:
    std::string m_name;
    int m_cardCount;
    std::string topCard;
    };
}
#endif 