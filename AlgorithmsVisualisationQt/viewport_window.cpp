#include "viewport_window.h"

viewport_window::viewport_window(Qt3DCore::QEntity* root,QWidget *parent)
	: QWidget(parent)
{
	

	window3d_main = new Qt3DExtras::Qt3DWindow();
	window3d_main->defaultFrameGraph()->setClearColor(QColor(0, 128, 128, 0));

	rootEntity = root;

	container=QWidget::createWindowContainer(window3d_main);

	QSize screenSize = window3d_main->screen()->size();
	container->setMinimumSize(QSize(128, 128));
	container->setMaximumSize(screenSize);

	currentSceneEntity = rootEntity;

	//Qt3DExtras::QTorusMesh* m_torus = new Qt3DExtras::QTorusMesh;
	//m_torus->setRadius(1.0f);
	//m_torus->setMinorRadius(0.4f);
	//m_torus->setRings(100);
	//m_torus->setSlices(20);

	////Qt3DCore::QTransform* torusTransform = new Qt3DCore::QTransform();
	////torusTransform->setScale(2.0f);
	////torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 25.0f));
	////torusTransform->setTranslation(QVector3D(5.0f, 4.0f, 0.0f));

	//Qt3DExtras::QPhongMaterial* torusMaterial = new Qt3DExtras::QPhongMaterial;
	//torusMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));

	//Qt3DCore::QEntity* m_torusEntity = new Qt3DCore::QEntity(currentSceneEntity);
	//Qt3DCore::QComponent* first_comp = m_torus;
	//Qt3DCore::QComponent* second_comp = torusMaterial;

	//m_torusEntity->addComponent(first_comp);
	//m_torusEntity->addComponent(second_comp);
	//m_torusEntity->addComponent(torusTransform);

	

	//camera
	camera_main = window3d_main->camera();
	camera_controller_main = new Qt3DExtras::QFirstPersonCameraController(currentSceneEntity);
	camera_controller_main->setCamera(camera_main);
	

	
	//light
	light_main = new Qt3DCore::QEntity(currentSceneEntity);
	point_light_main = new Qt3DRender::QPointLight(light_main);
	tansform_light_main = new Qt3DCore::QTransform(light_main);

	point_light_main->setColor(QColor(0, 0, 0));
	point_light_main->setIntensity(1.f);
	light_main->addComponent(point_light_main);
	light_main->addComponent(tansform_light_main);

	connect(camera_main, &Qt3DRender::QCamera::positionChanged, tansform_light_main, &Qt3DCore::QTransform::setTranslation);
	//

	window3d_main->setRootEntity(currentSceneEntity);

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



