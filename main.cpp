#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "perfil.hpp"
#include "tienda.hpp"
#include "estadisticas.hpp"
#include "competitivo.hpp"
#include "casual.hpp"
#include "modos_extra.hpp"
#include "multijugador.hpp"
#include "inventario.hpp"
#include "debug.hpp"
using namespace std;

void play_menu(stats& estadisticas, stats& multijugador)
{
    int accion;
    
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Casual" << endl;
    cout << "2. Competitivo" << endl;
    cout << "3. Modos extra" << endl;
    cout << "4. Multijugador" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: casual_menu(estadisticas); break;
        case 2: competitivo_menu(estadisticas); break;
        case 3: modos_extra_menu(estadisticas); break;
        case 4: multijugador_menu(estadisticas, multijugador); break;
    }
}

void profile_menu(stats& estadisticas)
{
    int accion;
    
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Crear perfil" << endl;
    cout << "2. Guardar estadisticas" << endl;
    cout << "3. Cargar estadisticas" << endl;
    cout << "4. Cargar estadisticas de archivo multijugador" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: create_profile(estadisticas); break;
        case 2: save_stats(estadisticas); break;
        case 3: load_stats(estadisticas); break;
        case 4: from_mp_load_stats(estadisticas); break;
    }
}

int action_menu(stats& estadisticas, stats& multijugador)
{
    int accion;
    
    save_stats(estadisticas);
    desbloqueo_apodos(estadisticas);

    cout << "Hola " << estadisticas.apodo_actual << estadisticas.nombre << endl;
    cout << "Escribe el numero de la accion que quieres realizar: " << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Estadisticas" << endl;
    cout << "3. Tienda" << endl;
    cout << "4. Inventario" << endl;
    cout << "5. Perfil" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: play_menu(estadisticas, multijugador); break;
        case 2: stats_general(estadisticas); break;
        case 3: tienda_menu(estadisticas); break;
        case 4: inventario_menu(estadisticas); break;
        case 5: profile_menu(estadisticas); break;
        case 130108: pre_debug_menu(estadisticas); break;
    }
    
    return accion;
}

void title_screen()
{
    //To do
    cout << "-------------------------------------" << endl;
    cout << "Hugo C presenta...                   " << endl;
    cout << "     Super                           " << endl;
    cout << "           piedra,                   " << endl;
    cout << "                   papel,            " << endl;
    cout << "                          tijera     " << endl;
    cout << "-------------------------------------" << endl;
    cout << endl;
}

int main()
{
    int accion = 1;
    stats estadisticas;
    stats multijugador;
    
    load_stats(estadisticas);
    title_screen();
    
    while(accion != 0) accion = action_menu(estadisticas, multijugador);
    
    return 0;
}
