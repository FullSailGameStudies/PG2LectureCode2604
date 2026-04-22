#include "BlackjackCard.h"

int BlackjackCard::Value()
{
    //2 kinds of overrides:
    // 1) EXTENSION override
    //      when we call the base method
    // 2) FULL override
    //      DON'T call the base method

    //EXTENSION
    //int val = Card::Value();
    //if (val > 10) val = 10;

    //FULL
    int val = 0;
    std::string face = GetFace();
    if (face == "J" or face == "Q" or face == "K") val = 10;
    else if (face == "A") val = 1;
    else val = std::stoi(face);
    return val;
}
