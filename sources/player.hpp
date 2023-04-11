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
            int  stacksize();
            void  setStackSize(int size);
            int  cardesTaken();
            Card getTopCard();
            std::string getName();
            std::stack<Card>& getGameCards();
            void setGameCards(Card card);
            int  getVictoriesNum();
            void setVictoriesNum(int i);
            int  getWinsNum(); 
            int getLossNum();
            int getDrawNum();
            void  setWinsNum(); 
            void setLossNum();
            void setDrawNum();
            void resetVictoriesNum();
        private:
        /*
        player1.getWinsNum() + player1.getLossNum()+ player1.getDrawNum();
        */
            int winNum;
            int lossNum;
            int drawNum;
            std::string m_name;
            int cardsLeftCount;
            std::string topCard;
            int victoriesNum;
            std::stack<Card> gameCards;
    };
}
#endif 