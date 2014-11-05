/* 
 * File:   TowerManager.cpp
 * Author: Samuel
 * 
 * Created on October 19, 2014, 3:42 PM
 */

#include <stddef.h>

#include "TowerManager.h"
#include "Tower.h"
#include "SplashTower.h"

TowerManager::TowerManager() {

	//If you put the range of the tower too high (higher than 3), you will get strange results since every tower will be in range at the beginning.
	//For the sake of the test, the test critters are close and by putting the range too high, the critter targetting algorithm will return the wrong critter.

    this->basicTower = new Tower(20, 3, 2, 20, 2, 0, 'B', "Basic Tower");

    this->slowTower = new Tower(30, 3, 2, 10, 2, 1, 'F', "Freezing Tower");
    Effect effTemp(1, 0, 0, CritterType::None, EffectType::Slow);
    this->slowTower->AddEffect(effTemp);

    this->splashTower = new SplashTower(25, 3, 2, 15, 2, 0, 1, 'S', "Splash Tower");

    this->numOfTowers = 0;

}

TowerManager::TowerManager(int maxNumTowers) : TowerManager() {
    if (maxNumTowers < 1) {
        this->maxNumTowers = 0;
    } else {
        this->maxNumTowers = maxNumTowers;
        this->towers = new Tower*[maxNumTowers];
    }
}

TowerManager::TowerManager(const TowerManager& orig) {
}

TowerManager::~TowerManager() {
    delete this->basicTower;
    delete this->slowTower;
    delete this->splashTower;
}

Tower* TowerManager::BuyTower(int amount, TowerTypes type) {

    Tower* temp = NULL;

    switch (type) {
        case TowerTypes::Basic:
            temp = new Tower(*this->basicTower);
            break;
        case TowerTypes::Slowing:
            temp = new Tower(*this->slowTower);
            break;
        case TowerTypes::Splash:
            temp = new SplashTower(*dynamic_cast<SplashTower*>(this->splashTower));
            break;
    }

    if (temp->CanBuy(amount)) {
        AddTower(temp);
        return temp;
    } else {
        return NULL;
    }
}

void TowerManager::AddTower(Tower* t) {
    this->towers[this->numOfTowers++] = t;
}

int TowerManager::SellTower(Tower* t){
    if (this->Contains(t)){
        int amount = t->GetCurrentRefundCost();
        this->RemoveTower(t);
        return amount;
    }else{
        return 0;
    }
}

void TowerManager::RemoveTower(Tower* t) {

    int i = 0;
    for (; i < numOfTowers; i++) {
        if (t == this->towers[i]) {
            delete this->towers[i];
			this->towers[i] = NULL;
            break;
        }
    }
    numOfTowers--;

    int j = i;
    for (; j < this->numOfTowers - 1; j++) {
        this->towers[j] = this->towers[j + 1];
    }
    this->towers[j] = NULL;

}

bool TowerManager::Contains(Tower* t) {
    if (this->numOfTowers == 0) return false;
    for (int i = 0; i < numOfTowers; i++) {
        if (t == this->towers[i])
            return true;
    }
    return false;
}
