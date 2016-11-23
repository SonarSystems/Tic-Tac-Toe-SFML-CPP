#pragma once

#include <sstream>
#include "SplashState.hpp"

#include <iostream>

namespace Sonar
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{

	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (clock.getElapsedTime().asSeconds() > 3)
		{
			// Switch To Main Menu
			std::cout << "Go To Main Menu" << std::endl;
		}
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.display();
	}
}