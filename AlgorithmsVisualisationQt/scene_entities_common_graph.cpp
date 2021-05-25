#include "scene_entities_common_graph.h"

scene_entities_common_graph::scene_entities_common_graph(Qt3DCore::QEntity* root, QWidget *parent)
	: QWidget(parent)
{

	rootEntity = new Qt3DCore::QEntity(root);

	vertex = new Qt3DCore::QEntity(rootEntity);
	edge = new Qt3DCore::QEntity(rootEntity);
	plane = new Qt3DCore::QEntity(rootEntity);


Qt3DCore::QTransform* vertexTransform = new Qt3DCore::QTransform();
vertexTransform->setScale(2.0f);
vertexTransform->setTranslation(QVector3D(10.0f, 10.0f, 0));
vertex->addComponent(vertexTransform);

Qt3DCore::QTransform* edgeTransform = new Qt3DCore::QTransform();
edgeTransform->setScale(2.0f);
edgeTransform->setTranslation(QVector3D(-10.0f, 4.0f, 0.0f));
edge->addComponent(edgeTransform);

Qt3DCore::QTransform* planeTransform = new Qt3DCore::QTransform();
planeTransform->setScale(2.0f);
planeTransform->setTranslation(QVector3D(-5.0f, 10.0f, 0.0f));
plane->addComponent(planeTransform);
Qt3DExtras::QPhongMaterial* torusMaterial = new Qt3DExtras::QPhongMaterial;
torusMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));


	Qt3DCore::QComponent* dummy_material = new Qt3DCore::QComponent;
	Qt3DCore::QComponent* dummy_mesh = new Qt3DCore::QComponent;

	vertex_material = dummy_material;
	edge_material = dummy_material;
	plane_material = dummy_material;
	vertex_mesh = dummy_mesh;
	edge_mesh = dummy_mesh;
	plane_mesh = dummy_mesh;

vertex->addComponent(vertex_material);
vertex->addComponent(vertex_mesh);
edge->addComponent(edge_material);
edge->addComponent(edge_mesh);
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
