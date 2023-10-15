#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

struct node{
	int id;
    char name[max];
    int quantity;
    float price;
    struct node* next;
};
typedef struct node inventory;
inventory *head=NULL;
void insertInventory(int id, char name[max], int quantity, float price);


void acceptItems()
{
	int id;
    char name[max];
    int quantity;
    float price;
    
    printf("Enter the id :");
    scanf("%d", &id);
    printf("Enter the name of the item: ");
    scanf("%s", name);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    printf("Enter the price: ");
    scanf("%f", &price);
    
    insertInventory(id, name, quantity, price);
}

void insertInventory(int id, char name[max], int quantity, float price)
{
	inventory *check=head;
	int flag=0;
	while(check!=NULL)
	{
		if(check->id==id)
		{
			flag=1;
		}
		check=check->next;
	}
	if(flag==1)
	{
		printf("\nError!! ID already exist...\n\n");
		return;
	}
	inventory *temp=(inventory *)malloc(sizeof(inventory));
	temp->id=id;
	strcpy(temp->name, name);
	temp->quantity=quantity;
	temp->price=price;
	
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
	}
	
	else
	{
		inventory *t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
		t->next->next=NULL;
	}
	printf("\n\n");
}

void displayInventory()
{
	int i;
	if(head==NULL)
	{
		printf("\n\nNo items in the inventory "); 
	}
	else
	{
		inventory *t=head;
		printf("Items in the inventory");
		printf("\n---------------------\n");
		i=1;
		while(t!=NULL)
		{
			printf("\n\nItem %d\n", i);
			printf("---------------\n");
			printf("id: %d\n", t->id);
			printf("Item name: %s\n", t->name);
			printf("Item quantity: %d\n", t->quantity);
			printf("Item price: %f\n\n", t->price);
			
			t=t->next;
			i++;
		}
	}
}

void updateInventory(int ch)
{
	if(head==NULL)
	{
		printf("No items in the inventory "); 
	}
	else 
	{
		inventory *t=head;
		while(t->id!=ch && t!=NULL)
		{
			t=t->next;
		}
		if(t==NULL)
		{
			printf("Searched item not found!!!!\n");
			
		}
		else
		{
			printf("\n\n1-To edit ID\n2-To edit item name\n3-To edit quantity\n4-To edit price\n_________\nEnter your choice: ");
			scanf("%d", &ch);
			switch(ch)
			{
				case 1:
					printf("Enter the updated ID: ");
					scanf("%d", &t->id);
					break;
				case 2:
					printf("Enter the updated name of the item: ");
					scanf("%s", t->name);
					break;
				case 3:
					printf("Enter the updated quantity: ");
    				scanf("%d", &t->quantity);
    				break;
    			case 4:
    				printf("Enter the price: ");
    				scanf("%f", &t->price);
    				break;
    			default:
    				printf("Invalid choice!!");
			}
    		
		}
	}
}
void delete(int id)
{
	if(head==NULL)
	{
		printf("The inventory is empty!!");
	}
	else
	{
		if(head->id==id)
		{
			head=head->next;
		}
		else
		{
			inventory *t=head;
			while(t->next!=NULL && t->next->id!=id)
			{
				t=t->next;
			}
			if(t->next==NULL)
			{
				printf("Element not found!!");
				return;
			}
			printf("Deleted!!");
			t->next=t->next->next;
		}
	}
}

void searchInventory(int n)
{
	
	inventory *t=head;
	while(t->id!=n && t!=NULL)
	{
		t=t->next;
	}
	if(t==NULL)
	{
		printf("Element not found!!!");
	}
	else
	{
		printf("Item found !!\n");
		printf("---------------\n");
		printf("id: %d\n", t->id);
		printf("Item name: %s\n", t->name);
		printf("Item quantity: %d\n", t->quantity);
		printf("Item price: %f\n", t->price);
	}
}


void saveInventoryToFile(const char *filename) 
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
	{
        perror("Error opening file");
        return;
    }

    inventory *t = head;
    int i=1;
    while (t != NULL) 
	{
		
        fprintf(file, "Item %d\n\nID: %d \nName: %s \nQuantity: %d \nPrice: %.2f\n\n", i, t->id, t->name, t->quantity, t->price);
        t = t->next;
        i++;
    }
    printf("File saved successfully");

    fclose(file);
}

int menu()
{
	int ch;
	printf("1-Add items to inventory\n2-Display items in the inventory\n");
	printf("3-Update any item in the inventory\n4-Deleting items in inventory\n5-Searching in inventory\n6-To save the inventory items as txt file\n7-Exit\n\nEnter your choice: ");
	scanf("%d", &ch);
	printf("\n\n");
	return ch;
}

void process()
{
	int i, n;
	for(i=menu(); i!=7; i=menu())
	{
		switch(i)
		{
			case 1:
				acceptItems();
				break;
			case 2:
				displayInventory();
				break;
			case 3:
				if(head==NULL)
				{
					printf("No items in the inventory "); 
					return;
				}
				else
				{
				
					printf("Enter the id of the item you want to be updated: ");
					scanf("%d", &n);
					updateInventory(n);
				}
				break;
			case 4:
				if(head==NULL)
				{
					printf("No items in the inventory "); 
					return;
				}
				else
				{
					printf("Enter the id of the item you want to be deleted: ");
					scanf("%d", &n);
					delete(n);
				}
				break;
			case 5:
				if(head==NULL)
				{
					printf("No items in the inventory "); 
					return;
				}
				else
				{
					printf("Enter the id for searching");
					scanf("%d", &n);
					searchInventory(n);
				}
				break;
			case 6:
				
				saveInventoryToFile("inventory.txt");
				
				break;
			default:
				printf("Invalid choice");
		}
	}
}
void main()
{
	printf("\nWelcome to inventory management system!!\n");
	printf("==========================================\n");
	process();
}


