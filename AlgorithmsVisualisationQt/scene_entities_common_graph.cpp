#include "scene_entities_common_graph.h"

scene_entities_common_graph::scene_entities_common_graph(Qt3DCore::QEntity* root, QWidget* parent)
	: QWidget(parent)
{

	//rootEntity = new Qt3DCore::QEntity(root);
	rootEntity = root;
	plane = new Qt3DCore::QEntity(rootEntity);

	Qt3DCore::QTransform* planeTransform = new Qt3DCore::QTransform(rootEntity);
	planeTransform->setScale(1000.0f);
	planeTransform->setRotationX(90);
	plane->addComponent(planeTransform);

	Qt3DCore::QComponent* dummy_material = new Qt3DCore::QComponent(rootEntity);
	Qt3DCore::QComponent* dummy_mesh = new Qt3DCore::QComponent(rootEntity);

	vertex_material = dummy_material;
	edge_material = dummy_material;
	plane_material = dummy_material;
	vertex_mesh = dummy_mesh;

	plane_mesh = dummy_mesh;
	camera_controller = Q_NULLPTR;
	dummy_camera = new Qt3DRender::QCamera(rootEntity);

	/*for (auto& vertex : vertexes) {
		vertex->addComponent(vertex_material);
		vertex->addComponent(vertex_mesh);
	}

	for (auto& edge : edges) {
		edge->addComponent(edge_material);
		
	}*/

	plane->addComponent(plane_material);
	plane->addComponent(plane_mesh);

	//test sphere
	//auto mesh = new Qt3DExtras::QSphereMesh(rootEntity);
	//auto material = new Qt3DExtras::QPhongMaterial(rootEntity);
	//auto transform = new Qt3DCore::QTransform(rootEntity);
	//auto entity = new Qt3DCore::QEntity(rootEntity);

	//material->setAmbient(QColor(255, 255, 0));

	//transform->setTranslation(QVector3D(0,0,10));

	//mesh->setRadius(5);
	//mesh->setSlices(10);
	//mesh->setRings(10);

	//entity->addComponent(transform);
	//entity->addComponent(mesh);
	//entity->addComponent(material);

	//light
	auto light_main = new Qt3DCore::QEntity(rootEntity);
	auto point_light_main = new Qt3DRender::QPointLight(rootEntity);
	auto tansform_light_main = new Qt3DCore::QTransform(rootEntity);

	point_light_main->setColor(QColor(255, 255, 255));
	point_light_main->setIntensity(1.f);
	light_main->addComponent(point_light_main);
	light_main->addComponent(tansform_light_main);
}

scene_entities_common_graph::~scene_entities_common_graph()
{
}

Qt3DCore::QEntity* scene_entities_common_graph::getRoot()
{
	return rootEntity;
	
}
