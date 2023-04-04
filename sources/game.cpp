#include <iostream>
#include <vector>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include<random>
# define CARDS_NUM 52
# define PLAYER_NUM 2
# define WAR_TRUN_NUM 3
using namespace std;

namespace ariel {
   
Game::Game(Player& player1, Player& player2): player1(player1), player2(player2){
    // Constructor 
    try {
        randomDistribution();
    }
    catch(const std::exception& e) {
        std::cerr << "Error during random card distribution: " << e.what() << '\n';
    }
    player1.setStackSize(CARDS_NUM/PLAYER_NUM);
    player2.setStackSize(CARDS_NUM/PLAYER_NUM);   
}
Game::~Game(){
   // delete player1;
   // delete player2;
}

void Game::playTurn() {
    if(player1.stacksize()==0 || player2.stacksize()==0){
            throw std::runtime_error("GAME OVER !!!");
    }
    else if (player1.stacksize() == 0) {
        throw std::runtime_error(player1.getName() + " DONT HAVE CARDS!!!");
    } 
    else if (player2.stacksize() == 0) {
        throw std::runtime_error(player2.getName() + " DONT HAVE CARDS!!!");
    } 
    else if (&player1 == &player2) {
        throw std::runtime_error("Both players are the same!");
    }

    try {
        // playing a single turn of the game
        Card player1Card=player1.getTopCard();
        Card player2Card=player2.getTopCard();
        if(player1Card.getRank()>player2Card.getRank()){
            //player 1 wins the trun
            player1.setVictoriesNum(2);

            lastTrun= player1.getName() + " played " + player1Card.toString() + ". ";
            lastTrun += player2.getName() + " played " + player2Card.toString() + ". ";
            lastTrun += player1.getName() + " wins.";
        }
        else if(player1Card.getRank()<player2Card.getRank()){
            //player 2 wins the trun

            player2.setVictoriesNum(2);

            lastTrun=player2.getName()+" played "+player2Card.toString()+" ";
            lastTrun+=player1.getName()+" played "+player1Card.toString()+". ";
            lastTrun+=player2.getName()+" wins";
        } 
        else if(player1Card.getRank()==player2Card.getRank()){
            // War turns
            int WarNum=1;
            cout << "A NEW WAR !!"<<std::endl;
            for(int i=0;i<WAR_TRUN_NUM+1;i++)
            {
                player1Card=player1.getTopCard();
                player2Card=player2.getTopCard();
                if(i==3 && player1Card.getRank()==player2Card.getRank()){
                    i=0;//WAR AGAIN !!!  
                    WarNum++;
                    cout << "A NEW WAR !!"<<std::endl;
                }
            }
            if(player1Card.getRank()>player2Card.getRank()){
                //player 1 wins the turn
                player1.setVictoriesNum(10*WarNum);
                cout<<player1.getName() +" WIN THIS WAR "<<std::endl;
                lastTrun= player1.getName() + " played " + player1Card.toString() + ". ";
                lastTrun += player2.getName() + " played " + player2Card.toString() + ". ";
                lastTrun += player1.getName() + " wins.";
            }
            else if(player1Card.getRank()<player2Card.getRank()){
                //player 2 wins the turn
                cout<<player2.getName() +" WIN THIS WAR "<<std::endl;
                player2.setVictoriesNum(10*WarNum); 

                lastTrun=player2.getName()+" played "+player2Card.toString()+" ";
                lastTrun+=player1.getName()+" played "+player1Card.toString()+". ";
                lastTrun+=player2.getName()+" wins";
            } 
        }
    }
    catch(const std::exception& e) {
        std::cerr << "Exception caught during game play: " << e.what() << std::endl;
    }
}
 


void Game::playAll() {
    // playing the entire game
    try {
        while (player1.getGameCards().size() != 0 || player2.getGameCards().size() != 0) {
            playTurn();
            gameLog += lastTrun + "\n";
        }

        if (player1.getVictoriesNum() > player2.getVictoriesNum()) {
            winner = player1.getName();
        } else if (player1.getVictoriesNum() < player2.getVictoriesNum()) {
            winner = player2.getName();
        } else {
            winner = " Draw ";
        }
        player1.setVictoriesNum(0);
        player2.setVictoriesNum(0);
    }
    catch (std::exception& e) {
        throw std::runtime_error("An error occurred during the game: " + std::string(e.what()));
    }
}

void Game::printStats() {
    // printing statistics about the game
    try {
        std::cout << "Player 1 name: " << player1.getName() << std::endl;
        std::cout << "Player 1 victories: " << player1.getVictoriesNum() << std::endl;
        std::cout << "Player 1 cards remaining: " << player1.getGameCards().size() << std::endl;

        std::cout << "Player 2 name: " << player2.getName() << std::endl;
        std::cout << "Player 2 victories: " << player2.getVictoriesNum() << std::endl;
        std::cout << "Player 2 cards remaining: " << player2.getGameCards().size() << std::endl;
    }
    catch (std::exception& e) {
        throw std::runtime_error("An error occurred while printing game statistics: " + std::string(e.what()));
    }
}

void Game::printLastTurn() {
    // printing the last turn of the game
    try {
        std::cout << lastTrun << std::endl;
    }
    catch (std::exception& e) {
        throw std::runtime_error("An error occurred while printing the last turn of the game: " + std::string(e.what()));
    }
}

void Game::printWiner() {
    // printing the winner of the game
    try {
        std::cout << "The WINNER is: " + winner << std::endl;
    }
    catch (std::exception& e) {
        throw std::runtime_error("An error occurred while printing the winner of the game: " + std::string(e.what()));
    }
}

void Game::printLog() {
    // printing the game log
    try {
        std::cout << gameLog;
    }
    catch (std::exception& e) {
        throw std::runtime_error("An error occurred while printing the game log: " + std::string(e.what()));
    }
}
std::string Game::getWinner(){
    return winner;
 }
void Game::initializeCards() {

    // Initialize the deck of cards
    for (int suit = static_cast<int>(Card::Suit::CLUBS); suit <= static_cast<int>(Card::Suit::SPADES); suit++) {
        for (int rank = static_cast<int>(Card::Rank::TWO); rank <= static_cast<int>(Card::Rank::ACE); rank++) {
            Card card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
            Cards.push_back(card);
            initialCards.push_back(card);
        }
    }
}

void Game::randomDistribution() {
    try {
        // Initialize 
        initializeCards();

        // Distribute cards among the players
        std::random_device rd;
        std::mt19937 gen(rd());
        for (int i = 0; i < PLAYER_NUM; i++) {
            Player& currentPlayer = (i == 0) ? player1 : player2; // get reference to current player
            for (int j = 0; j < CARDS_NUM / PLAYER_NUM; j++) { // distribute equal number of cards to each player
                if (initialCards.empty()) {
                    throw std::runtime_error("Not enough cards in the deck to distribute equally among the players");
                }
                std::uniform_int_distribution<std::vector<Card>::size_type> dist(0, initialCards.size() - 1); // create distribution
                std::vector<Card>::size_type randomIndex = dist(gen);
                Card card = initialCards[randomIndex];
                currentPlayer.setGameCards(card); // add card to player's hand
                initialCards.erase(std::next(initialCards.begin(), static_cast<long>(randomIndex))); // remove card from deck
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
void Game::reset()
{
   /**std::string winner;
    std::string lastTrun;
    std::string gameLog;
    std::vector<Card> initialCards;
    Player &player1;
    Player &player2;
    std::vector<Card> Cards;// Cards of the current game;*/ 
    winner="";
    lastTrun="";
    gameLog="";
    player1.setStackSize(0);
    player2.setStackSize(0);
    player1.setVictoriesNum(0);
    player2.setVictoriesNum(0);
    randomDistribution();
    player1.setStackSize(CARDS_NUM/PLAYER_NUM);
    player2.setStackSize(CARDS_NUM/PLAYER_NUM);

}
};