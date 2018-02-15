#include "BitCard.hpp"
#include <iostream>

int main() {

    BitCard* card = new BitCard(King, Spades);
    BitCard* card2 = card;

    std::cout << card->getSuit() << std::endl;
    std::cout << card->getRank() << std::endl;

    std::cout << card2->getSuit() << std::endl;
    std::cout << card2->getRank() << std::endl;

    BitCard* card3 = new BitCard(Two, Spades);
    if(card != card3) {
        std::cout << "card != card3\n";
    }

    if(card == card2) {
        std::cout << "card == card2\n";
    }

    if(card == card3) {
        std::cout << "card == card3\n";
    } else {
        std::cout << "card != card3\n";
    }

    return 0;

}