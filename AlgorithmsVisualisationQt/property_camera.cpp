#include "property_camera.h"

property_camera::property_camera(QString parentPath, QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	ADD_ENTITY(camera);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, aspect_ratio, AspectRatio, 0);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, bottom, Bottom, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, exposure, Exposure, 2);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, far_plane, FarPlane, 3);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, near_plane, NearPlane, 4);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, field_of_view, FieldOfView, 5);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, left, Left, 6);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, right, Right, 7);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, top, Top, 8);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(camera, camera, position, Position, 9);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(camera, camera, view_center, ViewCenter, 10);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(camera, camera, up_vector, UpVector, 11);

	btn_view_all = new QPushButton("View All", this);
	connect(btn_view_all, &QAbstractButton::clicked, this, [&, this] {camera_camera->viewAll(); });

	QGridLayout* grid_layout_this = new QGridLayout(this);
	grid_layout_this->setAlignment(Qt::AlignTop);
	grid_layout_this->addWidget(new QLabel("Camera settings:"), 0, 0, Qt::AlignTop);
	grid_layout_this->addWidget(camera_properties, 1, 0, Qt::AlignTop);
	grid_layout_this->addWidget(btn_view_all, 2, 0, Qt::AlignTop);

	setLayout(grid_layout_this);

}

property_camera::~property_camera()
{
}
