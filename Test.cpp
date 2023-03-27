#include "doctest.h"
#include <sstream>
#include <stdexcept>

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;


TEST_CASE(" Testing Game Class") {
  
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);

    SUBCASE("Test getCurrentRound"){    
        CHECK_EQ(game.getCurrentRound(), 0);
    }

    SUBCASE("Test playTrun()"){
        game.playTurn();
        CHECK_EQ(game.getCurrentRound(), 1);
        game.playTurn();
        game.playTurn();
        CHECK_EQ(game.getCurrentRound(), 3);
        game.playTurn();
        CHECK_EQ(game.getCurrentRound(), 4);

    }

    SUBCASE("Test printWiner()"){
        game.playAll();
        CHECK_NOTHROW(game.printWiner());
    }

    SUBCASE("Test printLog()"){
        game.playAll();
        CHECK_NOTHROW(game.printLog());
    }

    SUBCASE("Test printStats()"){
        game.playAll();
        CHECK_NOTHROW(game.printStats());
    }

    SUBCASE("Test printLastTurn()"){
        game.playAll();
        CHECK_NOTHROW(game.printLastTurn());
    }
    SUBCASE("Test playing the entire game") {
        game.playAll();
        std::string winner;
        if(p1.stacksize()==52 && p2.stacksize()==0)
        {
            winner=p1.getName();
            CHECK_EQ(game.getWinner(),winner);
        }
        else{
            winner=p2.getName();
            CHECK_EQ(game.getWinner(),winner);
        }
    }
}

TEST_CASE("Testing Player class")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
   
    SUBCASE("Testing getName()"){
        CHECK_EQ(p1.getName(), "Alice");
        CHECK_EQ(p2.getName(), "Bob");
    }

    SUBCASE("Testing getCardCount()"){
        CHECK_EQ(p1.getCardCount(), 0);
        CHECK_EQ(p2.getCardCount(), 0);
        game.playAll();
        if(game.getWinner()==p1.getName()){
            CHECK_EQ(p1.getCardCount(), 52);
            CHECK_EQ(p2.getCardCount(), 0);
        }
        else{
            CHECK_EQ(p2.getCardCount(), 52);
            CHECK_EQ(p1.getCardCount(), 0);
        }
   
    }

    SUBCASE("Testing stacksize()"){
        CHECK_EQ(p1.stacksize(), 0);
        CHECK_EQ(p2.stacksize(), 0);
        for(int i=0;i<5;i++)
        {
            game.playTurn();
        }
        CHECK_EQ(p1.stacksize(), 21);


    }
    SUBCASE("Testing cardesTaken()"){
        CHECK_EQ(p1.cardesTaken(), 0);
        CHECK_EQ(p2.cardesTaken(), 0);
    }
 
}


    

/*
    SUBCASE("Test playing a turn") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);

        // Alice plays a higher card than Bob's
        game.playTurn();
        std::stringstream expected_last_turn;
        expected_last_turn << "Alice played " << game.getPlayer1().getTopCard() <<
            " Bob played " << game.getPlayer2().getTopCard() << ". Alice wins.";
        CHECK_EQ(game.getLastTurnStats(), expected_last_turn.str());

        // Bob plays a higher card than Alice's
        game.playTurn();
        expected_last_turn.str("");
        expected_last_turn << "Alice played " << game.getPlayer1().getTopCard() <<
            " Bob played " << game.getPlayer2().getTopCard() << ". Bob wins.";
        CHECK_EQ(game.getLastTurnStats(), expected_last_turn.str());

        // Both players play the same card
        game.playTurn();
        expected_last_turn.str("");
        expected_last_turn << "Alice played " << game.getPlayer1().getTopCard() <<
            " Bob played " << game.getPlayer2().getTopCard() << ". Draw.";
        CHECK_EQ(game.getLastTurnStats(), expected_last_turn.str());
    }
   
    SUBCASE("Test playing the entire game") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        game.playAll();

        CHECK(game.getWinner() == p1 || game.getWinner() == p2);
        CHECK_EQ(game.getPlayer1().stacksize() + game.getPlayer2().stacksize(), 52);
    }
 */    