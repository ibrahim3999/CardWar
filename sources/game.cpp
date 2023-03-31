#include <iostream>
#include <vector>
#include "game.hpp"
#include "card.hpp"
#include<random>
# define CARDS_NUM 52
# define PLAYER_NUM 2
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
    Card player1Card=player1.getTopCard();
    Card player2Card=player2.getTopCard();
    cout << "player 1:"+player1Card.toString() << std::endl;
    cout << "player 2:"+ player2Card.toString() << std::endl;
    if(player1Card.getRank()>player2Card.getRank()){
        //player 1 wins the trun
        player1.setVictoriesQueue(player1Card);
        player1.setVictoriesQueue(player2Card);
        cout << "player1 is win "<< std::endl;
    }
    else if(player1Card.getRank()<player2Card.getRank()){
        //player 2 wins the trun
        player2.setVictoriesQueue(player1Card);
        player2.setVictoriesQueue(player2Card);
        cout << "player2 is win "<< std::endl;
    }   
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
            Cards.insert(Cards.begin(),Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank))); 
        }
    }
}
void Game::randomDistribution() {
    // Distribute cards among the players
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < PLAYER_NUM; i++) {
        Player& currentPlayer = (i == 0) ? player1 : player2; // get reference to current player
        for (int j = 0; j < CARDS_NUM / PLAYER_NUM; j++) { // distribute equal number of cards to each player
            std::uniform_int_distribution<std::vector<Card>::size_type> dist(0, Cards.size() - 1); // create distribution
            std::vector<Card>::size_type randomIndex = dist(gen);
            currentPlayer.setGameCards(Cards[randomIndex]); // add card to player's hand
            Cards.erase(std::next(Cards.begin(), static_cast<long>(randomIndex))); // remove card from deck
           // cout<< "player 1:"<<player1.getTopCard().toString() <<std::endl;
           // cout<< "player 2:"<<player2.getTopCard().toString()<<std::endl;
        }
    }
}
};