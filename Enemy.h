#pragma once

const int ENEMYNUMBER = 90;
const float ENEMY_X = 2000.0f;
const float DEFSPEED = 12.0f;
const float UPSPEED = 0.002f;

class Player;
class System;
class System;

// �G�l�~�[�\����.
class Enemy
{
public:

	int		X;
	int		Y;
	float G;
	int		W;
	int		H;
	float Speed;
	int DrawEmy;
	bool hitshot[ENEMYNUMBER];

	int animtime;
	int animRe;
	int GraphGrRe[16];


	void Initialize();										// �G�l�~�[������
	void Update(Player& player, System& system,bool&gameover);											// �G�l�~�[�X�V
	void Draw(System&system);											// �G�l�~�[�`��

};

