#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
#define ir6 A5
#define ir7 7
#define ml_e 10
#define mr_e 11
#define ml_1 4
#define ml_2 5
#define mr_1 2
#define mr_2 3

const int left_speed=120;
const int right_speed=120;
int y=left_speed;
int z=right_speed;
float CurrentTime = 1  , PreviousTime = 0 ,delta;
float P = 0.06;
float D = 0.009 ;
float current_error = 0 ;
float previous_error = 0 ;
float d_error = 0 ;


void setup() {
  Serial.begin(115200);
    pinMode(ir1,INPUT);
    pinMode(ir2,INPUT);
    pinMode(ir3,INPUT);
    pinMode(ir4,INPUT);
    pinMode(ir5,INPUT);
    pinMode(ir6,INPUT);
    pinMode(ir7,INPUT);
   pinMode(ml_e,OUTPUT);
   pinMode(ml_1,OUTPUT);
   pinMode(ml_2,OUTPUT);
   pinMode(mr_e,OUTPUT);
   pinMode(mr_1,OUTPUT);   
   pinMode(mr_2,OUTPUT);
    
    
      
  }
  
  void loop() {
                    sensor(); 
                   if(analogRead(ir1)>800 && analogRead(ir6)>800 && digitalRead(ir7)==0){ 
                       
                        CurrentTime = millis();
                        delta = (CurrentTime - PreviousTime) / 1000;

                            current_error =  !(digitalRead(ir4))&&(digitalRead(ir3)) ;
                          d_error = (current_error - previous_error) / delta ; // 10 miliseconds = 1/100 seconds
                          PreviousTime = CurrentTime ; 
                           
                     forward();
                    }
                     
    else if((analogRead(ir5)<800 && analogRead(ir6)<800)){                     
                      stop(); delay(10);  left();                                                                                                                                                                                    
    }     
    else if(analogRead(ir5)>800 && analogRead(ir6)>800 && analogRead(ir1)<800 && analogRead(ir2)<800 && digitalRead(ir7)==1 ){
                                            stop(); delay(10);  right();       
                                            } 
    else if(analogRead(ir3)>800 && analogRead(ir4)>800 && digitalRead(ir7)==1){
                                            stop(); delay(10); reverse();       
                                            }
                                  
                                                                                                                                                                                      

    

}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    void stop(){
     digitalWrite(ml_1,LOW);
     digitalWrite(ml_2,LOW);
     digitalWrite(mr_1,LOW);
     digitalWrite(mr_2,LOW);
      }
  
    void reverse(){
     digitalWrite(ml_1,LOW);
     digitalWrite(ml_2,HIGH);
     digitalWrite(mr_1,HIGH);
     digitalWrite(mr_2,LOW);
           delay(200);
      }
    void right(){
      analogWrite(ml_e,y);
     analogWrite(mr_e,z);
     digitalWrite(ml_1,HIGH );
     digitalWrite(ml_2,LOW);
     digitalWrite(mr_1,LOW);
     digitalWrite(mr_2,HIGH);
         delay(200);
      }   
    void left(){
      analogWrite(ml_e,y);
     analogWrite(mr_e,z);
     digitalWrite(ml_1,LOW );
     digitalWrite(ml_2,LOW);
     digitalWrite(mr_1,HIGH);
     digitalWrite(mr_2,LOW);
     delay(200);
     
      }
      void forward(){
     
 
//     analogWrite(ml_e,y);
//     analogWrite(mr_e,z);  
//     digitalWrite(ml_1,HIGH );
//     digitalWrite(ml_2,LOW);
//     digitalWrite(mr_1,HIGH);
//     digitalWrite(mr_2,LOW);
//      if(digitalRead(ir7)==1){
//      int x=15;
//      if(analogRead(ir4)>800){
//        y=y+x;
//       if(analogRead(ir4)<800){
//           y=y-x;
//        }}
//    if(analogRead(ir3)>800){
//      z=z+x;   
//      if(analogRead(ir3)<800){
//           z=z-x;
float v = (current_error)*P + (d_error)*D ; 
  analogWrite(ml_e,left_speed+ v * (-1));
  digitalWrite(ml_1, 1);
  digitalWrite(ml_2, 0);

  // give right motor velocity
  analogWrite(ml_e, right_speed + v);
  digitalWrite(mr_1, 1); digitalWrite(mr_2, 0);

    }
