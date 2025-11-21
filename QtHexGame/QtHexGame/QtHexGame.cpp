#include "QtHexGame.h"

QtHexGame::QtHexGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtHexGameClass())
{
    ui->setupUi(this);
}

QtHexGame::~QtHexGame()
{
    delete ui;
}

