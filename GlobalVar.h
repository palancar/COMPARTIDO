#pragma once


//VARIABLES / CONSTANTES GLOBALES (se definen por vez primera en el MainGlut)
class GlobalVar {
public:
	static float Distancia;//distancia del ojo
	static float R_Generacion;
	static float R_Destruccion;

	static int N_Disparos;
	static float V_Disparos;
	static float V_Nave;
	static float V_Nave_Mala;
	static float V_Asteroides;
	static int HP_Inicial;
	static int HP_Nave_Enemiga;
	static float T_Disparo_NaveEnemiga;
	static float T_Ciclo_Asteroides;
	static float T_Ciclo_Nave;
};


typedef GlobalVar GV;