#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct addr {
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	unsigned long int zip;
} addr_list[MAX];

//Initialise struct array
void init_list() {
	register int t;
	for (t = 0; t < MAX; t++) {
		addr_list[t].name[0] = '\0';
	}
}

//Prints what user wants
int menu_select() {
	char s[80];
	int c;
	printf("1. Input name \n");
	printf("2. Delete name \n");
	printf("3. Print the list \n");
	printf("4. Exit \n");
	do {
		printf("\nInput number of the desired item ");
		gets(s);
		c = atoi(s);
	} while (c < 0 || c>4);
	return c;
}

//Search for the free structure
int find_free() {
	register int t;
	for (t = 0; addr_list[t].name[0] && t < MAX; t++);
	if (t == MAX)
		return -1; //all structs aren`t free
	return t; //struct that is free
}

//Here the user inputs information
//Info saves into free structure
//If array is filled - the error message
void enter() {
	int slot;
	char s[80];
	slot = find_free();
	if (slot == -1) {
		printf("The list is filled ");
		return;
	}
	printf("Enter your name: ");
	gets(addr_list[slot].name);
	printf("Enter your street: ");
	gets(addr_list[slot].street);
	printf("Enter your city ");
	gets(addr_list[slot].city);
	printf("Enter your state ");
	gets(addr_list[slot].state);
	printf("Enter your zip: ");
	gets(s);
	addr_list[slot].zip = strtoul(s, '\0', 10);
}

//Deletes the struct (with index)
void delete() {
	register int slot;
	char s[80];
	printf("Enter an index pls: ");
	gets(s);
	slot = atoi(s);
	if (slot >= 0 && slot < MAX) {
		addr_list[slot].name[0] = '\0';
	}
}

//Prints everything out!
void list() {
	register int t;
	for (t = 0; t < MAX; t++) {
		if (addr_list[t].name[0]) {
			printf("%s\n", addr_list[t].name);
			printf("%s\n", addr_list[t].street);
			printf("%s\n", addr_list[t].city);
			printf("%s\n", addr_list[t].state);
			printf("%lu\n\n", addr_list[t].zip);
		}
	}

}


int main(void) {

	char choice;
	init_list();

	for (;;) {
		choice = menu_select();
		switch (choice)
		{
			case 1:
				enter();
				break;
			case 2:
				delete();
				break;
			case 3:
				list();
				break;
			case 4:
				exit(EXIT_SUCCESS);
				break;
		}
	}

	return 0;
}