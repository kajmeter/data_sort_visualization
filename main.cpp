#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>
#include <ctime>
#include "classes/button.h"
#include "classes/textObj.h"
#include "classes/SliderObj.h"
#include "sorting_algorithms/bubble_sort.h"
#include "globals/globals.h"

using namespace sf;
using namespace std;

int testcolor = 100;

bool logMode = true;
bool tmph = true;
int logNumber = 1;
int shcnt = 0;
int starte = 0;

bool startoff;

int ysliderout;
int xsliderout;

string msstring_string = "";

bool lock_buttons = false;
bool lock_buttons_return_color = false;
bool lock_buttons_greyout = false;

bool debug = false;

bool startBool = false;

string timeString;
string threadName;

string secArgLog;
string trdArgLog;
string frtArgLog;
string randomizeString;
int randomizeStringInt;

int xm;
int ym;

//defaults
string sort_method_type = "bubble_sort";
int chunks = 1;

int outi;

Font xf;
Text logup;
Text o;

int delVar;

RectangleShape separator;
RectangleShape rightMenu;

Event event;
Image black;
Texture blackTexture;
Sprite blackSprite;

// get variable location of window and pass it to other function to change with . the changeTitle

Image white;
Texture whiteTexture;
Sprite whiteSprite;
sf::Color grey(50,50,50,0);
sf::Color buttonGrey(25,25,90,208);
sf::Color notresponsive(30,30,30,208);
sf::Color logColor(30,30,208,208);
sf::Color logColorError(208,30,30,208);
sf::Color logColorSuccess(30,208,30,208);

Color xd;

string dir2;
string dir;
sf::Color green(0,0,0,208);
sf::Color gold(20,20,20,208);

void log(string logInfo){
    if(logMode){
        //Time calculation
        time_t logTime;struct tm*ti;
        time(&logTime); ti= localtime(&logTime);
        timeString = asctime(ti); timeString = timeString.substr(11); timeString = timeString.substr(0,timeString.size()-6);

        // Displaying information
        if(tmph){cout<<"["<<timeString<<"]"<<" :"<<"0"<<" "<<"'"<<"Starting with log arg"<<
                     "'"<<endl;tmph=false;}
        if(logMode){cout<<"["<<timeString<<"]"<<" :"<<logNumber<<threadName<<" "<<"'"<<logInfo<<secArgLog<<trdArgLog<<frtArgLog<<"'"<<endl;}
        secArgLog="";trdArgLog="";logNumber++;threadName="";frtArgLog="";

    }
}

