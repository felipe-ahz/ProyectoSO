#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <imagen_entrada> <imagen_salida>" << endl;
        return -1;
    }

    string inputImageName = argv[1];
    string outputImageName = argv[2];

    auto start = high_resolution_clock::now();
    cout << "Cargando Imagen..." << endl;

    Mat image = imread(inputImageName, IMREAD_COLOR);

    if (image.empty()) {
        cout << "Error al cargar la imagen desde " << inputImageName << endl;
        return -1;
    }else{
        cout << "Imagen Cargada" << endl;
    }

    cout << "Filas: " << image.rows << "	Columnas: " << image.cols << endl;
    cout << "Comenzando conversion..." << endl;

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
    cout << "Finalizando..." << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    // Guardar la imagen en escala de grises con el nombre proporcionado por el usuario
    imwrite(outputImageName, image);

    return 0;
}
