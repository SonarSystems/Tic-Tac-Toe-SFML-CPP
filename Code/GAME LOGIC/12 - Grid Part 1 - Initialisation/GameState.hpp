#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		void InitGridPieces();

		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _pauseButton;

		sf::Sprite _gridSprite;

		sf::Sprite _gridPieces[3][3];
		int gridArray[3][3];

		int turn;
		int gameState;
	};
}