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
	ADD_JSON_LOADER(orbit)
	ADD_JSON_LOADER(first_person)
	ADD_JSON_LOADER(current_camera_controller_type)

	QComboBox* combobox_camera_controller;

public:
	/// @brief initialisation function to call in constructor and set all data from json to different properties in widget window
	void send_initialization_data()
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		QMetaObject::invokeMethod(this,
			"camera_controller_type_signal",
			Qt::QueuedConnection,
			Q_ARG(int, combobox_camera_controller->currentIndex()));


		for (auto& e : e_vec_func_double) {
			qDebug() << "BEGIN::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ") - invoke data  ";
			bool result = QMetaObject::invokeMethod(this,
				e.signal_name.toStdString().data(),
				Qt::QueuedConnection,
				Q_ARG(double, e.signal_data));

			qDebug() << "END::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ")invoke result is: " << result;
		}

	};

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
