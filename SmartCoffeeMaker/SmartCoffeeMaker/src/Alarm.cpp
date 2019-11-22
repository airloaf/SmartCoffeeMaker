#include "Alarm.h"

#include "Arduino.h"
#include <Tone.h>

#define ALARM_LENGTH 10
#define PERIOD_LENGTH 500

Alarm::Alarm(){

    alarmToggled = false;
    periodOn = false;

}

void Alarm::update(){
    // Check if alarm toggled
    if(model->getAlarmToggle()){
        model->setAlarmToggle(false);
        alarmToggled = true;
        startTime = millis();
        periodTime = millis();
    }else if(alarmToggled){
        long currentTime = millis();

        int deltaTime = (currentTime - startTime) / 1000;
        if(deltaTime > ALARM_LENGTH){
            alarmToggled = false;
            noTone(BUZZER);
            return ;
        }

        long periodDelta = (currentTime - periodTime);
        if(periodDelta > PERIOD_LENGTH){
            periodOn = !periodOn;

            periodTime = currentTime;

            if(periodOn){
                tone(BUZZER, NOTE_A4);
            }else{
                noTone(BUZZER);
            }

        }

    }
}

void Alarm::setModel(Model *modelReference){
    model = modelReference;
}