#include "property_camera_controller.h"

property_camera_controller::property_camera_controller(QString parentPath, QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	SETTINGS_INIT()
	combobox_camera_controller = new QComboBox;
	combobox_camera_controller->addItem("First Person Camera");
	combobox_camera_controller->addItem("Orbit Camera");

	connect(combobox_camera_controller, QOverload<int>::of(&QComboBox::currentIndexChanged),
		this, &property_camera_controller::property_camera_controller_type_signal);

	ADD_ENTITY(first_person);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, first_person, acceleration, Acceleration);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, first_person, deceleration, Deceleration);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, first_person, linear_speed, LinearSpeed);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, first_person, look_speed, LookSpeed);

	ADD_ENTITY(orbit);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, acceleration, Acceleration);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, deceleration, Deceleration);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, linear_speed, LinearSpeed);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, look_speed, LookSpeed);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, zoom_in_limit, ZoomInLimit);

	QStackedLayout* stacked_layout_camera_controller = new QStackedLayout;
	stacked_layout_camera_controller->addWidget(first_person_properties);
	stacked_layout_camera_controller->addWidget(orbit_properties);

	connect(combobox_camera_controller, QOverload<int>::of(&QComboBox::currentIndexChanged),
		    stacked_layout_camera_controller, &QStackedLayout::setCurrentIndex);

	connect(combobox_camera_controller, QOverload<int>::of(&QComboBox::currentIndexChanged),
		this, [&](int value) {
			QSettings settings;
			settings.setValue(QString(QString(parentPath_) + QString("current_camera_controller_type")), value);
		});

	combobox_camera_controller->setCurrentIndex(settings.value(QString(QString(parentPath_) + QString("current_camera_controller_type"))).toInt());

	QMetaObject::invokeMethod(this,
		"property_camera_controller_type_signal",
		Qt::QueuedConnection,
		Q_ARG(int, combobox_camera_controller->currentIndex()));
	
	QGridLayout* grid_layout_this = new QGridLayout;
	
	grid_layout_this->addWidget(new QLabel("Camera controller type:"), 0, 0, Qt::AlignTop);
	grid_layout_this->addWidget(combobox_camera_controller, 1, 0, Qt::AlignTop);
	grid_layout_this->addLayout(stacked_layout_camera_controller, 2, 0, Qt::AlignTop);

	setLayout(grid_layout_this);

}

property_camera_controller::~property_camera_controller()
{
}
