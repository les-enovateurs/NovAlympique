#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;



#include "include/capture.h"
#include "include/menu.h"
#include "include/Screen.h"



int main()
{

    RenderWindow App(sf::VideoMode::getFullscreenModes()[0], "Destructor Nova",sf::Style::Fullscreen);
    //RenderWindow App(VideoMode(1366, 728), "NovAlympe"); // Pour faire des tests

    App.setVisible(false);

    Sleep(700);//Pour bloquer la souris

    capture captures;//impression d'écran 
    App.setVisible(true);

    Texture backgroundT;

    if(!backgroundT.loadFromFile("output.png"))//Affichage de l'image
        cerr<<"error"<<endl;



    Screen screen(App,backgroundT);

    while (App.isOpen())
    {

        // Clear screen
        App.clear();
        screen.management();//gestion clavier + souris
        screen.start();//lancement de la blague

        // Update the window
        App.display();
    }

    return EXIT_SUCCESS;
}
