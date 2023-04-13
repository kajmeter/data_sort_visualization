
#include "button.h"

string fontDirectory;
Font font;

void button::setFont(string fontPath){
    font.loadFromFile(fontPath);
};

button::button(Color outlineColor,Color fillColor,Color textColor,int thickness,int sizeofx,int sizeofy,int positionx,int positiony,string Text,int textSize){
    //default
     fontDirectory = "C:\\Users\\Kajtek\\CLionProjects\\DataSortVisualP\\cmake-build-debug\\fonts\\Roboto-Black.ttf";
     font.loadFromFile(fontDirectory);

    outlineThickness = thickness;
    sizex = sizeofx;
    sizey = sizeofy;
    tSize = textSize;

    buttonString = Text;

    posx = positionx;
    posy = positiony;

    //fun;

    shape.setSize(sf::Vector2f(sizex,sizey));
    shape.setOutlineColor(outlineColor);
    shape.setOutlineThickness(outlineThickness);
    shape.setPosition(posx,posy);
    shape.setFillColor(fillColor);

    buttonText.setString(buttonString);
    buttonText.setCharacterSize(tSize);
    buttonText.setFillColor(textColor);
    buttonText.setFont(font);
    buttonText.setCharacterSize(tSize);

    //buttonText.setPosition(480,200);

    sf::FloatRect rectBounds = shape.getGlobalBounds();
    sf::FloatRect textBounds = buttonText.getGlobalBounds();

    buttonText.setPosition((rectBounds.left+(rectBounds.width/2)-(textBounds.width)/2),
                           rectBounds.top+(rectBounds.height/2)-textBounds.height
    );

};

void button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape);
    target.draw(buttonText);
}
