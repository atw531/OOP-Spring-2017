#include "BitCard.hpp"

BitCard& BitCard::operator=(BitCard bc) {
    this->cardBits = bc.cardBits;
}

Rank BitCard::getRank() const {
    return (Rank)(0b111100 & this->cardBits);
}

Suit BitCard::getSuit() const {
    return (Suit)(0b000011 & this->cardBits);
}