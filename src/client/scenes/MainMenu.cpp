/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

#include "../ecs/components/DrawableClientSide.hpp"
#include "../ecs/components/Text.hpp"
#include "../ecs/components/Velocity.hpp"

#include "../ecs/systems/Animate.hpp"
#include "../ecs/systems/Click.hpp"
#include "../ecs/systems/Display.hpp"
#include "../ecs/systems/Move.hpp"
#include "../ecs/systems/WriteInBox.hpp"
#include "../ecs/systems/Input.hpp"
#include "../ecs/systems/Fire.hpp"

using namespace ecs;
using namespace rtype;

MainMenu::MainMenu(std::shared_ptr<SceneSystem> sceneSystem, sf::RenderWindow &window, sf::Event &event,
    const std::string &sceneName, const float scale, std::shared_ptr<Communicator> communicator, boost::thread *thread)
    : AScene(sceneSystem, window, sceneName, scale, communicator, thread), _event(event)
{
}

MainMenu::~MainMenu() {}

void MainMenu::OnCreate()
{
    /* We are going to create system here,
    dont forget to create the corresponding entityManager */

    _sceneSystem->getEcs()->createEntityManager(this->getName());
    _sceneSystem->getEcs()->createSystem<WriteInBox>(_sceneSystem->getEcs());
    _sceneSystem->getEcs()->createSystem<Display>(_sceneSystem->getEcs());
    _sceneSystem->getEcs()->createSystem<Click>(_sceneSystem->getEcs());
    _sceneSystem->getEcs()->createSystem<Move>(_sceneSystem->getEcs());
    _sceneSystem->getEcs()->createSystem<Animate>(_sceneSystem->getEcs());
    _sceneSystem->getEcs()->createSystem<Input>(_sceneSystem->getEcs());
    _sceneSystem->getEcs()->createSystem<Fire>(_sceneSystem->getEcs());

    _sceneSystem->getTextureDatabase()->onCall(this->getName());

    auto &hereManager = _sceneSystem->getEcs()->getEntityManager(this->getName());

    auto &title = hereManager.getEntity(ecs::generateEntity(hereManager, "Default"));

    auto &soloButton = hereManager.getEntity(ecs::generateEntity(hereManager, "Button"));
    auto &multiplayerButton = hereManager.getEntity(ecs::generateEntity(hereManager, "Button"));
    auto &quitbutton = hereManager.getEntity(ecs::generateEntity(hereManager, "Button"));

    auto &parallaxFirstImage = hereManager.getEntity(ecs::generateEntity(hereManager, "Default"));
    auto &parallaxSecondImage = hereManager.getEntity(ecs::generateEntity(hereManager, "Default"));

    parallaxFirstImage.addComponent<DrawableClientSide>(
        _sceneSystem->getTextureDatabase()->getTexture("Background"), (2 * _scale));
    parallaxFirstImage.addComponent<Velocity>(-0.005 * _scale, 0);
    parallaxFirstImage.getComponent<Position>().setPosition(0, 0);

    parallaxSecondImage.addComponent<DrawableClientSide>(
        _sceneSystem->getTextureDatabase()->getTexture("Background"), (2 * _scale));
    parallaxSecondImage.addComponent<Velocity>(-0.005 * _scale, 0);
    parallaxSecondImage.getComponent<Position>().setPosition(
        _sceneSystem->getTextureDatabase()->getSizeX("Background") * _scale, 0);

    title.addComponent<DrawableClientSide>(_sceneSystem->getTextureDatabase()->getTexture("Title"), _scale);
    title.getComponent<Position>().setPosition(
        _window.getSize().x / 2 - (_sceneSystem->getTextureDatabase()->getSizeX("Title") * _scale) / 2, 10);

    soloButton.getComponent<Text>().setText(std::string("Local"));
    soloButton.getComponent<Text>().setFontSize(50 * _scale);
    soloButton.getComponent<Position>().setPosition(title.getComponent<Position>().getX(),
        _window.getSize().y / 2 - (1 * soloButton.getComponent<Text>().getFontSize()));
    soloButton.getComponent<HitBox>().setHitBox(
        soloButton.getComponent<Text>().getTextWidth(), soloButton.getComponent<Text>().getTextHeight() * _scale);

    multiplayerButton.getComponent<Text>().setText(std::string("Multiplayer"));
    multiplayerButton.getComponent<Text>().setFontSize(50 * _scale);
    multiplayerButton.getComponent<Position>().setPosition(title.getComponent<Position>().getX(),
        soloButton.getComponent<Position>().getY() + (1.5 * multiplayerButton.getComponent<Text>().getFontSize()));
    multiplayerButton.getComponent<HitBox>().setHitBox(multiplayerButton.getComponent<Text>().getTextWidth(),
        multiplayerButton.getComponent<Text>().getTextHeight() * _scale);

    quitbutton.getComponent<Text>().setText(std::string("Quit"));
    quitbutton.getComponent<Text>().setFontSize(50 * _scale);
    quitbutton.getComponent<Position>().setPosition(title.getComponent<Position>().getX(),
        multiplayerButton.getComponent<Position>().getY() + (1.5 * quitbutton.getComponent<Text>().getFontSize()));
    quitbutton.getComponent<HitBox>().setHitBox(
        quitbutton.getComponent<Text>().getTextWidth(), quitbutton.getComponent<Text>().getTextHeight() * _scale);
}

