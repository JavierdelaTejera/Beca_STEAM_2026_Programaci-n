# 🚗 Proyecto: Demostración de Carrito Robot con Sensor Ultrasónico

Este repositorio contiene el código base para probar la funcionalidad de un carrito robot evasor de obstáculos. El programa utiliza un sensor ultrasónico HC-SR04 para medir distancias y ejecuta una coreografía de prueba con los motores cuando detecta un objeto cercano.

## 📋 Descripción

El objetivo de este código es validar que tanto el sensor ultrasónico como los motores del carrito estén conectados y funcionando correctamente. 

El carrito permanecerá estático hasta que un objeto (como tu mano) se acerque a menos de **20 cm** del sensor. Al detectar el objeto, el carrito ejecutará la siguiente secuencia:
1. Avanzar (1 segundo)
2. Girar a la derecha (0.5 segundos)
3. Girar a la izquierda (0.5 segundos)
4. Retroceder (1 segundo)
5. Detenerse y esperar 2 segundos antes de la siguiente lectura.

## 🛠️ Requisitos de Hardware

Para que este código funcione, asegúrate de tener las siguientes conexiones:
* **Sensor Ultrasónico HC-SR04:**
  * Pin `Trig` conectado al pin digital **3** del Arduino.
  * Pin `Echo` conectado al pin digital **4** del Arduino.
* **Controlador de Motores:** Conectado según lo defina la librería interna del carrito.

## 📂 Estructura del Repositorio

Es estrictamente necesario que los siguientes dos archivos se encuentren en la **misma carpeta** para que el programa pueda compilar:

* `Carrito_orienta_objetos.ino`: El código principal que se sube a la placa Arduino.
* `Carrito.h`: La librería que contiene las funciones de movimiento de los motores (`adelante()`, `atras()`, `parar()`, etc.).

## 🚀 Instrucciones de Uso

Sigue estos pasos para cargar el código en tu carrito:

1. **Descarga el repositorio:** Haz clic en el botón verde `<> Code` y selecciona *Download ZIP*, o clona el repositorio en tu computadora.
2. **Extrae los archivos:** Asegúrate de que tanto el archivo `.ino` como el `.h` estén en una carpeta llamada `Carrito_orienta_objetos`.
3. **Abre Arduino IDE:** Haz doble clic en el archivo `.ino`.
4. **Verifica tu placa y puerto:** En el menú `Herramientas`, asegúrate de tener seleccionada la placa correcta (ej. Arduino Uno) y el puerto COM correspondiente.
5. **Sube el código:** Haz clic en el botón de la flecha hacia la derecha (Subir).
6. **Abre el Monitor Serie:** Haz clic en el ícono de la lupa en la esquina superior derecha y configura los baudios a **9600**. Aquí podrás leer las distancias que mide el sensor y el estado de la prueba.

## 📝 Notas Adicionales

* Si al pasar la mano el carrito no se mueve pero el Monitor Serie indica "Moviendo: Adelante", revisa la conexión de tus baterías y del puente H o controlador de motores.
* Puedes modificar la variable `float umbral = 20.0;` en el código principal si deseas que reaccione a una distancia diferente.
