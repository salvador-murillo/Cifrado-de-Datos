/*
CUCEA | CIFRADO DE DATOS
Programa #1: Metodos de Cifrado en la historia
*/
#include <iostream>
#include <string>

using namespace std;

// Función para cifrar un mensaje utilizando el algoritmo César
string cifrarCesar(string mensaje, int clave, bool hacia_adelante) {
    string resultado = "";
    int direccion = hacia_adelante ? 1 : -1;
    for (int i = 0; i < mensaje.length(); i++) {
        // Solo cifra letras del alfabeto, ignorando otros caracteres
        if (isalpha(mensaje[i])) {
            char offset = isupper(mensaje[i]) ? 'A' : 'a';
            int posicion = (mensaje[i] - offset + clave * direccion) % 26;
            if (posicion < 0) posicion += 26; // Ajuste para posiciones negativas
            char letra_cifrada = posicion + offset;
            resultado += letra_cifrada;
            cout << "Letra '" << mensaje[i] << "' cifrada como '" << letra_cifrada << "'" << endl; //"' en la posicion " << posicion << endl;
        } else {
            resultado += mensaje[i];
        }
    }
    return resultado;
}

// Función para descifrar un mensaje cifrado utilizando el algoritmo César
string descifrarCesar(string mensajeCifrado, int clave, bool hacia_adelante) {
    // Invertimos la dirección del cifrado para descifrar hacia atrás
    return cifrarCesar(mensajeCifrado, -clave, hacia_adelante);
}

int main() {
    int opc=0, salir=0;
    do{
      cout << "\033[2J\033[0;0H";
      cout << "\tPractica #1 - Metodos de Cifrado en la Historia\n\tAlgoritmo Cesar\n" << endl;
  
      string opcion;
      cout << "¿Desea cifrar (C) o descifrar (D) un mensaje? ";
      cin >> opcion;
  
      if (opcion == "C" || opcion == "c") {
          string mensaje_original;
          int clave;
          char direccion;
  
          cin.ignore(); // Limpiar el buffer de entrada
  
          // Solicitar al usuario el mensaje a cifrar
          cout << "Ingrese el mensaje a cifrar: ";
          getline(cin, mensaje_original);
  
          // Solicitar al usuario el número de desplazamientos
          cout << "Ingrese el numero de desplazamientos: ";
          cin >> clave;
  
          // Solicitar al usuario la dirección del cifrado
          cout << "Ingrese la direccion del cifrado (A para adelante, B para atras): ";
          cin >> direccion;
  
          bool hacia_adelante = (toupper(direccion) == 'A');
  
          // Cifrar el mensaje original
          string mensaje_cifrado = cifrarCesar(mensaje_original, clave, hacia_adelante);
          cout << "Mensaje cifrado: " << mensaje_cifrado << endl;
      } else if (opcion == "D" || opcion == "d") {
          string mensaje_cifrado;
          int clave;
          char direccion;
  
          cin.ignore(); // Limpiar el buffer de entrada
  
          // Solicitar al usuario el mensaje a descifrar
          cout << "Ingrese el mensaje a descifrar: ";
          getline(cin, mensaje_cifrado);
  
          // Solicitar al usuario el número de desplazamientos
          cout << "Ingrese el numero de desplazamientos: ";
          cin >> clave;
  
          // Solicitar al usuario la dirección del cifrado
          cout << "Ingrese la direccion del cifrado (A para adelante, B para atras): ";
          cin >> direccion;
  
          bool hacia_adelante = (toupper(direccion) == 'A');
  
          // Descifrar el mensaje cifrado
          string mensaje_descifrado = descifrarCesar(mensaje_cifrado, clave, hacia_adelante);
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
