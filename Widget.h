#if !defined _WIDGET_H
#define _WIDGET_H

#include <iostream>
using namespace std;

class Widget
{
	private:
		double cost;
	
	public:
		Widget(double cos); //constructor
		~Widget(); //destructor
		
		void setCost(double cos);
		double getCost();
};

#endif