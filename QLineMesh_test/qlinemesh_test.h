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

#if QT_VERSION == QT_VERSION_CHECK(6,1,0)
#include <Qt3DCore/qattribute.h>
#include <Qt3DCore/qgeometry.h>
#include <Qt3DCore/qbuffer.h>
using ATTRIBUTE_TYPE = ATTRIBUTE_TYPE;
using GEOMETRY_TYPE = GEOMETRY_TYPE
#elif QT_VERSION == QT_VERSION_CHECK(5,15,2)
#include <Qt3dRender/qattribute.h>
#include <Qt3dRender/qgeometry.h>
#include <Qt3dRender/qbuffer.h>
using ATTRIBUTE_TYPE = Qt3DRender::QAttribute;
using GEOMETRY_TYPE = Qt3DRender::QGeometry;
using BUFFER_TYPE = Qt3DRender::QBuffer;

#endif
#include <qbytearray.h>

#include <QPropertyAnimation>
#include <vector>

#include<qpushbutton.h>

#include <QVector>

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
	
	QVector<Qt3DCore::QEntity*> vec;

	QPushButton* btn_regen;

public slots:
	void regen_lines()
	{
        qDebug()<< "regen_lines cleanup BEGIN";
		if (vec.size())
		{
			for (auto& v : vec)
			{
				for (auto& comp : v->components())
				{
					v->removeComponent(comp);
					
				}
					
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
			//line->setWidth(0.5f);

			Qt3DCore::QEntity* entity = new Qt3DCore::QEntity(rootEntity);
			entity->addComponent(material);
			entity->addComponent(line);

			vec.push_back(entity);

		}

			//		auto line_data = std::make_pair(QVector3D(0, 0, 0), QVector3D(rand() % 10, rand() % 10, rand() % 10));
			//auto line = new QLineMesh(line_data, rootEntity);
			////line->setWidth(0.5f);

			//Qt3DCore::QEntity* entity = new Qt3DCore::QEntity(rootEntity);
			//entity->addComponent(material);
			//entity->addComponent(line);


        qDebug() << "regen_lines END";

	}

protected:
	virtual void resizeEvent(QResizeEvent* event)override;

	
	
};
