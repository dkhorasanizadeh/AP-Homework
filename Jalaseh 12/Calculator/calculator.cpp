#include "calculator.hpp"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    waitingForNumber=true;
    sum=0.0;
    factor=0.0;
    connect(ui->OneButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->TwoButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->ThreeButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->FourButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->FiveButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->SixButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->SevenButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->EightButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->NineButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->ZeroButton,SIGNAL(clicked()),this,SLOT(digit()));
    connect(ui->DotButton,SIGNAL(clicked()),this,SLOT(dot()));
    connect(ui->PlusMinusButton,SIGNAL(clicked()),this,SLOT(plusMinus()));
    connect(ui->DotButton,SIGNAL(clicked()),this,SLOT(dot()));
    connect(ui->SquareRootButton,SIGNAL(clicked()),this,SLOT(unary()));
    connect(ui->PowerTwoButton,SIGNAL(clicked()),this,SLOT(unary()));
    connect(ui->DivideBy1Button,SIGNAL(clicked()),this,SLOT(unary()));
    connect(ui->PercentButton,SIGNAL(clicked()),this,SLOT(unary()));
    connect(ui->CEButton,SIGNAL(clicked()),this,SLOT(CE()));
    connect(ui->CButton,SIGNAL(clicked()),this,SLOT(C()));
    connect(ui->backSpaceButton,SIGNAL(clicked()),this,SLOT(backspace()));
    connect(ui->DivideButton,SIGNAL(clicked()),this,SLOT(multiplicative()));
    connect(ui->MultiplyButton,SIGNAL(clicked()),this,SLOT(multiplicative()));
    connect(ui->PlusButton,SIGNAL(clicked()),this,SLOT(additive()));
    connect(ui->MinusButton,SIGNAL(clicked()),this,SLOT(additive()));
    connect(ui->EqualButton,SIGNAL(clicked()),this,SLOT(equal()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::invalidInput()
{
    CE();
    ui->result->setText("Invalid Input");
}

bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == "+")
    {
        sum += rightOperand;
    }
    else if (pendingOperator == "-")
    {
        sum -= rightOperand;
    }
    else if (pendingOperator == "×")
    {
        factor *= rightOperand;
    }
    else if (pendingOperator == "÷")
    {
        if (rightOperand == 0.0)
        {
            return false;
        }
        factor /= rightOperand;
    }
    return true;
}

void Calculator::digit()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digit = clickedButton->text().toInt();
    if (ui->result->text() == "0" && digit == 0.0)
    {
        return;
    }
    if (waitingForNumber)
    {
        ui->result->clear();
        waitingForNumber = false;
    }
    ui->result->setText(ui->result->text() + QString::number(digit));
}

void Calculator::unary()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double number = ui->result->text().toDouble();
    double result = 0.0;
    if (clickedOperator == "√")
    {
        if (number < 0.0)
        {
            invalidInput();
            return;
        }
        result = std::sqrt(number);
    }
    else if (clickedOperator == "x²")
    {
        result = std::pow(number, 2.0);
    }
    else if (clickedOperator == "1/x")
    {
        if (number == 0.0)
        {
            invalidInput();
            return;
        }
        result = 1.0 / number;
    }
    else if(clickedOperator=="%")
    {
        result=number/100;
    }
    ui->result->setText(QString::number(result));
    waitingForNumber = true;
}

void Calculator::additive()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (!clickedButton)
    {
      return;
    }
    QString clickedOperator = clickedButton->text();
    double number = ui->result->text().toDouble();
    if (!pendingMultiplicative.isEmpty())
    {
        if (!calculate(number, pendingMultiplicative))
        {
            invalidInput();
            return;
        }
        ui->result->setText(QString::number(factor));
        number = factor;
        factor = 0.0;
        pendingMultiplicative.clear();
    }
    if (!pendingAdditive.isEmpty())
    {
        if (!calculate(number, pendingAdditive))
        {
            invalidInput();
            return;
        }
        ui->result->setText(QString::number(sum));
    }
    else
    {
        sum = number;
    }
    pendingAdditive = clickedOperator;
    waitingForNumber = true;
}

void Calculator::multiplicative()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (!clickedButton)
    {
      return;
    }
    QString clickedOperator = clickedButton->text();
    double number = ui->result->text().toDouble();
    if (!pendingMultiplicative.isEmpty())
    {
        if (!calculate(number, pendingMultiplicative))
        {
            invalidInput();
            return;
        }
        ui->result->setText(QString::number(factor));
    }
    else
    {
        factor = number;
    }
    pendingMultiplicative = clickedOperator;
    waitingForNumber = true;
}

void Calculator::equal()
{
    double number = ui->result->text().toDouble();
    if (!pendingMultiplicative.isEmpty())
    {
        if (!calculate(number, pendingMultiplicative))
        {
            invalidInput();
            return;
        }
        number = factor;
        factor = 0.0;
        pendingMultiplicative.clear();
    }
    if (!pendingAdditive.isEmpty())
    {
        if (!calculate(number, pendingAdditive))
        {
            invalidInput();
            return;
        }
        pendingAdditive.clear();
    }
    else
    {
        sum = number;
    }
    ui->result->setText(QString::number(sum));
    sum = 0.0;
    waitingForNumber = true;
}

void Calculator::dot()
{
    if (waitingForNumber)
    {
        ui->result->setText("0");
    }
    if (!ui->result->text().contains('.'))
    {
        ui->result->setText(ui->result->text() + ".");
    }
    waitingForNumber = false;
}

void Calculator::plusMinus()
{
    QString text = ui->result->text();
    double number = text.toDouble();
    if (number > 0.0)
    {
        text.prepend("-");
    }
    else if (number < 0.0)
    {
        text.remove(0, 1);
    }
    ui->result->setText(text);
}

void Calculator::backspace()
{
    if (waitingForNumber)
    {
        return;
    }
    QString text = ui->result->text();
    text.chop(1);
    if (text.isEmpty())
    {
        text = "0";
        waitingForNumber = true;
    }
    ui->result->setText(text);
}

void Calculator::C()
{
    if (waitingForNumber)
    {
        return;
    }
    ui->result->setText("0");
    waitingForNumber = true;
}

void Calculator::CE()
{
    sum = 0.0;
    factor = 0.0;
    pendingAdditive.clear();
    pendingMultiplicative.clear();
    ui->result->setText("0");
    waitingForNumber = true;
}

