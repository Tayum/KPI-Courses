#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RobotsNWeapons.h"

struct Weapon {
	char name[10];
	int damage;
	int feature; //1,2,3
} knife, gun, laser;

struct Robot {
	char name[50];
	int strength;
	int agility;
	int intelligence;
	int hp; //default = 100
	int free_slots;
	int busy_slots;
	struct Weapon robotWeapon;
};

void updateWeapons() {
	//Knife
	strcpy(knife.name, "Knife");
	knife.damage = 30;
	knife.feature = 1;
	//Gun
	strcpy(gun.name, "Gun");
	gun.damage = 40;
	gun.feature = 2;
	//Laser
	strcpy(laser.name, "Laser");
	laser.damage = 55;
	laser.feature = 3;
}

void updateRobotInfo(struct Robot *robotStructPtr) {
	//Initialize weapons.
	updateWeapons();
	//Add info to the robot.
	puts("Please, enter such stuff: ");
	puts("Name : ");
	gets_s(robotStructPtr->name, 50 * sizeof(char));
	puts("Strength : ");
	gets_s(robotStructPtr->strength, sizeof(int));
	puts("Agility : ");
	gets_s(robotStructPtr->agility, sizeof(int));
	puts("Intelligence : ");
	gets_s(robotStructPtr->intelligence, sizeof(int));
	puts("Weapon : ");
	char choice[10];
	gets_s(choice, 10 * sizeof(char));
	if ((strcmp(choice, "Knife")) == 0) {
	//	robotStructPtr->robotWeapon = knife;
	}
	else if ((strcmp(choice, "Gun")) == 1) {
	//	robotStructPtr->robotWeapon = gun;
	}
	else if ((strcmp(choice, "Laser")) == 2) {
	//	robotStructPtr->robotWeapon = laser;
	}
	else {
		puts("Incorrect input");
		
	}

	//HP, free_slots and busy_slots will be set by default: 100, 3, 0.
	robotStructPtr->hp = 100;
	robotStructPtr->free_slots = 4;
	robotStructPtr->busy_slots = 0;

}
void displayInfo(struct Robot *robotStructPtr) {
	printf("Name : %s\n", robotStructPtr->name);
	printf("Strength : %d\n", robotStructPtr->strength);
	printf("Agility : %d\n", robotStructPtr->agility);
	printf("Intelligence : %d\n", robotStructPtr->intelligence);
	printf("HP : %d\n", robotStructPtr->hp);
	printf("Free slots : %d\n", robotStructPtr->free_slots);
}

void behavior() {


}