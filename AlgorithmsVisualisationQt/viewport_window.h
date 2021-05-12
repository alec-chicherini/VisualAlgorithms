#pragma once

#include <QWidget>

#include <Qt3DCore/qentity.h>
#include <qt3dwindow.h>
#include <qforwardrenderer.h>

#include <Qt3DRender/QGeometryRenderer>

//dummy
#include <Qt3DExtras/qspheremesh.h>
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

class viewport_window : public QWidget
{
	Q_OBJECT

public:
	viewport_window(QWidget *parent = Q_NULLPTR);
	~viewport_window();

private:
	Qt3DCore::QEntity* rootEntity;
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
	void viewport_camera_position_signal(const QVector3D& position);
	void viewport_camera_view_center_signal(const QVector3D& position);

public slots:
	void viewport_camera_possition_slot(QVector3D pos)
	{
		camera_main->blockSignals(true);
		camera_main->setPosition(pos);
		camera_main->blockSignals(false);
	};

	void viewport_camera_view_center_slot(QVector3D pos)
	{
		camera_main->blockSignals(true);
		camera_main->setViewCenter(pos);
		camera_main->blockSignals(false);
	};

	void viewport_camera_controller_slot(int index)
	{
		if (index == 0)
		{
			if (camera_controller_main != Q_NULLPTR)delete camera_controller_main;

			camera_controller_main = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
			camera_controller_main->setCamera(camera_main);
		}
		else if (index == 1)
		{
			if (camera_controller_main != Q_NULLPTR)delete camera_controller_main;

			camera_controller_main = new Qt3DExtras::QOrbitCameraController(rootEntity);
			camera_controller_main->setCamera(camera_main);
		}

	}

	void viewport_light_color_slot(QColor clr)
	{
		point_light_main->setColor(clr);
		OutputDebugStringW(LPCWSTR(std::to_wstring(clr.red()).c_str()));
		OutputDebugStringW(L" <----- COLOR RED WAS CHANGED()\n");
		OutputDebugStringW(LPCWSTR(std::to_wstring(clr.green()).c_str()));
		OutputDebugStringW(L" <----- COLOR GREEN WAS CHANGED()\n");
		OutputDebugStringW(LPCWSTR(std::to_wstring(clr.blue()).c_str()));
		OutputDebugStringW(L" <----- COLOR BLUE WAS CHANGED()\n");
	}

	void viewport_light_intensity_slot(float intens)
	{
		point_light_main->setIntensity(intens);
			OutputDebugStringW(LPCWSTR(std::to_wstring(intens).c_str()));
			OutputDebugStringW(L" <----- LIGHT INTENSYTY WAS CHANGED()\n");
	}


};
