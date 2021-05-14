#pragma once


#include <QWidget>
#include "enums.h"

#include <qgroupbox.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qgridlayout.h>
#include <qstackedlayout.h>
#include <qcheckbox.h>
#include <qspinbox.h>
#include "property_macros.h"

class property_mesh : public QWidget
{
	Q_OBJECT

public:
	property_mesh(MeshType mt = MeshType::SPHERE, QWidget *parent = Q_NULLPTR);
	~property_mesh();

private:
	QComboBox* combobox_mesh;

signals:

	void property_mesh_shpere_radius_signal(double);
	void property_mesh_shpere_rings_signal(int);
	void property_mesh_shpere_slices_signal(int);

	void property_mesh_cone_bottom_radius_signal(double);
	void property_mesh_cone_has_bootom_endcap_signal(bool);
	void property_mesh_cone_has_top_endcap_signal(bool);
	void property_mesh_cone_length_signal(double);
	void property_mesh_cone_rings_signal(int);
	void property_mesh_cone_slices_signal(int);
	void property_mesh_cone_top_radius_signal(double);

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
