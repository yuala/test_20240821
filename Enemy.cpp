#include "DxLib.h"
#include "Enemy.h"
#include"Player.h"
#include"system.h"

// �G�l�~�[������
void Enemy::Initialize()
{
	
	LoadDivGraph("data/texture/gr_3.png", 24, 24, 1, 120, 120, GraphGrRe);
	GetGraphSize(GraphGrRe[0], &W, &H);
		
	X = ENEMY_X;
		
	Y = 792.0f;

		DrawEmy = 0;
	
	G = START_G;

	Speed = DEFSPEED;

	animtime = 0;
	animRe = 6;


	
}

// �G�l�~�[�X�V
void Enemy::Update(Player&player,System&system,bool&gameover)
{
	
	

	animtime++;

		if (CheckHitKeyAll)
		{
			if (animtime >= ANIMSPEED)
			{
				animtime = 0;
				animRe--;
			}
		}
		if (animRe < 2)
		{
			animRe = 6;
		}



	// �G�l�~�[�̍��W���ړ����Ă�������Ɉړ�����
	if (X> -100)
	{
			X -= Speed;
		
	}
	else//�G�l�~�[����ʊO�ɏo���炻�̍��W����ʉE�[�Ƀ��Z�b�g����
	{
		X= 2000;
		if (system.gamecount < 55)
		{
			Speed = Speed + UPSPEED;
		}
			
			
		
	}

	if (system.gamecount > 40)
	{
				//�W�����v
		if (Y == START_Y)
		{
			G = JUMPPOWER;
		}

		if (Y > START_Y)
		{
			Y = START_Y;
			G = START_G;
		}

		Y -= G;
		G -= FALLSPEED;


	}
	else
	{
		Y = START_Y;
	}
	

	
	if (hitshot[DrawEmy] == 1)
	{
		X = 2000;
		if(DrawEmy != 50)
		{
			DrawEmy++;
		}
		else
		{
			DrawEmy = 0;
		}
	}
	
	/*
	DrawLine(pos.x+20, pos.y+20, pos.x + W-20, pos.y+20, GetColor(255, 0, 0));//�㉡
	DrawLine(pos.x+20, pos.y + H-20, pos.x + W-20, pos.y + H-20, GetColor(255, 0, 0));//����
	DrawLine(pos.x+20, pos.y+20, pos.x+20, pos.y + H-20, GetColor(255, 0, 0));//���c
	DrawLine(pos.x + W-20, pos.y+20, pos.x + W-20, pos.y + H-20, GetColor(255, 0,
	
	
	*/
	

	// �v���C���[�Ƃ̓����蔻��
	if ((player.pos.x + 20 <= X && player.pos.x + W - 20 >= X) && (player.pos.y + 20 <= Y + 20 && player.pos.y + H - 20 >= Y + 20))
	{
		//�q�b�g����
		gameover = true;
	}
	if ((player.pos.x + 20 <= X && player.pos.x + W - 20 >= X) && (player.pos.y + 20 >= Y + 20 && player.pos.y + 20 <= Y + H - 20))
	{
		//�q�b�g����
		gameover = true;
	}
	if ((player.pos.x + 20 >= X && player.pos.x + 20 <= X + W - 20) && (player.pos.y + 20 <= Y + 20 && player.pos.y + H - 20 >= Y + 20))
	{
		//�q�b�g����
		gameover = true;
	}
	if ((player.pos.x + 20 >= X && player.pos.x + 20 <= X + W - 20) && (player.pos.y + 20 >= Y + 20 && player.pos.y + 20 <= Y + H - 20))
	{
		//�q�b�g����
		gameover = true;
	}

	
}

// �G�l�~�[�`��
void Enemy::Draw(System&system)
{
	
	DrawLine(X, Y + 20, X + W - 20, Y + 20, GetColor(255, 0, 0));//�㉡
	DrawLine(X, Y + H - 20, X + W - 20, Y + H - 20, GetColor(255, 0, 0));//����
	DrawLine(X, Y + 20, X, Y + H - 20, GetColor(255, 0, 0));//���c
	DrawLine(X + W - 20, Y + 20, X + W - 20, Y + H - 20, GetColor(255, 0, 0));//�E�c

	/*
	SetFontSize(70);
	DrawFormatString(400, 400, GetColor(255, 100, 100), "�G�l�~�[\n��F%d\n���F%d\n�E�F%d\n���F%d", Y + 20, Y + H - 20, X + W - 20, X);
	SetFontSize(-1);
	*/
	

	if (system.gamecount > 20&& system.gamecount < 40 || system.gamecount > 70)
	{
		if (X>1500&&X<1700||X>700&&X<900)
		{
			
		}
		else
		{
			// �G�l�~�[��`��
			DrawGraph(X, Y, GraphGrRe[animRe], TRUE);

		}
	}
	else
	{
		// �G�l�~�[��`��
		DrawGraph(X, Y, GraphGrRe[animRe], TRUE);
		
	}
	
}
