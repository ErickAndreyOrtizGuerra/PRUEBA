#include <iostream>
#include <filesystem> /*esta linea biblioteca trabaja con archivos y directorios*/
#include <windows.h> /*interractuar con el sistema operativo*/

using namespace std;
namespace fs = std::filesystem;

int main() {
    /*obtener la ruta de la carpeta del usuario*/
    string folderPath; /* se declara una variable "folderPath" se utiliza para almacenar la ruta de la carpeta que se va a examinar.*/
    cout << "Ingrese la ruta de la carpeta: ";
    getline(cin, folderPath);

    try { /*este es el inicio de un bloque "try", que se utiliza excepciones que puedan ocurrir en el codigo.*/

        for (const auto& file : fs::directory_iterator(folderPath)) { /*este es un bucle "for" que utiliza la función "directory_iterator()" de la biblioteca "filesystem" para repetir sobre todos los archivos "folderPath" la variable "file" se utiliza para almacenar el objeto que representa directorio actual.*/
            /* muestra el nombre de los archivos*/
            cout << file.path().filename() << endl;
        }
    }
    catch (const fs::filesystem_error& ex) { /*este es un bloque "catch" que se ejecuta si ocurre una excepción en el bloque "try" en este caso, estamos capturando una excepcion de tipo "filesystem_error" de la biblioteca "filesystem".*/
        cout << "Error:  El directorio agregado es incorrecto"; //<< ex.what() << endl;
        return EXIT_FAILURE; /*esta linea indica que el programa ha fallado y devuelve un código de salida de error al sistema operativo*/
    }

    return EXIT_SUCCESS; /*esta linea indica que el programa ha finalizado correctamente y devuelve un codigo de salida de exito al sistema operativo*/
}
