#pragma once


//VARIABLES / CONSTANTES GLOBALES (se definen por vez primera en el MainGlut)
class GlobalVar {
public:
	static float Distancia;//distancia del ojo
	static float R_Generacion;
	static float R_Destruccion;

	static float V_Disparos;
	static float V_Nave;
	static float V_Nave_Mala;

	static int HP_Inicial;
	static int HP_Nave_Enemiga;
	static float T_Disparo_NaveEnemiga;
	//Mejor, al cambiar la dificultad, que solo cambien los tiempos de ciclo y los radios
	//y velocidad de los asteroides (alguna cosilla más también)
	static float T_Ciclo_Asteroides;
	static float T_Ciclo_Nave;
	static float T_Ciclo_Nave_elite;
	static float R_Asteroide;
	static float V_Asteroides;

	//también se puede chetar la nave legendaria, subiendo la vida por ejemplo
	static float T_Ciclo_Nave_Legendaria;
	static int HP_Nave_legendaria;
	static float T_Disparo_Nave_Legendaria;

	static float V_Nave_elite;
	static float HP_Nave_elite;
	static float V_Disparo_elite;
	static float T_Disparo_Nave_elite;
	
};


typedef GlobalVar GV;