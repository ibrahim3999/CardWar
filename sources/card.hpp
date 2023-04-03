#ifndef CARD_HPP
#define CARD_HPP

#include <string>

namespace ariel {

class Card {

public:
    enum Suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    enum Rank {
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

    Card(Suit suit, Rank rank)
        : m_suit(suit), m_rank(rank) {}

    Suit getSuit() const { return m_suit; }
    Rank getRank() const { return m_rank; }

    bool isLarger(const Card& other) const {
        return m_rank > other.m_rank;
    }

    bool isEquals(const Card& other) const {
        return m_rank == other.m_rank && m_suit == other.m_suit;
    }

    std::string toString() const {
        std::string suitStr;
        switch (m_suit) {
            case CLUBS:
                suitStr = "Clubs";
                break;
            case DIAMONDS:
                suitStr = "Diamonds";
                break;
            case HEARTS:
                suitStr = "Hearts";
                break;
            case SPADES:
                suitStr = "Spades";
                break;
            default:
                suitStr = "Unknown suit";
                break;
        }

        std::string rankStr;
        switch (m_rank) {
            case TWO:
                rankStr = "Two";
                break;
            case THREE:
                rankStr = "Three";
                break;
            case FOUR:
                rankStr = "Four";
                break;
            case FIVE:
                rankStr = "Five";
                break;
            case SIX:
                rankStr = "Six";
                break;
            case SEVEN:
                rankStr = "Seven";
                break;
            case EIGHT:
                rankStr = "Eight";
                break;
            case NINE:
                rankStr = "Nine";
                break;
            case TEN:
                rankStr = "Ten";
                break;
            case JACK:
                rankStr = "Jack";
                break;
            case QUEEN:
                rankStr = "Queen";
                break;
            case KING:
                rankStr = "King";
                break;
            case ACE:
                rankStr = "Ace";
                break;
            default:
                rankStr = "Unknown rank";
                break;
        }

        return rankStr + " of " + suitStr;
    }

private:
    Suit m_suit;
    Rank m_rank;
};

}  // namespace ariel

#endif  // CARD_HPP