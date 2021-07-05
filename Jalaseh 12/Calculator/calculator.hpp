#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    void invalidInput();
    bool calculate(double rightOperand, const QString &pendingOperator);
    Ui::Calculator *ui;
    double sum;
    double factor;
    QString pendingAdditive;
    QString pendingMultiplicative;
    bool waitingForNumber;

public slots:
    void digit();
    void unary();
    void additive();
    void multiplicative();
    void equal();
    void dot();
    void plusMinus();
    void backspace();
    void C();
    void CE();
};
#endif // CALCULATOR_HPP
