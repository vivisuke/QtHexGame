#pragma once
//#include "C:\Qt\6.10.0\msvc2022_64\include\QtWidgets\qwidget.h"
#include <qwidget.h>
#include "Board.h"

class BoardWidget :
    public QWidget
{
public:
    BoardWidget(QWidget *parent);
public:
	QPointF	xyToPoint(int x, int y) const;
	void	drawStone(QPainter&, int x, int y, Color col) const;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    double	m_cellWd;
    double	m_cellHt;
};

