#pragma once

#include <QWidget>



//main layout
#include <qgridlayout.h>
#include <qtabwidget.h>

//main window widgets
#include "graph_menu.h"
#include "sorting_menu.h"
#include "vWindow.h"


class main_window : public QWidget
{
	Q_OBJECT

public:
	main_window(QWidget *parent = Q_NULLPTR);
	~main_window();

private:
	QGridLayout* grid_layout_main;
	QTabWidget* tab_menu_left;
	QWidget* graph_menu_;
	QWidget* sorting_menu_;
	QWidget* visualisation_window_;
	QPushButton* btn;
	



//protected:
//	virtual void resizeEvent(QResizeEvent* event)override;
};
