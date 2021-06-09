#include "component_states.h"

component_states::component_states(Qt3DCore::QEntity* root, QWidget *parent)
	: QWidget(parent)
{
	rootEntity = new Qt3DCore::QEntity(root);

	//all in app materials
	material_phong = new Qt3DExtras::QPhongMaterial(rootEntity);//id 0
	material_diffuse_map = new Qt3DExtras::QDiffuseMapMaterial(rootEntity);//id 1
	material_diffuse_specular_map = new Qt3DExtras::QDiffuseSpecularMapMaterial(rootEntity);//id 2
	material_diffuse_specular = new Qt3DExtras::QDiffuseSpecularMaterial(rootEntity);//id 3
	material_gooch = new Qt3DExtras::QGoochMaterial(rootEntity);//id 4
	material_metal_rough = new Qt3DExtras::QMetalRoughMaterial(rootEntity);//id 5
	material_morph_phong = new Qt3DExtras::QMorphPhongMaterial(rootEntity);//id 6
	material_normal_diffuse_map = new Qt3DExtras::QNormalDiffuseMapMaterial(rootEntity);//id 7
	material_normal_diffuse_specular_map = new Qt3DExtras::QNormalDiffuseSpecularMapMaterial(rootEntity);//id 8
	material_phong_alpha = new Qt3DExtras::QPhongAlphaMaterial(rootEntity);//id 9
	material_texture = new Qt3DExtras::QTextureMaterial(rootEntity);//id 10


  //all in app meshes
	mesh_cone = new Qt3DExtras::QConeMesh(rootEntity);//id 0
	mesh_cuboid = new Qt3DExtras::QCuboidMesh(rootEntity);//id 1
	mesh_cylinder = new Qt3DExtras::QCylinderMesh(rootEntity);//id 2
	mesh_plane = new Qt3DExtras::QPlaneMesh(rootEntity);//id 3
	mesh_sphere = new Qt3DExtras::QSphereMesh(rootEntity);//id 4
	mesh_torus = new Qt3DExtras::QTorusMesh(rootEntity);//id 5

	//all lights
	light_point = new Qt3DRender::QPointLight(rootEntity);//id 0
	light_spot = new Qt3DRender::QSpotLight(rootEntity);//id 1
	light_directional=new Qt3DRender::QDirectionalLight(rootEntity);//id 2


	//camera
	camera_controller_first_person = new Qt3DExtras::QFirstPersonCameraController(rootEntity);//id 0
	camera_controller_orbit = new Qt3DExtras::QOrbitCameraController(rootEntity);//id 1

//#define[] MAT phong,diffuse_map,diffuse_specular_map,diffuse_specular,gooch,metal_rough,morph_phong,normal_diffuse_map,normal_diffuse_specular_map,phong_alpha,texture
//#define[] MES cone,cuboid,cylinder,plane,sphere,torus



}

component_states::~component_states()
{
}
