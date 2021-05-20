#pragma once

#include <QWidget>

//enums
#include"enums.h"

//main layout
#include <qgridlayout.h>
#include <qstackedlayout.h>
#include <qtabwidget.h>
#include <qscrollarea.h>
#include <qsizepolicy.h>

//main window widgets
#include "graph_menu.h"
#include "sorting_menu.h"
#include "camera_menu.h"
#include "viewport_window.h"
#include "light_menu.h"

//different graphs scene properties
#include "scene_properties_common_graph.h"

//real world algorithms book
#include "../Real_World_Algorithms.h"

//debug
#include "qdebug_helper.h"


class main_window : public QWidget
{
	Q_OBJECT

public:
	main_window(QWidget *parent = Q_NULLPTR);
	~main_window();

private:
	
	Qt3DCore::QEntity* root;

	QGridLayout* grid_layout_main;
	QTabWidget* tab_menu_left;
	QTabWidget* tab_menu_right;
	QStackedLayout* stacked_menu_right;

	graph_menu* graph_menu_;
	sorting_menu* sorting_menu_;
	viewport_window* viewport_window_;
	camera_menu* camera_menu_;
	light_menu* light_menu_;

	scene_properties_common_graph* scene_properties_common_graph_;

	int current_graph_type=0;
	graph<int>* main_graph=Q_NULLPTR;

signals:
	void type_graph_signal(int, graph<int>, under_GP);
	
private slots:
	void re_gen_graph(const int V, const  int E_left, const  int E_right, const under_GP properties)
	{
		if (main_graph)
		{
			main_graph->cleanup();
			delete main_graph;
		};

		main_graph =  new graph<int>(generateRandomGraph<int>(V, E_left, E_right, properties));

		qDebug()<<QString::fromStdString(main_graph->print_to_string());

		emit type_graph_signal(current_graph_type, *main_graph, properties);
	
	}


	void graph_type_changed_slot(int id)
	{
	
		current_graph_type = id;
		qDebug() << " GRAPH TYPE CHANGED = " << id;
		switch(id)
		{
		case 0: {tab_menu_right->setTabText(0, "Graph"); break; }
		case 1:tab_menu_right->setTabText(0, "Tree"); break;
		case 2:tab_menu_right->setTabText(0, "2D graph"); break;
		case 3:tab_menu_right->setTabText(0, "3D graph"); break;
		}

	}

};
