#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "EventManager.h"

class Window
{
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();
	void BeginDraw(); //clear window
	void EndDraw(); //display the changes
	void Update();
	bool IsDone();
	bool IsFullscreen();
	bool IsFocused();
	sf::RenderWindow* GetRenderWindow();
	EventManager* GetEventManager();
	sf::Vector2u GetWindowSize();
	void ToggleFullScreen(EventDetails* l_details);
	void Close(EventDetails* l_details = nullptr);
	void Draw(sf::Drawable& l_drawble);
private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	EventManager m_eventManager;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isFocused;
	bool m_isDone;
	bool m_isFullScreen;
};

