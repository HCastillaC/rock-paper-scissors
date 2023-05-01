#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class stats
{
    public:
    
    //Identificacion
    string nombre = "invitado";
    int dinero = 0;
    int tamano_apodo = 53;
    string todos_apodos[53] = {
        "Novato ", //Desde el principio

        "Fan ", //500 partidas totales
        "Milenario ", //1000 partidas totales
        "Aspirante a viciado ", //2500 partidas totales
        "Viciado ", //5000 partidas totales
        "Viciado experto ", //10000 partidas totales
        "Millonario ", //1000000 partidas totales //Si alguien consigue esto me muero

        "Jugador competitivo ", //1000 competitivo
        "Solo competitivo ", //2500 competitivo
        "Viciado de competitivo ", //5000 competitivo

        "Jugador de modos extra ", //1000 m extra
        "Solo modos extra ", //2500 m extra
        "Viciado de modos extra ", //5000 m extra

        "Multijugador ", //1000 mps
        "Solo multijugador ", //2500 mps
        "Viciado de multijugador ", //5000 mps
        "Siempre con amigos ", //10000 mps

        "Experto ", //250 partidas ganadas
        "As ", //750 partidas ganadas
        "Campeon ", //2000 partidas ganadas
        "Leyenda ", //5000 partidas ganadas

        "Indecisivo ", //250 partidas empatadas
        "Igualitario ", //750 partidas empatadas
        "Igualitario experto ", //2000 partidas empatadas

        "Desafortunado ", //250 partidas perdidas
        "Perdedor nato ", //750 partidas perdidas
        "Espiritu libre ", //2000 partidas perdidas
        "Experto en derrotas ", //5000 partidas perdidas

        "Aspirante a tijeras ", //500 usado tijera
        "Tijeras novato ", //1000 usado tijera
        "Tijeras ", //2000 usado tijera
        "Tijeras experto ", //5000 usado tijera

        "Aspirante a piedras ", //500 usado piedra
        "Piedras novato ", //1000 usado piedra
        "Piedras ", //2000 usado piedra
        "Piedras experto ", //5000 usado piedra

        "Aspirante a papeles ", //500 usado papel
        "Papeles novato ", //1000 usado papel
        "Papeles ", //2000 usado papel
        "Papeles experto ", //5000 usado papel

        "Ser animal ", //1000 usado lagarto
        "Sheldon Cooper ", //1000 usado Spock
        "Fuego ardiente ", //1000 usado fuego
        "Esponjita ", //1000 usado esponja
        "Puro oxigeno ", //1000 usado aire
        "Necesario para vivir ", //1000 usado agua
        "No soy un robot ", //1000 usado humano
        "Arma letal ", //1000 usado pistola

        "Aspirante a victorioso ", //Record victorias 10
        "Victorioso novato ", //Record victorias 25
        "Victorioso ", //Record victorias 50
        "Victorioso experto ", //Record victorias 100

        "Desarrollador " //Exculsivo para mi
    };
    //0 = Aun no se puede obtener
    //1 = Disponible en aleatorio
    //2 = Poseido
    int estado_apodos[53] = {
        2,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,
        -1,
    };
    string apodo_actual = "Novato ";
    
    //Generales
    int victorias = 0;
    int empates = 0;
    int derrotas = 0;
    
    int partidas_ganadas = 0;
    int partidas_empatadas = 0;
    int partidas_perdidas = 0;
    
    int piedra = 0;
    int papel = 0;
    int tijera = 0;
    int lagarto = 0;
    int spock = 0;
    int fuego = 0;
    int esponja = 0;
    int aire = 0;
    int agua = 0;
    int humano = 0;
    int pistola = 0;
    
    int record_victorias = 0;
    bool acumula_victorias = 0; //No printear
    int record_empates = 0;
    bool acumula_empates = 0; //No printear
    int record_derrotas = 0;
    bool acumula_derrotas = 0; //No printear
    
    //Tipos de partida jugados
    int totales = 0;
    int casuales = 0;
    int casuales_infinito = 0;
    int casuales_limite = 0;
    int casuales_hasta = 0;
    int casuales_tira_afloja = 0;
    
    int competitivo = 0;
    int competitivo_hasta_10 = 0;
    int competitivo_hasta_25 = 0;
    int competitivo_primero_5 = 0;
    int competitivo_primero_10 = 0;
    int competitivo_diferencia_3 = 0;
    int competitivo_diferencia_5 = 0;
    
    int extra = 0;
    int extra_cinco_movimientos = 0;
    int extra_siete_movimientos = 0;
    int extra_nueve_movimientos = 0;

    int multijugador = 0;
    int multijugador_hasta = 0;
    int multijugador_primero = 0;
    int multijugador_diferencia = 0;
    
    //Puntuaciones competitivo
    int puntos_hasta = 0;
    int puntos_primero = 0;
    int puntos_diferencia = 0;

    //Desbloqueos
    bool ul_casual_primero = 0;
    bool ul_casual_tira_afloja = 0;
    bool ul_casual_infinito = 0;
    bool ul_cinco_movimientos = 0;
    bool ul_siete_movimientos = 0;
    bool ul_nueve_movimientos = 0;
    bool ul_competitivo_ganador25 = 0;
    bool ul_competitivo_primero5 = 0;
    bool ul_competitivo_primero10 = 0;
    bool ul_competitivo_diferencia3 = 0;
    bool ul_competitivo_diferencia5 = 0;
};

