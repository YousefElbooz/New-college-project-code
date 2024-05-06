#include "state.h"
State::State(sf::RenderWindow* window,std::stack<State*>* states)
{
    this->window = window;
    this->states = states;
    this->Quit = false;
}
State::~State()
{
}
const bool& State::getQuit() const
{
    return this->Quit;
}
void State::updatemousepostion()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
void State::endState()
{
    std::cout << "Ending Gamestate" << "\n";
    this->Quit = true;
}