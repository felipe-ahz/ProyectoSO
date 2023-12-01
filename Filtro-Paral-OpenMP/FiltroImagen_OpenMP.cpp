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

int main() {
    auto start = high_resolution_clock::now();

    Mat image = imread("Zampedri.png", IMREAD_COLOR);

    if (image.empty()) {
        cout << "Error al cargar la imagen." << endl;
        return -1;
    }

    const int numThreads = 4;

    // Calcular la cantidad de filas por thread
    int rowsPerThread = image.rows / numThreads;

    processSectionOpenMP(image, 0, image.rows);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    imwrite("Zampedri_Paralel_OpenMP.jpg", image);

    return 0;
}
