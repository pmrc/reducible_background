//Created by Pedro Cipriano

void loop_comp_fake(int mode = 1)
	{

	if (mode == 1 or mode == 0)
		{
		//Z2e 
		//comp_fake("Ze","rate",""); already done on loading

		//Z2mu
		comp_fake("Zmu","rate","");
		}

	if (mode == 2 or mode == 0)
		{
		//4e
		comp_fake("4e","correction","");

		//2mu2e
		comp_fake("2mu2e","correction","");
		}
	}

