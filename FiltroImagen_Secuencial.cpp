#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    // Medir el tiempo de inicio
    auto start = high_resolution_clock::now();

    Mat image = imread("Zampedri.png", IMREAD_COLOR);

    if (image.empty()) {
        cout << "Error al cargar la imagen." << endl;
        return -1;
    }

    // Leer imagen y aplicar filtro
    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Point3_<uchar>* p = image.ptr<Point3_<uchar>>(r, c);
            // Luminosity method: L = 0.299*R + 0.587*G + 0.114*B
            uchar grayValue = static_cast<uchar>(0.299 * p->z + 0.587 * p->y + 0.114 * p->x);
            p->x = p->y = p->z = grayValue;
        }
    }

    // Medir el tiempo de finalización
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    // Mostrar el tiempo de ejecución en milisegundos
    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    // Guardar la imagen en escala de grises (puedes ajustar el nombre del archivo)
    imwrite("grayscale_sequential.jpg", image);

    return 0;
}
