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
	/// @brief default constructor
	light_menu(QWidget *parent = Q_NULLPTR);
	/// @brief default destructor
	~light_menu();

private:
	QDoubleSpinBox* spinbox_intensity;
	color_picker* property_color;

signals:
	/// @brief signal emits on intencity change from this this
	void light_intencity_signal(float);
	/// @brief signal emits on color change from this this
	void light_color_signal(QColor);

};
