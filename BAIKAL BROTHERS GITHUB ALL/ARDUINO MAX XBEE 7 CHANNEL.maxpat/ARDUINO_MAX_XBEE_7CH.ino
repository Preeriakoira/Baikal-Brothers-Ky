int digipin1;
int digipin2;
int digipin3;
int digipin4;
int digipin5;
int digipin6;
int digipin7;
int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;
int state5 = 0;
int state6 = 0;
int state7 = 0;

void setup() 
{
  // Create/open serial port  
  Serial.begin(57600);      

  // Define LED mode 
  // PWM LED    
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() 
{ 
  while (Serial.available() > 0) {

    
    String incoming = Serial.readStringUntil('\n');
    digipin1 = getValue(incoming, ' ', 0).toInt();
    digipin2 = getValue(incoming, ' ', 1).toInt();
    digipin3 = getValue(incoming, ' ', 2).toInt();
    digipin4 = getValue(incoming, ' ', 3).toInt();
    digipin5 = getValue(incoming, ' ', 4).toInt();
    digipin6 = getValue(incoming, ' ', 5).toInt();
    digipin7 = getValue(incoming, ' ', 6).toInt();
  }

digitalWrite(2, digipin1);

if (state1 != digipin1) {
  Serial.print(digipin1);
  digitalWrite(2, digipin6);
  state1 = digipin1;
}

digitalWrite(3, digipin2);

if (state2 != digipin2) {
  Serial.print(digipin2);
  digitalWrite(3, digipin2);
  state2 = digipin2;
}
digitalWrite(4, digipin3);

if (state3 != digipin3) {
  Serial.print(digipin3);
  digitalWrite(4, digipin3);
  state3 = digipin3;
}

digitalWrite(5, digipin4);

if (state4 != digipin4) {
  Serial.print(digipin4);
  digitalWrite(5, digipin4);
  state4 = digipin4;
}

digitalWrite(6, digipin5);

if (state5 != digipin5) {
  Serial.print(digipin5);
  digitalWrite(6, digipin5);
  state5 = digipin5;
}

digitalWrite(7, digipin6);

if (state6 != digipin6) {
  Serial.print(digipin6);
  digitalWrite(7, digipin6);
  state6 = digipin6;
}

digitalWrite(8, digipin7);

if (state7 != digipin7) {
  Serial.print(digipin7);
  digitalWrite(8, digipin7);
  state7 = digipin7;
}

}


String getValue(String data, char separator, int index)
{
 int found = 0;
  int strIndex[] = {
0, -1  };
  int maxIndex = data.length()-1;
  for(int i=0; i<=maxIndex && found<=index; i++){
  if(data.charAt(i)==separator || i==maxIndex){
  found++;
  strIndex[0] = strIndex[1]+1;
  strIndex[1] = (i == maxIndex) ? i+1 : i;
  }
 }
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
