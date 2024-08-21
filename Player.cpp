#include "DxLib.h"
#include "Player.h"
#include"Vector.h"
#include"system.h"


// �v���C���[������
void Player::Initialize()
{
	// �v���C���[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	LoadDivGraph("data/texture/red_4.png", 24, 24, 1, 120, 120, Graph);
	LoadDivGraph("data/texture/red_8_re.png", 24, 24, 1, 120, 120, GraphRE);
	LoadDivGraph("data/texture/gr_3.png", 24, 24, 1, 120, 120, GraphGrRe);
	
	jumpsound = LoadSoundMem("data/sound/se05.wav");

	G = START_G;
	anim = 5;
	animtime = 0;
	pos = VGet(START_X, START_Y, 0);
	GrX = 2200;
	GrY = 792;
	HitEmy = 0;
	animRe = 6;
	isMove = true;

	// �V���b�g�{�^�����O�̃t���[���ŉ����ꂽ���ǂ�����ۑ�����ϐ���false(�����ꂢ�Ȃ�)����
	PrevShotFlag = false;

	// �v���C���[�ƒe�̉摜�̃T�C�Y�𓾂�
	GetGraphSize(Graph[anim], &W, &H);
}

// �v���C���[�̍X�V����
void Player::Update()
{
	
		animtime++;
		if (CheckHitKeyAll&& pos.y == START_Y)
		{
			if (animtime >= ANIMSPEED)
			{
				animtime = 0;
				anim++;
			}
		}
		if (anim > 8)
		{
			anim = 3;
		}
	



	// ���L�[�������Ă�����v���C���[���ړ�������
	if (CheckHitKey(KEY_INPUT_SPACE)&&pos.y== START_Y)
	{
		PlaySoundMem(jumpsound, DX_PLAYTYPE_BACK);
		G = JUMPPOWER+3.0f;
	}
	
	if (pos.y > START_Y)
	{
		pos.y = START_Y;
		G = START_G;
	}
	
	pos.y -= G;
	G -= FALLSPEED;

	

	

	// �v���C���[����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
	if (pos.x < 0)
	{
		pos.x = 0;
	}
	if (pos.x > 1920 - W)
	{
		pos.x = 1920 - W;
	}
	if (pos.y < 0)
	{
		pos.y = 0;
	}
	if (pos.y >START_Y)
	{
		pos.y = START_Y;
	}
}

// �v���C���[�̕`�揈��
void Player::Draw()
{
	// �v���C���[��`��
	/*
	SetFontSize(70);
	DrawFormatString(100, 400, GetColor(255, 100, 100), "�v���C���[\n��F%.0f\n���F%.0f\n�E�F%.0f\n���F%.0f", pos.y + 20, pos.y + H - 20, pos.x + W - 20, pos.x + 20);
	SetFontSize(-1);
	*/
	

		DrawGraph(pos.x, pos.y, Graph[anim], TRUE);

	DrawLine(pos.x+20, pos.y+20, pos.x + W-20, pos.y+20, GetColor(255, 0, 0));//�㉡
	DrawLine(pos.x+20, pos.y + H-20, pos.x + W-20, pos.y + H-20, GetColor(255, 0, 0));//����
	DrawLine(pos.x+20, pos.y+20, pos.x+20, pos.y + H-20, GetColor(255, 0, 0));//���c
	DrawLine(pos.x + W-20, pos.y+20, pos.x + W-20, pos.y + H-20, GetColor(255, 0, 0));//�E�c
		
	if (HitEmy ==1)
	{
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);//�ȉ��ɋL�q�����Draw�֐��̃u�����h��ύX����
			DrawGraph(pos.x, pos.y, Graph[anim], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);//���L�ɋL�q�����Draw�֐��̃u�����h���m�[�}���ɕύX����B
			HitEmy = 0;

	}
}


void Player::Drawtitle()
{
	// �v���C���[��`��
	



	if (isMove == true)
		DrawGraph(pos.x, pos.y, Graph[anim], TRUE);
	else if (isMove == false)
	{
		DrawGraph(pos.x, pos.y, GraphRE[animRe], TRUE);
		DrawGraph(GrX, GrY, GraphGrRe[animRe], TRUE);
	}

	if (HitEmy == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 255);//�ȉ��ɋL�q�����Draw�֐��̃u�����h��ύX����
		DrawGraph(pos.x, pos.y, Graph[anim], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);//���L�ɋL�q�����Draw�֐��̃u�����h���m�[�}���ɕύX����B
		HitEmy = 0;

	}
}

// �v���C���[�̍X�V����
void Player::UpdateTitle()
{

	


	animtime++;
	if (isMove == true)
	{
		
			if (animtime >= ANIMSPEED)
			{
				animtime = 0;
				anim++;
			}
			
		if (anim > 8)
		{
			anim = 3;
		}
	}
	else if (isMove == false)
	{
			if (animtime >= ANIMSPEED)
			{
				animtime = 0;
				animRe--;
			}
		if (animRe<2)
		{
			animRe = 6;
		}
	}

	// ���L�[�������Ă�����v���C���[���ړ�������
	if (CheckHitKey(KEY_INPUT_SPACE) && pos.y == START_Y)
	{
		G = JUMPPOWER;
		PlaySoundMem(jumpsound, DX_PLAYTYPE_BACK);
	}

	if (pos.y > START_Y)
	{
		pos.y = START_Y;
		G = START_G;
	}

	pos.y -= G;
	G -= FALLSPEED;





	// �v���C���[����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
	if (pos.y < 0)
	{
		pos.y = 0;
	}
	if (pos.y > START_Y)
	{
		pos.y = START_Y;
	}


	if (isMove == true)
	{
		pos.x += 5;
	}
	else if (isMove == false)
	{
		pos.x -= 7;
		GrX -= 7;

	}
		

	if (pos.x > 2000)
	{
		isMove = false;
		GrX = 2200;
	}
	else if (GrX < -200)
		isMove = true;
	
}
