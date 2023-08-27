#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void debug_menu(stats& estadisticas)
{
    int accion;
    
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Dinero" << endl;
    cout << "2. Modos" << endl;
    cout << "3. Apodos" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: estadisticas.dinero += 10000; break;
        case 2:
            estadisticas.ul_casual_primero = 1;
            estadisticas.ul_casual_tira_afloja = 1;
            estadisticas.ul_casual_infinito = 1;
            estadisticas.ul_cinco_movimientos = 1;
            estadisticas.ul_siete_movimientos = 1;
            estadisticas.ul_nueve_movimientos = 1;
            estadisticas.ul_competitivo_ganador25 = 1;
            estadisticas.ul_competitivo_primero5 = 1;
            estadisticas.ul_competitivo_primero10 = 1;
            estadisticas.ul_competitivo_diferencia3 = 1;
            estadisticas.ul_competitivo_diferencia5 = 1;
            break;
        case 3:
            for(int i = 0; i < estadisticas.tamano_apodo; i++) estadisticas.estado_apodos[i] = 2;
            break;
    }
}

int que_es(char letra)
{
    char minuscula[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char mayuscula[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char simbolos[26] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', ',', ':', ';', '-', '_', '(', ')', '{', '}', '[', ']', '&', '%', '#', '@'};
    
    for(int i = 0; i < 26; i++) if(letra == minuscula[i]) return 0;
    for(int i = 0; i < 26; i++) if(letra == mayuscula[i]) return 1;
    for(int i = 0; i < 26; i++) if(letra == simbolos[i]) return 2;
    return 3;
}

int cual_es(char letra)
{
    char minuscula[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char mayuscula[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char simbolos[26] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', ',', ':', ';', '-', '_', '(', ')', '{', '}', '[', ']', '&', '%', '#', '@'};
    
    for(int i = 0; i < 26; i++) if(letra == minuscula[i]) return i;
    for(int i = 0; i < 26; i++) if(letra == mayuscula[i]) return i;
    for(int i = 0; i < 26; i++) if(letra == simbolos[i]) return i;
    return 0;
}

string cifrate(string palabra)
{
    srand(time(nullptr));
    
    int clave = 18;
    int largo_frase = palabra.size();

    int tipo;
    int letra;
    
    char minuscula[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char mayuscula[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char simbolos[26] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', ',', ':', ';', '-', '_', '(', ')', '{', '}', '[', ']', '&', '%', '#', '@'};
    
    for(int index_letra = 0; index_letra < largo_frase; index_letra++){
        tipo = que_es(palabra[index_letra]);
        letra = cual_es(palabra[index_letra]);
        
        letra += clave;
        
        while(letra < -1) letra += 26;
        while(letra > 25) letra -= 26;
        
        switch(tipo){
            case 0: palabra[index_letra] = minuscula[letra]; break;
            case 1: palabra[index_letra] = mayuscula[letra]; break;
            case 2: palabra[index_letra] = simbolos[letra]; break;
            case 3: break;
        }
    }
    
    return palabra;
}

void pre_debug_menu(stats& estadisticas)
{
    string password;
    string password_cifrated = "S ysangls tsapakls lwe mes nwflsywe";

    cout << "Escribe la contraseña: " << endl,
    cin.ignore();
    getline(cin, password);
    password = cifrate(password);

    if(password == password_cifrated) debug_menu(estadisticas);
    else cout << "Contraseña incorrecta" << endl;    
}
