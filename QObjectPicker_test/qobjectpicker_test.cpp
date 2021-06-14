#include "qobjectpicker_test.h"


qobjectpicker_test::qobjectpicker_test(QWidget* parent)
	: QWidget(parent)
{
	
	rootEntity = new Qt3DCore::QEntity();
	
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
	//mouse
	Qt3DInput::QMouseDevice* mouse_device = new Qt3DInput::QMouseDevice(rootEntity);
	Qt3DInput::QMouseHandler* mouse_handler = new Qt3DInput::QMouseHandler(rootEntity);
	mouse_handler->setSourceDevice(mouse_device);
	
	picked_entity = Q_NULLPTR;

	Qt3DCore::QEntity* first_box = new Qt3DCore::QEntity(rootEntity);
	Qt3DCore::QEntity* second_box = new Qt3DCore::QEntity(rootEntity);

	Qt3DExtras::QPhongMaterial* material = new Qt3DExtras::QPhongMaterial(rootEntity);
	material->setAmbient(QColor(255, 128, 0));

	Qt3DExtras::QCuboidMesh* mesh = new Qt3DExtras::QCuboidMesh(rootEntity);
	mesh->setXExtent(3);
	mesh->setYExtent(3);
	mesh->setZExtent(3);

	auto* first_transform = new Qt3DCore::QTransform();
	first_transform->setTranslation(QVector3D(4.6394, -1.66462, 0.958794));

	auto* second_transform = new Qt3DCore::QTransform();
	second_transform->setTranslation(QVector3D(2.5291, -0.369929, -0.960943));

	auto* first_picker = new Qt3DRender::QObjectPicker();
	first_picker->setDragEnabled(true);
	//first_picker->setHoverEnabled(true);
	connect(first_picker, &Qt3DRender::QObjectPicker::moved,
		this, [&](Qt3DRender::QPickEvent* pick)
		{
			//qDebug() << "&Qt3DRender::QObjectPicker::moved";
			//qDebug() <<"pick->localIntersection()"<< pick->localIntersection();
			//qDebug() << "pick->worldIntersection()" << pick->worldIntersection();
			//qDebug() << pick->button();
			//qDebug() << pick->buttons();
			if (pick->buttons() == Qt3DRender::QPickEvent::LeftButton) 
			{
		
				QVector3D vec = pick->entity()->componentsOfType<Qt3DCore::QTransform>().front()->translation();
				qDebug() << "possition :" << vec;

				//qDebug() << "proj_debug(vec)" << proj_debug(vec);
				//qDebug() << "unproj_debug(vec)" << unproj_debug(vec);

				auto projected_ = proj_debug(vec);
				picked_projection_z = projected_.z();
				//qDebug() << "proj_debug(pick->worldIntersection())" << projected_;
				//qDebug() << "unproj_debug(pick->worldIntersection())" << unproj_debug(projected_);

				//qDebug() << "pick->distance()" << pick->distance();
				//qDebug() << "pick->position()" << pick->position();

				pick->entity()->
					componentsOfType<Qt3DCore::QTransform>().front()->
					setTranslation(unproj_debug(QVector3D(pick->position().x(), pick->position().y(), picked_projection_z)));
				
			}
				// vec = pick->entity()->componentsOfType<Qt3DCore::QTransform>().front()->translation();
				//qDebug() << "possition : " << vec;
			//	qDebug() << "Qt3DInput::QMouseHandler::moved";
			
		});
	
	//auto* second_picker = new Qt3DRender::QObjectPicker();

	connect(mouse_handler, &Qt3DInput::QMouseHandler::released,
		this, [&](Qt3DInput::QMouseEvent* mouse)
		{
		//	qDebug() << "Qt3DInput::QMouseHandler::released" << mouse->x() << mouse->y();

			if (picked_entity) {
				picked_entity->
					componentsOfType<Qt3DCore::QTransform>().front()->
					setTranslation(unproj_debug(QVector3D(mouse->x(), mouse->y(), picked_projection_z)));

				QVector3D vec = picked_entity->componentsOfType<Qt3DCore::QTransform>().front()->translation();
				qDebug() << "new possition vec " << vec;
				picked_entity = Q_NULLPTR;
			}

		});


	first_box->addComponent(material);
	first_box->addComponent(mesh);
	first_box->addComponent(first_transform);
	//first_box->addComponent(first_picker);

	second_box->addComponent(material);
	second_box->addComponent(mesh);
	second_box->addComponent(second_transform);
	//second_box->addComponent(second_picker);

	rootEntity->addComponent(first_picker);

	//Add container to show window as widget
	container = createWindowContainer(view, this);
	container->setFixedSize(128, 128);
	container->setFocusPolicy(Qt::TabFocus);
	container->setContentsMargins(0, 0, 0, 0);

	QGridLayout* layout = new QGridLayout;
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(container);

	btn_regen = new QPushButton("viewAll", this);
	connect(btn_regen, &QAbstractButton::clicked, camera, &Qt3DRender::QCamera::viewAll);
	layout->addWidget(btn_regen);

	this->setContentsMargins(1, 1, 1, 1);

	setLayout(layout);

	
	camera->viewAll();
}

qobjectpicker_test::~qobjectpicker_test()
{
}

void qobjectpicker_test::resizeEvent(QResizeEvent* event)
{
	container->setMaximumSize(4096, 4096);
	container->setMinimumSize(128, 128);

	/*auto value = this->y();
	OutputDebugStringW(LPCWSTR(std::to_wstring(value).c_str()));
	OutputDebugStringW(L" <----- this->y()\n");

	auto value2 = container->y();
	OutputDebugStringW(LPCWSTR(std::to_wstring(value2).c_str()));
	OutputDebugStringW(L" <----- container->y()\n");*/
}
