# Diseño del software

1. Análisis de imágenes
    -  [Procesamiento de imágenes](https://github.com/RoboticaLLR/redmachine2024/blob/main/src/software.md#Procesamiento-de-imágenes)
    -  [Detección de color](https://github.com/RoboticaLLR/redmachine2024/blob/main/src/software.md#Detección-de-color)
    - [Programaciób](https://github.com/RoboticaLLR/redmachine2024/blob/main/src/software.md#Programación)

# Procesamiento de imágenes
Para procesar la imagen, Luka utiliza una cámara. Esta es la pixy2. 

![pixy2.1](https://github.com/user-attachments/assets/46298b4d-2184-4b40-9b81-577219ed9214)

La pixy2 trabaja a 60 fps, y es capaz de detectar objetos, líneas y colores. En luka el objetivo principal de la camara es detectar colores (rojo y verde). 
Se conecta al arduino con un cable IDC 2 ICSP Arduino que va en los pines ICSP del arduino, que proporciona todas las conexiones necesarias para alimentar y comunicarse con el pixy. 

## Detección de color
Pixy2 utiliza un algoritmo de filtrado basado en el color para detectar objetos llamado el algoritmo Color Connected Components (CCC). Pixy2 calcula el color (tono) y la saturación de cada píxel RGB del sensor de imagen y los utiliza como parámetros principales de filtrado. El tono de un objeto permanece prácticamente inalterado con los cambios de iluminación y exposición. El algoritmo CCC de Pixy2 recuerda hasta 7 firmas de color diferentes.

Después de guardar un color en una firma de color, el pixy lo añadirá a una tabla de objetos que está rastreando actualmente y le asignará un índice de rastreo. A continuación, intentará encontrar el objeto (y todos los objetos de la tabla) en el siguiente fotograma buscando su mejor coincidencia. Cada objeto rastreado recibe un índice entre 0 y 255 que mantendrá hasta que abandone el campo de visión de Pixy2. 

![seguimiento_color](https://github.com/user-attachments/assets/46d2f0c5-c726-4a08-a899-b9a19b0e1dee)


## Programación 
Para establecer los colores que debe detectar la cámara, el equipo utiliza pixymon. PixyMon es una aplicación que funciona en Windows, MacOs y Linux. Te permite ver lo que Pixy2 ve, ya sea como vídeo en bruto o procesado. También te permite configurar tu Pixy2, establecer el puerto de salida y gestionar las firmas de color. PixyMon se comunica con Pixy2 a través de un cable mini USB estándar.

![Screenshot 2024-11-11 103435](https://github.com/user-attachments/assets/f58a573e-7a54-49de-9017-4953aa863677)

En pixymon el equipo establece 6 firmas, tres para el verde y tres para el rojo. Las firmas 1, 3 y 5 para el rojo, y las firmas 2, 4 y 6 para el verde. 

Después de esto el arduino proccesing necesitaba ser hecho. 

En el arduino, el equipo utiliza la librería pixy2, que permite obtener toda la información necesaria de la detección de pixeles. Entonces, usando el siguiente código, el equipo guarda cuando el pixy detecta un color y a qué firmas corresponde el color en una variable llamada «hola». Si hola es divisible por dos, entonces el color es verde, y si hola no es divisible por dos, entonces el color es rojo. 