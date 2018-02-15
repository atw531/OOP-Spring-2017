#include "BitCard.hpp"

Rank BitCard::getRank() const {
    return (Rank)(0b111100 & this->cardBits);
}

Suit BitCard::getSuit() const {
    return (Suit)(0b000011 & this->cardBits);
}

BitCard& BitCard::operator=(BitCard bc) {
    this->cardBits = bc.cardBits;
}

bool BitCard::operator!=(BitCard bc) {
    return cardBits != bc.cardBits;
}

bool BitCard::operator==(BitCard bc) {
    return cardBits == bc.cardBits;
}