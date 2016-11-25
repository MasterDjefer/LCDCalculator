#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), firstNumber(0), secondNumber(0),
    isFinished(false), whichButton(0)
{
    this->setFixedSize(250, 300);

    setWidgetOnScreen();

    connects();
}

void Widget::setWidgetOnScreen()
{
    mLayout = new QGridLayout;
    mScreen = new QLCDNumber;
    mScreen->display("0");
    mScreen->setDigitCount(10);

    mNum0 = new QPushButton("0");
    mNum1 = new QPushButton("1");
    mNum2 = new QPushButton("2");
    mNum3 = new QPushButton("3");
    mNum4 = new QPushButton("4");
    mNum5 = new QPushButton("5");
    mNum6 = new QPushButton("6");
    mNum7 = new QPushButton("7");
    mNum8 = new QPushButton("8");
    mNum9 = new QPushButton("9");
    mNumSum = new QPushButton("+");
    mNumSum->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    mNumRiz = new QPushButton("-");
    mNumMno = new QPushButton("*");
    mNumDil = new QPushButton("/");
    mNumC = new QPushButton("C");
    mNumEquel = new QPushButton("=");
    mNumEquel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    mLayout->addWidget(mScreen, 0, 0, 1, 4);
    mLayout->addWidget(mNumC, 1, 0, 1, 1);
    mLayout->addWidget(mNumDil, 1, 1, 1, 1);
    mLayout->addWidget(mNumMno, 1, 2, 1, 1);
    mLayout->addWidget(mNumRiz, 1, 3, 1, 1);
    mLayout->addWidget(mNumSum, 2, 3, 2, 1);
    mLayout->addWidget(mNumEquel, 4, 3, 2, 1);
    mLayout->addWidget(mNum7, 2, 0, 1, 1);
    mLayout->addWidget(mNum8, 2, 1, 1, 1);
    mLayout->addWidget(mNum9, 2, 2, 1, 1);
    mLayout->addWidget(mNum4, 3, 0, 1, 1);
    mLayout->addWidget(mNum5, 3, 1, 1, 1);
    mLayout->addWidget(mNum6, 3, 2, 1, 1);
    mLayout->addWidget(mNum1, 4, 0, 1, 1);
    mLayout->addWidget(mNum2, 4, 1, 1, 1);
    mLayout->addWidget(mNum3, 4, 2, 1, 1);
    mLayout->addWidget(mNum0, 5, 0, 1, 3);

    this->setLayout(mLayout);
}

void Widget::connects()
{
    QObject::connect(mNum0, &QPushButton::clicked, this, &Widget::pressed0);
    QObject::connect(mNum1, &QPushButton::clicked, this, &Widget::pressed1);
    QObject::connect(mNum2, &QPushButton::clicked, this, &Widget::pressed2);
    QObject::connect(mNum3, &QPushButton::clicked, this, &Widget::pressed3);
    QObject::connect(mNum4, &QPushButton::clicked, this, &Widget::pressed4);
    QObject::connect(mNum5, &QPushButton::clicked, this, &Widget::pressed5);
    QObject::connect(mNum6, &QPushButton::clicked, this, &Widget::pressed6);
    QObject::connect(mNum7, &QPushButton::clicked, this, &Widget::pressed7);
    QObject::connect(mNum8, &QPushButton::clicked, this, &Widget::pressed8);
    QObject::connect(mNum9, &QPushButton::clicked, this, &Widget::pressed9);
    QObject::connect(mNumC, &QPushButton::clicked, this, &Widget::pressedC);
    QObject::connect(mNumSum, &QPushButton::clicked, this, &Widget::pressedSum);
    QObject::connect(mNumRiz, &QPushButton::clicked, this, &Widget::pressedRiz);
    QObject::connect(mNumMno, &QPushButton::clicked, this, &Widget::pressedMno);
    QObject::connect(mNumDil, &QPushButton::clicked, this, &Widget::pressedDil);
    QObject::connect(mNumEquel, &QPushButton::clicked, this, &Widget::pressedEquel);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == '0')
        pressed0();
    else
    if (event->key() == '1')
        pressed1();
    else
    if (event->key() == '2')
        pressed2();
    else
    if (event->key() == '3')
        pressed3();
    else
    if (event->key() == '4')
        pressed4();
    else
    if (event->key() == '5')
        pressed5();
    else
    if (event->key() == '6')
        pressed6();
    else
    if (event->key() == '7')
        pressed7();
    else
    if (event->key() == '8')
        pressed8();
    else
    if (event->key() == '9')
        pressed9();
    else
    if (event->key() == '+')
        pressedSum();
    else
    if (event->key() == '-')
        pressedRiz();
    else
    if (event->key() == '*')
        pressedMno();
    else
    if (event->key() == '/')
        pressedDil();
    else
    if (event->key() == 16777220)
        pressedEquel();
    else
    if (event->key() == 16777221)
        pressedEquel();
    else
    if (event->key() == 16777223)
        pressedC();
    else
    if (event->key() == 16777219)
        pressedC();
    if (event->key() == 16777216)
        this->close();
}

void Widget::pressed0()
{
    if (isFinished)
        mScreen->display(0);

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(0);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "0");
}

void Widget::pressed1()
{
    if (isFinished)
    {
        mScreen->display(1);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(1);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "1");
}

void Widget::pressed2()
{
    if (isFinished)
    {
        mScreen->display(2);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(2);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "2");
}

void Widget::pressed3()
{
    if (isFinished)
    {
        mScreen->display(3);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(3);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "3");
}

void Widget::pressed4()
{
    if (isFinished)
    {
        mScreen->display(4);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(4);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "4");
}

void Widget::pressed5()
{
    if (isFinished)
    {
        mScreen->display(5);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(5);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "5");
}

void Widget::pressed6()
{
    if (isFinished)
    {
        mScreen->display(6);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(6);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "6");
}

void Widget::pressed7()
{
    if (isFinished)
    {
        mScreen->display(7);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(7);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "7");
}

void Widget::pressed8()
{
    if (isFinished)
    {
        mScreen->display(8);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(8);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "8");
}

void Widget::pressed9()
{
    if (isFinished)
    {
        mScreen->display(9);
        isFinished = false;
        return;
    }

    if (QString::number(mScreen->intValue()) == "0")
        mScreen->display(9);
    else
        mScreen->display(QString::number(mScreen->intValue()) + "9");
}

void Widget::pressedC()
{
    isFinished = false;
    mScreen->display(0);
    firstNumber = 0;
    secondNumber = 0;
}

void Widget::pressedSum()
{
    firstNumber = mScreen->intValue();
    mScreen->display(0);
    whichButton = 1;
}

void Widget::pressedRiz()
{
    firstNumber = mScreen->intValue();
    mScreen->display(0);
    whichButton = 2;
}

void Widget::pressedMno()
{
    firstNumber = mScreen->intValue();
    mScreen->display(0);
    whichButton = 3;
}

void Widget::pressedDil()
{
    firstNumber = mScreen->intValue();
    mScreen->display(0);
    whichButton = 4;
}

void Widget::pressedEquel()
{
    secondNumber = mScreen->intValue();

    switch (whichButton)
    {
        case 1:
            mScreen->display(firstNumber + secondNumber);
            break;
        case 2:
            mScreen->display(firstNumber - secondNumber);
            break;
        case 3:
            mScreen->display(firstNumber * secondNumber);
            break;
        case 4:
            if (!secondNumber)
                mScreen->display(firstNumber / secondNumber);
            break;
    }

    isFinished = true;
    firstNumber = 0;
    secondNumber = 0;
}
