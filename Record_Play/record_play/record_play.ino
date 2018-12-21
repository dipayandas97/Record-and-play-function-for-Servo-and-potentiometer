/* 
 *  A 1K pull up resistor for A0 pin. 
 *  A touch of GND to AO pin will toggle the system between record and play mode.
 *  Though this is made for copying a potentiometer's movement into a servo, 
    it can be used for other kinds of outputs too like LED etc (need to change the upper and lower bound of map() for respective outputs).
 *  To use a servo include Servo.h library, initialize a servo object like: Servo servo 
 *  and attach it to a pin using servo.attach(PWMpinNumber)
 *  Move the servo using servo.write() function
    */
    
boolean play=false;
boolean record=true;

int m[600];
int i=0;
int j=0;

void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}

void loop() {
  if(record)
  {
    int val = analogRead(A0);
    Serial.println(val); //print analog input value from potentiometer
    m[i] = map(val,0,1023,1,179); //map potentiometer values to servo writable values.
                                  //1 and 179 as a servo output of 0 and 180 sometimes causes jittering problem.
    i++;
    delay(50);
    //check for toggle
    if(analogRead(A1)==0){
      record=false;
      play=true;
          Serial.println("Playing...");
          delay(1000);
    }
  } 
  
  else if(play)
  {

    Serial.println(m[j]); //print servo values 
    //this is where the servo driving code goes servo.write(m[j]). 
    j++;
    delay(50); //adjust accroding to required servo speed or output frequency
    //check if loop ends, then restart the output loop
    if(j==(i-1))
    {
      j=0;
      delay(1000);
    }
    //check for toggle
    if(analogRead(A1)==LOW)
    {
      record=true;
      play=false;
      i=0;
      j=0;
     Serial.println("Recording...");
    delay(1000);
    }
  } //play
}

    
