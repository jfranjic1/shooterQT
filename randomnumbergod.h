#ifndef RANDOMNUMBERGOD_H
#define RANDOMNUMBERGOD_H


class RandomNumberGod {
private:
    double percentage=0;
public:
    RandomNumberGod(double percentage);
    RandomNumberGod();
    bool roll();
    bool roll(double percentage);
    int number_int(int min, int max);
    double number_double(double min, double max);
};

#endif // RANDOMNUMBERGOD_H
