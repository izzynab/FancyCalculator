

#include <QtWidgets/QMainWindow>
#include "ui_FancyCalculator.h"

class FancyCalculator : public QMainWindow
{
    Q_OBJECT

public:
    FancyCalculator(QWidget* parent = nullptr);
    ~FancyCalculator();

private slots:
    void showPage1();
    void showPage2();
    void showPage3();

private:
    Ui::FancyCalculatorClass ui;
};

