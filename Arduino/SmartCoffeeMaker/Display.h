#pragma once

enum Option {

  BREW = 0,
  DISPLAY_STATS = 1,
  NUM_OPTIONS
  
};

char *BREW_TEXT = "Brew Coffee";
char *strings[] = {
  BREW_TEXT
};

class Display{

  public:
    Display();

  private:
    Option currentOption;
};
