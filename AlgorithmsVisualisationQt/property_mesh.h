#pragma once


#include <QWidget>
#include "enums.h"

#include <qcombobox.h>
#include <qlabel.h>
#include <qgridlayout.h>
#include <qstackedlayout.h>
#include <qcheckbox.h>
#include <qspinbox.h>

#include "property_macros.h"

#include <qjsonobject.h>
#include <qfile.h>
#include <qdir.h>
#include <qjsondocument.h>
#include <qjsonvalue.h>
#include <qbytearray.h>

#include <tuple>
#include <qobject.h>

class property_mesh : public QWidget
{
	Q_OBJECT

public:
	property_mesh(QString parentPath, QWidget *parent = Q_NULLPTR);
	~property_mesh();

private:
	QComboBox* combobox_mesh;
	QString parentPath_;

		ADD_JSON_LOADER(sphere)
		ADD_JSON_LOADER(cone)
		ADD_JSON_LOADER(cuboid)
		ADD_JSON_LOADER(cylinder)
		ADD_JSON_LOADER(plane)
		ADD_JSON_LOADER(torus)
		ADD_JSON_LOADER(current_mesh_index)

	template <typename T>
	struct 	delayed_emit
	{
		QString signal_name;
		T signal_data;
	};

	std::vector<delayed_emit<double>> e_vec_func_double;
	std::vector<delayed_emit<int>> e_vec_func_int;
	//std::vector<delayed_emit<QColor>> e_vec_func_QColor;

public:
	void send_initialization_data()
	{
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
		//emit property_mesh_type_signal(combobox_mesh->currentIndex());

		QMetaObject::invokeMethod(this,
			"property_mesh_type_signal",
			Qt::QueuedConnection,
			Q_ARG(int, combobox_mesh->currentIndex()));

		for (auto& e : e_vec_func_double) {
		qDebug() << "BEGIN::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ") - invoke data  ";
		bool result = QMetaObject::invokeMethod(this,
			e.signal_name.toStdString().data(),
			Qt::QueuedConnection,
			Q_ARG(double, e.signal_data));

		qDebug() << "END::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ")invoke result is: " << result;
	}

		for (auto& e : e_vec_func_int)
		{
			qDebug() << "BEGIN::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ") - invoke data";
			bool result = QMetaObject::invokeMethod(this,
				e.signal_name.toStdString().data(),
				Qt::QueuedConnection,
				Q_ARG(int, e.signal_data));

			qDebug() << "END::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ")invoke result is: " << result;
		}


	};
signals:

	void property_mesh_type_signal(int);


	ADD_SIGNAL_FOR_ENTITY(mesh, sphere, radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh, sphere, rings, int);
	ADD_SIGNAL_FOR_ENTITY(mesh, sphere, slices, int);

	ADD_SIGNAL_FOR_ENTITY(mesh, cone, bottom_radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, length, double);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, top_radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, rings, int);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, slices, int);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, has_bottom_endcap, bool);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, has_top_endcap, bool);

	ADD_SIGNAL_FOR_ENTITY(mesh,cuboid, x_extent,double);
	ADD_SIGNAL_FOR_ENTITY(mesh,cuboid, y_extent, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,cuboid, z_extent, double);

	ADD_SIGNAL_FOR_ENTITY(mesh,cylinder, length, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,cylinder, radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,cylinder, rings, int);
	ADD_SIGNAL_FOR_ENTITY(mesh,cylinder, slices, int);

	ADD_SIGNAL_FOR_ENTITY(mesh,plane, height, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,plane, width, double);

	ADD_SIGNAL_FOR_ENTITY(mesh,torus, minor_radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,torus, radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,torus, rings, int);
	ADD_SIGNAL_FOR_ENTITY(mesh,torus, slices, int);


};
