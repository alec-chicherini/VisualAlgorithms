#include "main_window.h"

main_window::main_window(QWidget *parent)
	: QWidget(parent)
{
	//left menu
	tab_menu_left = new QTabWidget(this);
	graph_menu_ = new graph_menu(this);
	sorting_menu_ = new sorting_menu(this);
	camera_menu_ = new camera_menu(this);
	light_menu_ = new light_menu(this);

	tab_menu_left->addTab(graph_menu_,"Graph");
	tab_menu_left->addTab(sorting_menu_, "Sort");
	tab_menu_left->setTabPosition(QTabWidget::TabPosition::West);
	//
	
	//visualisation window
	viewport_window_ = new viewport_window(this);
	//


	//main layout
	grid_layout_main = new QGridLayout;
	
	grid_layout_main->addWidget(tab_menu_left,0,0,Qt::AlignTop);
	grid_layout_main->addWidget(viewport_window_, 0, 1);

	QGridLayout* gridlayout_menu_right = new QGridLayout;
	gridlayout_menu_right->setAlignment(Qt::AlignTop);
	gridlayout_menu_right->addWidget(camera_menu_, 0, 0, Qt::AlignTop);
	gridlayout_menu_right->addWidget(light_menu_, 1, 0, Qt::AlignTop);

	grid_layout_main->addLayout(gridlayout_menu_right, 0, 2, Qt::AlignTop);

	grid_layout_main->setColumnMinimumWidth(0, 100);
	grid_layout_main->setColumnStretch(0, 0);

	grid_layout_main->setColumnMinimumWidth(1, 300);
	grid_layout_main->setColumnStretch(1, 1);

	grid_layout_main->setColumnMinimumWidth(2, 100);
	grid_layout_main->setColumnStretch(2, 0);

	setLayout(grid_layout_main);
	//

	connect(graph_menu_, &graph_menu::regen_data_signal,this, &main_window::re_gen_graph);

	//connections between viewport and menu camera possitions
	connect(camera_menu_, &camera_menu::camera_possition_signal, viewport_window_, &viewport_window::viewport_camera_possition_slot);
	connect(camera_menu_, &camera_menu::camera_view_center_signal, viewport_window_, &viewport_window::viewport_camera_view_center_slot);
	connect(viewport_window_, &viewport_window::viewport_camera_position_signal, camera_menu_, &camera_menu::camera_possition_slot);
	connect(viewport_window_, &viewport_window::viewport_camera_view_center_signal, camera_menu_, &camera_menu::camera_view_center_slot);

	connect(camera_menu_, &camera_menu::camera_controller_signal, viewport_window_, &viewport_window::viewport_camera_controller_slot);

	//light
	connect(light_menu_, &light_menu::light_color_signal, viewport_window_, &viewport_window::viewport_light_color_slot);
	connect(light_menu_, &light_menu::light_intencity_signal, viewport_window_, &viewport_window::viewport_light_intensity_slot);

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
