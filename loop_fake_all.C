//Created by Pedro Cipriano

void loop_fake_all()
	{
	
TString fstates[2] = {"Ze","Zmu"};
int nfstates = 2;
TString samples[5] = {"ALL", "DY50", "TT", "WZ", "ZZ"};
int nsamples = 5;
TString extras[5] = {"76X", "76XMZ10", "76XMZ7", "76XMZ60","76XM3L5"};
int nextras = 5;

//standard fake loop for all samples and final states
for (int i=0;i<nfstates;i++)
	{
	for (int j=0;j<nsamples;j++)
		{
		loopFake(fstates[i],samples[j],"CRZL","76X");
		}
	}


//aditional fake loop for different extra cuts for Ze channel for all samples
for (int i=1;i<nextras;i++)
	{
	for (int j=0;j<nsamples;j++)
		{
		loopFake(fstates[0],samples[j],"CRZL",extras[i]);
		}
	}

	//Z2e CRZLL - to compute missing hits (need to run redback.C first)
	//loopFake("Ze","ALL","CRZLL","76X");
    	//loopFake("Ze","DY50","CRZLL","76X");
    	//loopFake("Z2e","TT","CRZLL","76X");
	//loopFake("Z2e","WZ","CRZLL","76X");
	//loopFake("Z2e","ZZ","CRZLL","76X");
	}

