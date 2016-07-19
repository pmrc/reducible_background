//Created by Pedro Ciprianpo

#include <iostream>
#include <fstream>
#include <iomanip>

#include <TFile.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TString.h>


void create_cjlst_fakerates(TString era = "80XB")
{

TString year = "";

if (era.Contains("76X")>0) { year = "2015"; }
if (era.Contains("80XA")>0) { year = "2016A"; }
if (era.Contains("80XB")>0) { year = "2016B"; }

TString output_name = "histograms/computed_fakerate/FakeRate_SS_"+year+".root";
TFile *OutPutFile = new TFile(output_name,"RECREATE","",0); 

TString electrons_name = "histograms/computed_fakerate/Z2e/computedfakerate_"+era+".root";
TFile * electrons_file = TFile::Open(electrons_name);

//load barrel electrons
TGraphErrors *electrons_barrel = 0;
TString electrons_barrel_name = "CorrFR_TG_Lep3_pT_all_EB_afterMET_wzremoved_ALL_"+era;
electrons_barrel = (TGraphErrors*) electrons_file->Get(electrons_barrel_name);
if (electrons_barrel == 0)
	{ cout<< electrons_barrel_name << " in " << electrons_name << " not found!" <<endl; return; }
electrons_barrel->SetName("FR_SS_electron_EB");

//load endcap electrons
TGraphErrors *electrons_endcap = 0;
TString electrons_endcap_name = "CorrFR_TG_Lep3_pT_all_EE_afterMET_wzremoved_ALL_"+era;
electrons_endcap = (TGraphErrors*) electrons_file->Get(electrons_endcap_name);
if (electrons_endcap == 0)
	{ cout<< electrons_endcap_name << " in " << electrons_name << " not found!" <<endl; return; }
electrons_endcap->SetName("FR_SS_electron_EE");

TString muons_name = "histograms/computed_fakerate/Zmu/computedfakerate_"+era+".root";
TFile * muons_file = TFile::Open(muons_name);

//load barrel muons
TGraphAsymmErrors *muons_barrel = 0;
TString muons_barrel_name = "TG_Lep3_pT_all_EB_afterMET_wzremoved_ALL_"+era;
muons_barrel = (TGraphAsymmErrors*) muons_file->Get(muons_barrel_name);
if (muons_barrel == 0)
	{ cout<< muons_barrel_name << " in " << muons_name << " not found!" <<endl; return; }
muons_barrel->SetName("FR_SS_muon_EB");

//load endcap muons
TGraphAsymmErrors *muons_endcap = 0;
TString muons_endcap_name = "TG_Lep3_pT_all_EE_afterMET_wzremoved_ALL_"+era;
muons_endcap = (TGraphAsymmErrors*) muons_file->Get(muons_endcap_name);
if (muons_endcap == 0)
	{ cout<< muons_endcap_name << " in " << muons_name << " not found!" <<endl; return; }
muons_endcap->SetName("FR_SS_muon_EE");


OutPutFile->cd();
electrons_barrel->Write();
electrons_endcap->Write();
muons_barrel->Write();
muons_endcap->Write();


}
