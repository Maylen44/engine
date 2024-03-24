#ifndef RENDERER_H
#define RENDERER_H

#include "common_data.h"
#include "Isender.h"

class Renderer : public ISender
{
public:
	Renderer();
	virtual ~Renderer() {};

	//SR methods
	void attach(IReceiver* receiver) override { m_listReceivers.push_back(receiver); };
	void detach(IReceiver* receiver) override { m_listReceivers.remove(receiver); };
	void sendContent() override;

	//Class methods
	void const renderContent(/*const std::vector<IGameObject*>& objects*/);
	void updateWindowSettings();
	void closeWindow();

private:
	sf::RenderWindow m_window;
	sf::VideoMode m_videoMode;
	sf::Uint64 m_style;
	std::string m_title;
	std::list<IReceiver*> m_listReceivers;
};
#endif //RENDERER_H