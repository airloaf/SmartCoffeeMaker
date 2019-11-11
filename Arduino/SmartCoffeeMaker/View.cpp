#include "View.h"

View::View(){
  lcd = new LiquidCrystal_I2C(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
  lcd->begin(16,2);
  lcd->setCursor(0, 0);
  lcd->blink();
  lcd->clear();
}

void View::setModel(Model *modelReference){
  model = modelReference;
  
}

void View::onNotify(){
  lcd->setCursor(0, 0);
  if(model->getIsBrewing()){
    lcd->print("Is Brewing");
  }else{
    lcd->print("Not Brewing");
  }
}
