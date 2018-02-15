#include "BitCard.hpp"
#include <iostream>

int main() {

    BitCard* card = new BitCard(King, Spades);
    BitCard* card2 = card;

    std::cout << card->getSuit() << std::endl;
    std::cout << card->getRank() << std::endl;

    std::cout << card2->getSuit() << std::endl;
    std::cout << card2->getRank() << std::endl;

    return 0;

}