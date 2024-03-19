#ifndef UPDATER_H
#define UPDATER_H

#include "common_data.h"

class Updater
{
public:
	Updater();
	//~Updater();

	void update();
	void resetContent();

	bool isFrameTime();

private:
	sf::Clock m_deltaClock;
	sf::Time m_deltaTime;
};
#endif //UPDATER_H