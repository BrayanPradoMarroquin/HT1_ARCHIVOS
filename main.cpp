#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Profesor
{
  int tipo;
  int id_profesor;
  char cui[15];
  char nombre[25];
  char curso[25];
};

struct Estudiante
{
  int tipo;
  int id_estudiante;
  char cui[15];
  char nombre[25];
  char carnet[25];
};

void writeTeacher()
{
  // STRUCT QUE VAMOS A GUARDAR
  Profesor data;

  // DATOS DE PRUEBA
  string cui = "2995454660101";
  string nombre = "Brayan Prado";
  string curso = "Manejo de Archivos";

  // PARA ESCRIBIR STRINGS SE USA strcpy
  data.id_profesor = 232;
  data.tipo = 1;
  strcpy(data.cui, cui.c_str());
  strcpy(data.nombre, nombre.c_str());
  strcpy(data.curso, curso.c_str());

  // AQUÍ ABRIMOS COMO LECTURA Y ESCRITURA (rb+) EL ARCHIVO BINARIO
  string path = "./teacher.bin";
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
  string path = "./teacher.bin";
  FILE *disk_file = fopen(path.c_str(), "r+");

  // FSEEK NOS POSICIONA DENTRO  DEL ARCHIVO
  fseek(disk_file, 0, SEEK_SET); // EL SEGUNDO PARAMETROS ES LA POSICIÓN (0 EN ESTE CASO)

  // CON FWRITE GUARDAMOS EL STRUCT LUEGO DE POSICIONARNOS
  fread(&data, sizeof(Profesor), 1, disk_file); // EL TERCER PAREMETRO ES LA CANTIDAD DE STRUCTS A GUARDAR (EN ESTE CASO SOLO 1)

  // CERRAR STREAM (importante)
  fclose(disk_file);

  // AQUÍ MOSTRAMOS EL STRUCT
  cout << data.tipo << endl  
       << data.id_profesor << endl
       << data.cui << endl
       << data.nombre << endl
       << data.curso  << endl;
}

void writeStudent(){
  Estudiante data;

  //DATOS DE PRUEBA
  string cui = "2995454660102";
  string nombre = "Ramiro de Leon";
  string carnet = "201801369";

  //PARA ESCRIBIR 
  data.id_estudiante = 158;
  data.tipo = 2;
  strcpy(data.cui, cui.c_str());
  strcpy(data.nombre, nombre.c_str());
  strcpy(data.carnet, carnet.c_str());

  string path = "./student.bin";
  FILE *disk_fs = fopen(path.c_str(), "rb+");

  fseek(disk_fs, 0, SEEK_SET);
  fwrite(&data, sizeof(Estudiante), 1, disk_fs);
  fclose(disk_fs);
}

void readStudent(){
  Estudiante data;

  string path = "./student.bin";
  FILE *disk_fs = fopen(path.c_str(), "r+");

  fread(&data, sizeof(Estudiante), 1, disk_fs);
  fclose(disk_fs);

  cout << data.id_estudiante << endl
       << data.tipo          << endl
       << data.cui           << endl
       << data.nombre        << endl
       << data.carnet        << endl;
}

int main(int argc, char *argv[])
{
    cout<<"Brayan Hamllelo Estevem Prado Marroquin"<<endl;
    cout<<"Carnet: 201801369"<<endl;
    int opc;
    do
    {
      cout << "Ingrese una opcion"         << endl
           << "1. Registro de Profesor "   << endl
           << "2. Resgistro de Estudiante" << endl
           << "3. Ver Registros"           << endl;
           cin>>opc;
           if (opc == 1)
           {
            writeTeacher();
           }else if (opc == 2)
           {
            writeStudent();
           }else if(opc == 3)
           {
            readTeacher();
            cout<<" -----------------"<<endl;
            readStudent();
           }
    } while (opc!=4);
}
