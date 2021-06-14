#include "main_window.h"

main_window::main_window(QWidget *parent)
	: QWidget(parent)
{
	main_graph=generateRandomGraph<int>(1, 1, 1, 0);
	root = new Qt3DCore::QEntity();
	qDebug() << root << "<<<<------------- root main_window PARENT VALUE ";

	//left menu
	tab_menu_left = new QTabWidget(this);
	graph_menu_ = new graph_menu(this);
	sorting_menu_ = new sorting_menu(this);

	tab_menu_left->addTab(graph_menu_,"Graph");
	tab_menu_left->addTab(sorting_menu_, "Sort");
	tab_menu_left->setTabPosition(QTabWidget::TabPosition::West);

	//visualisation window
	viewport_window_ = new viewport_window(root, this);
	//
	
	//right menu
	property_menu_right = new QWidget(this);
	stacked_menu_right = new QStackedLayout(property_menu_right);
	scene_properties_common_graph_ = new scene_properties_common_graph(root,this);
	stacked_menu_right->addWidget(scene_properties_common_graph_);
	property_menu_right->setLayout(stacked_menu_right);
	//
	


	//main layout
	grid_layout_main = new QGridLayout;
	
	grid_layout_main->addWidget(tab_menu_left,0,0,Qt::AlignTop);
	grid_layout_main->addWidget(viewport_window_, 0, 1);

	grid_layout_main->addWidget(property_menu_right, 0, 2, Qt::AlignTop);

	grid_layout_main->setColumnMinimumWidth(0, 100);
	grid_layout_main->setColumnStretch(0, 0);

	grid_layout_main->setColumnMinimumWidth(1, 300);
	grid_layout_main->setColumnStretch(1, 1);

	grid_layout_main->setColumnMinimumWidth(2, 100);
	grid_layout_main->setColumnStretch(2, 0);

	setLayout(grid_layout_main);
	//

	connect(viewport_window_, &viewport_window::viewport_window_screen_size_signal,
		scene_properties_common_graph_, &scene_properties_common_graph::scene_properties_common_graph_viewport_size_slot);

	//from graph menu
	connect(graph_menu_, &graph_menu::regen_data_signal,this, &main_window::re_gen_graph);
	connect(graph_menu_, &graph_menu::graph_type_signal, this, &main_window::graph_type_changed_slot);

	connect(this, &main_window::type_graph_signal, scene_properties_common_graph_, &scene_properties_common_graph::scene_properties_common_graph_type_slot);
	
	
	//connections between viewport and menu camera possitions
	connect(viewport_window_, &viewport_window::viewport_camera_signal, scene_properties_common_graph_, &scene_properties_common_graph::scene_properties_common_graph_camera_slot);
	//connect(property_camera_, &property_camera::camera_possition_signal, viewport_window_, &viewport_window::viewport_camera_possition_slot);
	//connect(property_camera_, &property_camera::camera_view_center_signal, viewport_window_, &viewport_window::viewport_camera_view_center_slot);
	//connect(viewport_window_, &viewport_window::viewport_camera_position_signal, property_camera_, &property_camera::camera_possition_slot);
	//connect(viewport_window_, &viewport_window::viewport_camera_view_center_signal, property_camera_, &property_camera::camera_view_center_slot);

	//connect(property_camera_, &property_camera::camera_controller_signal, viewport_window_, &viewport_window::viewport_camera_controller_slot);

	//connect(property_camera_, &property_camera::camera_view_all_signal, viewport_window_, &viewport_window::viewport_camera_view_all_slot);

	////light
	//connect(property_light_, &property_light::light_color_signal, viewport_window_, &viewport_window::viewport_light_color_slot);
	//connect(property_light_, &property_light::light_intencity_signal, viewport_window_, &viewport_window::viewport_light_intensity_slot);


	
}

main_window::~main_window()
{
}



