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
#include "enums.h"
#include <Qt3DCore/qcomponent.h>

#include <Qt3DCore/qentity.h>

//cameras environment
#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <Qt3DExtras/qorbitcameracontroller.h>
#include <qabstractcameracontroller.h>

//light
#include <QAbstractLight>
#include <Qt3DRender/qpointlight.h>
#include <QDirectionalLight>
#include <QPointLight>
#include <QSpotLight>
// 

/// @brief class which store all instances of materials and meshes with current settings. So later if some entity switch component from one to another it just switch pointer to existing version in this.
class component_states : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	/// @param root root entity for materials and meshes
	/// @param parent QWidget for this
	component_states(Qt3DCore::QEntity* root, QWidget *parent = Q_NULLPTR);
	~component_states();

private:
	Qt3DCore::QEntity* rootEntity;
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

	//all in app meshes
	Qt3DExtras::QConeMesh* mesh_cone;//id 0
	Qt3DExtras::QCuboidMesh* mesh_cuboid;//id 1
	Qt3DExtras::QCylinderMesh* mesh_cylinder;//id 2
	Qt3DExtras::QPlaneMesh* mesh_plane;//id 3
	Qt3DExtras::QSphereMesh* mesh_sphere;//id 4
	Qt3DExtras::QTorusMesh* mesh_torus;//id 5

	//camera
	Qt3DRender::QCamera* camera_camera;
	Qt3DExtras::QFirstPersonCameraController* camera_controller_first_person; //id 0
	Qt3DExtras::QOrbitCameraController* camera_controller_orbit;//id 1
	//
	 
	//light
	Qt3DRender::QPointLight* light_point;//id 0
	Qt3DRender::QDirectionalLight* light_directional;//id 1
	Qt3DRender::QSpotLight* light_spot;//id 2
	//
   
	//current component
	MeshType current_mesh_type;
	MaterialType current_material_type;
	bool current_camera_controller_type;
	Qt3DRender::QAbstractLight::Type current_light_type;


signals:
	/// @brief on changing current material type emit pointer to new component
	void component_states_material_type_signal(Qt3DCore::QComponent*);

	/// @brief on changing current mesh type emit pointer to new component
	void component_states_mesh_type_signal(Qt3DCore::QComponent*);

	/// @brief on changing current camera controller type emit pointer to current camera controller
	void component_states_camera_controller_type_signal(Qt3DExtras::QAbstractCameraController*);

	/// @brief dummy to prevent macroses generating errors - do nothing
	void component_states_camera_type_signal();

/// @brief on changing current light type emit pointer to current light type
	void component_states_light_type_signal(Qt3DRender::QAbstractLight*);


