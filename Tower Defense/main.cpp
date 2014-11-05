/* 
 * File:   main.cpp
 * Author: samuel beland-leblanc
 *
 * Created on October 1, 2014, 5:27 PM
 */

#include<iostream>
#include <cstdlib>

#include "SplashTower.h"
#include "TowerManager.h"
#include "TowerObserver.h"

using namespace std;

/*
 * 
 */

void print(Tower& t, Critter** c) {

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {

            if (t.getX() == j && t.getY() == i) {
                cout << "t";
            } else {
				bool dotMade = false;
				for (int k = 0; k < 3; k++){
					if (c[k]->getX() == j && c[k]->getY() == i) {
						if (c[k]->GetState() == CritterState::Alive){
							cout << "c";
							break;
						}
						else{
							cout << "d";
							break;
						}

					}
					else if (!dotMade){
						cout << ".";
						dotMade = true;
					}
				}
                /**/
            }


        }
        cout << "|\n";
    }

}

/*

Every moving object is a MapEntity

They are Towers and SplashTowers (which are a specialisation of the Towers)

The Towers can have different Effect which are applied once when attacking a critter

Towers only attack 1 critter at the time.

the TowerManager determines if you can buy a Tower. Returns the Tower itsef if you can buy it.
If you try to sell it, the TowerManager returns the refund amount.
The TowerManager keeps a reference to every Towers that a user bought. these references are updated depending on the buying/selling of towers

The Critter and CritterGroup class are dummies and are not well built. I tried to encapsulate everything for the classes Towers, SplashTowers and Effect.


***ASSIGNMENT 2***

For assignement 2, the driver is the controller. In that case, we didn't need a new class. 

The way the view works, if the screen refreshes (clears and displays after), this means the view got notified by the model.
Else, if the screen doesn't change and the texts simply adds under the current "view output", then the internal state of the tower didn't change.

The map in the output doesn't belong to a logical view the tower would have and it's only there to show the change in the position, which is part of state of the tower that could change.

The current driver will test all the different logical ways to update the view. What I mean is that I didn't create unused mutators simply to put a call to Notify() in it. 
If the function was intended to change the state, Notify will be called. Ex. The fire rate could simply be changed when trying to level up, so only the function TryToLevelUp would cause and update if needed.

*/


