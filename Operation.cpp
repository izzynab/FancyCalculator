#include "Operation.h"
#include <stdexcept>

class Dodawanie : public Operation {
public:
    double wykonaj(double a, double b) const override {
        return a + b;
    }
};

class Odejmowanie : public Operation {
public:
    double wykonaj(double a, double b) const override {
        return a - b;
    }
};

class Mnozenie : public Operation {
public:
    double wykonaj(double a, double b) const override {
        return a * b;
    }
};

class Dzielenie : public Operation {
public:
    double wykonaj(double a, double b) const override {
        if (b == 0) {
            // TODO: throw exception but in QT
            throw std::runtime_error("Dzielenie przez zero");
        }
        return a / b;
    }
};
