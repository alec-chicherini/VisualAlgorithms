#pragma once

#include <QWidget>

#include <Qt3DExtras/qphongalphamaterial.h>
#include <Qt3DExtras/qphongmaterial.h>
#include <Qt3DExtras/qdiffusemapmaterial.h>
#include <Qt3DExtras/qdiffusespecularmapmaterial.h>
#include <Qt3DExtras/qdiffusespecularmaterial.h>
#include <Qt3DExtras/qgoochmaterial.h>
#include <Qt3DExtras/qmetalroughmaterial.h>
#include <Qt3DExtras/qtexturematerial.h>
#include <Qt3DExtras/qnormaldiffusemapalphamaterial.h>
#include <Qt3DExtras/qnormaldiffusemapmaterial.h>
#include <Qt3DExtras/qnormaldiffusespecularmapmaterial.h>
#include <Qt3DExtras/qmorphphongmaterial.h>

#include <Qt3DExtras/qconemesh.h>
#include <Qt3DExtras/qcuboidmesh.h>
#include <Qt3DExtras/qcylindermesh.h>
#include <Qt3DExtras/qplanemesh.h>
#include <Qt3DExtras/qspheremesh.h>
#include <Qt3DExtras/qtorusmesh.h>

#include "property_macros.h"


class component_states : public QWidget
{
	Q_OBJECT

public:
	component_states(QWidget *parent = Q_NULLPTR);
	~component_states();

private:
	//all in app materials
	Qt3DExtras::QPhongMaterial* material_phong;//id 0
	Qt3DExtras::QDiffuseMapMaterial* material_diffuse_map;//id 1
	Qt3DExtras::QDiffuseSpecularMapMaterial* material_diffuse_specular_map;//id 2
	Qt3DExtras::QDiffuseSpecularMaterial* material_diffuse_specular;//id 3
	Qt3DExtras::QGoochMaterial* material_gooch;//id 4
	Qt3DExtras::QMetalRoughMaterial* material_metal_rough;//id 5
	Qt3DExtras::QMorphPhongMaterial* material_morph_phong;//id 6
	Qt3DExtras::QNormalDiffuseMapMaterial* material_normal_diffuse_map;//id 7
	Qt3DExtras::QNormalDiffuseSpecularMapMaterial* material_normal_diffuse_specular_map;//id 8
	Qt3DExtras::QPhongAlphaMaterial* material_phong_alpha;//id 9
	Qt3DExtras::QTextureMaterial* material_texture;//id 10

	int current_material = 0;


	//all in app meshes
	Qt3DExtras::QConeMesh* mesh_cone;//id 0
	Qt3DExtras::QCuboidMesh* mesh_cuboid;//id 1
	Qt3DExtras::QCylinderMesh* mesh_cylinder;//id 2
	Qt3DExtras::QPlaneMesh* mesh_plane;//id 3
	Qt3DExtras::QSphereMesh* mesh_sphere;//id 4
	Qt3DExtras::QTorusMesh* mesh_torus;//id 5
	int current_mesh = 0;

public slots:
	

	void property_material_type_slot(int id)
	{
		current_material = id;
		qDebug() << __FUNCSIG__ << " CALLED !!! "; 
	}

	void property_mesh_type_slot(int id)
	{
		current_mesh = id;
		qDebug() << __FUNCSIG__ << " CALLED !!! "; 
	}
	
	//material slots
	
	//PHONG
	ADD_SLOT_FOR_ENTITY(material, phong, ambient, setAmbient, QColor);
	ADD_SLOT_FOR_ENTITY(material, phong, diffuse, setDiffuse, QColor);
	ADD_SLOT_FOR_ENTITY(material, phong, shininess, setShininess, double);
	ADD_SLOT_FOR_ENTITY(material, phong, specular, setSpecular, QColor);
	//

	//DIFFUSE_MAP
	ADD_SLOT_FOR_ENTITY(material, diffuse_map, ambient, setAmbient, QColor);
	ADD_SLOT_FOR_ENTITY(material, diffuse_map, specular, setSpecular, QColor);
	ADD_SLOT_FOR_ENTITY(material, diffuse_map, shininess, setShininess, double);
	ADD_SLOT_FOR_ENTITY(material, diffuse_map, texture_scale, setTextureScale, double);
	//

