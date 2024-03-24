#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "Isender.h"
#include <unordered_map>

class EventHandler : public IReceiver, public ISender
{
public:
	EventHandler();
	virtual ~EventHandler() {};

	//SR methods
	virtual void attach(IReceiver* receiver) override { m_listReceivers.push_back(receiver); };
	virtual void detach(IReceiver* receiver) override { m_listReceivers.remove(receiver); }
	virtual void sendContent() override;
	void receiveContent(sf::Event& event) override {m_windowPullEvent = event; };
	
	//Class methods
	void updateInputEvents();

private:
	void updateKeyboardState();
	void updateMouseState();
	void fetchKeyboardEvents(InputEvent event);
	void fetchMouseEvents(InputEvent event);

	sf::Event m_windowPullEvent;
	InputEvent m_inputEvent;
	std::unordered_map<sf::Keyboard::Key, bool> keyboardState;
	std::unordered_map<sf::Mouse::Button, bool> mouseState;
	std::list<IReceiver*> m_listReceivers;

};
#endif //EVENT_HANDLER_H