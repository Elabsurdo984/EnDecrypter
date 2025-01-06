#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Función para encriptar el texto (incluyendo números)
string encriptar(string texto, int desplazamiento) {
    string texto_encriptado = "";

    for (char& c : texto) {
        if (isalpha(c)) {  // Solo procesamos caracteres alfabéticos
            char base = (islower(c)) ? 'a' : 'A';
            // Desplazamos el carácter y lo agregamos al texto encriptado
            c = (c - base + desplazamiento) % 26 + base;
        } else if (isdigit(c)) {  // Procesamos los dígitos
            c = (c - '0' + desplazamiento) % 10 + '0';  // Desplazamos el dígito y lo agregamos
        }
        texto_encriptado += c;
    }

    return texto_encriptado;
}

// Función para desencriptar el texto (incluyendo números)
string desencriptar(string texto, int desplazamiento) {
    return encriptar(texto, 10 - desplazamiento);  // Desencriptar es lo mismo que encriptar con desplazamiento invertido para números
}

// Función para encriptar un archivo
void encriptarArchivo(const string& nombreArchivoEntrada, const string& nombreArchivoSalida, int desplazamiento) {
    ifstream archivoEntrada(nombreArchivoEntrada);
    ofstream archivoSalida(nombreArchivoSalida);

    if (!archivoEntrada) {
        cout << "Error al abrir el archivo de entrada.\n";
        return;
    }

    if (!archivoSalida) {
        cout << "Error al abrir el archivo de salida.\n";
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) {
        archivoSalida << encriptar(linea, desplazamiento) << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    cout << "El archivo ha sido encriptado y guardado como '" << nombreArchivoSalida << "'.\n";
}

// Función para desencriptar un archivo
void desencriptarArchivo(const string& nombreArchivoEntrada, const string& nombreArchivoSalida, int desplazamiento) {
    ifstream archivoEntrada(nombreArchivoEntrada);
    ofstream archivoSalida(nombreArchivoSalida);

    if (!archivoEntrada) {
        cout << "Error al abrir el archivo de entrada.\n";
        return;
    }

    if (!archivoSalida) {
        cout << "Error al abrir el archivo de salida.\n";
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) {
        archivoSalida << desencriptar(linea, desplazamiento) << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    cout << "El archivo ha sido desencriptado y guardado como '" << nombreArchivoSalida << "'.\n";
}

// Función para manejar el menú
void mostrarMenu() {
    cout << "Seleccione una opcion:\n";
    cout << "1. Encriptar texto\n";
    cout << "2. Desencriptar texto\n";
    cout << "3. Encriptar archivo\n";
    cout << "4. Desencriptar archivo\n";
    cout << "5. Salir\n";
}

int main() {
    int opcion = 0;  // Aseguramos que 'opcion' esté inicializada
    string texto = "";  // Aseguramos que 'texto' esté inicializada
    int desplazamiento = 0;  // Aseguramos que 'desplazamiento' esté inicializada

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();  // Limpiar el buffer del teclado

        switch (opcion) {
            case 1: {
                // Encriptar texto
                cout << "Introduce el texto a encriptar: ";
                getline(cin, texto);
                cout << "Introduce el desplazamiento: ";
                cin >> desplazamiento;
                cout << "Texto encriptado: " << encriptar(texto, desplazamiento) << endl;
                break;
            }

            case 2: {
                // Desencriptar texto
                cout << "Introduce el texto a desencriptar: ";
                getline(cin, texto);
                cout << "Introduce el desplazamiento: ";
                cin >> desplazamiento;
                cout << "Texto desencriptado: " << desencriptar(texto, desplazamiento) << endl;
                break;
            }

            case 3: {
                // Encriptar archivo
                string archivoEntrada;
                cout << "Introduce el nombre del archivo a encriptar (con extensión): ";
                cin >> archivoEntrada;
                cout << "Introduce el desplazamiento: ";
                cin >> desplazamiento;
                encriptarArchivo(archivoEntrada, "archivo_encriptado.txt", desplazamiento);
                break;
            }

            case 4: {
                // Desencriptar archivo
                string archivoEntrada;
                cout << "Introduce el nombre del archivo a desencriptar (con extensión): ";
                cin >> archivoEntrada;
                cout << "Introduce el desplazamiento: ";
                cin >> desplazamiento;
                desencriptarArchivo(archivoEntrada, "archivo_desencriptado.txt", desplazamiento);
                break;
            }

            case 5:
                cout << "¡Gracias por usar el programa! Hasta luego.\n";
                break;

            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcion != 5);

    return 0;
}


