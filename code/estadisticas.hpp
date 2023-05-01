#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void stats_general(stats& estadisticas)
{
    cout << "Creditos: " << estadisticas.dinero << "c" << endl;

    cout << endl;
    
    cout << "Victorias: " << estadisticas.victorias << endl;
    cout << "Empates: " << estadisticas.empates << endl;
    cout << "Derrotas: " << estadisticas.derrotas << endl;
    
    cout << endl;
    
    cout << "Partidas ganadas: " << estadisticas.partidas_ganadas << endl;
    cout << "Partidas empatadas: " << estadisticas.partidas_empatadas << endl;
    cout << "Partidas perdidas: " << estadisticas.partidas_perdidas << endl;
    
    cout << endl;
    
    cout << "Veces utilizado piedra: " << estadisticas.piedra << endl;
    cout << "Veces utilizado papel: " << estadisticas.papel << endl;
    cout << "Veces utilizado tijera: " << estadisticas.tijera << endl;
    cout << "Veces utilizado lagarto: " << estadisticas.lagarto << endl;
    cout << "Veces utilizado Spock: " << estadisticas.spock << endl;
    cout << "Veces utilizado fuego: " << estadisticas.fuego << endl;
    cout << "Veces utilizado esponja: " << estadisticas.esponja << endl;
    cout << "Veces utilizado aire: " << estadisticas.aire << endl;
    cout << "Veces utilizado agua: " << estadisticas.agua << endl;
    cout << "Veces utilizado humano: " << estadisticas.humano << endl;
    cout << "Veces utilizado pistola: " << estadisticas.pistola << endl;
    
    cout << endl;
    
    cout << "Racha de victorias mas larga: " << estadisticas.record_victorias << endl;
    cout << "Racha de empates mas larga: " << estadisticas.record_empates << endl;
    cout << "Racha de derrotas mas larga: " << estadisticas.record_derrotas << endl;
    
    cout << endl;
    
    cout << "Partidas totales: " << estadisticas.totales << endl;
    
    cout << endl;
    
    cout << "Partidas casuales: " << estadisticas.casuales << endl;
    cout << "Partidas casuales infinitas: " << estadisticas.casuales_infinito << endl;
    cout << "Partidas casuales limitadas: " << estadisticas.casuales_limite << endl;
    cout << "Partidas casuales primero a: " << estadisticas.casuales_hasta << endl;
    cout << "Partidas casuales tira y afloja: " << estadisticas.casuales_tira_afloja << endl;
    
    cout << endl;
    
    cout << "Partidas competitivo: " << estadisticas.competitivo << endl;
    cout << "Partidas competitivas hasta 10: " << estadisticas.competitivo_hasta_10 << endl;
    cout << "Partidas competitivas hasta 25: " << estadisticas.competitivo_hasta_25 << endl;
    cout << "Partidas competitivas primero a 5: " << estadisticas.competitivo_primero_5 << endl;
    cout << "Partidas competitivas primero a 10: " << estadisticas.competitivo_primero_10 << endl;
    cout << "Partidas competitivas diferencia de 3: " << estadisticas.competitivo_diferencia_3 << endl;
    cout << "Partidas competitivas direfencia de 5: " << estadisticas.competitivo_diferencia_5 << endl;
    
    cout << endl;
    
    cout << "Puntos en competitivas hasta: " << estadisticas.puntos_hasta << endl;
    cout << "Puntos en competitivas primero: " << estadisticas.puntos_primero << endl;
    cout << "Puntos en competitivas diferencia: " << estadisticas.puntos_diferencia << endl;
    
    cout << endl;
    
    cout << "Partidas de modos extra: " << estadisticas.extra << endl;
    cout << "Partidas de piedra, papel, tijera, lagarto, Spock: " << estadisticas.extra_cinco_movimientos << endl;
    cout << "Partidas de siete movimientos: " << estadisticas.extra_siete_movimientos << endl;
    cout << "Partidas de nueve movimientos: " << estadisticas.extra_nueve_movimientos << endl;
    
    cout << endl;

    cout << "Partidas de multijugador: " << estadisticas.multijugador << endl;
    cout << "Partidas de multijugador hasta: " << estadisticas.multijugador_hasta << endl;
    cout << "Partidas de multijugador primero: " << estadisticas.multijugador_primero << endl;
    cout << "Partidas de multijugador tira y afloja: " << estadisticas.multijugador_diferencia << endl;
    
    cout << endl;
}
