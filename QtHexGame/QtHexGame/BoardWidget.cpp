#include <QPainter>
#include "BoardWidget.h"

const int N_HORZ = 4;
const int fr = 40;	//	上下左右空白

BoardWidget::BoardWidget(QWidget *parent)
	: QWidget(parent)
{
    // 囲碁盤っぽい緑系（例）
    QPalette pal = palette();                     // 現在の palette を取得
    pal.setColor(QPalette::Window, QColor("#f0f0c0"));
    setPalette(pal);
    // 重要：これがないと背景が描かれない子ウィジェットがある！
    setAutoFillBackground(true);
}

QPointF BoardWidget::xyToPoint(int x, int y) const {
	return QPointF(fr + m_cellWd * (x + y/2.0), fr + m_cellHt * y);
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
    const int LNWD = 4;
    painter.drawLine(xyToPoint(N_HORZ - 1, 0), xyToPoint(0, N_HORZ - 1));
    pen.setColor(Qt::black);            // 黒線
    pen.setWidth(LNWD+2);               // 線幅 px
    painter.setPen(pen);
	painter.drawLine(xyToPoint(0, 0), xyToPoint(0, N_HORZ-1));
    painter.drawLine(xyToPoint(N_HORZ - 1, 0), xyToPoint(N_HORZ - 1, N_HORZ - 1));
    pen.setColor(Qt::white);            // 白線
    pen.setWidth(LNWD);                 // 線幅 px
    painter.setPen(pen);
	painter.drawLine(xyToPoint(0, 0), xyToPoint(0, N_HORZ-1));
    painter.drawLine(xyToPoint(N_HORZ - 1, 0), xyToPoint(N_HORZ - 1, N_HORZ - 1));
    pen.setColor(Qt::black);            // 黒線
    pen.setWidth(LNWD+2);               // 線幅 px
    painter.setPen(pen);
	painter.drawLine(xyToPoint(0, 0), xyToPoint(N_HORZ-1, 0));
	painter.drawLine(xyToPoint(0, N_HORZ-1), xyToPoint(N_HORZ-1, N_HORZ-1));
	//
	drawStone(painter, 1, 2, BLACK);
	drawStone(painter, 2, 0, WHITE);
	drawStone(painter, 3, 0, BLACK);
	drawStone(painter, 2, 1, WHITE);
}
void BoardWidget::drawStone(QPainter& painter, int x, int y, Color col) const {
	double R = m_cellWd / 2 * 0.75;
	auto center = xyToPoint(x, y);
	// ──────────────────────────────
    // 1. ふわっとした影（一番簡単で綺麗！）
    // ──────────────────────────────
    QRadialGradient shadowGrad(center, R * 1.0);   // 影は石よりちょっと大きい
    shadowGrad.setColorAt(0.0, QColor(0, 0, 0, 80));   // 中心は濃いめ
    shadowGrad.setColorAt(0.6, QColor(0, 0, 0, 70));
    shadowGrad.setColorAt(1.0, QColor(0, 0, 0, 60));     // 外側

    painter.setPen(Qt::NoPen);
    painter.setBrush(shadowGrad);
    painter.setOpacity(0.8);                // 影全体の濃さ調整
    painter.drawEllipse(center+QPointF(R*0.1, R * 0.1), R * 1.0, R * 1.0);   // 石より一回り大きく描く
    painter.setOpacity(1.0);                // 戻しておく
    
    QPen pen;
    pen.setWidth(1);                    // 線幅 1px
    pen.setColor(Qt::black);            // 線色
    //pen.setColor(col == BLACK ? Qt::white : Qt::black);            // 線色
    painter.setPen(pen);
    painter.setBrush(QBrush(col == BLACK ? Qt::black : Qt::white));  // 黒 or 白色で塗りつぶし
    painter.drawEllipse(center, R, R);
}