int main(int argc, char** argv) {

    TowerManager tm(5);

	//Can change the tower type to test
	Tower* t1 = tm.BuyTower(50, TowerTypes::Basic);
	TowerObserver to(t1);

	//Short way to do an initial display by updating the view
	t1->SetPosition(1, 0);

	cout << endl << "Moving the tower to 0,0..." << endl;
	std::system("PAUSE");
	t1->SetPosition(0, 0);

	cout << endl << "Trying to level up with 5$..." << endl;
	std::system("PAUSE");
	t1->TryToLevelUp(5);

	cout << endl << "Trying to level up with 65$..." << endl;
	std::system("PAUSE");
	t1->TryToLevelUp(65);

	CritterGroup c(1);
	c.GetCritters()[0] = new Critter(7, 2);
	c.GetCritters()[0]->SetPosition(1, 0);

	cout << endl << "Trying to attack a critter at 1,0 ('*' should if tower attacks)..." << endl;
	std::system("PAUSE");
	t1->TryToAttackCritter(c);

	cout << endl << "Trying to attack a critter at 1,0 ('*' should if tower attacks)..." << endl;
	std::system("PAUSE");
	t1->TryToAttackCritter(c);

	cout << endl << "Trying to attack a critter at 1,0 ('*' should if tower attacks)..." << endl;
	std::system("PAUSE");
	t1->TryToAttackCritter(c);

	cout << endl << "Trying to attack a critter at 1,0 ('*' should if tower attacks)..." << endl;
	std::system("PAUSE");
	t1->TryToAttackCritter(c);

	cout << endl << "Trying to attack a critter at 1,0 ('*' should if tower attacks)..." << endl;
	std::system("PAUSE");
	t1->TryToAttackCritter(c);

	cout << endl << "Trying to attack a critter at 1,0 ('*' should if tower attacks)..." << endl;
	std::system("PAUSE");
	t1->TryToAttackCritter(c);

	cout << endl << "Trying to attack a critter at 1,0 ('*' should if tower attacks)..." << endl;
	std::system("PAUSE");
	t1->TryToAttackCritter(c);

	cout << endl << "Trying to attack a critter at 1,0 ('*' should if tower attacks)..." << endl;
	std::system("PAUSE");
	t1->TryToAttackCritter(c);

	std::system("PAUSE");

   /* CritterGroup c(3);
	c.GetCritters()[0] = new Critter(7,2);
	c.GetCritters()[1] = new Critter(7,2);
	c.GetCritters()[2] = new Critter(7,2);

    c.GetCritters()[0]->SetPosition(0,3);
	c.GetCritters()[1]->SetPosition(1, 3);
	c.GetCritters()[2]->SetPosition(2, 3);*/

	//Can change the tower type to test
    //Tower* t1 = tm.BuyTower(50, TowerTypes::Splash);
    //t1->SetPosition(2, 2);
	///*t1->TryToLevelUp(2);
	//t1->TryToLevelUp(20);*/
	//t1->TryToLevelUp(20);
	/*t1->TryToLevelUp(300);
	t1->TryToLevelUp(300);
	t1->TryToLevelUp(300);*/

	/*TowerObserver to(t1);
	t1->SetPosition(1, 0);
	std::system("PAUSE");
	t1->SetPosition(0, 0);
	std::system("PAUSE");
	t1->TryToLevelUp(2);
	std::system("PAUSE");
	t1->TryToLevelUp(20);
	std::system("PAUSE");*/


	return 0;
 //   while ( c.GetCritters()[0]->getX() != 10) {

	//	cout << t1->TryToAttackCritter(c) << endl;

	//	//Can only move right at the moment
	//	c.GetCritters()[0]->Move(Direction::RIGHT);
	//	c.GetCritters()[1]->Move(Direction::RIGHT);
	//	c.GetCritters()[2]->Move(Direction::RIGHT);
	//	/*c.GetCritters()[0]->SetPosition(c.GetCritters()[0]->getX() + 1, c.GetCritters()[0]->getY());
	//	c.GetCritters()[1]->SetPosition(c.GetCritters()[1]->getX() + 1, c.GetCritters()[1]->getY());
	//	c.GetCritters()[2]->SetPosition(c.GetCritters()[2]->getX() + 1, c.GetCritters()[2]->getY());*/
 //       
 //       print(*t1, c.GetCritters());
	//	cout << "HP of critter #1 : " << c.GetCritters()[0]->GetHP() << " x : " << c.GetCritters()[0]->getX() << " y : " << c.GetCritters()[0]->getY() << " Speed :" << c.GetCritters()[0]->GetSpeed() << endl;
	//	cout << "HP of critter #2 : " << c.GetCritters()[1]->GetHP() << " x : " << c.GetCritters()[1]->getX() << " y : " << c.GetCritters()[1]->getY() << " Speed :" << c.GetCritters()[1]->GetSpeed() << endl;
	//	cout << "HP of critter #3 : " << c.GetCritters()[2]->GetHP() << " x : " << c.GetCritters()[2]->getX() << " y : " << c.GetCritters()[2]->getY() << " Speed :" << c.GetCritters()[2]->GetSpeed() << endl;
 //       cout << endl;
 //       system("pause");

 //   }

	////Will be higher if more levels are applied
	//cout << "Selling price : " << tm.SellTower(t1) << endl;
	//
	//system("pause");

 //   //    SplashTower st;
 //   //    //    st.test();
 //   //    //    const SplashTower cst;
 //   //    //    cst.test2();
 //   //    //    cst.test2();
 //   //    
 //   //    
 //   //    MapEntity critter;
 //   //
 //   //    st.setX(0);
 //   //    st.setY(0);
 //   //
 //   //    critter.setX(3);
 //   //    critter.setY(4);
 //   //
 //   //    bool result = st.isInRange(critter, 3);
 //   //
 //   //    cout << result;

    //return 0;
}

