#pragma once

#include "scene_entities_common_graph.h"

#include <QWidget>

#include "property_mesh.h"
#include "property_material.h"
#include "property_transform.h"
#include "property_camera.h"
#include "property_camera_controller.h"
#include "property_light.h"

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
	component_states* component_states_camera;
	component_states* component_states_camera_controller;
	component_states* component_states_light;

	scene_entities_common_graph* scene_entities_common_graph_;

	property_camera* camera_camera_ptr;

signals:
	void scene_properties_common_graph_type_signal(int& type, graph<int>& gr, under_GP& options);
	void scene_properties_common_graph_camera_signal(Qt3DRender::QCamera*);
	void scene_properties_common_graph_viewport_size_signal(Qt3DExtras::Qt3DWindow*);
	void scene_properties_common_graph_light_possition(QVector3D);
	void scene_properties_common_graph_light_direction(QVector3D);


public slots:

	/// @brief recieve pointer viewport window to entities in common graph
	void scene_properties_common_graph_viewport_size_slot(Qt3DExtras::Qt3DWindow* view)
	{

		QMetaObject::invokeMethod(this,
			"scene_properties_common_graph_viewport_size_signal",
			Qt::QueuedConnection,
			Q_ARG(Qt3DExtras::Qt3DWindow*, view));
	}

	/// @brief if graph type is common graph this scene start to work
	/// @return void
	void scene_properties_common_graph_type_slot(int& type, graph<int>& gr, under_GP& options)
	{
		if (type == 0)
		{
			emit scene_properties_common_graph_type_signal(type, gr, options);

		}
	}

	void scene_properties_common_graph_camera_slot(Qt3DRender::QCamera* camera)
	{
		QMetaObject::invokeMethod(this,
			"scene_properties_common_graph_camera_signal",
			Qt::QueuedConnection,
			Q_ARG(Qt3DRender::QCamera*, camera));

		QMetaObject::invokeMethod(this,
			"scene_properties_common_graph_camera_signal",
			Qt::DirectConnection,
			Q_ARG(Qt3DRender::QCamera*, camera));
	}

};
