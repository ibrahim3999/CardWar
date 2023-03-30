#include <iostream>
#include <vector>
#include "game.hpp"
#include "card.hpp"
using namespace std;

namespace ariel {
//Card cards
   
Game::Game(Player& player1, Player& player2): player1(player1), player2(player2){
    // Constructor 
}
Game::~Game(){
   // delete player1;
   // delete player2;
}

void Game::playTurn() {
    //  playing a single turn of the game
}

void Game::playAll() {
    //  playing the entire game
}

void Game::printWiner() {
    //  printing the winner of the game
}

void Game::printLog() {
    //  printing the game log
}

void Game::printStats() {
    //  printing statistics about the game
}

void Game::printLastTurn() {
    //  printing the last turn of the game
}
int Game::getCurrentRound(){
    //  return Current Round
    return 0;

}
std::string Game::getWinner(){
    return "";
 }

void Game::createCards() {
    // creat all cards game
    for (int suit = static_cast<int>(Card::Suit::CLUBS); suit <= static_cast<int>(Card::Suit::SPADES); suit++) {
        for (int rank = static_cast<int>(Card::Rank::TWO); rank <= static_cast<int>(Card::Rank::ACE); rank++) {
            Cards.push(Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)));
            
        }
    }
}
};