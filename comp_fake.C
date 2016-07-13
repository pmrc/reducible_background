//Created by Christophe Orchando
//Modified by Pedro Cipriano

#include <iostream>
#include <fstream>
#include <iomanip>

#include <TFile.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TH1F.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TLegend.h>

#include "macro_utils.C"


// ==================================================================================================================================
void draw_comp_histo(TFile * file, TString channel, TFile * OutputFile, TString name_histo_truth, TString name_histo_simu, int REBIN, double range_min, double range_max, 
		     bool print, bool norm, bool do_reweight, bool REBIN1, bool do_turnon, TString * name_legend, TString extra_name) //, TGraphAsymmErrors * TG_turn)
// ==================================================================================================================================
{
  
  //gStyle->SetOptStat(0000);
  
  TH1F* histo_truth;
  TH1F* histo_simu;
  
  cout << "Draw Comp Histo -----------------> Histo for : " << name_histo_truth << "     and " << name_histo_simu << " extra = " << extra_name << endl; //Xhisto_pass << endl;
  
  TString reduced_name = name_histo_truth; //TString
  //reduced_name.Remove("0","/");
  reduced_name.ReplaceAll("/", ""); //name_histo, "/","");
  //name_histo.Remove("/");
  cout << "-----------------> Histo for : " << reduced_name << endl; 

  histo_truth = (TH1F*)file->Get(name_histo_truth); //"JET_PT_1");
  histo_simu  = (TH1F*)file->Get(name_histo_simu); 
  
  TCanvas * TC_histo = new TCanvas("TC_"+name_histo_simu+"_"+extra_name,"TC_"+name_histo_simu+"_"+extra_name,800,600);
  drawCMS();
  
  // ----------------
  //  Create Legend
  // ----------------
  //   TLegend* legend = new TLegend(0.70,0.7,0.99,0.99);
  //   legend->SetTextSize(0.02); 
  TLegend* legend;
  if      (name_histo_truth.Contains("fbrem")) legend = new TLegend(0.6155779,0.1643357,0.8442211,0.4020979,NULL,"brNDC");
  else if (name_histo_truth.Contains("sigma") || name_histo_truth.Contains("N_em") )  legend = new TLegend(0.620603,0.6381119,0.8492462,0.8758741,NULL,"brNDC");
  else if (name_histo_truth.Contains("he")    || name_histo_truth.Contains("iso"))    legend = new TLegend(0.620603,0.6381119,0.8492462,0.8758741,NULL,"brNDC");
  else if (name_histo_truth.Contains("Sig"))  legend = new TLegend(0.4, 0.168, 0.63, 0.4, NULL,"brNDC");
  //else if (name_histo_truth.Contains("MVA"))  legend = new TLegend(0.3994975,0.7604895,0.6256281,0.9685315,NULL,"brNDC"); //legend = new TLegend(0.4, 0.968, 0.93, 0.6, NULL,"brNDC");
  else if (name_histo_truth.Contains("MVA"))  legend = new TLegend(0.4535176,0.7185315,0.6796482,0.9265734,NULL,"brNDC");
  //&& name_histo_truth.Contains("EE")) 
  //else legend = new TLegend(0.1520101,0.6346154,0.3806533,0.8723776,NULL,"brNDC");
  else legend = new TLegend(0.7236181,0.7587413,0.9434673,0.9667832,NULL,"brNDC");

  //(0.6545226,0.1171329,0.8831658,0.3548951);
  //legend->SetTextSize(0.02); 
  legend->SetTextFont(42);
  legend->SetTextSize(0.03496503);
  legend->SetFillColor(kWhite);
  legend->SetBorderSize(0);
  
  //TH_DATA->GetYaxis()->SetTitle(TString(tmp_string)+" "+TString(unit));

  if(REBIN1) histo_truth->Rebin(REBIN);
  histo_truth->SetFillColor(kBlue); //kRed); //9);
  histo_truth->SetFillStyle(3005); //3003);
  histo_truth->SetLineColor(kBlue); //kRed);
  histo_truth->SetLineWidth(3);
  histo_truth->GetXaxis()->SetRangeUser(range_min,range_max);
  legend->AddEntry(histo_truth, name_legend[0],"lf");
 
  histo_simu->Rebin(REBIN);
  //histo_simu->SetMarkerStyle(21);
  histo_simu->SetFillColor(kRed); //kBlue); //2);
  histo_simu->SetFillStyle(0); //3003);
  histo_simu->SetLineWidth(3);
  histo_simu->SetLineStyle(2);
  histo_simu->SetLineColor(kRed); //kBlue);
  //histo_simu->SetLineColor(1); //2);
  //histo_simu->SetMarkerColor(1);//2);
  //histo_simu->SetMarkerStyle(20);
  legend->AddEntry(histo_simu,name_legend[1],"l");
  
  // 
  int NB_bins1 = histo_truth->GetNbinsX();
  
  double NB_truth = histo_truth->Integral(0,NB_bins1+1);
  double NB_simu  = histo_simu->Integral(0,NB_bins1+1);
  
  string unit = "GeV";
  if(name_histo_truth.Contains("Delta_phi"))  unit = "rad";
  else if(name_histo_truth.Contains("eta"))   unit = "";
  else if(name_histo_truth.Contains("fbrem")) unit = "";
  else if(name_histo_truth.Contains("sigma")) unit = "";
  else if(name_histo_truth.Contains("Sig"))   unit = "";
  else if(name_histo_truth.Contains("Rel"))   unit = "";
  else if(name_histo_truth.Contains("MVA"))   unit = "";
  double bin = histo_truth->GetBinWidth(1);
  char  tmp_string[500];
  sprintf(tmp_string, "Events/ %.2f", bin); // unit);
  
  histo_truth->GetYaxis()->SetTitle(TString(tmp_string)+" "+TString(unit));
  if(name_histo_truth.Contains("MVA")) { 
    histo_truth->GetYaxis()->SetTitle("a.u.");
    histo_truth->GetXaxis()->SetTitle("MVA eID Output");
  }
 
  // Max
  if(histo_truth->GetMaximum()< histo_simu->GetMaximum()) {
    //histo_file1->SetMaximum(1.2*histo_file2->GetMaximum());
    histo_truth->GetYaxis()->SetRangeUser(0., 1.2*histo_simu->GetMaximum());
  }
  else {
    //histo_file1->SetMaximum(1.2*histo_file1->GetMaximum());
    histo_truth->GetYaxis()->SetRangeUser(0., 1.2*histo_truth->GetMaximum());
  } // else
  
  if(histo_truth->GetMaximum()< histo_simu->GetMaximum()) histo_truth->SetMaximum(1.2*histo_simu->GetMaximum());

  if(norm==true) {
    double scale = 1;
    if(NB_simu!=0) scale = double(NB_truth)/(double)NB_simu;
   
    //histo_truth->SetMinimum(0.01);
    //gPad->SetLogy(); 
    histo_truth->Draw("HIST");//Normalized("HIST");
    histo_simu->Scale(scale);
    histo_simu->Draw("HISTSAME"); //Normalized(
  } // if norm
  else {
    histo_truth->Draw("HIST");
    histo_simu->Draw("HISTSAME"); //SAME");
  } // else norme

  legend->Draw();


  // ----------------------
  //       LOG
  // ----------------------
  TCanvas * TC_log_histo = new TCanvas("LOG_"+name_histo_simu+"_"+extra_name,"LOG_"+name_histo_simu+"_"+extra_name,800,600);
  histo_truth->SetMinimum(0.01);
  //drawCMS();

  gPad->SetLogy();
 
  histo_truth->Draw("HIST");//Normalized("HIST");
  //   histo_simu->Scale(scale);
  histo_simu->Draw("HISTSAME");
  
  drawCMS();

  legend->Draw();

  // ----------------------
  //  Write Canvas/Graphs
  // ----------------------
  OutputFile->cd();
  TC_histo->Write("COMP_"+reduced_name+"_"+extra_name);
  TC_log_histo->Write("LOG_COMP_"+reduced_name+"_"+extra_name);
  //  Print the plots...
  if(print) {
    TC_histo->Print("PLOTS/png/"+channel+"_COMP_"+reduced_name+"_"+extra_name+".png");
    TC_log_histo->Print("PLOTS/png/"+channel+"_LOG_COMP_"+reduced_name+"_"+extra_name+".png");
    TC_log_histo->Print("PLOTS/C/"+channel+"_LOG_COMP_"+reduced_name+"_"+extra_name+".C");
    TC_log_histo->Print("PLOTS/root/"+channel+"_LOG_COMP_"+reduced_name+"_"+extra_name+".root");
  } //print

  // ------------------
  //     Turnon...
  // ------------------
  TGraphAsymmErrors * TG_turn_temp  = new TGraphAsymmErrors();
  
  if(do_turnon) {
    // Build Latex Box
    //TLatex* TL_higgs = new TLatex(0.17,0.82, "H#rightarrowZZ*#rightarrow4e   m_{H}=150 GeV/c^{2}"); //"");
    //TL_pT->SetTextFont(12);
    //TL_higgs->SetTextColor(1);   // 4
    //TL_higgs->SetTextAlign(12);
    //TL_higgs->SetTextSize(0.05);
    //TL_higgs->SetNDC();

    TLegendEntry *entry;
    TLegend *leg4 = new TLegend(0.304,0.19,0.741,0.28,NULL,"brNDC");
    leg4->SetTextSize(0.047);
    leg4->SetTextAlign(22);
    leg4->SetLineColor(0);
    leg4->SetLineWidth(0);
    leg4->SetFillColor(kWhite);    
    // leg4->SetFillStyle(0);    
    leg4->SetMargin(0.01);
    //leg4->AddEntry(hptvseta,"H#rightarrowZZ*#rightarrow4e   m_{H}=150 GeV/c^{2}","");

    // TGraphErrors
    TCanvas * TC_histo_turnon = new TCanvas("TC_Turnon_"+reduced_name+"_"+extra_name,"TC_Turnon_"+reduced_name+"_"+extra_name,800,600);
    TC_histo->ToggleEventStatus();
    gPad->SetGrid();  

    //TG_turn = new TGraphAsymmErrors();
    TG_turn_temp->BayesDivide(histo_simu, histo_truth);
    //TG_turn_temp->Divide(histo_simu, histo_truth, "e0");
    TG_turn_temp->SetLineColor(9);
    TG_turn_temp->SetMarkerColor(9);
    TG_turn_temp->SetMarkerStyle(20);
    TG_turn_temp->GetXaxis()->SetLimits(range_min, range_max);
    TG_turn_temp->SetMinimum(0.);  // 0.4
    TG_turn_temp->SetMaximum(0.8); // 1.
    TG_turn_temp->GetYaxis()->SetTitle("Fake Rate"); //Efficiency"); //Electron ID efficiency");
    //leg4->AddEntry(TG_turn_temp,"H#rightarrowZZ*#rightarrow4e   m_{H}=150 GeV/c^{2}","");
    //
    TString xname =  histo_truth->GetXaxis()->GetTitle();
    TG_turn_temp->GetXaxis()->SetTitle(xname);
    //
    TG_turn_temp->Draw("AP");
    //leg4->Draw();
    //
    
    // -----------------------
    // Simple Divide
    // -----------------------
    TCanvas * TC_histo_divide = new TCanvas("TC_divide_"+reduced_name+"_"+extra_name,"TC_divide_"+reduced_name+"_"+extra_name,800,600);
    gPad->SetGrid();  
    histo_simu->Divide(histo_truth);
    histo_simu->SetLineWidth(2);
    histo_simu->SetMarkerStyle(20);
    histo_simu->SetMarkerColor(9);
    //histo_simu->SetFillColor(9);
    //histo_simu->SetFillStyle(3003);
    histo_simu->SetLineColor(9);
    histo_simu->GetXaxis()->SetRangeUser(range_min, range_max);
    histo_simu->SetTitle("");
    histo_simu->GetYaxis()->SetTitle("Efficiency");
    histo_simu->GetYaxis()->SetRangeUser(0.0,1.);
    histo_simu->Draw("P"); //HIST");
    //leg4->Draw();

    // Print the plots
    if(print) {
      TC_histo_turnon->Print("PLOTS/png/"+channel+"_Turnon_"+reduced_name+"_"+extra_name+".png");
      //TC_histo_turnon->Print("PLOTS/Turnon_"+name_histo_simu+".eps");
      TC_histo_divide->Print("PLOTS/png/"+channel+"_Divide_"+reduced_name+"_"+extra_name+".png");
      //TC_histo_divide->Print("PLOTS/Divide_"+name_histo_simu+".eps");
    }

    


    // -----------------------
    // Write the plots
    // -----------------------
    OutputFile->cd();
    TG_turn_temp->Write("TG_"+reduced_name+"_"+extra_name);
    histo_simu->Write("Divide_"+reduced_name+"_"+extra_name);
    TC_histo_turnon->Write("Turnon_"+reduced_name+"_"+extra_name);
    TC_histo_divide->Write("TC_Divide_"+reduced_name+"_"+extra_name);
  } // if do turnon

 
  //if(name_histo_truth=="JET_PT_2_after_truth" || name_histo_truth=="JET_PT_after_truth_L3_v15all" || name_histo_truth=="JET_PT_after_truth_L3_v1520"
  // || name_histo_truth=="JET_PT_after_truth_L3_v15" || name_histo_truth=="JET_PT_2_afterL1_truth") {
  if(do_turnon) {
    cout << " $$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << " NB before = " << NB_truth << endl; //histo_truth->Integral() << endl;
    cout << " NB truth  = " << NB_simu << endl; //histo_simu->Integral() << endl;
    float RATIO = (float)NB_simu/(float)NB_truth;
    cout << " Ratio     = " << RATIO << endl;
    cout << " $$$$$$$$$$$$$$$$$$$$$$" << endl;

    double eff = 0.;
    //if(NB_before!=0) {
      //eff = double(NB_simu)/double(NB_truth);
    //   } 
    //double errro = 

  } // if name
  
  // --------------
  //  REWEIGHTING
  // --------------  
  if(do_reweight) {

    ofstream norm_data(TString("COMP_QCD/DAT/RW_"+reduced_name+".dat"),ios::out); //"_"+extra+".dat"),ios::out);
    
    int NB = histo_truth->GetXaxis()->GetNbins();

    //float ratio[NB];
    
    for(int i=1;i<=NB+1;i++) {
      float diff = 0;
      if(histo_truth->GetBinContent(i)!=0) diff = histo_simu->GetBinContent(i)/histo_truth->GetBinContent(i);
      
      norm_data  << diff << endl;
      //	cout << "MC = " << vect_photonpT[0]->GetBinContent(i) << "   data = " << vect_photonpT[1]->GetBinContent(i) << "  diff = " << diff[i] << "  " << i << endl;
    } // for
    norm_data.close(); 
  } // if do_reweight 
  

  //  if(do_turnon) 
  //if(do_turnon) { 
    //TG_turn = new TGraphAsymmErrors();
    //*TG_turn = *TG_turn_temp;}

  //TCanvas * TC_new = new TCanvas("c1","c1",800,600);
  //TG_turn->Draw("AP");
 
  //TC_new->Write("new_"+name_histo_simu);
 
 //  cout << "hey" << endl;
  
//   cout << "prout" << endl;
}