void desbloqueo_apodos(stats& estadisticas)
{
    if(estadisticas.totales >= 500) estadisticas.estado_apodos[1] = 1;
    if(estadisticas.totales >= 1000) estadisticas.estado_apodos[2] = 1;
    if(estadisticas.totales >= 2500) estadisticas.estado_apodos[3] = 1;
    if(estadisticas.totales >= 5000) estadisticas.estado_apodos[4] = 1;
    if(estadisticas.totales >= 10000) estadisticas.estado_apodos[5] = 1;
    if(estadisticas.totales >= 1000000) estadisticas.estado_apodos[6] = 1;

    if(estadisticas.competitivo >= 1000) estadisticas.estado_apodos[7] = 1;
    if(estadisticas.competitivo >= 2500) estadisticas.estado_apodos[8] = 1;
    if(estadisticas.competitivo >= 5000) estadisticas.estado_apodos[9] = 1;
    
    if(estadisticas.extra >= 1000) estadisticas.estado_apodos[10] = 1;
    if(estadisticas.extra >= 2500) estadisticas.estado_apodos[11] = 1;
    if(estadisticas.extra >= 5000) estadisticas.estado_apodos[12] = 1;

    if(estadisticas.multijugador >= 1000) estadisticas.estado_apodos[13] = 1;
    if(estadisticas.multijugador >= 2500) estadisticas.estado_apodos[14] = 1;
    if(estadisticas.multijugador >= 5000) estadisticas.estado_apodos[15] = 1;
    if(estadisticas.multijugador >= 10000) estadisticas.estado_apodos[16] = 1;

    if(estadisticas.partidas_ganadas >= 250) estadisticas.estado_apodos[17] = 1;
    if(estadisticas.partidas_ganadas >= 750) estadisticas.estado_apodos[18] = 1;
    if(estadisticas.partidas_ganadas >= 2000) estadisticas.estado_apodos[19] = 1;
    if(estadisticas.partidas_ganadas >= 5000) estadisticas.estado_apodos[20] = 1;

    if(estadisticas.partidas_empatadas >= 250) estadisticas.estado_apodos[21] = 1;
    if(estadisticas.partidas_empatadas >= 750) estadisticas.estado_apodos[22] = 1;
    if(estadisticas.partidas_empatadas >= 2000) estadisticas.estado_apodos[23] = 1;

    if(estadisticas.partidas_perdidas >= 250) estadisticas.estado_apodos[24] = 1;
    if(estadisticas.partidas_perdidas >= 750) estadisticas.estado_apodos[25] = 1;
    if(estadisticas.partidas_perdidas >= 2000) estadisticas.estado_apodos[26] = 1;
    if(estadisticas.partidas_perdidas >= 5000) estadisticas.estado_apodos[27] = 1;

    if(estadisticas.tijera >= 500) estadisticas.estado_apodos[28] = 1;
    if(estadisticas.tijera >= 1000) estadisticas.estado_apodos[29] = 1;
    if(estadisticas.tijera >= 2000) estadisticas.estado_apodos[30] = 1;
    if(estadisticas.tijera >= 5000) estadisticas.estado_apodos[31] = 1;

    if(estadisticas.piedra >= 500) estadisticas.estado_apodos[32] = 1;
    if(estadisticas.piedra >= 1000) estadisticas.estado_apodos[33] = 1;
    if(estadisticas.piedra >= 2000) estadisticas.estado_apodos[34] = 1;
    if(estadisticas.piedra >= 5000) estadisticas.estado_apodos[35] = 1;

    if(estadisticas.papel >= 500) estadisticas.estado_apodos[36] = 1;
    if(estadisticas.papel >= 1000) estadisticas.estado_apodos[37] = 1;
    if(estadisticas.papel >= 2000) estadisticas.estado_apodos[38] = 1;
    if(estadisticas.papel >= 5000) estadisticas.estado_apodos[39] = 1;

    if(estadisticas.lagarto >= 1000) estadisticas.estado_apodos[40] = 1;
    if(estadisticas.spock >= 1000) estadisticas.estado_apodos[41] = 1;
    if(estadisticas.fuego >= 1000) estadisticas.estado_apodos[42] = 1;
    if(estadisticas.esponja >= 1000) estadisticas.estado_apodos[43] = 1;
    if(estadisticas.aire >= 1000) estadisticas.estado_apodos[44] = 1;
    if(estadisticas.agua >= 1000) estadisticas.estado_apodos[45] = 1;
    if(estadisticas.humano >= 1000) estadisticas.estado_apodos[46] = 1;
    if(estadisticas.pistola >= 1000) estadisticas.estado_apodos[47] = 1;

    if(estadisticas.record_victorias >= 10) estadisticas.estado_apodos[48] = 1;
    if(estadisticas.record_victorias >= 25) estadisticas.estado_apodos[49] = 1;
    if(estadisticas.record_victorias >= 50) estadisticas.estado_apodos[50] = 1;
    if(estadisticas.record_victorias >= 100) estadisticas.estado_apodos[51] = 1;
}

