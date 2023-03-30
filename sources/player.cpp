#include "player.hpp"
#include "game.hpp"
#include "card.hpp"

namespace ariel {
    // Constructor
    Player::Player(std::string name) : m_name(name), m_cardCount(0) {}

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

    std::string Player::getTopCard(){

        return "";
    }
    std::queue<Card> Player::getVictoriesQueue(){
        return victoriesQueue;
    }

    

}