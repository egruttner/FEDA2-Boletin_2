#include <chrono>
#include "busquedas.h"
#include <fstream>

using namespace std;

int main(int argv, char* argc[]) {
  srand(time(NULL)); 

  long n;
  string dir_csv;
  string busqueda_seleccionada;
  int id_busqueda_seleccionada;
  string nombre_archivo_salida;
  int valor_buscado;
  int porcentaje;

  cout<<"INICIO"<<endl;

  //TIPOS DE PRUEBAS
  switch(atoi(argc[1]))
  {

    case 1: busqueda_seleccionada = "secuencial-dif_tam-pos0"; break;
    case 2: busqueda_seleccionada = "binaria-dif_tam-pos0"; break;
    case 3: busqueda_seleccionada = "galopante-dif_tam-pos0"; break;

    case 4: busqueda_seleccionada = "secuencial-dif_tam-pos25"; break;
    case 5: busqueda_seleccionada = "binaria-dif_tam-pos25"; break;
    case 6: busqueda_seleccionada = "galopante-dif_tam-pos25"; break;

    case 7: busqueda_seleccionada = "secuencial-dif_tam-pos50"; break;
    case 8: busqueda_seleccionada = "binaria-dif_tam-pos50"; break;
    case 9: busqueda_seleccionada = "galopante-dif_tam-pos50"; break;

    case 10: busqueda_seleccionada = "secuencial-dif_tam-pos75"; break;
    case 11: busqueda_seleccionada = "binaria-dif_tam-pos75"; break;
    case 12: busqueda_seleccionada = "galopante-dif_tam-pos75"; break;

    case 13: busqueda_seleccionada = "secuencial-dif_tam-pos100"; break;
    case 14: busqueda_seleccionada = "binaria-dif_tam-pos100"; break;
    case 15: busqueda_seleccionada = "galopante-dif_tam-pos100"; break;

    case 16: busqueda_seleccionada = "secuencial-dif_pos-tam100000"; break;
    case 17: busqueda_seleccionada = "binaria-dif_pos-tam100000"; break;
    case 18: busqueda_seleccionada = "galopante-dif_pos-tam100000"; break;

    default: busqueda_seleccionada = ""; break;
  }

  //DEFINE DIRECTORIO DE CSV
  dir_csv = "csv/";

  //SI VIENE CON PARÁMETRO "head" entonces solamente crea la cabecera del archivo CSV
  if((strcmp(argc[2],"--head") == 0))
  {
    nombre_archivo_salida = dir_csv + busqueda_seleccionada + "_results.csv";
    ofstream outfile(nombre_archivo_salida);
    outfile << "n,tiempo[ms]\n";

    return 0;
  }
  else
  {
    //LEE EL TAMAÑO DEL VECTOR
    cin>>n;

    switch(atoi(argc[1]))
    {
      case 1:
      case 2:
      case 3: valor_buscado=floor(n*10/100);break;

      case 4: 
      case 5: 
      case 6: valor_buscado=floor(n*25/100); break;

      case 7: 
      case 8: 
      case 9: valor_buscado=floor(n*50/100); break;

      case 10: 
      case 11: 
      case 12: valor_buscado=floor(n*75/100); break;

      case 13: 
      case 14: 
      case 15: valor_buscado=n; break;

      case 16: 
      case 17: 
      case 18:
          switch ( atoi(argc[3]))
          {
          case 1: valor_buscado=floor(n*10/100); porcentaje = 10; break;
          case 2: valor_buscado=floor(n*25/100); porcentaje = 25; break;
          case 3: valor_buscado=floor(n*50/100); porcentaje = 50; break;
          case 4: valor_buscado=floor(n*75/100); porcentaje = 75; break;
          case 5: valor_buscado=n; porcentaje = 100; break;

          default:
            break;
          }
          break;

      default: busqueda_seleccionada = floor(n*10/100); porcentaje = 10; break;
    }

    //BUSQUEDA SELECCIONADA COMO PARAMETRO
    id_busqueda_seleccionada = atoi(argc[1]);

    //DEFINE MATRICES DE ENTRADA
    vector<int> A(n);   //VECTOR A

    //LEE VECTOR
    for(auto &row : A)
      {
          cin>>row;
      }
    
    nombre_archivo_salida = dir_csv + busqueda_seleccionada + "_results.csv";
    ofstream outfile(nombre_archivo_salida,std::ios::app);

    double mm_total_time = 0;
    int numero_de_experimentos=30;
    for(int j = 0; j < numero_de_experimentos; j++){ 
      
      long long single_execution_time = execution_time_ms(A, valor_buscado, id_busqueda_seleccionada);
      
      mm_total_time += single_execution_time;
    }
    double mm_avg_time = mm_total_time / numero_de_experimentos;



    //PARA EL CASO DE DISTINTAS POSICIONES SE DEBE CAMBIAR EL RÓTULO DE n
    switch (atoi(argc[1]))
    {
    case 16:
    case 17:
    case 18:
      n=porcentaje;
      break;
    
    default:
      break;
    }

    outfile << n << "," << mm_avg_time <<endl;
    outfile.close(); 
    
    return 0;
  }



}
