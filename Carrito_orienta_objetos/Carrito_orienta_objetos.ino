#include "Carrito.h" 

// Instanciamos el objeto del carrito
Carrito R; //Cambiar nombre de su carrito, solo cambiar la letra "R" por su nombre, no modificar lo que dice Carrito

//Recuerden cambiar en todas las funciones el nombre de su carrito en lugar de "R".

// Prototipo de la función
bool probarSensor(float umbralDistancia);

// Definición de pines
const int trigPin = 3;
const int echoPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Aseguramos que los motores inicien apagados
  R.parar(); 
  
  Serial.println("Iniciando demostracion del carrito...");
  Serial.println("Acerca un objeto a menos de 20 cm para iniciar la secuencia.");
}

void loop() {
  float umbral = 20.0; 
  bool objetoDetectado = probarSensor(umbral);

  // Si detecta algo, arranca la rutina de prueba
  if (objetoDetectado == true) {
    Serial.println("Objeto detectado! Iniciando secuencia de prueba...");
    
    Serial.println("Moviendo: Adelante");
    R.adelante();
    delay(1000);
    
    Serial.println("Moviendo: Derecha");
    R.derecha();
    delay(500);
    
    Serial.println("Moviendo: Izquierda");
    R.izquierda();
    delay(500);
    
    Serial.println("Moviendo: Atras");
    R.atras();
    delay(1000); 
    
    Serial.println("Secuencia terminada. Deteniendo motores.");
    R.parar();
    
    // Pausa de 2 segundos para darte tiempo de quitar la mano
    delay(2000); 
    Serial.println("Listo para otra prueba.");
    Serial.println("------------------------------------------------");
    
  } else {
    // Si no hay nada enfrente, se mantiene quieto
    R.parar();
  }
  
  // Pequeña pausa para no saturar el sensor ultrasónico
  delay(100); 
}

// Función del sensor ultrasónico
bool probarSensor(float umbralDistancia) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duracion = pulseIn(echoPin, HIGH);
  
  float distancia = duracion * 0.0343 / 2.0; 
  
  if (distancia > 0.0 && distancia <= umbralDistancia) {
    return true;
  } else {
    return false;
  }
}