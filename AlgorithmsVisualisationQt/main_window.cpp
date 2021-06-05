#include "main_window.h"

main_window::main_window(QWidget *parent)
	: QWidget(parent)
{
	main_graph=generateRandomGraph<int>(1, 1, 1, 0);
	root = new Qt3DCore::QEntity();
	//left menu
	tab_menu_left = new QTabWidget(this);
	tab_menu_right = new QTabWidget(this);
	graph_menu_ = new graph_menu(this);
	sorting_menu_ = new sorting_menu(this);
	camera_menu_ = new camera_menu(this);
	light_menu_ = new light_menu(this);

	tab_menu_left->addTab(graph_menu_,"Graph");
	tab_menu_left->addTab(sorting_menu_, "Sort");
	tab_menu_left->setTabPosition(QTabWidget::TabPosition::West);


	//right menu
	stacked_menu_right = new QStackedLayout(tab_menu_right);
	scene_properties_common_graph_ = new scene_properties_common_graph(root,this);
	stacked_menu_right->addWidget(scene_properties_common_graph_);


	QWidget* menu_right = new QWidget(this);
	menu_right->setLayout(stacked_menu_right);

	tab_menu_right->addTab(menu_right, "Graph");
	tab_menu_right->addTab(camera_menu_, "Camera");
	tab_menu_right->addTab(light_menu_, "Light");
	tab_menu_right->setTabPosition(QTabWidget::TabPosition::East);
	//
	
	//visualisation window
	viewport_window_ = new viewport_window(root,this);
	//

	//main layout
	grid_layout_main = new QGridLayout;
	
	grid_layout_main->addWidget(tab_menu_left,0,0,Qt::AlignTop);
	grid_layout_main->addWidget(viewport_window_, 0, 1);

	grid_layout_main->addWidget(tab_menu_right, 0, 2, Qt::AlignTop);

	grid_layout_main->setColumnMinimumWidth(0, 100);
	grid_layout_main->setColumnStretch(0, 0);

	grid_layout_main->setColumnMinimumWidth(1, 300);
	grid_layout_main->setColumnStretch(1, 1);

	grid_layout_main->setColumnMinimumWidth(2, 100);
	grid_layout_main->setColumnStretch(2, 0);

	setLayout(grid_layout_main);
	//


	//from graph menu
	connect(graph_menu_, &graph_menu::regen_data_signal,this, &main_window::re_gen_graph);
	connect(graph_menu_, &graph_menu::graph_type_signal, this, &main_window::graph_type_changed_slot);

	connect(this, &main_window::type_graph_signal, scene_properties_common_graph_, &scene_properties_common_graph::scene_properties_common_graph_type_slot);
	
	//

	//connections between viewport and menu camera possitions
	connect(camera_menu_, &camera_menu::camera_possition_signal, viewport_window_, &viewport_window::viewport_camera_possition_slot);
	connect(camera_menu_, &camera_menu::camera_view_center_signal, viewport_window_, &viewport_window::viewport_camera_view_center_slot);
	connect(viewport_window_, &viewport_window::viewport_camera_position_signal, camera_menu_, &camera_menu::camera_possition_slot);
	connect(viewport_window_, &viewport_window::viewport_camera_view_center_signal, camera_menu_, &camera_menu::camera_view_center_slot);

	connect(camera_menu_, &camera_menu::camera_controller_signal, viewport_window_, &viewport_window::viewport_camera_controller_slot);

	connect(camera_menu_, &camera_menu::camera_view_all_signal, viewport_window_, &viewport_window::viewport_camera_view_all_slot);

	//light
	connect(light_menu_, &light_menu::light_color_signal, viewport_window_, &viewport_window::viewport_light_color_slot);
	connect(light_menu_, &light_menu::light_intencity_signal, viewport_window_, &viewport_window::viewport_light_intensity_slot);


}

main_window::~main_window()
{
}



