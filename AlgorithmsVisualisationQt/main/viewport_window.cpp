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

//draw axys
	QVector3D center = { 0,0,0 };

	QVector3D vec_x = QVector3D(center.x() + size_axis, center.y(), center.z());
	auto x = std::make_pair(center, vec_x);
	line_axis_x->setPossition(x);

	QVector3D vec_y = QVector3D(center.x(), center.y() + size_axis, center.z());
	auto y = std::make_pair(center, vec_y);
	line_axis_y->setPossition(y);

	QVector3D vec_z = QVector3D(center.x(), center.y(), center.z() + size_axis);
	auto z = std::make_pair(center, vec_z);
	line_axis_z->setPossition(z);
	

	axis_x = new Qt3DCore::QEntity(rootEntity);
	axis_y = new Qt3DCore::QEntity(rootEntity);
	axis_z = new Qt3DCore::QEntity(rootEntity);

	auto material_axis = new Qt3DExtras::QPhongMaterial(rootEntity);
	material_axis->setAmbient(QColor(255, 255, 0));

	axis_x->addComponent(line_axis_x);
	axis_x->addComponent(material_axis);

	axis_y->addComponent(line_axis_y);
	axis_y->addComponent(material_axis);

	axis_z->addComponent(line_axis_z);
	axis_z->addComponent(material_axis);

	//connect(window3d_main->camera(), &Qt3DRender::QCamera::positionChanged, this, &viewport_window::draw_axis);
}



viewport_window::~viewport_window()
{
}



