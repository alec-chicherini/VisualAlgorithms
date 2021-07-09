#pragma once

#include <QWidget>

#include <Qt3DCore/qentity.h>
#include <Qt3DExtras/qt3dwindow.h>
#include <qforwardrenderer.h>

#include <Qt3DRender/QGeometryRenderer>

//
#include <Qt3DExtras/qspheremesh.h>
#include <Qt3DExtras/qplanemesh.h>
#include <Qt3DExtras/qphongmaterial.h>
//

//light
#include <Qt3DRender/qpointlight.h>
#include <Qt3DCore/qtransform.h>
// 

//cameras environment
#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <Qt3DExtras/qorbitcameracontroller.h>
#include <qabstractcameracontroller.h>

//for QWidget container
#include <qgridlayout.h>
#include <QResizeEvent>
#include <qvariant.h>
#include <Qt3DExtras/qt3dwindow.h>


//real world algorithms book
#include "../Real_World_Algorithms/Real_World_Algorithms.h"
#include <qtorusmesh.h>
#include <qcomponent.h>


#include<qpushbutton.h>

#include "qlinemesh.h"

/// @brief viewport widget to show Qt3D objects
class viewport_window : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	/// @param root root entity for 3d objects
	/// @param parent paretnt for this instance
	viewport_window(Qt3DCore::QEntity* root, QWidget* parent = Q_NULLPTR);

	/// @brief default destructor
	~viewport_window();

	Qt3DExtras::Qt3DWindow* window3d_main;


private:
	Qt3DCore::QEntity* rootEntity;
	Qt3DCore::QEntity* currentSceneEntity;


	//camera
	Qt3DRender::QCamera* camera_main;
	Qt3DExtras::QAbstractCameraController* camera_controller_main = Q_NULLPTR;

	QWidget* container;

	//axis

	Qt3DCore::QEntity* axis_x;
	Qt3DCore::QEntity* axis_y;
	Qt3DCore::QEntity* axis_z;

	QLineMesh* line_axis_x;
	QLineMesh* line_axis_y;
	QLineMesh* line_axis_z;

    float size_axis = 5.0f;


signals:
	void viewport_camera_signal(Qt3DRender::QCamera*);

	/// @brief update current showed graph data
	/// @param gr graph
	/// @param op options
	void update_common_graph(graph<int> gr, std::underlying_type_t<GP> op);

	void viewport_window_screen_size_signal(Qt3DExtras::Qt3DWindow*);

private slots:

	void viewport_window::draw_axis(const QVector3D& center)
	{
		

		line_axis_x->setPossition(std::make_pair(center, QVector3D(center.x() + size_axis, center.y(), center.z())));
		line_axis_y->setPossition(std::make_pair(center, QVector3D(center.x(), center.y() + size_axis, center.z())));
		line_axis_z->setPossition(std::make_pair(center, QVector3D(center.x(), center.y(), center.z() + size_axis)));
	};
};
