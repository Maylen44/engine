#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "Ireceiver.h"
#include <unordered_map>
#include <iostream>

enum InputEvent
{
	InputEvent_NoInput,
	InputEvent_W,
	InputEvent_Up,
	InputEvent_S,
	InputEvent_Down,
	InputEvent_A,
	InputEvent_Left,
	InputEvent_D,
	InputEvent_Right,
	InputEvent_ESC,
	InputEvent_CloseApplication,
	InputEvent_Restart,
	InputEvent_MouseLeft,
	InputEvent_MouseRight,
	InputEvent_MAX
};

class EventHandler : public IReceiver
{
public:
	EventHandler();
	virtual ~EventHandler() {};

	void receiveContent(Scene scene) override {};
	void receiveContent(sf::Event& event) override {
		std::cout << "received" << std::endl;
		m_windowPullEvent = event; };
	void updateInputEvents();

private:
	void updateKeyboardState();
	void updateMouseState();
	void fetchKeyboardEvents(InputEvent& event);
	void fetchMouseEvents(InputEvent& event);

	sf::Event m_windowPullEvent;
	std::unordered_map<sf::Keyboard::Key, bool> keyboardState;
	std::unordered_map<sf::Mouse::Button, bool> mouseState;

};
#endif //EVENT_HANDLER_H