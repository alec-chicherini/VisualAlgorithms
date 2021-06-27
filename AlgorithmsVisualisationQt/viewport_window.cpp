#include "viewport_window.h"

viewport_window::viewport_window(Qt3DCore::QEntity* root,QWidget *parent)
	: QWidget(parent)
{
	qDebug() << Q_FUNC_INFO << " CALLED !!! ";

	rootEntity = root;
	currentSceneEntity = rootEntity;

	window3d_main = new Qt3DExtras::Qt3DWindow();
	window3d_main->defaultFrameGraph()->setClearColor(QColor(0, 128, 128, 0));
	window3d_main->setRootEntity(currentSceneEntity);
	container = QWidget::createWindowContainer(window3d_main);

	QMetaObject::invokeMethod(this,
		"viewport_camera_signal",
		Qt::QueuedConnection,
		Q_ARG(Qt3DRender::QCamera*, window3d_main->camera()));

	qDebug() << window3d_main->camera() << "<<<<---window3d_main->camera() viewport ";
	

	QSize screenSize = window3d_main->
#if QT_VERSION == QT_VERSION_CHECK(6,1,0)
		screen()->
#endif
		size();
	container->setMinimumSize(QSize(128, 128));
	container->setMaximumSize(screenSize);

	QMetaObject::invokeMethod(this,
		"viewport_window_screen_size_signal",
		Qt::QueuedConnection,
		Q_ARG(Qt3DExtras::Qt3DWindow*, window3d_main));
	

	QGridLayout* gl = new QGridLayout;
	gl->setSpacing(0);
	gl->setContentsMargins(0, 0, 0, 0);
	gl->addWidget(container);

	setLayout(gl);
	
}

viewport_window::~viewport_window()
{
}



