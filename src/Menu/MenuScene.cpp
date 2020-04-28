/*
** EPITECH PROJECT, 2019
** MenuScene.cpp
** File description:
** MenuScene Class Implementation
*/

#include "MenuScene.hpp"
#include "Macros.hpp"
#include "Transform.hpp"
#include "MeshRenderer.hpp"
#include "TextRenderer.hpp"
#include "TextBox.hpp"
#include "MenuEntity.hpp"
#include "FillNameField.hpp"
#include "ScoreManager.hpp"

wd::MenuScene::MenuScene() : AScene("Menu")
{
    build();
}

void wd::MenuScene::reset()
{
    destroyGameObject();
    build();
}

void wd::MenuScene::build()
{
    std::shared_ptr<wd::AGameObject> pacmanIcon = std::make_shared<wd::MenuEntity>("pacmanIcon", wd::NOTHING, wd::BACKGROUND, 0.3);
    pacmanIcon->addComponent<wd::MeshRenderer>("MeshRenderer", "./Textures/pacman.txt", "./Textures/pacman.png", "./Textures/pacman.png");
    addObject(pacmanIcon);
    std::shared_ptr<wd::AGameObject> cherryIcon = std::make_shared<wd::MenuEntity>("cherryIcon", wd::NOTHING, wd::BACKGROUND, 1.0);
    cherryIcon->addComponent<wd::MeshRenderer>("MeshRenderer", "./Textures/cherry.txt", "./Textures/cherry.png", "./Textures/cherry.png");
    addObject(cherryIcon);
    std::shared_ptr<wd::AGameObject> ghostIcon = std::make_shared<wd::MenuEntity>("ghostIcon", wd::NOTHING, wd::BACKGROUND, 0.5);
    ghostIcon->addComponent<wd::MeshRenderer>("MeshRenderer", "./Textures/ghost.txt", "./Textures/ghost.png", "./Textures/ghost.png");
    addObject(ghostIcon);
    std::shared_ptr<wd::AGameObject> snakeIcon = std::make_shared<wd::MenuEntity>("snakeIcon", wd::NOTHING, wd::BACKGROUND, 0.7);
    snakeIcon->addComponent<wd::MeshRenderer>("MeshRenderer", "./Textures/snake.txt", "./Textures/snake.png", "./Textures/snake.png");
    addObject(snakeIcon);
    std::shared_ptr<wd::AGameObject> shipIcon = std::make_shared<wd::MenuEntity>("shipIcon", wd::NOTHING, wd::BACKGROUND, 0.1);
    shipIcon->addComponent<wd::MeshRenderer>("MeshRenderer", "./Textures/ship.txt", "./Textures/ship.png", "./Textures/ship.png");
    addObject(shipIcon);

    std::shared_ptr<wd::AGameObject> logo = std::make_shared<wd::AGameObject>("logo", wd::NOTHING, wd::FOREGROUND);
    logo->getComponent<wd::Transform>("Transform").setPosition(14.0, 25.0, 0.0);
    logo->addComponent<wd::MeshRenderer>("MeshRenderer", "./Textures/warden_logo-arcade.txt", "./Textures/warden_logo-arcade.png", "./Textures/warden_logo-arcade.png");
    addObject(logo);

    std::shared_ptr<wd::AGameObject> name = std::make_shared<wd::TextBox>("name", wd::NOTHING, wd::HUD, "Your name :");
    name->getComponent<wd::Transform>("Transform").setPosition(2.0, 3.0, 0.0);
    addObject(name);
    std::shared_ptr<wd::AGameObject> name_input = std::make_shared<wd::TextBox>("name_input", wd::NOTHING, wd::HUD);
    name_input->getComponent<wd::Transform>("Transform").setPosition(7.0, 3.0, 0.0);
    name_input->addComponent<wd::FillNameField>("FillNameField", name_input);
    addObject(name_input);
    std::shared_ptr<wd::AGameObject> score = std::make_shared<wd::TextBox>("score", wd::NOTHING, wd::HUD, "Score :");
    score->getComponent<wd::Transform>("Transform").setPosition(2.0, 5.0, 0.0);
    addObject(score);
    std::shared_ptr<wd::AGameObject> score_input = std::make_shared<wd::TextBox>("score_input", wd::NOTHING, wd::HUD);
    score_input->getComponent<wd::Transform>("Transform").setPosition(5.0, 5.0, 0.0);
    score_input->addComponent<wd::ScoreManager>("ScoreManager", getScore(), score_input);
    addObject(score_input);
}
