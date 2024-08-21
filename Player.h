#pragma once

//�萔
const float JUMPPOWER = 22.0f;
const float START_X = 400.0f;
const float START_Y = 792.0f;
const float START_G = 0.0f;
const float FALLSPEED = 0.8f;
const float ANIMSPEED = 7;



// �v���g�^�C�v�錾
class Shot;
class System;

// �v���C���[�\����.
class Player
{
public:
	int Graph[16];
	int GraphRE[16];
	int GraphGrRe[16];
	float GrX;
	float GrY;
	int animRe;
	int W;
	int H;
	float G;
	bool PrevShotFlag;

	int jumpsound;

	int anim;
	int animtime;
	bool HitEmy;
	bool isMove = true;

	VECTOR pos;//�|�W�V����


	void Initialize();									// �v���C���[������
	void Update();	// �v���C���[�̍X�V����
	void Draw();										// �v���C���[�̕`�揈��		
	void Drawtitle();										// �v���C���[�̕`�揈��
	void UpdateTitle();	// �^�C�g����ʂ̃v���C���[�̍X�V����

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; };

	void SetPos(const VECTOR set) { pos = set; };

};




