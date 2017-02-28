#include "Widget.h"

#include <iostream>
using namespace std;

Widget::Widget(double cos)
{
	cost = cos;
}

Widget::~Widget()
{
}

double Widget::getCost()
{
	return cost;
}