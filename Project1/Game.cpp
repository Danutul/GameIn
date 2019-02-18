#include "Game.h"

Game::Game()
	:
	m_window("Game", sf::Vector2u(800, 600)),
	m_stateManager(&m_context)
{
	m_clock.restart();
	srand(time(nullptr));

	m_context.m_wind = &m_window;
	m_context.m_eventManager = m_window.GetEventManager();

	m_stateManager.SwitchTo(StateType::Intro);
	
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
	m_stateManager.Update(m_elapsed);
}

void Game::Render()
{
	m_window.BeginDraw(); //clear
	m_stateManager.Draw();
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

void Game::LateUpdate()
{
	m_stateManager.ProcessRequests();
	RestartClock();
}
