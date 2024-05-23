#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FancyCalculator.h"

class FancyCalculator : public QMainWindow
{
    Q_OBJECT

public:
    FancyCalculator(QWidget *parent = nullptr);
    ~FancyCalculator();

private:
    Ui::FancyCalculatorClass ui;
};
