#include "player.hpp"
#include "game.hpp"

namespace ariel {
    // Constructor
    Player::Player(std::string name) : m_name(name), m_cardCount(0) {}

    // Getter method for m_cardCount
    int Player::getCardCount() const {
        return 0;
    }

    // Additional methods
    int Player::stacksize() {
        return 0;
      
    }

    int Player::cardesTaken() {
        return 0;
        
    }
}