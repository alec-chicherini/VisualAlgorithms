

#include "qlinemesh_test.h"


qlinemesh_test::qlinemesh_test(QWidget* parent)
	: QWidget(parent)
{

	rootEntity = new Qt3DCore::QEntity();
	
	//////////////////////////////////////////////////////////////////////////
	regen_lines();
	
	view = new Qt3DExtras::Qt3DWindow();
	view->defaultFrameGraph()->setClearColor(QColor(0, 128, 128, 0));

	camera = view->camera();
	camera->setPosition(QVector3D(0, 0, 10.f));
	camera->setViewCenter(QVector3D(0, 0, 0));
    camera->viewAll();

	camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
	camController->setCamera(camera);

	Qt3DCore::QEntity* lightEntity = new Qt3DCore::QEntity(rootEntity);
	Qt3DRender::QPointLight* light = new Qt3DRender::QPointLight(lightEntity);

	light->setColor(QColor(255, 255, 255));
	light->setIntensity(1.f);
	lightEntity->addComponent(light);
	Qt3DCore::QTransform* lightTransform = new Qt3DCore::QTransform(lightEntity);
	lightTransform->setTranslation(camera->position());
	lightEntity->addComponent(lightTransform);
	lightEntity->addComponent(light);

	view->setRootEntity(rootEntity);
	//

	//Add container to show window as widget
	container = createWindowContainer(view, this);
	container->setFixedSize(128, 128);
	container->setFocusPolicy(Qt::TabFocus);
	container->setContentsMargins(0, 0, 0, 0);

	QGridLayout* layout = new QGridLayout;
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(container);

	btn_regen = new QPushButton("ReGen", this);
	layout->addWidget(btn_regen);

	this->setContentsMargins(1, 1, 1, 1);

	setLayout(layout);
	//

	connect(btn_regen, &QAbstractButton::clicked, this, &qlinemesh_test::regen_lines);
}

qlinemesh_test::~qlinemesh_test()
{
}

void qlinemesh_test::resizeEvent(QResizeEvent* event)
{
	container->setMaximumSize(4096, 4096);
	container->setMinimumSize(128, 128);

	auto value = this->y();
	OutputDebugStringW(LPCWSTR(std::to_wstring(value).c_str()));
	OutputDebugStringW(L" <----- this->y()\n");

	auto value2 = container->y();
	OutputDebugStringW(LPCWSTR(std::to_wstring(value2).c_str()));
	OutputDebugStringW(L" <----- container->y()\n");
}
