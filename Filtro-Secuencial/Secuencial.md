## Primer programa: Filtro de Imagen en Versión Secuencial Funcional.
Este primer programa implementa un filtro de escala de grises en una imagen utilizando el método de luminosidad. 

### Instrucciones de ejecución:
1. Compilar el código utilizando el siguiente comando en la terminal: make

2. Ejecutar el programa ya compilado: 
./FiltroImagen_Secuencial ../Zampedri.png ZampedriGris.png

- "../Zampedri.png" es para indicar que la imagen que le aplicaremos el filtro está un directorio atrás, y el "ZampedriGris.png" es el nombre que le damos para exportar la imagen final, ese fue solo un nombre de ejemplo, usted puede dejar el nombre que más le acomode. 

Tras la ejecución de estos comandos, la imagen se cargará, revelando información sobre sus dimensiones en términos de filas y columnas. Posteriormente, se llevará a cabo la conversión aplicando el filtro de escala de grises. Finalmente, se exhibirá el tiempo de ejecución, representado en milisegundos (por ej; 14ms).
La imagen con el filtro aplicado se guardará como se haya indicado al final del paso n°2.

