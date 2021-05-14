#include "scene_properties_common_graph.h"

scene_properties_common_graph::scene_properties_common_graph(QWidget *parent)
	: QWidget(parent)
{
	QGridLayout* layout=new QGridLayout;
	
	property_mesh* pm = new property_mesh;
	property_material* pm2 = new property_material;

	layout->addWidget(pm,0,0);
	layout->addWidget(pm2, 1, 0);
	setLayout(layout);

}

scene_properties_common_graph::~scene_properties_common_graph()
{
}
