#pragma once

#include <QWidget>

#include "property_mesh.h"
#include "property_material.h"
#include "property_transform.h"

#include <qscrollarea.h>
#include <qgridlayout.h>
#include <qboxlayout.h>


class scene_properties_common_graph : public QWidget
{
	Q_OBJECT

public:
	scene_properties_common_graph(QWidget *parent = Q_NULLPTR);
	~scene_properties_common_graph();

private:
	QScrollArea* scroll_area_common_graph;

};
