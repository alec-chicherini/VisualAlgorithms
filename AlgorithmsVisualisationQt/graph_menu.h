#pragma once

#include <QWidget>

#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qstackedlayout.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>
#include <qpushbutton.h>

class graph_menu : public QWidget
{
	Q_OBJECT

public:
	graph_menu(QWidget *parent = Q_NULLPTR);
	~graph_menu();

private:
	
	QGroupBox* gbox_graph_type;
	QButtonGroup* btngroup_graph_type;
	QStackedLayout* stacked_layout_graphs;

	QGroupBox* gbox_genereate_vegraph;
	QGroupBox* gbox_genereate_2dgraph;

};
