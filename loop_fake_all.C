//Created by Pedro Cipriano

void loop_fake_all()
	{
	/*
	//4e - basic
	loopFake("4e","ALL","CRZL","76X");
    	loopFake("4e","DY50","CRZL","76X");
    	loopFake("4e","TT","CRZL","76X");
	loopFake("4e","WZ","CRZL","76X");
	loopFake("4e","ZZ","CRZL","76X");
	//4e MZ10 - cuts required to computed the corrected fakerate
	loopFake("4e","ALL","CRZL","76XMZ10");
    	loopFake("4e","DY50","CRZL","76XMZ10");
    	loopFake("4e","TT","CRZL","76XMZ10");
	loopFake("4e","WZ","CRZL","76XMZ10");
	loopFake("4e","ZZ","CRZL","76XMZ10");
	//4e MZ7 - cuts required to computed the corrected fakerate
	loopFake("4e","ALL","CRZL","76XMZ7");
    	loopFake("4e","DY50","CRZL","76XMZ7");
    	loopFake("4e","TT","CRZL","76XMZ7");
	loopFake("4e","WZ","CRZL","76XMZ7");
	loopFake("4e","ZZ","CRZL","76XMZ7");
	//4e MZ60 - cuts required to computed the corrected fakerate
	loopFake("4e","ALL","CRZL","76XMZ60");
    	loopFake("4e","DY50","CRZL","76XMZ60");
    	loopFake("4e","TT","CRZL","76XMZ60");
	loopFake("4e","WZ","CRZL","76XMZ60");
	loopFake("4e","ZZ","CRZL","76XMZ60");
	//4e M3L5 - cuts required to computed the corrected fakerate
	loopFake("4e","ALL","CRZL","76XM3L5");
    	loopFake("4e","DY50","CRZL","76XM3L5");
    	loopFake("4e","TT","CRZL","76XM3L5");
	loopFake("4e","WZ","CRZL","76XM3L5");
	loopFake("4e","ZZ","CRZL","76XM3L5");
	*/

	//4e CRZLL - to compute missing hits
	loopFake("4e","ALL","CRZLL","76X");
    	loopFake("4e","DY50","CRZLL","76X");
    	loopFake("4e","TT","CRZLL","76X");
	loopFake("4e","WZ","CRZLL","76X");
	loopFake("4e","ZZ","CRZLL","76X");

	/*
	//4mu
	loopFake("4mu","ALL","CRZL","76X");
    	loopFake("4mu","DY50","CRZL","76X");
    	loopFake("4mu","TT","CRZL","76X");
	loopFake("4mu","WZ","CRZL","76X");
	loopFake("4mu","ZZ","CRZL","76X");


	//2e2mu
	loopFake("2e2mu","ALL","76X");
    	loopFake("2e2mu","DY50","76X");
    	loopFake("2e2mu","TT","76X");
	loopFake("2e2mu","WZ","76X");
	loopFake("2e2mu","ZZ","76X");
	//2e2mu MZ10
	loopFake("2e2mu","ALL","76XMZ10");
    	loopFake("2e2mu","DY50","76XMZ10");
    	loopFake("2emu","TT","76XMZ10");
	loopFake("2e2mu","WZ","76XMZ10");
	loopFake("2e2mu","ZZ","76XMZ10");
	//2e2mu MZ7
	loopFake("2e2mu","ALL","76XMZ7");
    	loopFake("2e2mu","DY50","76XMZ7");
    	loopFake("2e2mu","TT","76XMZ7");
	loopFake("2e2mu","WZ","76XMZ7");
	loopFake("2e2mu","ZZ","76XMZ7");
	//2e2mu MZ60
	loopFake("2e2mu","ALL","76XMZ60");
    	loopFake("2e2mu","DY50","76XMZ60");
    	loopFake("2e2mu","TT","76XMZ60");
	loopFake("2e2mu","WZ","76XMZ60");
	loopFake("2e2mu","ZZ","76XMZ60");
	//2e2mu M3L5
	loopFake("2e2mu","ALL","76XM3L5");
    	loopFake("2e2mu","DY50","76XM3L5");
    	loopFake("2e2mu","TT","76XM3L5");
	loopFake("2e2mu","WZ","76XM3L5");
	loopFake("2e2mu","ZZ","76XM3L5");


	//2mu2e
	loopFake("2mu2e","ALL","76X");
    	loopFake("2mu2e","DY50","76X");
    	loopFake("2mu2e","TT","76X");
	loopFake("2mu2e","WZ","76X");
	loopFake("2mu2e","ZZ","76X");
	//2mu2e MZ10
	loopFake("2mu2e","ALL","76XMZ10");
    	loopFake("2mu2e","DY50","76XMZ10");
    	loopFake("2mu2e","TT","76XMZ10");
	loopFake("2mu2e","WZ","76XMZ10");
	loopFake("2mu2e","ZZ","76XMZ10");
	//2mu2e MZ7
	loopFake("2mu2e","ALL","76XMZ7");
    	loopFake("2mu2e","DY50","76XMZ7");
    	loopFake("2mu2e","TT","76XMZ7");
	loopFake("2mu2e","WZ","76XMZ7");
	loopFake("2mu2e","ZZ","76XMZ7");
	//2mu2e MZ60
	loopFake("2mu2e","ALL","76XMZ60");
    	loopFake("2mu2e","DY50","76XMZ60");
    	loopFake("2mu2e","TT","76XMZ60");
	loopFake("2mu2e","WZ","76XMZ60");
	loopFake("2mu2e","ZZ","76XMZ60");
	//2mu2e M3L5
	loopFake("2mu2e","ALL","76XM3L5");
    	loopFake("2mu2e","DY50","76XM3L5");
    	loopFake("2mu2e","TT","76XM3L5");
	loopFake("2mu2e","WZ","76XM3L5");
	loopFake("2mu2e","ZZ","76XM3L5");
	*/
	}