void drawWindow(){

    button start(gold,buttonGrey,sf::Color::White,4,100,50,1097,520,"start",40);
    button sort2Button(sf::Color::White,buttonGrey,sf::Color::White,2,100,35,1025,45,"bubble sort",13);
    button sort4Button(gold,buttonGrey,sf::Color::White,2,100,35,1175,45,"insertion sort",13);

    button sort1Button(gold,buttonGrey,sf::Color::White,2,100,35,1025,100,"merge sort",13);
    button sort3Button(gold,buttonGrey,sf::Color::White,2,100,35,1175,100,"selection sort",13);

    textObj sort_method_text(sf::Color::White,"sort method",30,1066,0);
    textObj sort_delay_text(sf::Color::White,"sort delay",30,1082,145);
    textObj simulate_chunks(sf::Color::White,"simulate chunks",30,1040,215);

    button simulatechunk1(sf::Color::White,buttonGrey,sf::Color::White,2,50,25,1012,265,"one",13);
    button simulatechunk2(gold,buttonGrey,sf::Color::White,2,50,25,1087,265,"two",13);
    button simulatechunk3(gold,buttonGrey,sf::Color::White,2,50,25,1162,265,"three",13);
    button simulatechunk4(gold,buttonGrey,sf::Color::White,2,50,25,1236,265,"four",13); // tofix

    textObj slider_ms(sf::Color::Blue,"030 us",20,1230,185);
    textObj slider_ms_legend(buttonGrey,"*300 ",13,1260,175);

    SliderObj delay(150,4,1075,195,Color::Blue,10,2,Color::Blue,Color::Black);  // X: 1075 - 1225
    delay.circle.setPosition(1105,187);

ysliderout = delay.yslider;
xsliderout = delay.xslider;

     RenderWindow window = {VideoMode{static_cast<unsigned int>(1300),
                                          static_cast<unsigned int>(600)},
                                          "Sort Array Visualiser"};
    window.setFramerateLimit(60);

    //DEBUG
    sf::Vertex tiltleft[]={sf::Vertex(sf::Vector2f(1000,0)),sf::Vertex(sf::Vector2f(1300,600))};
    sf::Vertex tiltright[]={sf::Vertex(sf::Vector2f(1000,600)),sf::Vertex(sf::Vector2f(1300,0))};
    sf::Vertex hordeb[]={sf::Vertex(sf::Vector2f(1000,300)),sf::Vertex(sf::Vector2f(1300,300))};
    sf::Vertex verdeb[]={sf::Vertex(sf::Vector2f(1150,600)),sf::Vertex(sf::Vector2f(1150,0))};
    sf::Vertex top[]={sf::Vertex(sf::Vector2f(1000,150)),sf::Vertex(sf::Vector2f(1300,150))};
    sf::Vertex down[]={sf::Vertex(sf::Vector2f(1000,450)),sf::Vertex(sf::Vector2f(1300,450))};
    sf::Vertex up[]={sf::Vertex(sf::Vector2f(1075,600)),sf::Vertex(sf::Vector2f(1075,0))};
    sf::Vertex low[]={sf::Vertex(sf::Vector2f(1225,600)),sf::Vertex(sf::Vector2f(1225,0))};
    //DEBUG

    //separator
    sf::Vertex separator2[]={
            sf::Vertex(sf::Vector2f(1000,0),sf::Color::Blue),
            sf::Vertex(sf::Vector2f(1000,600),sf::Color::Red)
    };


  //  blackSprite.rotate(180);
    //blackSprite.setPosition(1000,600);
    while(true){
        // add safe resizing
        /////////LEFT SIDE/////////
        window.clear(grey);
        window.pollEvent(event);

        window.draw(delay);

        window.draw(whiteSprite);
        window.draw(blackSprite);
        window.draw(o);
        window.draw(logup);

        window.draw(separator2,2,sf::Lines);


        //////////DEBUG//////////
        if(debug){
            window.draw(tiltleft,2,sf::Lines);window.draw(tiltright,2,sf::Lines);window.draw(hordeb,2,sf::Lines);
            window.draw(verdeb,2,sf::Lines);window.draw(top,2,sf::Lines);window.draw(down,2,sf::Lines);
            window.draw(up,2,sf::Lines);window.draw(low,2,sf::Lines);
        }
        //////////DEBUG//////////


        //////////MENU//////////
        //texts
        window.draw(sort_method_text);
        window.draw(sort_delay_text);
        window.draw(simulate_chunks);

        // buttons
        window.draw(start);

        window.draw(sort1Button);
        window.draw(sort2Button);
        window.draw(sort3Button);
        window.draw(sort4Button);


        window.draw(slider_ms);
        window.draw(slider_ms_legend);

        window.draw(simulatechunk1);
        window.draw(simulatechunk2);
        window.draw(simulatechunk3);
        window.draw(simulatechunk4);




        // ADD GREYING OUT BUTTONS // RESPONSIVE if responsive
           //MOUSE PRESS CHECK


           // COLOR CHANGES
        if(startoff == true && start.shape.getOutlineColor() == sf::Color::White){
            start.shape.setOutlineColor(gold);
            startoff = false;
        }
        //locks
        if(lock_buttons_greyout == true){
            start.shape.setFillColor(notresponsive);
            sort1Button.shape.setFillColor(notresponsive);
            sort2Button.shape.setFillColor(notresponsive);
            sort3Button.shape.setFillColor(notresponsive);
            sort4Button.shape.setFillColor(notresponsive);
            simulatechunk1.shape.setFillColor(notresponsive);
            simulatechunk2.shape.setFillColor(notresponsive);
            simulatechunk3.shape.setFillColor(notresponsive);
            simulatechunk4.shape.setFillColor(notresponsive);
            lock_buttons_greyout = false;
        }

        if(lock_buttons_return_color == true){
            start.shape.setFillColor(buttonGrey);
            sort1Button.shape.setFillColor(buttonGrey);
            sort2Button.shape.setFillColor(buttonGrey);
            sort3Button.shape.setFillColor(buttonGrey);
            sort4Button.shape.setFillColor(buttonGrey);
            simulatechunk1.shape.setFillColor(buttonGrey);
            simulatechunk2.shape.setFillColor(buttonGrey);
            simulatechunk3.shape.setFillColor(buttonGrey);
            simulatechunk4.shape.setFillColor(buttonGrey);
            lock_buttons_return_color = false;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ // MOUSE PRESS CHECK
            xm = sf::Mouse::getPosition(window).x;
            ym = sf::Mouse::getPosition(window).y;

            if(!lock_buttons){ // LOCK CHECK


                // start button 2
                if(start.shape.getGlobalBounds().contains(xm,ym)) {
                    secArgLog = to_string(xm) + " x ";
                    trdArgLog = to_string(ym);
                    frtArgLog = ")";
                    log("Registered mouse press at (");
                    startBool == true;
                    start.shape.setOutlineColor(sf::Color::White);
                    secArgLog = to_string(start.shape.getGlobalBounds().height);
                    trdArgLog = to_string(start.shape.getGlobalBounds().width);
                    log("position : ");
                    if (startBool) {
                        cout << "PROGRAM HAS ALREADY STARTED!" << endl;
                    }
                    startBool = true;
                    sleep(milliseconds(100));
                }

                //sort buttons//

                // bubble sort
                if(sort2Button.shape.getGlobalBounds().contains(xm,ym)){
                    sort1Button.shape.setOutlineColor(gold);sort2Button.shape.setOutlineColor(Color::White);
                    sort3Button.shape.setOutlineColor(gold);sort4Button.shape.setOutlineColor(gold);

                    sort_method_type = "bubble_sort";
                }

                // insertion sort
                if(sort4Button.shape.getGlobalBounds().contains(xm,ym)){
                    sort1Button.shape.setOutlineColor(gold);sort2Button.shape.setOutlineColor(gold);
                    sort3Button.shape.setOutlineColor(gold);sort4Button.shape.setOutlineColor(Color::White);

                    sort_method_type = "bubble_sort";
                }

                // merge sort
                if(sort1Button.shape.getGlobalBounds().contains(xm,ym)){
                    sort1Button.shape.setOutlineColor(Color::White);sort2Button.shape.setOutlineColor(gold);
                    sort3Button.shape.setOutlineColor(gold);sort4Button.shape.setOutlineColor(gold);

                    sort_method_type = "bubble_sort";
                }

                // selection sort
                if(sort3Button.shape.getGlobalBounds().contains(xm,ym)){
                    sort1Button.shape.setOutlineColor(gold);sort2Button.shape.setOutlineColor(gold);
                    sort3Button.shape.setOutlineColor(Color::White);sort4Button.shape.setOutlineColor(gold);

                    sort_method_type = "bubble_sort";
                }


                // chunk buttons

                //one
                if(simulatechunk1.shape.getGlobalBounds().contains(xm,ym)){
                    simulatechunk1.shape.setOutlineColor(Color::White);simulatechunk3.shape.setOutlineColor(gold);
                    simulatechunk2.shape.setOutlineColor(gold);simulatechunk4.shape.setOutlineColor(gold);
                }

                //two
                if(simulatechunk2.shape.getGlobalBounds().contains(xm,ym)){
                    simulatechunk1.shape.setOutlineColor(gold);simulatechunk3.shape.setOutlineColor(gold);
                    simulatechunk2.shape.setOutlineColor(Color::White);simulatechunk4.shape.setOutlineColor(gold);
                }

                //three
                if(simulatechunk3.shape.getGlobalBounds().contains(xm,ym)){
                    simulatechunk1.shape.setOutlineColor(gold);simulatechunk3.shape.setOutlineColor(Color::White);
                    simulatechunk2.shape.setOutlineColor(gold);simulatechunk4.shape.setOutlineColor(gold);
                }

                //four
                if(simulatechunk4.shape.getGlobalBounds().contains(xm,ym)){
                    simulatechunk1.shape.setOutlineColor(gold);simulatechunk3.shape.setOutlineColor(gold);
                    simulatechunk2.shape.setOutlineColor(gold);simulatechunk4.shape.setOutlineColor(Color::White);
                }




            } // LOCK CHECK


            // slider
            if(delay.circle.getGlobalBounds().contains(xm,ym)){
                  if(delay.circle.getPosition().x>=1075 && delay.circle.getPosition().x<=1225-delay.circleradius){
                      delay.circle.setPosition((xm-delay.circleradius),ysliderout);

                  }else if(delay.circle.getPosition().x<1075) {
                      delay.circle.setPosition((1075),ysliderout);
                  }else if(delay.circle.getPosition().x>1225-delay.circleradius){
                      delay.circle.setPosition((1225-delay.circleradius),ysliderout);
                  }

                  if(delay.circle.getPosition().x-1075 >= 0 && delay.circle.getPosition().x-1075 <= 150 ){
                      cout<<delay.circle.getPosition().x-1075<<endl;
                      Globals::usToDelay = delay.circle.getPosition().x-1075;
                     // cout<<endl<<"x:"<<delay.circle.getPosition().x;
                     // cout<<endl<<"y:"<<delay.circle.getPosition().y;
                      msstring_string = to_string((int)(delay.circle.getPosition().x-1075));
                      if((int)(delay.circle.getPosition().x-1075)<100 && (int)(delay.circle.getPosition().x-1075) > 9){
                          msstring_string.insert(0,"0");
                          msstring_string.append(" us");
                      }else if((int)(delay.circle.getPosition().x-1075)>=100){
                          msstring_string.append(" us");
                      }

                       if((int)(delay.circle.getPosition().x-1075)<10){
                           msstring_string.insert(0,"00");
                           msstring_string.append("us");
                       }
                      slider_ms.textDec.setString(msstring_string);
                  }
            }
        } // MOUSE PRESS CHECK
        //dynamic title
        //DISPLAY
        window.display();
    }
}

