#include "scene_entities_common_graph.h"

scene_entities_common_graph::scene_entities_common_graph(Qt3DCore::QEntity* root, QWidget *parent)
	: QWidget(parent)
{

	rootEntity = new Qt3DCore::QEntity(root);

	vertex = new Qt3DCore::QEntity(rootEntity);
	edge = new Qt3DCore::QEntity(rootEntity);
	plane = new Qt3DCore::QEntity(rootEntity);



	Qt3DExtras::QTorusMesh* m_torus = new Qt3DExtras::QTorusMesh;
m_torus->setRadius(1.0f);
m_torus->setMinorRadius(0.4f);
m_torus->setRings(100);
m_torus->setSlices(20);

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

vertex_material = torusMaterial;
 vertex_mesh = m_torus;
 edge_material = torusMaterial;
 edge_mesh = m_torus;
 plane_material = torusMaterial;
 plane_mesh = m_torus;

	Qt3DCore::QComponent* dummy = new Qt3DCore::QComponent;

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
