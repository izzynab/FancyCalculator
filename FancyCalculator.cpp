#include "FancyCalculator.h"
#include "ui_FancyCalculator.h"
#include "Operation.h"
#include <QApplication>
#include <QCheckBox>
#include <QWidget>
#include <QMessageBox>
#include <stack>

FancyCalculator::FancyCalculator(QWidget* parent)
    : QMainWindow(parent), currentOperation(nullptr), operationLoaded(false), firstNumberLoaded(false), isChecked(false)
{
    ui.setupUi(this);

    // Starting page (default calcualtor)
    ui.stackedWidget->setCurrentIndex(0);

    connect(ui.Btn_equal, &QPushButton::clicked, this, &FancyCalculator::equal_operation);
    connect(ui.Btn_plus, &QPushButton::clicked, this, &FancyCalculator::operation<Addition>);
    connect(ui.Btn_minus, &QPushButton::clicked, this, &FancyCalculator::operation<Subtraction>);
    connect(ui.Btn_division, &QPushButton::clicked, this, &FancyCalculator::operation<Division>);
    connect(ui.Btn_multiplication, &QPushButton::clicked, this, &FancyCalculator::operation<Multiplication>);
    connect(ui.Btn_C, &QPushButton::clicked, this, &FancyCalculator::clearText);
    connect(ui.Btn_delet, &QPushButton::clicked, this, &FancyCalculator::delet_operation);

    connect(ui.Btn_dot, &QPushButton::clicked, [=]() { loadNumberPart("."); });
    connect(ui.Btn0, &QPushButton::clicked, [=]() { loadNumberPart("0"); });
    connect(ui.Btn1, &QPushButton::clicked, [=]() { loadNumberPart("1"); });
    connect(ui.Btn2, &QPushButton::clicked, [=]() { loadNumberPart("2"); });
    connect(ui.Btn3, &QPushButton::clicked, [=]() { loadNumberPart("3"); });
    connect(ui.Btn4, &QPushButton::clicked, [=]() { loadNumberPart("4"); });
    connect(ui.Btn5, &QPushButton::clicked, [=]() { loadNumberPart("5"); });
    connect(ui.Btn6, &QPushButton::clicked, [=]() { loadNumberPart("6"); });
    connect(ui.Btn7, &QPushButton::clicked, [=]() { loadNumberPart("7"); });
    connect(ui.Btn8, &QPushButton::clicked, [=]() { loadNumberPart("8"); });
    connect(ui.Btn9, &QPushButton::clicked, [=]() { loadNumberPart("9"); });

    connect(ui.Btn_mode, &QPushButton::clicked, this, &FancyCalculator::onBtnToggled);
}

FancyCalculator::~FancyCalculator() {
    delete currentOperation;
}

void FancyCalculator::loadNumberPart(const QString& part) {
    currentNumber += part;
    currentText = currentNumber;
    showCurrentText();
}

void FancyCalculator::delet_operation() {
    if (operationLoaded) {
        currentOperation = nullptr;
        operationLoaded = false;
    }
    else {
        currentNumber.chop(1);
    }
    currentText.chop(1);
    showCurrentText();
}

void FancyCalculator::clearText() {
    currentText.clear();
    currentNumber.clear();
    firstNumber.clear();
    delete currentOperation;
    currentOperation = nullptr;
    operationLoaded = false;
    firstNumberLoaded = false;
    showCurrentText();
}

void FancyCalculator::showCurrentText() {
    ui.textEdit->setPlainText(currentText);
}

void FancyCalculator::addOperatorToText() {
    if (currentOperation) {
        currentText += currentOperation->getOperator();
    }
}

template<typename T>
void FancyCalculator::operation() {
    if (operationLoaded) {
        QMessageBox::warning(this, "Błąd", "Operacja już została wybrana.");
        return;
    }
    if (currentNumber.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Proszę wprowadzić liczbę przed operacją.");
        return;
    }
    firstNumber = currentNumber;
    currentNumber.clear();
    currentOperation = new T();
    operationLoaded = true;
    firstNumberLoaded = true;
    addOperatorToText();
    showCurrentText();
}

void FancyCalculator::equal_operation() {
    if (!operationLoaded || currentNumber.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Proszę wprowadzić dwie liczby i jedną operację.");
        return;
    }

    bool ok1, ok2;
    double firstNumberVal = firstNumber.toDouble(&ok1);
    double secondNumberVal = currentNumber.toDouble(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Błąd", "Niepoprawna liczba.");
        return;
    }

    try {
        double result = currentOperation->execute(firstNumberVal, secondNumberVal);
        showNumber(QString::number(result));
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Błąd", e.what());
    }

    delete currentOperation;
    currentOperation = nullptr;
    operationLoaded = false;
    firstNumberLoaded = false;
    currentNumber.clear();
    firstNumber.clear();
}

void FancyCalculator::onBtnToggled() {
    isChecked = !isChecked;
    if (isChecked) {
        ui.widget->setStyleSheet("QWidget { background-color:white; color:black }");
        ui.textEdit->setStyleSheet("QTextEdit {color: black;font-size: 32px;}");
        ui.centralWidget->setStyleSheet("QWidget { background-color:white; }");
    }
    else {
        ui.centralWidget->setStyleSheet("QWidget { background-color: rgb(24, 24, 24) }");
        ui.textEdit->setStyleSheet("QTextEdit {background-color: rgb(24, 24, 24);color: white;font-size:32px;}");
    }
}

void FancyCalculator::showNumber(const QString& number) {
    currentText = number;
    showCurrentText();
}