void config(){
    if(shcnt==0 || startBool){
        char directory[256];
        getcwd(directory, 256);
         dir = directory;
        dir.append("/assets/black.png");
        string dir2;

        dir2 = directory;
        dir2.append("/assets/white.png");
        black.loadFromFile(dir);
       blackTexture.loadFromImage(black);
        blackSprite.setTexture(blackTexture);

        white.loadFromFile(dir2);
        whiteTexture.loadFromImage(white);
        whiteSprite.setTexture(whiteTexture);



    }else{
        blackTexture.loadFromImage(black);
        blackSprite.setTexture(blackTexture);
    }
    shcnt++;
}

void separatorConfig(){
    sf::Color greygood(134,134,134,0);
    separator.setSize(sf::Vector2f(5,600));
    separator.setPosition(1000,0);
    separator.setFillColor(sf::Color::Blue);

    rightMenu.setSize(sf::Vector2f(300,600));
    rightMenu.setPosition(1000,0);
    rightMenu.setFillColor(greygood);
}

void loadFont(){
    dir2 = "C:\\Users\\Kajtek\\CLionProjects\\DataSortVisualP\\cmake-build-debug\\fonts\\Roboto-Black.ttf";
    xf.loadFromFile(dir2);
}

void randomizeArray(){
    for(int i = 0;i<1000;i++){
        Globals::arraySort[i] = (rand() % (600+1-1))+1;
        //
    }
}
///add stop button where start is///
void iterateArray(){
    for(int i = 0;i<1000;i++){
        for(int j=0;j<Globals::arraySort[i];j++){
            black.setPixel(i,j,Color::Transparent);
        }
    }
    blackTexture.loadFromImage(black);
    blackSprite.setTexture(blackTexture);
    config();
}

