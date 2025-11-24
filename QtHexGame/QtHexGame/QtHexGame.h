#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtHexGame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtHexGameClass; };
QT_END_NAMESPACE

class QtHexGame : public QMainWindow
{
    Q_OBJECT

public:
    QtHexGame(QWidget *parent = nullptr);
    ~QtHexGame();

protected:
    void do_connect_actions();

public slots:
    void on_actionInitGame_triggered();
    void update_next();

private:
    Ui::QtHexGameClass *ui;
};

