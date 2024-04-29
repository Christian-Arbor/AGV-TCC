

// ========================================================================================================
// --- Mapeamento de Hardware ---

#define    echoPin  5
#define    trigPin  4
#define    sensor   2


void setup() {
  
pinMode(echoPin,  INPUT);
pinMode(trigPin, OUTPUT);
pinMode(sensor, OUTPUT);
}
unsigned int duracao=0;
unsigned int distancia=0;


void loop() {

 
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duracao=pulseIn(echoPin,HIGH);
  distancia=duracao*0.017;
  //delay(100);
  
  if(distancia<=14)
  {
    digitalWrite(sensor,HIGH);
    
  }
      
 
   else
   {
    digitalWrite(sensor,LOW);
   }
   
   /* Serial.begin(115200);
  Serial.println("CM: ");
  Serial.println(distancia);
  
   Serial.println("sensor: ");
   Serial.println(digitalRead(sensor)); */

}

//https://www.canva.com/design/DAFCM7q2LYs/WPO40rmOnEEz89xsKgHK_g/view?utm_content=DAFCM7q2LYs&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton