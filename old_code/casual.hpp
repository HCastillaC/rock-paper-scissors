#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void tira_afloja(stats& estadisticas)
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
    
    int limite;
    
    cout << "Escribe la diferencia que gana la partida: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.casuales++;
    estadisticas.casuales_tira_afloja++;
    
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
        estadisticas.dinero += 20;
        
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

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) tira_afloja(estadisticas);
    else cout << endl;
}

void primero(stats& estadisticas)
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
    
    int limite;
    
    cout << "Escribe el número de rondas a ganar: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.casuales++;
    estadisticas.casuales_hasta++;
    
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
        estadisticas.dinero += 20;
        
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
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado la partida " <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) primero(estadisticas);
    else cout << endl;
}

void limitado(stats& estadisticas)
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
    
    int limite;
    
    cout << "Escribe el número de rondas: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.casuales++;
    estadisticas.casuales_limite++;
    
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
        
        cout << "Has perdido la partida " <<
        victorias_jugador << " - " << victorias_bot <<
        " (empates: " << empates << ")" << endl;
    }
    if(victorias_jugador > victorias_bot){
        estadisticas.partidas_ganadas++;
        estadisticas.dinero += 20;
        
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
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado la partida " <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) limitado(estadisticas);
    else cout << endl;
}

void infinito(stats& estadisticas)
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
    estadisticas.casuales++;
    estadisticas.casuales_infinito++;
    
    while(movimiento_jugador != -1){
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
        if(movimiento_jugador == -1){
            if(victorias_jugador < victorias_bot){
                estadisticas.partidas_perdidas++;
                
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
                
                cout << "Has perdido la partida " <<
                victorias_jugador << " - " << victorias_bot <<
                " (empates: " << empates << ")" << endl;
            }
            if(victorias_jugador > victorias_bot){
                estadisticas.partidas_ganadas++;
                
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
                
                cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has empatado la partida " <<
                victorias_jugador <<
                " (empates: " << empates << ")" << endl;
            }
            cout << endl;

            cout << "¿Quieres volver a jugar?" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cin >> movimiento_jugador;
            cout << endl;

            if(movimiento_jugador == 1) infinito(estadisticas);
            else cout << endl;
            break;
        } 
        
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
}

void casual_menu(stats& estadisticas)
{
    int accion;
    
    cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;

    cout << "1. Hasta..." << endl;

    if(estadisticas.ul_casual_primero == 1) cout << "2. Primero a..." << endl;
    else cout << "2. <Desbloquea este modo en la tienda>" << endl;

    if(estadisticas.ul_casual_tira_afloja == 1) cout << "3. Tira y afloja" << endl;
    else cout << "3. <Desbloquea este modo en la tienda>" << endl;

    if(estadisticas.ul_casual_infinito == 1) cout << "4. Infinito" << endl;
    else cout << "4. <Desbloquea este modo en la tienda>" << endl;

    cout << "0. Salir" << endl;
    
    cin >> accion;
    cout << endl;
    
    switch(accion){
        case 1: limitado(estadisticas); break;
        case 2: 
            if(estadisticas.ul_casual_primero == 1) primero(estadisticas);
            else cout << "Aun no has desbloqueado este modo. Dirigete a la tienda para desbloquearlo (150c) " << endl << endl;
            break;
        case 3: 
            if(estadisticas.ul_casual_tira_afloja == 1) tira_afloja(estadisticas);
            else cout << "Aun no has desbloqueado este modo. Dirigete a la tienda para desbloquearlo (250c) " << endl << endl;
            break;
        case 4: 
            if(estadisticas.ul_casual_infinito == 1) infinito(estadisticas);
            else cout << "Aun no has desbloqueado este modo. Dirigete a la tienda para desbloquearlo (500c) " << endl << endl;
            break;
    }
}
