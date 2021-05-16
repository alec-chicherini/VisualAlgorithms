#include "viewport_window.h"

viewport_window::viewport_window(QWidget *parent)
	: QWidget(parent)
{
	
	window3d_main = new Qt3DExtras::Qt3DWindow();
	window3d_main->defaultFrameGraph()->setClearColor(QColor(0, 128, 128, 0));

	rootEntity = new Qt3DCore::QEntity();

	container=QWidget::createWindowContainer(window3d_main);

	QSize screenSize = window3d_main->screen()->size();
	container->setMinimumSize(QSize(128, 128));
	container->setMaximumSize(screenSize);

	//dummy 
	auto sphere_mesh = new Qt3DExtras::QSphereMesh;
	sphere_mesh->setRadius(1.0f);
	sphere_mesh->setRings(20);
	sphere_mesh->setSlices(20);

	auto sphere_material = new Qt3DExtras::QPhongMaterial;
	sphere_material->setDiffuse(QColor(0, 128, 0));

	Qt3DCore::QEntity* sphere_entity = new Qt3DCore::QEntity(rootEntity);
	sphere_entity->addComponent(sphere_mesh);
	sphere_entity->addComponent(sphere_material);

	//

	//camera
	camera_main = window3d_main->camera();
	camera_controller_main = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
	camera_controller_main->setCamera(camera_main);
	//
	
	//light
	light_main = new Qt3DCore::QEntity(rootEntity);
	point_light_main = new Qt3DRender::QPointLight(light_main);
	tansform_light_main = new Qt3DCore::QTransform(light_main);

	point_light_main->setColor(QColor(0, 0, 0));
	point_light_main->setIntensity(1.f);
	light_main->addComponent(point_light_main);
	light_main->addComponent(tansform_light_main);

	connect(camera_main, &Qt3DRender::QCamera::positionChanged, tansform_light_main, &Qt3DCore::QTransform::setTranslation);
	//

	window3d_main->setRootEntity(rootEntity);

	//this->setContentsMargins(0, 0, 0, 0);
	//this->setContentsMargins(1, 1, 1, 1);
	QGridLayout* gl = new QGridLayout;
	gl->setSpacing(0);
	gl->setContentsMargins(0, 0, 0, 0);
	gl->addWidget(container);

	setLayout(gl);
	
	connect(camera_main, &Qt3DRender::QCamera::positionChanged,
		this, [this](const QVector3D& vec)
		{
			if (camera_menu_possition_signal_was_recived)this->camera_menu_possition_signal_was_recived = false;
			else emit viewport_camera_position_signal(vec);
		}
	);

	connect(camera_main, &Qt3DRender::QCamera::viewVectorChanged,
		   this, [this](const QVector3D& vec)
	{
		if (camera_menu_view_center_signal_was_recived)this->camera_menu_view_center_signal_was_recived = false;
		else emit viewport_camera_view_center_signal(vec);
	}
	);

}

viewport_window::~viewport_window()
{
}

void viewport_window::update_common_graph(graph<int> g, std::underlying_type_t<GP> options)
{
	
	//Qt3DCore::QEntity* plane = new Qt3DCore::QEntity(rootEntity);
	
	QVector<Qt3DCore::QEntity*> vertexes; vertexes.resize(g.V.size());
	QVector<Qt3DCore::QEntity*> edges; edges.resize(g.E.size());
	for (auto& v : vertexes)
	{
		//update_components(v);
	}

	for (auto& e : edges)
	{
		//update_components(e);
	}

}