void create_profile(stats& estadisticas)
{
    cout << "Escribe tu nombre de usuario: ";
    cin >> estadisticas.nombre;
    
    cout << endl;
}

void save_stats(stats& estadisticas)
{
    ofstream guardado ("stats.save");

    guardado << estadisticas.nombre << endl;
    guardado << estadisticas.dinero << endl;
    guardado << estadisticas.victorias << endl;
    guardado << estadisticas.empates << endl;
    guardado << estadisticas.derrotas << endl;
    guardado << estadisticas.partidas_ganadas << endl;
    guardado << estadisticas.partidas_empatadas << endl;
    guardado << estadisticas.partidas_perdidas << endl;
    guardado << estadisticas.piedra << endl;
    guardado << estadisticas.papel << endl;
    guardado << estadisticas.tijera << endl;
    guardado << estadisticas.lagarto << endl;
    guardado << estadisticas.spock << endl;
    guardado << estadisticas.fuego << endl;
    guardado << estadisticas.esponja << endl;
    guardado << estadisticas.aire << endl;
    guardado << estadisticas.agua << endl;
    guardado << estadisticas.humano << endl;
    guardado << estadisticas.pistola << endl;
    guardado << estadisticas.record_victorias << endl;
    guardado << estadisticas.record_empates << endl;
    guardado << estadisticas.record_derrotas << endl;
    guardado << estadisticas.acumula_victorias << endl;
    guardado << estadisticas.acumula_empates << endl;
    guardado << estadisticas.acumula_derrotas << endl;
    guardado << estadisticas.totales << endl;
    guardado << estadisticas.casuales << endl;
    guardado << estadisticas.casuales_infinito << endl;
    guardado << estadisticas.casuales_limite << endl;
    guardado << estadisticas.casuales_hasta << endl;
    guardado << estadisticas.casuales_tira_afloja << endl;
    guardado << estadisticas.competitivo << endl;
    guardado << estadisticas.competitivo_hasta_10 << endl;
    guardado << estadisticas.competitivo_hasta_25 << endl;
    guardado << estadisticas.competitivo_primero_5 << endl;
    guardado << estadisticas.competitivo_primero_10 << endl;
    guardado << estadisticas.competitivo_diferencia_3 << endl;
    guardado << estadisticas.competitivo_diferencia_5 << endl;
    guardado << estadisticas.puntos_hasta << endl;
    guardado << estadisticas.puntos_primero << endl;
    guardado << estadisticas.puntos_diferencia << endl;
    guardado << estadisticas.extra << endl;
    guardado << estadisticas.extra_cinco_movimientos << endl;
    guardado << estadisticas.extra_siete_movimientos << endl;
    guardado << estadisticas.extra_nueve_movimientos << endl;
    guardado << estadisticas.ul_casual_primero << endl;
    guardado << estadisticas.ul_casual_tira_afloja << endl;
    guardado << estadisticas.ul_casual_infinito << endl;
    guardado << estadisticas.ul_cinco_movimientos << endl;
    guardado << estadisticas.ul_siete_movimientos << endl;
    guardado << estadisticas.ul_nueve_movimientos << endl;
    for(int i = 0; i < estadisticas.tamano_apodo; i++) guardado << estadisticas.estado_apodos[i] << endl;

    guardado.close();
}

