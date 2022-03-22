#include"sll_node.h"

bool check(Node* root, int value)
{
	Node* current = root;
	while (current!=NULL)
	{
		if (current->value!=value)
		{
			current = current->next;
		}
		else
		{
			break;
		}
	}
	if (current=NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}