#pragma once
//#include "C:\Qt\6.10.0\msvc2022_64\include\QtWidgets\qwidget.h"
#include <qwidget.h>

class BoardWidget :
    public QWidget
{
public:
    BoardWidget(QWidget *parent)
    	: QWidget(parent)
	{
	}
public:
	QPoint	xyToPoint(double x, double y) const;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    double	m_cellWd;
    double	m_cellHt;
};

