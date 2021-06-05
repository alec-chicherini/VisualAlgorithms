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
#include <vector>

#include<qpushbutton.h>

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
	
	std::vector<Qt3DCore::QEntity*> vec;

	QPushButton* btn_regen;

	void regen_lines()
	{
        qDebug()<< "regen_lines cleanup BEGIN";
		if (vec.size())
		{
			for (auto& v : vec)
			{
				for (auto& comp : v->components())
					delete comp;
				delete v;

			}
			vec.clear();
		}

        qDebug()<< "regen_lines create BEGIN";
		auto material = new Qt3DExtras::QPhongMaterial;
		material->setDiffuse(QColor(0, 128, 0));

        for (int i = 100; i != 0; i--)
		{
			auto line_data = std::make_pair(QVector3D(0, 0, 0), QVector3D(rand() % 10, rand() % 10, rand() % 10));
			auto line = new QLineMesh(line_data, rootEntity);
			line->setWidth(0.5f);

			Qt3DCore::QEntity* entity = new Qt3DCore::QEntity(rootEntity);
			entity->addComponent(material);
			entity->addComponent(line);

			vec.push_back(entity);

		}
        qDebug() << "regen_lines END";
	}

protected:
	virtual void resizeEvent(QResizeEvent* event)override;

	
	
};
