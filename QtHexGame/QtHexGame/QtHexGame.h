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

private:
    Ui::QtHexGameClass *ui;
};

