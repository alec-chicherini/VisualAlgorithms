//test for custom mesh
#pragma once

#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qfile.h>
#include <qbytearray.h>
#include <qmessagebox.h>

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

#include "qlinemesh.h"

#include "qpair.h"

//
#include <QGuiApplication>


#include <Qt3DCore/QEntity>

#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>

#include <Qt3DInput/QInputAspect>


#include <Qt3DExtras/QPerVertexColorMaterial>

#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DCore/QGeometry>
#include <Qt3DCore/QAttribute>
#include <Qt3DCore/QBuffer>

#include <QPropertyAnimation>

//


class qlinemesh_test : public QWidget
{
	Q_OBJECT

public:
	qlinemesh_test(QWidget *parent=Q_NULLPTR);
	~qlinemesh_test();

private:
	Qt3DCore::QEntity* rootEntity;
	Qt3DExtras::Qt3DWindow* view;
	Qt3DRender::QCamera* camera;
	Qt3DExtras::QOrbitCameraController* camController;
	QWidget* container;
	QLineMesh* line;

protected:
	virtual void resizeEvent(QResizeEvent* event)override;

	
	
};
