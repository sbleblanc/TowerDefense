/* 
 * File:   TowerManager.h
 * Author: Samuel
 *
 * Created on October 19, 2014, 3:42 PM
 */

#ifndef TOWERMANAGER_H
#define	TOWERMANAGER_H

#include "Tower.h"

enum class TowerTypes {
    Basic, Splash, Slowing
};

class TowerManager {
public:
    TowerManager();
    TowerManager(int maxNumTowers);
    TowerManager(const TowerManager& orig);
    virtual ~TowerManager();
    
    Tower* BuyTower(int, TowerTypes);
    int SellTower(Tower*);
    
private:

    int numOfTowers;
    int maxNumTowers;
    Tower** towers;
    
    Tower* basicTower;
    Tower* splashTower;
    Tower* slowTower;
    
    void AddTower(Tower*);
    void RemoveTower(Tower*);
    bool Contains(Tower*);

};

#endif	/* TOWERMANAGER_H */

