/*
CUCEA | CIFRADO DE DATOS
Programa #1: Metodos de Cifrado en la historia
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Función para cifrar un mensaje utilizando el cifrado Vigenère
string cifrarVigenere(string mensaje, string clave) {
    string mensaje_cifrado = "";

    // Convertir la clave a mayúsculas para facilitar el cifrado
    for (char &c : clave) {
        c = toupper(c);
    }

    int clave_length = clave.length();
    int j = 0; // Variable para iterar sobre la clave

    for (char &c : mensaje) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            // Aplicar la fórmula de Vigenère para cifrar la letra
            char cifrado = ((c - base) + (clave[j % clave_length] - 'A')) % 26 + base;
            mensaje_cifrado += cifrado;
            j++;
        } else {
            mensaje_cifrado += c; // Mantener otros caracteres sin cifrar
        }
    }

    return mensaje_cifrado;
}

// Función para descifrar un mensaje cifrado utilizando el cifrado Vigenère
string descifrarVigenere(string mensaje_cifrado, string clave) {
    string mensaje_descifrado = "";

    // Convertir la clave a mayúsculas para facilitar el descifrado
    for (char &c : clave) {
        c = toupper(c);
    }

    int clave_length = clave.length();
    int j = 0; // Variable para iterar sobre la clave

    for (char &c : mensaje_cifrado) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            // Aplicar la fórmula de Vigenère para descifrar la letra
            char descifrado = ((c - base) - (clave[j % clave_length] - 'A') + 26) % 26 + base;
            mensaje_descifrado += descifrado;
            j++;
        } else {
            mensaje_descifrado += c; // Mantener otros caracteres sin descifrar
        }
    }

    return mensaje_descifrado;
}

int main() {
    int opc=0, salir=0;
    do{
      cout << "\033[2J\033[0;0H";
      cout << "\tPractica #1 - Metodos de Cifrado en la Historia\n\tAlgortimo Vigenere\n" << endl;
      char opcion;
      cout << "¿Desea cifrar (C) o descifrar (D) un mensaje? ";
      cin >> opcion;
  
      cin.ignore(); // Limpiar el buffer de entrada
  
      if (toupper(opcion) == 'C') {
          string mensaje_original, clave;
  
          // Solicitar al usuario el mensaje a cifrar
          cout << "Ingrese el mensaje a cifrar: ";
          getline(cin, mensaje_original);
  
          // Solicitar al usuario la clave
          cout << "Ingrese la clave: ";
          getline(cin, clave);
  
          // Cifrar el mensaje original
          string mensaje_cifrado = cifrarVigenere(mensaje_original, clave);
          cout << "Mensaje cifrado: " << mensaje_cifrado << endl;
      } else if (toupper(opcion) == 'D') {
          string mensaje_cifrado, clave;
  
          // Solicitar al usuario el mensaje a descifrar
          cout << "Ingrese el mensaje a descifrar: ";
          getline(cin, mensaje_cifrado);
  
          // Solicitar al usuario la clave
          cout << "Ingrese la clave: ";
          getline(cin, clave);
  
          // Descifrar el mensaje cifrado
          string mensaje_descifrado = descifrarVigenere(mensaje_cifrado, clave);
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
