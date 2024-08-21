#pragma once

#include "DxLib.h"

class System;

class Dome final
{
public:
	
	int num;
	float ang;

	void Init();//������
	void Update();			// �X�V.
	void Draw();			// �`��.


	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

private:
	int		modelHandle;	// ���f���n���h��.
	VECTOR	pos;			// �|�W�V����.

};
