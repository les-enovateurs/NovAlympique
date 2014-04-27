#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;
using namespace sf;

#include "../include/Screen.h"

Screen::Screen(RenderWindow &_App,Texture &_backgroundT):App(_App),backgroundT(_backgroundT)
{
    srand (time(NULL));
    init();
}

void Screen::init()
{
    letsPlayJoke.restart();//les chronos
    nextVirus.restart();
    background.setTexture(backgroundT);
    addVirus("./res/virus1.png");//chargement des images
    addVirus("./res/virus2.png");
    addVirus("./res/virus3.png");
    addVirus("./res/virus4.png");
    addVirus("./res/virus5.png");
    addVirus("./res/virus6.png");
    addVirus("./res/virus7.png");
    addVirus("./res/virus8.png");
    addVirus("./res/virus9.png");
    addVirus("./res/virus1.png");
    addVirus("./res/virus2.png");
    addVirus("./res/virus3.png");
    addVirus("./res/virus4.png");
    addVirus("./res/virus5.png");
    addVirus("./res/virus6.png");
    addVirus("./res/virus7.png");
    addVirus("./res/virus8.png");
    addVirus("./res/virus9.png");
    addVirus("./res/virus1.png");
    addVirus("./res/virus2.png");
    addVirus("./res/virus3.png");
    addVirus("./res/virus4.png");
    addVirus("./res/virus5.png");
    addVirus("./res/virus6.png");
    addVirus("./res/virus7.png");
    addVirus("./res/virus8.png");
    addVirus("./res/virus9.png");
    addVirus("./res/virus1.png");
    addVirus("./res/virus2.png");
    addVirus("./res/virus3.png");
    addVirus("./res/virus4.png");
    addVirus("./res/virus5.png");
    addVirus("./res/virus6.png");
    addVirus("./res/virus7.png");
    addVirus("./res/virus8.png");
    addVirus("./res/virus9.png");
    moveMouse = false;
    startUp = false;
    currentVirus = 1;

    progresInt = 0;



    if(!avgT.loadFromFile("./res/avg1.jpg"))//chargement de l'image avg
        cerr<<"erreur de chargement fichier"<<endl;
    else
    {
       avg.setTexture(avgT);
       avg.setPosition(((backgroundT.getSize().x/2)-(avgT.getSize().x/2)),((backgroundT.getSize().y/2)-(avgT.getSize().y/2)));
    }


    if(!formateurT.loadFromFile("./res/format.png"))//chargement de l'image de formatage
        cerr<<"erreur de chargement fichier"<<endl;
    else
    {
       formateur.setTexture(formateurT);
       formateur.setPosition(((backgroundT.getSize().x/2)-(formateurT.getSize().x/2)),((backgroundT.getSize().y/2)-(formateurT.getSize().y/2)));
    }

    launchFormat = false;
    depile = false;
    decompter = 40;

    string finalSc="";
    ostringstream oss;
    oss << decompter;
    finalSc = oss.str();

    bombe.setString(finalSc);
    bombe.setPosition(avg.getPosition().x+300,avg.getPosition().y+200);

    progression.setSize(sf::Vector2f(progresInt, 25.69));//barre de progression de formatage
    progression.setFillColor(sf::Color::Green);
    progression.setPosition(formateur.getPosition().x+24.67+1, formateur.getPosition().y+41.44+1);

    if(!backgroundTerreur.loadFromFile("./res/ter.jpg"))
        cerr<<"erreur chargement terreur"<<endl;

    finalStep = false;

    fin.setPosition(100,100);
    currentLetter = 0;
    completeText = "Merci d'avoir participe a cet exercice de securite informatique\nPour arreter il faut\n\nfaire un Alt + F4\n\n";
    fin.setString("");
    fin.setColor(Color(255,255,255));
}

void Screen::addVirus(string link)
{
    fenetres.push_back(Texture());
    if(!fenetres[fenetres.size()-1].loadFromFile(link))
        cerr<<"erreur de chargement de virus1"<<endl;

    point.push_back(Point((rand() % 880 + 0),((rand() % 500 + 0)),1));
}

