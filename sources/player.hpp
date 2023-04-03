#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "card.hpp"
#include<string>
#include<stack>



using namespace std;


namespace ariel {
    class Player {
        public:
            Player(std::string name);
            ~Player();
            int getCardCount();
            int  stacksize();
            int  cardesTaken();
            Card getTopCard();
            std::string getName();
            std::stack<Card> getGameCards();
            void setGameCards(Card card);
            int  getVictoriesNum();
            void setVictoriesNum(int i);
        private:
            std::string m_name;
            int m_cardCount;
            std::string topCard;
            int victoriesNum;
            std::stack<Card> gameCards;
    };
}
#endif 