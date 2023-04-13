
#include "SliderObj.h"

SliderObj::SliderObj(int sizex,int sizey,int posx,int posy,Color fillColor,int circleRadius,
                  int circleThickness,Color circleFillColor,Color circleOutlineColor){

    sliderBase.setSize(sf::Vector2f(sizex,sizey));
    sliderBase.setPosition(posx,posy);
    sliderBase.setFillColor(fillColor);

    sf::FloatRect  rectBounds = sliderBase.getGlobalBounds();

    circle.setRadius(circleRadius);

    circle.setPosition(rectBounds.left,rectBounds.top+(rectBounds.height/2)-circle.getRadius());

     circle.setFillColor(circleFillColor);
     circle.setOutlineColor(circleOutlineColor);
     circle.setOutlineThickness(circleThickness);


circleradius = circleRadius;
xslider = circle.getPosition().x;
yslider = circle.getPosition().y;
xrectangle = sliderBase.getPosition().x;
}

void SliderObj::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(sliderBase);
    target.draw(circle);
}
