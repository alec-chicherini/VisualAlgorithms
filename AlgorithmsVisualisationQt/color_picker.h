#pragma once

#include <QWidget>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qspinbox.h>

/// @brief widget consists spinboxes signals and slots to work with rgb colors 
class color_picker : public QWidget
{
	Q_OBJECT
private:
	QSpinBox* spinbox_r;
	QSpinBox* spinbox_g;
	QSpinBox* spinbox_b;
public:
	/// @brief default constructor
	/// @param label current label.
	/// @param parent parent for this widget
	color_picker(QString label,QWidget *parent = Q_NULLPTR);

	/// @brief default destructor
	~color_picker();

	/// @brief set color
	/// @param r red 0-255
	/// @param g green 0-255
	/// @param b blue 0-255
	void setColor(int r, int g, int b)
	{
		spinbox_r->setValue(r);
		spinbox_g->setValue(g);
		spinbox_b->setValue(b);
	}

signals:
	/// @brief on changing one of spinboxes this signal with QColor send
	void color_picker_signal(QColor);
	/// @brief on changing one of spinboxes this signal with R,G,B send
	void color_picker_signal_int(int, int, int);

public :
	/// @brief slot to take color from this
	/// @return color from this
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
