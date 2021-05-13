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

//debug
#include "qdebug_helper.h"


class camera_menu : public QWidget
{
	Q_OBJECT

public:
	camera_menu(QWidget *parent = Q_NULLPTR);
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

	bool viewport_possition_signal_was_recived = false;
	bool viewport_view_center_signal_was_recived = false;


signals:
		void camera_possition_signal(QVector3D pos);
		void camera_view_center_signal(QVector3D pos);
		void camera_controller_signal(int val);

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
