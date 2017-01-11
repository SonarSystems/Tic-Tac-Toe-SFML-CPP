#pragma once

#include <sstream>
#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace Sonar
{
	PauseState::PauseState(GameDataRef data) : _data(data)
	{

	}

	void PauseState::Init()
	{
		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
		this->_homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
	}

	void PauseState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{
				// Resume Game By Popping Of The Current State (Pause State)
				this->_data->machine.RemoveState();

			}

			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				// Remove The Pause State Off The Stack
				this->_data->machine.RemoveState();

				// Switch To Main Menu State By Replacing The Game State
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

			}
		}
	}

	void PauseState::Update(float dt)
	{

	}

	void PauseState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}
}