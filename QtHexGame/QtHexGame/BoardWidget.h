#pragma once
//#include "C:\Qt\6.10.0\msvc2022_64\include\QtWidgets\qwidget.h"
#include <qwidget.h>
#include "Board.h"

class BoardWidget : public QWidget
{
    //Q_OBJECT

public:
    BoardWidget(QWidget *parent);
public:
	QPointF	xyToPoint(int x, int y) const;
	void	drawStone(QPainter&, int x, int y, Color col) const;
	QPoint	posToXY(QPoint pos) const;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent *event) override;

//signals:
//    void	next_changed();

private slots:
    void on_actionInitGame_triggered();

private:
    double	m_cellWd;
    double	m_cellHt;
};

