#pragma once

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

//propertie windows states in objects
#include "component_states.h"

class scene_properties_common_graph : public QWidget
{
	Q_OBJECT

public:
	scene_properties_common_graph(QWidget *parent = Q_NULLPTR);
	~scene_properties_common_graph();

private:
	component_states* component_states_vertex;
	component_states* component_states_edge;
	component_states* component_states_plane;

};
