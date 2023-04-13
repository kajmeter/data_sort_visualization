
#include "textObj.h"

string fontDirectoryText;
Font fontText;

textObj::textObj(Color color,string text,int size,int posx,int posy){
    //default
    fontDirectoryText = "C:\\Users\\Kajtek\\CLionProjects\\DataSortVisualP\\cmake-build-debug\\fonts\\Roboto-Black.ttf";
    fontText.loadFromFile(fontDirectoryText);

    textDec.setString(text);
    textDec.setCharacterSize(size);
    textDec.setFillColor(color);
    textDec.setFont(fontText);
    textDec.setPosition(posx,posy);
}

void textObj::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(textDec);
}