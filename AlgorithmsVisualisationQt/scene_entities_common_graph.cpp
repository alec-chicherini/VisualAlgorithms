#include "scene_entities_common_graph.h"

scene_entities_common_graph::scene_entities_common_graph(Qt3DCore::QEntity* root, QWidget *parent)
	: QWidget(parent)
{

	rootEntity = new Qt3DCore::QEntity(root);

	vertex = new Qt3DCore::QEntity(rootEntity);
	edge = new Qt3DCore::QEntity(rootEntity);
	plane = new Qt3DCore::QEntity(rootEntity);


	vertex_material = new Qt3DCore::QComponent;
	vertex_mesh = new Qt3DCore::QComponent;
	edge_material = new Qt3DCore::QComponent;
	edge_mesh = new Qt3DCore::QComponent;
	plane_material = new Qt3DCore::QComponent;
	plane_mesh = new Qt3DCore::QComponent;

}

scene_entities_common_graph::~scene_entities_common_graph()
{
}

Qt3DCore::QEntity* scene_entities_common_graph::getRoot()
{
	return rootEntity;
	
}
