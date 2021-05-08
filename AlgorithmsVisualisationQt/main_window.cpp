#include "main_window.h"

main_window::main_window(QWidget *parent)
	: QWidget(parent)
{
	//left menu
	tab_menu_left = new QTabWidget(this);
	graph_menu_ = new graph_menu(this);
	sorting_menu_ = new sorting_menu(this);

	tab_menu_left->addTab(graph_menu_,"Graph");
	tab_menu_left->addTab(sorting_menu_, "Sort");
	tab_menu_left->setTabPosition(QTabWidget::TabPosition::West);
	//
	

	//visualisation window
	visualisation_window_ = new vWindow(this);
	//

	btn = new QPushButton("1234567890");

	//main layout
	
	grid_layout_main = new QGridLayout;

	grid_layout_main->addWidget(tab_menu_left,0,0,Qt::AlignTop);
	grid_layout_main->addWidget(visualisation_window_, 0, 1);
	grid_layout_main->addWidget(btn, 0, 2, Qt::AlignTop);

	grid_layout_main->setColumnMinimumWidth(0, 100);
	grid_layout_main->setColumnStretch(0, 0);

	grid_layout_main->setColumnMinimumWidth(1, 300);
	grid_layout_main->setColumnStretch(1, 1);

	grid_layout_main->setColumnMinimumWidth(2, 100);
	grid_layout_main->setColumnStretch(2, 0);

	setLayout(grid_layout_main);
	//

}

main_window::~main_window()
{
}


//void main_window::resizeEvent(QResizeEvent* event)
//{
//
//
//	auto value = this->y();
//	OutputDebugStringW(LPCWSTR(std::to_wstring(value).c_str()));
//	OutputDebugStringW(L" <----- this->y()\n");
//
//	auto value2 = visualisation_window_->y();
//	OutputDebugStringW(LPCWSTR(std::to_wstring(value2).c_str()));
//	OutputDebugStringW(L" <----- visualisation_window_->y()\n");
//
//	auto value3 = tab_menu_left->y();
//	OutputDebugStringW(LPCWSTR(std::to_wstring(value3).c_str()));
//	OutputDebugStringW(L" <----- tab_menu_left->y()\n");
//}