// else{
//     y=left_speed;
//     z=right_speed;
//       }
//    }
   
   void sensor(){
  Serial.print((analogRead(ir1)) ); 
 Serial.print(" ");
 Serial.print((analogRead(ir2)) );
 Serial.print(" ");    
 Serial.print((analogRead(ir3)) );
 Serial.print(" ");
 Serial.print((analogRead(ir4)) );
 Serial.print(" ");
 Serial.print((analogRead(ir5)) );
 Serial.print(" ");
 Serial.print((analogRead(ir6)) );
 Serial.print(" ");
Serial.println((digitalRead(ir7)) );
                                      void done() {
  digitalWrite(ml_1, LOW );
  digitalWrite(ml_2, LOW);
  digitalWrite(mr_1, LOW);
  digitalWrite(mr_2, LOW);
  delay(10000);
  j = 0 ;
  i = 0 ;
  while (j < index) {
    if (sense[j] == 'L' && sense[j + 1] == 'B' && sense[j + 2] == 'R') {
      sense[j] = 'B' ;
      if (j + 4 >= index) {
        sense[j + 1] = sense[j + 3];
        sense[j + 2] = '\n';
        sense[j + 3] = '\n';
      }
      else {
        for (i = j + 3; i < index; i++) {
          sense[i - 2] = sense[i];
        }
      }
      j = 0 ;
      index = index - 2 ;
    }
    else if (sense[j] == 'L' && sense[j + 1] == 'B' && sense[j + 2] == 'S') {
      sense[j] = 'R' ;
      if (j + 4 >= index) {
        sense[j + 1] = sense[j + 3];
        sense[j + 2] = '\n';
        sense[j + 3] = '\n';
      }
      else {
        for (i = j + 3; i < index; i++) {
          sense[i - 2] = sense[i];
        }
      }
      j = 0 ;
      index = index - 2 ;
    }
    else if (sense[j] == 'R' && sense[j + 1] == 'B' && sense[j + 2] == 'L') {
      sense[j] = 'B' ;
      if (j + 4 >= index) {
        sense[j + 1] = sense[j + 3];
        sense[j + 2] = '\n';
        sense[j + 3] = '\n';
      }
      else {
        for (i = j + 3; i < index; i++) {
          sense[i - 2] = sense[i];
        }
      }
      j = 0 ;
      index = index - 2 ;
    }
    else if (sense[j] == 'S' && sense[j + 1] == 'B' && sense[j + 2] == 'L') {
      sense[j] = 'R' ;
      if (j + 4 >= index) {
        sense[j + 1] = sense[j + 3];
        sense[j + 2] = '\n';
        sense[j + 3] = '\n';
      }
      else {
        for (i = j + 3; i < index; i++) {
          sense[i - 2] = sense[i];
        }
      }
      j = 0 ;
      index = index - 2 ;
    }
    else if (sense[j] == 'S' && sense[j + 1] == 'B' && sense[j + 2] == 'S') {
      sense[j] = 'B' ;
      if (j + 4 >= index) {
        sense[j + 1] = sense[j + 3];
        sense[j + 2] = '\n';
        sense[j + 3] = '\n';
      }
      else {
        for (i = j + 3; i < index; i++) {
          sense[i - 2] = sense[i];
        }
      }
      j = 0 ;
      index = index - 2 ;
    }
    else if (sense[j] == 'L' && sense[j + 1] == 'B' && sense[j + 2] == 'L') {
      sense[j] = 'S' ;
      if (j + 4 >= index) {
        sense[j + 1] = sense[j + 3];
        sense[j + 2] = '\n';
        sense[j + 3] = '\n';
      }
      else {
        for (i = j + 3; i < index; i++) {
          sense[i - 2] = sense[i];
        }
      }
      j = 0 ;
      index = index - 2 ;
    }
    else {
      j++;
    }
  }
  // Now its time to start maze solution Run ( sortedsense Run )
  // start with taking index 0
  index = 0 ;
  shortest();
}
    }
void shortest() {
  index = 0 ;
  while (1) {

    sensor();
    forward(v);
    if ((analogRead(ir5) < 800 && analogRead(ir6) < 800) && analogRead(ir4) < 800) {
      if (digitalRead(ir7) == 0 && digitalRead(ir8) == 0  ) {
       stop();
      }
      else if (sense[index] == 'L') {
        stop();
        left();
        index++;
      }
      else if (sense[index] == 'R') {
        stop();
        right();
        index++;
      }
      else if (sense[index] == 'B') {
        stop();
        reverse();
        index++;
      }
      else if (sense[index] == 'S') {
        forward(v);
        index++;

      }
      else {
        stop();
      }
    }

    // Note: Forward sensor gives 1 when there is a black
    // only right possibleir
    if (analogRead(ir6) > 800 && analogRead(ir5) > 800 && analogRead(ir2) < 800 && analogRead(ir3) < 800 && analogRead(ir1) < 800 && digitalRead(ir7) == 0) {
      if (sense[index] == 'L') {
        stop();
        left();
        index++;
      }
      else if (sense[index] == 'R') {
        stop();
        right();
        index++;
      }
      else if (sense[index] == 'B') {
        stop();
        reverse();
        index++;
      }
      else if (sense[index] == 'S') {
        forward(v);
        index++;

      }
      else {
        stop();
      }
    }

    // right and forward possible
    if (analogRead(ir6) > 800 && analogRead(ir1) < 800 && digitalRead(ir7) == 0) {
      if (sense[index] == 'L') {
        stop();
        left();
        index++;
      }
      else if (sense[index] == 'R') {
        stop();
        right();
        index++;
      }
      else if (sense[index] == 'B') {
        stop();
        reverse();
        index++;
      }
      else if (sense[index] == 'S') {
        forward(v);
        index++;

      }
      else {
        stop();
      }
    }

    // If all Black ahead : No way forward
    if (analogRead(ir1) > 800 && analogRead(ir2) > 800 && analogRead(ir3) > 800 && analogRead(ir4) > 800
        && analogRead(ir5) > 800 && analogRead(ir6) > 800) {
      if (sense[index] == 'L') {
        stop();
        left();
        index++;
      }
      else if (sense[index] == 'R') {
        stop();
        right();
        index++;
      }
      else if (sense[index] == 'B') {
        stop();
        reverse();
        index++;
      }
      else if (sense[index] == 'S') {
        forward(v);
        index++;

      }
      else {
        stop();
      }
    }
  }
}