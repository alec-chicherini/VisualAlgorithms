#pragma once

#include <QWidget>
//camera controller
#include <Qt3DExtras/qfirstpersoncameracontroller.h>

//camera
#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>

#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qcombobox.h>
#include <qpushbutton.h>

//debug
#include "qdebug_helper.h"

/// @brief  class holds the global camera current possition settings
class camera_menu : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	camera_menu(QWidget *parent = Q_NULLPTR);
	/// @brief default destructor
	~camera_menu();


private:

	QDoubleSpinBox* spinbox_possition_x;
	QDoubleSpinBox* spinbox_possition_y;
	QDoubleSpinBox* spinbox_possition_z;

	QDoubleSpinBox* spinbox_view_center_x;
	QDoubleSpinBox* spinbox_view_center_y;
	QDoubleSpinBox* spinbox_view_center_z;

	QSpinBox* spinbox_fov;

	QComboBox* combobox_projection;

	QComboBox* combobox_camera_controller;
	
	QPushButton* pushbtn_camera_view_all;

	bool viewport_possition_signal_was_recived = false;
	bool viewport_view_center_signal_was_recived = false;


signals:
		/// @brief camera possition signal
		/// @param pos Current QVector3D data from spinboxes in this widget.
		void camera_possition_signal(QVector3D pos);

		/// @brief camera view center signal
		/// @param pos Current QVector3D data from spinboxes in this widget.
		void camera_view_center_signal(QVector3D pos);
		/// @brief camera controller type signal
		/// @param val if  0 camera first person, if 1 camera is orbit
		void camera_controller_signal(int val);
		/// @brief send signal if button View All pressed
		void camera_view_all_signal();

private slots:


	void camera_possition_update_(double value)
	{

		qDebug() << QDateTime::currentDateTimeUtc()<<QString("<----- call camera_possition_update_")<<QString::number(viewport_possition_signal_was_recived);
		if (viewport_possition_signal_was_recived == true)  viewport_possition_signal_was_recived = false;
		else emit camera_possition_signal(QVector3D(
			(float)spinbox_possition_x->value(),
			(float)spinbox_possition_y->value(),
			(float)spinbox_possition_z->value()));
	}

	void camera_view_center_update_(double value)
	{

		qDebug() << QDateTime::currentDateTimeUtc()<< QString("<----- call camera_view_center_update_") << QString::number(viewport_view_center_signal_was_recived);
		if (viewport_view_center_signal_was_recived == true)  viewport_view_center_signal_was_recived = false;
		else emit camera_view_center_signal(QVector3D(
			(float)spinbox_view_center_x->value(),
			(float)spinbox_view_center_y->value(),
			(float)spinbox_view_center_z->value()));
	}

public slots:
		
	/// @brief camera possition slot to change spinboxes values in menu if camera possition changed from another sources. For example from drag camera from viewport.
	/// @param pos New updated possition of camera
	/// @return void
		void camera_possition_slot(const QVector3D& pos) 
		{
			qDebug() << QDateTime::currentDateTimeUtc()<< QString("<----- call camera_possition_slot") << QString::number(viewport_possition_signal_was_recived);
		
			viewport_possition_signal_was_recived = true;
			spinbox_possition_x->setValue(pos.x());
			viewport_possition_signal_was_recived = true;
			spinbox_possition_y->setValue(pos.y());
			viewport_possition_signal_was_recived = true;
			spinbox_possition_z->setValue(pos.z());
		}
		/// @brief camera view center slot to change spinboxes values in menu if camera view center slot changed from another sources. For example from drag camera from viewport.
		/// @param pos New updated camera view port slot of camera
		/// @return void
		void camera_view_center_slot(const QVector3D& pos)
		{
			qDebug() << QDateTime::currentDateTimeUtc()<< QString("<----- call camera_view_center_slot") << QString::number(viewport_view_center_signal_was_recived);
	
			viewport_view_center_signal_was_recived = true;
			spinbox_view_center_x->setValue(pos.x());
			viewport_view_center_signal_was_recived = true;
			spinbox_view_center_y->setValue(pos.y());
			viewport_view_center_signal_was_recived = true;
			spinbox_view_center_z->setValue(pos.z());

		}

};
