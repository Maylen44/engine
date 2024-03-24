#include "engine.h"
#include "renderer.h"
#include "logger.h"
#include "config.h"
#include "updater.h"
#include "event_handler.h"
#include "scene_manager.h"
#include <vector>

static Engine* s_ptrEngine = nullptr;
static Renderer* s_ptrRenderer = nullptr;
static Logger* s_ptrLogger = nullptr;
static ConfigManager* s_ptrConfigManager = nullptr;
static Updater* s_ptrUpdater = nullptr;
static EventHandler* s_ptrEventHandler = nullptr;
static SceneManager* s_ptrSceneManager = nullptr;

static std::vector<ISender*> s_senders;
static std::vector<IReceiver*> s_receivers;

//adding Senders and Receivers to vectors and attaching them
static void s_initializeSenders()
{
	s_senders.push_back(s_ptrRenderer);
	s_senders.push_back(s_ptrSceneManager);
	s_senders.push_back(s_ptrEventHandler);

	s_receivers.push_back(s_ptrEventHandler);
	s_receivers.push_back(s_ptrUpdater);

	for (IReceiver* receiver : s_receivers)
	{
		for (ISender* sender : s_senders) {sender->attach(receiver);}
	}
}

//sending content from senders to receivers
static void s_sendingContentForReceivers()
{
	for (ISender* sender : s_senders) {sender->sendContent();}
}

//instanciate pointer to singleton engine
Engine* Engine::instance()
{
	if (s_ptrEngine == nullptr)
	{
		s_ptrEngine = new Engine();
		s_ptrRenderer = new Renderer();
		s_ptrLogger = Logger::instance();
		s_ptrConfigManager = ConfigManager::instance();
		s_ptrUpdater = new Updater();
		s_ptrEventHandler = new EventHandler();
		s_ptrSceneManager = new SceneManager();

		s_initializeSenders();
	}
	return s_ptrEngine;
}

void Engine::addApplicationObject(IApplicationObject* object)
{
	m_objects.push_back(object);
}

void Engine::update()
{
	s_sendingContentForReceivers();
	s_ptrRenderer->renderContent();

}

void Engine::logOutsideMsg(const char* msg)
{
	s_ptrLogger->log("%s", msg);
}

