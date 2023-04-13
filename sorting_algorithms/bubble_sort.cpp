
#include "bubble_sort.h"
#include "../globals/globals.h"

void chunk1(){
    int temp;
    for(int i = 0;i<1000;i++){
        for(int j=i+1;j<1000;j++){

            if(Globals::arraySort[j] < Globals::arraySort[i]){
                temp=Globals::arraySort[i];
                Globals::arraySort[i] = Globals::arraySort[j];
                Globals::arraySort[j] = temp;
            }
            Globals::globali = i;
        }
        Globals::action=true;
        sleep(microseconds(Globals::usToDelay*330));
    }
}

bubble_sort::bubble_sort(int chunks){
if(chunks==1){chunk1();}
}

