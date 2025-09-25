#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
	item_list[index].price = price;
	item_list[index].sku = malloc(strlen(sku) + 1);
	strcpy(item_list[index].sku, sku);
	item_list[index].name = malloc(strlen(name) + 1);
	strcpy(item_list[index].name, name);
	item_list[index].category = malloc(strlen(name) + 1);
	strcpy(item_list[index].category, category);
}

void free_items(Item *item_list, int size) {
	int i;
	for (i = 0; i < size; i++) {
		free(item_list[i].sku);
		free(item_list[i].name);	
		free(item_list[i].category);
	}
	free(item_list);
}

double average_price(Item *item_list, int size) {
	double total = 0;
	int i;
	for (i = 0; i < size; i++) {
		total += item_list[i].price;
	}
	return total / size;
}

void print_items(Item *item_list, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("###############\n");
		printf("item name = %s\n", item_list[i].name);
        	printf("item sku = %s\n", item_list[i].sku);
        	printf("item category = %s\n", item_list[i].category);
        	printf("item price = %f\n", item_list[i].price);
    	}
    	printf("###############\n");
}

int main(int argc, char *argv[]) {
	int size = 5;
	Item *items = malloc(sizeof(Item) * size);
	add_item(items, 5.00, "19282", "breakfast", "reese's cereal", 0);
	add_item(items, 3.95, "79862", "dairy", "milk", 1);
	add_item(items, 9.88, "14512", "cleaning", "laundry detergent", 2);
        add_item(items, 6.36, "37846", "produce", "apples", 3);
        add_item(items, 6.21, "01927", "meat", "bacon", 4);
   
        print_items(items, size);
    
        double avg = average_price(items, size);
        printf("average price of items = %f\n", avg);
   
        if (argc > 1) {
		char *search_sku = argv[1];
                int ct = 0;
                while (ct < size && strcmp(items[ct].sku, search_sku) != 0) {
			ct++;
		}
                if (ct < size) {
			printf("\nItem found:\n");
                        printf("###############\n");
                        printf("item name = %s\n", items[ct].name);
                        printf("item sku = %s\n", items[ct].sku);
                        printf("item category = %s\n", items[ct].category);
                        printf("item price = %f\n", items[ct].price);
			printf("###############\n");
		} else {
			printf("\nItem not found.\n");
		}
	}	

	free_items(items,size);

	return 0;
}
