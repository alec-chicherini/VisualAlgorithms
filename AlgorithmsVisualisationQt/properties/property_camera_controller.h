#pragma once

#include <QWidget>

#include <qgridlayout.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qstackedlayout.h>

//json
#include <qjsonobject.h>
#include <qfile.h>
#include <qdir.h>
#include <qjsondocument.h>
#include <qjsonvalue.h>
#include <qbytearray.h>

#include "property_macros.h"
#include "xyz_picker.h"

//cameras environment
#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <Qt3DExtras/qorbitcameracontroller.h>
#include <Qt3DExtras/qabstractcameracontroller.h>

/// @brief  class holds the camera current possition settings
class property_camera_controller : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	property_camera_controller(QString parentPath, QWidget *parent = Q_NULLPTR);
	/// @brief default destructor
	~property_camera_controller();


private:
	QString parentPath_;
	
	QComboBox* combobox_camera_controller;

	

signals:

	///@brief emit camera controller type changed
	void property_camera_controller_type_signal(int);

	//camera controllers signals
	ADD_SIGNAL_FOR_ENTITY(camera_controller, first_person, acceleration, float);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, first_person, deceleration, float);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, first_person, linear_speed, float);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, first_person, look_speed, float);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, first_person, camera, Qt3DRender::QCamera*);
						  
	ADD_SIGNAL_FOR_ENTITY(camera_controller, orbit, acceleration, float);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, orbit, deceleration, float);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, orbit, linear_speed, float);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, orbit, look_speed, float);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, orbit, camera, Qt3DRender::QCamera*);
	ADD_SIGNAL_FOR_ENTITY(camera_controller, orbit, zoom_in_limit, float);
	
	
};