void load_stats(stats& estadisticas)
{
    ifstream loadeado("stats.save");
    
    loadeado >> estadisticas.nombre;
    loadeado >> estadisticas.dinero;
    loadeado >> estadisticas.victorias;
    loadeado >> estadisticas.empates;
    loadeado >> estadisticas.derrotas;
    loadeado >> estadisticas.partidas_ganadas;
    loadeado >> estadisticas.partidas_empatadas;
    loadeado >> estadisticas.partidas_perdidas;
    loadeado >> estadisticas.piedra;
    loadeado >> estadisticas.papel;
    loadeado >> estadisticas.tijera;
    loadeado >> estadisticas.lagarto;
    loadeado >> estadisticas.spock;
    loadeado >> estadisticas.fuego;
    loadeado >> estadisticas.esponja;
    loadeado >> estadisticas.aire;
    loadeado >> estadisticas.agua;
    loadeado >> estadisticas.humano;
    loadeado >> estadisticas.pistola;
    loadeado >> estadisticas.record_victorias;
    loadeado >> estadisticas.record_empates;
    loadeado >> estadisticas.record_derrotas;
    loadeado >> estadisticas.acumula_victorias;
    loadeado >> estadisticas.acumula_empates;
    loadeado >> estadisticas.acumula_derrotas;
    loadeado >> estadisticas.totales;
    loadeado >> estadisticas.casuales;
    loadeado >> estadisticas.casuales_infinito;
    loadeado >> estadisticas.casuales_limite;
    loadeado >> estadisticas.casuales_hasta;
    loadeado >> estadisticas.casuales_tira_afloja;
    loadeado >> estadisticas.competitivo;
    loadeado >> estadisticas.competitivo_hasta_10;
    loadeado >> estadisticas.competitivo_hasta_25;
    loadeado >> estadisticas.competitivo_primero_5;
    loadeado >> estadisticas.competitivo_primero_10;
    loadeado >> estadisticas.competitivo_diferencia_3;
    loadeado >> estadisticas.competitivo_diferencia_5;
    loadeado >> estadisticas.puntos_hasta;
    loadeado >> estadisticas.puntos_primero;
    loadeado >> estadisticas.puntos_diferencia;
    loadeado >> estadisticas.extra;
    loadeado >> estadisticas.extra_cinco_movimientos;
    loadeado >> estadisticas.extra_siete_movimientos;
    loadeado >> estadisticas.extra_nueve_movimientos;
    loadeado >> estadisticas.ul_casual_primero;
    loadeado >> estadisticas.ul_casual_tira_afloja;
    loadeado >> estadisticas.ul_casual_infinito;
    loadeado >> estadisticas.ul_cinco_movimientos;
    loadeado >> estadisticas.ul_siete_movimientos;
    loadeado >> estadisticas.ul_nueve_movimientos;
    for(int i = 0; i < estadisticas.tamano_apodo; i++) loadeado >> estadisticas.estado_apodos[i];

    loadeado.close();
}

