#include "TowerObserver.h"
#include "IObserver.h"
#include "Effect.h"
#include <iostream>
using namespace std;


TowerObserver::TowerObserver()
{
}

//The view attaches itself to the model when created
TowerObserver::TowerObserver(Tower *tow){
	this->t = tow;
	this->t->Attach(this);
}


TowerObserver::~TowerObserver()
{
}

void TowerObserver::Update(){
	system("CLS");
	DisplayDummyMap();
	DisplayStats();
}

void TowerObserver::DisplayDummyMap(){

	for (int i = 0; i <= 5; i++){
		for (int j = 0; j < 5; j++){
			if (j == this->t->getX() && i == this->t->getY()){
				cout << this->t->getDisplayChar();
			}
			else if (i == 5){
				cout << "-";
			}
			else{
				cout << " ";
			}
		}
		cout << "|" << endl;
	}

}

void TowerObserver::DisplayStats(){
	cout << endl << this->t->GetName() << endl;
	cout << "--------------------------" << endl;
	cout << "PosX : " << this->t->getX() << endl;
	cout << "PosY : " << this->t->getY() << endl;
	cout << "Cost : " << this->t->GetCost() << endl;
	cout << "Power : " << this->t->GetPower() << endl;
	cout << "Range : " << this->t->GetRange() << endl;
	cout << "Fire rate : " << this->t->GetRange() << endl;
	cout << "Level : " << this->t->GetLevel() << endl;
	cout << "Cost to level up : " << this->t->GetCurrentLevelUpCost() << endl;
	cout << "Current refund value : " << this->t->GetCurrentRefundCost() << endl;
	cout << "Effects: ";
	if (this->t->GetMaxNumOfEffects() == 0){
		cout << "None";
	}
	else {
		for (int i = 0; i < this->t->GetMaxNumOfEffects(); i++){
			if (this->t->GetEffects()[i] != NULL){
				switch (this->t->GetEffects()[i]->getType()){
				case EffectType::None:
					cout << "None ";
					break;
				case EffectType::Slow:
					cout << "Freezing ";
					break;
				}
			}
		}
	}
	cout << endl;
	cout << "Current critter : ";
	if (this->t->GetCurrentCritter() != NULL && this->t->GetCurrentCritter()->GetState() != CritterState::Dead) {
		cout << "HP : " << this->t->GetCurrentCritter()->GetHP() << " X : " << this->t->GetCurrentCritter()->getX() << " Y : " << this->t->GetCurrentCritter()->getY();
	}
	else  {
		cout << "None";
	}
	cout << endl;

}

