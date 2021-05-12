//deprecated viewport from first experiments. now using viewport_window.cpp

#include "vWindow.h"

vWindow::vWindow(QWidget *parent)
	: QWidget(parent)
{
	QFile load_config("graph_common_config.json");
	if (!load_config.open(QIODevice::ReadOnly)) 
	{
		qWarning("Couldn`t open config file.");
	
	}

	QByteArray config_data = load_config.readAll();
	QJsonDocument config(QJsonDocument::fromJson(config_data));

	QMessageBox msgBox;

	msgBox.setText(QString(config["info"].toString()));
	//msgBox.exec();

	rootEntity = new Qt3DCore::QEntity();

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

	view = new Qt3DExtras::Qt3DWindow();
	view->defaultFrameGraph()->setClearColor(QColor(0, 128, 128,0));
	
	camera = view->camera();
	camera->setPosition(QVector3D(0, 0, 10.f));
	camera->setViewCenter(QVector3D(0, 0, 0));

	camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
	camController->setCamera(camera);

	Qt3DCore::QEntity* lightEntity = new Qt3DCore::QEntity(rootEntity);
	Qt3DRender::QPointLight* light = new Qt3DRender::QPointLight(lightEntity);

	light->setColor(QColor(0, 0, 0));
	light->setIntensity(1.f);
	lightEntity->addComponent(light);
	Qt3DCore::QTransform* lightTransform = new Qt3DCore::QTransform(lightEntity);
	lightTransform->setTranslation(camera->position());
	lightEntity->addComponent(lightTransform);

	view->setRootEntity(rootEntity);
	//

	//Add container to show window as widget
	container = createWindowContainer(view,this);
	container->setFixedSize(128, 128);
	container->setFocusPolicy(Qt::TabFocus);
	container->setContentsMargins(0, 0, 0, 0);

	QGridLayout* layout = new QGridLayout;
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(container);
	
	this->setContentsMargins(1, 1, 1, 1);

	setLayout(layout);
	//
}

vWindow::~vWindow()
{
}

 void vWindow::resizeEvent(QResizeEvent* event) 
{
	 container->setMaximumSize(4096,4096);
	 container->setMinimumSize(128, 128);

	 auto value = this->y();
	 OutputDebugStringW(LPCWSTR(std::to_wstring(value).c_str()));
	 OutputDebugStringW(L" <----- this->y()\n");

	 auto value2 = container->y();
	 OutputDebugStringW(LPCWSTR(std::to_wstring(value2).c_str()));
	 OutputDebugStringW(L" <----- container->y()\n");
}
