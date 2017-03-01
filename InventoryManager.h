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
	/*constructor & destructor*/
		//pre: takes choice as parameter, applies choice to inventory_choice and creates pointer (stack or queue) based on choice parameter, initializes profit
		//post: returns nothing
		InventoryManager(int choice);
		
		//pre: takes nothing, delete both stack and queue pointers
		//post: returns nothing
		~InventoryManager(); //destructor
		
	/*methods*/
		//pre: takes cost and num_to_buy as parameter, check user's choice from InventoryManager and use stack's push() or queue's enqueue() as necessary
		//post: returns nothing
		void buyWidgets(double cost, int num_to_buy);
		
		//pre: takes nothing
		//post: returns profit in private class
		double getTotalProfit();
		
		//pre: takes price and num_to_sell as parameter, check user's choice from InventoryManager, get size of either, then proceed to remove item from back of array (stack) or remove item from front of array (queue) and calculate profit based on each iteration it gets
		//post: returns profit calculated from either operation based on user choice
		double sellWidgets(double price, int num_to_sell);
};

#endif