// ==================================================================================================================================
void comp_FRMhits(std::vector<TString> vec_file_name, TString channel, std::vector<TString> vec_fakename_EBEE, TH1F *corr, TH1F *corr_up, TH1F *corr_down, TH1F *hmhits_plot, TFile* OutputFile, TString mhitsname, TString file_ZLL, TString mhitsnameZLL)
//(vec_file_name, name_vecEB, OutPutFile, "Lep3_mhits_EE_pT1020");
// ==================================================================================================================================
{

  TCanvas * TC_FRvsMhits = new TCanvas("FRvsMhits_"+mhitsname, "FRvsMhits_"+mhitsname, 800, 600);
  gPad->SetGrid();

  double * fakerate = new double[8];
  double * fakerateErr = new double[8];
  double * mhits = new double[8];
  double * mhitsErr = new double[8];
   
  int fakebin=0;
  //Lep3pT710, Lep3pT1020, Lep3pT2030, Lep3pT3040, Lep3pT4050,Lep3pT5080
  if(mhitsname.Contains("710")>0) fakebin = 0;
  if(mhitsname.Contains("1020")>0) fakebin = 1;
  if(mhitsname.Contains("2030")>0) fakebin = 2;
  if(mhitsname.Contains("3040")>0) fakebin = 3;
  if(mhitsname.Contains("4050")>0) fakebin = 4;
  if(mhitsname.Contains("5080")>0) fakebin = 5;
  
  cout << "fake bin = " << fakebin << endl;

  TH1F *hmhits = 0;
  hmhits = new TH1F("mhits","Lep3_pT",vec_file_name.size(), 0, vec_file_name.size());;


  for(unsigned int i=0;i<vec_file_name.size();i++) {
    TFile *file = TFile::Open(vec_file_name.at(i)); 
    TH1F* h_mhits = (TH1F*)file->Get(mhitsname);
    mhits[i] = h_mhits->GetMean();
    mhitsErr[i] = h_mhits->GetMeanError();
    hmhits->SetBinContent(i+1,h_mhits->GetMean());
    hmhits->SetBinError(i+1,h_mhits->GetMeanError());
    //cout << "mhits = " << mhits[i] << endl;
  } // for loop on mhits

  for(unsigned int j=0;j<vec_fakename_EBEE.size();j++) {
    cout <<  "Graph = " << vec_fakename_EBEE.at(j) << endl;
    TGraph* h_fake = (TGraph*)OutputFile->Get(vec_fakename_EBEE.at(j));
    double*yfake = h_fake->GetY(); //BinContent(fakebin);
    double*yfakeErr = h_fake->GetEYhigh();
    fakerate[j] = yfake[fakebin];
    fakerateErr[j] = yfakeErr[fakebin];
    cout << "fake = " <<  fakerate[j] << endl;
  } // for loop on fake rate
  
  cout << "Size = " << vec_file_name.size() << endl;

  TGraph * FRvsMhits = new TGraphErrors(vec_file_name.size(), mhits, fakerate, mhitsErr, fakerateErr);
  FRvsMhits->SetTitle("");
  FRvsMhits->SetMarkerStyle(20);
  FRvsMhits->Draw("AP");
  FRvsMhits->GetXaxis()->SetTitle("<Missing Hits>");
  FRvsMhits->GetYaxis()->SetTitle("Fake Rate");

  // -----------------------
  //        Fit
  // -----------------------
  TF1 *f1 = new TF1("f1", "pol1"); //, 1, 3);
  FRvsMhits->Fit("f1");
  TFitResultPtr r = FRvsMhits->Fit(f1,"S");
  //TMatrixDSym cov = r->GetCovarianceMatrix();  //  to access the covariance matrix
  //Double_t chi2   = r->Chi2(); // to retrieve the fit chi2
  //Double_t par0   = r->Parameter(0); // retrieve the value for the parameter 0
  double slope=f1->GetParameter(0);
  double ordo=f1->GetParameter(1);
  cout << "slope= " << slope << " b = " << ordo << endl;
  
  // -----------------------
  //   Corrected Fake Rate
  // -----------------------
  TFile *f_ZLL = TFile::Open(file_ZLL); 
  cout << "File : " << file_ZLL <<endl;
  cout << "Histogram : " << mhitsnameZLL << endl;
  TH1F* zLL_mhits = (TH1F*)f_ZLL->Get(mhitsnameZLL);
  //TH1F* h_mhits = (TH1F*)file->Get(mhitsname);
  cout << " ==============" << endl;
  cout << " pT " << mhitsname << endl;
  cout << " Bin1 = << " << zLL_mhits->GetBinContent(1) << " mean = " << zLL_mhits->GetMean() << " error = " << zLL_mhits->GetMeanError() << endl;
  double corr_fake =  f1->Eval(zLL_mhits->GetMean());
  double corr_fakeErr = f1->Eval(zLL_mhits->GetMean() + zLL_mhits->GetMeanError());
  double dif = corr_fakeErr - corr_fake;
  //double corr_fakeErrDown = f1->Eval(zLL_mhits->GetMean() - zLL_mhits->GetMeanError());
  cout << "Correction : " << corr_fake << " +- " << dif << " (" << 100*(dif)/corr_fake << "%)" << endl;
  double temp_corr_up = corr_fake + dif;
  double temp_corr_down = corr_fake - dif;
  if (corr_fake < 0.0) { corr_fake = 0.0; temp_corr_up = dif;}
  if (temp_corr_down < 0.0) { temp_corr_down = 0.0; }
  cout << "Up = " << temp_corr_up << " Down = " << temp_corr_down << endl;
  cout << " ==============" << endl;
  //mhits[i] = h_mhits->GetMean();

  // -----------------------
  //        Write
  // -----------------------
  OutputFile->cd();
  TC_FRvsMhits->Write();

  corr->SetBinContent(fakebin+1,corr_fake);
  corr->SetBinError(fakebin+1,dif);
  corr_up->SetBinContent(fakebin+1,temp_corr_up);
  corr_down->SetBinContent(fakebin+1,temp_corr_down);
  hmhits_plot->SetBinContent(fakebin+1,zLL_mhits->GetMean());
  hmhits_plot->SetBinError(fakebin+1,zLL_mhits->GetMeanError());

  TC_FRvsMhits->Print("PLOTS/png/"+ channel + "_" + TString(TC_FRvsMhits->GetName())+".png");
  TC_FRvsMhits->Print("PLOTS/pdf/"+ channel + "_" + TString(TC_FRvsMhits->GetName())+".pdf");


  TCanvas * cmhits = new TCanvas("cmhits", "cmhits", 800, 600);


  hmhits->Draw();

  cmhits->Print("PLOTS/png/"+ channel + "_mhits_" + TString(TC_FRvsMhits->GetName())+".png");
 }




