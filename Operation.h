#pragma once 

#include <cmath>
#include <stdexcept>

class Operation {
protected:
    char operatorSign;

public:
    virtual ~Operation() = default;
    virtual double execute(double a, double b) const = 0;
    char getOperator() const
    {
        return operatorSign;
    }

    Operation(char sign) : operatorSign(sign) {}
};

class Addition : public Operation {
public:
    double execute(double a, double b) const override {
        return a + b;
    }

    Addition() : Operation('+') {}
};

class Subtraction : public Operation {
public:
    double execute(double a, double b) const override {
        return a - b;
    }

    Subtraction() : Operation('-') {}
};

class Multiplication : public Operation {
public:
    double execute(double a, double b) const override {
        return a * b;
    }

    Multiplication() : Operation('*') {}
};

class Division : public Operation {
public:
    double execute(double a, double b) const override 
    {
        if (b == 0) 
        {
            throw std::runtime_error("Division by zero");
        }
        return a / b;
    }

    Division() : Operation('/') {}
};
