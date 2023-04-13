
#ifndef DATASORTVISUALP_TEXT_H
#define DATASORTVISUALP_TEXT_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>
#include <ctime>
using namespace std;
using namespace sf;

class textObj : public Drawable {
public:
    Text textDec;
    textObj(Color color,string text,int size,int posx,int posy);

private:
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;


};


#endif //DATASORTVISUALP_TEXT_H
