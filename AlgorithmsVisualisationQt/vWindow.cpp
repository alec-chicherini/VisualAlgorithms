#include "vWindow.h"

vWindow::vWindow(QWidget *parent)
	: QWidget(parent)
{
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

	camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
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


	container = createWindowContainer(view,this);
	container->setFixedSize(128, 128);
	container->setFocusPolicy(Qt::TabFocus);
	container->setContentsMargins(0, 0, 0, 0);

	QGridLayout* gl = new QGridLayout;
	gl->setSpacing(0);
	gl->setContentsMargins(0, 0, 0, 0);
	gl->addWidget(container);
	
	this->setContentsMargins(1, 1, 1, 1);

	setLayout(gl);

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