// ==================================================================================================================================
void plot_correction(TH1F *corr, TH1F *corr_up, TH1F *corr_down, TString channel, TString flag)
// ==================================================================================================================================
{

  TCanvas * canvas = new TCanvas("corr","corr",800,600);

  TLegend *legend = new TLegend(0.1545226,0.6835664,0.3743719,0.8916084,NULL,"");
  legend->SetTextSize(0.03811252); //(0.035); 
  legend->SetTextFont(42);
  legend->SetLineColor(0);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);

    corr->GetYaxis()->SetRangeUser(0.0,0.5);
    corr->GetYaxis()->SetTitle("Fake Rate"); //Electron ID Efficiency");
    corr->GetXaxis()->SetTitle("3^{rd} Lepton p_{T}"); //Electron ID Efficiency");
    corr->Draw();
    corr_up->SetLineColor(2);
    corr_up->Draw("same");
    corr_down->SetLineColor(3);
    corr_down->Draw("same");


    legend->AddEntry(corr, "Correction","lp");
    legend->AddEntry(corr_up, "Upper Estimation","lp");
    legend->AddEntry(corr_down, "Lower Estimation","lp");
    legend->Draw();


  canvas->Print("PLOTS/png/"+ channel + "_fake_rate_correction_" + flag + ".png");

}


