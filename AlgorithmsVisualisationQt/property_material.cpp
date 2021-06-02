#include "property_material.h"

property_material::property_material(QString parentPath, QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	combobox_material = new QComboBox;

	combobox_material->addItem("PHONG");//id 0
	combobox_material->addItem("DIFFUSE_MAP");//id 1
	combobox_material->addItem("DIFFUSE_SPECULAR_MAP");//id 2
	combobox_material->addItem("DIFFUSE_SPECULAR");//id 3
	combobox_material->addItem("GOOCH");//id 4
	combobox_material->addItem("METAL_ROUGH");//id 5
	combobox_material->addItem("MORPH_PHONG");//id 6
	combobox_material->addItem("NORMAL_DIFFUSE_MAP");//id 7
	combobox_material->addItem("NORMAL_DIFFUSE_SPECULAR_MAP");//id 8
	combobox_material->addItem("PHONG_ALPHA");//id 9
	combobox_material->addItem("TEXTURE");//id 10

	connect(combobox_material, &QComboBox::currentIndexChanged, this, &property_material::property_material_type_signal);

	//PHONG
	/*QWidget* phong_properties = new QWidget(this);
	QGridLayout* phong_properties_layout = new QGridLayout;
	phong_properties_layout->setAlignment(Qt::AlignTop);
	phong_properties->setLayout(phong_properties_layout);

	color_picker* color_picker_phong_ambient = new color_picker("Ambient ");
	phong_properties_layout->addWidget(color_picker_phong_ambient, 0, 0);
	connect(color_picker_phong_ambient, &color_picker::color_picker_signal, this, &property_material::property_material_phong_ambient_signal);*/

	//PHONG
	ADD_ENTITY(phong)
	ADD_COLOR_PICKER_PROPERTY(material, phong, ambient, Ambient, 0);
	ADD_COLOR_PICKER_PROPERTY(material, phong, diffuse, Diffuse, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, phong, shininess, Shininess, 2);
	ADD_COLOR_PICKER_PROPERTY(material, phong, specular, Specular, 3);
	//


	//DIFFUSE_MAP
	ADD_ENTITY(diffuse_map)
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_map, ambient, Ambient, 0);
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_map, specular, Specular, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_map, shininess, Shininess, 2);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_map, texture_scale, TextureScale, 3);
	//

	//DIFFUSE_SPECULAR_MAP
	ADD_ENTITY(diffuse_specular_map)
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_specular_map, ambient, Ambient, 0);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_specular_map, shininess, Shininess, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_specular_map, texture_scale, TextureScale, 2);
	//

	//DIFFUSE_SPECULAR
	ADD_ENTITY(diffuse_specular)
	ADD_CHECK_BOX_PROPERTY(material, diffuse_specular, alpha_blending, AlphaBlending, 0);
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_specular, ambient, Ambient, 1);
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_specular, diffuse, Diffuse, 2);
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_specular, specular, Specular, 3);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_specular, shininess, Shininess, 4);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_specular, texture_scale, TextureScale, 5);
	//

	//GOOCH
	ADD_ENTITY(gooch)
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, gooch, alpha, Alpha, 0);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, gooch, beta, Beta, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, gooch, shininess, Shininess, 2);
	ADD_COLOR_PICKER_PROPERTY(material, gooch, specular, Specular, 3);
	ADD_COLOR_PICKER_PROPERTY(material, gooch, warm, Warm, 4);
	ADD_COLOR_PICKER_PROPERTY(material, gooch, diffuse, Diffuse, 5);
	ADD_COLOR_PICKER_PROPERTY(material, gooch, cool, Cool, 6);
	//
	
	//METAL_ROUGH
	ADD_ENTITY(metal_rough)
	ADD_COLOR_PICKER_PROPERTY(material, metal_rough, base_color, BaseColor, 0);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, metal_rough, texture_scale, TextureScale, 1);
	//

	//MORPH_PHONG
	ADD_ENTITY(morph_phong)
	ADD_COLOR_PICKER_PROPERTY(material, morph_phong, ambient, Ambient, 0);
	ADD_COLOR_PICKER_PROPERTY(material, morph_phong, diffuse, Diffuse, 1);
	ADD_COLOR_PICKER_PROPERTY(material, morph_phong, specular, Specular, 2);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, morph_phong, shininess, Shininess, 3);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, morph_phong, interpolator, Interpolator, 4);
	//

	//NORMAL_DIFFUSE_MAP
	ADD_ENTITY(normal_diffuse_map)
	ADD_COLOR_PICKER_PROPERTY(material, normal_diffuse_map, ambient, Ambient, 0);
	ADD_COLOR_PICKER_PROPERTY(material, normal_diffuse_map, specular, Specular, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, normal_diffuse_map, shininess, Shininess, 2);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, normal_diffuse_map, texture_scale, TextureScale, 3);
	//

	//NORMAL_DIFFUSE_SPECULAR_MAP
	ADD_ENTITY(normal_diffuse_specular_map)
	ADD_COLOR_PICKER_PROPERTY(material, normal_diffuse_specular_map, ambient, Ambient, 0);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, normal_diffuse_specular_map, shininess, Shininess, 1);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, normal_diffuse_specular_map, texture_scale, TextureScale, 2);
	//

	//PHONG_ALPHA
	ADD_ENTITY(phong_alpha)
	ADD_COLOR_PICKER_PROPERTY(material, phong_alpha, ambient, Ambient, 0);
	ADD_COLOR_PICKER_PROPERTY(material, phong_alpha, diffuse, Diffuse, 1);
	ADD_COLOR_PICKER_PROPERTY(material, phong_alpha, specular, Specular, 2);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, phong_alpha, shininess, Shininess, 3);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, phong_alpha, alpha, Alpha, 4);
	//

	//TEXTURE
	ADD_ENTITY(texture)
	ADD_CHECK_BOX_PROPERTY(material, texture, alpha_blending, AlphaBlending, 0);
	//
	


	QGridLayout* grid_layout_this = new QGridLayout;
	grid_layout_this->addWidget(new QLabel("Material type:"), 0, 0, Qt::AlignTop);
	grid_layout_this->addWidget(combobox_material, 1, 0, Qt::AlignTop);

	QStackedLayout* stackedlayout_material = new QStackedLayout;

	stackedlayout_material->addWidget(phong_properties);//id 0
	stackedlayout_material->addWidget(diffuse_map_properties);//id 1
	stackedlayout_material->addWidget(diffuse_specular_map_properties);//id 2
	stackedlayout_material->addWidget(diffuse_specular_properties);//id 3
	stackedlayout_material->addWidget(gooch_properties);//id 4
	stackedlayout_material->addWidget(metal_rough_properties);//id 5
	stackedlayout_material->addWidget(morph_phong_properties);//id 6
	stackedlayout_material->addWidget(normal_diffuse_map_properties);//id 7
	stackedlayout_material->addWidget(normal_diffuse_specular_map_properties);//id 8
	stackedlayout_material->addWidget(phong_alpha_properties);//id 9
	stackedlayout_material->addWidget(texture_properties);//id 10

	connect(combobox_material, &QComboBox::currentIndexChanged, stackedlayout_material, &QStackedLayout::setCurrentIndex);

	connect(combobox_material, &QComboBox::currentIndexChanged, this, [&](int value) {
		read_write_current_material_index_json_(QIODevice::WriteOnly, "current_material_index", value); });

	combobox_material->setCurrentIndex(read_write_current_material_index_json_(QIODevice::ReadOnly, "current_material_index", int()).toInt());
	
	grid_layout_this->addLayout(stackedlayout_material, 2, 0, Qt::AlignTop);

	setLayout(grid_layout_this);

}

property_material::~property_material()
{
}
