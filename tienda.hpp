#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

void tienda_apodos(stats& estadisticas)
{
    srand(time(nullptr));
    
    int apodos_disponibles_0 = 0;
    vector<int> apodos_disponibles;
    int id_apodo = 0;
    int accion;
    int apodo_elegido;

    for(int i = 0; i < estadisticas.tamano_apodo; i++){
        if(estadisticas.estado_apodos[i] == 0) apodos_disponibles_0++;
        else if(estadisticas.estado_apodos[i] == 1) apodos_disponibles.push_back(i);
    }
    
    cout << "Tienes " << estadisticas.dinero << " c" << endl;
    if(apodos_disponibles.size() == 0){
        cout << "Has comprado todos los apodos" << endl;
        if(apodos_disponibles_0 != 0) cout << "Sigue jugando para desbloquear mas" << endl;
        else cout << "¡Felicidades! Ya has desbloqueado todos los titulos de jugador" << endl;
    } 
    else{
        cout << "¿" << estadisticas.apodo_actual << estadisticas.nombre << " " << " quieres comprar un apodo aleatorio (200c)?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> accion;

        if(accion == 1 and estadisticas.dinero >= 200){
            estadisticas.dinero -= 200;
            apodo_elegido = rand();
            apodo_elegido %= apodos_disponibles.size();

            estadisticas.estado_apodos[apodos_disponibles[apodo_elegido]] = 2;
            cout << "Has conseguido el apodo " << estadisticas.todos_apodos[apodos_disponibles[apodo_elegido]] << endl;
        }
        else if(estadisticas.dinero < 200) cout << "No tienes suficiente dinero" << endl;
    } 
}

void tienda_modos(stats& estadisticas)
{
    int accion;
    
    cout << "Tienes " << estadisticas.dinero << " c" << endl;
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    
    if(estadisticas.ul_casual_primero == 0) cout << "1. Comprar casual primero a... (150c)" << endl;
    else cout << "<Ya has comprado el modo casual primero a...>" << endl;

    if(estadisticas.ul_casual_tira_afloja == 0) cout << "2. Comprar casual tira y afloja (250c)" << endl;
    else cout << "<Ya has comprado el modo casual tira y afloja>" << endl;

    if(estadisticas.ul_casual_infinito == 0) cout << "3. Comprar casual infinito... (500c)" << endl;
    else cout << "<Ya has comprado el modo casual infinito>" << endl;

    if(estadisticas.ul_cinco_movimientos == 0) cout << "4. Comprar modo extra Piedra, papel, tijera, lagarto, Spock... (1000c)" << endl;
    else cout << "<Ya has comprado el modo extra Piedra, papel, tijera, lagarto, Spock...>" << endl;

    if(estadisticas.ul_siete_movimientos == 0) cout << "5. Comprar modo extra siete movimientos... (1000c)" << endl;
    else cout << "<Ya has comprado el modo extra siete movimientos>" << endl;

    if(estadisticas.ul_nueve_movimientos == 0) cout << "6. Comprar modo extra nueve movimientos... (1000c)" << endl;
    else cout << "<Ya has comprado el modo extra nueve movimientos>" << endl;

    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: 
            if(estadisticas.dinero >= 150 and estadisticas.ul_casual_primero == 0){
                estadisticas.ul_casual_primero = 1;
                estadisticas.dinero -= 150;
                cout << "Has comprado el modo casual primero a..." << endl;
            } 
            else if(estadisticas.dinero < 150) cout << "No tienes suficientes creditos. Necesitas " << 150 - estadisticas.dinero << "c mas" << endl;
            else cout << "Ya has comprado el modo casual primero a..." << endl;
            break;
        case 2: 
            if(estadisticas.dinero >= 250 and estadisticas.ul_casual_tira_afloja == 0){
                estadisticas.ul_casual_tira_afloja = 1;
                estadisticas.dinero -= 250;
                cout << "Has comprado el modo casual tira y afloja..." << endl;
            } 
            else if(estadisticas.dinero < 250) cout << "No tienes suficientes creditos. Necesitas " << 250 - estadisticas.dinero << "c mas" << endl;
            else cout << "Ya has comprado el modo casual tira y afloja" << endl;
            break;
        case 3: 
            if(estadisticas.dinero >= 500 and estadisticas.ul_casual_infinito == 0){
                estadisticas.ul_casual_infinito = 1;
                estadisticas.dinero -= 500;
                cout << "Has comprado el modo casual infinito" << endl;
            } 
            else if(estadisticas.dinero < 500) cout << "No tienes suficientes creditos. Necesitas " << 500 - estadisticas.dinero << "c mas" << endl;
            else cout << "Ya has comprado el modo casual infinito" << endl;
            break;
        case 4: 
            if(estadisticas.dinero >= 1000 and estadisticas.ul_cinco_movimientos == 0){
                estadisticas.ul_cinco_movimientos = 1;
                estadisticas.dinero -= 1000;
                cout << "Has comprado el modo extra Piedra, papel, tijera, lagarto, Spock..." << endl;
            } 
            else if(estadisticas.dinero < 1000) cout << "No tienes suficientes creditos. Necesitas " << 1000 - estadisticas.dinero << "c mas" << endl;
            else cout << "Ya has comprado el modo extra Piedra, papel, tijera, lagarto, Spock..." << endl;
            break;
        case 5: 
            if(estadisticas.dinero >= 1000 and estadisticas.ul_siete_movimientos == 0){
                estadisticas.ul_siete_movimientos = 1;
                estadisticas.dinero -= 1000;
                cout << "Has comprado el modo extra siete movimientos" << endl;
            } 
            else if(estadisticas.dinero < 1000) cout << "No tienes suficientes creditos. Necesitas " << 1000 - estadisticas.dinero << "c mas" << endl;
            else cout << "Ya has comprado el modo extra siete movimientos" << endl;
            break;
        case 6: 
            if(estadisticas.dinero >= 1000 and estadisticas.ul_nueve_movimientos == 0){
                estadisticas.ul_nueve_movimientos = 1;
                estadisticas.dinero -= 1000;
                cout << "Has comprado el modo extra nueve movimientos" << endl;
            } 
            else if(estadisticas.dinero < 1000) cout << "No tienes suficientes creditos. Necesitas " << 1000 - estadisticas.dinero << "c mas" << endl;
            else cout << "Ya has comprado el modo extra nueve movimientos" << endl;
            break;
    }
}

void tienda_menu(stats& estadisticas)
{
    int accion;
    
    cout << "Tienes " << estadisticas.dinero << " c" << endl;
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Comprar modos" << endl;
    cout << "2. Comprar apodos" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: tienda_modos(estadisticas); break;
        case 2: tienda_apodos(estadisticas); break;
    }
}