
#include <iostream>
#include <vector>
#include "game.hpp"
#include "card.hpp"
using namespace std;

namespace ariel {
    Card::Suit Card::getSuit()const{
        return m_suit;
    }
    Card::Rank Card::getRank()const{
        return m_rank;
    }
    bool Card::isLarger(const Card& other)const{
        return m_rank > other.m_rank;
    }
    bool Card::isEquals(const  Card& other)const{
        return m_rank == other.m_rank;
    }
}
