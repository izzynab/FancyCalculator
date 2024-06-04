

#include <QtWidgets/QMainWindow>
#include <string>

#include "ui_FancyCalculator.h"
#include "Operation.h"


/*
QT stuff that needs to be included:

Layouty: Skalowalny interfejs.
QPushButton: Przycisk do wykonania operacji.
QCheckBox: Opcjonalne ustawienia.
QComboBox: Wybór operacji.
QListWidget: Wyświetlanie historii operacji.
QMessageBox: Komunikaty o błędach.
*/

/*

stuff TODO

- zapisywanie / odczytywanie historii do pliku
- uzyc string / vector (STL; smart_pointers???) TODO: think on that
- throw_exception -> QT messhage box eror (dzielenie przez 0)
- ogarnac jak uzywac polimorizmu i takich inncyh dla liczb etc...

*/

/*
ideas:

- zmiany kolorkow / zapisywanie ich
- dodanie nowych operacji (np. potegowanie)
- dodanie nowych trybow (narazie jebac nie dodajemy za duzo myslenia)

*/


class FancyCalculator : public QMainWindow
{
    Q_OBJECT

public:
    FancyCalculator(QWidget* parent = nullptr);
    ~FancyCalculator();

private:
    QStringList texts;
    QString operation_char;
    QString variable1;
    QString variable2;
    bool isChecked = false;

private slots:
  
    void showPage1();
    //void showPage2();
    //void showPage3();

private:
    void wykonajOperacje(const Operation& operacja, double a, double b);
    QString processText();
    void cin_operation_char(QChar b);
    void showNumber(QString i);

    void equal_operation();
    void plus_operation();
    void multiplication_operation();
    void minus_operation();
    void devide_operation();
    void power_1x_operation();
    void power_2_operation();

    void sign_reverse_operation();
    void delet_operation();
    void clearText();

    void onBtnToggled();


private:
    Ui::FancyCalculatorClass ui;
};

