#pragma once

#include <QWidget>

#include <Qt3DRender/qpointlight.h>
#include <Qt3DCore/qtransform.h>

#include <qgroupbox.h>
#include <qspinbox.h>
#include <qlabel.h>
#include<qgridlayout.h>

class light_menu : public QWidget
{
	Q_OBJECT

public:
	light_menu(QWidget *parent = Q_NULLPTR);
	~light_menu();

private:
	QDoubleSpinBox* spinbox_intensity;
	QSpinBox* spinbox_r;
	QSpinBox* spinbox_g;
	QSpinBox* spinbox_b;

signals:
	void light_intencity_signal(float);
	void light_color_signal(QColor);

	private slots:
	void light_color_changed_(int x)
	{
		emit light_color_signal(QColor(
			spinbox_r->value(),
			spinbox_g->value(),
			spinbox_b->value()
		));
	};

};
