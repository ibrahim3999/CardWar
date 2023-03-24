#ifndef Player_hpp
#define Player_hpp

#include <string>

class Player {
public:
    Player(std::string name);
    std::string getName() const;
    int  getCardCount() const;
    int  stacksize();
    int  cardesTaken();
    void setCardCount(int count);
    void increaseCardCount();
    void decreaseCardCount();
    
private:
    std::string m_name;
    int m_cardCount;
};

#endif 