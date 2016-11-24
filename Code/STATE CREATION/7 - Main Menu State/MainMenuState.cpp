#pragma once

#include <sstream>
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Background", "Resources/res/Main Menu Background.png");
		this->_data->assets.LoadTexture("Play Button", "Resources/res/Play Button.png");
		this->_data->assets.LoadTexture("Play Button Outer", "Resources/res/Play Button Outer.png");
		this->_data->assets.LoadTexture("Game Title", "Resources/res/Game Title.png");

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));
		this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));
		this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButtonOuter.getGlobalBounds().height / 2));
		
		this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.1);
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Go To Game Screen" << std::endl;
			}
		}
	}

	void MainMenuState::Update(float dt)
	{

	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_playButtonOuter);
		this->_data->window.draw(this->_title);

		this->_data->window.display();
	}
}