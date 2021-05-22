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

	void setColor(int r, int g, int b)
	{
		spinbox_r->setValue(r);
		spinbox_g->setValue(g);
		spinbox_b->setValue(b);
	}

signals:
	void color_picker_signal(QColor);
	void color_picker_signal_int(int r, int g, int b);

public :
	QColor getColor()
	{
		return QColor(
			spinbox_r->value(),
			spinbox_g->value(),
			spinbox_b->value());
	}

private slots:
	void color_changed_(int)
	{
		emit color_picker_signal(QColor(
			spinbox_r->value(),
			spinbox_g->value(),
			spinbox_b->value()));

		emit color_picker_signal_int(
			spinbox_r->value(),
			spinbox_g->value(),
			spinbox_b->value()
		);
	}



};
