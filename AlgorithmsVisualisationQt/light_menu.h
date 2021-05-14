#pragma once

#include <QWidget>

#include <Qt3DRender/qpointlight.h>
#include <Qt3DCore/qtransform.h>

#include <qgroupbox.h>
#include <qspinbox.h>
#include <qlabel.h>
#include<qgridlayout.h>

#include "color_picker.h"

class light_menu : public QWidget
{
	Q_OBJECT

public:
	light_menu(QWidget *parent = Q_NULLPTR);
	~light_menu();

private:
	QDoubleSpinBox* spinbox_intensity;
	color_picker* property_color;

signals:
	void light_intencity_signal(float);
	void light_color_signal(QColor);

};
