#include <iostream>
#include <vector>
#include "game.hpp"
using namespace std;

namespace ariel {

Game::Game(Player& player1, Player& player2){
    // Constructor 
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
};