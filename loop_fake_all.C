//Created by Pedro Cipriano

void loop_fake_all(TString era = "80XB")
	{

int nfstates = 2;	
TString fstates[2] = {"Ze","Zmu"};
int nsamples = 5;
TString samples[5] = {"ALL", "DY50", "TT", "WZ", "ZZ"};
int nextras = 5;
TString extras[5] = {era, era+"MZ10", era+"MZ7", era+"MZ60",era+"M3L5"};


//standard fake loop for all samples and final states
for (int i=0;i<nfstates;i++) //first is done on loading
	{
	for (int j=0;j<nsamples;j++)
		{
		loopFake(fstates[i],samples[j],"CRZL",era);
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

}
