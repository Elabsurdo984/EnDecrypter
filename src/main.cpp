#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

// Función para encriptar o desencriptar un carácter con desplazamiento
char desplazarCaracter(char c, int desplazamiento, char base, int rango) {
    return (c - base + desplazamiento) % rango + base;
}

// Función para encriptar el texto con cifrado César
string encriptarCesar(string texto, int desplazamiento) {
    string texto_encriptado = "";
    desplazamiento %= 26;  // Garantizar que el desplazamiento sea entre 0 y 25
    if (desplazamiento == 0) {
        cout << "Desplazamiento no válido. El valor no debe ser 0 o múltiplo de 26.\n";
        return ""; // Retornar una cadena vacía si el desplazamiento es inválido
    }

    for (char& c : texto) {
        if (isalpha(c)) {
            char base = (islower(c)) ? 'a' : 'A';
            c = desplazarCaracter(c, desplazamiento, base, 26);
        } else if (isdigit(c)) {
            c = desplazarCaracter(c, desplazamiento, '0', 10);
        }
        texto_encriptado += c;
    }
    return texto_encriptado;
}

// Función para desencriptar el texto con cifrado César
string desencriptarCesar(string texto, int desplazamiento) {
    return encriptarCesar(texto, 26 - desplazamiento);  // Desencriptar es lo mismo que encriptar con desplazamiento invertido
}

// Función para convertir el texto a binario
string convertirABinario(string texto) {
    string texto_binario = "";
    for (char& c : texto) {
        texto_binario += bitset<8>(c).to_string();  // Convertir cada carácter a su binario de 8 bits
    }
    return texto_binario;
}

// Función para convertir el texto binario de vuelta a caracteres
string convertirDeBinario(string texto_binario) {
    string texto_convertido = "";

    for (size_t i = 0; i < texto_binario.length(); i += 8) {
        string byte_str = texto_binario.substr(i, 8);
        char c = static_cast<char>(bitset<8>(byte_str).to_ulong());
        texto_convertido += c;
    }

    return texto_convertido;
}

// Función para abrir archivos con control de errores
ifstream abrirArchivoEntrada(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo de entrada: " << nombreArchivo << endl;
    }
    return archivo;
}

ofstream abrirArchivoSalida(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo de salida: " << nombreArchivo << endl;
    }
    return archivo;
}