	//DIFFUSE_SPECULAR_MAP
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular_map, ambient, setAmbient, QColor);
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular_map, shininess, setShininess, double);
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular_map, texture_scale, setTextureScale, double);
	//

	//DIFFUSE_SPECULAR
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular, alpha_blending, setAlphaBlendingEnabled, bool);
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular, ambient, setAmbient, QColor);
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular, diffuse, setDiffuse, QColor);
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular, specular, setSpecular, QColor);
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular, shininess, setShininess, double);
	ADD_SLOT_FOR_ENTITY(material, diffuse_specular, texture_scale, setTextureScale, double);
	//

	//GOOCH
	ADD_SLOT_FOR_ENTITY(material, gooch, specular, setSpecular, QColor);
	ADD_SLOT_FOR_ENTITY(material, gooch, warm, setWarm, QColor);
	ADD_SLOT_FOR_ENTITY(material, gooch, diffuse, setDiffuse, QColor);
	ADD_SLOT_FOR_ENTITY(material, gooch, cool, setCool, QColor);
	ADD_SLOT_FOR_ENTITY(material, gooch, alpha, setAlpha, double);
	ADD_SLOT_FOR_ENTITY(material, gooch, beta, setBeta, double);
	ADD_SLOT_FOR_ENTITY(material, gooch, shininess, setShininess, double);
	//

	//METAL_ROUGH
	ADD_SLOT_FOR_ENTITY(material, metal_rough, base_color, setBaseColor, QColor);
	ADD_SLOT_FOR_ENTITY(material, metal_rough, texture_scale, setTextureScale, double);
	//

	//MORPH_PHONG
	ADD_SLOT_FOR_ENTITY(material, morph_phong, ambient, setAmbient, QColor);
	ADD_SLOT_FOR_ENTITY(material, morph_phong, diffuse, setDiffuse, QColor);
	ADD_SLOT_FOR_ENTITY(material, morph_phong, specular, setSpecular, QColor);
	ADD_SLOT_FOR_ENTITY(material, morph_phong, shininess, setShininess, double);
	ADD_SLOT_FOR_ENTITY(material, morph_phong, interpolator, setInterpolator, double);
	//

	//NORMAL_DIFFUSE_MAP
	ADD_SLOT_FOR_ENTITY(material, normal_diffuse_map, ambient, setAmbient, QColor);
	ADD_SLOT_FOR_ENTITY(material, normal_diffuse_map, specular, setSpecular, QColor);
	ADD_SLOT_FOR_ENTITY(material, normal_diffuse_map, shininess, setShininess, double);
	ADD_SLOT_FOR_ENTITY(material, normal_diffuse_map, texture_scale, setTextureScale, double);
	//

	//NORMAL_DIFFUSE_SPECULAR_MAP
	ADD_SLOT_FOR_ENTITY(material, normal_diffuse_specular_map, ambient, setAmbient, QColor);
	ADD_SLOT_FOR_ENTITY(material, normal_diffuse_specular_map, shininess, setShininess, double);
	ADD_SLOT_FOR_ENTITY(material, normal_diffuse_specular_map, texture_scale, setTextureScale, double);
	//

	//PHONG_ALPHA
	ADD_SLOT_FOR_ENTITY(material, phong_alpha, ambient, setAmbient, QColor);
	ADD_SLOT_FOR_ENTITY(material, phong_alpha, diffuse, setDiffuse, QColor);
	ADD_SLOT_FOR_ENTITY(material, phong_alpha, specular, setSpecular, QColor);
	ADD_SLOT_FOR_ENTITY(material, phong_alpha, shininess, setShininess, double);
	ADD_SLOT_FOR_ENTITY(material, phong_alpha, alpha, setAlpha, double);
	//

	//TEXTURE
	ADD_SLOT_FOR_ENTITY(material, texture, alpha_blending, setAlphaBlendingEnabled, bool);

	//mesh slots

	ADD_SLOT_FOR_ENTITY(mesh, sphere, radius, setRadius, double);
	ADD_SLOT_FOR_ENTITY(mesh, sphere, rings, setRings, int);
	ADD_SLOT_FOR_ENTITY(mesh, sphere, slices, setSlices, int);

	ADD_SLOT_FOR_ENTITY(mesh, cone, bottom_radius, setBottomRadius, double);
	ADD_SLOT_FOR_ENTITY(mesh, cone, length, setLength, double);
	ADD_SLOT_FOR_ENTITY(mesh, cone, top_radius, setTopRadius, double);
	ADD_SLOT_FOR_ENTITY(mesh, cone, rings, setRings, int);
	ADD_SLOT_FOR_ENTITY(mesh, cone, slices, setSlices, int);
	ADD_SLOT_FOR_ENTITY(mesh, cone, has_bottom_endcap, setHasBottomEndcap, bool);
	ADD_SLOT_FOR_ENTITY(mesh, cone, has_top_endcap, setHasTopEndcap, bool);

	ADD_SLOT_FOR_ENTITY(mesh, cuboid, x_extent, setXExtent, double);
	ADD_SLOT_FOR_ENTITY(mesh, cuboid, y_extent, setYExtent, double);
	ADD_SLOT_FOR_ENTITY(mesh, cuboid, z_extent, setZExtent, double);

	ADD_SLOT_FOR_ENTITY(mesh, cylinder, length, setLength, double);
	ADD_SLOT_FOR_ENTITY(mesh, cylinder, radius, setRadius, double);
	ADD_SLOT_FOR_ENTITY(mesh, cylinder, rings, setRings, int);
	ADD_SLOT_FOR_ENTITY(mesh, cylinder, slices, setSlices, int);

	ADD_SLOT_FOR_ENTITY(mesh, plane, height, setHeight, double);
	ADD_SLOT_FOR_ENTITY(mesh, plane, width, setWidth, double);

	ADD_SLOT_FOR_ENTITY(mesh, torus, minor_radius, setMinorRadius, double);
	ADD_SLOT_FOR_ENTITY(mesh, torus, radius, setRadius, double);
	ADD_SLOT_FOR_ENTITY(mesh, torus, rings, setRings, int);
	ADD_SLOT_FOR_ENTITY(mesh, torus, slices, setSlices, int);
};
