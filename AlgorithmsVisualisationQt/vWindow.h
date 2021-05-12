//deprecated viewport from first experiments. now using viewport_window.h
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


class vWindow : public QWidget
{
	Q_OBJECT

public:
	vWindow(QWidget *parent);
	~vWindow();

private:
	Qt3DCore::QEntity* rootEntity;
	Qt3DExtras::Qt3DWindow* view;
	Qt3DRender::QCamera* camera;
	Qt3DExtras::QOrbitCameraController* camController;
	QWidget* container;

protected:
	virtual void resizeEvent(QResizeEvent* event)override;

	
	
};
