#include "engine.h"

int main()
{
	//ENGINElog("f");
	//KFJG->madedd();
	
	Engine::instance()->logOutsideMsg("hello");
	Engine::instance()->update();

	while (true)
	{
		Engine::instance()->update();
	}

	Engine* e = Engine::instance();
	/*
	CONFIG_GET.WindowResolution.x;
	std::cout << CONFIG_GET.WindowResolution.x << std::endl;
	CONFIG->changeConfigTo(ConfigOption_WindowResolution_1280x800);
	std::cout << CONFIG_GET.WindowResolution.x << std::endl;

	*/
	

	return 0;
}

/*
initialize();
AssetsManager* s_AssetManager = AssetsManager::instance();
std::vector<InputEvent> events(3, InputEvent_NoInput);

while (m_isPlaying)
{
	m_eventHandler.setEvents(events, m_renderer.pollWindowEvent());

	switch (events[0])
	{
	case InputEvent_ESC:
		m_isPlaying = false;
		clearObject();
		m_renderer.closeWindow();
		break;
	case InputEvent_Restart:
		if (m_updater.isSFXTime())
		{
			s_AssetManager->playSFX(SFX_RestartSound);
		}
		reset();
		break;
	default:
		break;
	}
	m_updater.update(m_gameObjects, events);
	progressGameLogic(events);

	s_AssetManager->editText(Text::Text_Score, "Score: " + std::to_string(m_score));
	m_renderer.renderContent(m_gameObjects);

}

*/


/*
What musst engine do and provide? What should we provide?
1) We need to provide GameObjects and there information. Attachment of information to the objects make engine
2) We provide logic of the game. This schould me managed by us, but take ellements of Engine
3) Engine musst give posibility of control for settings but it makes the processes

*/

/*
	struct PlainOldData
		serialize
		version + weight in biyts
			header and content
	read config
	write config
*/