#include "property_light.h"

property_light::property_light(QString parentPath, QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	SETTINGS_INIT()
	combobox_light = new QComboBox(this);

	combobox_light->addItem("POINT");//id 0
	combobox_light->addItem("DIRECTIONAL");//id 1
	combobox_light->addItem("SPOT");//id 2

	connect(combobox_light, QOverload<int>::of(&QComboBox::currentIndexChanged),
		this, &property_light::property_light_type_signal);

	ADD_ENTITY(point);
	ADD_COLOR_PICKER_PROPERTY(light, point, color, Color);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, point, intensity, Intensity);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, point, constant_attenuation, constantAttenuation);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, point, linear_attenuation, linearAttenuation);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, point, quadratic_attenuation, quadraticAttenuation);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(light, point, possition, Possition);
	QPushButton* btn_light_point_possition_from_camera = new QPushButton("Set possition from camera", this);
	point_properties_layout->addWidget(btn_light_point_possition_from_camera,6,0,1, -1);
	connect(btn_light_point_possition_from_camera, &QAbstractButton::clicked,
		this, &property_light::property_light_possition_signal);


	ADD_ENTITY(directional);
	ADD_COLOR_PICKER_PROPERTY(light, directional, color, Color);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, directional, intensity, Intensity);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(light, directional, world_direction, Direction);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(light, directional, possition, Possition);
	QPushButton* btn_light_directional_possition_from_camera = new QPushButton("Set possition from camera", this);
	directional_properties_layout->addWidget(btn_light_directional_possition_from_camera, 4, 0,1, -1);
	connect(btn_light_directional_possition_from_camera, &QAbstractButton::clicked,
		this, &property_light::property_light_possition_signal);

	ADD_ENTITY(spot);
	ADD_COLOR_PICKER_PROPERTY(light, spot, color, Color);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, spot, intensity, Intensity);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, spot, constant_attenuation, constantAttenuation);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, spot, linear_attenuation, linearAttenuation);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, spot, quadratic_attenuation, quadraticAttenuation);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(light, spot, cut_off_angle, cutOffAngle);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(light, spot, local_direction, Direction);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(light, spot, possition, Possition);
	QPushButton* btn_light_spot_possition_from_camera = new QPushButton("Set possition from camera", this);
	spot_properties_layout->addWidget(btn_light_spot_possition_from_camera, 8, 0,1,-1);
	connect(btn_light_spot_possition_from_camera, &QAbstractButton::clicked,
		this, &property_light::property_light_possition_signal);
	
	QGridLayout* grid_layout_this = new QGridLayout;
	grid_layout_this->addWidget(new QLabel("light type:"), 0, 0, Qt::AlignTop);
	grid_layout_this->addWidget(combobox_light, 1, 0, Qt::AlignTop);

	QStackedLayout* stackedlayout_light = new QStackedLayout;
	stackedlayout_light->addWidget(point_properties);
	stackedlayout_light->addWidget(directional_properties);
	stackedlayout_light->addWidget(spot_properties);

	connect(combobox_light, QOverload<int>::of(&QComboBox::currentIndexChanged),
		stackedlayout_light, &QStackedLayout::setCurrentIndex);

	connect(combobox_light, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [&](int value) {
		QSettings settings;
		settings.setValue(QString(QString(parentPath_) + QString("current_light_index")), value);
		});

	combobox_light->setCurrentIndex(settings.value(QString(QString(parentPath_) + QString("current_light_index"))).toInt());

	grid_layout_this->addLayout(stackedlayout_light, 2, 0, Qt::AlignTop);

	setLayout(grid_layout_this);
}

property_light::~property_light()
{
}