// ==================================================================================================================================
void plot_mhits(TH1F *mhits_EB, TH1F *mhits_EE, TString channel)
// ==================================================================================================================================
{

  TCanvas * canvas = new TCanvas("mhits",",hits",800,600);

  TLegend *legend = new TLegend(0.1545226,0.6835664,0.3743719,0.8916084,NULL,"brNDC");
  legend->SetTextSize(0.03811252); //(0.035); 
  legend->SetTextFont(42);
  legend->SetLineColor(0);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);

    mhits_EB->GetYaxis()->SetRangeUser(0.0,0.5);
    mhits_EB->Draw();
    mhits_EE->SetLineColor(2);
    mhits_EE->Draw("same");


    legend->AddEntry(mhits_EB, "Barrel","lp");
    legend->AddEntry(mhits_EE, "EndCap","lp");
    legend->Draw();


  canvas->Print("PLOTS/png/"+ channel + "_mhits.png");

}



// ==================================================================================================================================
void draw_comp_vecturnons(TFile * OutputFile, TString channel, std::vector<TString> name_TG, int REBIN, double range_min, double range_max, 
			  bool print, TString * name_legend, TString extra_name)
// ==================================================================================================================================
{
  //TGraphAsymmErrors * TG_turnon1;
  //TGraphAsymmErrors * TG_turnon2;

  //cout << "coucou" << endl;
  
  //cout << "--------> Comp Turnons " << name_TG1 << endl;; 
  //TG_turnon1 = (TGraphAsymmErrors*)OutputFile->Get(name_TG1); //"TG_mc_pT_matched");
  
  //cout << "--------> and " << name_TG2 << endl;
  //TG_turnon2 = (TGraphAsymmErrors*)OutputFile->Get(name_TG2); //"TG_mc_pT_matched_ED");
  
  //cout << "hey" << endl;

  // ----------------
  //  Create Legend
  // ----------------
  //TLegend *legend = new TLegend(0.7386935,0.7185315,0.9585427,0.9265734,NULL,"brNDC");
  //TLegend *legend = new TLegend(0.5917085,0.7115385,0.8115578,0.9195804,NULL,"brNDC");
  TLegend *legend = new TLegend(0.1545226,0.6835664,0.3743719,0.8916084,NULL,"brNDC");
  legend->SetTextSize(0.03811252); //(0.035); 
  legend->SetTextFont(42);
  legend->SetLineColor(0);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);

  TCanvas * TC_comp = new TCanvas("COMP_VECturnon_"+name_TG.at(0)+"_"+extra_name,"COMP_VECturnon_"+name_TG.at(0)+"_"+extra_name,800,600);
  TC_comp->ToggleEventStatus();
  gPad->SetGrid();
  //
  
  int colors[6] = {kBlack, kBlue, kRed, kGreen, kBlue-3,  kGreen+3};
  int marker[6] = {20, 20, 20, 20, 20, 20};
  int line[6]   = {1,  1, 1, 1 ,  1, 1};
  
  for(unsigned int i=0;i<name_TG.size();i++) {

    TString name = name_TG.at(i);     
    cout << "--------> Comp Turnons " << name << endl;

    
    TGraphAsymmErrors * TG_turnon1;
    TG_turnon1 = (TGraphAsymmErrors*)OutputFile->Get(name_TG.at(i));
    
    //cout << "t1" << endl;
    TG_turnon1->SetMarkerSize(1.3);
    TG_turnon1->SetMarkerStyle(marker[i]);
    TG_turnon1->SetLineColor(colors[i]);
    TG_turnon1->SetLineStyle(line[i]);
    TG_turnon1->SetMarkerColor(colors[i]);
    //if(name_TG.at(i).Contains("pT")>0)  TG_turnon1->GetXaxis()->SetTitle("E_{T} [GeV]");
    TG_turnon1->GetYaxis()->SetTitle("Fake Rate"); //Electron ID Efficiency");
    TG_turnon1->GetXaxis()->SetTitle("3^{rd} Lepton p_{T}"); //Electron ID Efficiency");
    TG_turnon1->GetXaxis()->SetLimits(range_min,range_max);
    TG_turnon1->GetYaxis()->SetRangeUser(0., 0.25); //1.4);
    if (name_legend[1].Contains("WZ") > 0) { TG_turnon1->GetYaxis()->SetRangeUser(0., 1.5); }
    if(i==0) TG_turnon1->Draw("AP");
    else TG_turnon1->Draw("PSAME");
    legend->AddEntry(TG_turnon1, name_legend[i],"lp");

  } // for loop on turnons
    //
    //cout <<"draw second" << endl;
  //  TG_turnon2->SetMarkerSize(0.9);
  //   TG_turnon2->SetMarkerStyle(20);
  //   TG_turnon2->SetLineColor(2);
  //   TG_turnon2->SetMarkerColor(2);
  //   TG_turnon2->Draw("PSAME");
  //   legend->AddEntry(TG_turnon2, name_legend[1],"lp");
  
    legend->Draw();
    
    // drawCMS();
    
    // if(name_TG.at(0).Contains("pT")>0) {
    //   TLatex * TL_cms = new TLatex(0.45, 0.82,"|#eta|<2.5"); 
    //   TL_cms->SetNDC();
    //   TL_cms->SetTextFont(42);
    //   TL_cms->SetTextSize(0.03908571);
    //   TL_cms->SetLineWidth(2);
    //   TL_cms->Draw("same"); 
    // }
    
    // ------------------
    // Write in the file
    // ------------------
    cout << "Write" << endl;
    OutputFile->cd();
    TC_comp->Write();
    
    //TC_DIFF_turnons->Write(); 

    // ------------------
  // Print plots
  // ------------------
    if(print) {
      cout << "Print" << endl;
      TC_comp->Print("PLOTS/png/"+ channel + "_" + TString(TC_comp->GetName())+".png");
      //TC_comp->Print("PLOTS/C/"+ channel + "_" + TString(TC_comp->GetName())+".C");
      TC_comp->Print("PLOTS/root/"+ channel + "_" + TString(TC_comp->GetName())+".root");
      TC_comp->Print("PLOTS/pdf/"+ channel + "_" + TString(TC_comp->GetName())+".pdf");
      //TC_comp->Print("PLOTS/"+ TString(TC_comp->GetName())+".eps");
      //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".png");
      //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".eps");
    }
    
   // End of draw_comp_turnons
  
}


