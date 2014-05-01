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
   // RenderWindow App(VideoMode(1366, 728), "NovAlympe");

    App.setVisible(false);
    Sleep(700);
    capture captures(Texture::getMaximumSize());
    App.setVisible(true);


    Texture backgroundT;

    if(!backgroundT.loadFromFile("output.png"))
        cerr<<"error"<<endl;



    Screen screen(App,backgroundT);

    while (App.isOpen())
    {

        // Clear screen
        App.clear();
        screen.management();
        screen.start();

        // Update the window
        App.display();
    }

    return EXIT_SUCCESS;
}
