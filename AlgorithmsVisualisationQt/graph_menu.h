#pragma once

#include <QWidget>

#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qstackedlayout.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qspinbox.h>
#include <qlabel.h>


class graph_menu : public QWidget
{
	Q_OBJECT

public:
	graph_menu(QWidget *parent = Q_NULLPTR);
	~graph_menu();



};
