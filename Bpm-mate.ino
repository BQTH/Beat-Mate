
byte button =2;
double startTime;
double endTime;
double duration;
double sec;
double freq;
double bpm;
byte timerRunning;
bool pressed = false;

void setup(){
pinMode (button, INPUT_PULLUP);
Serial.begin(9600);
}
void loop(){

if (timerRunning == 0 && digitalRead(button) == LOW && pressed == false ){ //button pressed & timer start
  startTime = millis();
  timerRunning = 1;
  pressed = true;
  delay(200);
}

if (timerRunning == 1 && digitalRead(button) == LOW && pressed == true){ // button pressed & timer stop + Calculations
  endTime = millis();
  timerRunning = 0;
  duration = endTime - startTime;
  sec = duration / 1000;
  freq = 1 / sec;
  bpm = freq * 60;
  Serial.print ("bpm = ");
  Serial.println (bpm);
  pressed = false;
  delay(200);
 }
}
