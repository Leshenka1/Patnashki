#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patnashki.h"
#include <QMessageBox>


Patnashki pat;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ms = 0;
    s=0;
    m=0;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerSlot()));

    for(auto i=0; i<4; i++)
    {
        ui->twPatnashki->setColumnWidth(i,75);
        ui->twPatnashki->setRowHeight(i,75);
    }

    showTable();


    if(!pat.isUnCreate())
    {
        QMessageBox::about(this,"Ууупс!", "Игра не соберётся :(");
    }

}

void MainWindow::showTable()
{
    ui->lbMovCount->setText("Количесвто шагов: "+QString::number(pat.getMovCount()));

    for (auto i = 0; i <4;i++)
    {
        for (auto j = 0; j <4;j++)
        {
            if(pat.getItem(i,j)==0)
            {
                num->setText(" ");
            }
            else
            {
            num->setText(QString::number(pat.getItem(i,j)));
            }
            ui->twPatnashki->setItem(i,j,new QTableWidgetItem(*num));
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_twPatnashki_cellClicked(int row, int column)
{
    timer->start(1);

    pat.reCalc(row,column);
    showTable();
    if(pat.isFinished())
    {
        timer->stop();
        if (QMessageBox::question(this,"Игра закончена!", "Победа!!! Желаете сыграть ещё раз?",
                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
         QApplication::quit();
        else {
            zeroTimer();
            timer->stop();
            pat.startGame();
            showTable();
        }
    }
}

void MainWindow::on_newGame_triggered()
{
    zeroTimer();
    timer->stop();
    pat.startGame();
    if(!pat.isUnCreate())
    {
        QMessageBox::about(this,"Ууупс!", "Игра не соберётся :(");
    }
    showTable();
}

void MainWindow::on_repeatGame_triggered()
{
        zeroTimer();
    timer->stop();
    pat.restartGame();
    showTable();
}

void MainWindow::TimerSlot()
{
    ms++;
    if(ms>=1000)
    {
        ms = 0;
        s++;
    }
    if(s>=60)
    {
        s=0;
        m++;
    }
    ui->lbTimer->setText(QString::number(m) + " : " + QString::number(s)+" : " + QString::number(ms));

}

void MainWindow::zeroTimer()
{
    ms=0;
    s=0;
    m=0;
    ui->lbTimer->setText(QString::number(m) + " : " + QString::number(s)+" : " + QString::number(ms));

}


