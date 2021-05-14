#pragma once

#include <QWidget>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qspinbox.h>

class color_picker : public QWidget
{
	Q_OBJECT
private:
	QSpinBox* spinbox_r;
	QSpinBox* spinbox_g;
	QSpinBox* spinbox_b;
public:
	color_picker(QString label,QWidget *parent = Q_NULLPTR);
	~color_picker();

signals:
	void color_picker_signal(QColor);

private slots:
	void color_changed_(int)
	{
		emit color_picker_signal(QColor(
			spinbox_r->value(),
			spinbox_g->value(),
			spinbox_b->value()
		));
	}

};
