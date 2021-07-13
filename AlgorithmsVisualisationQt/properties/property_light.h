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

	
};
