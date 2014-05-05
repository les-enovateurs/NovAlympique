#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;



#include "include/capture.h"
#include "include/Screen.h"



int main()
{
	//Start the application in full screen
    RenderWindow app(sf::VideoMode::getFullscreenModes()[0], "NovAlympique",sf::Style::Fullscreen);

    //Small version window (1366 x 728)
    //RenderWindow app(VideoMode(1366, 728), "NovAlympique");

    //Hide de software
    app.setVisible(false);

    //the software is waiting until the user puts the mouse correctly
    Sleep(700);

    //There is a bug with small graphics cards, that why there is a new parameter to know the maximum size of the background
    //It takes time to do a screenshot
    capture captures(Texture::getMaximumSize());

    //Display the software
    app.setVisible(true);


    Texture backgroundT;    

    //Display the screenshot and the user will think that the computer has frozen
    if(!backgroundT.loadFromFile("output.png"))
        cerr<<"error when loading the screenshot"<<endl;


    //the main class which display the different scary screens
    Screen screen(app,backgroundT);

    while (app.isOpen())
    {

        // Clear screen
        app.clear();

        //Manage the mouse
        screen.management();

        //Start the animation
        screen.start();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
