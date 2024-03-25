#ifndef UPDATER_H
#define UPDATER_H

#include "common_data.h"
#include "Ireceiver.h"
#include "Iapplication_object.h"
#include <list>

class Updater : public IReceiver
{
public:
	Updater();
	virtual ~Updater() {};

	//SR methods
	void receiveContent(Scene scene) override { m_currentScene = scene; };
	void receiveContent(InputEvent event) override { m_inputEvent = event; };

	//Class methods
	void update(std::list<IApplicationObject*>& objects);
	void resetContent();

	bool isFrameTime();

private:
	sf::Clock m_deltaClock;
	sf::Time m_deltaTime;
	Scene m_currentScene;
	InputEvent m_inputEvent;
};
#endif //UPDATER_H