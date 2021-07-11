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
#include "property_camera.h"
#include "viewport_window.h"
#include "property_light.h"

//different graphs scene properties
#include "scene_properties_common_graph.h"

//real world algorithms book
#include "../../Real_World_Algorithms/Real_World_Algorithms.h"

//debug
#include "qdebug_helper.h"

/// @brief The main window of app. Holds the three big parts.
/// @brief 1) Left menu widget - parts of book picker. Graphs algorithms, sorting algorithms and their settings.
/// @brief 2) Middle viewport widget - show Qt3D objects.
/// @brief 3) Right menu widget - show current properties of scene presenting in viewport.
class main_window : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	main_window(QWidget *parent = Q_NULLPTR);
	/// @brief default destructor
	~main_window();

private:
	
	Qt3DCore::QEntity* root;

	QGridLayout* grid_layout_main;
	QTabWidget* tab_menu_left;
	QStackedLayout* stacked_menu_right;
	QWidget* property_menu_right;
	graph_menu* graph_menu_;
	sorting_menu* sorting_menu_;
	viewport_window* viewport_window_;


	scene_properties_common_graph* scene_properties_common_graph_;

	int current_graph_type=0;
	graph<int> main_graph;
	under_GP current_graph_properties;

signals:
	/// @brief graph signal retranslation to pass the generated graph to entities in this 
	void type_graph_signal(int&, graph<int>&, under_GP&);
	
	
private slots:
	void re_gen_graph(const int V, const  int E_left, const  int E_right, const under_GP properties)
	{
		current_graph_properties = properties;
		//if (main_graph)
		//{
		//	main_graph->cleanup();
		//	delete main_graph;
		//};

		main_graph.cleanup();
		main_graph = generateRandomGraph<int>(V, E_left, E_right, properties);

		qDebug()<<QString::fromStdString(main_graph.print_to_string());

		emit type_graph_signal(current_graph_type, main_graph, current_graph_properties);
	
	}


	void graph_type_changed_slot(int id)
	{
	
		current_graph_type = id;
		qDebug() << " GRAPH TYPE CHANGED = " << id;
		switch(id)
		{
		case 0:qDebug()<<"Graph"; break; 
		case 1:qDebug()<<"Tree"; break;
		case 2:qDebug()<<"2D graph"; break;
		case 3:qDebug()<<"3D graph"; break;
		}

	}

};
