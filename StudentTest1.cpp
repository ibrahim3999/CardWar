#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;

TEST_CASE("The amount of cards before starting a game")
{
    Player p1("Alice");
    Player p2("Bob");

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("The amount of cards after starting a game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("The card scheme at the end of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    int sum = p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken();
    CHECK(sum == 52);
}

TEST_CASE("Throwing errors from the functions")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        game.playTurn();
    }
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Activating another turn after the game is over")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("One player")
{
    Player p1("Alice");
    Game game(p1, p1);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Printing the winner")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    if (p1.cardesTaken() == p2.cardesTaken())
    {
        CHECK_THROWS(game.printWiner());
    }
    else
    {
        CHECK_NOTHROW(game.printWiner());
    }
}

TEST_CASE("The game ends after at most 26 turns")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool maxTurns = 26;
    
    for (int i = 0 ; i <= 26 ; i++ && p1.stacksize()>=0)
    {
        game.playTurn();
    }
    CHECK(maxTurns == 26);
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}