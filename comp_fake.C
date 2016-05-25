//#include "SCRIPTS/root_style_setup.C"
#include "macro_utils.C"
//#include "style.C"

// ==============================================================
void comp_fake(TString channel = "4e", TString EXTRA = "")
// ==============================================================
{
  
  //TString channel = "4mu";
  // gROOT->ProcessLine(".L macro_utils.C");
  

  //init_style(gStyle);
  //gROOT->SetBatch();
  //gROOT->Reset();
  //gROOT->SetStyle("Plain");

  //setTDRStyle_rob();

  //loadPresentationStyle();
  //gStyle->SetOptStat(0);
  //gStyle->SetPalette(51);
  //  gROOT->ForceStyle();
  
// ====================================================================================================================================================
  //     DEFINTIONS
  // ====================================================================================================================================================
  // TString file_name1 = "out/output_";
  // //
  // TString file_name2 = "RESULTS/output_mc_ztozz_ztozzee.root";


  std::vector<TString> vec_file_name; vec_file_name.clear();
  //vec_file_name.push_back("out/outputCRZL_ALL_"+channel+"_76XMZ7.root");
  vec_file_name.push_back("out/outputCRZL_ALL_"+channel+"_76X"+EXTRA+".root");
  if(channel=="4e") {
    //vec_file_name.push_back("out/outputCRZL_ALL_"+channel+"_76X.root");
    vec_file_name.push_back("out/outputCRZL_ALL_"+channel+"_76XMZ7"+EXTRA+".root");
    vec_file_name.push_back("out/outputCRZL_ALL_"+channel+"_76XMZ60"+EXTRA+".root");
    vec_file_name.push_back("out/outputCRZL_ALL_"+channel+"_76XM3L5"+EXTRA+".root");
  } // if 4e
    
  TString output_name = "RESULTS/output_FR_"+channel+EXTRA+".root";
  
  TFile *OutPutFile = new TFile(output_name,"RECREATE","",0); 

  // TFile *file1 = TFile::Open(file_name1);
  // TFile *file2 = TFile::Open(file_name2);
  //file->cd(); 

  bool PRINT    = true;
  
  bool doNORM   = false;
  bool do_RW    = true;
  bool doNOT_RW = false;
  bool doLOG    = true;

  //float pi = acos(-1);

  // ====================================================================================================================================================
  //     MODE: ONE INPUT FILE : ALONE HISTO
  // ====================================================================================================================================================
  TString * name_legend = new TString[10];
  name_legend[0] = "Probe electrons"; //pthat>5"; //"with UE";
  name_legend[1] = "Passing Probe electrons"; //pthat>10"; //w/o UE";

  //draw_comp_histo(TFile * file, TFile * OutputFile, TString name_histo_truth, TString name_histo_simu, int REBIN, int range_min, int range_max, 
  //bool print, bool norm, bool do_reweight, bool REBIN1, bool do_turnon, TString * name_legend)
  
  int rebin_pT  = 1;
  int rebin_eta = 10;
  
  //   TString reg[3]  = {"","_EB","_EE"};
 
  // --------------------------------------
    // Lepton FakeRate (DATA, 4e)
    // --------------------------------------
   std::vector<TString> name_vecEB; std::vector<TString> name_vecEE; 
   
  //draw_comp_vechisto(vec_file_name, OutPutFile, "ems_pT_probe"+reg[ir],  "ems_pT_probe_CiCMedium"+reg[ir],rebin_pT, 0,80, PRINT, true, doturn, name_legend, "MC");
  for(unsigned int ifile=0;ifile<vec_file_name.size();ifile++) {
    TFile *file = TFile::Open(vec_file_name.at(ifile));
    TString reduced_name = vec_file_name.at(ifile);
    reduced_name.ReplaceAll("out/outputCRZL_ALL_"+channel+"_", ""); 
    reduced_name.ReplaceAll(".root", ""); 
    cout << "reduce = " << reduced_name << endl;
    draw_comp_histo(file, OutPutFile,"Lep3_pT_all_EB_afterMET",  "Lep3_pT_all_EB_afterIDISO", rebin_pT, 0,80, PRINT, false, false, 1, true, name_legend, reduced_name);
    draw_comp_histo(file, OutPutFile,"Lep3_pT_all_EE_afterMET",  "Lep3_pT_all_EE_afterIDISO", rebin_pT, 0,80, PRINT, false, false, 1, true, name_legend, reduced_name);

    if(channel=="4e") {
      name_vecEB.push_back("TG_Lep3_pT_all_EB_afterMET_"+reduced_name);
      name_vecEE.push_back("TG_Lep3_pT_all_EE_afterMET_"+reduced_name);
    } // if 4e

    if(channel=="4mu") { 
      name_vecEB.push_back("TG_Lep3_pT_all_EB_afterMET_"+reduced_name);
      name_vecEB.push_back("TG_Lep3_pT_all_EE_afterMET_"+reduced_name);
    } // if 4mu
    //draw_comp_histo(TFile * file, TFile * OutputFile, TString name_histo_truth, TString name_histo_simu, int REBIN, double range_min, double range_max, 
    //bool print, bool norm, bool do_reweight, bool REBIN1, bool do_turnon, TString * name_legend, TString extra_name); 
  } // file_name_size
  
  
  if(channel=="4e") {
    // -------------------------------------
    // Compare Lepton FakeRate (DATA, 4e)
    // --------------------------------------
    //void draw_comp_vecturnons(TFile * OutputFile, std::vector<TString> name_TG, int REBIN, double range_min, double range_max, 
    //bool print, TString * name_legend, TString extra_name)
    name_legend[0] = "40<MZ<120"; 
    name_legend[1] = "|MZ-91.2|<7";
    name_legend[2] = "60<MZ<120"; 
    name_legend[3] = "|M3L-91.2|<5";
    
    draw_comp_vecturnons(OutPutFile, name_vecEB, 1, 0, 80, PRINT, name_legend, "SS");
    draw_comp_vecturnons(OutPutFile, name_vecEE, 1, 0, 80, PRINT, name_legend, "SS");

    // --------------------------------------
    //         FR vs Missing Hits
    // --------------------------------------
    //Lep3pT710, Lep3pT1020, Lep3pT2030, Lep3pT3040, Lep3pT4050,Lep3pT5080
    TString pTbins[6] = {"710", "1020", "2030", "3040", "4050", "5080"};
    TString file_ZLL = "out/outputCRZLL_ALL_4e_76X.root";
   
    if(EXTRA.Contains("incl")>0) {
      comp_FRMhits(vec_file_name, name_vecEB, OutPutFile, "Lep3_inclmhits_EB", file_ZLL, "Lep34_inclmhits_EB");
      comp_FRMhits(vec_file_name, name_vecEE, OutPutFile, "Lep3_inclmhits_EE", file_ZLL, "Lep34_inclmhits_EE");
    }
    else {
 
      for(int i=0;i<6;i++) {
	comp_FRMhits(vec_file_name, name_vecEB, OutPutFile, "Lep3_mhits_EB_pT"+pTbins[i], file_ZLL, "Lep34_mhits_EB_pT"+pTbins[i]);
	comp_FRMhits(vec_file_name, name_vecEE, OutPutFile, "Lep3_mhits_EE_pT"+pTbins[i], file_ZLL, "Lep34_mhits_EE_pT"+pTbins[i]);
      } // for loop on pT bins
      //void comp_FRMhits(std::vector<TString> vec_file_name, std::vector<TString> vec_fakename_EBEE, TFile* OutputFile, TString mhitsname)
    } // else 
    
    // --------------------------------------
    //         FR vs Corrected FR
    // --------------------------------------
    //void draw_comp_inclcorrFR(TFile* OutputFile, TString name_FR)
    if(EXTRA.Contains("incl")>0) {
      draw_comp_inclcorrFR(OutPutFile, name_vecEB.at(0));
      draw_comp_inclcorrFR(OutPutFile, name_vecEE.at(0));
    }
    else {
      draw_comp_corrFR(OutPutFile, name_vecEB.at(0));
      draw_comp_corrFR(OutPutFile, name_vecEE.at(0));
    } // else pT 
   
  } // if channel = 4e

   // -------------------------------------
   // Compare Lepton FakeRate (DATA, 4mu)
   // --------------------------------------
  if(channel=="4mu") {
    //void draw_comp_vecturnons(TFile * OutputFile, std::vector<TString> name_TG, int REBIN, double range_min, double range_max, 
    //bool print, TString * name_legend, TString extra_name)
    name_legend[0] = "Barrel"; //0<MZ<120"; 
    name_legend[1] = "Endcaps"; //|MZ-91.2|<10";
    
    draw_comp_vecturnons(OutPutFile, name_vecEB, 1, 0, 80, PRINT, name_legend, "SS4mu");
  } // if 4mu
 
 
  cout << "---> Draw Comp Turnons " << endl;

  cout << "" << endl;

  cout << "---------------> Closing File : " << output_name  << endl;

} // fin de la macro
