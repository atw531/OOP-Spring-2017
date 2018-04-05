#pragma once

#include "Global.hpp"

class BitCard {

public:
	BitCard() {

	}

	BitCard(Rank rank, Suit suit)
        : cardBits((unsigned)standardFlag << 7 | (unsigned)rank << 2 | (unsigned) suit) {

    }

    BitCard(Color color)
    	: cardBits((unsigned)jokerFlag << 7 | (unsigned)color) {

    }

private:
	unsigned char cardBits;

	int jokerFlag = 1;
	int standardFlag = 0;

}