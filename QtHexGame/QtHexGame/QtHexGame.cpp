#include "QtHexGame.h"
#include "Board.h"

Board *g_bd = nullptr;
Global g;

QtHexGame::QtHexGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtHexGameClass())
{
	g_bd = new Board(4);
    ui->setupUi(this);
    do_connect_actions();
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
	setFixedSize(900, 500);
}

QtHexGame::~QtHexGame()
{
    delete ui;
}

void QtHexGame::do_connect_actions() {
    connect(ui->action_Init, &QAction::triggered, 
        this, &QtHexGame::on_actionInitGame_triggered);
}

void QtHexGame::on_actionInitGame_triggered() {
	qDebug() << "QtHexGame::on_actionInitGame_triggered()";
	g.init();
	g_bd->init();
	ui->board->update();
}
