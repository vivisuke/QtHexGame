#include <QPainter>
#include "BoardWidget.h"

const int N_HORZ = 4;
const int fr = 40;	//	上下左右空白

QPoint BoardWidget::xyToPoint(double x, double y) const {
	return QPoint(fr + m_cellWd * (x + y/2), fr + m_cellHt * y);
}

void BoardWidget::paintEvent(QPaintEvent* event)
{
	double ww = width();
    double wh = height();

	double w = width() - fr*2;
    double h = height() - fr*2;
    if (h < w / 3.0 * sqrt(3.0))
        w = h * 3.0 / sqrt(3.0);
    double w2 = w / 3.0;			//	上下辺長/2
    double bh = w2 * sqrt(3.0);
    m_cellWd = w2 * 2 / (N_HORZ - 1);
    m_cellHt = bh / (N_HORZ - 1);

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

    //painter.drawLine(QPoint(0, 0), QPoint(ww, wh));

    for(int i = 0; i < N_HORZ; ++i) {
    	painter.drawLine(xyToPoint(0, i), xyToPoint(N_HORZ-1, i));
    	painter.drawLine(xyToPoint(i, 0), xyToPoint(i, N_HORZ-1));
    }
    for(int i = 1; i < N_HORZ; ++i) {
    	painter.drawLine(xyToPoint(i, 0), xyToPoint(0, i));
        painter.drawLine(xyToPoint(N_HORZ - 1-i, N_HORZ - 1), xyToPoint(N_HORZ - 1, N_HORZ - 1-i));
    }
    painter.drawLine(xyToPoint(N_HORZ - 1, 0), xyToPoint(0, N_HORZ - 1));
    pen.setWidth(8);                    // 線幅 8px
    painter.setPen(pen);
	painter.drawLine(xyToPoint(0, 0), xyToPoint(N_HORZ-1, 0));
	painter.drawLine(xyToPoint(0, N_HORZ-1), xyToPoint(N_HORZ-1, N_HORZ-1));
}
