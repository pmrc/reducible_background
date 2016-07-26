//Created by Pedro Cipriano

void loop_fake_all(TString era = "80XD")
	{

int nfstates = 2;	
TString fstates[2] = {"Ze","Zmu"};
int nsamples = 2;
TString samples[5] = {"ALL", "WZ", "DY50", "TT", "ZZ"};
int nextras = 5;
TString extras[5] = {era, era+"MZ10", era+"MZ7", era+"MZ60",era+"M3L5"};


//standard fake loop for all samples and final states
for (int i=0;i<nfstates;i++) //first is done on loading
	{
	for (int j=1;j<nsamples;j++)
		{
		loopFake(fstates[i],samples[j],"CRZL",era);
		}
	}


//aditional fake loop for different extra cuts for Ze channel for all samples
for (int i=1;i<nextras;i++) //first is done the loop above
	{
	for (int j=1;j<nsamples;j++)
		{
		loopFake(fstates[0],samples[j],"CRZL",extras[i]);
		}
	}



//aditional fake loop to cross-check phillip results
	for (int j=1;j<nsamples;j++)
		{
		loopFake(fstates[1],samples[j],"CRZL",extras[3]);
		}

}
