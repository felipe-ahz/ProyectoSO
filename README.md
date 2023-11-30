# ProyectoSO
Tarea 2 de la asignatura de Sistemas Operativos (2023-2).

## Requisitos 
- Sistema operativo: Linux
- Compilador: g++
- Biblioteca: OpenCV

## Primer programa; Filtro de Imagen Secuencial
Este primer programa implementa un filtro de escala de grises en una imagen utilizando el método de luminosidad. La imagen de entrada se carga desde el archivo "Zampedri.png" (que está dentro del directorio) y posteriormente se guarda como "grayscale_sequential.jpg" después de aplicar el filtro de manera secuencial.

¿Cómo lo ejecutamos?, con los siguientes dos comandos:

1. g++ -o FiltroImagen_Secuencial FiltroImagen_Secuencial.cpp $(pkg-config --cflags --libs opencv4)

2. ./FiltroImagen_Secuencial

y luego de esos dos comandos mencionados, se nos entregaría el tiempo de ejecución (por ej; 14ms) 

## Segundo programa; Filtro de Imagen Paralelo