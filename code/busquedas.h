#include <iostream>
#include <vector>

using namespace std;

//BUSQUEDA SECUENCIAL
void secuencial(const vector<int> &A, int valor_buscado) 
{
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == valor_buscado) 
        {
            cout<<"ENCONTRADO:" + to_string(valor_buscado) <<endl;//ENCONTRADO
            break;
        }
    }

}

void binaria(const vector<int> &A, int valor_buscado)
{
    int izquierda = 0;
    int derecha = A.size() - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (A[medio] == valor_buscado) {
            cout<<"ENCONTRADO:" + to_string(valor_buscado) <<endl;//ENCONTRADO
            break;
        } else if (A[medio] < valor_buscado) {
            izquierda = medio + 1;  // El elemento está en la mitad derecha
        } else {
            derecha = medio - 1;  // El elemento está en la mitad izquierda
        }

    }
}


void galopante(const vector<int> &A, int valor_buscado)
{
    int tamano = A.size();
    int paso = sqrt(tamano);
    int previo = 0;

    // Realiza saltos hasta encontrar un intervalo que contenga el objetivo
    while (A[min(paso, tamano) - 1] < valor_buscado) {
        previo = paso;
        paso += sqrt(tamano);
        if (previo >= tamano) {
            cout<<"VALOR NO ENCONTRADO:" + to_string(valor_buscado) <<endl;
        }

    }

    // Realiza una búsqueda secuencial en el intervalo actual
    for (int i = previo; i < min(paso, tamano); ++i) {
        if (A[i] == valor_buscado) {
            cout<<"ENCONTRADO:" + to_string(valor_buscado) <<endl;
        }
    }

}



//PARA TOMAR EL TIEMPO
long long execution_time_ms(const vector<int> &A, int valor_buscado, int id_busqueda_seleccionada) {
  auto start_time = std::chrono::high_resolution_clock::now();
  
    switch (id_busqueda_seleccionada)
    {
    case 1:
    case 4:
    case 7:
    case 10:
    case 13:
    case 16:
        secuencial(A,valor_buscado);
        break;
    case 2:
    case 5:
    case 8:
    case 11:
    case 14:
    case 17:
        binaria(A,valor_buscado);
        break;
    case 3:
    case 6:
    case 9:
    case 12:
    case 15:  
    case 18:         
        galopante(A,valor_buscado);
        break;

    default:
        break;
    }

  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

