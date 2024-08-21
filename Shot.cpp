#include "DxLib.h"
#include "Enemy.h"
#include "Shot.h"
#include"Player.h"
#include"System.h"

// �V���b�g������
void Shot:: Initialize(int shotGraph)
{
	// �V���b�g�̃O���t�B�b�N���������Ƀ��[�h.
	Graph = shotGraph;

	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false�������Ă���
	visibleFlag = false;

	// �e�̃O���t�B�b�N�̃T�C�Y������
	GetGraphSize(Graph, &W, &H);
}

// �V���b�g�X�V
void Shot::Update(Enemy& enemy)
{
	// �e�̂����蔻��.
	// �ei�����݂��Ă���ꍇ�̂ݎ��̏����ɉf��
	if (visibleFlag == 1)
	{
		// �G�l�~�[�Ƃ̓����蔻��
		if (((X > enemy.X[enemy.DrawEmy] && X < enemy.X[enemy.DrawEmy] + enemy.W[enemy.DrawEmy]) ||
			(enemy.X[enemy.DrawEmy] > X && enemy.X[enemy.DrawEmy] < X + W)) &&
			((Y > enemy.Y[enemy.DrawEmy] && Y < enemy.Y[enemy.DrawEmy] + enemy.H[enemy.DrawEmy]) ||
				(enemy.Y[enemy.DrawEmy] > Y && enemy.Y[enemy.DrawEmy] < Y + H)))
		{
			// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			visibleFlag = 0;

			// �G�l�~�[�̊��c�߂Ă��邩�ǂ�����ێ�����ϐ��Ɂw�c�߂Ă���x��\��TRUE����
			enemy.DamageFlag[enemy.DrawEmy] = true;
			// �G�l�~�[�̊��c�߂Ă��鎞�Ԃ𑪂�J�E���^�ϐ��ɂO����
			enemy.DamageCounter[enemy.DrawEmy] = 0;
			enemy.hitshot[enemy.DrawEmy] = 1;
			
		}
	}
}

// �V���b�g�`��
void Shot::Draw()
{
	// ���@�̒ei�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e��true(���݂���)�̏ꍇ�̂ݍs�� )
	if (visibleFlag == true)
	{
		// �ei���P�U�h�b�g�E�Ɉړ�������
		X += 16;

		// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ���false(���݂��Ȃ�)��������
		if (X > SCREEN_W)
		{
			visibleFlag = false;
		}

		// ��ʂɒei��`�悷��
		DrawGraph(X, Y, Graph, TRUE);
	}
}