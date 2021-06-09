#pragma once

#include <QWidget>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qvector3d.h>

#include <qdebug.h>

/// @brief widget consists double spinboxes signals and slots to work with XYZ coordinates
class xyz_picker : public QWidget
{
	Q_OBJECT
private:
	QDoubleSpinBox* spinbox_x;
	QDoubleSpinBox* spinbox_y;
	QDoubleSpinBox* spinbox_z;
public:
	/// @brief default constructor
	/// @param label current label.
	/// @param parent parent for this widget
	xyz_picker(QString label,QWidget *parent = Q_NULLPTR);

	/// @brief default destructor
	~xyz_picker();

	/// @brief set xyz
	/// @param x coordinate
	/// @param y coordinate 
	/// @param z coordinate 
	void setXYZ(double x, double y, double z)
	{
		spinbox_x->setValue(x);
		spinbox_y->setValue(y);
		spinbox_z->setValue(z);
	}

	void setXYZ(QVector3D vec)
	{
		spinbox_x->setValue(double(vec.x()));
		spinbox_y->setValue(double(vec.y()));
		spinbox_z->setValue(double(vec.z()));
	}

signals:
	/// @brief on changing one of spinboxes this signal with QVector3D send
	void xyz_picker_signal(QVector3D);
	/// @brief on changing one of spinboxes this signal with X,Y,Z send
	void xyz_picker_signal_double(double, double, double);

public :
	/// @brief slot to take xyz from this
	/// @return xyz from this
	QVector3D getXYZ()
	{
		return QVector3D(
			spinbox_x->value(),
			spinbox_y->value(),
			spinbox_z->value());
	}

private slots:
	void xyz_changed_(double)
	{
		emit xyz_picker_signal(QVector3D(
			spinbox_x->value(),
			spinbox_y->value(),
			spinbox_z->value()));

		emit xyz_picker_signal_double(
			spinbox_x->value(),
			spinbox_y->value(),
			spinbox_z->value()
		);
	}


};