public slots:
	
	/// @brief slot to change current material
	void component_states_material_type_slot(int id)
	{
		current_material_type = static_cast<MaterialType>(id);
		switch (current_material_type)
		{
		case ENUMS_NAMESPACE::MaterialType::PHONG:
		{
			emit component_states_material_type_signal( material_phong);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::DIFFUSE_MAP:
		{
			emit component_states_material_type_signal( material_diffuse_map);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::DIFFUSE_SPECULAR_MAP:
		{
			emit component_states_material_type_signal( material_diffuse_specular_map);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::DIFFUSE_SPECULAR:
		{
			emit component_states_material_type_signal( material_diffuse_specular);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::GOOCH:
		{
			emit component_states_material_type_signal( material_gooch);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::METAL_ROUGH:
		{
			emit component_states_material_type_signal( material_metal_rough);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::MORPH_PHONG:
		{
			emit component_states_material_type_signal( material_morph_phong);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::NORMAL_DIFFUSE_MAP:
		{
			emit component_states_material_type_signal( material_normal_diffuse_map);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::NORMAL_DIFFUSE_SPECULAR_MAP:
		{
			emit component_states_material_type_signal( material_normal_diffuse_specular_map);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::PHONG_ALPHA:
		{
			emit component_states_material_type_signal( material_phong_alpha);
			break;
		}
		case ENUMS_NAMESPACE::MaterialType::TEXTURE:
		{
			emit component_states_material_type_signal( material_texture);
			break;
		}
		default:
			break;
		}

		qDebug() << Q_FUNC_INFO << " CALLED !!! "; 
	}

	
	/// @brief slot to change current mesh
	void component_states_mesh_type_slot(int id)
	{
		current_mesh_type = static_cast<MeshType>(id);

		switch (current_mesh_type)
		{
		case ENUMS_NAMESPACE::MeshType::CONE:
				{emit component_states_mesh_type_signal(mesh_cone);break;};
		case ENUMS_NAMESPACE::MeshType::CUBOID:
				{emit component_states_mesh_type_signal(mesh_cuboid);break;};
		case ENUMS_NAMESPACE::MeshType::CYLINDER:
				{emit component_states_mesh_type_signal(mesh_cylinder);break;};
		case ENUMS_NAMESPACE::MeshType::PLANE:
				{emit component_states_mesh_type_signal(mesh_plane);break;};
		case ENUMS_NAMESPACE::MeshType::SPHERE:
				{emit component_states_mesh_type_signal(mesh_sphere);break;};
		case ENUMS_NAMESPACE::MeshType::TORUS:
				{emit component_states_mesh_type_signal(mesh_torus);break;};
		default:
			break;	
		}

		qDebug() << Q_FUNC_INFO << " CALLED !!! "; 
	}
	

	///@brief slot to change current camera controller
	void component_states_camera_controller_type_slot(int type)
	{
		current_camera_controller_type = type;

		if (current_camera_controller_type==1)
			emit component_states_camera_controller_type_signal(camera_controller_orbit);
		else if (current_camera_controller_type == 0)
			emit component_states_camera_controller_type_signal(camera_controller_first_person);
		qDebug() << Q_FUNC_INFO << "| type = "<<type;
	};

	/// @brief slot to set current camera to pointer from camera in viewport qwindow_3d
	void component_states_camera_slot(Qt3DRender::QCamera* camera)
	{
		camera_camera = camera;

		//qDebug() << camera_camera << "<<<<---camera_camera component_states pointer ";
	};

	/// @brief dummy to prevent macroses generating errors - do nothing
	void component_states_camera_type_slot()
	{

	};

	///@brief slot to change current light
	void component_states_light_type_slot(Qt3DRender::QAbstractLight* light) 
	{

	};

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

	//light slots
	ADD_SLOT_FOR_ENTITY(light, point, color, setColor, QColor);
	ADD_SLOT_FOR_ENTITY(light, point, intensity, setIntensity, float);
	ADD_SLOT_FOR_ENTITY(light, point, constant_attenuation, setConstantAttenuation, float);
	ADD_SLOT_FOR_ENTITY(light, point, linear_attenuation, setLinearAttenuation, float);
	ADD_SLOT_FOR_ENTITY(light, point, quadratic_attenuation, setQuadraticAttenuation, float);

	ADD_SLOT_FOR_ENTITY(light, spot, color, setColor, QColor);
	ADD_SLOT_FOR_ENTITY(light, spot, intensity, setIntensity, float);
	ADD_SLOT_FOR_ENTITY(light, spot, constant_attenuation, setConstantAttenuation, float);
	ADD_SLOT_FOR_ENTITY(light, spot, linear_attenuation, setLinearAttenuation, float);
	ADD_SLOT_FOR_ENTITY(light, spot, quadratic_attenuation, setQuadraticAttenuation, float);
	ADD_SLOT_FOR_ENTITY(light, spot, cut_off_angle, setCutOffAngle, float);
	ADD_SLOT_FOR_ENTITY(light, spot, local_direction, setLocalDirection, QVector3D);

	ADD_SLOT_FOR_ENTITY(light, directional, color, setColor, QColor);
	ADD_SLOT_FOR_ENTITY(light, directional, intensity, setIntensity, float);
	ADD_SLOT_FOR_ENTITY(light, directional, world_direction, setWorldDirection, QVector3D);


	//camera controllers
	ADD_SLOT_FOR_ENTITY(camera_controller, first_person, acceleration, setAcceleration, float);
	ADD_SLOT_FOR_ENTITY(camera_controller, first_person, deceleration, setDeceleration, float);
	ADD_SLOT_FOR_ENTITY(camera_controller, first_person, linear_speed, setLinearSpeed, float);
	ADD_SLOT_FOR_ENTITY(camera_controller, first_person, look_speed, setLookSpeed, float);
	ADD_SLOT_FOR_ENTITY(camera_controller, first_person, camera, setCamera, Qt3DRender::QCamera*);

	ADD_SLOT_FOR_ENTITY(camera_controller, orbit, acceleration, setAcceleration, float);
	ADD_SLOT_FOR_ENTITY(camera_controller, orbit, deceleration, setDeceleration, float);
	ADD_SLOT_FOR_ENTITY(camera_controller, orbit, linear_speed, setLinearSpeed, float);
	ADD_SLOT_FOR_ENTITY(camera_controller, orbit, look_speed, setLookSpeed, float);
	ADD_SLOT_FOR_ENTITY(camera_controller, orbit, camera, setCamera, Qt3DRender::QCamera*);
	ADD_SLOT_FOR_ENTITY(camera_controller, orbit, zoom_in_limit, setZoomInLimit, float);

	//camera
	ADD_SLOT_FOR_ENTITY(camera, camera, aspect_ratio, setAspectRatio, float);
	ADD_SLOT_FOR_ENTITY(camera, camera, bottom, setBottom, float);
	ADD_SLOT_FOR_ENTITY(camera, camera, exposure, setExposure, float);
	ADD_SLOT_FOR_ENTITY(camera, camera, far_plane, setFarPlane, float);
	ADD_SLOT_FOR_ENTITY(camera, camera, near_plane, setNearPlane, float);
	ADD_SLOT_FOR_ENTITY(camera, camera, field_of_view, setFieldOfView, float);
	ADD_SLOT_FOR_ENTITY(camera, camera, left, setLeft, float);
	ADD_SLOT_FOR_ENTITY(camera, camera, right, setRight, float);
	ADD_SLOT_FOR_ENTITY(camera, camera, top, setTop, float);

	ADD_SLOT_FOR_ENTITY(camera, camera, position, setPosition, QVector3D);
	ADD_SLOT_FOR_ENTITY(camera, camera, view_center, setViewCenter, QVector3D);
	ADD_SLOT_FOR_ENTITY(camera, camera, up_vector, setUpVector, QVector3D);

	ADD_SLOT_FOR_ENTITY(camera, camera, projection_type, setProjectionType, Qt3DRender::QCameraLens::ProjectionType);

	ADD_SLOT_FOR_ENTITY(camera, camera, projection_matrix, setProjectionMatrix, QMatrix4x4);

};
