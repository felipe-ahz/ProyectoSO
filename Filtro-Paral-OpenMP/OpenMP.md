## Tercer Programa: Filtro de Imagen en Versión Paralela con OpenMP.
Este tercer programa muestra una versión paralela del filtro de escala de grises utilizando la API OpenMP en C++. El método de luminosidad se aplica a una imagen de entrada cargada desde el archivo "Zampedri.png". La imagen filtrada se guarda como "Zampedri_Paralel_OpenMP.jpg" después de aplicar el filtro de manera paralela mediante OpenMP.

### Instrucciones de ejecución
1. Compilar el código utilizando el siguiente comando en la terminal:
g++ -o FiltroImagen_Paralel_OpenMP FiltroImagen_Paralel_OpenMP.cpp $(pkg-config --cflags --libs opencv4) -fopenmp

2. Ejecutar el programa ya compilado: 
./FiltroImagen_Paralel_OpenMP

Después de ejecutar estos comandos, se mostrará el tiempo de ejecución en milisegundos.
La imagen filtrada se guardará como "Zampedri_Paralel_OpenMP.jpg".

### Consideraciones
- La opción -fopenmp es necesaria durante la compilación para habilitar el soporte de OpenMP.

