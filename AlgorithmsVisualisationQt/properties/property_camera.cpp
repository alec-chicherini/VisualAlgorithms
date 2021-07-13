#include "property_camera.h"

property_camera::property_camera(QString parentPath, QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	SETTINGS_INIT()
	ADD_ENTITY(camera);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, aspect_ratio, AspectRatio);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, bottom, Bottom);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, exposure, Exposure);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, far_plane, FarPlane);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, near_plane, NearPlane);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, field_of_view, FieldOfView);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, left, Left);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, right, Right);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(camera, camera, top, Top);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(camera, camera, position, Position);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(camera, camera, view_center, ViewCenter);
	ADD_XYZ_PICKER_PROPERTY_DECLARATION(camera, camera, up_vector, UpVector);

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
