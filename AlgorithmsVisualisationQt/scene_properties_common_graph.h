#pragma once

#include "scene_entities_common_graph.h"

#include <QWidget>

#include "property_mesh.h"
#include "property_material.h"
#include "property_transform.h"

#include <qgridlayout.h>
#include <qboxlayout.h>

#include <qtreeview.h>
#include <qstandarditemmodel.h>

#include <qtreewidget.h>
#include <qabstractitemview.h>

#include <qscrollbar.h>

#include "property_macros.h"

#include <Qt3DCore/qcomponent.h>
#include <Qt3DCore/qentity.h>

//propertie windows states in objects
#include "component_states.h"

//real world algorithms book
#include "../Real_World_Algorithms.h"



class scene_properties_common_graph : public QWidget
{
	Q_OBJECT

public:
	scene_properties_common_graph(Qt3DCore::QEntity* root, QWidget* parent = Q_NULLPTR);
	~scene_properties_common_graph();

private:
	component_states* component_states_vertex;
	component_states* component_states_edge;
	component_states* component_states_plane;

	scene_entities_common_graph* scene_entities_common_graph_;

signals:
	void scene_properties_common_graph_scene_entity(Qt3DCore::QEntity*);

public slots:
	void scene_properties_common_graph_type_slot(int type, graph<int> gr, under_GP options)
	{
		if (type == 0)
		{
			emit scene_properties_common_graph_scene_entity(scene_entities_common_graph_->getRoot());

		}
	}

	void graph_vertex_material_type_slot(Qt3DCore::QComponent* component) 
	{
		emit graph_vertex_material_type_signal(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! "; 
	};

	void graph_vertex_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		emit graph_vertex_mesh_type_signal(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! "; 
		
	};

	void graph_edge_material_type_slot(Qt3DCore::QComponent* component)
	{
		emit graph_edge_material_type_signal(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
	};

	void graph_edge_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		emit graph_edge_mesh_type_signal(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
	};

	void graph_plane_material_type_slot(Qt3DCore::QComponent* component)
	{
		emit graph_plane_material_type_signal(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
	};

	void graph_plane_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		emit graph_plane_mesh_type_signal(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
	};

signals:


	void graph_vertex_material_type_signal(Qt3DCore::QComponent*);
	void graph_vertex_mesh_type_signal(Qt3DCore::QComponent*);

	void graph_edge_material_type_signal(Qt3DCore::QComponent*);
	void graph_edge_mesh_type_signal(Qt3DCore::QComponent*);

	void graph_plane_material_type_signal(Qt3DCore::QComponent*);
	void graph_plane_mesh_type_signal(Qt3DCore::QComponent*);


};
