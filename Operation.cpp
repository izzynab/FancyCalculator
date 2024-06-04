#include "Operation.h"
#include "FancyCalculator.h"
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
void FancyCalculator::equal_operation() {
    
    bool ok1, ok2;
    double wynik = 0.0;
    double var1 = variable1.toDouble(&ok1);
    if (operation_char == 'r') {
        var1 *= -1.0;
        QString wynik2 = QString::number(var1);
        showNumber(wynik2);
        return;
    }
    else if (operation_char == '1') {
        var1 =1/var1;
        QString wynik2 = QString::number(var1);
        showNumber(wynik2);
        return;
    }
    else if (operation_char == '2') {
        var1 *= var1;
        QString wynik2 = QString::number(var1);
        showNumber(wynik2);
        return;
    }

    variable2 = processText();
    clearText();
    double var2 = variable2.toDouble(&ok2);
    if (!ok1 || !ok2) {
        qDebug() << "Error: Invalid input for numerical operation";
        return;
    }
    if (operation_char == '+') {
        wynik = var1 + var2;
    }
    else if (operation_char == '-') {
        wynik = var1 - var2;
    }
    else if (operation_char == '/') {
        wynik = var1 / var2;
    }
    else if (operation_char == '*') {
        wynik = var1 * var2;
    }
    else {
        qDebug() << "Error: Unsupported operation";
        return;
    }
    QString wynik2 = QString::number(wynik);
    showNumber(wynik2);
}
void FancyCalculator::plus_operation() {
    cin_operation_char('+');
    variable1 = processText();
    clearText();
}
void FancyCalculator::minus_operation() {
    cin_operation_char('-');
    variable1 = processText();
    clearText();
}
void FancyCalculator::devide_operation() {
    cin_operation_char('/');
    variable1 = processText();
    clearText();
}
void FancyCalculator::multiplication_operation() {
    cin_operation_char('*');
    variable1 = processText();
    clearText();
}
void FancyCalculator::sign_reverse_operation() {
    cin_operation_char('r');
    variable1 = processText();
    
    clearText();
}
void FancyCalculator::power_1x_operation() {
    cin_operation_char('1');
    variable1 = processText();
    clearText();
}
void FancyCalculator::power_2_operation() {
    cin_operation_char('2');
    variable1 = processText();
    clearText();
}
