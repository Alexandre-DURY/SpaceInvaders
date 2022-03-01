#include "Terrain.h"
#include <cassert>
#include <iostream>

// Initialisation du terrain vide
const char terrain1[21][38] = {
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!                                   !",
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!",
};

Terrain::Terrain()
{ // Initialisation
	dimx = 37;
	dimy = 21;
	for (int x = 0; x < dimx; ++x)
		for (int y = 0; y < dimy; ++y)
			ter[x][y] = terrain1[y][x]; // copie du terrain
}

Terrain::~Terrain() {}

int Terrain::getDimX() const
{
	return dimx;
}

int Terrain::getDimY() const { return dimy; }

char Terrain::getXY(const int x, const int y) const
{
	// vérification des dimension du terrain
	assert(x >= 0);
	assert(y >= 0);
	assert(x < dimx);
	assert(y < dimy);
	return ter[x][y];
}

void Terrain::setXY(const int x, const int y, char c)
{
	// vérification des dimension du terrain
	assert(x >= 0);
	assert(y >= 0);
	assert(x < dimx);
	assert(y < dimy);
	if (c != ' ')
	{
		assert(estPositionPersoValide(x, y));
	}
	ter[x][y] = c;
}

void Terrain::setDim(int x, int y)
{
	assert((x >= 0) && (y >= 0));
	dimx = x;
	dimy = y;
}

bool Terrain::estPositionPersoValide(const int x, const int y) const
{
	return ((x >= 0) && (x < dimx) && (y >= 0) && (y < dimy) && (ter[x][y] == ' '));
}

void Terrain::TestRegression()
{
	assert(getDimX() == 37);
	std::cout << "DimX = " << getDimX() << std::endl;

	assert(getDimY() == 21);
	std::cout << "DimY = " << getDimY() << std::endl;

	for (int x = 0; x < dimx; ++x)
	{
		for (int y = 0; y < dimy; ++y)
		{
			assert(getXY(x, y) == terrain1[y][x]);
			std::cout << getXY(x, y);
		}
		std::cout << std::endl;
	}

	setDim(20, 10);
	assert(getDimX() == 20);
	std::cout << "DimX = " << getDimX() << std::endl;
	assert(getDimY() == 10);
	std::cout << "DimY = " << getDimY() << std::endl;

	setXY(1, 1, '@');
	assert(getXY(1, 1) == '@');
	std::cout << "SetXY = " << getXY(1, 1) << std::endl;

	assert(estPositionPersoValide(2, 2) == true);
	std::cout << "Position valide = " << estPositionPersoValide(2, 2) << std::endl;
	assert(estPositionPersoValide(1, 1) == false);
	std::cout << "Position valide = " << estPositionPersoValide(1, 1) << std::endl;
}