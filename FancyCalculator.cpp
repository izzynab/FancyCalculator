
#include "FancyCalculator.h"
#include "ui_FancyCalculator.h"

FancyCalculator::FancyCalculator(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.programmerModeButton, &QPushButton::clicked, this, &FancyCalculator::showPage1);
    connect(ui.basicModeButton, &QPushButton::clicked, this, &FancyCalculator::showPage2);
    connect(ui.pushButton_55, &QPushButton::clicked, this, &FancyCalculator::showPage3);

}

FancyCalculator::~FancyCalculator()
{
}
void FancyCalculator::showPage1()
{
    ui.stackedWidget->setCurrentIndex(0); // Prze³¹cz na stronê 1
}

void FancyCalculator::showPage2()
{
    ui.stackedWidget->setCurrentIndex(1); // Prze³¹cz na stronê 2
}

void FancyCalculator::showPage3()
{
    ui.stackedWidget->setCurrentIndex(2); // Prze³¹cz na stronê 3
}

