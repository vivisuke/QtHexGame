#include "QtHexGame.h"

QtHexGame::QtHexGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtHexGameClass())
{
    ui->setupUi(this);
#if 0
    // 囲碁盤っぽい緑系（例）
    QPalette pal = palette();                     // 現在の palette を取得
    pal.setColor(QPalette::Window, QColor("#f0f0c0"));
    setPalette(pal);
    // 重要：これがないと背景が描かれない子ウィジェットがある！
    setAutoFillBackground(true);
#endif
	//centralWidget()->setContentsMargins(0, 0, 0, 0);
	if (QLayout *lay = centralWidget()->layout()) {
        lay->setContentsMargins(0, 0, 0, 0);
        lay->setSpacing(0);
    }
}

QtHexGame::~QtHexGame()
{
    delete ui;
}

