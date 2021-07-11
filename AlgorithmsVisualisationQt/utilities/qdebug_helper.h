#pragma once
#include <QtGlobal>
#include <QDateTime>

#include <tuple>

template<typename ...Ts>
static void qDebug_(Ts...args)
{
	//qDebug res;

	auto t = std::make_tuple(args...);

	/*apply([&](auto&&... args))
	{
		((res << args << " "), ...);
	}, t);*/

};