#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h>

using namespace cv;
using namespace std;
using namespace chrono;

void processSectionOpenMP(Mat& image, int startRow, int endRow) {
#pragma omp parallel for
    for (int r = startRow; r < endRow; r++) {
        for (int c = 0; c < image.cols; c++) {
            Point3_<uchar>* p = image.ptr<Point3_<uchar>>(r, c);
            uchar grayValue = static_cast<uchar>(0.299 * p->z + 0.587 * p->y + 0.114 * p->x);
            p->x = p->y = p->z = grayValue;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <imagen_entrada> <numero_hebras>" << endl;
        return -1;
    }

    string inputImageName = argv[1];

    auto startLoading = high_resolution_clock::now();
    cout << "Cargando Imagen..." << endl;

    Mat image = imread(inputImageName, IMREAD_COLOR);

    if (image.empty()) {
        cout << "Error al cargar la imagen." << endl;
        return -1;
    } else {
        cout << "Imagen Cargada" << endl;
    }

    auto stopLoading = high_resolution_clock::now();
    auto loadingDuration = duration_cast<milliseconds>(stopLoading - startLoading);
    cout << "Tiempo de carga de imagen: " << loadingDuration.count() << " ms" << endl;

    cout << "Filas: " << image.rows << "        Columnas: " << image.cols << endl;
    cout << "Comenzando Conversion..." << endl;

    auto start = high_resolution_clock::now();

    processSectionOpenMP(image, 0, image.rows);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Finalizando Conversion..." << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    imwrite("Zampedri_Paralel_OpenMP.jpg", image);

    return 0;
}
