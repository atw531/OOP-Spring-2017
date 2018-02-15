#pragma once

enum Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades,
};

enum Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

class BitCard {

public:

    // Default Constructor
    BitCard() {

    }

    // Constructor with rank and suit
    BitCard(Rank rank, Suit suit)
        : cardBits((unsigned)rank << 2 | (unsigned) suit) {

    }

private:

    unsigned char cardBits;

};
