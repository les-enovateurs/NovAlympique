#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "Point.h"

class Screen
{
    public:
        Screen(RenderWindow &_App,Texture &_backgroundT);
        void management();
        void start();
        void init();
        void addVirus(string link);
        virtual ~Screen();
    protected:
    private:
        RenderWindow &App;
        Texture backgroundT;
        Sprite background;
        Sprite feneteur;
        vector<Texture> fenetres;
        vector<Point> point;
        Clock letsPlayJoke;
        Clock nextVirus;
        bool moveMouse;
        Vector2i position;
        int currentVirus;
        bool startUp;
        Texture avgT;
        Sprite avg;
        bool launchFormat;
        bool depile;
        Texture formateurT;
        Sprite formateur;
        Clock depileTime;
        int decompter;
        Text bombe;
        Clock bombeClock;
        RectangleShape progression;
        int progresInt;
        Texture backgroundTerreur;
        bool finalStep;
        Texture backgroundNoir;
        Text fin;
        int currentLetter;
        string completeText;

};

#endif // SCREEN_H
