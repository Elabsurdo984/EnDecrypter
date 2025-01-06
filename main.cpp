#include <iostream>
#include <string>
using namespace std;

// Funcion para encriptar el texto
string encriptar(string texto, int desplazamiento) {
    string texto_encriptado = "";

    for (char& c : texto) {
        if (isalpha(c)) { // Solo procesamos caracteres alfabeticos
            char base = (islower(c)) ? 'a' : 'A';
            // Desplazamos el caracter y lo agregamos al texto encriptado
            c = (c - base + desplazamiento) % 26 + base;
        }
        texto_encriptado += c;
    }

    return texto_encriptado;
}

// Funcion para desencriptar
string desencriptar(string texto, int desplazamiento) {
    return encriptar(texto, 26 - desplazamiento); // Desencriptar es lo mismo que encriptar con dezplasamiento invertido
}

int main() {
    string texto;
    int desplazamiento;

    // Entrada de texto y desplazamiento
    cout << "Introduce el texto: ";
    getline(cin, texto);
    cout << "Introduce el desplazamiento: ";
    cin >> desplazamiento;

    // Encriptar el texto
    string texto_encriptado = encriptar(texto, desplazamiento);
    cout << "Texto encriptado: " << texto_encriptado << endl;

    // Desencriptar el texto
    string texto_desencriptado = desencriptar(texto_encriptado, desplazamiento);
    cout << "Texto desencriptado: " << texto_desencriptado << endl;

    return 0;
}