#include "Game.h"

Game* Game::_instance = new Game();

std::list<Level> Game::_levels;
GraphicsManager Game::_graphics;
ControlsManager Game::_controls;
SoundsManager Game::_sounds;
PhysicsManager Game::_physics;

const std::list<Level>& Game::levels = Game::_levels;
GraphicsManager& Game::graphics = Game::_graphics;
ControlsManager& Game::controls = Game::_controls;
SoundsManager& Game::sounds = Game::_sounds;
PhysicsManager& Game::physics = Game::_physics;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
}