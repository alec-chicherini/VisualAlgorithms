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

signals:
		void camera_possition_signal(QVector3D pos);
		void camera_view_center_signal(QVector3D pos);
		void camera_controller_signal(int val);

private slots:

	void camera_possition_update_(double value)
	{
		emit camera_possition_signal(QVector3D(
			(float)spinbox_possition_x->value(),
			(float)spinbox_possition_y->value(),
			(float)spinbox_possition_z->value()));
	}

	void camera_view_center_update_(double value)
	{
		emit camera_view_center_signal(QVector3D(
			(float)spinbox_view_center_x->value(),
			(float)spinbox_view_center_y->value(),
			(float)spinbox_view_center_z->value()));
	}

public slots:

		void camera_possition_slot(const QVector3D& pos) 
		{
			const QSignalBlocker sb1(spinbox_possition_x);
			const QSignalBlocker sb2(spinbox_possition_y);
			const QSignalBlocker sb3(spinbox_possition_z);

			spinbox_possition_x->setValue(pos.x());
			spinbox_possition_y->setValue(pos.y());
			spinbox_possition_z->setValue(pos.z());
		}

		void camera_view_center_slot(const QVector3D& pos)
		{
			spinbox_view_center_x->blockSignals(true);
			spinbox_view_center_y->blockSignals(true);
			spinbox_view_center_z->blockSignals(true);

			spinbox_view_center_x->setValue(pos.x());
			spinbox_view_center_y->setValue(pos.y());
			spinbox_view_center_z->setValue(pos.z());

			spinbox_view_center_x->blockSignals(false);
			spinbox_view_center_y->blockSignals(false);
			spinbox_view_center_z->blockSignals(false);
		}

};
