#include "doctest.h"
#include <sstream>
#include <stdexcept>

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;


TEST_CASE("Card game tests") {
    SUBCASE("Test game initialization") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);

        CHECK_EQ(game.getCurrentRound(), 0);
        CHECK_EQ(game.getPlayer1().getName(), "Alice");
        CHECK_EQ(game.getPlayer2().getName(), "Bob");
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