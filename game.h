#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <vector>
#include <QPushButton>
#include <QGridLayout>
namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    QPushButton* hidden;
    QPushButton* clicked;
    QGridLayout* board;
    QMouseEvent* event;
    int hx, hy;
    ~Game();
    void moveTile(int, int);
private slots:
private:
    Ui::Game *ui;
};

#endif // GAME_H
