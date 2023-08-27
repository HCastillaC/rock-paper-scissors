#include <iostream>
#include <vector>
#include <string>

void inv_apodo(stats& estadisticas){
    int accion;
    int i;
    vector<string> apodos_disponibles;

    for(i = 0; i < estadisticas.tamano_apodo + 1; i++){
        if(estadisticas.estado_apodos[i] == 2) apodos_disponibles.push_back(estadisticas.todos_apodos[i]);
    }

    cout << "Escribe el apodo que quieres usar: " << endl;

    for(i = 0; i < apodos_disponibles.size(); i++){
        cout << i + 1 << ". " << apodos_disponibles[i] << endl;
    }
    cout << i + 1 << ". Ninguno" << endl;
    cin >> accion;

    if(accion < i + 1) estadisticas.apodo_actual = apodos_disponibles[accion - 1];
    else if(accion == i + 1) estadisticas.apodo_actual = "";
}

void inventario_menu(stats& estadisticas)
{
    int accion;

    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Elegir apodo" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: inv_apodo(estadisticas); break;
    }
}
