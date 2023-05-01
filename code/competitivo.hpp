#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void competitivo_hasta(stats& estadisticas, int limite)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot;
    
    string movimientos[3] = {"Piedra", "Papel", "Tijera"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int racha_victorias = 0;
    int racha_empates = 0;
    int racha_derrotas = 0;
    
    estadisticas.totales++;
    estadisticas.competitivo++;
    if(limite == 10) estadisticas.competitivo_hasta_10++;
    if(limite == 25) estadisticas.competitivo_hasta_25++;
    
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
        
        movimiento_bot = rand();
        movimiento_bot %= 3;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        if((movimiento_jugador == 0 and movimiento_bot == 1) or
        (movimiento_jugador == 1 and movimiento_bot == 2) or
        (movimiento_jugador == 2 and movimiento_bot == 0)){
            victorias_bot++;
            estadisticas.derrotas++;
            estadisticas.puntos_hasta--;
            racha_derrotas++;
            
            if(racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = racha_empates;
            } 
            racha_empates = 0;
            if(racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = racha_victorias;
            } 
            racha_victorias = 0;
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else if((movimiento_jugador == 1 and movimiento_bot == 0) or
        (movimiento_jugador == 2 and movimiento_bot == 1) or
        (movimiento_jugador == 0 and movimiento_bot == 2)){
            victorias_jugador++;
            estadisticas.victorias++;
            estadisticas.puntos_hasta++;
            racha_victorias++;
            
            if(racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = racha_empates;
            } 
            racha_empates = 0;
            if(racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = racha_derrotas;
            } 
            racha_derrotas = 0;
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else{
            empates++;
            estadisticas.empates++;
            racha_empates++;
            
            if(racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = racha_derrotas;
            } 
            racha_derrotas = 0;
            if(racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = racha_victorias;
            } 
            racha_victorias = 0;
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        movimiento_jugador = -3;
        cout << endl;
    }
    
    if(victorias_jugador < victorias_bot){
        estadisticas.partidas_perdidas++;
        estadisticas.puntos_hasta -= 10;
        estadisticas.dinero -= 10;
        if(estadisticas.dinero < 0) estadisticas.dinero = 0;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_derrotas = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador > victorias_bot){
        estadisticas.partidas_ganadas++;
        estadisticas.puntos_hasta += 10;
        estadisticas.dinero += 50;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_victorias = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador == victorias_bot){
        estadisticas.partidas_empatadas++;
        estadisticas.dinero += 5;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_empates = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado la partida a " <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;
    
    if(estadisticas.puntos_hasta >= 100) estadisticas.ul_competitivo_ganador25 = 1;
    if(estadisticas.puntos_hasta >= 250) estadisticas.ul_competitivo_primero5 = 1;

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) competitivo_hasta(estadisticas, limite);
    else cout << endl;
}

void competitivo_primero(stats& estadisticas, int limite)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot;
    
    string movimientos[3] = {"Piedra", "Papel", "Tijera"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int racha_victorias = 0;
    int racha_empates = 0;
    int racha_derrotas = 0;
    
    estadisticas.totales++;
    estadisticas.competitivo++;
    
    if(limite == 5) estadisticas.competitivo_primero_5++;
    if(limite == 10) estadisticas.competitivo_primero_10++;
    
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
        
        movimiento_bot = rand();
        movimiento_bot %= 3;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        if((movimiento_jugador == 0 and movimiento_bot == 1) or
        (movimiento_jugador == 1 and movimiento_bot == 2) or
        (movimiento_jugador == 2 and movimiento_bot == 0)){
            victorias_bot++;
            estadisticas.derrotas++;
            estadisticas.puntos_primero--;
            racha_derrotas++;
            
            if(racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = racha_empates;
            } 
            racha_empates = 0;
            if(racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = racha_victorias;
            } 
            racha_victorias = 0;
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else if((movimiento_jugador == 1 and movimiento_bot == 0) or
        (movimiento_jugador == 2 and movimiento_bot == 1) or
        (movimiento_jugador == 0 and movimiento_bot == 2)){
            victorias_jugador++;
            estadisticas.victorias++;
            estadisticas.puntos_primero++;
            racha_victorias++;
            
            if(racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = racha_empates;
            } 
            racha_empates = 0;
            if(racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = racha_derrotas;
            } 
            racha_derrotas = 0;
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else{
            empates++;
            estadisticas.empates++;
            racha_empates++;
            
            if(racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = racha_derrotas;
            } 
            racha_derrotas = 0;
            if(racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = racha_victorias;
            } 
            racha_victorias = 0;
            
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        movimiento_jugador = -3;
        cout << endl;
    }
    
    if(victorias_jugador < victorias_bot){
        estadisticas.partidas_perdidas++;
        estadisticas.puntos_primero -= 10;
        estadisticas.dinero -= 10;
        if(estadisticas.dinero < 0) estadisticas.dinero = 0;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_derrotas = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador > victorias_bot){
        estadisticas.partidas_ganadas++;
        estadisticas.puntos_primero += 10;
        estadisticas.dinero += 50;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_victorias = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador == victorias_bot){
        estadisticas.partidas_empatadas++;
        estadisticas.dinero += 5;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_empates = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado la partida a " <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;

    if(estadisticas.puntos_primero >= 100) estadisticas.ul_competitivo_primero10 = 1;
    if(estadisticas.puntos_primero >= 250) estadisticas.ul_competitivo_diferencia3 = 1;

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) competitivo_primero(estadisticas, limite);
    else cout << endl;
}

void competitivo_tira_afloja(stats& estadisticas, int limite)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot;
    
    string movimientos[3] = {"Piedra", "Papel", "Tijera"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int racha_victorias = 0;
    int racha_empates = 0;
    int racha_derrotas = 0;
    
    estadisticas.totales++;
    estadisticas.competitivo++;
    
    if(limite == 3) estadisticas.competitivo_diferencia_3++;
    if(limite == 5) estadisticas.competitivo_diferencia_5++;
    
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
        
        movimiento_bot = rand();
        movimiento_bot %= 3;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        if((movimiento_jugador == 0 and movimiento_bot == 1) or
        (movimiento_jugador == 1 and movimiento_bot == 2) or
        (movimiento_jugador == 2 and movimiento_bot == 0)){
            victorias_bot++;
            estadisticas.derrotas++;
            estadisticas.puntos_diferencia--;
            racha_derrotas++;
            
            if(racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = racha_empates;
            } 
            racha_empates = 0;
            if(racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = racha_victorias;
            } 
            racha_victorias = 0;
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else if((movimiento_jugador == 1 and movimiento_bot == 0) or
        (movimiento_jugador == 2 and movimiento_bot == 1) or
        (movimiento_jugador == 0 and movimiento_bot == 2)){
            victorias_jugador++;
            estadisticas.victorias++;
            estadisticas.puntos_diferencia++;
            racha_victorias++;
            
            if(racha_empates > estadisticas.record_empates){
                if(estadisticas.acumula_empates == 1){
                    estadisticas.record_empates += racha_empates;
                    estadisticas.acumula_empates = 0;
                }
                else estadisticas.record_empates = racha_empates;
            } 
            racha_empates = 0;
            if(racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = racha_derrotas;
            } 
            racha_derrotas = 0;
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        else{
            empates++;
            estadisticas.empates++;
            racha_empates++;
            
            if(racha_derrotas > estadisticas.record_derrotas){
                if(estadisticas.acumula_derrotas == 1){
                    estadisticas.record_derrotas += racha_derrotas;
                    estadisticas.acumula_derrotas = 0;
                }
                else estadisticas.record_derrotas = racha_derrotas;
            } 
            racha_derrotas = 0;
            if(racha_victorias > estadisticas.record_victorias){
                if(estadisticas.acumula_victorias == 1){
                    estadisticas.record_victorias += racha_victorias;
                    estadisticas.acumula_victorias = 0;
                }
                else estadisticas.record_victorias = racha_victorias;
            } 
            racha_victorias = 0;
            
            
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado" << endl;
            cout << "El marcador va " << victorias_jugador << " - " << victorias_bot << endl;
        }
        
        movimiento_jugador = -3;
        cout << endl;
    }
    
    if(victorias_jugador < victorias_bot){
        estadisticas.partidas_perdidas++;
        estadisticas.puntos_diferencia -= 10;
        estadisticas.dinero -= 10;
        if(estadisticas.dinero < 0) estadisticas.dinero = 0;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_derrotas = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador > victorias_bot){
        estadisticas.partidas_ganadas++;
        estadisticas.puntos_diferencia += 10;
        estadisticas.dinero += 50;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_victorias = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador == victorias_bot){
        estadisticas.partidas_empatadas++;
        estadisticas.dinero += 10;
        
        if(racha_derrotas > estadisticas.record_derrotas){
            if(estadisticas.acumula_derrotas == 1) estadisticas.record_derrotas += racha_derrotas;
            else estadisticas.record_derrotas = racha_derrotas;
        }
        if(racha_empates > estadisticas.record_empates){
            if(estadisticas.acumula_empates == 1) estadisticas.record_empates += racha_empates;
            else estadisticas.record_empates = racha_empates;
        } 
        if(racha_victorias > estadisticas.record_victorias){
            if(estadisticas.acumula_victorias == 1) estadisticas.record_victorias += racha_victorias;
            else estadisticas.record_victorias = racha_victorias;
        } 
        estadisticas.acumula_empates = 1;
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado la partida a " <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;
    
    if(estadisticas.puntos_diferencia >= 100) estadisticas.ul_competitivo_diferencia5 = 1;

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) competitivo_tira_afloja(estadisticas, limite);
    else cout << endl;
}

void competitivo_menu(stats& estadisticas){
    
    int accion;
    
    if(estadisticas.puntos_hasta >= 100) estadisticas.ul_competitivo_ganador25 = 1;
    if(estadisticas.puntos_hasta >= 250) estadisticas.ul_competitivo_primero5 = 1;
    if(estadisticas.puntos_primero >= 100) estadisticas.ul_competitivo_primero10 = 1;
    if(estadisticas.puntos_primero >= 250) estadisticas.ul_competitivo_diferencia3 = 1;
    if(estadisticas.puntos_diferencia >= 100) estadisticas.ul_competitivo_diferencia5 = 1;

    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
    cout << "1. Ganador a 10 partidas" << endl;

    if(estadisticas.ul_competitivo_ganador25 == 1) cout << "2. Ganador a 25 partidas" << endl;
    else cout << "2. <Consigue 100 puntos en ganador a...>" << endl;

    if(estadisticas.ul_casual_primero == 1) cout << "3. Primero en ganar 5 partidas" << endl;
    else cout << "3. <Consigue 250 puntos en ganador a...>" << endl;

    if(estadisticas.ul_casual_primero == 1) cout << "4. Primero en ganar 10 partidas" << endl;
    else cout << "4. <Consigue 100 puntos en primero en ganar a...>" << endl;

    if(estadisticas.ul_casual_primero == 1) cout << "5. Ganador a diferencia de 3" << endl;
    else cout << "4. <Consigue 250 puntos en primero en ganar a...>" << endl;

    if(estadisticas.ul_casual_primero == 1) cout << "6. Ganador a diferencia de 5" << endl;
    else cout << "6. <Consigue 100 puntos en diferencia de...>" << endl;

    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: competitivo_hasta(estadisticas, 10); break;
        case 2: 
            if(estadisticas.ul_competitivo_ganador25 == 1) competitivo_hasta(estadisticas, 25);
            else cout << "Aun no has desbloqueado este modo, juega mas competivo " << endl << endl;
            break;
        case 3: 
            if(estadisticas.ul_competitivo_primero5 == 1) competitivo_primero(estadisticas, 5);
            else cout << "Aun no has desbloqueado este modo, juega mas competivo " << endl << endl;
            break;
        case 4: 
            if(estadisticas.ul_competitivo_primero10 == 1) competitivo_primero(estadisticas, 10);
            else cout << "Aun no has desbloqueado este modo, juega mas competivo " << endl << endl;
            break;
        case 5: 
            if(estadisticas.ul_competitivo_diferencia3 == 1) competitivo_tira_afloja(estadisticas, 3);
            else cout << "Aun no has desbloqueado este modo, juega mas competivo " << endl << endl;
            break;
        case 6: 
            if(estadisticas.ul_competitivo_diferencia5 == 1) competitivo_tira_afloja(estadisticas, 5);
            else cout << "Aun no has desbloqueado este modo, juega mas competivo " << endl << endl;
            break;
    }
}
