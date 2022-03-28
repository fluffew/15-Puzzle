#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTimer>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTimer();
    void updateTurns();
    void on_twGameboard_cellClicked(int i, int j);
    void on_btRestart_clicked();

private:
    QTimer *tmr;
    QTime time;
    Ui::MainWindow *ui;
    void showTable();
    void exitGame();
};
#endif // MAINWINDOW_H
