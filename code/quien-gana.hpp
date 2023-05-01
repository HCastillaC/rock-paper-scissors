#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int quien_gana(int movimiento_jugador1, int movimiento_jugador2, int total_opciones)
{
    int mitad;
    
    if(movimiento_jugador1 < movimiento_jugador2){
        mitad = total_opciones / 2;
        
        for(int i = movimiento_jugador1 + 1; i < movimiento_jugador1 + mitad + 1; i++){
            if(i == movimiento_jugador2) return 1;
        }
        
        return 0;
    }
    
    if(movimiento_jugador2 < movimiento_jugador1){
        mitad = total_opciones / 2;
        
        for(int i = movimiento_jugador2 + 1; i < movimiento_jugador2 + mitad + 1; i++){
            if(i == movimiento_jugador1) return 0;
        }
        
        return 1;
    }
    
    return 2;
}
