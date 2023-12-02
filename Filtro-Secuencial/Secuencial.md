## Primer programa: Filtro de Imagen en Versión Secuencial Funcional.
Este primer programa implementa un filtro de escala de grises en una imagen utilizando el método de luminosidad. La imagen de entrada se carga desde el archivo "Zampedri.png" (que está dentro del directorio) y posteriormente se guarda como "Zampedri_sequential.jpg" después de aplicar el filtro de manera secuencial.

### Instrucciones de ejecución:
1. Compilar el código utilizando el siguiente comando en la terminal: 
g++ -o FiltroImagen_Secuencial FiltroImagen_Secuencial.cpp $(pkg-config --cflags --libs opencv4)

2. Ejecutar el programa ya compilado: 
./FiltroImagen_Secuencial

Tras la ejecución de estos comandos, la imagen se cargará, revelando información sobre sus dimensiones en términos de filas y columnas. Posteriormente, se llevará a cabo la conversión aplicando el filtro de escala de grises. Finalmente, se exhibirá el tiempo de ejecución, representado en milisegundos (por ej; 14ms).
La imagen filtrada se guardará como "Zampedri_Sequential.jpg".