void Screen::management()
{
    Event event;
    while (App.pollEvent(event))
    {
        if(event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            App.close();
    }
}

void Screen::start()
{
    App.draw(background);

    if(letsPlayJoke.getElapsedTime().asSeconds() > 30)
    {
        if(!startUp)
        {
            startUp = true;
            position = Mouse::getPosition();
        }
        else
        {
            if(!moveMouse)
            {
                if(Mouse::getPosition() != position)
                {
                    moveMouse = true;
                    nextVirus.restart();
                    bombeClock.restart();
                }
            }
            else
            {
                if(!launchFormat)
                {
                    if(nextVirus.getElapsedTime().asSeconds() > 0.5 && currentVirus < fenetres.size() && !depile)
                    {
                            currentVirus++;
                            nextVirus.restart();
                    }


                    for(unsigned int i=0;i<currentVirus;i++)
                    {
                        feneteur.setTexture(fenetres[i]);
                        feneteur.setPosition(point[i].getX(),point[i].getY());
                        App.draw(feneteur);
                    }

                    if(currentVirus >= (fenetres.size())-1 && !launchFormat && !depile)
                    {
                        App.draw(avg);
                        App.draw(bombe);

                        if(Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition(App).x > (556+avg.getPosition().x) && Mouse::getPosition(App).x < (avg.getPosition().x+avgT.getSize().x) && Mouse::getPosition(App).y > avg.getPosition().y && Mouse::getPosition(App).y < (avg.getPosition().y+15))
                        {
                             depile = true;
                             depileTime.restart();
                             string finalSc="";
                             ostringstream oss;
                             oss << 0;
                             finalSc = oss.str();

                             bombe.setString(finalSc);
                        }

                        if(Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition(App).x > (51+avg.getPosition().x) && Mouse::getPosition(App).x < (51+avg.getPosition().x+459) && Mouse::getPosition(App).y > (avg.getPosition().y+256) && Mouse::getPosition(App).y < (avg.getPosition().y+256+62))
                        {
                             depile = true;
                             depileTime.restart();
                             string finalSc="";
                             ostringstream oss;
                             oss << 0;
                             finalSc = oss.str();

                            bombe.setString(finalSc);
                        }

                        if(decompter >= 0 && bombeClock.getElapsedTime().asSeconds() > 1)
                        {
                                string finalSc="";
                                ostringstream oss;
                                oss << decompter;
                                finalSc = oss.str();

                                bombe.setString(finalSc);
                                decompter--;
                                bombeClock.restart();
                        }
                        else if(decompter < 0)
                        {
                            depile = true;

                            string finalSc="";
                            ostringstream oss;
                            oss << 0;
                            finalSc = oss.str();

                            bombe.setString(finalSc);

                            depileTime.restart();
                        }

                    }

                    if(currentVirus == 0)
                    {
                        depile = false;
                        launchFormat = true;
                        point.clear();
                        fenetres.clear();
                    }

                    if(depile && currentVirus > 0 && depileTime.getElapsedTime().asSeconds() > 0.3)
                    {
                        currentVirus--;
                        depileTime.restart();
                    }


                }
                else
                {
                    if(!finalStep)
                    {
                        if(bombeClock.getElapsedTime().asSeconds() > 0.4)
                        {
                            bombeClock.restart();
                            progresInt++;
                            progression.setSize(sf::Vector2f(progresInt, 25.69));
                        }

                        if(progresInt == 5)
                            background.setTexture(backgroundTerreur);

                        if(progresInt > 20)
                        {
                             background.setColor(Color(0,0,0));
                             finalStep = true;
                             progression.setSize(Vector2f(0,0));
                             progression.setFillColor(Color(255,255,255));
                        }



                        App.draw(formateur);
                        App.draw(progression);
                    }
                    else
                    {
                        if(bombeClock.getElapsedTime().asSeconds() > 0.2 && currentLetter < completeText.size())
                        {
                            fin.setString(fin.getString()+completeText[currentLetter]);
                            currentLetter++;
                            bombeClock.restart();
                        }

                        if(currentLetter >= (completeText.size())-1)
                            App.draw(progression);
                        App.draw(fin);
                    }
                }
            }
        }
    }

}




Screen::~Screen()
{
    //dtor
}
