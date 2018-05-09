#ifndef TEST_SANTA_RESOURCE_HPP
#define TEST_SANTA_RESOURCE_HPP

struct Resource {
public:
    Resource(int initialAmount) : Count(initialAmount) {

    }

    int Count;
};

struct Grain : Resource {
public:
    Grain(int initialAmount, int price)
            : Resource(initialAmount), Cost(price),
              Demand(0), Rats(0), Harvest(0) {

    }

    int Cost;
    int Demand;
    int Rats;
    int Harvest;
};

struct Land : Resource {
public:
    Land(int initialAmount, double price)
            : Resource(initialAmount), Cost(price) {

    }

    double Cost;
};

#endif //TEST_SANTA_RESOURCE_HPP