// ==================================================================================================================================
void draw_comp_corrFR(TFile* OutputFile, TString channel, TH1F *corr, TString name_FR)
// ==================================================================================================================================
{
  TCanvas * TC_corrFR = new TCanvas("CORRFR_"+name_FR, "CORRFR_"+name_FR, 800, 600);
  gPad->SetGrid();

  TGraph* h_fake = (TGraph*)OutputFile->Get(name_FR); /// vec_fakename_EBEE.at(j));
  h_fake->GetYaxis()->SetRangeUser(-0.05,0.3);
  h_fake->GetXaxis()->SetTitle("3^{rd} Lepton p_{T}"); 
  h_fake->Draw("AP");


  // 
  //7,10,20,30,40,50,80
  double pTbins[6]      = {8.5, 15, 25, 35, 45, 65}; // 7,10,20,30,40,50,80};
  double pTbinsErr[6] = {1.5, 5, 5, 5, 5, 15};
	
  double * TGpTbins = new double[6];
  double * TGpTbinsErr = new double[6];
  double * TGcorrFR = new double[6];
  double * TGcorrFR_up = new double[6];
  double * TGcorrFR_down = new double[6];
  double * TGcorrFRErr = new double[6];
  for(int i=0;i<6;i++) {
    TGpTbins[i] = pTbins[i];
    TGpTbinsErr[i] = pTbinsErr[i];

    TGcorrFR[i] = corr->GetBinContent(i+1);
    if (TGcorrFR[i] < 0.0) { TGcorrFR[i] = 0.0; }
    TGcorrFRErr[i] = corr->GetBinError(i+1);
    TGcorrFR_up[i] = corr->GetBinContent(i+1) + corr->GetBinError(i+1);
    if (TGcorrFR_up[i] < 0.0) { TGcorrFR_up[i] = 0.0; }
    TGcorrFR_down[i] = corr->GetBinContent(i+1) - corr->GetBinError(i+1);
    if (TGcorrFR_down[i] < 0.0) { TGcorrFR_down[i] = 0.0; }
    cout << "Corr = " << TGcorrFR[i] << " Up = " << TGcorrFR_up[i] << " Down = " << TGcorrFR_down[i] << endl;
  } // for loop

    TGraph * CorrFR = new TGraphErrors(6, TGpTbins, TGcorrFR, TGpTbinsErr, TGcorrFRErr);
    CorrFR->SetMarkerStyle(20);
    CorrFR->SetMarkerColor(kRed);
    CorrFR->SetLineColor(kRed);
    CorrFR->Draw("PSAME");
  
  TLegend *legend = new TLegend(0.1545226,0.6835664,0.3743719,0.8916084,NULL,"brNDC");
  legend->SetTextSize(0.03811252); //(0.035); 
  legend->SetTextFont(42);
  legend->SetLineColor(0);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);
  legend->AddEntry(h_fake, "Uncorrected Fake Rate","lp");
  legend->AddEntry(CorrFR, "Corrected Fake Rate","lp");
  legend->Draw();

    TGraph * CorrFR_up = new TGraphErrors(6, TGpTbins, TGcorrFR_up, TGpTbinsErr, TGcorrFRErr);
    TGraph * CorrFR_down = new TGraphErrors(6, TGpTbins, TGcorrFR_down, TGpTbinsErr, TGcorrFRErr);

  // -----------------------
  //        Write
  // -----------------------
  OutputFile->cd();
  TC_corrFR->Write();
  CorrFR->Write("CorrFR_"+TString(name_FR));
  CorrFR_up->Write("CorrFR_"+TString(name_FR)+"_up");
  CorrFR_down->Write("CorrFR_"+TString(name_FR)+"_down");

  TC_corrFR->Print("PLOTS/png/" + channel + "_" + TString(TC_corrFR->GetName())+".png");
  TC_corrFR->Print("PLOTS/pdf/" + channel + "_" + TString(TC_corrFR->GetName())+".pdf");
  
}



