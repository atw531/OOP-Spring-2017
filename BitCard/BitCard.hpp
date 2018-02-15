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

    // Copy Constructor
    BitCard& operator=(BitCard bc);

    // Get the card's Rank
    Rank getRank() const;

    // Get the card's Suit
    Suit getSuit() const;

    // Operator Overloads
    bool operator!=(BitCard bc);
    bool operator==(BitCard bc);

private:

    unsigned char cardBits;

};
