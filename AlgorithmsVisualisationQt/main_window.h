#pragma once

#include <QWidget>

//enums
#include"enums.h"

//main layout
#include <qgridlayout.h>
#include <qtabwidget.h>

//main window widgets
#include "graph_menu.h"
#include "sorting_menu.h"
#include "vWindow.h"

//real world algorithms book
#include "../Real_World_Algorithms.h"

#include <qmessagebox.h>





class main_window : public QWidget
{
	Q_OBJECT

public:
	main_window(QWidget *parent = Q_NULLPTR);
	~main_window();

private:
	QGridLayout* grid_layout_main;
	QTabWidget* tab_menu_left;
	graph_menu* graph_menu_;
	sorting_menu* sorting_menu_;
	vWindow* visualisation_window_;
	QPushButton* btn;

	graph<int>* main_graph=Q_NULLPTR;
	
//protected:
//	virtual void resizeEvent(QResizeEvent* event)override;

public slots:
	void re_gen_graph(const int V, const  int E_left, const  int E_right, const under_GP properties)
	{
		if (main_graph)
		{
			main_graph->cleanup();
			delete main_graph;
		};

		main_graph =  new graph<int>(generateRandomGraph<int>(V, E_left, E_right, properties));

		QMessageBox msgBox;

		msgBox.setText(QString().fromStdString(main_graph->print_to_string()));
		msgBox.exec();
	}
};
