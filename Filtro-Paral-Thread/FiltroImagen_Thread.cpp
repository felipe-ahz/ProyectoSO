#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;
using namespace chrono;

// Función para procesar una sección de la imagen en paralelo
void processSection(Mat& image, int startRow, int endRow) {
    for (int r = startRow; r < endRow; r++) {
        for (int c = 0; c < image.cols; c++) {
            Point3_<uchar>* p = image.ptr<Point3_<uchar>>(r, c);
            uchar grayValue = static_cast<uchar>(0.299 * p->z + 0.587 * p->y + 0.114 * p->x);
            p->x = p->y = p->z = grayValue;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <imagen_entrada> <imagen_salida> <numero_hebras>" << endl;
        return -1;
    }

    string inputImageName = argv[1];
    string outputImageName = argv[2];
    int numThreads = atoi(argv[3]);

    auto start = high_resolution_clock::now();
    cout << "Cargando Imagen..." << endl;

    Mat image = imread(inputImageName, IMREAD_COLOR);

    if (image.empty()) {
        cout << "Error al cargar la imagen." << endl;
        return -1;
    } else {
        cout << "Imagen Cargada" << endl;
    }

    cout << "Filas: " << image.rows << "        Columnas: " << image.cols << endl;
    cout << "Comenzando Conversion..." << endl;

    // Vector para almacenar los threads
    vector<thread> threadList;

    // Calcular la cantidad de filas por thread
    int rowsPerThread = image.rows / numThreads;

    // Iniciar los threads
    for (int i = 0; i < numThreads; i++) {
        int startRow = i * rowsPerThread;
        int endRow = (i == numThreads - 1) ? image.rows : (i + 1) * rowsPerThread;

        threadList.emplace_back(processSection, ref(image), startRow, endRow);
    }

    for (auto& t : threadList) {
        t.join();
    }

    // Medir el tiempo de finalización
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Finalizando..." << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    imwrite(outputImageName, image);
    return 0;
}
