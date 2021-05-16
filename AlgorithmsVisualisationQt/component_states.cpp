#include "component_states.h"

component_states::component_states(QWidget *parent)
	: QWidget(parent)
{
	//all in app materials
	material_phong = new Qt3DExtras::QPhongMaterial;//id 0
	material_diffuse_map = new Qt3DExtras::QDiffuseMapMaterial;//id 1
	material_diffuse_specular_map = new Qt3DExtras::QDiffuseSpecularMapMaterial;//id 2
	material_diffuse_specular = new Qt3DExtras::QDiffuseSpecularMaterial;//id 3
	material_gooch = new Qt3DExtras::QGoochMaterial;//id 4
	material_metal_rough = new Qt3DExtras::QMetalRoughMaterial;//id 5
	material_morph_phong = new Qt3DExtras::QMorphPhongMaterial;//id 6
	material_normal_diffuse_map = new Qt3DExtras::QNormalDiffuseMapMaterial;//id 7
	material_normal_diffuse_specular_map = new Qt3DExtras::QNormalDiffuseSpecularMapMaterial;//id 8
	material_phong_alpha = new Qt3DExtras::QPhongAlphaMaterial;//id 9
	material_texture = new Qt3DExtras::QTextureMaterial;//id 10


  //all in app meshes
	mesh_cone = new Qt3DExtras::QConeMesh;//id 0
	mesh_cuboid = new Qt3DExtras::QCuboidMesh;//id 1
	mesh_cylinder = new Qt3DExtras::QCylinderMesh;//id 2
	mesh_plane = new Qt3DExtras::QPlaneMesh;//id 3
	mesh_sphere = new Qt3DExtras::QSphereMesh;//id 4
	mesh_torus = new Qt3DExtras::QTorusMesh;//id 5

}

component_states::~component_states()
{
}
