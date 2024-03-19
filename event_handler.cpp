#include "event_handler.h"

EventHandler::EventHandler() : m_windowPullEvent() {}

void EventHandler::updateInputEvents()
{
    InputEvent event = InputEvent_NoInput;

    updateKeyboardState();
    updateMouseState();

    if ((m_windowPullEvent.type == sf::Event::Closed))
    {
        event = InputEvent_CloseApplication;
    }
    else if (keyboardState[sf::Keyboard::Escape])
    {
        event = InputEvent_ESC;
    }
    else if (keyboardState[sf::Keyboard::R])
    {
        event = InputEvent_Restart;
    }
    fetchKeyboardEvents(event);
    fetchMouseEvents(event);
}

void EventHandler::updateKeyboardState()
{
    if (m_windowPullEvent.type == sf::Event::KeyPressed)
        keyboardState[m_windowPullEvent.key.code] = true;
    else if (m_windowPullEvent.type == sf::Event::KeyReleased)
        keyboardState[m_windowPullEvent.key.code] = false;
}

void EventHandler::updateMouseState()
{
    if (m_windowPullEvent.type == sf::Event::MouseButtonPressed)
        mouseState[m_windowPullEvent.mouseButton.button] = true;
    else if (m_windowPullEvent.type == sf::Event::MouseButtonReleased)
        mouseState[m_windowPullEvent.mouseButton.button] = false;
}

void EventHandler::fetchKeyboardEvents(InputEvent& event)
{
    if (keyboardState[sf::Keyboard::W] || keyboardState[sf::Keyboard::Up])
        event = InputEvent_Up;
    else if (keyboardState[sf::Keyboard::S] || keyboardState[sf::Keyboard::Down])
        event = InputEvent_Down;
    else if (keyboardState[sf::Keyboard::A] || keyboardState[sf::Keyboard::Left])
        event = InputEvent_Left;
    else if (keyboardState[sf::Keyboard::D] || keyboardState[sf::Keyboard::Right])
        event = InputEvent_Right;
}

void EventHandler::fetchMouseEvents(InputEvent& event)
{
    if (mouseState[sf::Mouse::Left])
        event = InputEvent_MouseLeft;
    else if (mouseState[sf::Mouse::Right])
        event = InputEvent_MouseRight;
}