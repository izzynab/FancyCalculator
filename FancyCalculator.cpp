
#include "FancyCalculator.h"
#include "ui_FancyCalculator.h"
#include "Operation.h"
#include <QApplication>
#include <QCheckBox>
#include <QWidget>

FancyCalculator::FancyCalculator(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Starting page (default calcualtor)
    ui.stackedWidget->setCurrentIndex(0);

    connect(ui.programmerModeButton, &QPushButton::clicked, this, &FancyCalculator::showPage1);
    //connect(ui.basicModeButton, &QPushButton::clicked, this, &FancyCalculator::showPage2);
    //connect(ui.pushButton_55, &QPushButton::clicked, this, &FancyCalculator::showPage3);

    connect(ui.Btn_equal, &QPushButton::clicked, this, &FancyCalculator::equal_operation);
    connect(ui.Btn_plus, &QPushButton::clicked, this, &FancyCalculator::plus_operation);
    connect(ui.Btn_minus, &QPushButton::clicked, this, &FancyCalculator::minus_operation);
    connect(ui.Btn_division, &QPushButton::clicked, this, &FancyCalculator::devide_operation);
    connect(ui.Btn_multiplication, &QPushButton::clicked, this, &FancyCalculator::multiplication_operation);
    connect(ui.Btn_C, &QPushButton::clicked, this, &FancyCalculator::clearText);
    connect(ui.Btn_delet, &QPushButton::clicked, this, &FancyCalculator::delet_operation);
    connect(ui.Btn_reverse, &QPushButton::clicked, this, &FancyCalculator::sign_reverse_operation);
    connect(ui.Btn_power_2, &QPushButton::clicked, this, &FancyCalculator::power_2_operation);
    connect(ui.Btn_1x, &QPushButton::clicked, this, &FancyCalculator::power_1x_operation);

    connect(ui.Btn_Pi, &QPushButton::clicked, [=]() { showNumber("3.1415926535897932384626433832"); });
    connect(ui.Btn_e, &QPushButton::clicked, [=]() { showNumber("2.7182818284590452353602874713"); });
    connect(ui.Btn_dot, &QPushButton::clicked, [=]() { showNumber("."); });
    connect(ui.Btn0, &QPushButton::clicked, [=]() { showNumber("0"); });
    connect(ui.Btn1, &QPushButton::clicked, [=]() { showNumber("1"); });
    connect(ui.Btn2, &QPushButton::clicked, [=]() { showNumber("2"); });
    connect(ui.Btn3, &QPushButton::clicked, [=]() { showNumber("3"); });
    connect(ui.Btn4, &QPushButton::clicked, [=]() { showNumber("4"); });
    connect(ui.Btn5, &QPushButton::clicked, [=]() { showNumber("5"); });
    connect(ui.Btn6, &QPushButton::clicked, [=]() { showNumber("6"); });
    connect(ui.Btn7, &QPushButton::clicked, [=]() { showNumber("7"); });
    connect(ui.Btn8, &QPushButton::clicked, [=]() { showNumber("8"); });
    connect(ui.Btn9, &QPushButton::clicked, [=]() { showNumber("9"); });
    //connect(ui.Btn_plus, &QPushButton::clicked, [=]() { cin_operation_char('+'), & FancyCalculator::plus_operation; });

    connect(ui.Btn_mode, &QPushButton::clicked, this, &FancyCalculator::onBtnToggled);

}

FancyCalculator::~FancyCalculator()
{
}

void FancyCalculator::showPage1()
{
    ui.stackedWidget->setCurrentIndex(0); 
}


void FancyCalculator::wykonajOperacje(const Operation& operacja, double a, double b)
{
    double value1 = variable1.toDouble();
    double value2 = variable2.toDouble();
    a = value1;
    b = value2;
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
QString FancyCalculator::processText()
{
    // Wczytaj tekst z QTextEdit
    QString text = ui.textEdit->toPlainText();
    //ui.label->setText(text);
    return text;
}

void FancyCalculator::delet_operation(){
    QString text = processText();
    text.chop(1); // Usuwa ostatni znak
    clearText();
    showNumber(text);
}

void FancyCalculator::showNumber(QString i) {

    FancyCalculator::texts << QString(i);
    QString finalText = texts.join("");
    ui.textEdit->setPlainText(finalText);
}

void FancyCalculator::cin_operation_char(QChar b) {

    operation_char=b;
}


void FancyCalculator::clearText() {

    ui.textEdit->clear();
    texts.clear();
}

void FancyCalculator::onBtnToggled()
{
    isChecked = !isChecked;
    if (isChecked) {
        // Ustaw styl dla zaznaczonego checkboxa
        ui.widget->setStyleSheet("QWidget { background-color:white; color:black }QWidget{ background - color:white; color:black }  QCheckBox { color: blue; }");
        ui.textEdit->setStyleSheet("QTextEdit {color: black;font-size: 32px;    border:0px,solid,white;}");
        ui.widget_2->setStyleSheet("QWidget { background-color:white; color:black }");
        ui.centralWidget->setStyleSheet("QWidget{ margin:0; background-color: white;   }");
        ui.stackedWidget_2->setStyleSheet("QWidget{ background-color: white;   }");
}
    else {
        // Resetuj styl
        ui.centralWidget->setStyleSheet("QWidget{ margin:0; background - color: rgb(24, 24, 24)   }");
        ui.widget->setStyleSheet("QWidget{ background - color: rgb(24, 24, 24);}");
        ui.stackedWidget_2->setStyleSheet("QWidget{ background - color: rgb(24, 24, 24);   }");
        ui.textEdit->setStyleSheet("QTextEdit {background-color: rgb(24, 24, 24);color: white;font-size:32px;border:0px,solid,black;}");
        ui.widget_2->setStyleSheet("QWidget{ background - color: rgb(24, 24, 24);}");
    }
}


