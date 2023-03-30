#ifndef Card_hpp
#define Card_hpp
#include "player.hpp"
#include <string>

namespace ariel {

class Card {

public:
    enum class Suit{
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES,
    };
    enum class Rank{
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };

    Card(Suit suit,Rank rank):m_suit(suit),m_rank(rank){}
    Suit getSuit()const;
    Rank getRank()const;
    bool isLarger(const  Card & other)const;
    bool isEquals(const  Card & other)const;
    
private:
    Suit m_suit;
    Rank m_rank;

};
}
#endif 