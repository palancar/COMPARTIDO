#pragma once


//VARIABLES / CONSTANTES GLOBALES (se definen por vez primera en el MainGlut)
class GlobalVar {
public:
	static const int N_Disparos;
	static const float V_Disparos;
	static const float V_Nave;
	static const float V_Asteroides;
	static const float Distancia;
	static const float R_Generacion;
	static const float R_Destruccion;
	static const int HP_Inicial;
	static const int HP_Nave_Enemiga;
	static const float T_Disparo_NaveEnemiga;
	static const float T_Ciclo_Asteroides;
	static const float V_Nave_Mala;
};


typedef GlobalVar GV;