void from_mp_load_stats(stats& estadisticas)
{
    ifstream loadeado("mp.save");
    
    loadeado >> estadisticas.nombre;
    loadeado >> estadisticas.dinero;
    loadeado >> estadisticas.victorias;
    loadeado >> estadisticas.empates;
    loadeado >> estadisticas.derrotas;
    loadeado >> estadisticas.partidas_ganadas;
    loadeado >> estadisticas.partidas_empatadas;
    loadeado >> estadisticas.partidas_perdidas;
    loadeado >> estadisticas.piedra;
    loadeado >> estadisticas.papel;
    loadeado >> estadisticas.tijera;
    loadeado >> estadisticas.lagarto;
    loadeado >> estadisticas.spock;
    loadeado >> estadisticas.fuego;
    loadeado >> estadisticas.esponja;
    loadeado >> estadisticas.aire;
    loadeado >> estadisticas.agua;
    loadeado >> estadisticas.humano;
    loadeado >> estadisticas.pistola;
    loadeado >> estadisticas.record_victorias;
    loadeado >> estadisticas.record_empates;
    loadeado >> estadisticas.record_derrotas;
    loadeado >> estadisticas.acumula_victorias;
    loadeado >> estadisticas.acumula_empates;
    loadeado >> estadisticas.acumula_derrotas;
    loadeado >> estadisticas.totales;
    loadeado >> estadisticas.casuales;
    loadeado >> estadisticas.casuales_infinito;
    loadeado >> estadisticas.casuales_limite;
    loadeado >> estadisticas.casuales_hasta;
    loadeado >> estadisticas.casuales_tira_afloja;
    loadeado >> estadisticas.competitivo;
    loadeado >> estadisticas.competitivo_hasta_10;
    loadeado >> estadisticas.competitivo_hasta_25;
    loadeado >> estadisticas.competitivo_primero_5;
    loadeado >> estadisticas.competitivo_primero_10;
    loadeado >> estadisticas.competitivo_diferencia_3;
    loadeado >> estadisticas.competitivo_diferencia_5;
    loadeado >> estadisticas.puntos_hasta;
    loadeado >> estadisticas.puntos_primero;
    loadeado >> estadisticas.puntos_diferencia;
    loadeado >> estadisticas.extra;
    loadeado >> estadisticas.extra_cinco_movimientos;
    loadeado >> estadisticas.extra_siete_movimientos;
    loadeado >> estadisticas.extra_nueve_movimientos;
    loadeado >> estadisticas.ul_casual_primero;
    loadeado >> estadisticas.ul_casual_tira_afloja;
    loadeado >> estadisticas.ul_casual_infinito;
    loadeado >> estadisticas.ul_cinco_movimientos;
    loadeado >> estadisticas.ul_siete_movimientos;
    loadeado >> estadisticas.ul_nueve_movimientos;
    for(int i = 0; i < estadisticas.tamano_apodo; i++) loadeado >> estadisticas.estado_apodos[i];

    loadeado.close();
}