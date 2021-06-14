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
#include <qabstractcameracontroller.h>



/// @brief  class holds the camera current possition settings
class property_camera : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	property_camera(QString parentPath, QWidget *parent = Q_NULLPTR);
	/// @brief default destructor
	~property_camera();

	//camera
	Qt3DRender::QCamera* camera_camera;

	//view all button
	QPushButton* btn_view_all;



private:
	QString parentPath_;
	ADD_JSON_LOADER(camera)

	ADD_XYZ_PICKER_PROPERTY_DEFINITION(camera, camera, position);
	ADD_XYZ_PICKER_PROPERTY_DEFINITION(camera, camera, view_center);
	ADD_XYZ_PICKER_PROPERTY_DEFINITION(camera, camera, up_vector);

public:
	/// @brief initialisation function to call in constructor and set all data from json to different properties in widget window
	void send_initialization_data()
	{
		for (auto& e : e_vec_func_double) {
			qDebug() << "BEGIN::QMetaObject::invokeMethod(" << e.signal_name.toStdString().data() << "," << e.signal_data << ") - invoke data  ";
			bool result = QMetaObject::invokeMethod(this,
				e.signal_name.toStdString().data(),
				Qt::QueuedConnection,
				Q_ARG(double, e.signal_data));

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
	/// @brief list of all signals and their datas type of QVector3D
	std::vector<delayed_emit<QVector3D>> e_vec_func_QVector3D;

signals:

	///@brief dummy signal for prevent macroses changing - do nothing
	void property_camera_type_signal();

	///// @brief send current camera controller type from json
	//void property_camera_current_camera_controller_signal(int);

	//camera 
	ADD_SIGNAL_FOR_ENTITY(camera, camera, aspect_ratio, float);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, bottom, float);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, exposure, float);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, far_plane, float);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, near_plane, float);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, field_of_view, float);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, left, float);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, right, float);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, top, float);
						  
	ADD_SIGNAL_FOR_ENTITY(camera, camera, position, QVector3D);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, view_center, QVector3D);
	ADD_SIGNAL_FOR_ENTITY(camera, camera, up_vector, QVector3D);
						  
	ADD_SIGNAL_FOR_ENTITY(camera, camera, projection_type, Qt3DRender::QCameraLens::ProjectionType);
						  
	ADD_SIGNAL_FOR_ENTITY(camera, camera, projection_matrix, QMatrix4x4);

public slots:
	/// @brief slot to set current camera to pointer from camera in viewport
	void property_camera_camera_slot(Qt3DRender::QCamera* camera)
	{
		camera_camera = camera;

		connect(camera_camera, &Qt3DRender::QCamera::positionChanged, this, &property_camera::property_camera_possition_slot);
		connect(camera_camera, &Qt3DRender::QCamera::viewVectorChanged, this, &property_camera::property_camera_view_center_slot);
		connect(camera_camera, &Qt3DRender::QCamera::upVectorChanged, this, &property_camera::property_camera_up_vector_slot);
	};

public slots:
		
	/// @brief camera possition slot to change spinboxes values in menu if camera possition changed from another sources. For example from drag camera from viewport.
	/// @param pos New updated data
	/// @return void
		void property_camera_possition_slot(const QVector3D& pos)
		{
			//qDebug() << Q_FUNC_INFO;
			bool_camera_camera_position = false;
			xyz_picker_camera_position->setXYZ(pos);
			bool_camera_camera_position = true;
		}

	/// @brief camera view center slot to change spinboxes values in menu if camera view center slot changed from another sources. For example from drag camera from viewport.
	/// @param pos New updated data
	/// @return void
		void property_camera_view_center_slot(const QVector3D& pos)
		{
			//qDebug() << Q_FUNC_INFO;
			bool_camera_camera_view_center = false;
			xyz_picker_camera_view_center->setXYZ(pos);
			bool_camera_camera_position = true;
		}

	 /// @brief camera view center slot to change spinboxes values in menu if camera up vector slot changed from another sources. For example from drag camera from viewport.
	 /// @param pos New updated data
	 /// @return void
		void property_camera_up_vector_slot(const QVector3D& pos)
		{
			//qDebug() << Q_FUNC_INFO;
			bool_camera_camera_up_vector = false;
			xyz_picker_camera_up_vector->setXYZ(pos);
			bool_camera_camera_up_vector = true;
		}


};
