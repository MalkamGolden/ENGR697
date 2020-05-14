
#include <Stepper.h>
#include <AccelStepper.h>
#include <SharpIR.h>
#define ir A0
#define model 20150
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            (working distance range according to the datasheets)
int distance_cm;
// Create a new instance of the SharpIR class:
 SharpIR SharpIR(ir, model);
 
const int stepsPerRevolution = (10000);  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
void setup() {
    // set the speed at 60 rpm:
  //myStepper.setSpeed(5);
  // initialize the serial port:
  Serial.begin(9600);

  distance_cm = SharpIR.distance();
  Serial.print("Mean distance: ");
      Serial.print(distance_cm-17);
      Serial.println(" cm");

    while(distance_cm > 17){
      myStepper.setSpeed(5);
     distance_cm = SharpIR.distance();
     Serial.println("counterclockwise");
     myStepper.step(-(200)*(distance_cm-17));
     Serial.print("Mean distance: ");
      Serial.print(distance_cm-17);
      Serial.println(" cm");
      delay(1);
      } 
      delay(10);
      myStepper.step(-(2000));
     }
  //myStepper.setSpeed(0);
  //myStepper.step(0);

int cur_Height = 0;
int cur_Pos = 0;
String des_Height = "";
int desired = -1;
int dir_Step = -1;
String upDown = "CounterClockWise - Down";

void loop() {
   distance_cm = SharpIR.distance();
    
   //Serial.println(cur_Height);
   Serial.println("ENTER DESIRED HEIGHT");  
   delay(100);
   if (Serial.available()>0) {
   // Checks for a character in the serial monitor
      des_Height = Serial.readString(); //Reading the Input string from Serial port. 
      desired = des_Height.toInt(); 
   }

   Serial.println(des_Height);
   Serial.println(des_Height.toInt());
   Serial.print("Mean distance: ");
   Serial.print(distance_cm-17);
   Serial.println(" cm");
   delay(1000);

//   if(cur_Height == des_Height.toInt()){
//    myStepper.setSpeed(0);
//   }
   if (desired > -1 && desired < 49){
    if(distance_cm > 17 && cur_Pos > 0){
      while(distance_cm > 17){
          myStepper.setSpeed(5);
          distance_cm = SharpIR.distance();
          Serial.println("counterclockwise");
          myStepper.step(-(200)*(distance_cm-17));
          Serial.print("Mean distance: ");
          Serial.print(distance_cm-17);
          Serial.println(" cm");
          delay(1);
      }
      myStepper.step(-(1600));
      cur_Pos = -1;
    }
      while (des_Height.toInt() > cur_Height){
      Serial.println("I'm Running UP");
      Serial.println(cur_Height);
      Serial.println(des_Height.toInt());
      distance_cm = SharpIR.distance();
            myStepper.setSpeed(5);
            Serial.println("clockwise");
            myStepper.step((264)*(des_Height.toInt()-cur_Height));
            Serial.print("Mean distance: ");
            Serial.print(distance_cm-17);
            Serial.println(" cm");
            cur_Height = des_Height.toInt();
            //delay(1000);
     }
   
     while (des_Height.toInt() < cur_Height){
      Serial.println("I'm Running DOWN");
      Serial.println(des_Height.toInt());
      Serial.println(cur_Height);
      distance_cm = SharpIR.distance();
            myStepper.setSpeed(5);
            Serial.println("counterclockwise");
            myStepper.step((-264)*(cur_Height-des_Height.toInt()));
            Serial.print("Mean distance: ");
            Serial.print(distance_cm-17);
            Serial.println(" cm");
            cur_Height = des_Height.toInt();
            //delay(1000);
        }
     }  else  {
      if (cur_Pos % 48 == 0) {
        dir_Step = dir_Step * -1;
        cur_Pos = 0;
        upDown = "ClockWise - UP";
      }
       while (cur_Pos < 48 && cur_Pos != -1 && desired < 0){
              myStepper.setSpeed(4);
              Serial.println(cur_Pos);
              Serial.println(upDown);
              myStepper.step((dir_Step*264));
              cur_Pos++;
              delay(100); 
        }
   }
}

      



