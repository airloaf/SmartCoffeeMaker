#ifndef DISPLAY_H
#define DISPLAY_H

enum State{
  BREW = 0,
  TIMER = 1,
  NUM_STATES = 2
};

char *brew_text = "Brew Coffee";
char *set_timer = "Set Timer";

class Display{
  public:
  
    Display();
    void initializeDisplay();
    char *printDisplay();
    void shiftStateRight();
    void shiftStateLeft();
    
  private:
    State state;
  
};

Display::Display(){
  initializeDisplay();
}

void Display::initializeDisplay(){
  state = BREW;
}

char *Display::printDisplay(){
  if(state == BREW){
    return brew_text;
  }else{
    return set_timer;
  }
}

void Display::shiftStateRight(){
  
}

void Display::shiftStateLeft(){
  
}


#endif
