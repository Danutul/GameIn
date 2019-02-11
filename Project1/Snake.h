#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct SnakeSegment
{
	SnakeSegment(int x, int y)
		:
		position(x, y) 
	{}
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction
{
	None, 
	Up, 
	Down,
	Left,
	Right
};

class Snake
{
public:
	Snake(int l_blockSize);
	~Snake();

	//Helper methods
	void SetDirection(Direction l_dir);
	Direction GetDirection();
	int GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();
	
	void Lose(); //hendle losing here
	void ToggleLost();
	void Extend(); // Grow the snake
	void Reset(); //Reset the starting point
	void Move();
	void Tick(); //Update method
	void Cut(int l_segments); //method for cutting snake
	void Render(sf::RenderWindow& l_window);

private:
	void CheckCollision();

	SnakeContainer m_snakeBody;

	//segment vector
	int m_size; //size of the graphics
	Direction m_dir; //current direction
	
	int m_speed; 
	int m_lives;
	int m_score;
	bool m_lost; //losing state
	sf::RectangleShape m_bodyRect;
};

