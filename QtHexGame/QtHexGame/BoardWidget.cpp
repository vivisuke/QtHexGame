#include <QPainter>
#include "BoardWidget.h"

const int N_HORZ = 4;

void BoardWidget::paintEvent(QPaintEvent* event)
{
	double ww = width();
    double wh = height();

    QPainter painter(this);
    // アンチエイリアシング（滑らかに描画）
    painter.setRenderHint(QPainter::Antialiasing);
    // ペンの設定（線のカラー・太さ・スタイル）
    QPen pen;
    pen.setWidth(1);                    // 線幅 1px
    pen.setColor(Qt::black);            // 黒線
    pen.setCapStyle(Qt::RoundCap);      // 線の端を丸く
    pen.setJoinStyle(Qt::RoundJoin);    // 折れ線の接続部も丸く
    painter.setPen(pen);
    // ブラシの設定（塗りつぶし）
    painter.setBrush(QBrush(Qt::yellow));  // 黄色で塗りつぶし

    painter.drawLine(QPoint(0, 0), QPoint(ww, wh));
}
