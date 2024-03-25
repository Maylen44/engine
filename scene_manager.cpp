#include "scene_manager.h"

SceneManager::SceneManager(Scene startScene) : m_currentScene(startScene) {}

bool SceneManager::getScene(Scene scene) const
{
	bool initializationResult;
	if (m_currentScene < 0 || m_currentScene > Scene_MAX)
	{
		initializationResult = false;
	}
	else
	{
		scene = m_currentScene;
		initializationResult = true;
	}
	return initializationResult;
}

void SceneManager::setScene(Scene scene) noexcept
{
	m_currentScene = scene;
	sendContent();
}