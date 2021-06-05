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
#include "../Real_World_Algorithms/Real_World_Algorithms.h"


/// @brief 3d scene for graphs visualisation properties. 
class scene_properties_common_graph : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	scene_properties_common_graph(Qt3DCore::QEntity* root, QWidget* parent = Q_NULLPTR);
	/// @brief default destructor
	~scene_properties_common_graph();

private:
	component_states* component_states_vertex;
	component_states* component_states_edge;
	component_states* component_states_plane;

	scene_entities_common_graph* scene_entities_common_graph_;

signals:
	void scene_properties_common_graph_type_signal(int& type, graph<int>& gr, under_GP& options);

public slots:
	/// @brief if graph type is common graph this scene start to work
	/// @return void
	void scene_properties_common_graph_type_slot(int& type, graph<int>& gr, under_GP& options)
	{
		if (type == 0)
		{
			emit scene_properties_common_graph_type_signal(type, gr, options);

		}
	}



};
