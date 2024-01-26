// pruebaOMP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

//definicion de variables
#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);


int main()
{
    std::cout << "Verificando la ejecución de las directivas OMP!\n";

# ifdef _OPENMP
    std::cout << "OMP disponible y funcionando" << std::endl;
#endif

//inicia el programa de paralelos

    std::cout << "Sumando arreglos en paralelo!\n";

    //creación de variables para los arreglos con N como constante que definimos
    float a[N], b[N], c[N];
    int i;

    //asignamos valores como el elejericico
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }

    //asignar valores aleatorios
     // Inicializar la semilla del generador de números aleatorios con la hora actual
    srand(time(NULL));
    // Asignar valores aleatorios a los arreglos
    //for (i = 0; i < N; i++) {
      //  a[i] = rand() % 1000; // Rango de valores de 0 a 999
        //b[i] = static_cast<float>(rand()) / RAND_MAX * 100.0; // Rango de valores de 0.0 a 100.0
    //}

    int pedazos = chunk;

    //programar con OpenMP para trabajo paralelo
    #pragma omp parallel for \
    shared (a, b, c, pedazos) private (i) \
    schedule (static, pedazos)
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    //imprimir areglo mandando llamar la función imprimirArreglo
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);


        
}

//creamos la función de imprimir

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
