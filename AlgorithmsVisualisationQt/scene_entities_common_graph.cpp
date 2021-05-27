#include "scene_entities_common_graph.h"

scene_entities_common_graph::scene_entities_common_graph(Qt3DCore::QEntity* root, QWidget* parent)
	: QWidget(parent)
{

	rootEntity = new Qt3DCore::QEntity(root);

	plane = new Qt3DCore::QEntity(rootEntity);

	Qt3DCore::QTransform* planeTransform = new Qt3DCore::QTransform();
	planeTransform->setScale(1000.0f);
	planeTransform->setRotationX(90);
	plane->addComponent(planeTransform);

	Qt3DCore::QComponent* dummy_material = new Qt3DCore::QComponent;
	Qt3DCore::QComponent* dummy_mesh = new Qt3DCore::QComponent;

	vertex_material = dummy_material;
	edge_material = dummy_material;
	plane_material = dummy_material;
	vertex_mesh = dummy_mesh;

	plane_mesh = dummy_mesh;

	for (auto& vertex : vertexes) {
		vertex->addComponent(vertex_material);
		vertex->addComponent(vertex_mesh);
	}

	for (auto& edge : edges) {
		edge->addComponent(edge_material);
		
	}

	plane->addComponent(plane_material);
	plane->addComponent(plane_mesh);

}

scene_entities_common_graph::~scene_entities_common_graph()
{
}

Qt3DCore::QEntity* scene_entities_common_graph::getRoot()
{
	return rootEntity;
	
}