//==================================================================================================================================
void draw_comp_inclcorrFR(TFile* OutputFile, TString channel, TH1F *corr, TString name_FR)
// ==================================================================================================================================
{
  TCanvas * TC_corrFR = new TCanvas("inclCORRFR_"+name_FR, "inclCORRFR_"+name_FR, 800, 600);
  gPad->SetGrid();

  TGraph* h_fake = (TGraph*)OutputFile->Get(name_FR); /// vec_fakename_EBEE.at(j));
  h_fake->GetYaxis()->SetRangeUser(0,0.2);
  h_fake->GetXaxis()->SetTitle("Lepton pT"); 
  h_fake->Draw("AP");

  // 
  //7,10,20,30,40,50,80
  double pTbins[1]      = {40}; //8.5, 15, 25, 35, 45, 65}; // 7,10,20,30,40,50,80};
  double pTbinsErr[1] = {40}; //1.5, 5, 5, 5, 5, 15};
  
  double corrEB[1] = {0.0278854}; //0.020687,  0.019609, 0.0506095, 0.0280723, 0.0296561, 0.100752 };
  double corrEBErr[1] = {0.032982 - corrEB[0]}; //,  0.0272634- corrEB[1], 0.0658386- corrEB[2], 0.0418654 - corrEB[3], 0.033576- corrEB[4], 0.135549- corrEB[5]};

  double corrEE[6] = {0.0507767}; //0.0394433 , 0.0465471, 0.0748147, 0.0304773, 0.0475017, 0.141148 };
  double corrEEErr[6] = {0.0590706- corrEE[0]}; //, 0.0613032- corrEE[1], 0.0969381- corrEE[2], 0.041634- corrEE[3], 0.0623318- corrEE[4], 0.149169- corrEE[5]};
	
  double * TGpTbins = new double[1];
  double * TGpTbinsErr = new double[1];
  double * TGcorrFR = new double[1];
  double * TGcorrFRErr = new double[1];
  for(int i=0;i<1;i++) {
    TGpTbins[i] = pTbins[i];
    TGpTbinsErr[i] = pTbinsErr[i];


    TGcorrFR[i] = corr->GetBinContent(i+1);
    if (TGcorrFR[i] < 0.0) { TGcorrFR[i] = 0.0; }
    TGcorrFRErr[i] = corr->GetBinError(i+1);
  } // for loop

    TGraph * CorrFR = new TGraphErrors(1, TGpTbins, TGcorrFR, TGpTbinsErr, TGcorrFRErr);
    CorrFR->SetMarkerStyle(20);
    CorrFR->SetMarkerColor(kRed);
    CorrFR->SetLineColor(kRed);
    CorrFR->Draw("PSAME");
  
  // -----------------------
  //        Write
  // -----------------------
  OutputFile->cd();
  TC_corrFR->Write();
  CorrFR->Write("CorrFR_"+TString(name_FR));

  TC_corrFR->Print("PLOTS/png/"+ channel + "_" + TString(TC_corrFR->GetName())+".png");
TC_corrFR->Print("PLOTS/pdf/"+ channel + "_" + TString(TC_corrFR->GetName())+".pdf");

}


