#pragma once

#include <QWidget>

#include <Qt3DCore/qentity.h>
#include <qt3dwindow.h>
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

private:
	Qt3DCore::QEntity* rootEntity;
	Qt3DCore::QEntity* currentSceneEntity;
	Qt3DExtras::Qt3DWindow* window3d_main;

	//camera
	Qt3DRender::QCamera* camera_main;
	Qt3DExtras::QAbstractCameraController* camera_controller_main = Q_NULLPTR;

	//light
	Qt3DCore::QEntity* light_main;
	Qt3DRender::QPointLight* point_light_main;
	Qt3DCore::QTransform* tansform_light_main;

	QWidget* container;


signals:
	void viewport_camera_signal(Qt3DRender::QCamera*);

	/// @brief update current showed graph data
	/// @param gr graph
	/// @param op options
	void update_common_graph(graph<int> gr, std::underlying_type_t<GP> op);

//public slots:
//	/// @brief slot to set current type of camera controller
//	/// @param index 0 - normal; 1 - orbital;
//	/// @return void
//	void viewport_camera_controller_slot(int index)
//	{
//		if (index == 0)
//		{
//			if (camera_controller_main != Q_NULLPTR)delete camera_controller_main;
//
//			camera_controller_main = new Qt3DExtras::QFirstPersonCameraController(currentSceneEntity);
//			camera_controller_main->setCamera(camera_main);
//		}
//		else if (index == 1)
//		{
//			if (camera_controller_main != Q_NULLPTR)delete camera_controller_main;
//
//			camera_controller_main = new Qt3DExtras::QOrbitCameraController(currentSceneEntity);
//			camera_controller_main->setCamera(camera_main);
//		}
//	}
//
//	/// @brief slot to update light color
//	/// @param clr
//	/// @return void
//	void viewport_light_color_slot(QColor clr)
//	{
//		point_light_main->setColor(clr);
//		qDebug((std::to_string(clr.red()).c_str()));
//		qDebug(" <----- COLOR RED WAS CHANGED()");
//		qDebug((std::to_string(clr.green()).c_str()));
//		qDebug(" <----- COLOR GREEN WAS CHANGED()");
//		qDebug((std::to_string(clr.blue()).c_str()));
//		qDebug(" <----- COLOR BLUE WAS CHANGED()");
//	}
//	/// @brief slot to update light intensity
//	/// @param intens intensity
//	/// @return void
//	void viewport_light_intensity_slot(float intens)
//	{
//		point_light_main->setIntensity(intens);
//			qDebug((std::to_string(intens).c_str()));
//			qDebug(" <----- LIGHT INTENSYTY WAS CHANGED()");
//	}
//
//
//	/// @brief slot to set current scene by switching second entity after root
//	/// @param scene scene entity
//	/// @return void
//	void viewport_scene_entity_slot(Qt3DCore::QEntity* scene)
//	{
//		currentSceneEntity = scene;
//	}

};
