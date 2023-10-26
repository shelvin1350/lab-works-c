#include <stdio.h>
int queue[15], rear=-1, front=-1;
void enqueue(int e)
{
	if(rear+1==15)
	{
		printf("Queue is full");
	}
	else
	{
		if(front==-1)
		{
			front++;
		}
		queue[++rear]=e;
	}
}
void dequeue()
{
	if(front==-1)
	{
		printf("Queue is empty");
	}
	else if(front==rear)
	{
		printf("Dequeued element is %d", queue[front]);
		front=rear=-1;
	}
	else
	{
		printf("Dequeued element is %d", queue[front++]);
	}	
}
int main()
{
	enqueue(10);
	enqueue(29);
	enqueue(43);
	enqueue(98);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	return 0;
}
