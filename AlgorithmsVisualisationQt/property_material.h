#pragma once

#include <QWidget>
#include "enums.h"

#include <qgroupbox.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qgridlayout.h>
#include <qstackedlayout.h>
#include <qcheckbox.h>
#include<qspinbox.h>
#include"color_picker.h"

#include "property_macros.h"


class property_material : public QWidget
{
	Q_OBJECT

public:
	property_material(MaterialType mt = MaterialType::PHONG, QWidget *parent = Q_NULLPTR);
	~property_material();

private:
	QComboBox* combobox_material;

signals:
	//PHONG
	ADD_SIGNAL_FOR_ENTITY(material, phong, ambient, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, phong, diffuse, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, phong, shininess, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, phong, specular, QColor);
	//

	//DIFFUSE_MAP
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_map, ambient, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_map, specular, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_map, shininess, double);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_map, texture_scale, double);
	//

	//DIFFUSE_SPECULAR_MAP
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular_map, ambient, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular_map, shininess, double);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular_map, texture_scale, double);
	//

	//DIFFUSE_SPECULAR
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular, alpha_blending, bool);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular, ambient, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular, diffuse, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular, specular, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular, shininess, double);
	ADD_SIGNAL_FOR_ENTITY(material, diffuse_specular, texture_scale, double);
	//
	
	//GOOCH
	ADD_SIGNAL_FOR_ENTITY(material, gooch, specular, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, gooch, warm, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, gooch, diffuse, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, gooch, cool, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, gooch, alpha, double);
	ADD_SIGNAL_FOR_ENTITY(material, gooch, beta, double);
	ADD_SIGNAL_FOR_ENTITY(material, gooch, shininess, double);
	//

	//METAL_ROUGH
	ADD_SIGNAL_FOR_ENTITY(material, metal_rough, base_color, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, metal_rough, texture_scale, double);
	//

	//MORPH_PHONG
	ADD_SIGNAL_FOR_ENTITY(material, morph_phong, ambient, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, morph_phong, diffuse, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, morph_phong, specular, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, morph_phong, shininess, double);
	ADD_SIGNAL_FOR_ENTITY(material, morph_phong, interpolator, double);
	//

	//NORMAL_DIFFUSE_MAP
	ADD_SIGNAL_FOR_ENTITY(material, normal_diffuse_map, ambient, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, normal_diffuse_map, specular, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, normal_diffuse_map, shininess, double);
	ADD_SIGNAL_FOR_ENTITY(material, normal_diffuse_map, texture_scale, double);
	//

	//NORMAL_DIFFUSE_SPECULAR_MAP
	ADD_SIGNAL_FOR_ENTITY(material, normal_diffuse_specular_map, ambient, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, normal_diffuse_specular_map, shininess, double);
	ADD_SIGNAL_FOR_ENTITY(material, normal_diffuse_specular_map, texture_scale, double);
	//

	//PHONG_ALPHA
	ADD_SIGNAL_FOR_ENTITY(material, phong_alpha, ambient, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, phong_alpha, diffuse, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, phong_alpha, specular, QColor);
	ADD_SIGNAL_FOR_ENTITY(material, phong_alpha, shininess, double);
	ADD_SIGNAL_FOR_ENTITY(material, phong_alpha, alpha, double);
	//

	//TEXTURE
	ADD_SIGNAL_FOR_ENTITY(material, texture, alpha_blending, bool);
	//

	

};