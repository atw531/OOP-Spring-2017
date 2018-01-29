#ifndef WAR_CARD_HPP
#define WAR_CARD_HPP

enum Suit {
    Diamonds,
    Hearts,
    Spades,
    Clubs
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
    King
};

class Card {

public:
    Card(Rank r, Suit s)
            : rank(r),suit(s) {

    }

    Rank getRank() {
        return rank;
    }

    Suit getSuit() {
        return suit;
    }

private:
    Rank rank;
    Suit suit;

};

#endif //WAR_CARD_HPP
