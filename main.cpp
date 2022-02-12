#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Profesor
{
  int id_profesor;
  char cui[14];
  char nombre[25];
  char curso[25];
};

void writeTeacher()
{
  // STRUCT QUE VAMOS A GUARDAR
  Profesor data;

  // DATOS DE PRUEBA
  string cui = "2995454660101";
  string nombre = "Brayan Prado";
  string curso = "MIA";

  // PARA ESCRIBIR STRINGS SE USA strcpy
  data.id_profesor = 232;
  strcpy(data.cui, cui.c_str());
  strcpy(data.nombre, nombre.c_str());
  strcpy(data.curso, curso.c_str());

  // AQUÍ ABRIMOS COMO LECTURA Y ESCRITURA (rb+) EL ARCHIVO BINARIO
  string path = "./binario.bin";
  FILE *disk_file = fopen(path.c_str(), "rb+");

  // FSEEK NOS POSICIONA DENTRO  DEL ARCHIVO
  fseek(disk_file, 0, SEEK_SET); // EL SEGUNDO PARAMETROS ES LA POSICIÓN (0 EN ESTE CASO)

  // CON FWRITE GUARDAMOS EL STRUCT LUEGO DE POSICIONARNOS
  fwrite(&data, sizeof(Profesor), 1, disk_file); // EL TERCER PAREMETRO ES LA CANTIDAD DE STRUCTS A GUARDAR (EN ESTE CASO SOLO 1)

  // CERRAR STREAM (importante)
  fclose(disk_file);
}

void readTeacher()
{
  // STRUCT QUE VAMOS A LEER
  Profesor data;

  // AQUÍ ABRIMOS COMO LECTURA Y ESCRITURA (r+) EL ARCHIVO BINARIO
  string path = "./binario.bin";
  FILE *disk_file = fopen(path.c_str(), "r+");

  // FSEEK NOS POSICIONA DENTRO  DEL ARCHIVO
  fseek(disk_file, 0, SEEK_SET); // EL SEGUNDO PARAMETROS ES LA POSICIÓN (0 EN ESTE CASO)

  // CON FWRITE GUARDAMOS EL STRUCT LUEGO DE POSICIONARNOS
  fread(&data, sizeof(Profesor), 1, disk_file); // EL TERCER PAREMETRO ES LA CANTIDAD DE STRUCTS A GUARDAR (EN ESTE CASO SOLO 1)

  // CERRAR STREAM (importante)
  fclose(disk_file);

  // AQUÍ MOSTRAMOS EL STRUCT
  cout << data.id_profesor << endl
       << data.cui << endl
       << data.nombre << endl
       << data.curso;
}

int main(int argc, char *argv[])
{
    cout<<"Brayan Hamllelo Estevem Prado Marroquin"<<endl;
    cout<<"Carnet: 201801369"<<endl;

    writeTeacher();
    readTeacher();
}
