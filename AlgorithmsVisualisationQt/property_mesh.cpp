#include "property_mesh.h"

property_mesh::property_mesh(MeshType mt,QWidget *parent)
	: QWidget(parent)
{
	
	combobox_mesh = new QComboBox;
	
	combobox_mesh->addItem("CONE");//id 0
	combobox_mesh->addItem("CUBOID");//id 1
	combobox_mesh->addItem("CYLINDER");//id 2
	combobox_mesh->addItem("PLANE");//id 3
	combobox_mesh->addItem("SPHERE");//id 4
	combobox_mesh->addItem("TORUS");//id 5

	combobox_mesh->setCurrentIndex(static_cast<MeshType_under>(mt));

	//Sphere
	QWidget* sphere_properties = new QWidget(this);
	QGridLayout* sphere_properties_layout = new QGridLayout;
	sphere_properties_layout->setAlignment(Qt::AlignTop);

	sphere_properties_layout->addWidget(new QLabel("Radius:"), 0, 0);
	QDoubleSpinBox* spinbox_sphere_radius = new QDoubleSpinBox;
	sphere_properties_layout->addWidget(spinbox_sphere_radius, 0, 1);
	connect(spinbox_sphere_radius, &QDoubleSpinBox::valueChanged, this, &property_mesh::property_mesh_shpere_radius_signal);

	sphere_properties_layout->addWidget(new QLabel("Rings:"), 1, 0);
	QSpinBox* spinbox_sphere_rings = new QSpinBox;
	sphere_properties_layout->addWidget(spinbox_sphere_rings, 1, 1);
	connect(spinbox_sphere_rings, &QSpinBox::valueChanged, this, &property_mesh::property_mesh_shpere_rings_signal);

	sphere_properties_layout->addWidget(new QLabel("Slices:"), 2, 0);
	QSpinBox* spinbox_sphere_slices = new QSpinBox;
	sphere_properties_layout->addWidget(spinbox_sphere_slices, 2, 1);
	connect(spinbox_sphere_slices, &QSpinBox::valueChanged, this, &property_mesh::property_mesh_shpere_slices_signal);
	sphere_properties->setLayout(sphere_properties_layout);
	//

	//Cone
	QWidget* cone_properties = new QWidget(this);
	QGridLayout* cone_properties_layout = new QGridLayout;
	cone_properties_layout->setAlignment(Qt::AlignTop);

	cone_properties_layout->addWidget(new QLabel("Bottom radius:"), 0, 0);
	QDoubleSpinBox* spinbox_cone_bottom_radius = new QDoubleSpinBox;
	cone_properties_layout->addWidget(spinbox_cone_bottom_radius, 0, 1);
	connect(spinbox_cone_bottom_radius, &QDoubleSpinBox::valueChanged, this, &property_mesh::property_mesh_cone_bottom_radius_signal);

	cone_properties_layout->addWidget(new QLabel("Length:"), 1, 0);
	QDoubleSpinBox* spinbox_cone_length = new QDoubleSpinBox;
	cone_properties_layout->addWidget(spinbox_cone_length, 1, 1);
	connect(spinbox_cone_length, &QDoubleSpinBox::valueChanged, this, &property_mesh::property_mesh_cone_length_signal);

	cone_properties_layout->addWidget(new QLabel("Top radius:"), 2, 0);
	QDoubleSpinBox* spinbox_cone_top_radius = new QDoubleSpinBox;
	cone_properties_layout->addWidget(spinbox_cone_top_radius, 2, 1);
	connect(spinbox_cone_top_radius, &QDoubleSpinBox::valueChanged, this, &property_mesh::property_mesh_cone_top_radius_signal);

	cone_properties_layout->addWidget(new QLabel("Rings:"), 3, 0);
	QSpinBox* spinbox_cone_rings = new QSpinBox;
	cone_properties_layout->addWidget(spinbox_cone_rings, 3, 1);
	connect(spinbox_cone_rings, &QSpinBox::valueChanged, this, &property_mesh::property_mesh_cone_rings_signal);

	cone_properties_layout->addWidget(new QLabel("Slices:"), 4, 0);
	QSpinBox* spinbox_cone_slices = new QSpinBox;
	cone_properties_layout->addWidget(spinbox_cone_slices, 4, 1);
	connect(spinbox_cone_slices, &QSpinBox::valueChanged, this, &property_mesh::property_mesh_cone_slices_signal);

	cone_properties_layout->addWidget(new QLabel("hasBottomEndcap:"), 5, 0);
	QCheckBox* checkbox_cone_has_bottom_endcap = new QCheckBox;
	cone_properties_layout->addWidget(checkbox_cone_has_bottom_endcap, 5, 1);
	connect(checkbox_cone_has_bottom_endcap, &QCheckBox::stateChanged, this, &property_mesh::property_mesh_cone_has_bootom_endcap_signal);

	cone_properties_layout->addWidget(new QLabel("hasTopEndcap:"), 6, 0);
	QCheckBox* checkbox_cone_has_top_endcap = new QCheckBox;
	cone_properties_layout->addWidget(checkbox_cone_has_top_endcap, 6, 1);
	connect(checkbox_cone_has_top_endcap, &QCheckBox::stateChanged, this, &property_mesh::property_mesh_cone_has_top_endcap_signal);

	cone_properties->setLayout(cone_properties_layout);
	//
	// 
		//Cuboid
		ADD_ENTITY(cuboid)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh,cuboid, x_extent, xExtent, 0)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh,cuboid, y_extent, yExtent, 1)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh,cuboid, z_extent, zExtent, 2)
		//

		//Cylinder
		ADD_ENTITY(cylinder)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh,cylinder, length, Length, 0);
	    ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh,cylinder, radius, Radius, 1);
		ADD_SPIN_BOX_PROPERTY(mesh,cylinder, rings, Rings, 2);
		ADD_SPIN_BOX_PROPERTY(mesh,cylinder, slices, Slices, 3);
		//

		//Plane
		ADD_ENTITY(plane)
		ADD_SPIN_BOX_PROPERTY(mesh,plane, height, Height, 0);
		ADD_SPIN_BOX_PROPERTY(mesh,plane, width, Width, 1);
		//

		//Torus
		ADD_ENTITY(torus)
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh,torus, minor_radius, MinorRadius, 0);
		ADD_DOUBLE_SPIN_BOX_PROPERTY(mesh,torus, radius, Radius, 1);
		ADD_SPIN_BOX_PROPERTY(mesh,torus, rings, Rings, 2);
		ADD_SPIN_BOX_PROPERTY(mesh,torus, slices, Slices, 3);
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
	
	QGroupBox* groupbox_main = new QGroupBox;
	groupbox_main->setTitle("Mesh");
	groupbox_main->setLayout(grid_layout_this);
	

	QGridLayout* layout = new QGridLayout;
	layout->addWidget(groupbox_main);
	setLayout(layout);
}

property_mesh::~property_mesh()
{
}
