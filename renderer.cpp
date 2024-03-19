#include "renderer.h"

Renderer::Renderer()
	: m_window()
	, m_videoMode()
	, m_style(sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close)
	, m_title("Game of Life")
	, m_listReceivers()
{
	m_videoMode.width = CONFIG_GET.WindowResolution.x;
	m_videoMode.height = CONFIG_GET.WindowResolution.y;
	m_window.create(m_videoMode, m_title, m_style);
}

void Renderer::sendContent()
{
	sf::Event pullEvent;
	m_window.pollEvent(pullEvent);

	for (auto& receiver : m_listReceivers)
	{
		receiver->receiveContent(pullEvent);
	}
}

void const Renderer::renderContent()
{
	sendContent();
	m_window.clear();
	m_window.display();
}

void Renderer::updateWindowSettings()
{
	m_videoMode.width = CONFIG_GET.WindowResolution.x;
	m_videoMode.height = CONFIG_GET.WindowResolution.y;
	m_window.create(m_videoMode, m_title, m_style);
}

void Renderer::closeWindow()
{
	m_window.close();
}