void leftTopText(Color color,string Text){
    logup.setString(Text);
    logup.setCharacterSize(35);
    logup.setFillColor(sf::Color::Red);
    logup.setFillColor(color);
    logup.setFont(xf);
}


void percentageBar(){
    randomizeStringInt = Globals::globali/10;
    randomizeString = "Sorting array (";
    randomizeString.append(to_string(randomizeStringInt));
    randomizeString.append(" / 100 %)");

    sf::Color testxd(0,(randomizeStringInt*2)+9,((testcolor-randomizeStringInt)*2)+8,208);
    leftTopText(testxd,randomizeString);
}

void countdown(int numbers,int sleepTime){
        o.setString("");
        o.setCharacterSize(100);
        o.setFillColor(sf::Color::White);
        o.setFont(xf);
        o.setPosition(480,200);
    for(int i = numbers;i>0;i--){
        o.setString(to_string(i));
        sleep(sleepTime);
    }
    o.setString("");
}

//add stop restart integrated in start button
//add countdown skip button

void activeRefresh(){
    while(true){
        if(Globals::action==true){
            black.loadFromFile(dir);
            iterateArray();
            percentageBar();
            Globals::action=false;
        }
    }
}

int main() {
    sf::Thread drawWindowThread(drawWindow);
    sf::Thread actionThread(activeRefresh);
    // configuration // implement here waiting for java program (config window reading from the same xml)
    // add seed 'debug' that shows all debug tools

    drawWindowThread.launch();
    loadFont();
    leftTopText(logColor, "STANDBY");
    log("window thread launched");
    while(true){
        sleep(1); // reduces my cpu usage ,like 10%
        if(startBool == true) {
            // button lock
            lock_buttons = true;
            lock_buttons_greyout = true;

            startBool = false;
            // main config
            log("running main configuration");
            separatorConfig();
            loadFont();

            // randomizing array
            leftTopText(logColor, "Randomizing array");
            randomizeArray();
            sleep(1);

            // displaying preview of randomization
            config();
            iterateArray();
            config();

            //locking buttons

            // running countdown
            leftTopText(logColor, "waiting");
            countdown(5, 1);

            // sorting
            if(sort_method_type == "bubble_sort"){
                actionThread.launch();
                bubble_sort(1);
            }
            sleep(1);
            actionThread.terminate();


            leftTopText(logColorSuccess, "Sorting array ( 100 / 100 %)");
            startoff = true;

            //freeing buttons
            lock_buttons = false;
            lock_buttons_return_color = true;
        }
    }
}

