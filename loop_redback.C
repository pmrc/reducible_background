//Created by Pedro Cipriano

void loop_redback(int mode = 1, TString era = "80XD")
	{

	int nmodes = 2;
	TString modes[2] = {"estimate", "final"};
	int nfstates = 4;
	TString fstates[5] = {"4e", "2mu2e", "4mu", "2e2mu","Z2e"};
	int ncategories = 7;
	TString categories[7] = {"ALL", "untagged", "VBF-1j", "VBF-2j", "VH-leptonic", "VH-hadronic", "ttH"};
	int nsamples = 1;
	TString samples[6] = {"ALL", "DY50", "TT", "WZ", "ZZ",""};


	//standard redback loop for all samples and final states
	if (mode == 2)
		{
		for (int i=2;i<nfstates;i++)
			{
			for (int j=0;j<nsamples;j++)
				{
				for (int k=0;k<ncategories;k++)
					{
					redback(fstates[i],samples[j],modes[1],categories[k],era);
					}
				}
			}
		}


	if (mode == 1)
		{
		for (int i=1;i<5;i++) //first already run on loading, 4mu and 2e2mu dont need correction
			{
			redback(fstates[i],samples[0],modes[0],categories[0],era);
			}
		}

	
	}

