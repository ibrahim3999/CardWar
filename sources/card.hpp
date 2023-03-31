#ifndef Card_hpp
#define Card_hpp
#include "player.hpp"
#include <string>
#include<sstream>

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

   std::string toString() const {
        std::string rankStr;
        switch (m_rank) {
            case Rank::ACE: rankStr= "Ace";break;
            case Rank::TWO: rankStr="Two";break;
            case Rank::THREE: rankStr="Three";break;
            case Rank::FOUR:rankStr= "Four";break;
            case Rank::FIVE: rankStr= "Five";break;
            case Rank::SIX: rankStr= "Six";break;
            case Rank::SEVEN: rankStr= "Seven";break;
            case Rank::EIGHT: rankStr= "Eight";break;
            case Rank::NINE: rankStr= "Nine";break;
            case Rank::TEN: rankStr= "Ten";break;
            case Rank::JACK: rankStr= "Jack";break;
            case Rank::QUEEN: rankStr= "Queen";break;
            case Rank::KING: rankStr= "King";break;
            default: rankStr= "Unknown rank";break;
        }
        std::string suitStr;
         switch (m_suit) {
            case Suit::SPADES: suitStr= "Spades";break;
            case Suit::HEARTS: suitStr= "Hearts";break;
            case Suit::CLUBS: suitStr= "Clubs";break;
            case Suit::DIAMONDS: suitStr= "Diamonds";break;
            default: suitStr= "Unknown suit";break;
        }
        return rankStr+ " of " +suitStr;
    }
    
    
private:
    Suit m_suit;
    Rank m_rank;
};
};


#endif 