// ==============================================================
void subtract_wz(TFile * OutputFile, TString channel, TH1 *fakerate_data, TH1 *data, TH1 *fakerate_wz, TH1 *wz, TH1 *fakerate, TString region)
// ==============================================================
	{
	cout << "Subtract WZ " << endl;
	double factor = wz->Integral()/data->Integral();

	cout << "Factor = " << factor << endl;

	//fakerate_wz->Scale(factor);

	fakerate = (TH1*) fakerate_data->Clone("fakerate");


	for (int i = 1; i <= fakerate->GetNbinsX();i++)
		{
		double val_data = data->GetBinContent(i);
		double val_wz = wz->GetBinContent(i);
		double factor_bin = val_wz/val_data;
		double fr_data = fakerate_data->GetBinContent(i);
		double fr_wz = fakerate_wz->GetBinContent(i);
		double new_fr = fr_data - fr_wz * factor_bin;
		cout << "Factor for bin " << i<< " = " << factor_bin << " orginal fake rate = " << fr_data << " corrected fake rate = " << new_fr << endl;
		fakerate->SetBinContent(i,new_fr);
		}

	//fakerate->Add(fakerate_wz,-1);

  	OutputFile->cd();
  	fakerate->Write("CorrFR_"+region);


  	TCanvas * TC_corrFR = new TCanvas("CORRFR_"+channel+"_"+region, "CORRFR_"+channel+"_"+region, 800, 600);
  	gPad->SetGrid();

	fakerate_data->SetMarkerColor(1);
  	fakerate_data->SetLineColor(1);
  	fakerate_data->Draw();
	fakerate->SetMarkerColor(2);
  	fakerate->SetLineColor(2);
  	fakerate->Draw("same");

  	TLegend *legend = new TLegend(0.1545226,0.6835664,0.3743719,0.8916084,NULL,"brNDC");
  	legend->SetTextSize(0.03811252); //(0.035); 
  	legend->SetTextFont(42);
  	legend->SetLineColor(0);
  	legend->SetLineStyle(1);
  	legend->SetLineWidth(1);
  	legend->SetFillColor(0);
  	legend->SetFillStyle(0);
  	legend->AddEntry(fakerate_data, "Uncorrected Fake Rate","lp");
  	legend->AddEntry(fakerate, "Corrected Fake Rate","lp");
  	legend->Draw();

  	TC_corrFR->Print("PLOTS/png/" + channel + "_correction_"+region+".png");
  	TC_corrFR->Print("PLOTS/pdf/" + channel + "_correction_"+region+".pdf");

}

// ==============================================================
void comp_fake(TString channel = "Ze", TString mode = "rate", TString EXTRA = "80XB")
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

  std::vector<TString> vec_file_name; vec_file_name.clear();
  //vec_file_name.push_back("out/outputCRZL_ALL_"+channel+"_76XMZ7.root");
if (channel == "4e" or channel == "2mu2e" or channel == "Z2e")
	{
	vec_file_name.push_back("histograms/FR/Ze/FR_CRZL_ALL_"+EXTRA+".root");
	}
