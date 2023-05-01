#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

void mp_diferencia(stats& estadisticas, stats& multijugador)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot = -3;
    
    string movimientos[3] = {"Piedra", "Papel", "Tijera"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int jugador_racha_victorias = 0;
    int jugador_racha_empates = 0;
    int jugador_racha_derrotas = 0;
    int bot_racha_victorias = 0;
    int bot_racha_empates = 0;
    int bot_racha_derrotas = 0;
    
    int limite;
    
    cout << "Escribe el número de rondas: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.multijugador++;
    estadisticas.multijugador_diferencia++;
    multijugador.totales++;
    multijugador.multijugador++;
    multijugador.multijugador_diferencia++;
    
    while(limite > victorias_jugador - victorias_bot and limite > victorias_bot - victorias_jugador){
        while(movimiento_jugador > 4 or movimiento_jugador < -1){
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << "0. Finalizar" << endl;
            
            cin >> movimiento_jugador;
        }
        
        switch(movimiento_jugador){
            case 1: estadisticas.piedra++; break;
            case 2: estadisticas.papel++; break;
            case 3: estadisticas.tijera++; break;
        }
        
        movimiento_jugador--;
        
        while(movimiento_bot > 4 or movimiento_bot < -1){
            cout << multijugador.apodo_actual << multijugador.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << "0. Finalizar" << endl;
            
            cin >> movimiento_bot;
        }
        
        switch(movimiento_jugador){
            case 1: multijugador.piedra++; break;
            case 2: multijugador.papel++; break;
            case 3: multijugador.tijera++; break;
        }

        movimiento_bot--;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        if((movimiento_jugador == 0 and movimiento_bot == 1) or
        (movimiento_jugador == 1 and movimiento_bot == 2) or
        (movimiento_jugador == 2 and movimiento_bot == 0)){
            victorias_bot++;
            estadisticas.derrotas++;
            multijugador.victorias;
            jugador_racha_derrotas++;
            bot_racha_victorias++;
            
            if(jugador_racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += jugador_racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = jugador_racha_empates;
            } 
            jugador_racha_empates = 0;
            if(jugador_racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += jugador_racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = jugador_racha_victorias;
            } 
            jugador_racha_victorias = 0;
            

            if(bot_racha_empates > multijugador.record_empates){
                if(multijugador.acumula_empates == 1){
                    multijugador.record_empates += bot_racha_empates;
                    multijugador.acumula_empates = 0;
                }
                else multijugador.record_empates = bot_racha_empates;
            } 
            bot_racha_empates = 0;
            if(bot_racha_derrotas > multijugador.record_derrotas){
                if(multijugador.acumula_derrotas == 1){
                    multijugador.record_derrotas += bot_racha_derrotas;
                    multijugador.acumula_derrotas = 0;
                }
                else multijugador.record_derrotas = bot_racha_derrotas;
            } 
            bot_racha_derrotas = 0;

            cout << multijugador.apodo_actual << " " << multijugador.nombre << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else if((movimiento_jugador == 1 and movimiento_bot == 0) or
        (movimiento_jugador == 2 and movimiento_bot == 1) or
        (movimiento_jugador == 0 and movimiento_bot == 2)){
            victorias_jugador++;
            estadisticas.victorias++;
            multijugador.derrotas++;
            jugador_racha_victorias++;
            bot_racha_derrotas++;
            
            if(jugador_racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += jugador_racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = jugador_racha_empates;
            } 
            jugador_racha_empates = 0;
            if(jugador_racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += jugador_racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = jugador_racha_derrotas;
            } 
            jugador_racha_derrotas = 0;

            if(bot_racha_empates > multijugador.record_empates){
                if(multijugador.acumula_empates == 1){
                    multijugador.record_empates += bot_racha_empates;
                    multijugador.acumula_empates = 0;
                }
                else multijugador.record_empates = bot_racha_empates;
            } 
            bot_racha_empates = 0;
            if(bot_racha_victorias > multijugador.record_victorias){
                if(multijugador.acumula_victorias == 1){
                    multijugador.record_victorias += bot_racha_victorias;
                    multijugador.acumula_victorias = 0;
                }
                else multijugador.record_victorias = bot_racha_victorias;
            } 
            bot_racha_victorias = 0;
            
            cout << estadisticas.apodo_actual << " " << estadisticas.nombre << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else{
            empates++;
            estadisticas.empates++;
            multijugador.empates++;
            jugador_racha_empates++;
            bot_racha_empates++;
            
            if(jugador_racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += jugador_racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = jugador_racha_derrotas;
            } 
            jugador_racha_derrotas = 0;
            if(jugador_racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += jugador_racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = jugador_racha_victorias;
            } 
            jugador_racha_victorias = 0;

            if(bot_racha_derrotas > multijugador.record_derrotas){
                if(multijugador.acumula_derrotas == 1){
                    multijugador.record_derrotas += bot_racha_derrotas;
                    multijugador.acumula_derrotas = 0;
                }
                else multijugador.record_derrotas = bot_racha_derrotas;
            } 
            bot_racha_derrotas = 0;
            if(bot_racha_victorias > multijugador.record_victorias){
                if(multijugador.acumula_victorias == 1){
                    multijugador.record_victorias += bot_racha_victorias;
                    multijugador.acumula_victorias = 0;
                }
                else multijugador.record_victorias = bot_racha_victorias;
            } 
            bot_racha_victorias = 0;
            
            cout << "Habeis empatado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        movimiento_jugador = -3;
        movimiento_bot = -3;
        cout << endl;
    }
    
    if(victorias_jugador < victorias_bot){
        estadisticas.partidas_perdidas++;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_derrotas = 1;
        
        cout << multijugador.apodo_actual << " " << multijugador.nombre << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador > victorias_bot){
        estadisticas.partidas_ganadas++;
        estadisticas.dinero += 20;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_victorias = 1;
        
        cout << estadisticas.apodo_actual << " " << estadisticas.nombre << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador == victorias_bot){
        estadisticas.partidas_empatadas++;
        estadisticas.dinero += 5;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_empates = 1;
        
        cout << "Habeis empatado la partida a " <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;
}

void mp_primero(stats& estadisticas, stats& multijugador)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot = -3;
    
    string movimientos[3] = {"Piedra", "Papel", "Tijera"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int jugador_racha_victorias = 0;
    int jugador_racha_empates = 0;
    int jugador_racha_derrotas = 0;
    int bot_racha_victorias = 0;
    int bot_racha_empates = 0;
    int bot_racha_derrotas = 0;
    
    int limite;
    
    cout << "Escribe el número de rondas: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.multijugador++;
    estadisticas.multijugador_primero++;
    multijugador.totales++;
    multijugador.multijugador++;
    multijugador.multijugador_primero++;
    
    while(limite > victorias_jugador and limite > victorias_bot){
        while(movimiento_jugador > 4 or movimiento_jugador < -1){
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << "0. Finalizar" << endl;
            
            cin >> movimiento_jugador;
        }
        
        switch(movimiento_jugador){
            case 1: estadisticas.piedra++; break;
            case 2: estadisticas.papel++; break;
            case 3: estadisticas.tijera++; break;
        }
        
        movimiento_jugador--;
        
        while(movimiento_bot > 4 or movimiento_bot < -1){
            cout << multijugador.apodo_actual << multijugador.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << "0. Finalizar" << endl;
            
            cin >> movimiento_bot;
        }
        
        switch(movimiento_jugador){
            case 1: multijugador.piedra++; break;
            case 2: multijugador.papel++; break;
            case 3: multijugador.tijera++; break;
        }

        movimiento_bot--;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        if((movimiento_jugador == 0 and movimiento_bot == 1) or
        (movimiento_jugador == 1 and movimiento_bot == 2) or
        (movimiento_jugador == 2 and movimiento_bot == 0)){
            victorias_bot++;
            estadisticas.derrotas++;
            multijugador.victorias;
            jugador_racha_derrotas++;
            bot_racha_victorias++;
            
            if(jugador_racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += jugador_racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = jugador_racha_empates;
            } 
            jugador_racha_empates = 0;
            if(jugador_racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += jugador_racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = jugador_racha_victorias;
            } 
            jugador_racha_victorias = 0;
            

            if(bot_racha_empates > multijugador.record_empates){
                if(multijugador.acumula_empates == 1){
                    multijugador.record_empates += bot_racha_empates;
                    multijugador.acumula_empates = 0;
                }
                else multijugador.record_empates = bot_racha_empates;
            } 
            bot_racha_empates = 0;
            if(bot_racha_derrotas > multijugador.record_derrotas){
                if(multijugador.acumula_derrotas == 1){
                    multijugador.record_derrotas += bot_racha_derrotas;
                    multijugador.acumula_derrotas = 0;
                }
                else multijugador.record_derrotas = bot_racha_derrotas;
            } 
            bot_racha_derrotas = 0;

            cout << multijugador.apodo_actual << " " << multijugador.nombre << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else if((movimiento_jugador == 1 and movimiento_bot == 0) or
        (movimiento_jugador == 2 and movimiento_bot == 1) or
        (movimiento_jugador == 0 and movimiento_bot == 2)){
            victorias_jugador++;
            estadisticas.victorias++;
            multijugador.derrotas++;
            jugador_racha_victorias++;
            bot_racha_derrotas++;
            
            if(jugador_racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += jugador_racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = jugador_racha_empates;
            } 
            jugador_racha_empates = 0;
            if(jugador_racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += jugador_racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = jugador_racha_derrotas;
            } 
            jugador_racha_derrotas = 0;

            if(bot_racha_empates > multijugador.record_empates){
                if(multijugador.acumula_empates == 1){
                    multijugador.record_empates += bot_racha_empates;
                    multijugador.acumula_empates = 0;
                }
                else multijugador.record_empates = bot_racha_empates;
            } 
            bot_racha_empates = 0;
            if(bot_racha_victorias > multijugador.record_victorias){
                if(multijugador.acumula_victorias == 1){
                    multijugador.record_victorias += bot_racha_victorias;
                    multijugador.acumula_victorias = 0;
                }
                else multijugador.record_victorias = bot_racha_victorias;
            } 
            bot_racha_victorias = 0;
            
            cout << estadisticas.apodo_actual << " " << estadisticas.nombre << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else{
            empates++;
            estadisticas.empates++;
            multijugador.empates++;
            jugador_racha_empates++;
            bot_racha_empates++;
            
            if(jugador_racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += jugador_racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = jugador_racha_derrotas;
            } 
            jugador_racha_derrotas = 0;
            if(jugador_racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += jugador_racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = jugador_racha_victorias;
            } 
            jugador_racha_victorias = 0;

            if(bot_racha_derrotas > multijugador.record_derrotas){
                if(multijugador.acumula_derrotas == 1){
                    multijugador.record_derrotas += bot_racha_derrotas;
                    multijugador.acumula_derrotas = 0;
                }
                else multijugador.record_derrotas = bot_racha_derrotas;
            } 
            bot_racha_derrotas = 0;
            if(bot_racha_victorias > multijugador.record_victorias){
                if(multijugador.acumula_victorias == 1){
                    multijugador.record_victorias += bot_racha_victorias;
                    multijugador.acumula_victorias = 0;
                }
                else multijugador.record_victorias = bot_racha_victorias;
            } 
            bot_racha_victorias = 0;
            
            cout << "Habeis empatado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        movimiento_jugador = -3;
        movimiento_bot = -3;
        cout << endl;
    }
    
    if(victorias_jugador < victorias_bot){
        estadisticas.partidas_perdidas++;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_derrotas = 1;
        
        cout << multijugador.apodo_actual << " " << multijugador.nombre << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador > victorias_bot){
        estadisticas.partidas_ganadas++;
        estadisticas.dinero += 20;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_victorias = 1;
        
        cout << estadisticas.apodo_actual << " " << estadisticas.nombre << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador == victorias_bot){
        estadisticas.partidas_empatadas++;
        estadisticas.dinero += 5;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_empates = 1;
        
        cout << "Habeis empatado la partida a " <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;
}

void mp_hasta(stats& estadisticas, stats& multijugador)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot = -3;
    
    string movimientos[3] = {"Piedra", "Papel", "Tijera"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int jugador_racha_victorias = 0;
    int jugador_racha_empates = 0;
    int jugador_racha_derrotas = 0;
    int bot_racha_victorias = 0;
    int bot_racha_empates = 0;
    int bot_racha_derrotas = 0;
    
    int limite;
    
    cout << "Escribe el número de rondas: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.multijugador++;
    estadisticas.multijugador_hasta++;
    multijugador.totales++;
    multijugador.multijugador++;
    multijugador.multijugador_hasta++;
    
    for(int i = 0; i < limite; i++){
        while(movimiento_jugador > 4 or movimiento_jugador < -1){
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << "0. Finalizar" << endl;
            
            cin >> movimiento_jugador;
        }
        
        switch(movimiento_jugador){
            case 1: estadisticas.piedra++; break;
            case 2: estadisticas.papel++; break;
            case 3: estadisticas.tijera++; break;
        }
        
        movimiento_jugador--;
        
        while(movimiento_bot > 4 or movimiento_bot < -1){
            cout << multijugador.apodo_actual << multijugador.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << "0. Finalizar" << endl;
            
            cin >> movimiento_bot;
        }
        
        switch(movimiento_jugador){
            case 1: multijugador.piedra++; break;
            case 2: multijugador.papel++; break;
            case 3: multijugador.tijera++; break;
        }

        movimiento_bot--;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        if((movimiento_jugador == 0 and movimiento_bot == 1) or
        (movimiento_jugador == 1 and movimiento_bot == 2) or
        (movimiento_jugador == 2 and movimiento_bot == 0)){
            victorias_bot++;
            estadisticas.derrotas++;
            multijugador.victorias;
            jugador_racha_derrotas++;
            bot_racha_victorias++;
            
            if(jugador_racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += jugador_racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = jugador_racha_empates;
            } 
            jugador_racha_empates = 0;
            if(jugador_racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += jugador_racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = jugador_racha_victorias;
            } 
            jugador_racha_victorias = 0;
            

            if(bot_racha_empates > multijugador.record_empates){
                if(multijugador.acumula_empates == 1){
                    multijugador.record_empates += bot_racha_empates;
                    multijugador.acumula_empates = 0;
                }
                else multijugador.record_empates = bot_racha_empates;
            } 
            bot_racha_empates = 0;
            if(bot_racha_derrotas > multijugador.record_derrotas){
                if(multijugador.acumula_derrotas == 1){
                    multijugador.record_derrotas += bot_racha_derrotas;
                    multijugador.acumula_derrotas = 0;
                }
                else multijugador.record_derrotas = bot_racha_derrotas;
            } 
            bot_racha_derrotas = 0;

            cout << multijugador.apodo_actual << " " << multijugador.nombre << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else if((movimiento_jugador == 1 and movimiento_bot == 0) or
        (movimiento_jugador == 2 and movimiento_bot == 1) or
        (movimiento_jugador == 0 and movimiento_bot == 2)){
            victorias_jugador++;
            estadisticas.victorias++;
            multijugador.derrotas++;
            jugador_racha_victorias++;
            bot_racha_derrotas++;
            
            if(jugador_racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += jugador_racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = jugador_racha_empates;
            } 
            jugador_racha_empates = 0;
            if(jugador_racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += jugador_racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = jugador_racha_derrotas;
            } 
            jugador_racha_derrotas = 0;

            if(bot_racha_empates > multijugador.record_empates){
                if(multijugador.acumula_empates == 1){
                    multijugador.record_empates += bot_racha_empates;
                    multijugador.acumula_empates = 0;
                }
                else multijugador.record_empates = bot_racha_empates;
            } 
            bot_racha_empates = 0;
            if(bot_racha_victorias > multijugador.record_victorias){
                if(multijugador.acumula_victorias == 1){
                    multijugador.record_victorias += bot_racha_victorias;
                    multijugador.acumula_victorias = 0;
                }
                else multijugador.record_victorias = bot_racha_victorias;
            } 
            bot_racha_victorias = 0;
            
            cout << estadisticas.apodo_actual << " " << estadisticas.nombre << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else{
            empates++;
            estadisticas.empates++;
            multijugador.empates++;
            jugador_racha_empates++;
            bot_racha_empates++;
            
            if(jugador_racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += jugador_racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = jugador_racha_derrotas;
            } 
            jugador_racha_derrotas = 0;
            if(jugador_racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += jugador_racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = jugador_racha_victorias;
            } 
            jugador_racha_victorias = 0;

            if(bot_racha_derrotas > multijugador.record_derrotas){
                if(multijugador.acumula_derrotas == 1){
                    multijugador.record_derrotas += bot_racha_derrotas;
                    multijugador.acumula_derrotas = 0;
                }
                else multijugador.record_derrotas = bot_racha_derrotas;
            } 
            bot_racha_derrotas = 0;
            if(bot_racha_victorias > multijugador.record_victorias){
                if(multijugador.acumula_victorias == 1){
                    multijugador.record_victorias += bot_racha_victorias;
                    multijugador.acumula_victorias = 0;
                }
                else multijugador.record_victorias = bot_racha_victorias;
            } 
            bot_racha_victorias = 0;
            
            cout << "Habeis empatado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        movimiento_jugador = -3;
        movimiento_bot = -3;
        cout << endl;
    }
    
    if(victorias_jugador < victorias_bot){
        estadisticas.partidas_perdidas++;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_derrotas = 1;
        
        cout << multijugador.apodo_actual << " " << multijugador.nombre << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador > victorias_bot){
        estadisticas.partidas_ganadas++;
        estadisticas.dinero += 20;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_victorias = 1;
        
        cout << estadisticas.apodo_actual << " " << estadisticas.nombre << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador == victorias_bot){
        estadisticas.partidas_empatadas++;
        estadisticas.dinero += 5;
        
        if(jugador_racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += jugador_racha_derrotas;
            else estadisticas.record_derrotas = jugador_racha_derrotas;
        }
        if(jugador_racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += jugador_racha_empates;
            else estadisticas.record_empates = jugador_racha_empates;
        } 
        if(jugador_racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += jugador_racha_victorias;
            else estadisticas.record_victorias = jugador_racha_victorias;
        } 
        estadisticas.acumula_empates = 1;
        
        cout << "Habeis empatado la partida a " <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;
}

void play_multijugador_menu(stats& estadisticas, stats& multijugador)
{
    int accion;

    cout << "Escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Hasta..." << endl;
    cout << "2. Primero a..." << endl;
    cout << "3. Tira y afloja" << endl;

    cin >> accion;

    switch(accion){
        case 1: mp_hasta(estadisticas, multijugador); break;
        case 2: mp_primero(estadisticas, multijugador); break;
        case 3: mp_diferencia(estadisticas, multijugador); break;
    }
}

void add_cuentas(stats& estadisticas, stats& multijugador){
    ifstream guardado ("mp.save");

    guardado >> multijugador.nombre;
    guardado >> multijugador.dinero;
    guardado >> multijugador.victorias;
    guardado >> multijugador.empates;
    guardado >> multijugador.derrotas;
    guardado >> multijugador.partidas_ganadas;
    guardado >> multijugador.partidas_empatadas;
    guardado >> multijugador.partidas_perdidas;
    guardado >> multijugador.piedra;
    guardado >> multijugador.papel;
    guardado >> multijugador.tijera;
    guardado >> multijugador.lagarto;
    guardado >> multijugador.spock;
    guardado >> multijugador.fuego;
    guardado >> multijugador.esponja;
    guardado >> multijugador.aire;
    guardado >> multijugador.agua;
    guardado >> multijugador.humano;
    guardado >> multijugador.pistola;
    guardado >> multijugador.record_victorias;
    guardado >> multijugador.record_empates;
    guardado >> multijugador.record_derrotas;
    guardado >> multijugador.acumula_victorias;
    guardado >> multijugador.acumula_empates;
    guardado >> multijugador.acumula_derrotas;
    guardado >> multijugador.totales;
    guardado >> multijugador.casuales;
    guardado >> multijugador.casuales_infinito;
    guardado >> multijugador.casuales_limite;
    guardado >> multijugador.casuales_hasta;
    guardado >> multijugador.casuales_tira_afloja;
    guardado >> multijugador.competitivo;
    guardado >> multijugador.competitivo_hasta_10;
    guardado >> multijugador.competitivo_hasta_25;
    guardado >> multijugador.competitivo_primero_5;
    guardado >> multijugador.competitivo_primero_10;
    guardado >> multijugador.competitivo_diferencia_3;
    guardado >> multijugador.competitivo_diferencia_5;
    guardado >> multijugador.puntos_hasta;
    guardado >> multijugador.puntos_primero;
    guardado >> multijugador.puntos_diferencia;
    guardado >> multijugador.extra;
    guardado >> multijugador.extra_cinco_movimientos;
    guardado >> multijugador.extra_siete_movimientos;
    guardado >> multijugador.extra_nueve_movimientos;
    guardado >> multijugador.ul_casual_primero;
    guardado >> multijugador.ul_casual_tira_afloja;
    guardado >> multijugador.ul_casual_infinito;
    guardado >> multijugador.ul_cinco_movimientos;
    guardado >> multijugador.ul_siete_movimientos;
    guardado >> multijugador.ul_nueve_movimientos;
    for(int i = 0; i < estadisticas.tamano_apodo; i++) guardado >> estadisticas.estado_apodos[i];

    guardado.close();
}

void crear_mp(stats& estadisticas, stats& multijugador){
    ofstream loadeado("mp.save");
    
    loadeado << estadisticas.nombre << endl;
    loadeado << estadisticas.dinero << endl;
    loadeado << estadisticas.victorias << endl;
    loadeado << estadisticas.empates << endl;
    loadeado << estadisticas.derrotas << endl;
    loadeado << estadisticas.partidas_ganadas << endl;
    loadeado << estadisticas.partidas_empatadas << endl;
    loadeado << estadisticas.partidas_perdidas << endl;
    loadeado << estadisticas.piedra << endl;
    loadeado << estadisticas.papel << endl;
    loadeado << estadisticas.tijera << endl;
    loadeado << estadisticas.lagarto << endl;
    loadeado << estadisticas.spock << endl;
    loadeado << estadisticas.fuego << endl;
    loadeado << estadisticas.esponja << endl;
    loadeado << estadisticas.aire << endl;
    loadeado << estadisticas.agua << endl;
    loadeado << estadisticas.humano << endl;
    loadeado << estadisticas.pistola << endl;
    loadeado << estadisticas.record_victorias << endl;
    loadeado << estadisticas.record_empates << endl;
    loadeado << estadisticas.record_derrotas << endl;
    loadeado << estadisticas.acumula_victorias << endl;
    loadeado << estadisticas.acumula_empates << endl;
    loadeado << estadisticas.acumula_derrotas << endl;
    loadeado << estadisticas.totales << endl;
    loadeado << estadisticas.casuales << endl;
    loadeado << estadisticas.casuales_infinito << endl;
    loadeado << estadisticas.casuales_limite << endl;
    loadeado << estadisticas.casuales_hasta << endl;
    loadeado << estadisticas.casuales_tira_afloja << endl;
    loadeado << estadisticas.competitivo << endl;
    loadeado << estadisticas.competitivo_hasta_10 << endl;
    loadeado << estadisticas.competitivo_hasta_25 << endl;
    loadeado << estadisticas.competitivo_primero_5 << endl;
    loadeado << estadisticas.competitivo_primero_10 << endl;
    loadeado << estadisticas.competitivo_diferencia_3 << endl;
    loadeado << estadisticas.competitivo_diferencia_5 << endl;
    loadeado << estadisticas.puntos_hasta << endl;
    loadeado << estadisticas.puntos_primero << endl;
    loadeado << estadisticas.puntos_diferencia << endl;
    loadeado << estadisticas.extra << endl;
    loadeado << estadisticas.extra_cinco_movimientos << endl;
    loadeado << estadisticas.extra_siete_movimientos << endl;
    loadeado << estadisticas.extra_nueve_movimientos << endl;
    loadeado << estadisticas.ul_casual_primero << endl;
    loadeado << estadisticas.ul_casual_tira_afloja << endl;
    loadeado << estadisticas.ul_casual_infinito << endl;
    loadeado << estadisticas.ul_cinco_movimientos << endl;
    loadeado << estadisticas.ul_siete_movimientos << endl;
    loadeado << estadisticas.ul_nueve_movimientos << endl;
    for(int i = 0; i < estadisticas.tamano_apodo; i++) loadeado << estadisticas.estado_apodos[i] << endl;

    loadeado.close();
}

void save_stats_mp(stats& estadisticas, stats& multijugador){
    ofstream loadeado("mp.save");
    
    loadeado << multijugador.nombre << endl;
    loadeado << multijugador.dinero << endl;
    loadeado << multijugador.victorias << endl;
    loadeado << multijugador.empates << endl;
    loadeado << multijugador.derrotas << endl;
    loadeado << multijugador.partidas_ganadas << endl;
    loadeado << multijugador.partidas_empatadas << endl;
    loadeado << multijugador.partidas_perdidas << endl;
    loadeado << multijugador.piedra << endl;
    loadeado << multijugador.papel << endl;
    loadeado << multijugador.tijera << endl;
    loadeado << multijugador.lagarto << endl;
    loadeado << multijugador.spock << endl;
    loadeado << multijugador.fuego << endl;
    loadeado << multijugador.esponja << endl;
    loadeado << multijugador.aire << endl;
    loadeado << multijugador.agua << endl;
    loadeado << multijugador.humano << endl;
    loadeado << multijugador.pistola << endl;
    loadeado << multijugador.record_victorias << endl;
    loadeado << multijugador.record_empates << endl;
    loadeado << multijugador.record_derrotas << endl;
    loadeado << multijugador.acumula_victorias << endl;
    loadeado << multijugador.acumula_empates << endl;
    loadeado << multijugador.acumula_derrotas << endl;
    loadeado << multijugador.totales << endl;
    loadeado << multijugador.casuales << endl;
    loadeado << multijugador.casuales_infinito << endl;
    loadeado << multijugador.casuales_limite << endl;
    loadeado << multijugador.casuales_hasta << endl;
    loadeado << multijugador.casuales_tira_afloja << endl;
    loadeado << multijugador.competitivo << endl;
    loadeado << multijugador.competitivo_hasta_10 << endl;
    loadeado << multijugador.competitivo_hasta_25 << endl;
    loadeado << multijugador.competitivo_primero_5 << endl;
    loadeado << multijugador.competitivo_primero_10 << endl;
    loadeado << multijugador.competitivo_diferencia_3 << endl;
    loadeado << multijugador.competitivo_diferencia_5 << endl;
    loadeado << multijugador.puntos_hasta << endl;
    loadeado << multijugador.puntos_primero << endl;
    loadeado << multijugador.puntos_diferencia << endl;
    loadeado << multijugador.extra << endl;
    loadeado << multijugador.extra_cinco_movimientos << endl;
    loadeado << multijugador.extra_siete_movimientos << endl;
    loadeado << multijugador.extra_nueve_movimientos << endl;
    loadeado << multijugador.ul_casual_primero << endl;
    loadeado << multijugador.ul_casual_tira_afloja << endl;
    loadeado << multijugador.ul_casual_infinito << endl;
    loadeado << multijugador.ul_cinco_movimientos << endl;
    loadeado << multijugador.ul_siete_movimientos << endl;
    loadeado << multijugador.ul_nueve_movimientos << endl;
    for(int i = 0; i < estadisticas.tamano_apodo; i++) loadeado << estadisticas.estado_apodos[i] << endl;

    loadeado.close();
}

void mp_estadisticas(stats& estadisticas, stats& multijugador)
{
    cout << "Creditos: " << multijugador.dinero << "c" << endl;

    cout << endl;
    
    cout << "Victorias: " << multijugador.victorias << endl;
    cout << "Empates: " << multijugador.empates << endl;
    cout << "Derrotas: " << multijugador.derrotas << endl;
    
    cout << endl;
    
    cout << "Partidas ganadas: " << multijugador.partidas_ganadas << endl;
    cout << "Partidas empatadas: " << multijugador.partidas_empatadas << endl;
    cout << "Partidas perdidas: " << multijugador.partidas_perdidas << endl;
    
    cout << endl;
    
    cout << "Veces utilizado piedra: " << multijugador.piedra << endl;
    cout << "Veces utilizado papel: " << multijugador.papel << endl;
    cout << "Veces utilizado tijera: " << multijugador.tijera << endl;
    cout << "Veces utilizado lagarto: " << multijugador.lagarto << endl;
    cout << "Veces utilizado Spock: " << multijugador.spock << endl;
    cout << "Veces utilizado fuego: " << multijugador.fuego << endl;
    cout << "Veces utilizado esponja: " << multijugador.esponja << endl;
    cout << "Veces utilizado aire: " << multijugador.aire << endl;
    cout << "Veces utilizado agua: " << multijugador.agua << endl;
    cout << "Veces utilizado humano: " << multijugador.humano << endl;
    cout << "Veces utilizado pistola: " << multijugador.pistola << endl;
    
    cout << endl;
    
    cout << "Racha de victorias mas larga: " << multijugador.record_victorias << endl;
    cout << "Racha de empates mas larga: " << multijugador.record_empates << endl;
    cout << "Racha de derrotas mas larga: " << multijugador.record_derrotas << endl;
    
    cout << endl;
    
    cout << "Partidas totales: " << multijugador.totales << endl;
    
    cout << endl;
    
    cout << "Partidas casuales: " << multijugador.casuales << endl;
    cout << "Partidas casuales infinitas: " << multijugador.casuales_infinito << endl;
    cout << "Partidas casuales limitadas: " << multijugador.casuales_limite << endl;
    cout << "Partidas casuales primero a: " << multijugador.casuales_hasta << endl;
    cout << "Partidas casuales tira y afloja: " << multijugador.casuales_tira_afloja << endl;
    
    cout << endl;
    
    cout << "Partidas competitivo: " << multijugador.competitivo << endl;
    cout << "Partidas competitivas hasta 10: " << multijugador.competitivo_hasta_10 << endl;
    cout << "Partidas competitivas hasta 25: " << multijugador.competitivo_hasta_25 << endl;
    cout << "Partidas competitivas primero a 5: " << multijugador.competitivo_primero_5 << endl;
    cout << "Partidas competitivas primero a 10: " << multijugador.competitivo_primero_10 << endl;
    cout << "Partidas competitivas diferencia de 3: " << multijugador.competitivo_diferencia_3 << endl;
    cout << "Partidas competitivas direfencia de 5: " << multijugador.competitivo_diferencia_5 << endl;
    
    cout << endl;
    
    cout << "Puntos en competitivas hasta: " << multijugador.puntos_hasta << endl;
    cout << "Puntos en competitivas primero: " << multijugador.puntos_primero << endl;
    cout << "Puntos en competitivas diferencia: " << multijugador.puntos_diferencia << endl;
    
    cout << endl;
    
    cout << "Partidas de modos extra: " << multijugador.extra << endl;
    cout << "Partidas de piedra, papel, tijera, lagarto, Spock: " << multijugador.extra_cinco_movimientos << endl;
    cout << "Partidas de siete movimientos: " << multijugador.extra_siete_movimientos << endl;
    cout << "Partidas de nueve movimientos: " << multijugador.extra_nueve_movimientos << endl;
    
    cout << endl;
}

void mp_cuentas(stats& estadisticas, stats& multijugador)
{
    int accion;
    int numero_cuenta;
    
    cout << "Escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Cargar archivo multijugador" << endl;
    cout << "2. Crear archivo multijugador de tus estadisticas" << endl;
    cout << "3. Guardar estadisticas de multijugador" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: add_cuentas(estadisticas, multijugador); break;
        case 2: crear_mp(estadisticas, multijugador); break;
        case 3: save_stats_mp(estadisticas, multijugador); break;
    }
}

void multijugador_menu(stats& estadisticas, stats& multijugador)
{
    int accion;

    desbloqueo_apodos(multijugador);
    
    cout << "Escribe el numero de la accion que quieres realizar: " << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Estadisticas de multijugador" << endl;
    cout << "3. Gestionar cuentas" << endl;
    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: play_multijugador_menu(estadisticas, multijugador); break;
        case 2: mp_estadisticas(estadisticas, multijugador); break;
        case 3: mp_cuentas(estadisticas, multijugador); break;
    }

    if(accion != 0) multijugador_menu(estadisticas, multijugador);
}
