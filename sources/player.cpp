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

    Card Player::getTopCard(){
        if (gameCards.empty()) {
            // handle the case where the queue is empty
            throw std::runtime_error("The gameCards queue is empty");
         }
        return gameCards.front();
    } 
    std::queue<Card> Player::getVictoriesQueue(){
        return victoriesQueue;
    }
    std::queue<Card> Player::getGameCards(){
        return gameCards;
    }
    void Player::setGameCards(Card card)
    {
        gameCards.push(card);
    }
    void Player::setVictoriesQueue(Card card){
        victoriesQueue.push(card);
    }
    
    

}