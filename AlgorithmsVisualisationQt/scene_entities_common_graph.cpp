#include "scene_entities_common_graph.h"

scene_entities_common_graph::scene_entities_common_graph(Qt3DCore::QEntity* root, QWidget* parent)
	: QWidget(parent)
{

	rootEntity = new Qt3DCore::QEntity(root);
	
	vertexes_root_entity = new Qt3DCore::QEntity(rootEntity);

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



	//transform->setTranslation(QVector3D(0,0,10));

	//mesh->setRadius(5);
	//mesh->setSlices(10);
	//mesh->setRings(10);

	//entity->addComponent(transform);
	//entity->addComponent(mesh);
	//entity->addComponent(material);

	//light
	//auto light_main = new Qt3DCore::QEntity(rootEntity);
	//auto point_light_main = new Qt3DRender::QPointLight(rootEntity);


	//point_light_main->setColor(QColor(0, 255, 0));
	//point_light_main->setIntensity(1.f);
	//light_main->addComponent(point_light_main);

	light = new Qt3DCore::QEntity(rootEntity);
	transform_light = new Qt3DCore::QTransform(rootEntity);
	transform_light->setTranslation(QVector3D(0, 0, 0));
	light->addComponent(transform_light);
	light_ = Q_NULLPTR;
	//object picker
	
	picker_scene = new Qt3DRender::QObjectPicker(vertexes_root_entity);
	picker_scene->setDragEnabled(true);
	vertexes_root_entity->addComponent(picker_scene);

	connect(picker_scene, &Qt3DRender::QObjectPicker::clicked,
		this, [&](Qt3DRender::QPickEvent* pick)
		{
			qDebug() << "Clicked";
		});

	connect(picker_scene, &Qt3DRender::QObjectPicker::moved,
		this, [&](Qt3DRender::QPickEvent* pick)
		{

			if (pick->buttons() == Qt3DRender::QPickEvent::LeftButton)
			{
				QVector3D possition_entity = pick->entity()->componentsOfType<Qt3DCore::QTransform>().front()->translation();

				QMatrix4x4 modelView, projection;
				modelView.lookAt(camera->position(), camera->viewCenter(), camera->upVector());
				projection.perspective(camera->fieldOfView(), camera->aspectRatio(), camera->nearPlane(), camera->farPlane());
				auto viewport = QRect(QPoint(0, 0), viewport_->size());

				auto z = possition_entity.project(modelView, projection, viewport).z();

				auto possition_pick = QVector3D(pick->position().x(), pick->position().y(), z);

				possition_pick.setY(viewport.height() - possition_pick.y());

				pick->entity()->componentsOfType<Qt3DCore::QTransform>().front()->
					            setTranslation(possition_pick.unproject(modelView, projection, viewport));

				update_edges_possitions(pick->entity());
			}

		}
	);
}

scene_entities_common_graph::~scene_entities_common_graph()
{
}

Qt3DCore::QEntity* scene_entities_common_graph::getRoot()
{
	return rootEntity;
	
}