void MainMenu::OnDestroy() {}

void MainMenu::OnActivate()
{
    _sceneSystem->getTextureDatabase()->onCall(this->getName());
    /* wa are going to create different entity here (with they're components),
    dont forget to init the textureDatabase of the corresponding scene */

    // if we want it as a text, decomment this section
    // title.addComponent<Text>();
    // title.getComponent<Text>().setText(std::string("SUBAQUATICA"));
    // title.getComponent<Text>().setFont("assets/TitleFont.ttf");
    // title.getComponent<Position>().setPosition(_window.getSize().x / 2
    //         - ((((title.getComponent<Text>().getText().getString().getSize() / 2 + 1)
    //                 * title.getComponent<Text>().getFontSize())
    //                + 20)
    //             * _scale),
    //     10);
    // title.getComponent<Text>().setFontSize(50 * _scale);
}

void MainMenu::OnDeactivate() {}

void MainMenu::ProcessInput() {}

void MainMenu::Update()
{
    _sceneSystem->getEcs()->getSystem<Click>().run(_sceneName, _window);
    if (_sceneSystem->getEcs()->getEntityManager(this->getName()).getEntity(1).getComponent<Clickable>().isClicked()) {
        /* solo */
    }
    if (_sceneSystem->getEcs()->getEntityManager(this->getName()).getEntity(2).getComponent<Clickable>().isClicked()) {
        _sceneSystem->SwitchTo("Hub");
    }
    if (_sceneSystem->getEcs()->getEntityManager(this->getName()).getEntity(3).getComponent<Clickable>().isClicked()) {
        _window.close();
    }
}

void MainMenu::Draw()
{
    auto &firstParallaxImage = _sceneSystem->getEcs()->getEntityManager(this->getName()).getEntity(4);
    auto &secondParallaxImage = _sceneSystem->getEcs()->getEntityManager(this->getName()).getEntity(5);

    float firstParallaxImagePositionX = firstParallaxImage.getComponent<Position>().getX();
    float secondParallaxImagePositionX = secondParallaxImage.getComponent<Position>().getX();

    if (firstParallaxImagePositionX <= -(_sceneSystem->getTextureDatabase()->getSizeX("Background") * _scale * 2))
        firstParallaxImage.getComponent<Position>().setPosition(
            _sceneSystem->getTextureDatabase()->getSizeX("Background") * 2, 0);
    if (secondParallaxImagePositionX <= -(_sceneSystem->getTextureDatabase()->getSizeX("Background") * _scale * 2))
        secondParallaxImage.getComponent<Position>().setPosition(
            _sceneSystem->getTextureDatabase()->getSizeX("Background") * 2, 0);

    _sceneSystem->getEcs()->getSystem<Animate>().runButton(this->getName());
    _sceneSystem->getEcs()->getSystem<Move>().run(this->getName());
    _sceneSystem->getEcs()->getSystem<Display>().run(this->getName(), _window);
}
