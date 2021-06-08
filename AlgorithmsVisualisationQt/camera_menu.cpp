#include "camera_menu.h"

camera_menu::camera_menu(QWidget *parent)
	: QWidget(parent)
{

	QGroupBox* groupbox_camera = new QGroupBox;

	spinbox_possition_x = new QDoubleSpinBox(this);
	spinbox_possition_y = new QDoubleSpinBox(this);
	spinbox_possition_z = new QDoubleSpinBox(this);
	spinbox_possition_x->setRange(-FLT_MAX, FLT_MAX);
	spinbox_possition_y->setRange(-FLT_MAX, FLT_MAX);
	spinbox_possition_z->setRange(-FLT_MAX, FLT_MAX);

	spinbox_view_center_x = new QDoubleSpinBox(this);
	spinbox_view_center_y = new QDoubleSpinBox(this);
	spinbox_view_center_z = new QDoubleSpinBox(this);
	spinbox_view_center_x->setRange(-FLT_MAX, FLT_MAX);
	spinbox_view_center_y->setRange(-FLT_MAX, FLT_MAX);
	spinbox_view_center_z->setRange(-FLT_MAX, FLT_MAX);

	spinbox_fov = new QSpinBox(this);
	spinbox_fov->setRange(1, 360);
	
	combobox_projection = new QComboBox(this);
	combobox_projection->addItem("Orthographic");
	combobox_projection->addItem("Perspective");

	combobox_camera_controller = new QComboBox(this);
	combobox_camera_controller->addItem("First Person Camera");
	combobox_camera_controller->addItem("Orbit Camera");

	QGridLayout* gridlayout_possition = new QGridLayout;
	gridlayout_possition->setAlignment(Qt::AlignTop);
	gridlayout_possition->setSpacing(1);
	gridlayout_possition->setColumnMinimumWidth(2, 50);

	gridlayout_possition->addWidget(new QLabel("Possition "), 0, 0, 1, 1);
	gridlayout_possition->addWidget(new QLabel("x:"), 0, 1, 1, 1,Qt::AlignRight);
	gridlayout_possition->addWidget(new QLabel("y:"), 1, 1, 1, 1, Qt::AlignRight);
	gridlayout_possition->addWidget(new QLabel("z:"), 2, 1, 1, 1, Qt::AlignRight);
	gridlayout_possition->addWidget(spinbox_possition_x, 0, 2, 1, 1);
	gridlayout_possition->addWidget(spinbox_possition_y, 1, 2, 1, 1);
	gridlayout_possition->addWidget(spinbox_possition_z, 2, 2, 1, 1);
	
	QGridLayout* gridlayout_viewcenter = new QGridLayout;
	gridlayout_viewcenter->setAlignment(Qt::AlignTop);
	gridlayout_viewcenter->setSpacing(1);
	gridlayout_viewcenter->setColumnMinimumWidth(2, 25);

	gridlayout_viewcenter->addWidget(new QLabel("View center "), 3, 0, 1, 1);
	gridlayout_viewcenter->addWidget(new QLabel("x:"), 3, 1, 1, 1, Qt::AlignRight);
	gridlayout_viewcenter->addWidget(new QLabel("y:"), 4, 1, 1, 1, Qt::AlignRight);
	gridlayout_viewcenter->addWidget(new QLabel("z:"), 5, 1, 1, 1, Qt::AlignRight);
	gridlayout_viewcenter->addWidget(spinbox_view_center_x, 3, 2, 1, 1);
	gridlayout_viewcenter->addWidget(spinbox_view_center_y, 4, 2, 1, 1);
	gridlayout_viewcenter->addWidget(spinbox_view_center_z, 5, 2, 1, 1);
	
	QGridLayout* gridlayout_fov = new QGridLayout;
	gridlayout_fov->addWidget(new QLabel("Field of view:"), 0, 0, 1, 1);
	gridlayout_fov->addWidget(spinbox_fov, 0, 1, 1, -1);
	gridlayout_fov->setColumnMinimumWidth(1, 25);

	pushbtn_camera_view_all = new QPushButton("View all", this);

	QGridLayout* gridlayout_this = new QGridLayout;
	gridlayout_this->addLayout(gridlayout_possition, 0, 0, 1, -1);
	gridlayout_this->addLayout(gridlayout_viewcenter, 1, 0, 1, -1);
	gridlayout_this->addLayout(gridlayout_fov, 2, 0, 1, -1);

	gridlayout_this->addWidget(new QLabel("Projection:"), 3, 0, 1, -1);
	gridlayout_this->addWidget(combobox_projection, 4, 0, 1, -1);

	gridlayout_this->addWidget(new QLabel("Controller:"), 5, 0, 1, -1);
	gridlayout_this->addWidget(combobox_camera_controller, 6, 0, 1, -1);

	gridlayout_this->addWidget(pushbtn_camera_view_all, 7, 0, 1, -1);
	
	groupbox_camera->setLayout(gridlayout_this);
	groupbox_camera->setTitle("Camera");
	groupbox_camera->setAlignment(Qt::AlignTop);
	
	QGridLayout* layout = new QGridLayout;
	layout->setAlignment(Qt::AlignTop);
	layout->addWidget(groupbox_camera);
	setLayout(layout);

	connect(spinbox_possition_x, QOverload<double>::of(&QDoubleSpinBox::valueChanged),this, &camera_menu::camera_possition_update_);
	connect(spinbox_possition_y, QOverload<double>::of(&QDoubleSpinBox::valueChanged),this, &camera_menu::camera_possition_update_);
	connect(spinbox_possition_z, QOverload<double>::of(&QDoubleSpinBox::valueChanged),this, &camera_menu::camera_possition_update_);

	connect(spinbox_view_center_x, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &camera_menu::camera_view_center_update_);
	connect(spinbox_view_center_y, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &camera_menu::camera_view_center_update_);
	connect(spinbox_view_center_z, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &camera_menu::camera_view_center_update_);

	connect(combobox_camera_controller, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &camera_menu::camera_controller_signal);

	connect(pushbtn_camera_view_all, &QAbstractButton::pressed, this, &camera_menu::camera_view_all_signal);

	//first initial init
	spinbox_possition_z->setValue(100.f);
	
	QMetaObject::invokeMethod(this,
		"camera_possition_signal",
		Qt::QueuedConnection,
		Q_ARG(QVector3D, QVector3D(0.,0.,100.)));
}

camera_menu::~camera_menu()
{
}
