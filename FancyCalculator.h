﻿#include <QtWidgets/QMainWindow>
#include <QString>
#include <string.h>
#include <stack>
#include <QMessageBox>
#include "ui_FancyCalculator.h"
#include "Operation.h"

class FancyCalculator : public QMainWindow {
    Q_OBJECT

public:
    FancyCalculator(QWidget* parent = nullptr);
    ~FancyCalculator();

private:
    QString firstNumber;
    QString currentNumber;

    QString currentText;
    bool operationLoaded;
    bool firstNumberLoaded;

    Operation* currentOperation;
    bool isChecked;

    std::stack<std::string> resultsHistory;

private:
    void loadNumberPart(const QString& part);
    void showCurrentText();
    void addOperatorToText();
    void equal_operation();
    void delet_operation();
    void clearText();

    template<typename T>
    void operation();

private:
    Ui::FancyCalculatorClass ui;
};
