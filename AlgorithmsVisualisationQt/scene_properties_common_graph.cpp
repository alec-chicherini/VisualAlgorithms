#include "scene_properties_common_graph.h"

scene_properties_common_graph::scene_properties_common_graph(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout* layout=new QVBoxLayout;
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	property_mesh* pm = new property_mesh;
	property_material* pm2 = new property_material;
	property_material* pm3 = new property_material;

	layout->addWidget(pm);
	layout->addWidget(pm2);
	layout->addWidget(pm3);

	QWidget* this_widget = new QWidget(this);
	this_widget->setLayout(layout);
	this_widget->setContentsMargins(0, 0, 0, 0);
	
	scroll_area_common_graph = new QScrollArea(this);
	scroll_area_common_graph->setWidgetResizable(true);
	scroll_area_common_graph->setWidget(this_widget);
	scroll_area_common_graph->setAlignment(Qt::AlignLeft);
	scroll_area_common_graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scroll_area_common_graph->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scroll_area_common_graph->setFixedHeight(460);

	QVBoxLayout* layout_with_scroll_area = new QVBoxLayout;
	layout_with_scroll_area->addWidget(scroll_area_common_graph);
	layout_with_scroll_area->setSpacing(0);
	layout_with_scroll_area->setContentsMargins(0, 0, 0, 0);

	setLayout(layout_with_scroll_area);
	


}

scene_properties_common_graph::~scene_properties_common_graph()
{
}
