#include "Game.h"

Game::Game()
	:
	m_window("Game", sf::Vector2u(800, 600))
{
	//setting up class members
	
}


Game::~Game()
{
}

void Game::HandleInput()
{

}

void Game::Update()
{
	m_window.Update(); //update window events
}

void Game::Render()
{
	m_window.BeginDraw(); //clear
	
	m_window.EndDraw(); // display
}

Window * Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	m_elapsed = m_clock.restart();
}