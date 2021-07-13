#include "property_material.h"

property_material::property_material(QString parentPath, QWidget *parent)
	: QWidget(parent)
{
	parentPath_ = parentPath;
	SETTINGS_INIT()
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

	connect(combobox_material, QOverload<int>::of(&QComboBox::currentIndexChanged),
		    this, &property_material::property_material_type_signal);

	//PHONG
	ADD_ENTITY(phong)
	ADD_COLOR_PICKER_PROPERTY(material, phong, ambient, Ambient);
	ADD_COLOR_PICKER_PROPERTY(material, phong, diffuse, Diffuse);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, phong, shininess, Shininess);
	ADD_COLOR_PICKER_PROPERTY(material, phong, specular, Specular);
	//


	//DIFFUSE_MAP
	ADD_ENTITY(diffuse_map)
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_map, ambient, Ambient);
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_map, specular, Specular);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_map, shininess, Shininess);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_map, texture_scale, TextureScale);
	//

	//DIFFUSE_SPECULAR_MAP
	ADD_ENTITY(diffuse_specular_map)
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_specular_map, ambient, Ambient);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_specular_map, shininess, Shininess);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_specular_map, texture_scale, TextureScale);
	//

	//DIFFUSE_SPECULAR
	ADD_ENTITY(diffuse_specular)
	ADD_CHECK_BOX_PROPERTY(material, diffuse_specular, alpha_blending, AlphaBlending);
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_specular, ambient, Ambient);
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_specular, diffuse, Diffuse);
	ADD_COLOR_PICKER_PROPERTY(material, diffuse_specular, specular, Specular);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_specular, shininess, Shininess);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, diffuse_specular, texture_scale, TextureScale);
	//

	//GOOCH
	ADD_ENTITY(gooch)
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, gooch, alpha, Alpha);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, gooch, beta, Beta);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, gooch, shininess, Shininess);
	ADD_COLOR_PICKER_PROPERTY(material, gooch, specular, Specular);
	ADD_COLOR_PICKER_PROPERTY(material, gooch, warm, Warm);
	ADD_COLOR_PICKER_PROPERTY(material, gooch, diffuse, Diffuse);
	ADD_COLOR_PICKER_PROPERTY(material, gooch, cool, Cool);
	//
	
	//METAL_ROUGH
	ADD_ENTITY(metal_rough)
	ADD_COLOR_PICKER_PROPERTY(material, metal_rough, base_color, BaseColor);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, metal_rough, texture_scale, TextureScale);
	//

	//MORPH_PHONG
	ADD_ENTITY(morph_phong)
	ADD_COLOR_PICKER_PROPERTY(material, morph_phong, ambient, Ambient);
	ADD_COLOR_PICKER_PROPERTY(material, morph_phong, diffuse, Diffuse);
	ADD_COLOR_PICKER_PROPERTY(material, morph_phong, specular, Specular);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, morph_phong, shininess, Shininess);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, morph_phong, interpolator, Interpolator);
	//

	//NORMAL_DIFFUSE_MAP
	ADD_ENTITY(normal_diffuse_map)
	ADD_COLOR_PICKER_PROPERTY(material, normal_diffuse_map, ambient, Ambient);
	ADD_COLOR_PICKER_PROPERTY(material, normal_diffuse_map, specular, Specular);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, normal_diffuse_map, shininess, Shininess);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, normal_diffuse_map, texture_scale, TextureScale);
	//

	//NORMAL_DIFFUSE_SPECULAR_MAP
	ADD_ENTITY(normal_diffuse_specular_map)
	ADD_COLOR_PICKER_PROPERTY(material, normal_diffuse_specular_map, ambient, Ambient);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, normal_diffuse_specular_map, shininess, Shininess);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, normal_diffuse_specular_map, texture_scale, TextureScale);
	//

	//PHONG_ALPHA
	ADD_ENTITY(phong_alpha)
	ADD_COLOR_PICKER_PROPERTY(material, phong_alpha, ambient, Ambient);
	ADD_COLOR_PICKER_PROPERTY(material, phong_alpha, diffuse, Diffuse);
	ADD_COLOR_PICKER_PROPERTY(material, phong_alpha, specular, Specular);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, phong_alpha, shininess, Shininess);
	ADD_DOUBLE_SPIN_BOX_PROPERTY(material, phong_alpha, alpha, Alpha);
	//

	//TEXTURE
	ADD_ENTITY(texture)
	ADD_CHECK_BOX_PROPERTY(material, texture, alpha_blending, AlphaBlending);
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

	connect(combobox_material, QOverload<int>::of(&QComboBox::currentIndexChanged),
		stackedlayout_material, &QStackedLayout::setCurrentIndex);

	connect(combobox_material, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [&](int value) {
		QSettings settings;
		settings.setValue(QString(QString(parentPath_) + QString("current_material_index")), value); 
		});

	combobox_material->setCurrentIndex(settings.value(QString(QString(parentPath_) + QString("current_material_index"))).toInt());

	grid_layout_this->addLayout(stackedlayout_material, 2, 0, Qt::AlignTop);

	setLayout(grid_layout_this);

}

property_material::~property_material()
{
}
