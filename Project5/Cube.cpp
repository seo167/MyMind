#include "Cube.h"

void Cube::Change() {
	for (int i = 0; i < 6; ++i) {
		planeArray[i].transform.LocalToWorld();
		planeArray[i].transform.WorldToCamera();
		planeArray[i].transform.CameraToPerspective();
		planeArray[i].transform.PerspectiveToView();
	}
}

void Cube::Draw() {
	for (int i = 0; i < 6;++i) {
		planeArray[i].Draw();
	}
	
}

void Cube::RotateY(float Angle) {
	for (int i = 0; i < 6;++i) {
		planeArray[i].transform.RotateY(Angle);
	}
	
}

void Cube::InitCube() {
	
	int Front[4][3] = {
		{-10,10,10},
		{-10,-10,10},
		{10,-10,10},
		{10,10,10}
	};
	int Back[4][3] = {
		{-10,10,30},
		{-10,-10,30},
		{10,-10,30},
		{10,10,30}
	};
	int Left[4][3] = {
		{-10,10,10},
		{-10,-10,10},
		{-10,-10,30},
		{-10,10,30}
	};
	int Right[4][3] = {
		{10,10,10},
		{10,-10,10},
		{10,-10,30},
		{10,10,30}
	};
	int Top[4][3] = {
		{-10,10,10},
		{-10,10,30},
		{10,10,10},
		{10,10,30}
	};
	int Bottom[4][3] = {
		{-10,-10,10},
		{-10,-10,30},
		{10,-10,10},
		{10,-10,30}
	};

	planeArray[0].SetPoint(*Front,MColor(255,255,255));
	planeArray[1].SetPoint(*Back, MColor(255, 255, 255));
	planeArray[2].SetPoint(*Left, MColor(255, 255, 255));
	planeArray[3].SetPoint(*Right, MColor(255, 255, 255));
	planeArray[4].SetPoint(*Top, MColor(255, 255, 255));
	planeArray[5].SetPoint(*Bottom, MColor(255, 255, 255));
}

Cube::~Cube(){}