// Función para encriptar un archivo con cifrado César
void encriptarArchivoCesar(const string& nombreArchivoEntrada, const string& nombreArchivoSalida, int desplazamiento) {
    ifstream archivoEntrada = abrirArchivoEntrada(nombreArchivoEntrada);
    ofstream archivoSalida = abrirArchivoSalida(nombreArchivoSalida);

    if (!archivoEntrada || !archivoSalida) return;

    string linea;
    while (getline(archivoEntrada, linea)) {
        archivoSalida << encriptarCesar(linea, desplazamiento) << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    cout << "El archivo ha sido encriptado y guardado como '" << nombreArchivoSalida << "'.\n";
}

// Función para desencriptar un archivo con cifrado César
void desencriptarArchivoCesar(const string& nombreArchivoEntrada, const string& nombreArchivoSalida, int desplazamiento) {
    ifstream archivoEntrada = abrirArchivoEntrada(nombreArchivoEntrada);
    ofstream archivoSalida = abrirArchivoSalida(nombreArchivoSalida);

    if (!archivoEntrada || !archivoSalida) return;

    string linea;
    while (getline(archivoEntrada, linea)) {
        archivoSalida << desencriptarCesar(linea, desplazamiento) << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    cout << "El archivo ha sido desencriptado y guardado como '" << nombreArchivoSalida << "'.\n";
}

// Función para encriptar un archivo a binario
void encriptarArchivoBinario(const string& nombreArchivoEntrada, const string& nombreArchivoSalida) {
    ifstream archivoEntrada = abrirArchivoEntrada(nombreArchivoEntrada);
    ofstream archivoSalida = abrirArchivoSalida(nombreArchivoSalida);

    if (!archivoEntrada || !archivoSalida) return;

    string linea;
    while (getline(archivoEntrada, linea)) {
        archivoSalida << convertirABinario(linea) << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    cout << "El archivo ha sido convertido a binario y guardado como '" << nombreArchivoSalida << "'.\n";
}

// Función para desencriptar un archivo de binario
void desencriptarArchivoBinario(const string& nombreArchivoEntrada, const string& nombreArchivoSalida) {
    ifstream archivoEntrada = abrirArchivoEntrada(nombreArchivoEntrada);
    ofstream archivoSalida = abrirArchivoSalida(nombreArchivoSalida);

    if (!archivoEntrada || !archivoSalida) return;

    string linea;
    while (getline(archivoEntrada, linea)) {
        archivoSalida << convertirDeBinario(linea) << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    cout << "El archivo ha sido convertido de binario y guardado como '" << nombreArchivoSalida << "'.\n";
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal() {
    cout << "Seleccione el tipo de cifrado:\n";
    cout << "1. Cifrado Cesar\n";
    cout << "2. Conversion a binario\n";
    cout << "3. Salir\n";
}

// Función para mostrar el menú de opciones de Cifrado César
void mostrarMenuCesar() {
    cout << "Seleccione una opcion:\n";
    cout << "1. Encriptar texto con Cifrado Cesar\n";
    cout << "2. Desencriptar texto con Cifrado Cesar\n";
    cout << "3. Encriptar archivo con Cifrado Cesar\n";
    cout << "4. Desencriptar archivo con Cifrado Cesar\n";
    cout << "5. Volver al menú principal\n";
}

// Función para mostrar el menú de opciones de Conversión a Binario
void mostrarMenuBinario() {
    cout << "Seleccione una opcion:\n";
    cout << "1. Convertir texto a binario\n";
    cout << "2. Convertir binario a texto\n";
    cout << "3. Convertir archivo a binario\n";
    cout << "4. Convertir archivo binario a texto\n";
    cout << "5. Volver al menú principal\n";
}

int main() {
    int opcionPrincipal = 0;
    int opcionSecundaria = 0;
    string texto = "";
    string archivoEntrada;
    string archivoSalida;
    int desplazamiento = 0;

    do {
        mostrarMenuPrincipal();
        cin >> opcionPrincipal;
        cin.ignore();  // Limpiar el buffer del teclado

        switch (opcionPrincipal) {
            case 1: {
                do {
                    mostrarMenuCesar();
                    cin >> opcionSecundaria;
                    cin.ignore();

                    switch (opcionSecundaria) {
                        case 1: {
                            cout << "Introduce el texto a encriptar: ";
                            getline(cin, texto);
                            cout << "Introduce el desplazamiento: ";
                            cin >> desplazamiento;
                            // Validar que el desplazamiento no sea un múltiplo de 26
                            if (desplazamiento % 26 == 0 || desplazamiento == 0) {
                                cout << "Desplazamiento no válido. El valor no debe ser 0 ni múltiplo de 26.\n";
                                break;
                            }
                            cout << "Texto encriptado: " << encriptarCesar(texto, desplazamiento) << endl;
                            break;
                        }

                        case 2: {
                            cout << "Introduce el texto a desencriptar: ";
                            getline(cin, texto);
                            cout << "Introduce el desplazamiento: ";
                            cin >> desplazamiento;
                            // Validar que el desplazamiento no sea un múltiplo de 26
                            if (desplazamiento % 26 == 0 || desplazamiento == 0) {
                                cout << "Desplazamiento no válido. El valor no debe ser 0 ni múltiplo de 26.\n";
                                break;
                            }
                            cout << "Texto desencriptado: " << desencriptarCesar(texto, desplazamiento) << endl;
                            break;
                        }

                        case 3: {
                            cout << "Introduce el nombre del archivo a encriptar: ";
                            cin >> archivoEntrada;
                            cout << "Introduce el desplazamiento: ";
                            cin >> desplazamiento;
                            // Validar que el desplazamiento no sea un múltiplo de 26
                            if (desplazamiento % 26 == 0 || desplazamiento == 0) {
                                cout << "Desplazamiento no válido. El valor no debe ser 0 ni múltiplo de 26.\n";
                                break;
                            }
                            encriptarArchivoCesar(archivoEntrada, "archivo_encriptado_cesar.txt", desplazamiento);
                            break;
                        }

                        case 4: {
                            cout << "Introduce el nombre del archivo a desencriptar: ";
                            cin >> archivoEntrada;
                            cout << "Introduce el desplazamiento: ";
                            cin >> desplazamiento;
                            // Validar que el desplazamiento no sea un múltiplo de 26
                            if (desplazamiento % 26 == 0 || desplazamiento == 0) {
                                cout << "Desplazamiento no válido. El valor no debe ser 0 ni múltiplo de 26.\n";
                                break;
                            }
                            desencriptarArchivoCesar(archivoEntrada, "archivo_desencriptado_cesar.txt", desplazamiento);
                            break;
                        }

                        case 5:
                            break;

                        default:
                            cout << "Opcion no válida.\n";
                    }
                } while (opcionSecundaria != 5);
                break;
            }

            case 2: {
                do {
                    mostrarMenuBinario();
                    cin >> opcionSecundaria;
                    cin.ignore();

                    switch (opcionSecundaria) {
                        case 1: {
                            cout << "Introduce el texto a convertir a binario: ";
                            getline(cin, texto);
                            cout << "Texto en binario: " << convertirABinario(texto) << endl;
                            break;
                        }

                        case 2: {
                            cout << "Introduce el texto en binario a convertir: ";
                            getline(cin, texto);
                            cout << "Texto convertido: " << convertirDeBinario(texto) << endl;
                            break;
                        }

                        case 3: {
                            cout << "Introduce el nombre del archivo a convertir a binario: ";
                            cin >> archivoEntrada;
                            encriptarArchivoBinario(archivoEntrada, "archivo_binario.txt");
                            break;
                        }

                        case 4: {
                            cout << "Introduce el nombre del archivo binario a convertir a texto: ";
                            cin >> archivoEntrada;
                            desencriptarArchivoBinario(archivoEntrada, "archivo_convertido.txt");
                            break;
                        }

                        case 5:
                            break;

                        default:
                            cout << "Opcion no valida.\n";
                    }
                } while (opcionSecundaria != 5);
                break;
            }

            case 3:
                cout << "¡Gracias por usar el programa! Hasta luego.\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcionPrincipal != 3);

    return 0;
}
