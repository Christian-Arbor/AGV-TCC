// ========================================================================================================
// --- Mapeamento de Hardware ---

#define    sens_D   6                                  //sensor ir direito
#define    sens_E   7                                  //sensor de ir esquerdo
#define    m1_ah    2                                  //motor 1 sentido anti-horário
#define    m2_ah    3                                  //motor 2 sentido anti-horário
#define    m1_pwm   10                                 //pwm do motor 1
#define    m2_pwm   11                                 //pwm do motor 2
#define    m1_hr    12                                 //motor 1 sentido horário
#define    m2_hr    4                                 //motor 2 sentido horário  
#define   sensor_U 8

// ========================================================================================================
// --- Configurações Iniciais ---
void setup() 
{
    
    pinMode(sens_D,   INPUT);                            //entrada para o sensor ir direito
    pinMode(sens_E,   INPUT);                            //entrada para o sensor de ir esquerdo
    pinMode(sensor_U, INPUT);
    pinMode(m1_ah,    OUTPUT);                            //saída para controle de inversão do motor 1
    pinMode(m2_ah,    OUTPUT);                            //saída para controle de inversão do motor 2
    pinMode(m1_pwm,   OUTPUT);                            //saída para controle pwm do motor 1
    pinMode(m2_pwm,   OUTPUT);                            //saída para controle pwm do motor 2

    digitalWrite(m1_ah,  LOW);                         //Robô move-se para frente
    digitalWrite(m2_ah,  LOW);
    digitalWrite(m1_hr, HIGH);                        
    digitalWrite(m2_hr, HIGH);
    
    
    analogWrite(m1_pwm, 0x00);                          //motores parado
    analogWrite(m2_pwm, 0x00);
    
   


} //end setup


// ========================================================================================================
// --- Loop Infinito ---

void loop() 
{
  
  if(digitalRead(sensor_U)==1){                        //sensor_U está atuado ?
     analogWrite(m1_pwm, 0x00);                        //sim  
    analogWrite(m2_pwm, 0x00);                         //para motores
  }
  if(!digitalRead(sens_D))                              //sensor esquerdo está na linha preta?
  {                                                     //sim
    analogWrite(m1_pwm, 0x80);                          //aumenta velocidade do motor da direita
    analogWrite(m2_pwm, 0x00);                          //para motor da esquerda
    
  } //end if sens_2

 
  if(!digitalRead(sens_E))                              //sensor direito está na linha preta?
  {                                                     //sim
    analogWrite(m1_pwm, 0x00);                          //para motor da direita
    analogWrite(m2_pwm, 0x80);                          //aumenta velocidade do motor da esquerda
    
  } //end if sens_1


  //Se nenhum sensor estiver na linha preta, move robô para frente
  else
  {
    analogWrite(m1_pwm, 0x60);
    analogWrite(m2_pwm, 0x60);  
    
  } //end else

  /*Serial.begin(230400);
    Serial.println("sensor: ");
    Serial.println(digitalRead(sensor_U)); */
  

  
} //end loop