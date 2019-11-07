// Rotary Encoder inputs
#define inputCLK 4
#define inputDT 5

// LED Outputs
#define ledCW 8
#define ledCCW 9

int counter = 0;
int currentStateCLK;
int previousStateCLK;

String encdir = "";

void setup() {
  pinMode (inputCLK, INPUT);
  pinMode(inputDT, INPUT);

  pinMode(ledCW, OUTPUT);
  pinMode(ledCCW, OUTPUT);

  Serial.begin(9600);

  previousStateCLK = digitalRead(inputCLK);

}

void loop() {

  currentStateCLK = digitalRead(inputCLK);

  if( currentStateCLK != previousStateCLK){
    if(digitalRead(inputDT) != currentStateCLK){
      counter--;
      encdir = "CCW";
      digitalWrite(ledCW, LOW);
      digitalWrite(ledCCW, HIGH);
    }else{
      counter++;
      encdir = "CW";
      digitalWrite(ledCW, HIGH);
      digitalWrite(ledCCW, LOW);
    }
    Serial.print("Direction: ");
    Serial.print(encdir);
    Serial.print(" -- Value: ");
    Serial.println(counter);
  }

  previousStateCLK = currentStateCLK;

}
