#include "graph_menu.h"

graph_menu::graph_menu(QWidget *parent)
	: QWidget(parent)
{
	//graph type group box
	gbox_graph_type = new QGroupBox("Graph type:");
	QRadioButton* rbtn_ve_graph = new QRadioButton("Classic graph");
	QRadioButton* rbtn_2d_graph = new QRadioButton("2D graph");
	btngroup_graph_type = new QButtonGroup;
	btngroup_graph_type->addButton(rbtn_ve_graph,0);
	btngroup_graph_type->addButton(rbtn_2d_graph,1);
	rbtn_ve_graph->setChecked(true);

	QVBoxLayout* gbox_layout_graph_type = new QVBoxLayout;
	gbox_layout_graph_type->addWidget(rbtn_ve_graph);
	gbox_layout_graph_type->addWidget(rbtn_2d_graph);
	gbox_layout_graph_type->addStretch(1);
	
	gbox_graph_type->setLayout(gbox_layout_graph_type);
	//

	//ve graph generate group box
	gbox_genereate_vegraph = new QGroupBox("Generate:");
	QPushButton* pbtn_generate_vegraph = new QPushButton("ReGen VE Graph");
	QVBoxLayout* gbox_layout_generate_vegraph = new QVBoxLayout;
	gbox_layout_generate_vegraph->addWidget(pbtn_generate_vegraph);
	gbox_genereate_vegraph->setLayout(gbox_layout_generate_vegraph);
	//

	//ve graph generate group box
	gbox_genereate_2dgraph = new QGroupBox("Generate:");
	QPushButton* pbtn_generate_2dgraph = new QPushButton("ReGen 2d Graph");
	QVBoxLayout* gbox_layout_generate_2dgraph = new QVBoxLayout;
	gbox_layout_generate_2dgraph->addWidget(pbtn_generate_2dgraph);
	gbox_genereate_2dgraph->setLayout(gbox_layout_generate_2dgraph);
	//

	//stacked layout
	stacked_layout_graphs = new QStackedLayout;
	stacked_layout_graphs->addWidget(gbox_genereate_vegraph);
	stacked_layout_graphs->addWidget(gbox_genereate_2dgraph);

	connect(btngroup_graph_type, &QButtonGroup::idClicked,
		    stacked_layout_graphs, &QStackedLayout::setCurrentIndex);
	//

	//main layout
	QGridLayout* grid_layout_main = new QGridLayout;
	grid_layout_main->addWidget(gbox_graph_type, 0, 0,Qt::AlignTop);
	grid_layout_main->addLayout(stacked_layout_graphs, 1, 0, Qt::AlignTop);

	setLayout(grid_layout_main);
	//


}



graph_menu::~graph_menu()
{
}