else
	{
	vec_file_name.push_back("histograms/FR/"+channel+"/FR_CRZL_ALL_"+EXTRA+".root");
	}

  if(channel=="Ze" or channel == "4e" or channel == "2mu2e" or channel == "Z2e")
	{
    	//vec_file_name.push_back("out/outputCRZL_ALL_"+channel+"_"+era.root");
    	vec_file_name.push_back("histograms/FR/Ze/FR_CRZL_ALL_"+EXTRA+"MZ7.root");
    	vec_file_name.push_back("histograms/FR/Ze/FR_CRZL_ALL_"+EXTRA+"MZ60.root");
    	vec_file_name.push_back("histograms/FR/Ze/FR_CRZL_ALL_"+EXTRA+"M3L5.root");
  	} // if 4e

	TString output_name = "";
  	output_name = "histograms/computed_fakerate/"+channel+"/computedfakerate_"+EXTRA+".root";
  
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


  Float_t xbins[7] = {7,10,20,30,40,50,80};

  TH1F *corr_EB;
  corr_EB = new TH1F("Corr_EB","Lep3_pT;Fake Rate;3^{rd} Lepton p_{T}",6, xbins);
  TH1F *corr_EE;
  corr_EE = new TH1F("Corr_EE","Lep3_pT;Fake Rate;3^{rd} Lepton p_{T}",6, xbins);

  TH1F *corr_EB_up;
  corr_EB_up = new TH1F("Corr_EB_up","Lep3_pT;Fake Rate;3^{rd} Lepton p_{T}",6, xbins);
  TH1F *corr_EE_up;
  corr_EE_up = new TH1F("Corr_EE_up","Lep3_pT;Fake Rate;3^{rd} Lepton p_{T}",6, xbins);

  TH1F *corr_EB_down;
  corr_EB_down = new TH1F("Corr_EB_down","Lep3_pT;Fake Rate;3^{rd} Lepton p_{T}",6, xbins);
  TH1F *corr_EE_down;
  corr_EE_down = new TH1F("Corr_EE_down","Lep3_pT;Fake Rate;3^{rd} Lepton p_{T}",6, xbins);

  TH1F *mhits_EB;
  mhits_EB = new TH1F("MHits_EB","Lep3_pT",6, xbins);
  TH1F *mhits_EE;
  mhits_EE = new TH1F("MHits_EE","Lep3_pT",6, xbins);


  //draw_comp_histo(TFile * file, TFile * OutputFile, TString name_histo_truth, TString name_histo_simu, int REBIN, int range_min, int range_max, 
  //bool print, bool norm, bool do_reweight, bool REBIN1, bool do_turnon, TString * name_legend)
  
  int rebin_pT  = 1;
  int rebin_eta = 10;
  
  //   TString reg[3]  = {"","_EB","_EE"};
 
  // --------------------------------------
    // Lepton FakeRate (DATA, 4e)
    // --------------------------------------
   std::vector<TString> name_vecEB;
   std::vector<TString> name_vecEE;
   std::vector<TString> name_vec;  
 

  //draw_comp_vechisto(vec_file_name, OutPutFile, "ems_pT_probe"+reg[ir],  "ems_pT_probe_CiCMedium"+reg[ir],rebin_pT, 0,80, PRINT, true, doturn, name_legend, "MC");
  for(unsigned int ifile=0;ifile<vec_file_name.size();ifile++) {
    TFile *file = TFile::Open(vec_file_name.at(ifile));
    TString reduced_name = vec_file_name.at(ifile);
    reduced_name.ReplaceAll("histograms/FR/"+channel+"/FR_CRZL_", "");
    reduced_name.ReplaceAll("histograms/FR/Ze/FR_CRZL_", "");

    reduced_name.ReplaceAll(".root", ""); 
    cout << "reduce = " << reduced_name << endl;
    draw_comp_histo(file, channel, OutPutFile,"Lep3_pT_all_EB_afterMET_wzremoved",  "Lep3_pT_all_EB_afterIDISO_wzremoved", rebin_pT, 0,80, PRINT, false, false, 1, true, name_legend, reduced_name);
    draw_comp_histo(file, channel, OutPutFile,"Lep3_pT_all_EE_afterMET_wzremoved",  "Lep3_pT_all_EE_afterIDISO_wzremoved", rebin_pT, 0,80, PRINT, false, false, 1, true, name_legend, reduced_name);


    if(channel=="Ze" or channel == "4e" or channel == "2mu2e" or channel == "Z2e") {
      name_vecEB.push_back("TG_Lep3_pT_all_EB_afterMET_wzremoved_"+reduced_name);
      name_vecEE.push_back("TG_Lep3_pT_all_EE_afterMET_wzremoved_"+reduced_name);
    } // if 4e

    if(channel=="Zmu") {
      if (ifile == 0)
	{
      	name_vec.push_back("TG_Lep3_pT_all_EB_afterMET_wzremoved_"+reduced_name);
      	name_vec.push_back("TG_Lep3_pT_all_EE_afterMET_wzremoved_"+reduced_name);
	}
      name_vecEB.push_back("TG_Lep3_pT_all_EB_afterMET_wzremoved_"+reduced_name);
      name_vecEE.push_back("TG_Lep3_pT_all_EE_afterMET_wzremoved_"+reduced_name);
    } // if 4mu
    //draw_comp_histo(TFile * file, TFile * OutputFile, TString name_histo_truth, TString name_histo_simu, int REBIN, double range_min, double range_max, 
    //bool print, bool norm, bool do_reweight, bool REBIN1, bool do_turnon, TString * name_legend, TString extra_name); 
  } // file_name_size
  
  

  if(channel=="Ze" or channel == "4e" or channel == "2mu2e" or channel == "Z2e") {
    // -------------------------------------
    // Compare Lepton FakeRate (DATA, 4e)
    // --------------------------------------
    //void draw_comp_vecturnons(TFile * OutputFile, std::vector<TString> name_TG, int REBIN, double range_min, double range_max, 
    //bool print, TString * name_legend, TString extra_name)
    name_legend[0] = "40<MZ<120"; 
    name_legend[1] = "|MZ-91.2|<7";
    name_legend[2] = "60<MZ<120"; 
    name_legend[3] = "|M3L-91.2|<5";
    
    draw_comp_vecturnons(OutPutFile, "Ze", name_vecEB, 1, 0, 80, PRINT, name_legend, "SS");
    draw_comp_vecturnons(OutPutFile, "Ze", name_vecEE, 1, 0, 80, PRINT, name_legend, "SS");

    // --------------------------------------
    //         FR vs Missing Hits
    // --------------------------------------
    cout << "Missing hits !" << endl;
    if (mode == "correction")
    {
    //Lep3pT710, Lep3pT1020, Lep3pT2030, Lep3pT3040, Lep3pT4050,Lep3pT5080
    TString pTbins[6] = {"710", "1020", "2030", "3040", "4050", "5080"};
    TString file_ZLL = "histograms/FR/"+ channel +"/FR_CRZLL_ALL_ALL_"+EXTRA+".root";

    if(EXTRA.Contains("incl")>0)
	{
      	comp_FRMhits(vec_file_name, channel, name_vecEB, corr_EB, corr_EB_up, corr_EB_down, mhits_EB, OutPutFile, "Lep3_inclmhits_EB", file_ZLL, "Lep34_inclmhits_EB");
      	comp_FRMhits(vec_file_name, channel, name_vecEE, corr_EE, corr_EE_up, corr_EE_down, mhits_EE, OutPutFile, "Lep3_inclmhits_EE", file_ZLL, "Lep34_inclmhits_EE");
    	}
    else
	{
      	for(int i=0; i<6; i++)
		{
		comp_FRMhits(vec_file_name, channel, name_vecEB, corr_EB, corr_EB_up, corr_EB_down, mhits_EB, OutPutFile, "Lep3_mhits_EB_pT"+pTbins[i], file_ZLL, "Lep34_mhits_EB_pT"+pTbins[i]);
		comp_FRMhits(vec_file_name, channel, name_vecEE, corr_EE, corr_EE_up, corr_EE_down, mhits_EE, OutPutFile, "Lep3_mhits_EE_pT"+pTbins[i], file_ZLL, "Lep34_mhits_EE_pT"+pTbins[i]);
      		} // for loop on pT bins
      //void comp_FRMhits(std::vector<TString> vec_file_name, std::vector<TString> vec_fakename_EBEE, TFile* OutputFile, TString mhitsname)
    	} // else 
    

    

    // --------------------------------------
    //         FR vs Corrected FR
    // --------------------------------------
    //void draw_comp_inclcorrFR(TFile* OutputFile, TString name_FR)
    if(EXTRA.Contains("incl")>0)
	{
      	draw_comp_inclcorrFR(OutPutFile, channel, corr_EB, name_vecEB.at(0));
      	draw_comp_inclcorrFR(OutPutFile, channel, corr_EE, name_vecEE.at(0));
    	}
    else
	{
      	draw_comp_corrFR(OutPutFile, channel, corr_EB, name_vecEB.at(0));
      	draw_comp_corrFR(OutPutFile, channel, corr_EE, name_vecEE.at(0));
    	} // else pT 
  
    } //correction 
  } // if channel = 4e/Z2e/2mu2e


    

   // -------------------------------------
   // Compare Lepton FakeRate (DATA, 4mu)
   // --------------------------------------
  if(channel=="Zmu") {
    //void draw_comp_vecturnons(TFile * OutputFile, std::vector<TString> name_TG, int REBIN, double range_min, double range_max, 
    //bool print, TString * name_legend, TString extra_name)
    name_legend[0] = "Barrel"; 
    name_legend[1] = "Endcap";

    draw_comp_vecturnons(OutPutFile, channel, name_vec, 1, 0, 80, PRINT, name_legend, EXTRA);

    name_legend[0] = "Data"; 

    draw_comp_vecturnons(OutPutFile, channel, name_vecEB, 1, 0, 80, PRINT, name_legend, "SS");
    draw_comp_vecturnons(OutPutFile, channel, name_vecEE, 1, 0, 80, PRINT, name_legend, "SS");

  } // if 4mu
 

  cout << "---> Draw Comp Turnons " << endl;

  cout << "" << endl;

  if (mode == "correction")
	{
	plot_correction(corr_EB, corr_EB_up, corr_EB_down, channel, "barrel_"+EXTRA);
	plot_correction(corr_EE, corr_EE_up, corr_EE_down, channel, "endcap_"+EXTRA);
	plot_mhits(mhits_EB, mhits_EE, channel);
	corr_EE->Write();
        corr_EB->Write();
	corr_EE_up->Write();
        corr_EB_up->Write();
	corr_EE_down->Write();
        corr_EB_down->Write();
	}

  cout << "---------------> Closing File : " << output_name  << endl;

} // fin de la macro
