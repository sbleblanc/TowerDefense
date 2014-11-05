#pragma once
#include "IObserver.h"
#include "Tower.h"

/*

Concrete observer for Towers (View).
For the sake of the second assignement, a map is shown with the stats to show the change of position possible.

*/

class TowerObserver :
	public IObserver
{
public:
	TowerObserver();
	TowerObserver(Tower*);
	~TowerObserver();
	void Update();

	void DisplayStats();
	void DisplayDummyMap();

private:
	Tower *t;
};

