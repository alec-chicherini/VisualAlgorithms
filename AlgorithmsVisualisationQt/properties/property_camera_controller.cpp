#include "property_camera_controller.h"

property_camera_controller::property_camera_controller(QString parentPath, QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	combobox_camera_controller = new QComboBox;
	combobox_camera_controller->addItem("First Person Camera");
	combobox_camera_controller->addItem("Orbit Camera");

	connect(combobox_camera_controller, QOverload<int>::of(&QComboBox::currentIndexChanged),
		this, &property_camera_controller::property_camera_controller_type_signal);

	ADD_ENTITY(first_person);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, first_person, acceleration, Acceleration, 0);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, first_person, deceleration, Deceleration, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, first_person, linear_speed, LinearSpeed, 2);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, first_person, look_speed, LookSpeed, 3);

	ADD_ENTITY(orbit);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, acceleration, Acceleration, 0);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, deceleration, Deceleration, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, linear_speed, LinearSpeed, 2);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, look_speed, LookSpeed, 3);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera_controller, orbit, zoom_in_limit, ZoomInLimit, 4);

	QStackedLayout* stacked_layout_camera_controller = new QStackedLayout;
	stacked_layout_camera_controller->addWidget(first_person_properties);
	stacked_layout_camera_controller->addWidget(orbit_properties);

	connect(combobox_camera_controller, QOverload<int>::of(&QComboBox::currentIndexChanged),
		    stacked_layout_camera_controller, &QStackedLayout::setCurrentIndex);

	connect(combobox_camera_controller, QOverload<int>::of(&QComboBox::currentIndexChanged), 
		this, [&](int value) {
			read_write_current_camera_controller_type_json_(QIODevice::WriteOnly, "current_camera_controller_type", value); });

	combobox_camera_controller->setCurrentIndex(read_write_current_camera_controller_type_json_(QIODevice::ReadOnly, "current_camera_controller_type", int()).toInt());
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
