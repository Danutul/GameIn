#include "Window.h"



Window::Window()
{
}

Window::Window(const std::string & l_title, const sf::Vector2u & l_size)
{
}


Window::~Window()
{
}

void Window::BeginDraw()
{
}

void Window::EndDraw()
{
}

void Window::Update()
{
}

bool Window::IsDone()
{
	return false;
}

bool Window::IsFullscreen()
{
	return false;
}

sf::Vector2u Window::GetWindowSize()
{
	return sf::Vector2u();
}

void Window::ToggleFullScreen()
{
}

void Window::Draw(sf::Drawable & l_drawble)
{
}

void Window::Setup(const std::string & l_title, const sf::Vector2u & l_size)
{
}

void Window::Destroy()
{
}

void Window::Create()
{
}
