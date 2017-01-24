int trafficLights1[] = {2,3,4};  // ПИНЫ к светодиодам красный, желтый, зеленый
int situations = 4;
int duration[] = {8000,3000,10000}; // время работы светодиодов (красный, желтый, зеленый)
long previousCars = 0;
int ledState = LOW;
int state;
int i = 0;
 
void setup()
{
  for(int i = 0; i < 3; i++) {
    pinMode(trafficLights1[i], OUTPUT);
  }
  Serial.begin(9600);
}
 
void loop()
{ 
  unsigned long currentMillis = millis();   
  if(currentMillis - previousCars < duration[i]) {      
    situation(i);   
  } else { 
    previousCars = currentMillis; 
    if(i >= situations) {
      i = 0;
    } else {
      i++;
    }   
  }
}
 
void activateTrafficLight1(String lights) 
{ 
  for(int x = 0; x < 3; x++)  {
    if(lights[x] == '0') state = LOW;
    if(lights[x] == '1') state = HIGH;
    digitalWrite(trafficLights1[x], state); 
  }

}

 
void situation(int i)
{
  switch(i){
    case 0: 
      activateTrafficLight1("100"); // 100 means red ON, yellow OFF, green OFF
      break;              // 1 is ON and 0 is OFF
    case 1: 
      activateTrafficLight1("110"); // 110: red ON, yellow ON, green OFF
      break;  
    case 2: 
      activateTrafficLight1("001");
      break;
    case 3: 
      activateTrafficLight1("010");
      break;  
  }
}

