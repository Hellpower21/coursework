#include <iostream>
#include "Menu.h"

Menu::Menu()
{
    initFonts();
    initTitle();
    initMenuText();
    initSounds();
    update();
}

void Menu::posUp()
{
    initSounds();
    currentPos == 0 ? currentPos = 2 : --currentPos;
    switchMenuSound.play();
    update();
}

void Menu::posDown()
{
    initSounds();
    currentPos++;
    switchMenuSound.play();
    update();
}

int Menu::getPos()
{
    initSounds();
    choseMenuSound.play();
    return abs(currentPos % menuItems);
}

void Menu::initFonts()
{
    if (!titleFont.loadFromFile("fonts/title-font.otf"))
    {
        throw ("Could not load font file: \"title-font.otf\"");
    }
    if (!menuFont.loadFromFile("fonts/menu-font.ttf"))
    {
        throw ("Could not load font file: \"menu-font.ttf\"");
    }
}

void Menu::initTitle()
{
    title.setString("Nure Aim Trainer");
    title.setFillColor(sf::Color(255, 89, 94));
    title.setCharacterSize(60);
    title.setFont(titleFont);
    float width = title.getGlobalBounds().width;
    title.setPosition(sf::Vector2f(400 - width / 2, 20));
}

void Menu::initMenuText()
{
    menuText[0].setString("Aim Trainer");
    menuText[1].setString("Speed Trainer");
    menuText[2].setString("Exit");
    float width;
    for (int i = 0; i < menuItems; i++)
    {
        menuText[i].setFont(menuFont);
        menuText[i].setCharacterSize(45);
    }
    
}

void Menu::initSounds()
{
    if (!switchMenuSound.openFromFile("sounds/switch-sound.ogg"))
    {
        throw ("Could not load sound file: \"switch-sound.ogg\"");
    }
    if (!choseMenuSound.openFromFile("sounds/chose-sound.ogg"))
    {
        throw("Could not load sound file: \"sounds/chose-sound.ogg\"");
    }
}

void Menu::draw(sf::RenderTarget* target = nullptr)
{
    target->draw(title);
    for (int i = 0; i < menuItems; i++)
    {
        target->draw(menuText[i]);
    }
}

void Menu::update()
{
    float width;
    for (int i = 0; i < menuItems; i++)
    {
        if (abs(currentPos % menuItems) == i)
        {
            menuText[i].setScale(1.35, 1.35);
            menuText[i].setFillColor(sf::Color(106, 76, 147));
            width = menuText[i].getGlobalBounds().width;
            menuText[i].setPosition(sf::Vector2f((800 / 2) - (width) / 2, (((800 / 3) * (i + 1)) / 2) + 40));
        }
        else
        {
            menuText[i].setScale(1, 1);
            menuText[i].setFillColor(sf::Color(25, 130, 196));
            width = menuText[i].getGlobalBounds().width;
            menuText[i].setPosition(sf::Vector2f((800 / 2) - (width) / 2, (((800 / 3) * (i + 1)) / 2) + 40));
        }
    }
}


