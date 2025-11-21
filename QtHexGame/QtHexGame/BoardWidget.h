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

protected:
    void paintEvent(QPaintEvent* event) override;

};

