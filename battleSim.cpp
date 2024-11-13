#include<iostream>
using namespace std;

//function dec;eration
void BattleSim();


// global variables: can be seen and used by all functions in the program
int PlayerHealth = 100;
int main() {

	srand(time(NULL)); // seeds rand() *keep this at the top of main

	int room = 1;
	char input;
	while (PlayerHealth > 0) {// game loop
		switch (room) {
		case 1 :
			cout << "youre in room 1 you can go (s)outh" << endl;
			cin >> input;
			if (input == 's')
				room = 2;
			break;
		case 2:
			BattleSim();
			cout << "your in room 2 you can go (s)outh and (n)orth." << endl;
			cin >> input;
			if (input == 's')
				room = 3;
			if (input == 'n')
				room = 1;
			break;
		case 3:
			BattleSim();
			cout << "your in room 3 you can go (n)orth." << endl;
			cin >> input;
			if (input == 'n')
				room = 2;
			break;
		}

	}// end of game loop
	// GAMER OVER MESSAGE CAN GO HERE0000000000000000000000000000000000000000000000000000000000000000000000000
}// end of main

//defantions
void BattleSim() {
	int MonsterHealth = 20; // local variale: this can only be seen and used by BattleSim
	int damage;
	char dummy;
	cout << endl << endl << "------------------MONSTER BATTLE BEGINS------------------" << endl;
	cout << " a spider jumps at you" << endl;
	while (PlayerHealth > 0 && MonsterHealth > 0) { // battle  loop

		//monster fight section
		damage = rand() % 11+5; // monster can bite for 0-10 (+5 to make it 5-15
		cout << "the monster bites you for "<< damage << " dmg" << endl;
		PlayerHealth -= damage;
		cout << "press any key to continue........" << endl;
		cin >> dummy;

		//player fihts
		damage = rand() % 5 + 5; // player swings 5-9
		cout << "you hit the monster for "<<damage<<" Damage" << endl;
		MonsterHealth -= damage;
		cout << "press any key to continue........" << endl;
		cin >> dummy;

		if (PlayerHealth > 0)
			cout << "You're health is now: " << PlayerHealth << endl;
		else
			cout << "you died womp womp" << endl;

		if (MonsterHealth > 0)
			cout << "The Monsters health is now : " << MonsterHealth << endl;
		else
			cout << "you destroyed the monster good job" << endl;

		cout << "press any key to continue........" << endl;
		cin >> dummy;

	}
	if (PlayerHealth > 0)
		cout << "You won!" << endl; // place of loot after kill
	else
		cout << "you lost GAME OVER" << endl;
	cout << "---------------------------END OF BATTLE------------------------------" << endl << endl;
}
