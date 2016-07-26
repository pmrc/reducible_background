//Created by Pedro Cipriano

void loop_comp_fake(int mode = 1, TString era = "80XD")
	{

	if (mode == 1 or mode == 0)
		{
		//Z2e 
		//comp_fake("Ze","rate",""); already done on loading

		//Z2mu
		comp_fake("Zmu","rate",era);
		comp_fake("Zmu","rate",era+"MZ60");
		}

	if (mode == 2 or mode == 0)
		{
		//4e
		comp_fake("4e","correction",era);

		//2mu2e
		comp_fake("2mu2e","correction",era);

		//Z2e 4e+2mu2e for increased statistics
		comp_fake("Z2e","correction",era);
		}
	}

