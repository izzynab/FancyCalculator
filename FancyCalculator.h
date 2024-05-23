

#include <QtWidgets/QMainWindow>
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
- 

*/

/*
ideas:

- zmiany kolorkow / zapisywanie ich 
- dodanie nowych operacji (np. potegowanie)
- dodanie nowych trybow (np. tryb naukowy)

*/


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
    void wykonajOperacje(const Operation& operacja, double a, double b);

private:
    Ui::FancyCalculatorClass ui;
};

