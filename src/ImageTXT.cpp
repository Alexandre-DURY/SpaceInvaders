#include <iostream>
#include <sstream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include "Jeu.h"

void txtAff(WinTXT &win, const Jeu &jeu)
{
	const Terrain &ter = jeu.getConstTerrain();
	const SpaceShip &vaisseau = jeu.getConstSpaceShip();
	const Ennemie *enn = jeu.getConstEnnemie();
	int nb_enn = jeu.getNombreDeEnnemie();
	int nb_miss = vaisseau.getNombreDeMissiles();
	Missile *miss = vaisseau.getMissiles();
	int nb_missile = enn[0].getNombreDeMissiles();
	int niveau = jeu.getNiveau();
	/*std::stringstream c;
	std::string resultat;
	for (int i=0; i<nb_enn; i++) {
		c<<"missile"<<i;
		resultat=c.str();
		Missile*  = enn[i].getMissiles();
	}*/
	Missile *missile0 = enn[0].getMissiles();
	Missile *missile1 = enn[1].getMissiles();
	Missile *missile2 = enn[2].getMissiles();
	Missile *missile3 = enn[3].getMissiles();
	Missile *missile4 = enn[4].getMissiles();
	Missile *missile5 = enn[5].getMissiles();
	Missile *missile6 = enn[6].getMissiles();
	Missile *missile7 = enn[7].getMissiles();
	Missile *missile8 = enn[8].getMissiles();
	Missile *missile9 = enn[9].getMissiles();
	Missile *missile10 = enn[10].getMissiles();
	Missile *missile11 = enn[11].getMissiles();
	Missile *missile12 = enn[12].getMissiles();
	Missile *missile13 = enn[13].getMissiles();
	Missile *missile14 = enn[14].getMissiles();
	Missile *missile15 = enn[15].getMissiles();
	Missile *missile16 = enn[16].getMissiles();
	Missile *missile17 = enn[17].getMissiles();
	Missile *missile18 = enn[18].getMissiles();
	Missile *missile19 = enn[19].getMissiles();
	Missile *missile20 = enn[20].getMissiles();
	Missile *missile21 = enn[21].getMissiles();
	Missile *missile22 = enn[22].getMissiles();
	Missile *missile23 = enn[23].getMissiles();
	Missile *missile24 = enn[24].getMissiles();
	Missile *missile25 = enn[25].getMissiles();
	Missile *missile26 = enn[26].getMissiles();
	Missile *missile27 = enn[27].getMissiles();
	Missile *missile28 = enn[28].getMissiles();
	Missile *missile29 = enn[29].getMissiles();
	Missile *missile30 = enn[30].getMissiles();
	Missile *missile31 = enn[31].getMissiles();
	Missile *missile32 = enn[32].getMissiles();
	Missile *missile33 = enn[33].getMissiles();
	Missile *missile34 = enn[34].getMissiles();
	Missile *missile35 = enn[35].getMissiles();
	Missile *missile36 = enn[36].getMissiles();
	Missile *missile37 = enn[37].getMissiles();
	Missile *missile38 = enn[38].getMissiles();
	Missile *missile39 = enn[39].getMissiles();
	Missile *missile40 = enn[40].getMissiles();
	Missile *missile41 = enn[41].getMissiles();
	Missile *missile42 = enn[42].getMissiles();
	win.clear();

	// Affichage des murs
	for (int x = 0; x < ter.getDimX(); ++x)
		for (int y = 0; y < ter.getDimY(); ++y)
			win.print(x, y, ter.getXY(x, y));
	// Affichage des Missiles Vaisseau
	for (int j = 0; j < nb_miss; j++)
		if (miss[j].getY() != vaisseau.getY())
			win.print(miss[j].getX(), miss[j].getY(), '|');
	// Affichage des Missiles Ennemie
	for (int k = 0; k < nb_missile; k++)
	{
		switch (niveau)
		{
		case 0:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			break;
		case 1:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			break;
		case 2:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			break;
		case 3:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			win.print(missile20[k].getX(), missile20[k].getY(), '|');
			win.print(missile21[k].getX(), missile21[k].getY(), '|');
			win.print(missile22[k].getX(), missile22[k].getY(), '|');
			win.print(missile23[k].getX(), missile23[k].getY(), '|');
			win.print(missile24[k].getX(), missile24[k].getY(), '|');
			win.print(missile25[k].getX(), missile25[k].getY(), '|');
			win.print(missile26[k].getX(), missile26[k].getY(), '|');
			win.print(missile27[k].getX(), missile27[k].getY(), '|');
			break;
		case 4:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			win.print(missile20[k].getX(), missile20[k].getY(), '|');
			win.print(missile21[k].getX(), missile21[k].getY(), '|');
			win.print(missile22[k].getX(), missile22[k].getY(), '|');
			win.print(missile23[k].getX(), missile23[k].getY(), '|');
			win.print(missile24[k].getX(), missile24[k].getY(), '|');
			win.print(missile25[k].getX(), missile25[k].getY(), '|');
			win.print(missile26[k].getX(), missile26[k].getY(), '|');
			win.print(missile27[k].getX(), missile27[k].getY(), '|');
			break;
		case 5:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			win.print(missile20[k].getX(), missile20[k].getY(), '|');
			win.print(missile21[k].getX(), missile21[k].getY(), '|');
			win.print(missile22[k].getX(), missile22[k].getY(), '|');
			break;
		case 6:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			win.print(missile20[k].getX(), missile20[k].getY(), '|');
			win.print(missile21[k].getX(), missile21[k].getY(), '|');
			win.print(missile22[k].getX(), missile22[k].getY(), '|');
			win.print(missile23[k].getX(), missile23[k].getY(), '|');
			win.print(missile24[k].getX(), missile24[k].getY(), '|');
			break;
		case 7:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			win.print(missile20[k].getX(), missile20[k].getY(), '|');
			win.print(missile21[k].getX(), missile21[k].getY(), '|');
			win.print(missile22[k].getX(), missile22[k].getY(), '|');
			win.print(missile23[k].getX(), missile23[k].getY(), '|');
			win.print(missile24[k].getX(), missile24[k].getY(), '|');
			win.print(missile25[k].getX(), missile25[k].getY(), '|');
			win.print(missile26[k].getX(), missile26[k].getY(), '|');
			win.print(missile27[k].getX(), missile27[k].getY(), '|');
			win.print(missile28[k].getX(), missile28[k].getY(), '|');
			win.print(missile29[k].getX(), missile29[k].getY(), '|');
			break;
		case 8:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			win.print(missile20[k].getX(), missile20[k].getY(), '|');
			win.print(missile21[k].getX(), missile21[k].getY(), '|');
			win.print(missile22[k].getX(), missile22[k].getY(), '|');
			win.print(missile23[k].getX(), missile23[k].getY(), '|');
			win.print(missile24[k].getX(), missile24[k].getY(), '|');
			win.print(missile25[k].getX(), missile25[k].getY(), '|');
			win.print(missile26[k].getX(), missile26[k].getY(), '|');
			win.print(missile27[k].getX(), missile27[k].getY(), '|');
			win.print(missile28[k].getX(), missile28[k].getY(), '|');
			win.print(missile29[k].getX(), missile29[k].getY(), '|');
			break;
		case 9:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			win.print(missile20[k].getX(), missile20[k].getY(), '|');
			win.print(missile21[k].getX(), missile21[k].getY(), '|');
			win.print(missile22[k].getX(), missile22[k].getY(), '|');
			win.print(missile23[k].getX(), missile23[k].getY(), '|');
			break;
		case 10:
			win.print(missile0[k].getX(), missile0[k].getY(), '|');
			win.print(missile1[k].getX(), missile1[k].getY(), '|');
			win.print(missile2[k].getX(), missile2[k].getY(), '|');
			win.print(missile3[k].getX(), missile3[k].getY(), '|');
			win.print(missile4[k].getX(), missile4[k].getY(), '|');
			win.print(missile5[k].getX(), missile5[k].getY(), '|');
			win.print(missile6[k].getX(), missile6[k].getY(), '|');
			win.print(missile7[k].getX(), missile7[k].getY(), '|');
			win.print(missile8[k].getX(), missile8[k].getY(), '|');
			win.print(missile9[k].getX(), missile9[k].getY(), '|');
			win.print(missile10[k].getX(), missile10[k].getY(), '|');
			win.print(missile11[k].getX(), missile11[k].getY(), '|');
			win.print(missile12[k].getX(), missile12[k].getY(), '|');
			win.print(missile13[k].getX(), missile13[k].getY(), '|');
			win.print(missile14[k].getX(), missile14[k].getY(), '|');
			win.print(missile15[k].getX(), missile15[k].getY(), '|');
			win.print(missile16[k].getX(), missile16[k].getY(), '|');
			win.print(missile17[k].getX(), missile17[k].getY(), '|');
			win.print(missile18[k].getX(), missile18[k].getY(), '|');
			win.print(missile19[k].getX(), missile19[k].getY(), '|');
			win.print(missile20[k].getX(), missile20[k].getY(), '|');
			win.print(missile21[k].getX(), missile21[k].getY(), '|');
			win.print(missile22[k].getX(), missile22[k].getY(), '|');
			win.print(missile23[k].getX(), missile23[k].getY(), '|');
			win.print(missile24[k].getX(), missile24[k].getY(), '|');
			win.print(missile25[k].getX(), missile25[k].getY(), '|');
			win.print(missile26[k].getX(), missile26[k].getY(), '|');
			win.print(missile27[k].getX(), missile27[k].getY(), '|');
			win.print(missile28[k].getX(), missile28[k].getY(), '|');
			win.print(missile29[k].getX(), missile29[k].getY(), '|');
			win.print(missile30[k].getX(), missile30[k].getY(), '|');
			win.print(missile31[k].getX(), missile31[k].getY(), '|');
			win.print(missile32[k].getX(), missile32[k].getY(), '|');
			win.print(missile33[k].getX(), missile33[k].getY(), '|');
			win.print(missile34[k].getX(), missile34[k].getY(), '|');
			win.print(missile35[k].getX(), missile35[k].getY(), '|');
			win.print(missile36[k].getX(), missile36[k].getY(), '|');
			win.print(missile37[k].getX(), missile37[k].getY(), '|');
			win.print(missile38[k].getX(), missile38[k].getY(), '|');
			win.print(missile39[k].getX(), missile39[k].getY(), '|');
			win.print(missile40[k].getX(), missile40[k].getY(), '|');
			win.print(missile41[k].getX(), missile41[k].getY(), '|');
			win.print(missile42[k].getX(), missile42[k].getY(), '|');
			break;
		}
	}
	// Affichage du Vaisseau
	win.print(vaisseau.getX(), vaisseau.getY(), 'x');
	win.print(vaisseau.getX() - 1, vaisseau.getY(), 'x');
	win.print(vaisseau.getX() + 1, vaisseau.getY(), 'x');
	win.print(vaisseau.getX(), vaisseau.getY() - 1, 'x');
	// Affichage des Ennemies
	for (int i = 0; i < nb_enn; i++)
	{
		if (enn[i].getVie() != 0)
			win.print(enn[i].getX(), enn[i].getY(), '@');
	}
	//Affichage du score
	//win.print(0,ter.getDimY()-1,'Score : ');
	for (int i = 1; i < ter.getDimX(); i++)
	{
		if (jeu.getScore() >= i)
			win.print(i - 1, ter.getDimY() - 1, 's');
	}
	//Affichage des vies
	for (int i = 1; i < ter.getDimX(); i++)
	{
		if (vaisseau.getVie() >= i)
			win.print(i, 1, 'v');
	}

	win.draw();
}

void txtBoucle(Jeu &jeu)
{
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WinTXT win(jeu.getConstTerrain().getDimX(), jeu.getConstTerrain().getDimY());
	bool ok = true;
	int c;

	do
	{
		txtAff(win, jeu);

#ifdef _WIN32
		Sleep(100);
#else
		usleep(100000);
#endif // WIN32

		jeu.actionsAutomatiques();
		if (jeu.CollisionEnnemieSpaceShip() == true)
		{
			ok = false;
		}
		jeu.UpdateTabMissile();
		jeu.Collisions();
		//if (jeu.getConstSpaceShip().getVie()==0) {ok=false;}

		if (jeu.EnnemisEnVie())
			jeu.RemplirTabEnnemies(jeu.getNiveau() + 1);

		c = win.getCh();
		switch (c)
		{
		case 'q': //Gauche
			jeu.actionClavier('g');
			break;
		case 'd': //Droite
			jeu.actionClavier('d');
			break;
		/*case 'z': //Haut
				jeu.actionClavier('h');
				break;
			case 's': //Bas
				jeu.actionClavier('b');
				break;*/
		case ' ': //Tirer
			jeu.actionClavier('m');
			break;
		case 'w': //Quitter
			ok = false;
			break;
		}

	} while (ok);
}