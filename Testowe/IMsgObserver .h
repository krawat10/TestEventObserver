#pragma once

class IObserver
{
public:
	
	virtual void update(float temp, float humidity, float pressure);
};
