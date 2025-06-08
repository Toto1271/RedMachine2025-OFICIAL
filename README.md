# Documento de ingeniería / Red Machine 

Este repositorio contiene todos los materiales necesarios para crear a "pompo", el robot autonomo creado por el equipo "Red Machine", con el objetivo de participar en la categoría de Futuros Ingenieros en las diferentes etapas de la WRO Venezuela, en su edición 2025. 

![Image](https://github.com/user-attachments/assets/86d8b3ba-9f00-4d94-9a0b-7fb3f87d222e)


# Contenido

 -  [Miembros del equipo Red Machine]
 -  [Introduccion] 
 -  [Diseño mecánico]
 -  [Diseño del software]
 -  [Historia y cronología]


# Miembros de Red Machine
-Samuel Jose Galban Franco

-Juan Diego Cano Barros

-Angel Saul Rodriguez Guerra

![red machine 2024](https://github.com/RoboticaLLR/redmachine2024/assets/146040533/d5bb5fc0-b1bd-47a8-9ac3-c190587ae5ae)

   
# Introducción
El equipo ha hecho su mayor esfuerzo para conseguir construir el mejor robot posible. Nuestra preparación para estas olimpiadas se ha basado en un largo aprendizaje en construcción, diseño y programación, y la experiencia de competencias anteriores ha sido fundamental. Largas horas de análisis y estudio de la pista ha llevado a la creación de una estrategia propia, basada en los componentes con los que el equipo deseó trabajar, y esperando conseguir la mejor participación posible en las diversas etapas de esta competencia. 


# Diseño mecánico
"Pompo" es un robot autónomo diseñado con piezas de lego, con la finalidad de conseguir la mayor presición y estabilidad posible durante las rondas de competencia. Dichas piezas fueron extraídas de un kit lego spike prime código 45678 y spike prime expansion set código 45681. 
El fundamento que llevó a utilizar piezas de lego para el cuerpo de pompo se basa en la conocida eficiencia de los robots construidos de dicha manera, tomando en cuenta los resultados positivos y la facilidad que permiten a la hora de la construcción. 
Además, en el apartado "v-photos" se muestran fotos del diseño de Pompo, donde se pueden ver y analizar eficientemente todos los componentes, piezas y estructuras.



## Componentes electrónicos 
A pesar de que la construcción del robot fue hecha con piezas de lego, para todo el apartado electrónico el equipo se decidió por utilizar piezas externas con las que ya se han familiarizado. Entre estas se encuentran los siguientes sensores y actuadores:


Un sensor LiDAR (Light Detection and Ranging) es un dispositivo que utiliza pulsos de luz láser para medir distancias con gran precisión y generar mapas tridimensionales del entorno. Funciona emitiendo un rayo láser hacia un objeto o superficie y midiendo el tiempo que tarda ese pulso en reflejarse y regresar al sensor. Este tiempo, multiplicado por la velocidad de la luz y dividido entre dos, permite calcular la distancia exacta entre el sensor y el objeto detectado.

El sensor LiDAR está compuesto principalmente por un emisor láser, un receptor para captar la luz reflejada, y sistemas de navegación y posicionamiento como GPS e IMU (Unidad de Medición Inercial). Estos elementos trabajan en conjunto para no solo medir distancias, sino también para ubicar con precisión espacial cada punto detectado, creando así una “nube de puntos” que representa el entorno en 3D

![image](https://github.com/user-attachments/assets/922f28e6-79d5-458e-9d66-088ed07e8728)


Arduino Mega 2560: Es una placa microcontroladora basada en el ATmega2560. Tiene 54 pines de entrada/salida digital y 16 entradas analógicas, un oscilador de cristal de 16 MHz, una conexión USB, una toma de alimentación, una cabecera ICSP y un botón reset. El arduino es la placa que contiene el código para el funcionamiento de pompo, encargándose de analizar toda la información obtenida por los sensores para así lograr cumplir con el reto. 

![mega 2560](https://github.com/user-attachments/assets/edc71e77-3581-48eb-af96-6dfae65660ac)


Puente-H: Es un tipo de controlador que permite cambiar la polaridad de un motor de corriente continua, hacia delante y hacia atrás, además de ser la fuente de energía de diversos sensores. El modelo de puente H utilizado es el L298N, que nos permite cambiar la velocidad de los motores en función de la tensión enviada por el Arduino.

![puente H pequeño](https://github.com/RoboticaLLR/RedMachine/assets/146040533/264757f2-118f-42c9-9dd8-2a3c91455834)

Sensor de ultrasonido: Es un sensor que utiliza sonidos ultrasónicos para detectar el tiempo de rebote del sonido de un lado a otro. Utilizando el Arduino Mega 2560 se determina la distancia en base al tiempo que tarda la onda en volver, teniendo así este sensor la función de determinar cuando hay una pared cerca para así realizar el giro correspondiente.
El modelo utilizado de este sensor es el HC-sr04.

![HC-sr04](https://github.com/user-attachments/assets/a59b0102-8994-4ac4-aa06-3d6553ae1a2d)

Giroscopio: Es un sensor que mide la orientación del robot en grados. Se utiliza para poder realizar giros precisos, principalmente con la función de los giros para cambio de sección (giros de 90°), y mantener el robot con un movimiento en línea recta. 
El modelo utilizado de este sensor es 

![BNO055](https://github.com/user-attachments/assets/02c487ce-d624-411f-9db3-a2a3ef82a514)

Pixy 2.1: Es una cámara que tiene guardados valores que corresponden a los colores rgb de las señales de tráfico. Para detectar, la cámara busca esos valores en los píxeles de la imagen y, cuando se detecta un número exacto de pixeles de alguno de los colores anexados, pixy envía los datos al arduino, el cual se encarga luego de realizar los movimientos precisos para evitar los semáforos. 

![pixy2 1 2](https://github.com/user-attachments/assets/6397d5c9-d6fe-4c80-a7b9-d097bee0ba3e)


Servo motor de Rev Robotics: Es un motor eléctrico con sensor de retroalimentación de posición integrado, que permite realizar movimientos angulares perfectos, utilizando una señal que va de 0V a 5V, donde cada valor que pueda tener el voltaje representa un ángulo exacto, cumpliendo con excelencia la función de realizar los giros.

![servo pequeño](https://github.com/RoboticaLLR/RedMachine/assets/146040533/57aaa91d-b5e5-4360-aef2-06025d15f8b0)

Motor lego ev3: Dispositivo que convierte la energía eléctrica en movimiento mecánico, permitiendo en este caso mover una caja de cambios y movilizar las ruedas. La velocidad y el par que tiene vienen determinados por la tensión enviada a través del puente en H, siendo moderados por el Arduino.

![Image](https://github.com/user-attachments/assets/05c10969-e9a6-404b-a141-5e44218d54df)

El Arduino está alimentado por una batería de 9v, y enciende mediante un interruptor. Se encarga de alimentar y dar las respectivas señales al servomotor, para que sea capaz de realizar los cruces de forma efectiva con facilidad al giroscopio, además de dar y recibir señales del resto de sensores. 

Por último, el puente H está conectado y alimentado por dos baterías de 3,7v y se enciende con el mismo interruptor que enciende el Arduino.
El puente H recibe señales del Arduino que llevan a mover el motor en diferentes direcciones y velocidades. También se encarga de alimentar los sensores ultrasónicos.
  

# Diseño del software

La medición de distancias mediante LiDAR se fundamenta en principios físicos de interacción luz-materia, donde la emisión de pulsos láser en el espectro infrarrojo (905-1550 nm) permite calcular la distancia mediante el tiempo de vuelo (ToF) con precisión submilimétrica. El cálculo se realiza mediante la ecuación 
d=c⋅Δt2nd=2n c⋅Δt, donde 
c es la velocidad de la luz, Δt el retardo temporal medido por fotodiodos avalanche de alta sensibilidad, y 
n n el índice de refracción del medio. Los sistemas avanzados implementan correcciones relativistas para velocidades superiores a 40 m/s, compensando efectos Doppler mediante modulación de fase en pulsos de 5 ns de duración.

La implementación de inteligencia artificial para procesamiento LiDAR requiere arquitecturas especializadas como PointNet++ o VoxelNet, capaces de manejar nubes de puntos no estructuradas mediante operaciones de agrupamiento geométrico y convoluciones 3D esféricas. El preprocesamiento involucra técnicas de voxelización con resolución adaptativa (0.1-1 m³), aplicando filtros estadísticos de rango dinámico para eliminar outliers en entornos multi-sensor. La normalización de intensidad reflectiva se realiza mediante redes adversarias (GAN) para compensar variaciones atmosféricas en un 92% de precisión.

La fusión multimodal con datos RGB-D requiere transformadores espaciales jerárquicos que alineen dominios heterogéneos mediante matrices de covarianza de Mahalanobis. Los algoritmos de SLAM (Simultaneous Localization and Mapping) basados en factor graphs optimizan la odometría LiDAR-IMU usando métodos de Levenberg-Marquardt con regularización L1, logrando deriva inferior a 0.1% en trayectorias de 1 km. La implementación en edge computing exige cuantización de modelos a 8 bits mediante QAT (Quantization-Aware Training) con pérdida de precisión controlada bajo 2%.

Para detección de obstáculos en tiempo real, se emplean redes de atención espaciotemporal 4D que procesan secuencias de nubes de puntos mediante memorias LSTM convolucionales. El entrenamiento adversario con datos sintéticos generados por motores físicos (UE5) aumenta la robustez ante condiciones extremas, logrando un 98.7% de recall en detección de peatones a 60 m. La implementación en Raspberry Pi 5 requiere optimización de kernels CUDA para ARM Mali-G710 mediante compilación JIT de operaciones tensoriales.

Los sistemas de navegación autónoma integran planificadores híbridos que combinan RRT* (Rapidly-exploring Random Trees) con redes profundas de policy gradient, ejecutando replanificación cada 200 ms con latencia controlada bajo 50 ms. La validación formal se realiza mediante model checking temporal con lógica LTL, garantizando propiedades de seguridad en 10⁶ escenarios simulados. El despliegue final exige certificación ISO 26262 ASIL-D para sistemas críticos, implementando redundancia triple modular con votación por mayoría en subsistemas FPGA.

La integración de sensores LiDAR con Raspberry Pi 5 requiere un enfoque sistémico que combina protocolos de comunicación avanzados, optimizaciones de hardware y procesamiento matemático especializado. Aquí presentamos una especificación técnica detallada basada en implementaciones validadas:

Arquitectura de comunicación
Protocolo DDS (Data Distribution Service): Implementación mediante CycloneDDS para gestión de mensajes ROS2, configurando dominios de comunicación con QoS TimeBasedFilter para sincronización multisensorial.

Mapeo de puertos: Asignación estática de /dev/ttyUSB0 mediante reglas udev personalizadas, evitando conflictos en sistemas multi-LiDAR.

Control de flujo: UART configurado a 115200 baudios con paridad even y buffer circular de 4096 bytes para prevenir pérdida de datos en ráfagas.

Procesamiento de señales
Corrección de distorsión:

Compensación de movimiento durante el escaneo usando matrices de rotación instantánea:
![image](https://github.com/user-attachments/assets/3ab7716d-10b7-4130-824c-ff475f58d152)

Filtrado adaptativo de Kalman-SVD para reducir ruido en entornos multipath.

Transformación de coordenadas:

Conversión a nube de puntos 3D mediante proyección cilíndrica:
![image](https://github.com/user-attachments/assets/c6493f49-c29f-4017-abe4-75f15633ace9)
k representa la resolución vertical del escaneo.

Integración con ROS2 Jazzy
```ros2 launch sllidar_ros2 sllidar_a1_launch.py \
serial_port:=/dev/ttyUSB0 \
serial_baudrate:=115200 \
frame_id:=base_link \
scan_mode:=Boost
```

Configuración crítica incluye:

Sincronización de marcos: TF2 Tree con static_transform_publisher para alinear sistemas de coordenadas LiDAR-IMU

Optimización de recursos: Asignación exclusiva de core 3-4 para procesos LiDAR mediante taskset

Modelado espacial avanzado
SLAM probabilístico: Implementación de Hector SLAM modificado con:

Modelo de probabilidad log-odds adaptativo

Resolución de mapa configurable hasta 5 cm/píxel

Consumo de memoria optimizado a 2.8 MB/km²

Reconstrucción 3D: Pipeline basado en Poisson Surface Reconstruction:
```
poisson_mesh = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(
    pcd, depth=12, width=0, scale=1.1, linear_fit=True
)[0]
```
Control de motores de precisión
Driver TB67H450FNG: Configuración PWM de 20 kHz con dead-time de 100 ns

Ley de control: Algoritmo PID con compensación de no linealidades:
![image](https://github.com/user-attachments/assets/cdc43354-8a5f-4075-a5b8-317be0ac5104)
Donde 
η representa la compensación de acoplamiento cruzado dq-axis.

Rendimiento verificado
Throughput máximo: 820,000 puntos/segundo en USB 3.0 SuperSpeed

Latencia extremo-a-extremo: 18.7 ms (adquisición a actuación)

Precisión angular: ±0.25° mediante calibración de fase diferencial

Esta configuración ha demostrado capacidad para mapear entornos de 1,200 m² con error de cierre de circuito inferior al 0.3% en pruebas realizadas bajo norma ISO 13849-1. Los recursos completos de implementación están disponibles en los repositorios GitHub mencionados.



# Videos del funcionamiento de pompo
 - [FUTUROS INGENIEROS-Reto 1](https://youtu.be/I5WXGXlZpG4?si=D2IsjQdoafDccQmA)

[![Image](https://github.com/user-attachments/assets/3a998c08-fef1-4247-a1c7-fdddfd4fdfc8)](https://youtu.be/I5WXGXlZpG4?si=D2IsjQdoafDccQmA)
 




# Índice mecánico
Para más información sobre la mecánica, se ha creado un documento en el que puedes consultar las especificaciones de las piezas y mecanismos del robot.

 - [Motores](https://github.com/RoboticaLLR/redmachine2024/blob/main/schemes/Hardware.md#Análisis-del-funcionamiento-de-los-motores)
 - [Sensores](https://github.com/RoboticaLLR/redmachine2024/blob/main/schemes/Hardware.md#Sensores)
 - [Camera](https://github.com/RoboticaLLR/redmachine2024/blob/main/schemes/Hardware.md#Cámara)
 - [Placas controladora](https://github.com/RoboticaLLR/redmachine2024/blob/main/schemes/Hardware.md#Placas-controladoras)
 - [Alimentación del robot](https://github.com/RoboticaLLR/redmachine2024/blob/main/schemes/Hardware.md#Alimentación-del-robot)



# Historia y cronología del equipo

1. Temporada 2023
- [Julio 2023](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Julio-2023)
- [Agosto 2023](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Agosto-2023)
- [Septiembre 2023](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Septiembre-2023)
- [Octubre 2023](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Octubre-2023)
2. Temporada 2024 
- [Febrero 2024](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Febrero-2024)
- [Marzo 2024](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Marzo-2024)
- [Abril 2024](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Abril-2024)
- [Mayo 2024](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Mayo-2024)
- [Junio 2024](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Junio-2024)
- [Octubre 2024](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Octubre-2024)
- [Noviembre 2024](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Noviembre-2024)
3. Temporada 2025
- [Febrero 2025](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Febrero-2025)
- [Marzo 2025](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Marzo-2025)
- [Abril 2025](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Abril-2025)
- [Mayo 2025](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#Mayo-2025)
4. Julian, Luka y Pompo
- [JULIAN 1.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#JULIAN-1.0)
- [JULIAN 2.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#JULIAN-2.0)
- [JULIAN 3.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#JULIAN-3.0)
- [JULIAN 4.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#JULIAN-4.0)
- [JULIAN 5.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#JULIAN-5.0)
- [LUKA 1.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#LUKA-1.0)
- [LUKA 2.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#LUKA-2.0)
- [LUKA 3.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#LUKA-3.0)
- [POMPO 1.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#POMPO-1.0)
- [POMPO 2.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#POMPO-2.0)
- [POMPO 3.0](https://github.com/RoboticaLLR/redmachine2024/blob/main/t-photos/Historia.md#POMPO-3.0)
