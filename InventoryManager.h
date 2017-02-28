#if !defined _INVENTORYMANAGER_H
#define _INVENTORYMANAGER_H

#include "Widget.h"
#include "QueueDeque.h"
#include "StackDeque.h"

class InventoryManager
{
	private:
		double profit;
		int inventory_choice; //1 for stack, 2 for queue

		StackDeque<Widget>* stack;		
		QueueDeque<Widget>* queue;
		
	public:
		InventoryManager(int choice); //LIFO or FIFO & constructor
		~InventoryManager(); //destructor
		
		void buyWidgets(double cost, int num_to_buy);
		double getTotalProfit();
		double sellWidgets(double price, int num_to_sell);
}

#endif