#include "graph_menu.h"

graph_menu::graph_menu(QWidget *parent)
	: QWidget(parent)
{
	//graph type group box
	QGroupBox* groupbox_graph_type = new QGroupBox("Graph type:");
	QRadioButton* radiobutton_graph = new QRadioButton("Graph");
	QRadioButton* radiobutton_2d_graph = new QRadioButton("2D graph");
	QRadioButton* radiobutton_3d_graph = new QRadioButton("3D graph");
	QRadioButton* radiobutton_tree_graph = new QRadioButton("Tree");

	QButtonGroup* btngroup_graph_type = new QButtonGroup;
	btngroup_graph_type->addButton(radiobutton_graph,0);//Graph is classic in commonly meaning
	btngroup_graph_type->addButton(radiobutton_tree_graph, 1);//Graph is tree
	btngroup_graph_type->addButton(radiobutton_2d_graph, 2);//Graph is like 2D field
	btngroup_graph_type->addButton(radiobutton_3d_graph, 3);//Graph is like 3D field
	radiobutton_graph->setChecked(true);

	QVBoxLayout* groupbox_layout_graph_type = new QVBoxLayout;
	groupbox_layout_graph_type->addWidget(radiobutton_graph);
	groupbox_layout_graph_type->addWidget(radiobutton_tree_graph);
	groupbox_layout_graph_type->addWidget(radiobutton_2d_graph);
	groupbox_layout_graph_type->addWidget(radiobutton_3d_graph);
	groupbox_layout_graph_type->addStretch(1);

	groupbox_graph_type->setLayout(groupbox_layout_graph_type);
	//
	 
	//graph properties group box
	QGroupBox* groupbox_graph_properties = new QGroupBox("Properties:");

    checkbox_directed = new QCheckBox("Directed");
    checkbox_weighted = new QCheckBox("Weighted");

	QButtonGroup* btngroup_graph_properties = new QButtonGroup;
	btngroup_graph_properties->setExclusive(false);
	btngroup_graph_properties->addButton(checkbox_directed, 0);//Graph is directed
	btngroup_graph_properties->addButton(checkbox_weighted, 1);//Graph is weighted

	QVBoxLayout* groupbox_layout_graph_properties = new QVBoxLayout;
	groupbox_layout_graph_properties->addWidget(checkbox_directed);
	groupbox_layout_graph_properties->addWidget(checkbox_weighted);

	groupbox_graph_properties->setLayout(groupbox_layout_graph_properties);
	//
	
	//common graph generate group box
	QGroupBox* groupbox_genereate_common_graph = new QGroupBox("Generate:");
	QPushButton* pushbutton_generate_common_grraph = new QPushButton("ReGen Graph");

	checkbox_loops = new QCheckBox("Loops");
	checkbox_connected = new QCheckBox("Connected");

	QLabel* label_vertex_num = new QLabel("Vertex number :");
	spinbox_vertex_num = new QSpinBox;
	label_vertex_num->setBuddy(spinbox_vertex_num);
	spinbox_vertex_num->setValue(5);
	

	QLabel* label_edges_num = new QLabel("Edges number :");
    spinbox_edges_num_left = new QSpinBox;
	spinbox_edges_num_left->setValue(1);
	spinbox_edges_num_left->setFixedWidth(35);
	label_edges_num->setBuddy(spinbox_edges_num_left);

	QLabel* label_edges_separator = new QLabel("-");
    spinbox_edges_num_right = new QSpinBox;
	spinbox_edges_num_right->setValue(3);
	spinbox_edges_num_right->setFixedWidth(35);
	label_edges_separator->setBuddy(spinbox_edges_num_right);


	connect(pushbutton_generate_common_grraph, &QAbstractButton::clicked,
		    this, &graph_menu::regen_graph_button_pushed);

	QGridLayout* groupbox_layout_generate_vegraph = new QGridLayout;

	groupbox_layout_generate_vegraph->addWidget(checkbox_loops, 0, 0, 1, -1, Qt::AlignTop);

	groupbox_layout_generate_vegraph->addWidget(checkbox_connected, 1, 0, 1, -1, Qt::AlignTop);

	groupbox_layout_generate_vegraph->addWidget(label_vertex_num, 2, 0, 1, -1, Qt::AlignTop);
	groupbox_layout_generate_vegraph->addWidget(spinbox_vertex_num, 3, 0, 1, -1, Qt::AlignTop);

	groupbox_layout_generate_vegraph->addWidget(label_edges_num, 4, 0, 1, -1, Qt::AlignTop);
	groupbox_layout_generate_vegraph->addWidget(spinbox_edges_num_left, 5, 0, 1, 1, Qt::AlignTop);
	groupbox_layout_generate_vegraph->addWidget(label_edges_separator, 5, 1, 1, 1, Qt::AlignTop);
	groupbox_layout_generate_vegraph->addWidget(spinbox_edges_num_right, 5, 2, 1, 1, Qt::AlignTop);

	groupbox_layout_generate_vegraph->addWidget(pushbutton_generate_common_grraph,6,0,1,-1,Qt::AlignTop);

	groupbox_genereate_common_graph->setLayout(groupbox_layout_generate_vegraph);
	//

	//2d graph generate group box
	QGroupBox* groupbox_genereate_2dgraph = new QGroupBox("Generate:");
	QPushButton* pbtn_generate_2dgraph = new QPushButton("ReGen 2d Graph");
	QVBoxLayout* groupbox_layout_generate_2dgraph = new QVBoxLayout;
	groupbox_layout_generate_2dgraph->addWidget(pbtn_generate_2dgraph);
	groupbox_genereate_2dgraph->setLayout(groupbox_layout_generate_2dgraph);
	//

	//3d graph generate group box
	QGroupBox* groupbox_genereate_3dgraph = new QGroupBox("Generate:");
	QPushButton* pbtn_generate_3dgraph = new QPushButton("ReGen 3d Graph");
	QVBoxLayout* groupbox_layout_generate_3dgraph = new QVBoxLayout;
	groupbox_layout_generate_3dgraph->addWidget(pbtn_generate_3dgraph);
	groupbox_genereate_3dgraph->setLayout(groupbox_layout_generate_3dgraph);
	//

	//treed graph generate group box
	QGroupBox* groupbox_genereate_tree_graph = new QGroupBox("Generate:");
	QPushButton* pbtn_generate_tree_graph = new QPushButton("ReGen tree Graph");
	QVBoxLayout* groupbox_layout_generate_tree_graph = new QVBoxLayout;
	groupbox_layout_generate_tree_graph->addWidget(pbtn_generate_tree_graph);
	groupbox_genereate_tree_graph->setLayout(groupbox_layout_generate_tree_graph);
	//

	//stacked layout for generate menu
	QStackedLayout* stacked_layout_graphs_generate = new QStackedLayout;
	stacked_layout_graphs_generate->addWidget(groupbox_genereate_common_graph);//id 0
	stacked_layout_graphs_generate->addWidget(groupbox_genereate_tree_graph);//id 1
	stacked_layout_graphs_generate->addWidget(groupbox_genereate_2dgraph);//id 2
	stacked_layout_graphs_generate->addWidget(groupbox_genereate_3dgraph);//id 3

	connect(btngroup_graph_type,   &QButtonGroup::idClicked,
		    stacked_layout_graphs_generate, &QStackedLayout::setCurrentIndex);
	//

	//main layout
	QGridLayout* grid_layout_main = new QGridLayout;
	grid_layout_main->addWidget(groupbox_graph_type, 0, 0,Qt::AlignTop);
	grid_layout_main->addWidget(groupbox_graph_properties, 1, 0, Qt::AlignTop);
	grid_layout_main->addLayout(stacked_layout_graphs_generate, 2, 0, Qt::AlignTop);

	setLayout(grid_layout_main);
	//
}



graph_menu::~graph_menu()
{
}
