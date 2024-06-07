// Define os pinos Trig e Echo
const int trigPin = 4;
const int echoPin = 5;
// Define o pino PIR
const int pinoPIR = 3;
// Define os pinos dos LEDs
const int ledPin1 = 2; 
const int ledPin2 = 1; 
const int ledPin3 = 0; 

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  pinMode(trigPin, OUTPUT); // Define o pino Trig como saída
  pinMode(echoPin, INPUT);  // Define o pino Echo como entrada
  pinMode(pinoPIR, INPUT);  // Define o pino PIR como entrada
  pinMode(ledPin1, OUTPUT); // Define o pino LED como saída
  pinMode(ledPin2, OUTPUT); // Define o pino LED como saída
  pinMode(ledPin3, OUTPUT); // Define o pino LED como saída
}

void loop() {
  // Apaga todos o LED
  digitalWrite(ledPin1, LOW);
  
  
  // Envie um pulso ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Leia a duração do eco
  long duration = pulseIn(echoPin, HIGH);
  
  // Calcule a distância em centímetros
  float distance = duration * 0.034 / 2;
  
  // Imprima a distância no Serial Monitor
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Leia o estado do sensor PIR
  int pirEstado = digitalRead(pinoPIR);

  if (pirEstado == HIGH) {
    Serial.println("Movimento detectado");
    // Acende os LEDs
    digitalWrite(ledPin1, HIGH);
    
  } else {
    Serial.println("Nenhum movimento detectado");
    //Apaga os LEDs
    digitalWrite(ledPin1, LOW);
    
  }
  
  delay(400); // Aguarde 400ms antes de fazer a próxima leitura
}