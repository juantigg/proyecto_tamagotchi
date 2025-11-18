#include <iostream>
using namespace std;

void mostrarEstado (int&, int&, int&, int&, string&, string&);
void comer (int&, int&);
void eleccion (int&, string&);
void dormir (int&, int&);
char menu(char&, string&);
void trabajar (int&, int&, int&, int&);
void mostrar_mapa(string mapa[][4]);


int main () {

    string nombre;
    string id;
    string figura;

    string mapa[4][4];
    int numero = 0;
    int hambre = 0;
    int energia = 100;
    int felicidad = 100;
    int dinero = 0;
    char caracter;

    eleccion(numero, figura);

    cout << "Ingresa el nombre de tu mascota: ";
    cin >> nombre;
    cout << "Ahora, por favor ingresa el id de tu mascota: ";
    cin >> id;

    // zᶻ   ૮˶- ﻌ -˶ა⌒)ᦱ PA DORMIR
    

    do {
    menu(caracter, nombre);

    switch (caracter){

        case '1':
        mostrarEstado (hambre, energia, felicidad, dinero, figura, nombre);
        break;

        case '2':
        comer(dinero, hambre);
        break;

        case '3':
        cout << "Tu mascota duerme zzz" << endl;
        dormir(energia, hambre);
        break;

        case '4':
        cout << "Tu mascota se va a trabajar (?)" << endl;
        trabajar(energia, dinero, felicidad, hambre);
        break;
        
        case '5':
        cout << "Este es el mapa de la ciudad" << endl;
        mostrar_mapa(mapa);
        cout << endl << "A donde te gustaria ir?" << endl;
        break;

        case '6':
        // aqui va la funcion para guardar en un archivo pero eso no lo hemos visto
        break;

        case '7':
        // aqui va la funcion para cargar en un archivo pero tampoco lo hemos visto
        break;
    
        case '8':
        break;
        }
    } while (caracter != '8'); 
}

void eleccion(int& numero, string& figura) {
        
    cout << "¡Bienvenid@ a tu Tamagotchi!" << endl;
    cout << "Para empezar, por favor elige tu mascota" << endl;
    cout << "1. )^w^)/ GATO" <<  endl;
    cout << "2. /(OwO)/ PERRO" << endl;
    cout << "3. /)*u*)/ CONEJO" << endl;
    cout << "Introduce tu eleccion: ";
    cin >> numero;

    while (numero != 1 && numero != 2 && numero != 3) {
        cout << "Introduce una eleccion valida (1, 2 o 3): ";
        cin >> numero;
    }
    if (numero == 1) {
        cout << "¡Haz escogido gato! )^w^)/" << endl;
        figura = ")^w^)/";
    } else if (numero == 2) {
        cout << "¡Haz escogido perro! /(OwO)/" << endl;
        figura = "/(OwO)/";
    } else if (numero == 3) {
        cout << "¡Haz escogido conejo! /)*u*)/" << endl;
        figura = "/)*u*)/";
    }
}

void mostrarEstado(int& hambre, int& energia, int& felicidad, int& dinero, string& nombre, string& figura) {
    cout << "ESTADO ACTUAL DE TU TAMAGOTCHI"<< endl;
    cout << nombre << " " << figura << endl;
    cout << "Hambre: " << hambre << endl;
    cout << "Energia: " << energia << endl;
    cout << "Felicidad: " << felicidad << endl;
    cout << "Dinero: " << dinero << endl;
}

void comer(int& dinero, int& hambre) {
    if (dinero >= 20) {
        hambre -= 30;
        while (hambre <= 0) {
            hambre++;
        } 
        dinero -= 20;
    } else if (dinero < 20) {
        cout << "No tiene suficiente dinero para comer, su dinero actual es de: " << dinero << endl;
    }
}

void dormir(int& energia, int& hambre) {
    energia = 100;
    hambre += 20;
    while (hambre > 100) {
        hambre--;
    }
}

// No tiene sentido que la accion de trabajar pida al menos 20 de energia
// pero que disminuya la energia en 40 puntos ya que eso daria -20 de energia 
// debido a esto voy a diseñar la funcion para energia > 40

void trabajar (int& energia, int& dinero, int& felicidad, int& hambre) {
    if (energia >= 40) {

        energia -= 40;
        while (energia <= 0) {
            energia++;
        }

        dinero += 100;

        felicidad -= 10;
        while (felicidad <= 0) {
            felicidad++;
        }


        hambre +=10;
        while (hambre > 100) {
            hambre--;
        }

    } else if (energia < 40) {
        cout << "No tienes suficiente energia para trabajar, descansa!";
    }
}

char menu (char& caracter, string& nombre) {
    cout << "Elija la accion que realizara su mascota " << nombre << endl;
    cout << "1. Ver su estado" << endl;
    cout << "2. Darle de comer" << endl;
    cout << "3. Ponerle a dormir" << endl;
    cout << "4. Que vaya a trabajar" << endl;
    cout << "5. Moverse en el mapa" << endl;
    cout << "6. Guardar su progreso" << endl;
    cout << "7. Cargar su progreso" << endl;
    cout << "8. para matar el programa" << endl;
    cin >> caracter;
    return caracter;
}

void mostrar_mapa(string mapa[][4]) {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mapa[i][j] = "0";
            }
        }

        mapa[0][0] = "🏠";
        mapa[2][2] = "🏥";
        mapa[1][3] = "🛒";
        mapa[3][3] = "🌳";
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mapa[i][j] << " ";
                if (j == 3) {
                    cout << endl;
            }
        }
    }
}
