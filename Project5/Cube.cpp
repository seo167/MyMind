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

void Cube::RotateX(float Angle) {
	for (int i = 0; i < 6; ++i) {
		planeArray[i].RotateX(Angle);
	}
}

void Cube::RotateZ(float Angle) {
	for (int i = 0; i < 6; ++i) {
		planeArray[i].RotateZ(Angle);
	}
}

void Cube::InitCube() {
	
	int Front1[3][3] = {
		{1,-1,-1},
		{-1,-1,-1},
		{-1,1,-1}
	};

	int Front2[3][3] = {
		{-1,1,-1},
		{1,1,-1},
		{1,-1,-1}
	};

	planeArray.push_back(Plane(*Front1,*Front2, camera));
	
	int Back1[3][3] = {
		{-1,1,1},
		{-1,-1,1},
		{1,-1,1}
	};

	int Back2[3][3] = {
		{1,-1,1},
		{1,1,1},
		{-1,1,1}		
	};

	planeArray.push_back(Plane(*Back1,*Back2, camera));
	
	int Left1[3][3] = {
		{-1,1,-1},
		{-1,-1,-1},
		{-1,-1,1}
		
		
	};

	int Left2[3][3] = {
		{-1,-1,1},
		{-1,1,1},
		{-1,1,-1}
		
		
	};

	planeArray.push_back(Plane(*Left1,*Left2, camera));
	
	int Right1[4][3] = {
		{1,1,1},
		{1,-1,1},
		{1,-1,-1}		
	};

	int Right2[4][3] = {
		{1,-1,-1},
		{1,1,-1},
		{1,1,1}
	};

	planeArray.push_back(Plane(*Right1, *Right2,camera));
	
	int Top1[3][3] = {
		{1,1,1},
		{1,1,-1},
		{-1,1,-1 }
	};
	int Top2[3][3] = {
		{-1,1,-1 },
		{-1,1,1 },
		{1,1,1}
	};
	planeArray.push_back(Plane(*Top1, *Top2, camera));
	
	int Bottom1[3][3] = {
		{-1,-1,1},
		{-1,-1,-1},
		{1,-1,-1}
		
	};

	int Bottom2[3][3] = {
		{1,-1,-1},
		{1,-1,1},
		{-1,-1,1}
	};

	planeArray.push_back(Plane(*Bottom1,*Bottom2, camera));
}

Cube::~Cube(){}
