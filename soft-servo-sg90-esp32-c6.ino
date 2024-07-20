long currenttime;
long oldtime;
long ontimestamp;
long servotime;
bool fliptohigh= false;
int angle;
#define servopin D3

long currenttime2;
long oldtime2;
bool goup;
bool godown;

void setup() {
  // put your setup code here, to run once:
  pinMode(servopin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  currenttime= micros();
  if(currenttime - oldtime <= 20000){ // keeps track of the 20ms cycle time
    servotime= map(angle, 0, 180, 500, 2000);
    if(fliptohigh == true){ // If a new cycle is began, set the output HIGH once
      fliptohigh= false;
      digitalWrite(servopin, HIGH);
      ontimestamp= micros();
    }
    if(currenttime - ontimestamp >= servotime){ //after the HIGH time has passed, set the output LOW
      digitalWrite(servopin, LOW);
    }
  }else{
    oldtime= micros();
    fliptohigh= true;
  }

  // The code below cycles between 0 and 180 degrees, one by one
  currenttime2= micros();
  if(currenttime2 - oldtime2 >= 10000){
    oldtime2= micros();
    if(angle == 0){
      goup= true;
      godown= false;
    }else if(angle == 180){
      godown= true;
      goup= false;
    }
    if(goup == true){
      angle++;
    }else if(godown == true){
      angle--;
    }
  }
}
