#include "viewport_window.h"

viewport_window::viewport_window(Qt3DCore::QEntity* root,QWidget *parent)
	: QWidget(parent)
{
	

	window3d_main = new Qt3DExtras::Qt3DWindow();
	window3d_main->defaultFrameGraph()->setClearColor(QColor(0, 128, 128, 0));

	rootEntity = root;

	container=QWidget::createWindowContainer(window3d_main);

	QSize screenSize = window3d_main->
#if QT_VERSION == QT_VERSION_CHECK(6,1,0)
		screen()->
#endif
		size();
	container->setMinimumSize(QSize(128, 128));
	container->setMaximumSize(screenSize);

	currentSceneEntity = rootEntity;

	//camera
	camera_main = window3d_main->camera();
	camera_controller_main = new Qt3DExtras::QFirstPersonCameraController(currentSceneEntity);
	camera_controller_main->setCamera(camera_main);
	

	//light
	light_main = new Qt3DCore::QEntity(currentSceneEntity);
	point_light_main = new Qt3DRender::QPointLight(light_main);
	tansform_light_main = new Qt3DCore::QTransform(light_main);

	point_light_main->setColor(QColor(255, 255, 255));
	point_light_main->setIntensity(1.f);
	light_main->addComponent(point_light_main);
	light_main->addComponent(tansform_light_main);

	connect(camera_main, &Qt3DRender::QCamera::positionChanged, tansform_light_main, &Qt3DCore::QTransform::setTranslation);
	//

	window3d_main->setRootEntity(currentSceneEntity);

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



