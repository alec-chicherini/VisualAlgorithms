#include "property_mesh.h"

property_mesh::property_mesh(QString parentPath,QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	combobox_mesh = new QComboBox;
	
	combobox_mesh->addItem("CONE");//id 0
	combobox_mesh->addItem("CUBOID");//id 1
	combobox_mesh->addItem("CYLINDER");//id 2
	combobox_mesh->addItem("PLANE");//id 3
	combobox_mesh->addItem("SPHERE");//id 4
	combobox_mesh->addItem("TORUS");//id 5



	connect(combobox_mesh, &QComboBox::currentIndexChanged, this, &property_mesh::property_mesh_type_signal);

		//Sphere
		ADD_ENTITY(sphere)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, sphere, radius, Radius, 0)
		ADD_SPIN_BOX_PROPERTY(mesh, sphere, rings, Rings, 1)
		ADD_SPIN_BOX_PROPERTY(mesh, sphere, slices, Slices, 2)
		//
		 
		//Cone
		ADD_ENTITY(cone)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cone, bottom_radius, BottomRadius, 0)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cone, length, Length, 1)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cone, top_radius, TopRadius, 2)
		ADD_SPIN_BOX_PROPERTY(mesh, cone, rings, Rings, 3)
		ADD_SPIN_BOX_PROPERTY(mesh, cone, slices, Slices, 4)
		ADD_CHECK_BOX_PROPERTY(mesh, cone, has_bottom_endcap, hasBottomEndcap, 5)
		ADD_CHECK_BOX_PROPERTY(mesh, cone, has_top_endcap, hasTopEndcap, 6)
		//

		//Cuboid
		ADD_ENTITY(cuboid)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cuboid, x_extent, xExtent, 0)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cuboid, y_extent, yExtent, 1)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cuboid, z_extent, zExtent, 2)
		//

		//Cylinder
		ADD_ENTITY(cylinder)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cylinder, length, Length, 0)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, cylinder, radius, Radius, 1)
		ADD_SPIN_BOX_PROPERTY(mesh, cylinder, rings, Rings, 2)
		ADD_SPIN_BOX_PROPERTY(mesh, cylinder, slices, Slices, 3)
		//

		//Plane
		ADD_ENTITY(plane)
		ADD_SPIN_BOX_PROPERTY(mesh, plane, height, Height, 0)
		ADD_SPIN_BOX_PROPERTY(mesh, plane, width, Width, 1)
		//

		//Torus
		ADD_ENTITY(torus)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, torus, minor_radius, MinorRadius, 0)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh, torus, radius, Radius, 1)
		ADD_SPIN_BOX_PROPERTY(mesh, torus, rings, Rings, 2)
		ADD_SPIN_BOX_PROPERTY(mesh, torus, slices, Slices, 3)
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

	connect(combobox_mesh, &QComboBox::currentIndexChanged, stackedlayout_mesh, &QStackedLayout::setCurrentIndex);
	grid_layout_this->addLayout(stackedlayout_mesh,2,0,Qt::AlignTop);
	
	setLayout(grid_layout_this);
}

property_mesh::~property_mesh()
{
}
