#if !defined _WIDGET_H
#define _WIDGET_H

class Widget
{
	private:
		double cost;
	
	public:
		Widget(double cos); //constructor
		~Widget(); //destructor
		
		double getCost();
};

#endif