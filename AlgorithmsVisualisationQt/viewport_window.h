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

//debug
#include "qdebug_helper.h"

//real world algorithms book
#include "../Real_World_Algorithms/Real_World_Algorithms.h"



#include <qtorusmesh.h>
#include <qcomponent.h>

class viewport_window : public QWidget
{
	Q_OBJECT

public:
	viewport_window(Qt3DCore::QEntity* root, QWidget* parent = Q_NULLPTR);
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

	bool camera_menu_possition_signal_was_recived = false;
	bool camera_menu_view_center_signal_was_recived = false;

	void update_common_graph(graph<int>, std::underlying_type_t<GP>);

signals:
	void viewport_camera_position_signal(const QVector3D& position) ;
	void viewport_camera_view_center_signal(const QVector3D& position);


public slots:
	void viewport_camera_possition_slot(QVector3D pos)
	{
		camera_menu_possition_signal_was_recived = true;
		camera_main->setPosition(pos);
		
		 qDebug() << QDateTime::currentDateTimeUtc()<< QString("<----- call viewport_camera_possition_slot") << QString::number(camera_menu_possition_signal_was_recived);
	};

	void viewport_camera_view_center_slot(QVector3D pos)
	{
		camera_menu_view_center_signal_was_recived = true;
		camera_main->setViewCenter(pos);

		 qDebug() << QDateTime::currentDateTimeUtc()<< QString("<----- call viewport_camera_view_center_slot") << QString::number(camera_menu_view_center_signal_was_recived);
	
	};

	void viewport_camera_controller_slot(int index)
	{
		if (index == 0)
		{
			if (camera_controller_main != Q_NULLPTR)delete camera_controller_main;

			camera_controller_main = new Qt3DExtras::QFirstPersonCameraController(currentSceneEntity);
			camera_controller_main->setCamera(camera_main);
		}
		else if (index == 1)
		{
			if (camera_controller_main != Q_NULLPTR)delete camera_controller_main;

			camera_controller_main = new Qt3DExtras::QOrbitCameraController(currentSceneEntity);
			camera_controller_main->setCamera(camera_main);
		}

	}

	void viewport_light_color_slot(QColor clr)
	{
		point_light_main->setColor(clr);
		qDebug((std::to_string(clr.red()).c_str()));
		qDebug(" <----- COLOR RED WAS CHANGED()");
		qDebug((std::to_string(clr.green()).c_str()));
		qDebug(" <----- COLOR GREEN WAS CHANGED()");
		qDebug((std::to_string(clr.blue()).c_str()));
		qDebug(" <----- COLOR BLUE WAS CHANGED()");
	}

	void viewport_light_intensity_slot(float intens)
	{
		point_light_main->setIntensity(intens);
			qDebug((std::to_string(intens).c_str()));
			qDebug(" <----- LIGHT INTENSYTY WAS CHANGED()");
	}



	void viewport_scene_entity_slot(Qt3DCore::QEntity* scene)
	{
		currentSceneEntity = scene;
	}

};
