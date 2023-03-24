#ifndef Player_hpp
#define Player_hpp
#include <string>

namespace ariel {
    class Player {
public:
    Player(std::string name);
    int getCardCount() const;
    int  stacksize();
    int  cardesTaken();
private:
    std::string m_name;
    int m_cardCount;
    };
}
#endif 