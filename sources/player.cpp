#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include<stack>

using namespace std;

namespace ariel {
    // Constructor
    Player::Player(std::string name) : m_name(name), m_cardCount(0),victoriesNum(0) {}

    // Destructor
    Player::~Player(){
       // delete[] m_name;
       // delete m_cardCount;
    }

    // Getter method 
    int Player::getCardCount()  {
        return 0;
    }

    // Additional methods
    int Player::stacksize() {
        return 0;
      
    }

    int Player::cardesTaken() {
        return 0;
        
    }
    std::string Player::getName(){
        return this->m_name;
    }
    
    Card Player::getTopCard(){
        Card card=gameCards.top();
        gameCards.pop();
        return card;
    }
    std::stack<Card> Player::getGameCards(){
        return gameCards;
    }

    void Player::setGameCards(Card card){
        gameCards.push(card);
    }
    int  Player::getVictoriesNum(){
        return victoriesNum;
    }
    void Player::setVictoriesNum(int i){
        victoriesNum+=i;
    }
    
    

}