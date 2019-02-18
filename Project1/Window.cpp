#include "Window.h"



Window::Window()
{
	Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string & l_title, const sf::Vector2u & l_size)
{
	Setup(l_title, l_size);
}


Window::~Window()
{
	Destroy();
}

void Window::Setup(const std::string & l_title, const sf::Vector2u & l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullScreen = false;
	m_isDone = false;
	m_isFocused = true;
	m_eventManager.AddCallback(StateType(0),"Fullscreen_toggle", &Window::ToggleFullScreen, this);
	m_eventManager.AddCallback(StateType(0),"Window_close", &Window::Close, this);
	
	Create();
}

void Window::Create()
{
	auto style = (m_isFullScreen ? sf::Style::Fullscreen :
		sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, 
		m_windowTitle, style);
}

void Window::Destroy()
{
	m_window.close();
}

void Window::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::LostFocus)
		{
			m_isFocused = false;
			m_eventManager.SetFocus(false);
		}
		else if (event.type == sf::Event::GainedFocus) 
		{
			m_isFocused = true; 
			m_eventManager.SetFocus(true); 
		}
		m_eventManager.HandleEvent(event);
	}
	m_eventManager.Update();
}

void Window::ToggleFullScreen(EventDetails* l_details)
{
	m_isFullScreen = !m_isFullScreen;
	Destroy();
	Create();
}

void Window::Close(EventDetails* l_details)
{
	m_isDone = true;
}

void Window::BeginDraw()
{
	m_window.clear();
}

void Window::EndDraw()
{
	m_window.display();
}

bool Window::IsFullscreen()
{
	return m_isFullScreen;
}
bool Window::IsFocused()
{
	return m_isFocused;
}
sf::RenderWindow * Window::GetRenderWindow()
{
	return &m_window;
}
EventManager * Window::GetEventManager()
{
	return &m_eventManager;
}
bool Window::IsDone()
{
	return m_isDone;
}

sf::Vector2u Window::GetWindowSize()
{
	return m_windowSize;
}

sf::FloatRect Window::GetViewSpace()
{
	sf::Vector2f viewCenter = m_window.getView().getCenter();
	sf::Vector2f viewSize = m_window.getView().getSize();
	sf::Vector2f viewSizeHalf(viewSize.x / 2, viewSize.y / 2);

	sf::FloatRect viewSpace(viewCenter - viewSizeHalf, viewSize);

	return viewSpace;
}

void Window::Draw(sf::Drawable & l_drawble)
{
	m_window.draw(l_drawble);
}