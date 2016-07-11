//Created by Pedro Cipriano

#include <iostream>
#include <fstream>
#include <iomanip>

#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLegend.h>

void remove_wz(TString data, TString wz, TString channel, TFile *OutputFile, TString swz, TString EXTRA)
    	{

    	TH1D *hdata = 0;
    	hdata = (TH1D*) OutputFile->Get(data);
    	if (hdata == 0) { cout<< data << " in " << OutputFile << " not found!" <<endl; return; }
    	TFile *fwz = TFile::Open(swz);
    	TH1D *hwz = (TH1D*) fwz->Get(wz);
    	if (hwz == 0) { cout<< wz << " in " << swz << " not found!" <<endl; return; }

    	TH1 *wzremoved = (TH1*) hdata->Clone(data+"_wzremoved");

        //cout << wzremoved->GetName() << endl;
    	wzremoved->Add(hwz,-1);

    	OutputFile->cd();
    	wzremoved->Write();


	TCanvas * TC_corrFR = new TCanvas("CORRFR_"+channel+"_"+data+EXTRA, "CORRFR_"+channel+"_"+data+EXTRA, 800, 600);
  	gPad->SetGrid();

	hdata->SetMarkerColor(1);
  	hdata->SetLineColor(1);
  	hdata->Draw();
	wzremoved->SetMarkerColor(2);
  	wzremoved->SetLineColor(2);
  	wzremoved->Draw("same");

  	TLegend *legend = new TLegend(0.30,0.6835664,0.60,0.8916084,NULL,"brNDC");
  	legend->SetTextSize(0.03811252); //(0.035); 
  	legend->SetTextFont(42);
  	legend->SetLineColor(0);
  	legend->SetLineStyle(1);
  	legend->SetLineWidth(1);
  	legend->SetFillColor(0);
  	legend->SetFillStyle(0);
  	legend->AddEntry(hdata, "Uncorrected Fake Rate","lp");
  	legend->AddEntry(wzremoved, "Corrected Fake Rate","lp");
  	legend->Draw();

  	TC_corrFR->Print("PLOTS/png/" + channel + "_wzremoval_"+data+"_"+EXTRA+".png");
  	TC_corrFR->Print("PLOTS/pdf/" + channel + "_wzremoval_"+data+"_"+EXTRA+".pdf");


    	}


void wzremoval(TString channel = "Ze", TString era = "80XA", TString EXTRA = "")
{


TString fdata = "histograms/FR/"+channel+"/FR_CRZL_ALL_"+era+EXTRA+".root";
TString fwz = "histograms/FR/"+channel+"/FR_CRZL_WZ_"+era+EXTRA+".root";

cout << "Opening " << fdata << "..." << endl;

TFile *Output = new TFile(fdata,"UPDATE"); 

remove_wz("Lep3_pT_all_EB_afterMET", "Lep3_pT_all_EB_afterMET", channel, Output, fwz, EXTRA);
remove_wz("Lep3_pT_all_EE_afterMET", "Lep3_pT_all_EE_afterMET", channel, Output, fwz, EXTRA);
remove_wz("Lep3_pT_all_EB_afterIDISO", "Lep3_pT_all_EB_afterIDISO", channel, Output, fwz, EXTRA);
remove_wz("Lep3_pT_all_EE_afterIDISO", "Lep3_pT_all_EE_afterIDISO", channel, Output, fwz, EXTRA);

if (channel == "Ze")
{

fdata = "histograms/FR/"+channel+"/FR_CRZL_ALL_"+era+"MZ10"+EXTRA+".root";
fwz = "histograms/FR/"+channel+"/FR_CRZL_WZ_"+era+"MZ10"+EXTRA+".root";

cout << "Opening " << fdata << "..." << endl;

Output = new TFile(fdata,"UPDATE"); 

remove_wz("Lep3_pT_all_EB_afterMET", "Lep3_pT_all_EB_afterMET", channel, Output, fwz, "MZ10"+EXTRA);
remove_wz("Lep3_pT_all_EE_afterMET", "Lep3_pT_all_EE_afterMET", channel, Output, fwz, "MZ10"+EXTRA);
remove_wz("Lep3_pT_all_EB_afterIDISO", "Lep3_pT_all_EB_afterIDISO", channel, Output, fwz, "MZ10"+EXTRA);
remove_wz("Lep3_pT_all_EE_afterIDISO", "Lep3_pT_all_EE_afterIDISO", channel, Output, fwz, "MZ10"+EXTRA);


fdata = "histograms/FR/"+channel+"/FR_CRZL_ALL_"+era+"MZ7"+EXTRA+".root";
fwz = "histograms/FR/"+channel+"/FR_CRZL_WZ_"+era+"MZ7"+EXTRA+".root";

cout << "Opening " << fdata << "..." << endl;

Output = new TFile(fdata,"UPDATE"); 

remove_wz("Lep3_pT_all_EB_afterMET", "Lep3_pT_all_EB_afterMET", channel, Output, fwz, "MZ7"+EXTRA);
remove_wz("Lep3_pT_all_EE_afterMET", "Lep3_pT_all_EE_afterMET", channel, Output, fwz, "MZ7"+EXTRA);
remove_wz("Lep3_pT_all_EB_afterIDISO", "Lep3_pT_all_EB_afterIDISO", channel, Output, fwz, "MZ7"+EXTRA);
remove_wz("Lep3_pT_all_EE_afterIDISO", "Lep3_pT_all_EE_afterIDISO", channel, Output, fwz, "MZ7"+EXTRA);


fdata = "histograms/FR/"+channel+"/FR_CRZL_ALL_"+era+"MZ60"+EXTRA+".root";
fwz = "histograms/FR/"+channel+"/FR_CRZL_WZ_"+era+"MZ60"+EXTRA+".root";

cout << "Opening " << fdata << "..." << endl;

Output = new TFile(fdata,"UPDATE"); 

remove_wz("Lep3_pT_all_EB_afterMET", "Lep3_pT_all_EB_afterMET", channel, Output, fwz, "MZ60"+EXTRA);
remove_wz("Lep3_pT_all_EE_afterMET", "Lep3_pT_all_EE_afterMET", channel, Output, fwz, "MZ60"+EXTRA);
remove_wz("Lep3_pT_all_EB_afterIDISO", "Lep3_pT_all_EB_afterIDISO", channel, Output, fwz, "MZ60"+EXTRA);
remove_wz("Lep3_pT_all_EE_afterIDISO", "Lep3_pT_all_EE_afterIDISO", channel, Output, fwz, "MZ60"+EXTRA);


fdata = "histograms/FR/"+channel+"/FR_CRZL_ALL_"+era+"M3L5"+EXTRA+".root";
fwz = "histograms/FR/"+channel+"/FR_CRZL_WZ_"+era+"M3L5"+EXTRA+".root";

cout << "Opening " << fdata << "..." << endl;

Output = new TFile(fdata,"UPDATE"); 

remove_wz("Lep3_pT_all_EB_afterMET", "Lep3_pT_all_EB_afterMET", channel, Output, fwz, "M3L5"+EXTRA);
remove_wz("Lep3_pT_all_EE_afterMET", "Lep3_pT_all_EE_afterMET", channel, Output, fwz, "M3L5"+EXTRA);
remove_wz("Lep3_pT_all_EB_afterIDISO", "Lep3_pT_all_EB_afterIDISO", channel, Output, fwz, "M3L5"+EXTRA);
remove_wz("Lep3_pT_all_EE_afterIDISO", "Lep3_pT_all_EE_afterIDISO", channel, Output, fwz, "M3L5"+EXTRA);

}

}
