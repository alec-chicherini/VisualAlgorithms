//test for custom mesh
#pragma once

#include <QWidget>

#include <QEntity>

#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>

#include <qt3dwindow.h>
#include <qforwardrenderer.h>

#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <Qt3DExtras/qorbitcameracontroller.h>
#include <QPointLight>

#include <QPhongMaterial>

#include<Qt3DExtras/qspheremesh.h>

#include <qgridlayout.h>

#include <QResizeEvent>


//
#include <QGuiApplication>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DInput/QInputAspect>
#include <Qt3DExtras/QPerVertexColorMaterial>
#include <Qt3DRender/QGeometryRenderer>

#if QT_VERSION == QT_VERSION_CHECK(6,1,0)

#elif QT_VERSION == QT_VERSION_CHECK(5,15,2)

#endif

#include<qpushbutton.h>

#include <QObjectPicker>
#include <QPickEvent>
#include <Qt3DExtras/qcuboidmesh.h>

//mouse
#include <qt3dinput/qmousedevice.h>
#include <qt3dinput/qmouseevent.h>
#include <qt3dinput/qmousehandler.h>


class qobjectpicker_test : public QWidget
{
	Q_OBJECT

public:
	qobjectpicker_test(QWidget *parent=Q_NULLPTR);
	~qobjectpicker_test();

private:
	Qt3DCore::QEntity* rootEntity;
	Qt3DExtras::Qt3DWindow* view;
	Qt3DRender::QCamera* camera;
	Qt3DExtras::QOrbitCameraController* camController;
	QWidget* container;
	
	QVector<Qt3DCore::QEntity*> vec;

	QPushButton* btn_regen;
	Qt3DCore::QEntity* picked_entity;
	float picked_projection_z;

public slots:
	

protected:
	virtual void resizeEvent(QResizeEvent* event)override;

private:

	inline QVector3D unproj_debug(const QVector3D& vec) {

		auto v = vec;

		v.setY(view->size().height() - vec.y());
		QMatrix4x4 modelView, projection;
		modelView.lookAt(camera->position(), camera->viewCenter(), camera->upVector());
		projection.perspective(camera->fieldOfView(), camera->aspectRatio(), camera->nearPlane(), camera->farPlane());
		auto viewport =  QRect(QPoint(0, 0), view->size());

		auto result = v.unproject(modelView, projection, viewport);
		
		return result;
	};

	inline QVector3D proj_debug(const QVector3D& vec) {
		QMatrix4x4 modelView, projection;

		modelView.lookAt(camera->position(), camera->viewCenter(), camera->upVector());

		projection.perspective(camera->fieldOfView(), camera->aspectRatio(), camera->nearPlane(), camera->farPlane());
		//qDebug() <<"QRect(QPoint(0, 0), view->size()"<< QRect(QPoint(0, 0), view->size());
		auto result = vec.project(modelView, projection, QRect(QPoint(0, 0), view->size()));
		result.setY(view->size().height() - result.y());
		return result;
	};
	
};
