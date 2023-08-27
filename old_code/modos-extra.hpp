#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "cinco_movimientos.hpp"
#include "siete_movimientos.hpp"
#include "nueve_movimientos.hpp"

void nueve_movimientos_menu(stats& estadisticas)
{
    int accion;
    
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Hasta..." << endl;
    cout << "2. Primero a..." << endl;
    cout << "3. Tira y afloja" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: nueve_movimientos_hasta(estadisticas); break;
        case 2: nueve_movimientos_primero(estadisticas); break;
        case 3: nueve_movimientos_tira_afloja(estadisticas); break;
    }
}

void siete_movimientos_menu(stats& estadisticas)
{
    int accion;
    
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Hasta..." << endl;
    cout << "2. Primero a..." << endl;
    cout << "3. Tira y afloja" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: siete_movimientos_hasta(estadisticas); break;
        case 2: siete_movimientos_primero(estadisticas); break;
        case 3: siete_movimientos_tira_afloja(estadisticas); break;
    }
}

void cinco_movimientos_menu(stats& estadisticas)
{
    int accion;
    
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Hasta..." << endl;
    cout << "2. Primero a..." << endl;
    cout << "3. Tira y afloja" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: cinco_movimientos_hasta(estadisticas); break;
        case 2: cinco_movimientos_primero(estadisticas); break;
        case 3: cinco_movimientos_tira_afloja(estadisticas); break;
    }
}

void modos_extra_menu(stats& estadisticas)
{
    int accion;
    
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    if(estadisticas.ul_cinco_movimientos == 1) cout << "1. Piedra, papel, tijera, lagarto, Spock" << endl;
    else cout << "1. <Desbloquea este modo en la tienda>" << endl;

    if(estadisticas.ul_siete_movimientos == 1) cout << "2. Siete movimientos" << endl;
    else cout << "2. <Desbloquea este modo en la tienda>" << endl;

    if(estadisticas.ul_nueve_movimientos == 1) cout << "3. Nueve movimientos" << endl;
    else cout << "3. <Desbloquea este modo en la tienda>" << endl;
    
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: 
            if(estadisticas.ul_cinco_movimientos == 1) cinco_movimientos_menu(estadisticas);
            else cout << "Aun no has desbloqueado este modo. Dirigete a la tienda para desbloquearlo (1000c) " << endl << endl;
            break;
        case 2: 
            if(estadisticas.ul_siete_movimientos == 1) siete_movimientos_menu(estadisticas);
            else cout << "Aun no has desbloqueado este modo. Dirigete a la tienda para desbloquearlo (1000c) " << endl << endl;
            break;
        case 3: 
            if(estadisticas.ul_nueve_movimientos == 1) nueve_movimientos_menu(estadisticas);
            else cout << "Aun no has desbloqueado este modo. Dirigete a la tienda para desbloquearlo (1000c) " << endl << endl;
            break;
    }
}
