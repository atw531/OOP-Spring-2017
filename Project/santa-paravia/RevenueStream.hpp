#ifndef SANTA_PARAVIA_REVENUESTREAM_HPP
#define SANTA_PARAVIA_REVENUESTREAM_HPP

class RevenueStream {
public:
    RevenueStream()
            : Revenue(0) {

    };

    int Revenue;
};

class Tax : public RevenueStream {
public:
    Tax(int percentage)
            : Percentage(percentage) {

    }

    int Percentage;
};

#endif //SANTA_PARAVIA_REVENUESTREAM_HPP
