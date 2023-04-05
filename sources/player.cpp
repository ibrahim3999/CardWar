#include "player.hpp"
#include <iostream>
#include "game.hpp"
#include "card.hpp"
#include<stack>

using namespace std;

namespace ariel {
    // Constructor
    Player::Player(std::string name) : m_name(name),victoriesNum(0),cardsLeftCount(0){}


    // Additional methods
    int Player::stacksize() {
        return cardsLeftCount;   
    }

    int Player::cardesTaken() {
        return victoriesNum;
        
    }
    void  Player::setStackSize(int size){
        cardsLeftCount=size;
    }
    std::string Player::getName(){
        return this->m_name;
    }
    
   Card Player::getTopCard(){
        if (gameCards.empty()) {
            throw std::out_of_range("No cards left in gameCards stack");
        }
        Card card = gameCards.top();
        gameCards.pop();
        cardsLeftCount--;
        return card;
    
   
}

    std::stack<Card>& Player::getGameCards(){
        return gameCards;
    }

    void Player::setGameCards(Card  card){
        gameCards.push(card);
    }

    int  Player::getVictoriesNum(){
        return victoriesNum;
    }

    void Player::setVictoriesNum(int i){
        victoriesNum+=i;
    }   

}