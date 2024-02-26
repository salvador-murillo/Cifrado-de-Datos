/*
CUCEA | CIFRADO DE DATOS
Programa #1: Metodos de Cifrado en la historia
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Función para cifrar un mensaje utilizando el cifrado Polybios
string cifrarPolybios(string mensaje) {
    string resultado = "";
    string cuadradoPolybios[5] = {"ABCDE", "FGHIK", "LMNOP", "QRSTU", "VWXYZ"};

    for (char& c : mensaje) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') // omitimos la letra 'J'
                continue;
            if (c == ' ') // manejamos espacios
                resultado += " ";
            else {
                for (int i = 0; i < 5; i++) {
                    size_t pos = cuadradoPolybios[i].find(c);
                    if (pos != string::npos) {
                        resultado += to_string(i + 1) + to_string(pos + 1); // coordenadas
                        break;
                    }
                }
            }
        } else {
            resultado += c; // mantener otros caracteres
        }
    }
    return resultado;
}

// Función para descifrar un mensaje cifrado con el cifrado Polybios
string descifrarPolybios(string mensajeCifrado) {
    string resultado = "";
    string cuadradoPolybios[5] = {"ABCDE", "FGHIK", "LMNOP", "QRSTU", "VWXYZ"};

    for (int i = 0; i < mensajeCifrado.length(); i += 2) {
        if (mensajeCifrado[i] == ' ') {
            resultado += " "; // manejar espacios
            i--; // retroceder un paso para mantener el índice correcto
        } else {
            int fila = mensajeCifrado[i] - '0'; // convertir char a int
            int columna = mensajeCifrado[i + 1] - '0'; // convertir char a int
            resultado += cuadradoPolybios[fila - 1][columna - 1];
        }
    }
    return resultado;
}

int main() {
  int opc=0, salir=0;
  do{
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #1 - Metodos de Cifrado en la Historia\n\tAlgortimo Polybios\n" << endl;
  
    char opcion;
    cout << "¿Desea cifrar (C) o descifrar (D) un mensaje? ";
    cin >> opcion;

    cin.ignore(); // Limpiar el buffer de entrada

    if (toupper(opcion) == 'C') {
        string mensaje_original;

        // Solicitar al usuario el mensaje a cifrar
        cout << "Ingrese el mensaje a cifrar: ";
        getline(cin, mensaje_original);

        // Cifrar el mensaje original
        string mensaje_cifrado = cifrarPolybios(mensaje_original);
        cout << "Mensaje cifrado: " << mensaje_cifrado << endl;
    } else if (toupper(opcion) == 'D') {
        string mensaje_cifrado;

        // Solicitar al usuario el mensaje a descifrar
        cout << "Ingrese el mensaje a descifrar: ";
        getline(cin, mensaje_cifrado);

        // Descifrar el mensaje cifrado
        string mensaje_descifrado = descifrarPolybios(mensaje_cifrado);
        cout << "Mensaje descifrado: " << mensaje_descifrado << endl;
    } else {
        cout << "Opcion invalida." << endl;
    }

    cout << "\nDesea repetir el programa? (1.Si / 2.No): ";
    cin>>opc;
    if(opc==1){
      salir=1;
      cin.ignore();
    }else{
      salir=0;
    }
  }while(salir==1);
  return 0;
}
