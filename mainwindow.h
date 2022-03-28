#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
    QTableWidgetItem *num = new QTableWidgetItem;
    void showTable();

private slots:
    void on_twPatnashki_cellClicked(int row, int column);

    void on_newGame_triggered();

    void on_repeatGame_triggered();

    void TimerSlot();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int ms, s , m;
    void zeroTimer();

};
#endif // MAINWINDOW_H
