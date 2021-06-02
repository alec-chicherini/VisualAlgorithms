#pragma once

#include <QWidget>

/// @brief property transform class
class property_transform : public QWidget
{
	Q_OBJECT

public:
	property_transform(QWidget *parent = Q_NULLPTR);
	~property_transform();

	///@brief function without return - this will not be inserted inline
	void func()
	{
		1 + 2;
		3 << 4;
		5;
	};

	///@brief function without return - this will
	///@return void
	void func2()
	{
		1 + 2;
		3 << 4;
		5;
	};
	

};


