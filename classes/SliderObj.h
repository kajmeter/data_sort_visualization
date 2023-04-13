

#ifndef DATASORTVISUALP_SLIDER_H
#define DATASORTVISUALP_SLIDER_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>
#include <ctime>

using namespace std;
using namespace sf;

class SliderObj : public Drawable {

public:
int yslider;
int xslider;
int circleradius;
int xrectangle;
    SliderObj(int sizex, int sizey, int posx, int posy, Color fillColor, int circleRadius, int circleThickness,
              Color circleFillColor, Color circleOutlineColor);

    RectangleShape sliderBase;
    CircleShape circle;


private:
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

};


#endif //DATASORTVISUALP_SLIDER_H
