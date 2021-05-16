#include "scene_properties_common_graph.h"

scene_properties_common_graph::scene_properties_common_graph(QWidget *parent)
	: QWidget(parent)
{
	QTreeWidget* tree_widget = new QTreeWidget(this);

	ADD_ROOT(tree_widget, vertex)
		ADD_LEAF(vertex, mesh)
		ADD_LEAF(vertex, material)

	ADD_ROOT(tree_widget,edge)
		ADD_LEAF(edge, mesh)
		ADD_LEAF(edge, material)

	ADD_ROOT(tree_widget, plane)
		ADD_LEAF(plane, mesh)
		ADD_LEAF(plane, material)

//////////////////////////////////////////////////////////////////////////////////
	tree_widget->headerItem()->setText(0,"Common graph scene entities:");
	tree_widget->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
	tree_widget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

	tree_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tree_widget->resizeColumnToContents(1);
	QScrollBar* scroll = tree_widget->verticalScrollBar();
	
	QHBoxLayout* this_layout = new QHBoxLayout;
	this_layout->addWidget(scroll);
	this_layout->addWidget(tree_widget);

	setLayout(this_layout);
	this->setMinimumHeight(550);

//////////////////////////////////////////////////////////////////////////////////
	component_states_vertex = new component_states;
	component_states_edge = new component_states;
	component_states_plane = new component_states;

	ADD_CONNECTION_TYPE_TO_TYPE(vertex, material);
	ADD_CONNECTION_TYPE_TO_TYPE(vertex, mesh);
	ADD_CONNECTION_TYPE_TO_TYPE(edge, material);
	ADD_CONNECTION_TYPE_TO_TYPE(edge, mesh);
	ADD_CONNECTION_TYPE_TO_TYPE(plane, material);
	ADD_CONNECTION_TYPE_TO_TYPE(plane, mesh);


	//vertex connections
	//////////////////////////////////////////////////////////////////////////////////
	//PHONG
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong, specular);
	//

	//DIFFUSE_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_map, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_map, texture_scale);
	//

	//DIFFUSE_SPECULAR_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular_map, texture_scale);
	//

	//DIFFUSE_SPECULAR
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular, alpha_blending);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, diffuse_specular, texture_scale);
	//

	//GOOCH
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, gooch, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, gooch, warm);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, gooch, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, gooch, cool);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, gooch, alpha);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, gooch, beta);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, gooch, shininess);
	//

	//METAL_ROUGH
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, metal_rough, base_color);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, metal_rough, texture_scale);
	//

	//MORPH_PHONG
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, morph_phong, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, morph_phong, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, morph_phong, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, morph_phong, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, morph_phong, interpolator);
	//

	//NORMAL_DIFFUSE_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, normal_diffuse_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, normal_diffuse_map, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, normal_diffuse_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, normal_diffuse_map, texture_scale);
	//

	//NORMAL_DIFFUSE_SPECULAR_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, normal_diffuse_specular_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, normal_diffuse_specular_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, normal_diffuse_specular_map, texture_scale);
	//

	//PHONG_ALPHA
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong_alpha, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong_alpha, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong_alpha, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong_alpha, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, phong_alpha, alpha);
	//

	//TEXTURE
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,material, texture, alpha_blending);
	//

	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, sphere, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, sphere, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, sphere, slices);

	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cone, bottom_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cone, length);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cone, top_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cone, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cone, slices);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cone, has_bottom_endcap);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cone, has_top_endcap);

	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cuboid, x_extent);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cuboid, y_extent);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cuboid, z_extent);

	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cylinder, length);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cylinder, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cylinder, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, cylinder, slices);

	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, plane, height);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, plane, width);

	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, torus, minor_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, torus, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, torus, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(vertex,mesh, torus, slices);

	//edge connections
	///////////////////////////////////////////////////////////////
	//PHONG
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong, specular);
	//

	//DIFFUSE_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_map, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_map, texture_scale);
	//

	//DIFFUSE_SPECULAR_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular_map, texture_scale);
	//

	//DIFFUSE_SPECULAR
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, alpha_blending);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, texture_scale);
	//

	//GOOCH
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, warm);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, cool);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, alpha);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, beta);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, shininess);
	//

	//METAL_ROUGH
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, metal_rough, base_color);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, metal_rough, texture_scale);
	//

	//MORPH_PHONG
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, interpolator);
	//

	//NORMAL_DIFFUSE_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_map, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_map, texture_scale);
	//

	//NORMAL_DIFFUSE_SPECULAR_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_specular_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_specular_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_specular_map, texture_scale);
	//

	//PHONG_ALPHA
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, alpha);
	//

	//TEXTURE
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, texture, alpha_blending);
	//

	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, sphere, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, sphere, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, sphere, slices);

	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cone, bottom_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cone, length);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cone, top_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cone, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cone, slices);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cone, has_bottom_endcap);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cone, has_top_endcap);

	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cuboid, x_extent);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cuboid, y_extent);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cuboid, z_extent);

	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cylinder, length);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cylinder, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cylinder, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, cylinder, slices);

	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, plane, height);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, plane, width);

	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, torus, minor_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, torus, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, torus, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(edge, mesh, torus, slices);

	//plane connections
	///////////////////////////////////////////////////////////////
	//PHONG
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong, specular);
	//

	//DIFFUSE_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_map, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_map, texture_scale);
	//

	//DIFFUSE_SPECULAR_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular_map, texture_scale);
	//

	//DIFFUSE_SPECULAR
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, alpha_blending);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, texture_scale);
	//

	//GOOCH
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, warm);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, cool);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, alpha);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, beta);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, shininess);
	//

	//METAL_ROUGH
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, metal_rough, base_color);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, metal_rough, texture_scale);
	//

	//MORPH_PHONG
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, interpolator);
	//

	//NORMAL_DIFFUSE_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_map, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_map, texture_scale);
	//

	//NORMAL_DIFFUSE_SPECULAR_MAP
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_specular_map, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_specular_map, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_specular_map, texture_scale);
	//

	//PHONG_ALPHA
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, ambient);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, diffuse);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, specular);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, shininess);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, alpha);
	//

	//TEXTURE
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, texture, alpha_blending);
	//

	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, sphere, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, sphere, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, sphere, slices);

	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, bottom_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, length);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, top_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, slices);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, has_bottom_endcap);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, has_top_endcap);

	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cuboid, x_extent);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cuboid, y_extent);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cuboid, z_extent);

	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cylinder, length);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cylinder, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cylinder, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cylinder, slices);

	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, plane, height);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, plane, width);

	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, torus, minor_radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, torus, radius);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, torus, rings);
	ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, torus, slices);
}

scene_properties_common_graph::~scene_properties_common_graph()
{
}
