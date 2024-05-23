
#include "FancyCalculator.h"
#include "ui_FancyCalculator.h"
#include "Operation.h"

FancyCalculator::FancyCalculator(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Starting page (default calcualtor)
    ui.stackedWidget->setCurrentIndex(0);

    //connect(ui.programmerModeButton, &QPushButton::clicked, this, &FancyCalculator::showPage1);
    //connect(ui.basicModeButton, &QPushButton::clicked, this, &FancyCalculator::showPage2);
    //connect(ui.pushButton_55, &QPushButton::clicked, this, &FancyCalculator::showPage3);

}

FancyCalculator::~FancyCalculator()
{
}

void FancyCalculator::showPage1()
{
    ui.stackedWidget->setCurrentIndex(0); 
}

void FancyCalculator::showPage2()
{
    ui.stackedWidget->setCurrentIndex(1); 
}

void FancyCalculator::showPage3()
{
    ui.stackedWidget->setCurrentIndex(2);
}

void FancyCalculator::wykonajOperacje(const Operation& operacja, double a, double b)
{
    try
    {
        double wynik = operacja.wykonaj(a, b);
        // TODO: print the result
        //std::cout << "Wynik: " << wynik << std::endl;
    }
    catch (const std::exception& e)
    {
        // TODO: here we can use the QT message box 
        // create class for handling any type of errors (instead of the std::cerr)
        //std::cerr << "Błąd: " << e.what() << std::endl;
    }
}
