#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

void siete_movimientos_tira_afloja(stats& estadisticas)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot;
    
    string movimientos[7] = {"Piedra", "Fuego", "Tijera", "Esponja", "Papel", "Aire", "Agua"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int racha_victorias = 0;
    int racha_empates = 0;
    int racha_derrotas = 0;
    
    int ganador = 0; //0 = bot; 1 = jugador; 2 = empate
    
    int limite;
    
    cout << "Escribe el número de rondas: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.extra++;
    estadisticas.extra_siete_movimientos++;
    
    while(limite > victorias_jugador - victorias_bot and limite > victorias_bot - victorias_jugador){
        while(movimiento_jugador > 8 or movimiento_jugador < -1){
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Fuego" << endl;
            cout << "3. Tijera" << endl;
            cout << "4. Esponja" << endl;
            cout << "5. Papel" << endl;
            cout << "6. Aire" << endl;
            cout << "7. Agua" << endl;
            
            cin >> movimiento_jugador;
        }
        
        switch(movimiento_jugador){
            case 1: estadisticas.piedra++; break;
            case 2: estadisticas.fuego++; break;
            case 3: estadisticas.tijera++; break;
            case 4: estadisticas.esponja++; break;
            case 5: estadisticas.papel++; break;
            case 6: estadisticas.aire++; break;
            case 7: estadisticas.agua++; break;
        }
        
        movimiento_jugador--;
        
        movimiento_bot = rand();
        movimiento_bot %= 7;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        ganador = quien_gana(movimiento_jugador, movimiento_bot, 7);
        
        if(ganador == 0){
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
        
        else if(ganador == 1){
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
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado la partida " <<
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
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido" <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) siete_movimientos_tira_afloja(estadisticas);
    else cout << endl;
}

void siete_movimientos_primero(stats& estadisticas)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot;
    
    string movimientos[7] = {"Piedra", "Fuego", "Tijera", "Esponja", "Papel", "Aire", "Agua"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int racha_victorias = 0;
    int racha_empates = 0;
    int racha_derrotas = 0;
    
    int ganador = 0; //0 = bot; 1 = jugador; 2 = empate
    
    int limite;
    
    cout << "Escribe el número de rondas: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.extra++;
    estadisticas.extra_siete_movimientos++;
    
    while(limite > victorias_jugador and limite > victorias_bot){
        while(movimiento_jugador > 8 or movimiento_jugador < -1){
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Fuego" << endl;
            cout << "3. Tijera" << endl;
            cout << "4. Esponja" << endl;
            cout << "5. Papel" << endl;
            cout << "6. Aire" << endl;
            cout << "7. Agua" << endl;
            
            cin >> movimiento_jugador;
        }
        
        switch(movimiento_jugador){
            case 1: estadisticas.piedra++; break;
            case 2: estadisticas.fuego++; break;
            case 3: estadisticas.tijera++; break;
            case 4: estadisticas.esponja++; break;
            case 5: estadisticas.papel++; break;
            case 6: estadisticas.aire++; break;
            case 7: estadisticas.agua++; break;
        }
        
        movimiento_jugador--;
        
        movimiento_bot = rand();
        movimiento_bot %= 7;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        ganador = quien_gana(movimiento_jugador, movimiento_bot, 7);
        
        if(ganador == 0){
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
        
        else if(ganador == 1){
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
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado la partida " <<
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
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido" <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) siete_movimientos_primero(estadisticas);
    else cout << endl;
}

void siete_movimientos_hasta(stats& estadisticas)
{
    srand(time(nullptr));
    
    int movimiento_jugador = -3;
    int movimiento_bot;
    
    string movimientos[7] = {"Piedra", "Fuego", "Tijera", "Esponja", "Papel", "Aire", "Agua"};
    
    int victorias_jugador = 0;
    int victorias_bot = 0;
    int empates = 0;
    
    int racha_victorias = 0;
    int racha_empates = 0;
    int racha_derrotas = 0;
    
    int ganador = 0; //0 = bot; 1 = jugador; 2 = empate
    
    int limite;
    
    cout << "Escribe el número de rondas: ";
    cin >> limite;
    cout << endl;
    
    estadisticas.totales++;
    estadisticas.extra++;
    estadisticas.extra_siete_movimientos++;
    
    for(int i = 0; i < limite; i++){
        while(movimiento_jugador > 8 or movimiento_jugador < -1){
            cout << estadisticas.apodo_actual << estadisticas.nombre << " " << "escribe el número de la accion que quieres realizar: " << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Fuego" << endl;
            cout << "3. Tijera" << endl;
            cout << "4. Esponja" << endl;
            cout << "5. Papel" << endl;
            cout << "6. Aire" << endl;
            cout << "7. Agua" << endl;
            
            cin >> movimiento_jugador;
        }
        
        switch(movimiento_jugador){
            case 1: estadisticas.piedra++; break;
            case 2: estadisticas.fuego++; break;
            case 3: estadisticas.tijera++; break;
            case 4: estadisticas.esponja++; break;
            case 5: estadisticas.papel++; break;
            case 6: estadisticas.aire++; break;
            case 7: estadisticas.agua++; break;
        }
        
        movimiento_jugador--;
        
        movimiento_bot = rand();
        movimiento_bot %= 7;
        
        cout << movimientos[movimiento_jugador];
        cout << " vs. ";
        cout << movimientos[movimiento_bot] << endl;
        
        ganador = quien_gana(movimiento_jugador, movimiento_bot, 7);
        
        if(ganador == 0){
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
        
        else if(ganador == 1){
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
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has ganado la partida " <<
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
        
        cout << estadisticas.apodo_actual << estadisticas.nombre << " " << ", has perdido" <<
        victorias_jugador <<
        " (empates: " << empates << ")" << endl;
    }
    cout << endl;

    cout << "¿Quieres volver a jugar?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> movimiento_jugador;
    cout << endl;
    
    if(movimiento_jugador == 1) siete_movimientos_hasta(estadisticas);
    else cout << endl;
}
