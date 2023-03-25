#include "player.hpp"
#include "game.hpp"
#include "card.hpp"

namespace ariel {
    // Constructor
    Player::Player(std::string name) : m_name(name), m_cardCount(0) {}

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
        return "";
    }

    std::string getTopCard(){

        return "";
    }
    

}