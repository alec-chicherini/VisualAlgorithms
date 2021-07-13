#include "property_mesh.h"

property_mesh::property_mesh(QString parentPath,QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	SETTINGS_INIT()
	combobox_mesh = new QComboBox;
	
	combobox_mesh->addItem("CONE");//id 0
	combobox_mesh->addItem("CUBOID");//id 1
	combobox_mesh->addItem("CYLINDER");//id 2
	combobox_mesh->addItem("PLANE");//id 3
	combobox_mesh->addItem("SPHERE");//id 4
	combobox_mesh->addItem("TORUS");//id 5

	connect(combobox_mesh, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &property_mesh::property_mesh_type_signal);
	
		//Sphere
		ADD_ENTITY(sphere)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, sphere, radius, Radius)
		ADD_SPIN_BOX_PROPERTY(mesh, sphere, rings, Rings)
		ADD_SPIN_BOX_PROPERTY(mesh, sphere, slices, Slices)
		//
		
		//Cone
		ADD_ENTITY(cone)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cone, bottom_radius, BottomRadius)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cone, length, Length)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cone, top_radius, TopRadius)
		ADD_SPIN_BOX_PROPERTY(mesh, cone, rings, Rings)
		ADD_SPIN_BOX_PROPERTY(mesh, cone, slices, Slices)
		ADD_CHECK_BOX_PROPERTY(mesh, cone, has_bottom_endcap, hasBottomEndcap)
		ADD_CHECK_BOX_PROPERTY(mesh, cone, has_top_endcap, hasTopEndcap)
		//

		//Cuboid
		ADD_ENTITY(cuboid)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cuboid, x_extent, xExtent)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cuboid, y_extent, yExtent)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cuboid, z_extent, zExtent)
		//

		//Cylinder
		ADD_ENTITY(cylinder)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cylinder, length, Length)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cylinder, radius, Radius)
		ADD_SPIN_BOX_PROPERTY(mesh, cylinder, rings, Rings)
		ADD_SPIN_BOX_PROPERTY(mesh, cylinder, slices, Slices)
		//

		//Plane
		ADD_ENTITY(plane)
			ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, plane, height, Height)
			ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, plane, width, Width)
		//

		//Torus
		ADD_ENTITY(torus)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, torus, minor_radius, MinorRadius)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, torus, radius, Radius)
		ADD_SPIN_BOX_PROPERTY(mesh, torus, rings, Rings)
		ADD_SPIN_BOX_PROPERTY(mesh, torus, slices, Slices)
		//
		
	QGridLayout* grid_layout_this = new QGridLayout;
	grid_layout_this->addWidget(new QLabel("Mesh type:"), 0, 0, Qt::AlignTop);
	grid_layout_this->addWidget(combobox_mesh,1,0,Qt::AlignTop);

	QStackedLayout* stackedlayout_mesh = new QStackedLayout;
	stackedlayout_mesh->addWidget(cone_properties);//id 0
	stackedlayout_mesh->addWidget(cuboid_properties);//id 1
	stackedlayout_mesh->addWidget(cylinder_properties);//id 2
	stackedlayout_mesh->addWidget(plane_properties);//id 3
    stackedlayout_mesh->addWidget(sphere_properties);//id 4
	stackedlayout_mesh->addWidget(torus_properties);//id 5

	connect(combobox_mesh, QOverload<int>::of(&QComboBox::currentIndexChanged), stackedlayout_mesh, &QStackedLayout::setCurrentIndex);
	grid_layout_this->addLayout(stackedlayout_mesh,2,0,Qt::AlignTop);

	connect(combobox_mesh, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [&](int value) {
		QSettings settings;
		settings.setValue(QString(QString(parentPath_) + QString("current_mesh_index")), value);
		});

	combobox_mesh->setCurrentIndex(settings.value(QString(QString(parentPath_) + QString("current_mesh_index"))).toInt());

	setLayout(grid_layout_this);
}

property_mesh::~property_mesh()
{
}
