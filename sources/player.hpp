#ifndef Player_hpp
#define Player_hpp
#include <string>
#include <queue>
#include <stack>
#include "card.hpp"

namespace ariel {
    class Player {
public:
    Player(std::string name);
    ~Player();
    int getCardCount();
    int  stacksize();
    int  cardesTaken();
    ariel::Card getTopCard();
    std::string getName();
    std::queue<Card> getVictoriesQueue();
    std::queue<Card> getGameCards();
    void setGameCards(Card card);
    void setVictoriesQueue(Card carrd);
private:
    std::string m_name;
    int m_cardCount;
    std::string topCard;
    std::queue<Card> victoriesQueue;
    std::queue<Card> gameCards;
    };
}
#endif 