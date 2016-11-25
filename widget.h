#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QDebug>
#include <QKeyEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);

private:
    int whichButton;
    int firstNumber;
    int secondNumber;
    bool isFinished;
    QGridLayout *mLayout;
    QLCDNumber *mScreen;
    QPushButton *mNum0;
    QPushButton *mNum1;
    QPushButton *mNum2;
    QPushButton *mNum3;
    QPushButton *mNum4;
    QPushButton *mNum5;
    QPushButton *mNum6;
    QPushButton *mNum7;
    QPushButton *mNum8;
    QPushButton *mNum9;
    QPushButton *mNumSum;
    QPushButton *mNumRiz;
    QPushButton *mNumMno;
    QPushButton *mNumDil;
    QPushButton *mNumC;
    QPushButton *mNumEquel;

private:
    void setWidgetOnScreen();
    void connects();
    virtual void keyPressEvent(QKeyEvent *event) override;

private slots:
    void pressed0();
    void pressed1();
    void pressed2();
    void pressed3();
    void pressed4();
    void pressed5();
    void pressed6();
    void pressed7();
    void pressed8();
    void pressed9();
    void pressedC();
    void pressedSum();
    void pressedRiz();
    void pressedMno();
    void pressedDil();
    void pressedEquel();
};

#endif // WIDGET_H
