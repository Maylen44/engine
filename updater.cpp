#include "updater.h"

Updater::Updater()
	: m_deltaClock()
	, m_deltaTime(sf::seconds(0.1f))
	, m_currentScene()
	, m_inputEvent()
{
}

void Updater::update()
{
	if (isFrameTime())
	{

	}
}

void Updater::resetContent()
{
}

bool Updater::isFrameTime()
{
	bool result = false;
	static sf::Time lastFrameTime;
	sf::Time elapsedTime = m_deltaClock.getElapsedTime();
	if (elapsedTime - lastFrameTime >= m_deltaTime)
	{
		lastFrameTime = elapsedTime;
		result = true;
	}
	return result;
}