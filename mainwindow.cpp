#include "mainwindow.h"
#include "gameboard.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTime>
#include <QMessageBox>

Gameboard game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showTable();
    if (game.isFinished()) {
        exitGame();
    }
    time.setHMS(00,00,00,00);
    tmr = new QTimer(this);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTimer()));
    tmr->start(10);
}

void MainWindow::on_twGameboard_cellClicked(int row, int column)
{
    if (((std::abs(game.empty_row - row) == 1) && (game.empty_column == column)) ||
        ((std::abs(game.empty_column - column) == 1) && (game.empty_row == row))) {
        game.numbers[game.empty_row][game.empty_column] = game.numbers[row][column];
        game.numbers[row][column] = 16;

        QTableWidgetItem* cell = ui->twGameboard->item(row, column)->clone();
        ui->twGameboard->setItem(game.empty_row, game.empty_column, cell);
        delete ui->twGameboard->currentItem();

        game.empty_row = row;
        game.empty_column = column;
        game.turns_counter++;
        updateTurns();

        if (game.isFinished()) {
            exitGame();
        }
    }
}
void MainWindow::updateTimer()
{
    time = time.addMSecs(10);
    ui->lbTimer->setText(time.toString("hh:mm:ss"));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTable() {
    game.startGame();
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
        QTableWidgetItem* tile = new QTableWidgetItem;
        tile->setText(QString::number(game.numbers[i][j]));
        tile->setTextAlignment(0x0004 | 0x0080);
        tile->setBackground(QColor(212, 169, 252, 255));
        if (game.numbers[i][j] != 16) {
            ui->twGameboard->setItem(i,j,tile);
        }
        else {
            game.empty_row = i;
            game.empty_column = j;
        }
        }
    }
}

void MainWindow::on_btRestart_clicked()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            delete ui->twGameboard->item(i,j);
        }
    }
    game.turns_counter = 0;
    updateTimer();
    updateTurns();
    showTable();
    time.setHMS(0,0,0);
    tmr->start(10);
}

void MainWindow::updateTurns() {
    ui->lbTurns->setText(QString::number(game.turns_counter));
}

void MainWindow::exitGame() {
    tmr->stop();
    QMessageBox finish;
    QString output = "Turns: "+QString::number(game.turns_counter) + "\nTime: "+time.toString("hh:mm:ss");
    finish.setText(output);
    finish.exec();
}
