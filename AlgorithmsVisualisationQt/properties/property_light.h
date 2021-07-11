#pragma once

#include <QWidget>

#include <Qt3DRender/qpointlight.h>
#include <Qt3DCore/qtransform.h>

#include <qgroupbox.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlabel.h>
#include <qpushbutton.h>

#include<qgridlayout.h>

#include "color_picker.h"
#include "xyz_picker.h"

#include "property_macros.h"

#include "qstackedlayout.h"

#include <qjsonobject.h>
#include <qfile.h>
#include <qdir.h>
#include <qjsondocument.h>
#include <qjsonvalue.h>
#include <qbytearray.h>

class property_light : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	property_light(QString parentPath, QWidget *parent = Q_NULLPTR);
	/// @brief default destructor
	~property_light();

private:
	QComboBox* combobox_light;
	QString parentPath_;

	ADD_JSON_LOADER(directional);
	ADD_JSON_LOADER(point);
	ADD_JSON_LOADER(spot);
	ADD_JSON_LOADER(current_light_index);

	ADD_XYZ_PICKER_PROPERTY_DEFINITION(light, directional, world_direction);
	ADD_XYZ_PICKER_PROPERTY_DEFINITION(light, spot, local_direction);
	ADD_XYZ_PICKER_PROPERTY_DEFINITION(light, spot, possition);
	ADD_XYZ_PICKER_PROPERTY_DEFINITION(light, directional, possition);
	ADD_XYZ_PICKER_PROPERTY_DEFINITION(light, point, possition);

public slots:
	void property_light_possition_slot(QVector3D pos)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";

		xyz_picker_point_possition->setXYZ(pos);
		xyz_picker_spot_possition->setXYZ(pos);
		xyz_picker_directional_possition->setXYZ(pos);
	};

	void property_light_direction_slot(QVector3D pos)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";

		xyz_picker_directional_world_direction->setXYZ(pos);
		xyz_picker_spot_local_direction->setXYZ(pos);
	};
signals:
	/// @brief type of current light
	void property_light_type_signal(int);

	void property_light_possition_signal(bool);

	ADD_SIGNAL_FOR_ENTITY(light, point, color, QColor);
	ADD_SIGNAL_FOR_ENTITY(light, point, intensity, double);
	ADD_SIGNAL_FOR_ENTITY(light, point, constant_attenuation, double);
	ADD_SIGNAL_FOR_ENTITY(light, point, linear_attenuation, double);
	ADD_SIGNAL_FOR_ENTITY(light, point, quadratic_attenuation, double);
	ADD_SIGNAL_FOR_ENTITY(light, point, possition, QVector3D);

	ADD_SIGNAL_FOR_ENTITY(light, directional, color, QColor);
	ADD_SIGNAL_FOR_ENTITY(light, directional, intensity, double);
	ADD_SIGNAL_FOR_ENTITY(light, directional, world_direction, QVector3D);
	ADD_SIGNAL_FOR_ENTITY(light, directional, possition, QVector3D);

	ADD_SIGNAL_FOR_ENTITY(light, spot, color, QColor);
	ADD_SIGNAL_FOR_ENTITY(light, spot, intensity, double);
	ADD_SIGNAL_FOR_ENTITY(light, spot, constant_attenuation, double);
	ADD_SIGNAL_FOR_ENTITY(light, spot, linear_attenuation, double);
	ADD_SIGNAL_FOR_ENTITY(light, spot, quadratic_attenuation, double);
	ADD_SIGNAL_FOR_ENTITY(light, spot, cut_off_angle, double);
	ADD_SIGNAL_FOR_ENTITY(light, spot, local_direction, QVector3D);
	ADD_SIGNAL_FOR_ENTITY(light, spot, possition, QVector3D);

public:

	/// @brief plain structure to store signal name and signal data
	template <typename T>
	struct 	delayed_emit
	{
		QString signal_name;
		T signal_data;
	};
	/// @brief list of all signals and their datas type of double
	std::vector<delayed_emit<double>> e_vec_func_double;
	/// @brief list of all signals and their datas type of int
	std::vector<delayed_emit<int>> e_vec_func_int;
	/// @brief list of all signals and their datas type of QColor
	std::vector<delayed_emit<QColor>> e_vec_func_QColor;
	/// @brief list of all signals and their datas type of QVector3D
	std::vector<delayed_emit<QVector3D>> e_vec_func_QVector3D;
	

	/// @brief initialisation function to call in constructor and set all data from json to different properties in widget window
	void send_initialization_data()
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		//emit property_mesh_type_signal(combobox_mesh->currentIndex());

		QMetaObject::invokeMethod(this,
			"property_light_type_signal",
			Qt::QueuedConnection,
			Q_ARG(int, combobox_light->currentIndex()));

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

		for (auto& e : e_vec_func_QColor)
		{
			qDebug() << "BEGIN::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ") - invoke data";
			bool result = QMetaObject::invokeMethod(this,
				e.signal_name.toStdString().data(),
				Qt::QueuedConnection,
				Q_ARG(QColor, e.signal_data));

			qDebug() << "END::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ")invoke result is: " << result;
		}

		for (auto& e : e_vec_func_QVector3D) {
			qDebug() << "BEGIN::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ") - invoke data  ";
			bool result = QMetaObject::invokeMethod(this,
				e.signal_name.toStdString().data(),
				Qt::QueuedConnection,
				Q_ARG(QVector3D, e.signal_data));

			qDebug() << "END::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ")invoke result is: " << result;
		}
	};
};
