#pragma once
#include "Window.h"
#include "StateManager.h"
#include "SharedContext.h"

class Game
{
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();
	void LateUpdate();

private:
	Window m_window;
	StateManager m_stateManager;
	SharedContext m_context;
	sf::Clock m_clock;
	sf::Time m_elapsed;
};

