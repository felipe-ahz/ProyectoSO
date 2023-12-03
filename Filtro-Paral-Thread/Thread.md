## Segundo programa: Filtro de Imagen en Versión Paralela usando la clase Thread.
Este segundo programa presenta una versión paralela del filtro de escala de grises utilizando la clase thread en C++.

### Instrucciones de ejecución
1. Compilar el código utilizando el siguiente comando en la terminal: make

2. Ejecutar el programa ya compilado: 
./FiltroImagen_Thread ../Zampedri.png ZampedriGris.png 4

- "../Zampedri.png" es para indicar que la imagen que le aplicaremos el filtro está ubicada en un directorio atrás, y el "ZampedriGris.png" es el nombre que le damos para exportar la imagen final, ese fue solo un nombre de ejemplo, usted puede dejar el nombre que más le acomode. Y por último, se debe agregar el número de hebras a utilizar, que en este caso elegimos 4. 

Tras la ejecución de estos comandos, la imagen se cargará, revelando información sobre sus dimensiones en términos de filas y columnas. Posteriormente, se llevará a cabo la conversión aplicando el filtro de escala de grises. Finalmente, se exhibirá el tiempo de ejecución, representado en milisegundos (por ej; 14ms).
La imagen con el filtro aplicado se guardará como se haya indicado antes de la cantidad de hebras en el paso n°2.
