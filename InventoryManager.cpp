#include "InventoryManager.h"

#include <iostream>
using namespace std;

InventoryManager::InventoryManager(int inv_choice)
{
	inventory_choice = inv_choice;
	profit = 0.0;
	
	if (inventory_choice == 1) //stack 
		stack = new StackDeque<Widget>();
	else
		queue = new QueueDeque<Widget>();
}

InventoryManager::~InventoryManager()
{
	delete stack;
	delete queue;
}

void InventoryManager::buyWidgets(double cost, int num_to_buy)
{
	if (num_to_buy < 1) return; //checking input
	
	for (int i = 0; i < num_to_buy; i++)
	{
		Widget* wg = new Widget(cost);
		
		if (inventory_choice == 1)
			stack->push(wg);
		else
			queue->enqueue(wg);
	}
}

double InventoryManager::getTotalProfit()
{
	return profit;
}

double InventoryManager::sellWidgets(double price, int num_to_sell)
{
	Widget* wg;
	
	// getting size of stack/queue
	// if (inventory_choice == 1)
		// int stack_size = stack->size();
	// else
		// int queue_size = queue->size();
	
	//checking input
	if (num_to_sell < 0) return profit;
	
	//checking if input is greater than stack
	if (inventory_choice == 1)
	{
		if (num_to_sell > stack->size())
			num_to_sell = stack->size();
	}
	else
	{
		if (num_to_sell > queue->size())
			num_to_sell = queue->size();
	}		
	
	//calculating profit
	if (inventory_choice == 1)
	{
		for (int i = 0; i < num_to_sell; i++)
		{
			wg = stack->pop();
			profit = profit + (price - wg->getCost());
			
			//test string
			cout << profit << endl;
		}
	}
	else
	{
		for (int i = 0; i < num_to_sell; i++)
		{
			wg = queue->dequeue();
			profit = profit + (price - wg->getCost());
			
			//test string
			cout << profit << endl;
		}
	}
	
	return profit;
}

