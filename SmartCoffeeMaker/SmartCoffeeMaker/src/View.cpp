#include "View.h"

View::View(){
  lcd = new LiquidCrystal_I2C(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
  lcd->begin(16,2);
  lcd->setCursor(0, 0);
  lcd->blink();
  lcd->clear();

  previousTopDisplayText = nullptr;
}

void View::setModel(Model *modelReference){
  model = modelReference;
  
}

void View::onNotify(){

  const char *displayText = model->getDisplayText();

  if(previousTopDisplayText != displayText){
    lcd->setCursor(0, 0);
    lcd->clear();
    lcd->print(displayText);
    previousTopDisplayText = displayText;
  }


}
