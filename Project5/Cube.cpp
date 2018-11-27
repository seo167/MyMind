#include "Cube.h"

void Cube::Conversion() {
	for (int i = 0; i < 6; ++i) {
		planeArray[i].Conversion();
	}
}

void Cube::Draw() {
	for (int i = 0; i < 6;++i) {
		planeArray[i].Draw();
	}
	
}


void Cube::RotateY(float Angle) {
	for (int i = 0; i < 6;++i) {
		planeArray[i].RotateY(Angle);
	}
}

void Cube::InitCube() {
	
	int Front[4][3] = {
		{-10,10,10},
		{10,10,10},
		{10,-10,10},
		{-10,-10,10}
	};

	planeArray.push_back(Plane(*Front, camera));
	
	int Back[4][3] = {
		{-10,10,30},
		{10,10,30},
		{10,-10,30},
		{-10,-10,30}
	};
	planeArray.push_back(Plane(*Back, camera));
	
	int Left[4][3] = {
		{-10,10,30},
		{-10,10,10},
		{-10,-10,10},
		{-10,-10,30}
	};
	planeArray.push_back(Plane(*Left, camera));
	
	int Right[4][3] = {
		{10,10,10},
		{10,10,30},
		{10,-10,30},
		{10,-10,10}
	};
	planeArray.push_back(Plane(*Right, camera));
	
	int Top[4][3] = {
		{-10,10,30},
		{10,10,30},
		{10,10,10 },
		{-10,10,10}
	};
	planeArray.push_back(Plane(*Top, camera));
	
	int Bottom[4][3] = {
		{-10,-10,30},
		{10,-10,30},
		{10,-10,10},
		{-10,-10,10}
	};
	planeArray.push_back(Plane(*Bottom, camera));
}

Cube::~Cube(){}
