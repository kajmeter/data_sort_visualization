//
// Created by Kajtek on 08.07.2021.
//

#ifndef DATASORTVISUALP_BUTTON_H
#define DATASORTVISUALP_BUTTON_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>
#include <ctime>
using namespace std;
using namespace sf;


class button : public Drawable {

    Color red = sf::Color::Red;
public:
        int outlineThickness;
        int sizex;
        int sizey;

        int posx;
        int posy;
        string buttonString;
        int tSize;
    button(Color outlineColor,Color fillColor,Color textColor,int thickness,int sizeofx,int sizeofy,int positionx,int positiony,string Text,int textSize);

    RectangleShape shape;
    Text buttonText ;
    void setFont(string fontPath);
private:
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

};


#endif //DATASORTVISUALP_BUTTON_H
