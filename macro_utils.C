//Created by Christophe Orchando
//Modified by Pedro Cipriano



#include "macro_utils.h"

// C++ include
#include <ostream>
#include <iostream>
#include <sstream>
#include <fstream>

// ROOT include
#include <TROOT.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLegend.h>
#include <THStack.h>
#include <TProfile.h>
#include <TPaveText.h>

using namespace std;

// ================================================
void drawCMS() {
// ================================================
// ----------------------------------------------
  // TLatex
  // ----------------------------------------------
   TPaveText *pt = new TPaveText(0.24,0.78,0.3,0.84,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextAlign(12);
   pt->SetTextFont(42);
   pt->SetTextSize(0.04);
   TText *text = pt->AddText(0.01,0.5,"");
   pt->Draw();
   TLatex *tex = new TLatex(0.96,0.9451429,"14 TeV");
   tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.04114286);
   tex->SetLineWidth(2);
   tex->Draw();
   //tex = new TLatex(0.154345,0.8729,"CMS Simulation");
   //tex = new TLatex(0.1306533,0.902,"CMS Simulation");
   //tex = new TLatex(0.1306533,0.8793706,"CMS Simulation");
   tex = new TLatex(0.1306533,0.774,"CMS Simulation"); // for x,y scale at 0.8
   tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(61);
   tex->SetTextSize(0.05142857);
   tex->SetLineWidth(2);
   tex->Draw();
   //tex = new TLatex(0.846,0.316,"Endcaps");
   //tex = new TLatex(0.559,0.902,"Endcaps");
   //tex = new TLatex(0.4422,0.896,"Endcaps");
   //tex = new TLatex(0.2072864,0.7937063,"Endcaps");
   tex = new TLatex(0.2072864,0.7133,"Endcaps");// for x,y scale at 0.8
   tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(42);
   tex->SetTextSize(0.03908571);
   tex->SetLineWidth(2);
   tex->Draw();

   

}

// ================================================
void setTDRStyle_rob() {
// ================================================
// style:
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  //For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); 
  //Height of canvas
  tdrStyle->SetCanvasDefW(800); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  //For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(2);

  // For the histo:
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(2);
  tdrStyle->SetEndErrorSize(2);
  //tdrStyle->SetErrorMarker(20);
  //tdrStyle->SetErrorX(0.);
  tdrStyle->SetMarkerStyle(8);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  //tdrStyle->SetOptStat(1);
  tdrStyle->SetOptStat(0);
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(.1);
  tdrStyle->SetStatW(.15);

  // For the Global title:
  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(4);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);

  // For the axis titles:
  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  //tdrStyle->SetTitleSize(0.06, "XYZ");
  tdrStyle->SetTitleSize(0.07, "XYZ");
  //tdrStyle->SetTitleSize(0.03, "X");
  tdrStyle->SetTitleXOffset(0.54);
  //tdrStyle->SetTitleYOffset(1.25);
  //tdrStyle->SetTitleXOffset(0.5);
  tdrStyle->SetTitleYOffset(0.86);

  // For the axis labels:
  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");

  //tdrStyle->SetLabelSize(0.05, "XYZ");
  tdrStyle->SetLabelSize(0.04, "XYZ");

  // For the axis:
  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // CC style  
  tdrStyle->SetTitleXOffset(0.88);
  tdrStyle->SetTitleYOffset(1);
  tdrStyle->SetLabelOffset(0.0046, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  tdrStyle->SetTitleFont(42,"X");
  tdrStyle->SetTitleFont(42,"Y");
  //tdrStyle->SetPadBottomMargin(0.2);
  //tdrStyle->SetPadLeftMargin(0.2);
  tdrStyle->SetPadBottomMargin(0.13);
	tdrStyle->SetPadLeftMargin(0.12);
	tdrStyle->SetPadRightMargin(0.12);
  //tdrStyle->SetHistLineWidth(3);
  tdrStyle->SetHistLineWidth(2);
  tdrStyle->SetLineStyleString(5,"20 12 4 12");
  tdrStyle->SetLineStyleString(6,"20 12 4 12 4 12 4 12");
  tdrStyle->SetLineStyleString(7,"20 20");
  tdrStyle->SetLineStyleString(8,"20 12 4 12 4 12");
  tdrStyle->SetLineStyleString(9,"80 20");

  //tdrStyle->SetPadGridX(kTRUE);
  //tdrStyle->SetPadGridY(kTRUE);
  tdrStyle->SetPadGridX(kFALSE);
  tdrStyle->SetPadGridY(kFALSE);

  tdrStyle->SetPalette(1);

  tdrStyle->cd();
}


// // ================================================
// void setTDRStyle() {
// // ================================================
//   TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");
  
//   // For the canvas:
//   tdrStyle->SetCanvasBorderMode(0);
//   tdrStyle->SetCanvasColor(kWhite);
//   tdrStyle->SetCanvasDefH(600); //Height of canvas
//   tdrStyle->SetCanvasDefW(800); //Width of canvas
//   tdrStyle->SetCanvasDefX(0);   //POsition on screen
//   tdrStyle->SetCanvasDefY(0);
  
//   // For the Pad:
//   tdrStyle->SetPadBorderMode(0);
//   // tdrStyle->SetPadBorderSize(Width_t size = 1);
//   tdrStyle->SetPadColor(kWhite);
//   tdrStyle->SetPadGridX(false);
//   tdrStyle->SetPadGridY(false);
//   tdrStyle->SetGridColor(0);
//   tdrStyle->SetGridStyle(3);
//   tdrStyle->SetGridWidth(1);
  
//   // For the frame:
//   tdrStyle->SetFrameBorderMode(0);
//   tdrStyle->SetFrameBorderSize(1);
//   tdrStyle->SetFrameFillColor(0);
//   tdrStyle->SetFrameFillStyle(0);
//   tdrStyle->SetFrameLineColor(1);
//   tdrStyle->SetFrameLineStyle(1);
//   tdrStyle->SetFrameLineWidth(1);
  
//   // For the histo:
//   tdrStyle->SetHistFillColor(1);
//   tdrStyle->SetHistFillStyle(0);
//   //tdrStyle->SetHistLineColor(6);
//   tdrStyle->SetHistLineStyle(0);
//   tdrStyle->SetHistLineWidth(1);
//   tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
//   tdrStyle->SetNumberContours(Int_t number = 20);
  
//   //tdrStyle->SetEndErrorSize(2);
//   //tdrStyle->SetErrorMarker(20);
//   //tdrStyle->SetErrorX(0.);
  
//   //tdrStyle->SetMarkerStyle(20);
  
//   //For the fit/function:
//   //tdrStyle->SetOptFit(1);
//   //tdrStyle->SetFitFormat("5.4g");
//   //tdrStyle->SetFuncColor(2);
//   //tdrStyle->SetFuncStyle(1);
//   //tdrStyle->SetFuncWidth(1);
  
//   //For the date:
//   //tdrStyle->SetOptDate(0);
//   // tdrStyle->SetDateX(Float_t x = 0.01);
//   // tdrStyle->SetDateY(Float_t y = 0.01);
  
//   // For the statistics box:
//   tdrStyle->SetOptFile(0);
//   tdrStyle->SetOptStat(0000); // To display the mean and RMS:   SetOptStat("mr");
//   tdrStyle->SetStatColor(kWhite);
//   tdrStyle->SetStatFont(42);
//   tdrStyle->SetStatFontSize(0.025);
//   tdrStyle->SetStatTextColor(1);
//   tdrStyle->SetStatFormat("6.4g");
//   tdrStyle->SetStatBorderSize(1);
//   tdrStyle->SetStatH(0.1);
//   tdrStyle->SetStatW(0.15);
//   // tdrStyle->SetStatStyle(Style_t style = 1001);
//   // tdrStyle->SetStatX(Float_t x = 0);
//   // tdrStyle->SetStatY(Float_t y = 0);
  
//   // Margins:
//   tdrStyle->SetPadTopMargin(0.05);
//   tdrStyle->SetPadBottomMargin(0.13);
//   tdrStyle->SetPadLeftMargin(0.12);
//   tdrStyle->SetPadRightMargin(0.10);
  
//   // tdrStyle->SetTLegendColor(kWhite);
//   // For the Global title:
  
//   tdrStyle->SetOptTitle(1);
//   tdrStyle->SetTitleFont(42);
//   tdrStyle->SetTitleColor(1);
//   tdrStyle->SetTitleTextColor(1);
//   tdrStyle->SetTitleFillColor(10);
//   tdrStyle->SetTitleFontSize(0.05);
//   tdrStyle->SetTitleH(0); // Set the height of the title box
//   tdrStyle->SetTitleW(0); // Set the width of the title box
//   tdrStyle->SetTitleX(0.13); // Set the position of the title box
//   tdrStyle->SetTitleY(0.99); // Set the position of the title box
//   tdrStyle->SetTitleStyle(Style_t style = 1001);
//   tdrStyle->SetTitleBorderSize(1);
  
//   // For the axis titles:
  
//   tdrStyle->SetTitleColor(1, "XYZ");
//   tdrStyle->SetTitleFont(42, "XYZ");
//   tdrStyle->SetTitleSize(0.04, "XYZ");
//   // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
//   // tdrStyle->SetTitleYSize(Float_t size = 0.02);
//   tdrStyle->SetTitleXOffset(0.9);
//   tdrStyle->SetTitleYOffset(1.4);
//   // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset
  
//   // For the axis labels:
  
//   tdrStyle->SetLabelColor(1, "XYZ");
//   tdrStyle->SetLabelFont(42, "XYZ");
//   tdrStyle->SetLabelOffset(0.007, "XYZ");
//   tdrStyle->SetLabelSize(0.03, "XYZ");
  
//   // For the axis:
  
//   tdrStyle->SetAxisColor(1, "XYZ");
//   tdrStyle->SetStripDecimals(kTRUE);
//   tdrStyle->SetTickLength(0.01, "XYZ");
//   tdrStyle->SetNdivisions(510, "XYZ");
//   tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
//   tdrStyle->SetPadTickY(1);
  
//   // Change for log plots:
//   tdrStyle->SetOptLogx(0);
//   tdrStyle->SetOptLogy(0);
//   tdrStyle->SetOptLogz(0);
  
//   // Postscript options:
//   tdrStyle->SetPaperSize(20.,20.);
//   // tdrStyle->SetLineScalePS(Float_t scale = 3);
//   // tdrStyle->SetLineStyleString(Int_t i, const char* text);
//   // tdrStyle->SetHeaderPS(const char* header);
//   // tdrStyle->SetTitlePS(const char* pstitle);
  
//   // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
//   // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
//   // tdrStyle->SetPaintTextFormat(const char* format = "g");
//   // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
//   // tdrStyle->SetTimeOffset(Double_t toffset);
//   // tdrStyle->SetHistMinimumZero(kTRUE);

//tdrStyle->SetPalette(1);

//   tdrStyle->cd();
  
// }


// ==================================================================================================================================
void loadTPStyle()
// ==================================================================================================================================
{

  gROOT->ForceStyle();
  
  gStyle->SetOptFit(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  
  gStyle->SetPadRightMargin(0.03761349);
  gStyle->SetPadTopMargin(0.06715064);
  gStyle->SetPadBottomMargin(0.1161525);
  
  gStyle->SetFrameFillStyle(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameFillStyle(0);
  gStyle->SetFrameLineWidth(2);
  gStyle->SetFrameBorderMode(0);
  
  Font_t  FONT = 42;
  gStyle->SetTitleFont(FONT);
  gStyle->SetTitleFont(FONT,"XYZ");
  gStyle->SetTitleXOffset(0.9);
  gStyle->SetTitleYOffset(0.95);
  gStyle->SetTitleSize(0.05, "XYZ");

  gStyle->SetLabelFont(FONT, "XYZ");
  gStyle->SetLabelSize(0.055, "XYZ");

  gStyle->SetLegendFont(FONT);

  //h_efficiency_Pt->GetXaxis()->SetLabelFont(42);
  // h_efficiency_Pt->GetXaxis()->SetLabelSize(0.055);
   //h_efficiency_Pt->GetXaxis()->SetTitleSize(0.05);
   //h_efficiency_Pt->GetXaxis()->SetTitleOffset(0.9);
   //h_efficiency_Pt->GetXaxis()->SetTitleFont(42);
   //   h_efficiency_Pt->GetYaxis()->SetTitle("Efficiency              ");
   //h_efficiency_Pt->GetYaxis()->SetLabelFont(42);
  //   h_efficiency_Pt->GetYaxis()->SetLabelSize(0.055);
   //h_efficiency_Pt->GetYaxis()->SetTitleSize(0.05);
   //h_efficiency_Pt->GetYaxis()->SetTitleOffset(0.95);
   //h_efficiency_Pt->GetYaxis()->SetTitleFont(42);
  //h_efficiency_Pt->GetZaxis()->SetLabelFont(42);
  //h_efficiency_Pt->GetZaxis()->SetLabelSize(0.035);
   //h_efficiency_Pt->GetZaxis()->SetTitleSize(0.035);
   //h_efficiency_Pt->GetZaxis()->SetTitleFont(42);
 //figure->SetFillColor(0);
 //figure->SetBorderMode(0);
 //figure->SetBorderSize(2);
 //figure->SetRightMargin(0.03761349);
 //figure->SetTopMargin(0.06715064);
 //figure->SetBottomMargin(0.1161525);
//  figure->SetFrameFillStyle(0);
//  figure->SetFrameBorderMode(0);
//  figure->SetFrameFillStyle(0);
//  figure->SetFrameLineWidth(2);
//  figure->SetFrameBorderMode(0);
}

// ==================================================================================================================================
void loadPresentationStyle()
// ==================================================================================================================================
{

   Font_t  FONT = 42;
  
  gROOT->ForceStyle();
  //gROOT->SetStyle("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  //
  gStyle->SetTitleXOffset(0.8);
  gStyle->SetTitleYOffset(0.9);
  gStyle->SetTitleSize(0.05, "XYZ");
  gStyle->SetTitleFont(FONT);
  gStyle->SetTitleFont(FONT,"XYZ");
  //gStyle->SetTitleFont(FONT,"Y");
  //
  //gStyle->SetLabelOffset(0.005, "XYZ");
  gStyle->SetLabelSize(0.04, "XYZ");
  gStyle->SetLabelFont(FONT, "XYZ");
  //
  gStyle->SetLegendFont(FONT);
  //
  gStyle->SetTitleFillColor(10);
  gStyle->SetPadBottomMargin(0.13);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetHistLineWidth(2);
  
  gStyle->SetPalette(1,0);
  gStyle->SetOptTitle(0);
  gStyle->SetCanvasColor(kWhite);

}


// ==================================================================================================================================
void draw_comp_turnons_2files(TFile * file1, TFile * file2, TFile * OutputFile, TString name_TG1, TString name_TG2, TString name_TG3, 
			      int range_min, int range_max, bool print, TString * name_legend, TString extra_name)
// ==================================================================================================================================
{
  TGraphAsymmErrors * TG_turnon1;
  TGraphAsymmErrors * TG_turnon2;
  TGraphAsymmErrors * TG_turnon3;

  TG_turnon1 = (TGraphAsymmErrors*)file1->Get(name_TG1);
  TG_turnon2 = (TGraphAsymmErrors*)file1->Get(name_TG2);
  TG_turnon3 = (TGraphAsymmErrors*)file2->Get(name_TG3); 

  bool only_two = false;
  if(name_TG2==name_TG3) only_two = true;

  // ----------------
  //  Create Legend
  // ----------------
  //TLegend* legend = new TLegend(0.70,0.1,0.9,0.3);
  //TLegend* legend = new TLegend(0.669598,0.1311189,0.8982412,0.3688811); //NULL,"brNDC");
  TLegend* legend = new TLegend(6545226,0.1171329,0.8831658,0.3548951);
  //legend->SetTextSize(0.02); 
  legend->SetTextFont(62);
  legend->SetTextSize(0.03496503);

  TCanvas * TC_comp = new TCanvas("COMP_turnon_"+name_TG1+"_"+extra_name,"COMP_turnon_"+name_TG1+"_"+extra_name,800,600);
  TC_comp->ToggleEventStatus();
  gPad->SetGrid();
  //
  TG_turnon1->SetMarkerSize(0.9);
  TG_turnon1->SetMarkerStyle(20);
  TG_turnon1->SetLineColor(kBlue);
  TG_turnon1->SetMarkerColor(kBlue);
  TG_turnon1->SetMinimum(0);
  TG_turnon1->SetMaximum(1.);
  //TG_turnon1->SetRangeUser(range_min,range_max);
  TG_turnon1->GetXaxis()->SetLimits(range_min,range_max);
  TG_turnon1->Draw("AP");
  legend->AddEntry(TG_turnon1, name_legend[0],"lp");
  //
  //cout <<"draw second" << endl;
  if(only_two==false) {
    TG_turnon2->SetMarkerSize(0.9);
    TG_turnon2->SetMarkerStyle(20);
    TG_turnon2->SetLineColor(2);
    TG_turnon2->SetMarkerColor(2);
    TG_turnon2->Draw("PSAME");
    legend->AddEntry(TG_turnon2, name_legend[1],"lp");
  } // if 3 
  //
  TG_turnon3->SetMarkerSize(0.9);
  TG_turnon3->SetMarkerStyle(20);
  TG_turnon3->SetLineColor(1); //kOrange+7);
  TG_turnon3->SetMarkerColor(1); //kOrange+7);
  TG_turnon3->Draw("PSAME");
  legend->AddEntry(TG_turnon3, name_legend[2],"lp");

  legend->Draw();
  
  // Write in the file
  OutputFile->cd();
  TC_comp->Write();

  // ------------------
  // Print plots
  // ------------------
  if(print) {
    TC_comp->Print("PLOTS/png/"+ TString(TC_comp->GetName())+".png");
    //TC_comp->Print("PLOTS/"+ TString(TC_comp->GetName())+".eps");
  } // if print

} // End of draw_comp_turnons 2 files

// ==================================================================================================================================
void draw_comp_turnons(TFile * OutputFile, TString name_TG1, TString name_TG2, int REBIN, double range_min, double range_max, 
		       bool print, TString * name_legend, TString extra_name)
// ==================================================================================================================================
{
  TGraphAsymmErrors * TG_turnon1;
  TGraphAsymmErrors * TG_turnon2;

  //cout << "coucou" << endl;

  cout << "--------> Comp Turnons " << name_TG1 << endl;; 
  TG_turnon1 = (TGraphAsymmErrors*)OutputFile->Get(name_TG1); //"TG_mc_pT_matched");

  cout << "--------> and " << name_TG2 << endl;
  TG_turnon2 = (TGraphAsymmErrors*)OutputFile->Get(name_TG2); //"TG_mc_pT_matched_ED");
  
  //cout << "hey" << endl;

  // ----------------
  //  Create Legend
  // ----------------
  //TLegend* legend = new TLegend(0.70,0.1,0.9,0.3);
  //  TLegend* legend = new TLegend(0.669598,0.1311189,0.8982412,0.3688811); //NULL,"brNDC");
  //TLegend* legend = new TLegend(0.6545226,0.1171329,0.8831658,0.3548951);
  //legend->SetTextSize(0.02); 
  //legend->SetTextFont(42);
  //legend->SetTextSize(0.03496503);
  //TLegend* legend = new TLegend(0.3894472,0.1520979,0.6092965,0.3601399,NULL,"brNDC");
  //TLegend *legend = new TLegend(0.4497487,0.2832168,0.669598,0.4912587,NULL,"brNDC");
  TLegend *legend = new TLegend(0.7386935,0.7185315,0.9585427,0.9265734,NULL,"brNDC");
  //(0.4497487,0.2832168,0.669598,0.4912587,NULL,"brNDC");
  //(0.6394472,0.1818182,0.8592965,0.3898601,NULL,"brNDC");
  //legend = new TLegend(0.7236181,0.7587413,0.9434673,0.9667832,NULL,"brNDC");
  legend->SetTextSize(0.03811252); //(0.035); 
  legend->SetTextFont(42);
  ///legend->SetFillColor(kWhite);
  //legend->SetBorderSize(1);
  legend->SetLineColor(0);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);

  TCanvas * TC_comp = new TCanvas("COMP_turnon_"+name_TG2+"_"+extra_name,"COMP_turnon_"+name_TG2+"_"+extra_name,800,600);
  TC_comp->ToggleEventStatus();
  //gPad->SetGrid();
  //
  //cout << "t1" << endl;
  TG_turnon1->SetMarkerSize(1.3);
  TG_turnon1->SetMarkerStyle(20);
  TG_turnon1->SetLineColor(kBlue);
  TG_turnon1->SetMarkerColor(kBlue);
  //TG_turnon1->GetYaxis()->SetTitle("Electron ID Efficiency");
  TG_turnon1->GetYaxis()->SetTitle("Fake Rate");
  TG_turnon1->GetXaxis()->SetLimits(range_min,range_max);
  TG_turnon1->GetYaxis()->SetRangeUser(0., 0.8); //1.4);
  TG_turnon1->Draw("AP");
  legend->AddEntry(TG_turnon1, name_legend[0],"lp");
  //
  //cout <<"draw second" << endl;
  TG_turnon2->SetMarkerSize(0.9);
  TG_turnon2->SetMarkerStyle(20);
  TG_turnon2->SetLineColor(2);
  TG_turnon2->SetMarkerColor(2);
  TG_turnon2->Draw("PSAME");
  legend->AddEntry(TG_turnon2, name_legend[1],"lp");

  legend->Draw();

  //drawCMS();

//   // ----------------------------------------------
//   // TLatex
//   // ----------------------------------------------
//    TPaveText *pt = new TPaveText(0.24,0.78,0.3,0.84,"brNDC");
//    pt->SetBorderSize(0);
//    pt->SetFillColor(0);
//    pt->SetFillStyle(0);
//    pt->SetTextAlign(12);
//    pt->SetTextFont(42);
//    pt->SetTextSize(0.04);
//    TText *text = pt->AddText(0.01,0.5,"");
//    pt->Draw();
//    tex = new TLatex(0.96,0.9451429,"14 TeV");
//    tex->SetNDC();
//    tex->SetTextAlign(31);
//    tex->SetTextFont(42);
//    tex->SetTextSize(0.04114286);
//    tex->SetLineWidth(2);
//    tex->Draw();
//    tex = new TLatex(0.154345,0.7937,"CMS Simulation");
//    tex->SetNDC();
//    tex->SetTextAlign(13);
//    tex->SetTextFont(61);
//    tex->SetTextSize(0.05142857);
//    tex->SetLineWidth(2);
//    tex->Draw();
//    tex = new TLatex(0.846,0.316,"Endcaps");
//    tex->SetNDC();
//    tex->SetTextAlign(13);
//    tex->SetTextFont(42);
//    tex->SetTextSize(0.03908571);
//    tex->SetLineWidth(2);
//    tex->Draw();

  // TLatex * TL_cms = new TLatex(0.16, 0.91,"CMS Simulation, 14 TeV");
//   TL_cms->SetNDC();
//   TL_cms->SetTextFont(42);
//   TL_cms->SetTextSize(0.03);
//   TL_cms->SetLineWidth(2);
//   TL_cms->Draw("same");

//   TLatex * TL_cms = new TLatex(0.453, 0.522,"#it{HGCAL <PU>=140}");
//   TL_cms->SetNDC();
//   TL_cms->SetTextFont(42);
//   TL_cms->SetTextSize(0.035);
//   TL_cms->SetLineWidth(2);
//   TL_cms->Draw("same");
  
  // -----------------
  // Difference...
  // -----------------
  // double * x_tg1 = new double[300]; double x_tg1_errup [300]; double x_tg1_errdown [300]; 
//   double * y_tg1 = new double[300]; double y_tg1_errup [300]; double y_tg1_errdown [300]; 
  
//   double * x_tg2 = new double[300]; double x_tg2_errup [300]; double x_tg2_errdown [300]; 
//   double * y_tg2 = new double[300]; double y_tg2_errup [300]; double y_tg2_errdown [300]; 
  
//   double diff_x[300];
//   double diff_y[300];

//   //cout << " N = " << TG_turnon1->GetN() << endl;

//   //for(int i=0;i<TG_turnon1->GetN();i++) {
//   x_tg1 = TG_turnon1->GetX();
//   x_tg2 = TG_turnon2->GetX();
  
//   y_tg1 = TG_turnon1->GetY();
//   y_tg2 = TG_turnon2->GetY();
//     //} //
  
//   for(int j=0;j<TG_turnon1->GetN();j++) {
    
//     //cout << " x = " << x_tg1[j] << endl;
//     //cout << " y1 = " << y_tg1[j] << " ytg2 = " << y_tg2[j] << endl;

//     diff_x[j] = x_tg1[j];
//     if(y_tg1[j]!=0) diff_y[j] = (y_tg1[j] - y_tg2[j])/y_tg1[j];
//     else diff_y[j] = 0.;
//   } // for loop on N bins

//   TCanvas * TC_DIFF_turnons = new TCanvas ("DIFF_turnon_"+name_TG2+"_"+extra_name,"DIFF_turnon_"+name_TG2+"_"+extra_name,800,600);
//   TC_DIFF_turnons->ToggleEventStatus();
//   gPad->SetGrid();

//   TGraph * TG_diff = new TGraph(TG_turnon1->GetN(), diff_x, diff_y);
//   TG_diff->SetMarkerColor(6);
//   TG_diff->SetMarkerStyle(20);
//   TG_diff->SetLineColor(6);
//   TG_diff->SetTitle("");
//   TG_diff->GetXaxis()->SetLimits(range_min,range_max);
//   TG_diff->Draw("AP");
  
  // ------------------
  // Write in the file
  // ------------------
  cout << "Write" << endl;
  OutputFile->cd();
  TC_comp->Write();
  //TC_DIFF_turnons->Write(); 

  // ------------------
  // Print plots
  // -----------------
  if(print) {
    cout << "Print" << endl;
    TC_comp->Print("PLOTS/png/"+ TString(TC_comp->GetName())+".png");
    TC_comp->Print("PLOTS/C/"+ TString(TC_comp->GetName())+".C");
    TC_comp->Print("PLOTS/root/"+ TString(TC_comp->GetName())+".root");
    //TC_comp->Print("PLOTS/"+ TString(TC_comp->GetName())+".eps");
    //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".png");
    //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".eps");
  }
  
} // End of draw_comp_turnons




// ==================================================================================================================================
void draw_comp_vecturnons(TFile * OutputFile, std::vector<TString> name_TG, int REBIN, double range_min, double range_max, 
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
    
    cout << "--------> Comp Turnons " << name_TG.at(i) << endl;; 
    
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
    TG_turnon1->GetXaxis()->SetLimits(range_min,range_max);
    if(extra_name.Contains("4mu")>0) TG_turnon1->GetYaxis()->SetRangeUser(0., 0.5); //1.4);
    else TG_turnon1->GetYaxis()->SetRangeUser(0., 0.8); //1.4);
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
      TC_comp->Print("PLOTS/png/"+ TString(TC_comp->GetName())+".png");
      TC_comp->Print("PLOTS/C/"+ TString(TC_comp->GetName())+".C");
      TC_comp->Print("PLOTS/root/"+ TString(TC_comp->GetName())+".root");
      TC_comp->Print("PLOTS/pdf/"+ TString(TC_comp->GetName())+".pdf");
      //TC_comp->Print("PLOTS/"+ TString(TC_comp->GetName())+".eps");
      //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".png");
      //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".eps");
    }
    
   // End of draw_comp_turnons
  
}

// ==================================================================================================================================
//void draw_comp_vecturnonsFake(TFile * OutputFile, TFile *FakeFile, std::vector<TString> name_TG, std::vector<TString> name_Fake  ,int REBIN, 
//double range_min, double range_max, bool print, TString * name_legend, TString extra_name)
void draw_comp_vecturnonsFake(TFile * OutputFile, std::vector<TString> name_TG, std::vector<TString> name_Fake, int REBIN,
			      //name_filefake, TString name_histofake ,int REBIN, 
			      double range_min, double range_max, bool print, TString * name_legend, TString extra_name)
// ==================================================================================================================================
{
  cout << "--------> Comp Turnons & Fakes " << endl;; 
  //TG_turnon1 = (TGraphAsymmErrors*)OutputFile->Get(name_TG1); //"TG_mc_pT_matched");
  //cout << "--------> and " << name_TG2 << endl;
  //TG_turnon2 = (TGraphAsymmErrors*)OutputFile->Get(name_TG2); //"TG_mc_pT_matched_ED");

    
  int colors[6] = {kBlue-3, kGreen+3, kRed+2, kBlue-3, kGreen+3, kRed+2};
  int marker[6] = {20, 20, 20, 4, 4, 4};
  int line[6]   = {1,  1, 1,  2,  2, 2};

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

  // ---------------------
  //  Create Canvas & Pad
  // ---------------------
  TCanvas * TC_comp = new TCanvas("COMP_Faketurnon_"+name_TG.at(0)+"_"+extra_name,"COMP_Faketurnon_"+name_TG.at(0)+"_"+extra_name,800,600);
  TC_comp->ToggleEventStatus();
  
  TPad * pad1 = new TPad("pad1"+name_TG.at(0),"pad1"+name_TG.at(0),0.05,0.,0.99,0.99); //0.0,0.,0.83,0.99);
  //TPad * pad2 = new TPad("pad2"+name_TG.at(0),"pad2"+name_TG.at(0),0.3580402,0.1678322,0.8065327,0.527972);
  TPad * pad2 = new TPad("pad2"+name_TG.at(0),"pad2"+name_TG.at(0),0.3555276,0.1433566,0.870603,0.6171329);
  //0.3580402,0.0778322,0.9065327,0.627972);
   
  // Loop over TGraph/Turnons
  pad1->Draw();
  pad1->cd();
  for(unsigned int i=0;i<name_TG.size();i++) {
    
    cout << "--------> Comp Turnons " << name_TG.at(i) << endl;; 
    
    TGraphAsymmErrors * TG_turnon1;
    TG_turnon1 = (TGraphAsymmErrors*)OutputFile->Get(name_TG.at(i));
    
    //cout << "t1" << endl;
    TG_turnon1->SetMarkerSize(1.3);
    TG_turnon1->SetMarkerStyle(marker[i]);
    TG_turnon1->SetLineColor(colors[i]);
    TG_turnon1->SetLineStyle(line[i]);
    TG_turnon1->SetMarkerColor(colors[i]);
    TG_turnon1->GetXaxis()->SetTitle("p_{T}[GeV]");
    TG_turnon1->GetYaxis()->SetTitle("Electron ID Efficiency");
    TG_turnon1->GetXaxis()->SetLimits(range_min,range_max);
    TG_turnon1->GetYaxis()->SetRangeUser(0., 1.2);
    //TC_comp->cd(); pad1->cd();
    if(i==0) TG_turnon1->Draw("AP");
    else TG_turnon1->Draw("PSAME");
    legend->AddEntry(TG_turnon1, name_legend[i],"lp");
    //pad1->Update();
  }
  
  legend->Draw();
    
  drawCMS();
  
  TLatex * TL_cms = new TLatex(0.45, 0.82,"|#eta|<2.5"); 
  TL_cms->SetNDC();
  TL_cms->SetTextFont(42);
  TL_cms->SetTextSize(0.03908571);
  TL_cms->SetLineWidth(2);
  TL_cms->Draw("same");

  // ----------------------
  // Loop over Fakes
  // ----------------------
  // Get Max
  //TFile * filemax = TFile::Open(name_filefake[0]);
  //TH1F* h_max = (TH1F*) filemax->Get(name_histofake);
  //double max_histo = h_max->GetMaximum();
  TLegend *legend2 = new TLegend(0.3219512,0.7084871,0.5365854,0.9225092,NULL,"brNDC");
  //new TLegend(0.2829132,0.7087379,0.5266106,0.9368932,NULL,"brNDC");
  //(0.5917085,0.7115385,0.8115578,0.9195804,NULL,"brNDC");
  legend2->SetTextSize(0.0738); //0922); //3811252); //(0.035); 
  legend2->SetTextFont(42);
  legend2->SetLineColor(0);
  legend2->SetLineStyle(1);
  legend2->SetLineWidth(1);
  legend2->SetFillColor(0);
  legend2->SetFillStyle(0);

  TC_comp->cd(); 
  pad2->Draw();
  pad2->cd();
  pad2->SetLogy();
  //   
 //  Double_t xmin = range_min;
//   Double_t xmax = range_max;
//   Double_t dx = (xmax-xmin)/0.8;
//   Double_t ymax = 1.4*(max_histo);
//   Double_t ymin = 0;
//   Double_t dy = (ymax-ymin)/0.8;
//   pad2->SetLogy();
//   pad2->Range(xmin, ymin, xmax, ymax);
  //pad2->Range(xmin, ymin,xmax+0.1*dx, ymax+0.1*dy);// xmax, ymax);
  //pad2->Range(xmin-0.1*dx, ymin-0.1*dy, xmax+0.1*dx, ymax+0.1*dy);
  //cout << "dx = " << dx << " dy = " << dy << " ymax = " << ymax << endl;
 //  cout << " Uxmax = " << pad2->GetUxmax() << " Uxmin = " << pad2->GetUxmin() 
//        << " Uymax = " << pad2->GetUymax() << " Uymin = " << pad2->GetUymin()  << endl;
//   pad2->Draw();
 
//   pad2->cd();
//   cout << " Log Uxmax = " << pad2->GetUxmax() << " Uxmin = " << pad2->GetUxmin() 
//        << " Uymax = " << pad2->GetUymax() << " Uymin = " << pad2->GetUymin()  << endl;
  
  for(unsigned int ii=0;ii<name_Fake.size();ii++) { //name_filefake.size();ii++) {
    cout << "name_Fake = " << name_Fake.at(ii) << endl;
    TH1F* h_temp = (TH1F*)OutputFile->Get(name_Fake.at(ii));
    
    //TH1F* TH_divide1 = (TH1F*)OutputFile->Get(name_TG1);
    h_temp->SetMarkerSize(1.3);
    h_temp->SetMarkerStyle(marker[ii+3]);
    h_temp->SetLineColor(colors[ii+3]);
    h_temp->SetLineStyle(line[ii+3]);
    h_temp->SetMarkerColor(colors[ii+3]);
    h_temp->GetXaxis()->SetTitle("SC E_{T} [GeV]"); 
    if(ii==0) h_temp->Draw("P");
    else h_temp->Draw("Psame");

    legend2->AddEntry(h_temp, name_legend[ii+3],"lp");
    // Histo for Fakes
  //   TFile * file_temp  = TFile::Open(name_filefake[ii]);
    
//     TH1F* TH_fake = (TH1F*) file_temp->Get(name_histofake);
    
//     Float_t rightmax = 1.1*TH_fake->GetMaximum();
//     Float_t scale = gPad->GetUymax()/rightmax;
//     //hint1->SetLineColor(kRed);
//     //TH_fake->Scale(scale);
    
//     //TH_fake->Scale(1./N);
//     if(i==0) TH_fake->Draw("HIST");
//     else TH_fake->Draw("HISTsame");
//     //TH_fake->Draw("][sames");
    //pad2->Update();
  } // for loop on turnons
  legend2->Draw();

    //
    //cout <<"draw second" << endl;
  //  TG_turnon2->SetMarkerSize(0.9);
  //   TG_turnon2->SetMarkerStyle(20);
  //   TG_turnon2->SetLineColor(2);
  //   TG_turnon2->SetMarkerColor(2);
  //   TG_turnon2->Draw("PSAME");
  //   legend->AddEntry(TG_turnon2, name_legend[1],"lp");
  

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
    TC_comp->Print("PLOTS/png/"+ TString(TC_comp->GetName())+".png");
    TC_comp->Print("PLOTS/C/"+ TString(TC_comp->GetName())+".C");
    TC_comp->Print("PLOTS/root/"+ TString(TC_comp->GetName())+".root");
    //TC_comp->Print("PLOTS/"+ TString(TC_comp->GetName())+".eps");
    //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".png");
    //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".eps");
  }
  
  // End of draw_comp_turnons
  
}

// ==================================================================================================================================
void draw_comp_divide(TFile * OutputFile, TString name_TG1, TString name_TG2, int REBIN, double range_min, double range_max, 
		      bool print, TString * name_legend, TString extra_name)
// ==================================================================================================================================
{
  TH1F * TH_divide1;
  TH1F * TH_divide2;

  //cout << TH_divide1 << endl;

  cout << "--------> Comp Turnons " << name_TG1 << " and " << name_TG2 << endl;

  TH_divide1 = (TH1F*)OutputFile->Get(name_TG1);
  TH_divide2 = (TH1F*)OutputFile->Get(name_TG2); 
  
  if(TH_divide1==0) cout << "Not such histo1 ! " << endl;
  if(TH_divide2==0) cout << "Not such histo2 ! " << endl;
  //cout << "hey" << endl;

  // ----------------
  //  Create Legend
  // ----------------
  //TLegend* legend = new TLegend(0.70,0.1,0.9,0.3);
  //  TLegend* legend = new TLegend(0.669598,0.1311189,0.8982412,0.3688811); //NULL,"brNDC");
  //TLegend* legend = new TLegend(0.6545226,0.1171329,0.8831658,0.3548951);
  //legend->SetTextSize(0.02); 
  //legend->SetTextFont(42);
  //legend->SetTextSize(0.03496503);
  TLegend* legend;
  //legend = new TLegend(0.6394472,0.1818182,0.8592965,0.3898601,NULL,"brNDC");
  legend = new TLegend(0.7236181,0.7587413,0.9434673,0.9667832,NULL,"brNDC");
  legend->SetTextSize(0.025); 
  legend->SetTextFont(42);
  legend->SetFillColor(kWhite);
  legend->SetBorderSize(1);

  TCanvas * TC_comp = new TCanvas("COMP_turnon_"+name_TG2+"_"+extra_name,"COMP_turnon_"+name_TG2+"_"+extra_name,800,600);
  TC_comp->ToggleEventStatus();
  gPad->SetGrid();
  //
  cout << "t1" << endl;
  TH_divide1->SetMarkerSize(0.9);
  TH_divide1->SetMarkerStyle(20);
//   cout << "t1" << endl;
  TH_divide1->SetLineColor(kBlue);
  TH_divide1->SetMarkerColor(kBlue);
//   cout << "t1" << endl;
  TH_divide1->GetXaxis()->SetRangeUser(range_min,range_max); //SetRangeUser(SetLimits(range_min,range_max);
  TH_divide1->GetYaxis()->SetRangeUser(0, 0.4);
  cout << "t1 draw" << endl;
  TH_divide1->Draw(); //"AP");
  cout << "legend" << endl;
  legend->AddEntry(TH_divide1, name_legend[0],"lp");
  //
  cout <<"draw second" << endl;
  TH_divide2->SetMarkerSize(0.9);
  TH_divide2->SetMarkerStyle(20);
  TH_divide2->SetLineColor(2);
  TH_divide2->SetMarkerColor(2);
  TH_divide2->Draw("PSAME");
  legend->AddEntry(TH_divide2, name_legend[1],"lp");

  legend->Draw();

  // ------------------
  // Print Fake Rate
  // ------------------
  cout << "Histo: " << TH_divide1->GetName() << endl;
  cout << "{ ";
  for(int i=0;i<TH_divide1->GetNbinsX();i++) {
    cout << TH_divide1->GetBinContent(i) << ", " ;
  } // for loop on Nbins
  cout << "}," << endl;
  
  cout << "Histo: " << TH_divide2->GetName() << endl;
  cout << "{ ";
  for(int i=0;i<TH_divide2->GetNbinsX();i++) {
    cout << TH_divide2->GetBinContent(i) << ", " ;
  } // for loop on Nbins
  cout << "}," << endl;

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
    TC_comp->Print("PLOTS/png/"+ TString(TC_comp->GetName())+".png");
    //TC_comp->Print("PLOTS/"+ TString(TC_comp->GetName())+".eps");
    //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".png");
    //TC_DIFF_turnons->Print("PLOTS/"+TString(TC_DIFF_turnons->GetName())+".eps");
  }
  
} // End of draw_comp_turnons



// ==================================================================================================================================
void draw_comp_histo(TFile * file, TFile * OutputFile, TString name_histo_truth, TString name_histo_simu, int REBIN, double range_min, double range_max, 
		     bool print, bool norm, bool do_reweight, bool REBIN1, bool do_turnon, TString * name_legend, TString extra_name) //, TGraphAsymmErrors * TG_turn)
// ==================================================================================================================================
{
  
  //gStyle->SetOptStat(0000);
  
  TH1F* histo_truth;
  TH1F* histo_simu;
  
  cout << "-----------------> Histo for : " << name_histo_truth << "     and " << name_histo_simu << " extra = " << extra_name << endl; //Xhisto_pass << endl;
  
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
    TC_histo->Print("PLOTS/png/COMP_"+reduced_name+"_"+extra_name+".png");
    TC_log_histo->Print("PLOTS/png/LOG_COMP_"+reduced_name+"_"+extra_name+".png");
    TC_log_histo->Print("PLOTS/C/LOG_COMP_"+reduced_name+"_"+extra_name+".C");
    TC_log_histo->Print("PLOTS/root/LOG_COMP_"+reduced_name+"_"+extra_name+".root");
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
    histo_simu->GetYaxis()->SetRangeUser(0.4,1.);
    histo_simu->Draw("P"); //HIST");
    //leg4->Draw();

    // Print the plots
    if(print) {
      TC_histo_turnon->Print("PLOTS/png/Turnon_"+reduced_name+"_"+extra_name+".png");
      //TC_histo_turnon->Print("PLOTS/Turnon_"+name_histo_simu+".eps");
      TC_histo_divide->Print("PLOTS/png/Divide_"+reduced_name+"_"+extra_name+".png");
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


// ==========================================================================================================================================
void draw_histo_2files(TFile * file1, TFile * file2, TFile * OutputFile, TString name_histo_truth, int REBIN, double range_min, double range_max, 
		       bool print, bool norm, bool do_reweight, TString * name_legend, bool do_log, TString extra_name) //TDirectoryFile * TD_dir)
// ==========================================================================================================================================
{

  //gStyle->SetOptStat(0000);

  TH1F* histo_file1;
  TH1F* histo_file2;

  cout << "-----------------> Histo for : " << name_histo_truth << endl; //"     and " << name_histo_simu << endl; //Xhisto_pass << endl;


/* if      (name_histo_truth.Contains("fbrem")) legend = new TLegend(0.6155779,0.1643357,0.8442211,0.4020979,NULL,"brNDC"); */
/*   else if (name_histo_truth.Contains("sigma") || name_histo_truth.Contains("N_em") )  legend = new TLegend(0.620603,0.6381119,0.8492462,0.8758741,NULL,"brNDC"); */
/*   else if (name_histo_truth.Contains("he")    || name_histo_truth.Contains("iso"))    legend = new TLegend(0.620603,0.6381119,0.8492462,0.8758741,NULL,"brNDC"); */
/*   else if (name_histo_truth.Contains("Sig"))  legend = new TLegend(0.4, 0.168, 0.63, 0.4, NULL,"brNDC"); */
/*   //&& name_histo_truth.Contains("EE"))  */
/*   //else legend = new TLegend(0.1520101,0.6346154,0.3806533,0.8723776,NULL,"brNDC"); */
/*   else legend = new TLegend(0.7236181,0.7587413,0.9434673,0.9667832,NULL,"brNDC"); */



  // ----------------
  //  Create Legend
  // ----------------
  TLegend* legend;
  if(do_log) { 
    //legend =  new TLegend (0.671726,0.109871,0.992206,0.609605,NULL,"brNDC"); //(0.80,0.1,0.99,0.5);//0.82,0.5,0.99,0.95); //0.86,0.68,0.99,0.99);
    legend = new TLegend(0.620603,0.6381119,0.8492462,0.8758741,NULL,"brNDC");
  } // if
  else {
    //legend = new TLegend(0.7, 0.7, 0.92, 0.92,"","NDC"); ///0.78,0.63,0.99,0.99);
    legend = new TLegend(0.4158291,0.701049,0.6356784,0.9213287,NULL,"brNDC");
  } // else

  if(extra_name=="ZZ")  legend = new TLegend(0.1268844,0.7587413,0.3178392,0.9632867,NULL,"brNDC");
  if(extra_name=="bdt") legend = new TLegend(0.4045226,0.7202797,0.6231156,0.9405594,NULL,"brNDC"); 
  if(name_histo_truth.Contains("MVA")>0) legend = new TLegend(0.1268844,0.7587413,0.3178392,0.9632867,NULL,"brNDC");

  legend->SetTextSize(0.025); 
  legend->SetFillColor(kWhite);
  legend->SetBorderSize(1);

  file1->cd();
  histo_file1 = (TH1F*)file1->Get(name_histo_truth); //"JET_PT_1");
  file2->cd();
  histo_file2  = (TH1F*)file2->Get(name_histo_truth); 
  
  TCanvas * TC_histo = new TCanvas("TC_"+name_histo_truth+"_"+extra_name,"TC_"+name_histo_truth+"_"+extra_name,800,600);
  TC_histo->ToggleEventStatus();
  //init_style(gStyle);

  TPad * pad1 = new TPad("pad1"+name_histo_truth,"pad1"+name_histo_truth,0.,0.,0.83,0.99);
  TPad * pad2 = new TPad("pad2"+name_histo_truth,"pad2"+name_histo_truth,0.45,0.5,0.82,0.93) ;
  TPad * pad3 = new TPad("pad3"+name_histo_truth,"pad3"+name_histo_truth,0.5,0,0.99,0.99);

  histo_file1->Rebin(REBIN);
  //histo_file1->SetFillColor(kGray); //kBlue-6);//46); //9);
  histo_file1->SetFillColor(kBlue-6); //0); //kBlue-6);//
  //-6); //1); //kBlue-6); //2);
  histo_file1->SetLineWidth(2.);
  histo_file1->SetFillStyle(3001);
  histo_file1->SetStats(false);
  histo_file1->SetLineColor(kBlue-6);//-6); //1); //kBlack);//lue);
  histo_file1->SetMarkerColor(1);
  histo_file1->SetMarkerStyle(20);
  histo_file1->GetXaxis()->SetRangeUser(range_min,range_max);
  //histo_file1->Scale(2.34/30000.);
  legend->AddEntry(histo_file1,name_legend[0],"l"); //F
  histo_file1->SetMinimum(0.1); //01);
  
  histo_file2->SetStats(false);
  histo_file2->Rebin(REBIN);
  histo_file2->SetFillColor(0); //kBlue-6); //2);
  histo_file2->SetLineColor(kBlack); //Red); //1);
  histo_file2->SetLineWidth(2.);
  histo_file2->GetXaxis()->SetRangeUser(range_min,range_max);
  histo_file2->SetMinimum(0.1); //01);
  //histo_file2->SetFillStyle();
  histo_file2->SetMarkerColor(kBlack);//2);
  histo_file2->SetMarkerStyle(20);
  //histo_file2->Scale(1.13/30000.);
  //histo_file2->SetMinimum(0.);
  legend->AddEntry(histo_file2,name_legend[1],"l");
  
  int NB_bins1 = histo_file1->GetNbinsX();
  int NB_bins2 = histo_file2->GetNbinsX();

  int NB_file1 = histo_file1->Integral(0,NB_bins1+1);
  int NB_file2 = histo_file2->Integral(0,NB_bins2+1);
  //cout << "NB1 = " << NB_file1 << " NB2 = " << NB_file2 << endl;

  // ----------------
  //       Units
  // ----------------
  string unit = "GeV";
  if(name_histo_truth.Contains("Delta_phi"))  unit = "rad";
  else if(name_histo_truth.Contains("eta"))   unit = "";
  else if(name_histo_truth.Contains("fbrem")) unit = "";
  else if(name_histo_truth.Contains("sigma")) unit = "";
  else if(name_histo_truth.Contains("Sig"))   unit = "";
  else if(name_histo_truth.Contains("Rel"))   unit = "";
  else if(name_histo_truth.Contains("MVA"))   unit = "";
  double bin = histo_file1->GetBinWidth(1);
  char  tmp_string[500];
  sprintf(tmp_string, "Events/ %.3f", bin); // unit);
  
  histo_file1->GetYaxis()->SetTitle(TString(tmp_string)+" "+TString(unit));

 //  if(histo_file1->GetMaximum()< histo_file2->GetMaximum()) {
//     //histo_file1->SetMaximum(1.2*histo_file2->GetMaximum());
//     histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file2->GetMaximum());   
//   }
//   else {
//     //histo_file1->SetMaximum(1.2*histo_file1->GetMaximum());
//     histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file1->GetMaximum());
//   } // else
  

  //if(do_log) {
  //pad3->Draw();
  //    pad1->Draw();
  //    pad1->cd(); 
  //} // if do_log

  // ----------------
  //  Draw Plots
  // ----------------
  if(norm==true) {
    //HIST"); //PSAME");
    //histo_file1->DrawNormalized("P");//HISTSAME"); //HIST");
    //histo_file2->DrawNormalized("HISTSAME");//HISTSAME");
    
    double scale = 1;
    if(NB_file1!=0) scale = double(NB_file1)/(double)NB_file2;
    //cout << "scale = " << scale << endl;
    histo_file2->Scale(scale);
    //
    if(histo_file1->GetMaximum()< histo_file2->GetMaximum()) {
      //histo_file2->Draw("HIST");
      //histo_file1->Draw("PSAME");
      histo_file1->SetMaximum(1.2*histo_file2->GetMaximum());
    } // if max1<max2
    else {
      //histo_file1->Draw("P");
      //histo_file2->Draw("HISTSAME");
      
    } // else max1>max2

    histo_file1->Draw("HIST");
    histo_file2->Draw("PSAME");
    
    //     //histo_file1->SetMaximum(1.2*histo_file2->GetMaximum());
    //     histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file2->GetMaximum());
    //   }
    //   else {
    //     //histo_file1->SetMaximum(1.2*histo_file1->GetMaximum());
    //     histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file1->GetMaximum());
    //   } // else
  
    //histo_file1->Draw("P"); //HIST");
    //histo_file2->Draw("HISTSAME");
    //cout << histo_file1->Integral(0,NB_bins1+1) << " " << histo_file2->Integral(0,NB_bins2+1) << endl;
  } // if norm
  else {
    histo_file1->Draw("HIST");
    histo_file2->Draw("HISTSAME");

    //cout <<"file1 = "<< histo_file1->Integral(0,NB_bins1+1) << " file2= " << histo_file2->Integral(0,NB_bins2+1) << endl;
    //cout <<"Ratio = "<< histo_file1->Integral(0,NB_bins1+1) / histo_file2->Integral(0,NB_bins2+1) << endl;

  } // else norm
  
/*   if(do_log) { */
/*     TC_histo->cd(); */
/*     pad2->Draw(); */
/*     pad2->cd(); */
/*     pad2->SetLogy(); */
    
/*     if(norm==true) { */
/*       //histo_file1->Draw("HIST"); */
/*       //histo_file2->Draw("HISTSAME"); */
/*       histo_file2->DrawNormalized("HIST"); */
/*       histo_file1->DrawNormalized("PSAME"); */
/*     } // if norm */
/*     else { */
/*       histo_file1->Draw("HIST"); */
/*       histo_file2->Draw("HISTSAME"); */
/*     } // else norm */
    
/*     TC_histo->cd(); */
/*     pad3->cd(); */
/*   } // if do_log */
  
  // ----------------
  //  Draw Legend
  // ----------------
  legend->Draw();

  // LOG
  TCanvas * TC_LOG_histo = new TCanvas("TC_LOG_"+name_histo_truth+"_"+extra_name,"TC_LOG_"+name_histo_truth+"_"+extra_name,800,600);
  TC_LOG_histo->ToggleEventStatus();
  gPad->SetLogy(); 
  histo_file1->SetMinimum(0.1); //01);  
  histo_file1->Draw("HIST"); //"HIST");
  histo_file2->Draw("PSAME");
  legend->Draw();

  // ------------------
  //     Turnon...
  // ------------------
  TGraphAsymmErrors * TG_turn_temp  = new TGraphAsymmErrors();
  
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
  //TCanvas * TC_histo_turnon = new TCanvas("TC_Turnon_"+name_histo_truth+"_"+extra_name,"TC_Turnon_"+name_histo_truth+"_"+extra_name,800,600);
  //TC_histo->ToggleEventStatus();
  //gPad->SetGrid();  
  
  // Simple Divide
  TCanvas * TC_histo_divide = new TCanvas("TC_divide_"+name_histo_truth+"_"+extra_name,"TC_divide_"+name_histo_truth+"_"+extra_name,800,600);
  gPad->SetGrid();
  TH1F* histo_temp = (TH1F*) histo_file1->Clone("divide_"+name_histo_truth);
  histo_temp->Divide(histo_file2);
  histo_temp->SetLineWidth(2);
  histo_temp->SetFillColor(9);
  histo_temp->SetFillStyle(3003);
  histo_temp->SetLineColor(kBlack);
  histo_temp->SetTitle("");
  histo_temp->GetYaxis()->SetTitle("Ratio"); //Electron efficiency");
  histo_temp->GetYaxis()->SetRangeUser(0.9,2.);
  histo_temp->Draw("P");
  //leg4->Draw();

  //TG_turn = new TGraphAsymmErrors();
  //TG_turn_temp->BayesDivide(histo_file2, histo_file1);
  // TG_turn_temp->Divide(histo_truth, histo_truth, "e0");
//   TG_turn_temp->SetLineColor(9);
//   TG_turn_temp->SetMarkerColor(9);
//   TG_turn_temp->SetMarkerStyle(20);
//   TG_turn_temp->GetXaxis()->SetLimits(range_min, range_max);
//   TG_turn_temp->SetMinimum(0.3);  // 0.4
//   TG_turn_temp->SetMaximum(1.); // 1.
//   TG_turn_temp->GetYaxis()->SetTitle("Ratio"); //Electron ID efficiency");
//   //leg4->AddEntry(TG_turn_temp,"H#rightarrowZZ*#rightarrow4e   m_{H}=150 GeV/c^{2}","");
//   //
//   TString xname =  histo_file1->GetXaxis()->GetTitle();
//   TG_turn_temp->GetXaxis()->SetTitle(xname);
//   //
//   TG_turn_temp->Draw("AP");
  //leg4->Draw();
  //


  // --------------
  //  REWEIGHTING
  // --------------  
  if(do_reweight) {
    
    ofstream norm_data(TString("dat/RW_"+name_histo_truth+".dat"),ios::out); //"_"+extra+".dat"),ios::out);
    
    int NB = histo_file2->GetXaxis()->GetNbins();

    //float ratio[NB];
    
    for(int i=1;i<=NB+1;i++) {
      float diff = 0;
      if(histo_file2->GetBinContent(i)!=0) diff = histo_file1->GetBinContent(i)/histo_file2->GetBinContent(i);
      cout << "file1 = " << histo_file1->GetBinContent(i) << " file2 = " << histo_file2->GetBinContent(i) << endl;
      norm_data  << diff << endl;
      //	cout << "MC = " << vect_photonpT[0]->GetBinContent(i) << "   data = " << vect_photonpT[1]->GetBinContent(i) << "  diff = " << diff[i] << "  " << i << endl;
    } // for
    norm_data.close(); 
  } // if do_reweight 

  // ----------------
  //  Print Plots
  // ----------------
  //if(print) TC_histo->Print("PLOTS/"+name_histo_truth+".eps");
  if(print) {
    TString dir_name="";
    //if(TD_dir!=0) dir_name =  TD_dir->GetName();
    TC_histo->Print("PLOTS/"+dir_name+"/"+name_histo_truth+"_"+extra_name+".png");
    if(do_log) TC_LOG_histo->Print("PLOTS/"+dir_name+"/LOG_"+name_histo_truth+"_"+extra_name+".png");
    //TC_histo_divide->Print("PLOTS/"+dir_name+"/Divide_"+name_histo_truth+"_"+extra_name+".png");
  } // print

  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  //if(TD_dir!=0) TD_dir->cd(); 
  TC_histo->Write(name_histo_truth+"_"+extra_name);
  TC_LOG_histo->Write("LOG_"+name_histo_truth+"_"+extra_name);

}


// ==================================================================================================================================
void draw_alone_histo(TFile * file, TFile * OutputFile, TString name_histo, int REBIN, double range_min, double range_max, 
		      bool print, bool do_log)
// ==================================================================================================================================
{

  //gStyle->SetOptStat(0000);
  
  TH1F* histo_alone;
  
  cout << "-----------------> Histo alone for : " << name_histo << endl;
  
  histo_alone = (TH1F*)file->Get(name_histo);
    
  TCanvas * TC_histo = new TCanvas("TC_alone_"+name_histo,"TC_alone_"+name_histo,800,600);
  TC_histo->ToggleEventStatus();

  TPad * pad1 = new TPad("pad1"+name_histo,"pad1"+name_histo,0.05,0.,0.99,0.99); //0.0,0.,0.83,0.99);
  TPad * pad2 = new TPad("pad2"+name_histo,"pad2"+name_histo,0.45,0.45,0.94,0.93) ; // 0.45,0.5,0.82,0.93) ;
  //TPad * pad3 = new TPad("pad3"+name_histo,"pad3"+name_histo,0.5,0,0.99,0.99);

  double mean = histo_alone->GetMean();
  double meanErr = histo_alone->GetMeanError();
  char  tmp_string[500];
  sprintf(tmp_string, "Mean  = %.2f +/- %.2f", mean, meanErr); 
  TLatex* TL_mean = new TLatex(0.47, 0.41, TString(tmp_string));
  TL_mean->SetNDC();
  TL_mean->SetTextFont(42);
  TL_mean->SetTextSize(0.04);
  TL_mean->SetLineWidth(2);

  if(do_log) {
    TC_histo->cd();
    //pad3->Draw();
    pad1->Draw();
    pad1->cd(); } // if do_log
  
  histo_alone->SetStats(false);
  histo_alone->Rebin(REBIN);
  histo_alone->SetFillColor(kBlue-6); //46); //9);
  histo_alone->SetFillStyle(3003);
  histo_alone->GetXaxis()->SetRangeUser(range_min,range_max);
  histo_alone->Draw("HIST");

  TL_mean->Draw("same");
  
  if(do_log) {
    TC_histo->cd();
    pad2->Draw();
    pad2->cd();
    pad2->SetLogy();
    //histo_alone->SetStats(true);
    histo_alone->Draw("HIST");

    //TH_data->Draw("AP");
    //TS_mc->Draw("HISTSAME");
    //TH_mc_sum->Draw("HISTSAME");
    //TH_data->Draw("PSAME");
    
    TC_histo->cd();
    //pad3->cd();
  } // if do_log

  if(print) TC_histo->Print("PLOTS/png/alone_"+name_histo+".png");
  
  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  TC_histo->Write("alone_"+name_histo);

}


// ==========================================================================================================================================
void draw_profile(TFile * file1, TFile * OutputFile, TString name_histo1, TString name_histo2, int REBIN, double range_min, double range_max, 
		  bool print, TString * name_legend)
// ==========================================================================================================================================
{

  //gStyle->SetOptStat(0000);

  TH2F* histo_file1;
  TH2F* histo_file2;

  TProfile* TP_file1;
  TProfile* TP_file2;
  
  cout << "-----------------> Histo for : " << name_histo1 << endl; //"     and " << name_histo_simu << endl; //Xhisto_pass << endl;

  // ----------------
  //  Create Legend
  // ----------------
  //TLegend* legend = legend = new TLegend(0.78,0.63,0.99,0.99); 
  TLegend* legend = legend = new TLegend(0.7, 0.7, 0.92, 0.92,"","NDC"); ///0.78,0.63,0.99,0.99);
  legend->SetTextSize(0.025); 
  legend->SetFillColor(kWhite);
  legend->SetBorderSize(1);
    
  // -----------------------------------
  // Open File, get Histos, Get Profile
  // -----------------------------------
  file1->cd();
  histo_file1 = (TH2F*)file1->Get(name_histo1); //"JET_PT_1");
  histo_file1->RebinX(REBIN);

  //TP_file1 = new TProfile("profile_"+name_histo1+"_1",name_histo1+"_1");	 
  TP_file1 = histo_file1->ProfileX();
  //p_deltaetain_vs_eta[i][k][n] = new TProfile("p_deltaetain_vs_eta"+nameskind[k]+namesdata[n],"p_deltaetain_vs_eta",62,-2.7,2.7,-0.04 ,0.04);

  //file2->cd();
  histo_file2  = (TH2F*)file1->Get(name_histo2); 
  histo_file2->RebinX(REBIN);
  TP_file2 = histo_file2->ProfileX();
  
  // ----------------
  // Create Canvas
  // ----------------
  TCanvas * TC_profile = new TCanvas("TC_"+name_histo1,"TC_"+name_histo1,800,600);
  TC_profile->ToggleEventStatus();
  //init_style(gStyle);

  TP_file1->SetLineColor(kBlue);
  TP_file1->SetMarkerStyle(20);
  TP_file1->SetMarkerColor(kBlue);
  TP_file1->GetXaxis()->SetTitle(histo_file1->GetXaxis()->GetTitle());
  TP_file1->GetYaxis()->SetTitle(histo_file1->GetYaxis()->GetTitle());
  TP_file1->SetMinimum(range_min);
  TP_file1->SetMaximum(range_max);
  legend->AddEntry(TP_file1, name_legend[0],"lp"); //F

  TP_file2->SetLineColor(kRed);
  TP_file2->SetMarkerStyle(25);
  TP_file2->SetMarkerColor(kRed);
  //TP_file2->GetXaxis()->SetTitle(histo_file1->GetXaxis()->Title());
  //TP_file2->GetYaxis()->SetTitle(histo_file1->GetYaxis()->Title());
  //TP_file2->SetMinimum(range_min);
  //TP_file2->SetMaximum(range_max);
  legend->AddEntry(TP_file2,name_legend[1],"lp"); //F

  // Draw Profile
  TP_file1->Draw("ep");
  TP_file2->Draw("epsame");
  legend->Draw();
  
  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  //   if(TD_dir!=0) TD_dir->cd(); 
  TC_profile->Write("TP_"+name_histo1);
  //   TC_LOG_histo->Write("LOG_"+name_histo1);


  // ----------------
  //  Print Plots
  // ----------------
  //if(print) TC_histo->Print("PLOTS/"+name_histo1+".eps");
  if(print) {
    //TString dir_name="";
    //if(TD_dir!=0) dir_name =  TD_dir->GetName();
    TC_profile->Print("PLOTS/png/TP_"+name_histo1+".png");
    //class_2705/"+dir_name+"/"+name_histo1+".png");
    //TC_LOG_histo->Print("PLOTS/class_2705/"+dir_name+"/LOG_"+name_histo1+".png");
  } // print


} // end of draw_profile




// ==========================================================================================================================================
void draw_profile_2files(TFile * file1, TFile * file2, TFile * OutputFile, TString name_histo_truth, int REBIN, double range_min, double range_max, 
			 bool print, TString * name_legend)
			 //bool norm, bool do_reweight, TString * name_legend, bool do_log, TDirectoryFile * TD_dir)
// ==========================================================================================================================================
{

  //gStyle->SetOptStat(0000);

  TH2F* histo_file1;
  TH2F* histo_file2;

  TProfile* TP_file1;
  TProfile* TP_file2;
  
  cout << "-----------------> Histo for : " << name_histo_truth << endl; //"     and " << name_histo_simu << endl; //Xhisto_pass << endl;

  // ----------------
  //  Create Legend
  // ----------------
  //TLegend* legend = legend = new TLegend(0.78,0.63,0.99,0.99); 
  TLegend* legend = legend = new TLegend(0.7, 0.7, 0.92, 0.92,"","NDC"); ///0.78,0.63,0.99,0.99);
  legend->SetTextSize(0.025); 
  legend->SetFillColor(kWhite);
  legend->SetBorderSize(1);
    
  // -----------------------------------
  // Open File, get Histos, Get Profile
  // -----------------------------------
  file1->cd();
  histo_file1 = (TH2F*)file1->Get(name_histo_truth); //"JET_PT_1");
  histo_file1->RebinX(REBIN);

  //TP_file1 = new TProfile("profile_"+name_histo_truth+"_1",name_histo_truth+"_1");	 
  TP_file1 = histo_file1->ProfileX();
  //p_deltaetain_vs_eta[i][k][n] = new TProfile("p_deltaetain_vs_eta"+nameskind[k]+namesdata[n],"p_deltaetain_vs_eta",62,-2.7,2.7,-0.04 ,0.04);
  file2->cd();
  histo_file2  = (TH2F*)file2->Get(name_histo_truth); 
  histo_file2->RebinX(REBIN);
  TP_file2 = histo_file2->ProfileX();
  
  // ----------------
  // Create Canvas
  // ----------------
  TCanvas * TC_profile = new TCanvas("TC_"+name_histo_truth,"TC_"+name_histo_truth,800,600);
  TC_profile->ToggleEventStatus();
  //init_style(gStyle);

  TP_file1->SetLineColor(kBlue);
  TP_file1->SetMarkerStyle(20);
  TP_file1->SetMarkerColor(kBlue);
  TP_file1->GetXaxis()->SetTitle(histo_file1->GetXaxis()->GetTitle());
  TP_file1->GetYaxis()->SetTitle(histo_file1->GetYaxis()->GetTitle());
  TP_file1->SetMinimum(range_min);
  TP_file1->SetMaximum(range_max);
  legend->AddEntry(TP_file1, name_legend[0],"lp"); //F

  TP_file2->SetLineColor(kRed);
  TP_file2->SetMarkerStyle(25);
  TP_file2->SetMarkerColor(kRed);
  //TP_file2->GetXaxis()->SetTitle(histo_file1->GetXaxis()->Title());
  //TP_file2->GetYaxis()->SetTitle(histo_file1->GetYaxis()->Title());
  //TP_file2->SetMinimum(range_min);
  //TP_file2->SetMaximum(range_max);
  legend->AddEntry(TP_file2,name_legend[1],"lp"); //F

  // Draw Profile
  TP_file1->Draw("ep");
  TP_file2->Draw("epsame");
  legend->Draw();
  
  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  //   if(TD_dir!=0) TD_dir->cd(); 
  TC_profile->Write("TP_"+name_histo_truth);
  //   TC_LOG_histo->Write("LOG_"+name_histo_truth);


  // ----------------
  //  Print Plots
  // ----------------
  //if(print) TC_histo->Print("PLOTS/"+name_histo_truth+".eps");
  if(print) {
    //TString dir_name="";
    //if(TD_dir!=0) dir_name =  TD_dir->GetName();
    TC_profile->Print("PLOTS/png/TP_"+name_histo_truth+".png");
    //class_2705/"+dir_name+"/"+name_histo_truth+".png");
    //TC_LOG_histo->Print("PLOTS/class_2705/"+dir_name+"/LOG_"+name_histo_truth+".png");
  } // print


      //  p_deltaetain_vs_eta[i][k][n]= h_deltaetain_vs_eta[i][k][n]->ProfileX(temp,1,-1,"");
// 	     p_deltaetain_vs_eta[i][k][n]->SetLineColor(istyle[k]) ;
// 	     p_deltaetain_vs_eta[i][k][n]->GetXaxis()->SetTitle("#eta") ;
// 	     p_deltaetain_vs_eta[i][k][n]->GetYaxis()->SetTitle("#delta#eta") ;
// 	     p_deltaetain_vs_eta[i][k][n]->SetMarkerColor(istyle[k]);
// 	     p_deltaetain_vs_eta[i][k][n]->SetFillColor(istyle[k]);
// 	     p_deltaetain_vs_eta[i][k][n]->SetFillStyle(fillstyle[0]);
// 	     p_deltaetain_vs_eta[i][k][n]->SetTitle("CMS 7TeV");
// 	     p_deltaetain_vs_eta[i][k][n]->SetMarkerStyle(20);
// 	     if (n==1 ) p_deltaetain_vs_eta[i][k][n]->SetMarkerStyle(25);
// 	     p_deltaetain_vs_eta[i][k][n]->SetMarkerSize(0.9);
// 	     p_deltaetain_vs_eta[i][k][n]->SetLineWidth(2);
// 	     p_deltaetain_vs_eta[i][k][n]->SetMinimum(-0.005) ;
// 	     p_deltaetain_vs_eta[i][k][n]->SetMaximum(0.01) ;


  // histo_file1->Rebin(REBIN);
//   //histo_file1->SetFillColor(kGray); //kBlue-6);//46); //9);
//   histo_file1->SetFillColor(0); //kBlue-6);//
//   histo_file1->SetLineColor(kBlue); //-6); //1); //kBlue-6); //2);
//   histo_file1->SetLineWidth(1.2);
//   //histo_file1->SetFillStyle(1001);
//   histo_file1->SetStats(false);
//   //histo_file1->SetMarkerColor(1);
//   //histo_file1->SetMarkerStyle(20);
//   histo_file1->GetXaxis()->SetRangeUser(range_min,range_max);
//   //histo_file1->Scale(2.34/30000.);
//   legend->AddEntry(histo_file1,name_legend[0],"l"); //F
//   histo_file1->SetMinimum(0.);
  
//   histo_file2->SetStats(false);
//   histo_file2->Rebin(REBIN);
//   histo_file2->SetFillColor(0); //kBlue-6); //2);
//   histo_file2->SetLineColor(kRed); //1);
//   histo_file2->SetLineWidth(1.2);
//   //histo_file2->SetFillStyle();
//   //histo_file2->SetMarkerColor(1);//2);
//   //histo_file2->SetMarkerStyle(20);
//   //histo_file2->Scale(1.13/30000.);
//   //histo_file2->SetMinimum(0.);
//   legend->AddEntry(histo_file2,name_legend[1],"l");
  
//   int NB_bins1 = histo_file1->GetNbinsX();
//   int NB_bins2 = histo_file2->GetNbinsX();

//   int NB_file1 = histo_file1->Integral(0,NB_bins1+1);
//   int NB_file2 = histo_file2->Integral(0,NB_bins2+1);
//   cout << "NB1 = " << NB_file1 << " NB2 = " << NB_file2 << endl;
					
//   if(histo_file1->GetMaximum()< histo_file2->GetMaximum()) {
//     //histo_file1->SetMaximum(1.2*histo_file2->GetMaximum());
//     histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file2->GetMaximum());
//   }
//   else {
//     //histo_file1->SetMaximum(1.2*histo_file1->GetMaximum());
//     histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file1->GetMaximum());
//   } // else
  

//   if(do_log) {
//     pad3->Draw();
//     pad1->Draw();
//     pad1->cd(); 
//   } // if do_log

//   // ----------------
//   //  Draw Plots
//   // ----------------
//   if(norm==true) {
//     //histo_file1->DrawNormalized("HIST");
//     //histo_file2->DrawNormalized("PSAME");
//     double scale = 1;
//     if(NB_file1!=0) scale = double(NB_file2)/(double)NB_file1;
//     histo_file1->Scale(scale);
//     histo_file1->Draw("HIST");
//     histo_file2->Draw("HISTSAME");
//     cout << histo_file1->Integral(0,NB_bins1+1) << " " << histo_file2->Integral(0,NB_bins2+1) << endl;
//   } // if norm
//   else {
//     histo_file1->Draw("HIST");
//     histo_file2->Draw("HISTSAME");
//   } // else norm
  
//   if(do_log) {
//     TC_histo->cd();
//     pad2->Draw();
//     pad2->cd();
//     pad2->SetLogy();
    
//     if(norm==true) {
//       histo_file1->Draw("HIST");
//       histo_file2->Draw("HISTSAME");
//       //histo_file1->DrawNormalized("HIST");
//       //histo_file2->DrawNormalized("PSAME");
//     } // if norm
//     else {
//       histo_file1->Draw("HIST");
//       histo_file2->Draw("HISTSAME");
//     } // else norm
    
//     TC_histo->cd();
//     pad3->cd();
//   } // if do_log
  
//   // ----------------
//   //  Draw Legend
//   // ----------------
//   legend->Draw();

//   // LOG
//   TCanvas * TC_LOG_histo = new TCanvas("TC_LOG_"+name_histo_truth,"TC_LOG_"+name_histo_truth,800,600);
//   TC_LOG_histo->ToggleEventStatus();
//   gPad->SetLogy();
//   histo_file1->Draw("HIST");
//   histo_file2->Draw("HISTSAME");
//   //legend->Draw();

//   // ----------------
//   //  Print Plots
//   // ----------------
//   //if(print) TC_histo->Print("PLOTS/"+name_histo_truth+".eps");
//   if(print) {
//     TString dir_name="";
//     if(TD_dir!=0) dir_name =  TD_dir->GetName();
//     TC_histo->Print("PLOTS/class_2705/"+dir_name+"/"+name_histo_truth+".png");
//     TC_LOG_histo->Print("PLOTS/class_2705/"+dir_name+"/LOG_"+name_histo_truth+".png");
//   } // print

//   if(name_histo_truth=="JET_PT_2_after_truth" || name_histo_truth=="JET_PT_after_truth_L3_v15all" || name_histo_truth=="JET_PT_after_truth_L3_v1520"
//      || name_histo_truth=="JET_PT_after_truth_L3_v15" || name_histo_truth=="JET_PT_2_afterL1_truth") {
//     cout << " $$$$$$$$$$$$$$$$$$$$$$" << endl;
//     cout << " NB truth = " << NB_file1 << endl; //histo_truth->Integral() << endl;
//     cout << " NB truth  = " << NB_file2 << endl; //histo_truth->Integral() << endl;
//     cout << " $$$$$$$$$$$$$$$$$$$$$$" << endl;
//   } // if name
  
//   // -----------------
//   //   Write Canvas
//   // ----------------
//   OutputFile->cd();
//   if(TD_dir!=0) TD_dir->cd(); 
//   TC_histo->Write(name_histo_truth);
//   TC_LOG_histo->Write("LOG_"+name_histo_truth);

}

// ==================================================================================================================================
void draw_full_multiplicty (TFile * file, TFile * OutputFile, TString * name_histos, int size, int range_min, int range_max, bool print)
// ==================================================================================================================================
{
  //gStyle->SetOptStat(0000);

  TLegend* legend;
  //if(do_log) legend =  new TLegend (0.671726,0.109871,0.992206,0.609605,NULL,"brNDC"); //(0.80,0.1,0.99,0.5);//0.82,0.5,0.99,0.95); //0.86,0.68,0.99,0.99);
  legend = new TLegend(0.83,0.63,0.99,0.99);
  
  TCanvas * TC_histo = new TCanvas("TC_"+name_histos[0],"TC_"+name_histos[0],800,600);
  TC_histo->ToggleEventStatus();
  
  int colors[4] = {kRed, kGreen, kBlue,kBlack};
  TString name_legend[4] = {"Level 1", "Level 2", "Event Filter", "Offline"};

  TH1F* histos_N;
  for(int ii=0;ii<size;ii++){
    cout << "-----------------> Histo for : " << name_histos[ii] << endl;
    histos_N = (TH1F*)file->Get(name_histos[ii]);
    
    histos_N->SetFillColor(0);
    histos_N->SetLineColor(colors[ii]);
    histos_N->SetLineWidth(2);
    histos_N->SetTitle("Jet Multiplicity");
    histos_N->GetXaxis()->SetRangeUser(range_min,range_max);
    legend->AddEntry(histos_N ,name_legend[ii],"L");
    if(ii==0)  histos_N->Draw("HIST");
    else histos_N->Draw("HISTSAME");
  } // for loop on histos
  
  legend->Draw();
  
  if(print) TC_histo->Print("PLOTS/eps/full_"+name_histos[0]+".eps");
  
  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  TC_histo->Write("full_"+name_histos[0]);

}


// ==================================================================================================================================
void draw_2D_plots(TFile * file, TFile * OutputFile, TString name_histo, int REBINX, int REBINY, float range_xmin, float range_xmax, 
		   float range_ymin, float range_ymax, bool print, TString extra_name) //, bool norm, bool do_reweight, bool REBIN1)
// ==================================================================================================================================
{
  gStyle->SetPalette(1);
  
  TH2F* histo_2D;
  
  cout << "-----------------> Histo for : " << name_histo << endl; 
  
  histo_2D = (TH2F*)file->Get(name_histo); 

  TCanvas * TC_histo = new TCanvas("TC_"+name_histo+"_"+extra_name,"TC_"+name_histo+"_"+extra_name,800,600);
  TC_histo->ToggleEventStatus();

  histo_2D->RebinX(REBINX);
  histo_2D->RebinY(REBINY);
  histo_2D->GetXaxis()->SetRangeUser(range_xmin,range_xmax);
  histo_2D->GetYaxis()->SetRangeUser(range_ymin,range_ymax);
  
  histo_2D->Draw("COLZ");
  
  // Line
  TLine * TL_035 = new TLine(0.35,0,0, 0.35); //0.35,0);
  TL_035->SetLineColor(kBlack);
  TL_035->SetLineWidth(2);
  TL_035->Draw("same");

  TLine * TL_175035 = new TLine(0.175,0,0.175, 0.35); //0.35,0);
  TL_175035->SetLineColor(kBlack);
  TL_175035->SetLineWidth(2);
  TL_175035->SetLineStyle(2);
  TL_175035->Draw("same");
  
  TLine * TL_035175 = new TLine(0, 0.35, 0.175, 0.35); //0.35,0);
  TL_035175->SetLineColor(kBlack);
  TL_035175->SetLineWidth(2);
  TL_035175->SetLineStyle(2);
  TL_035175->Draw("same");

  TLine * TL_175035_v2 = new TLine(0, 0.175, 0.35, 0.175); //0.35,0);
  TL_175035_v2->SetLineColor(kBlack);
  TL_175035_v2->SetLineWidth(2);
  TL_175035_v2->SetLineStyle(2);
  TL_175035_v2->Draw("same");
  
  TLine * TL_035175v2 = new TLine(0.35,0, 0.35, 0.175); //0.35,0);
  TL_035175v2->SetLineColor(kBlack);
  TL_035175v2->SetLineWidth(2);
  TL_035175v2->SetLineStyle(2);
  TL_035175v2->Draw("same");
  


  //TList* mytlist  = (TList*)histo_2D->GetListOfFunctions();
  //TIter i(mytlist);
  //mytlist->Print();
  //TString name1 = 
  //  TPaveStats* stat = (TPaveStats*)histo_2D->GetListOfFunctions()->FindObject("TPave"); //stats");
  //stat->SetOptStat(0000);
  //TC_histo->Update();

  if(print) TC_histo->Print("PLOTS/png/2D_"+name_histo+"_"+extra_name+".png");
  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  TC_histo->Write("2D_"+name_histo+"_"+extra_name);

}

// ==================================================================================================================================
void draw_full_2D_plots(TFile * file, TFile * OutputFile, TString * name_histo, int size, int REBINX, int REBINY, float range_xmin, float range_xmax, 
			float range_ymin, float range_ymax, bool print) //, bool norm, bool do_reweight, bool REBIN1)
// ==================================================================================================================================
{
  //gStyle->SetPalette(1);
  
  TH2F* histo_2D;
  
  TCanvas * TC_histo = new TCanvas("TC_full_2D_"+name_histo[0],"TC_full_2D_"+name_histo[0],800,600);
  TC_histo->ToggleEventStatus();
  TC_histo->Divide(2,2);

  for(int ii=0;ii<size;ii++) {
    cout << "-----------------> Full 2D Histo for : " << name_histo[ii] << endl; 
    TC_histo->cd(ii+1);
    //  if(ii==0) TC_histo->cd(1,2);
    //     if(ii==1) TC_histo->cd(2,2);
    //     if(ii==2) TC_histo->cd(1,1);
    //     if(ii==3) TC_histo->cd(2,1);

    histo_2D = (TH2F*)file->Get(name_histo[ii]); 
    histo_2D->RebinX(REBINX);
    histo_2D->RebinY(REBINY);
    histo_2D->GetXaxis()->SetRangeUser(range_xmin,range_xmax);
    histo_2D->GetXaxis()->SetRangeUser(range_ymin,range_ymax);
  
    histo_2D->Draw("COLZ");
  } // for loop on name

  //TList* mytlist  = (TList*)histo_2D->GetListOfFunctions();
  //TIter i(mytlist);
  //mytlist->Print();
  //TString name1 = 
  //  TPaveStats* stat = (TPaveStats*)histo_2D->GetListOfFunctions()->FindObject("TPave"); //stats");
  //stat->SetOptStat(0000);
  //TC_histo->Update();

  if(print) TC_histo->Print("PLOTS/full_2D_"+name_histo[0]+".eps");
  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  TC_histo->Write("full_2D_"+name_histo[0]);

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Double_t gauss(Double_t *x,Double_t *par)
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
{       
  Double_t arg =0;

  if(par[2]!=0) arg=(par[0]*exp(-0.5*(x[0]-par[1])*(x[0]-par[1])/par[2]/par[2]));
  else arg=1.e30;
  return arg;
}

// ==================================================================================================================================
void draw_fit(TFile * file, TString name_histo, int REBIN, float range_min, float range_max, bool PRINT)
// ==================================================================================================================================
{
  TH1F* histo;
  
  histo = (TH1F*)file->Get(name_histo);
  
  histo->Rebin(REBIN);
  //histo_alone->GetXaxis()->SetRangeUser(range_min,range_max);

  TCanvas * TC_fit = new TCanvas("Fit_"+name_histo, "Fit_"+name_histo,800,600);

  cout << "range min = " << range_min << endl;  TF1* _gauss = new TF1("_gauss",gauss,range_min,range_max,3);
  _gauss->SetLineWidth(2);
  _gauss->SetLineStyle(10);
  _gauss->SetLineColor(4);
  _gauss->SetParName(0,"N"); 
  _gauss->SetParName(1,"mean");
  _gauss->SetParName(2,"sigma");

  //_gauss->SetParLimits(0,0,1000);

  _gauss->SetParameter(0,100);
  _gauss->SetParameter(1,1.);
  _gauss->SetParameter(2,0.15);
  
  histo->Fit("_gauss","R","",range_min,range_max);
 
  histo->Draw();

  if(PRINT) TC_fit->Print("PLOTS/png/"+name_histo+".png");

} // end of draw_fit


// ==========================================================================================================================================
void draw_2histos_2files(TFile * file1, TFile * file2, TFile * OutputFile, TString name_histo_truth, TString name_histo2, int REBIN, double range_min, double range_max, 
			 bool print, bool norm, bool do_reweight, TString * name_legend, bool do_log)
// ==========================================================================================================================================
{

  //gStyle->SetOptStat(0000);

  TH1F* histo_file1;
  TH1F* histo_file2;

  cout << "-----------------> Comp 2Histos 2 files for : " << name_histo_truth << endl; //"     and " << name_histo_simu << endl; //Xhisto_pass << endl;

  // ----------------
  //  Create Legend
  // ----------------
  TLegend* legend;
 
  if(do_log) { 
    legend =  new TLegend (0.671726,0.109871,0.992206,0.609605,NULL,"brNDC"); //(0.80,0.1,0.99,0.5);//0.82,0.5,0.99,0.95); //0.86,0.68,0.99,0.99);
    legend->SetTextSize(0.025); 
  } // if
  else {
    legend = new TLegend(0.78,0.63,0.99,0.99);
    legend->SetTextSize(0.02); 
  } // else
  
  legend->SetTextSize(0.02); 
  legend->SetTextFont(42);
  legend->SetFillColor(kWhite);
  legend->SetShadowColor(0);

  file1->cd();
  histo_file1 = (TH1F*)file1->Get(name_histo_truth); //"JET_PT_1");
  file2->cd();
  histo_file2  = (TH1F*)file2->Get(name_histo2); 
  
  TCanvas * TC_histo = new TCanvas("TC_comp_"+name_histo_truth,"TC_comp_"+name_histo_truth,800,600);
  TC_histo->ToggleEventStatus();
  //init_style(gStyle);

  TPad * pad1 = new TPad("pad1"+name_histo_truth,"pad1"+name_histo_truth,0.,0.,0.83,0.99);
  TPad * pad2 = new TPad("pad2"+name_histo_truth,"pad2"+name_histo_truth,0.45,0.5,0.82,0.93) ;
  TPad * pad3 = new TPad("pad3"+name_histo_truth,"pad3"+name_histo_truth,0.5,0,0.99,0.99);

  histo_file1->Rebin(REBIN);
  histo_file1->SetFillColor(kGray); //kBlue-6);//46); //9);
  histo_file1->SetLineColor(1); //kBlue-6); //2);
  histo_file1->SetLineWidth(1);
  histo_file1->SetFillStyle(1001);
  histo_file1->SetStats(false);
  //histo_file1->SetMarkerColor(1);
  //histo_file1->SetMarkerStyle(20);
  histo_file1->GetXaxis()->SetRangeUser(range_min,range_max);
  //histo_file1->Scale(2.34/30000.);
  legend->AddEntry(histo_file1,name_legend[0],"F");
  histo_file1->SetMinimum(0.);
  
  histo_file2->SetStats(false);
  histo_file2->Rebin(REBIN);
  //histo_file2->SetFillColor(kBlue-6); //2);
  //histo_file2->SetFillStyle();
  histo_file2->SetMarkerColor(1);//2);
  histo_file2->SetMarkerStyle(20);
  //histo_file2->Scale(1.13/30000.);
  legend->AddEntry(histo_file2,name_legend[1],"l");
  
  int NB_bins1 = histo_file1->GetNbinsX();
  int NB_bins2 = histo_file2->GetNbinsX();

  int NB_file1 = histo_file1->Integral(0,NB_bins1+1);
  int NB_file2 = histo_file2->Integral(0,NB_bins2+1);
  cout << "NB1 = " << NB_file1 << " NB2 = " << NB_file2 << endl;
					
  if(histo_file1->GetMaximum()< histo_file2->GetMaximum()) {
    //histo_file1->SetMaximum(1.2*histo_file2->GetMaximum());
    histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file2->GetMaximum());
  }
  else {
    //histo_file1->SetMaximum(1.2*histo_file1->GetMaximum());
    histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file1->GetMaximum());
  } // else
  

  if(do_log) {
    pad3->Draw();
    pad1->Draw();
    pad1->cd(); 
  } // if do_log

  // ----------------
  //  Draw Plots
  // ----------------
  if(norm==true) {
    //histo_file1->DrawNormalized("HIST");
    //histo_file2->DrawNormalized("PSAME");
    double scale = 1;
    if(NB_file1!=0) scale = double(NB_file2)/(double)NB_file1;
    histo_file1->Scale(scale);
    histo_file1->Draw("HIST");
    histo_file2->Draw("PSAME");
    cout << histo_file1->Integral(0,NB_bins1+1) << " " << histo_file2->Integral(0,NB_bins2+1) << endl;
  } // if norm
  else {
    histo_file1->Draw("HIST");
    histo_file2->Draw("PSAME");
  } // else norm
  
  if(do_log) {
    TC_histo->cd();
    pad2->Draw();
    pad2->cd();
    pad2->SetLogy();
    
    if(norm==true) {
      histo_file1->Draw("HIST");
      histo_file2->Draw("PSAME");
      //histo_file1->DrawNormalized("HIST");
      //histo_file2->DrawNormalized("PSAME");
    } // if norm
    else {
      histo_file1->Draw("HIST");
      histo_file2->Draw("PSAME");
    } // else norm
    
    TC_histo->cd();
    pad3->cd();
  } // if do_log
  
  // ----------------
  //  Draw Legend
  // ----------------
  legend->Draw();
  
  // --------------
  //  REWEIGHTING
  // --------------  
  if(do_reweight) {
    
    ofstream norm_data(TString("dat/RW_"+name_histo_truth+".dat"),ios::out); //"_"+extra+".dat"),ios::out);
    
    int NB  = histo_file2->GetXaxis()->GetNbins();
    int NB1 = histo_file1->GetXaxis()->GetNbins();
    cout << "NB " << NB << " NB1 = " << NB1 << endl;
    //float ratio[NB];
    
    for(int i=1;i<=NB1+1;i++) {
      float diff = 0;
      if(histo_file2->GetBinContent(i)!=0) diff = histo_file1->GetBinContent(i)/histo_file2->GetBinContent(i);
      cout << " i = " << i << " file1 = " << histo_file1->GetBinContent(i) << " file2 = " << histo_file2->GetBinContent(i) << " ratio = " << diff << endl;
      norm_data  << diff << endl;
      //	cout << "MC = " << vect_photonpT[0]->GetBinContent(i) << "   data = " << vect_photonpT[1]->GetBinContent(i) << "  diff = " << diff[i] << "  " << i << endl;
    } // for
    norm_data.close(); 
  } // if do_reweight 

  // ----------------
  //  Print Plots
  // ----------------
  //if(print) TC_histo->Print("PLOTS/comp_"+name_histo_truth+".eps");
  if(print) TC_histo->Print("PLOTS/png/comp_"+name_histo_truth+".png");

  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  TC_histo->Write("comp_"+name_histo_truth);

}



// ==========================================================================================================================================
void draw_MCcomposition_2files(TFile * file_mc, TFile * file_data, TFile * file_higgs, TFile * OutputFile, 
			       TString name_histo_data, TString name_histo_mc_ph, TString name_histo_mc_ele, TString name_histo_mc_had, TString name_histo_mc_higgs,
			       int REBIN, double range_min, double range_max, 
			       bool print, bool norm, bool do_log)
// ==========================================================================================================================================
{

  //gStyle->SetOptStat(0000);

  TH1F* histo_file_mc_ph;
  TH1F* histo_file_mc_ele;
  TH1F* histo_file_mc_had;
  TH1F* histo_file_mc_higgs;
  TH1F* histo_file_data; // data

  cout << "-----------------> Composition Histo for : " << name_histo_data << endl; //"     and " << name_histo_simu << endl; //Xhisto_pass << endl;

  // ----------------
  //  Create Legend
  // ----------------
  TLegend* legend;
  if(do_log) { 
    legend =  new TLegend (0.671726,0.109871,0.992206,0.609605,NULL,"brNDC"); //(0.80,0.1,0.99,0.5);//0.82,0.5,0.99,0.95); //0.86,0.68,0.99,0.99);
    legend->SetTextSize(0.025); 
  } // if
  else {
    legend = new TLegend(0.78,0.63,0.99,0.99);
    legend->SetTextSize(0.02); 
  } // else

  // ----------------
  //   Load Histos
  // ----------------
  file_mc->cd();
  histo_file_mc_ph  = (TH1F*)file_mc->Get(name_histo_mc_ph); 
  histo_file_mc_ele = (TH1F*)file_mc->Get(name_histo_mc_ele); 
  histo_file_mc_had = (TH1F*)file_mc->Get(name_histo_mc_had); 

  file_data->cd();
  histo_file_data  = (TH1F*)file_data->Get(name_histo_data); 

  file_higgs->cd();
  histo_file_mc_higgs = (TH1F*)file_higgs->Get(name_histo_mc_higgs);

  // ----------------
  //   Build Canvas
  // ----------------
  TCanvas * TC_histo = new TCanvas("TC_COMPOSITION_"+name_histo_data,"TC_COMPOSITION_"+name_histo_data,800,600);
  TC_histo->ToggleEventStatus();
  //init_style(gStyle);

  TPad * pad1 = new TPad("pad1"+name_histo_data,"pad1"+name_histo_data,0.,0.,0.83,0.99);
  TPad * pad2 = new TPad("pad2"+name_histo_data,"pad2"+name_histo_data,0.45,0.5,0.82,0.93) ;
  TPad * pad3 = new TPad("pad3"+name_histo_data,"pad3"+name_histo_data,0.5,0,0.99,0.99);

  // ----------------
  //   Draw Histos
  // ----------------
  histo_file_mc_ph->Rebin(REBIN);
  histo_file_mc_ph->SetFillColor(59); //kBlue);
  histo_file_mc_ph->SetLineColor(59); //kBlue);
  histo_file_mc_ph->SetLineWidth(1);
  histo_file_mc_ph->SetStats(false);
  histo_file_mc_ph->GetXaxis()->SetRangeUser(range_min,range_max);
  histo_file_mc_ph->SetMinimum(0.);
  legend->AddEntry(histo_file_mc_ph, "MC #gamma","F");
 
  histo_file_mc_ele->Rebin(REBIN);
  histo_file_mc_ele->SetFillColor(kGreen-3); //416-7); //kGreen);
  histo_file_mc_ele->SetLineColor(kGreen-3); //416-7); //kGreen);
  histo_file_mc_ele->SetLineWidth(1);
  histo_file_mc_ele->SetStats(false);
  histo_file_mc_ele->GetXaxis()->SetRangeUser(range_min,range_max);
  histo_file_mc_ele->SetMinimum(0.);
  legend->AddEntry(histo_file_mc_ele, "MC e","F");
  
  histo_file_mc_had->Rebin(REBIN);
  histo_file_mc_had->SetFillColor(632+1); //kRed);
  histo_file_mc_had->SetLineColor(632+1); //kRed);
  histo_file_mc_had->SetLineWidth(1);
  histo_file_mc_had->SetStats(false);
  histo_file_mc_had->GetXaxis()->SetRangeUser(range_min,range_max);
  histo_file_mc_had->SetMinimum(0.);
  legend->AddEntry(histo_file_mc_had, "MC hadrons","F");

  // DATA
  histo_file_data->SetStats(false);
  histo_file_data->Rebin(REBIN);
  //histo_file2->SetFillColor(kBlue-6); //2);
  //histo_file2->SetFillStyle();
  histo_file_data->SetMarkerColor(1);//2);
  histo_file_data->SetMarkerStyle(20);
  legend->AddEntry(histo_file_data, "DATA","l");
  
  // Integral
  int NB_bins_mc   = histo_file_mc_ph->GetNbinsX();
  int NB_bins_data = histo_file_data->GetNbinsX();

  int NB_file_mc_ph    = histo_file_mc_ph->Integral(0,NB_bins_mc+1);
  int NB_file_mc_ele   = histo_file_mc_ele->Integral(0,NB_bins_mc+1);
  int NB_file_mc_had   = histo_file_mc_had->Integral(0,NB_bins_mc+1);
  int NB_file_mc_higgs = histo_file_mc_higgs->Integral(0,NB_bins_mc+1);
  int NB_file_mc     = NB_file_mc_ph + NB_file_mc_ele + NB_file_mc_had;
  int NB_file_data   = histo_file_data->Integral(0,NB_bins_data+1);
  cout << "NB data = " << NB_file_data << " NB mc = " << NB_file_mc << endl;
 
  // Create TStack
  double scale_ele = 1.;
  double scale_ph  = 1.;
  double scale_had = 1.;
  double frac_ele  = 1.;
  double frac_ph   = 1.;
  double frac_had  = 1.;
  
  if(NB_file_mc!=0) {
    frac_ele = double(NB_file_mc_ele)/(double)NB_file_mc;
    frac_ph  = double(NB_file_mc_ph)/(double)NB_file_mc;
    frac_had = double(NB_file_mc_had)/(double)NB_file_mc;

    cout << "frac ele = " << frac_ele << " frac_ph = " << frac_ph << " frac had = " << frac_had << endl;

    if(NB_file_mc_ele!=0) scale_ele   = double(NB_file_data)/(double)NB_file_mc_ele;
    if(NB_file_mc_ph!=0)  scale_ph    = double(NB_file_data)/(double)NB_file_mc_ph;
    if(NB_file_mc_had!=0) scale_had   = double(NB_file_data)/(double)NB_file_mc_had;
  } // if NB file

  histo_file_mc_ele->Scale(scale_ele*frac_ele); //*frac_had);
  histo_file_mc_had->Scale(scale_had*frac_had); //*frac_ele);
  histo_file_mc_ph->Scale(scale_ph*frac_ph); //*frac_ph);

  THStack * TS_MC    = new THStack("TS_MC","");
  //  TS_plot->SetMaximum(3.e+9); //1000000);
  //TS_plot->SetMinimum(0.1);
  //TS_plot->SetTitle("CMS Preliminary");
  TS_MC->Add(histo_file_mc_had);
  TS_MC->Add(histo_file_mc_ph);
  TS_MC->Add(histo_file_mc_ele);

  //  if(histo_file1->GetMaximum()< histo_file2->GetMaximum()) {
  //     //histo_file1->SetMaximum(1.2*histo_file2->GetMaximum());
  //     histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file2->GetMaximum());
  //   }
  //   else {
  //     //histo_file1->SetMaximum(1.2*histo_file1->GetMaximum());
  //     histo_file1->GetYaxis()->SetRangeUser(0., 1.2*histo_file1->GetMaximum());
  //   } // else

  if(do_log) {
    pad3->Draw();
    pad1->Draw();
    pad1->cd(); 
  } // if do_log

  // ----------------
  //  Draw Plots
  // ----------------
  if(norm==true) {
    //histo_file1->DrawNormalized("HIST");
    //histo_file2->DrawNormalized("PSAME");
    double scale = 1;
    //if(NB_file_mc!=0) scale = double(NB_file_data)/(double)NB_file_mc;
    //TS_MC->Scale(scale);
    TS_MC->Draw("HIST");
    histo_file_data->Draw("PSAME");
    //cout << histo_file1->Integral(0,NB_bins1+1) << " " << histo_file2->Integral(0,NB_bins2+1) << endl;
  } // if norm
  else {
    TS_MC->Draw("HIST");
    histo_file_data->Draw("PSAME");
  } // else norm
  
  if(do_log) {
    TC_histo->cd();
    pad2->Draw();
    pad2->cd();
    pad2->SetLogy();
    
    if(norm==true) {
      TS_MC->Draw("HIST");
      histo_file_data->Draw("PSAME");
      //TS_MC->DrawNormalized("HIST");
      //histo_file_data->DrawNormalized("PSAME");
    } // if norm
    else {
      TS_MC->Draw("HIST");
      histo_file_data->Draw("PSAME");
    } // else norm
    
    TC_histo->cd();
    pad3->cd();
  } // if do_log
  
  // ----------------
  //  Draw Legend
  // ----------------
  legend->Draw();

  // ----------------
  // LOG
  // ----------------
  TCanvas * TC_LOG_histo = new TCanvas("TC_LOG_COMPOSITION_"+name_histo_data,"TC_LOG_COMPOSITION_"+name_histo_data,800,600);
  TC_LOG_histo->ToggleEventStatus();
  gPad->SetLogy();
  TS_MC->Draw("HIST");
  histo_file_data->Draw("PSAME");
  //legend->Draw();

  // ----------------
  //  Print Plots
  // ----------------
  //if(print) TC_histo->Print("PLOTS/"+name_histo_data+".eps");
  if(print) {
    TC_histo->Print("PLOTS/png/COMPOSITION_"+name_histo_data+".png");
    TC_LOG_histo->Print("PLOTS/png/LOG_COMPOSITION_"+name_histo_data+".png");
  } // print

  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  TC_histo->Write("COMPOSITION_"+name_histo_data);
  TC_LOG_histo->Write("LOG_COMPOSITION_"+name_histo_data);

  // -----------------
  // Comp Shapes Composition
  // -----------------
  TCanvas * TC_shape_histo = new TCanvas("TC_COMP_SHAPE_"+name_histo_data,"TC_COMP_SHAPE_"+name_histo_data,800,600);
  TC_shape_histo->ToggleEventStatus();
  //if(do_log) gPad->SetLogy();

  TLegend *legEleCuts = new TLegend(0.60,0.66,0.85,0.77,NULL,"brNDC");
  legEleCuts->SetTextFont(42);
  //legEleCuts->AddEntry(histo_file_mc_ele,"Data ","lp");
  legEleCuts->AddEntry(histo_file_mc_ele,"MC e","l");
  legEleCuts->AddEntry(histo_file_mc_ph,"MC #gamma","l");
  legEleCuts->AddEntry(histo_file_mc_had,"MC others","l");
  legEleCuts->AddEntry(histo_file_mc_higgs,"MC Z#rightarrow ee","l");
  //
  legEleCuts->SetFillColor(kWhite);
  legEleCuts->SetLineColor(kWhite);
  legEleCuts->SetShadowColor(kWhite);

  TLatex *latexLabel = new TLatex();
  latexLabel->SetTextSize(0.04);
  latexLabel->SetTextFont(42);
  latexLabel->SetLineWidth(2);
  latexLabel->SetNDC();

  // NB counting
  int NB_file_mc_ph_2    = histo_file_mc_ph->Integral(0,NB_bins_mc+1);
  int NB_file_mc_ele_2   = histo_file_mc_ele->Integral(0,NB_bins_mc+1);
  int NB_file_mc_had_2   = histo_file_mc_had->Integral(0,NB_bins_mc+1);
  int NB_file_mc_higgs_2 = histo_file_mc_higgs->Integral(0,NB_bins_mc+1);
  
  // Scaling
  histo_file_mc_ph->Scale(1./NB_file_mc_ph_2);
  histo_file_mc_ele->Scale(1./NB_file_mc_ele_2);
  histo_file_mc_had->Scale(1./NB_file_mc_had_2);
  histo_file_mc_higgs->Scale(1./NB_file_mc_higgs_2);
  
   // Find Max
  double max = 0.;
  if(histo_file_mc_ph->GetMaximum()>max)    max = histo_file_mc_ph->GetMaximum();
  if(histo_file_mc_ele->GetMaximum()>max)   max = histo_file_mc_ele->GetMaximum();
  if(histo_file_mc_had->GetMaximum()>max)   max = histo_file_mc_had->GetMaximum();
  if(histo_file_mc_higgs->GetMaximum()>max) max = histo_file_mc_higgs->GetMaximum();
  //cout << " max = " << max << endl;
  max = max*1.1;
  
  // Set Stuff
  histo_file_mc_ph->SetMinimum(0.);
  histo_file_mc_ph->SetMaximum(max);
  histo_file_mc_ph->SetFillColor(0);
  histo_file_mc_ph->SetLineWidth(2.);
   
  histo_file_mc_ele->SetMinimum(0.);
  histo_file_mc_ele->SetMaximum(max);
  histo_file_mc_ele->SetFillColor(0);
  histo_file_mc_ele->SetLineWidth(2.);
  
  histo_file_mc_had->SetMinimum(0.);
  histo_file_mc_had->SetMaximum(max);
  histo_file_mc_had->SetFillColor(0.);
  histo_file_mc_had->SetLineWidth(2.);

  histo_file_mc_higgs->SetMinimum(0.);
  histo_file_mc_higgs->SetMaximum(max);
  histo_file_mc_higgs->Rebin(REBIN);
  histo_file_mc_higgs->SetFillColor(0.);
  histo_file_mc_higgs->SetLineWidth(2.);
  histo_file_mc_higgs->SetLineColor(1);
  histo_file_mc_higgs->SetLineStyle(2);

  // Draw
  histo_file_mc_higgs->GetYaxis()->SetTitle("a.u.");
  histo_file_mc_had->GetYaxis()->SetTitle("a.u.");
  histo_file_mc_had->Draw("HIST");
  histo_file_mc_ph->Draw("HISTsame");
  histo_file_mc_ele->Draw("HISTsame");
  histo_file_mc_higgs->Draw("HISTsame");

  latexLabel->DrawLatex(0.60, 0.83, "CMS Preliminary 2010");
  latexLabel->DrawLatex(0.60, 0.78, "#sqrt{s} = 7 TeV");

  legEleCuts->Draw();

  // ----------------
  // LOG - Comp Shapes Composition
  // ----------------
  TCanvas * TC_LOG_shape_histo = new TCanvas("TC_LOG_COMP_SHAPE_"+name_histo_data,"TC_LOG_COMP_SHAPE_"+name_histo_data,800,600);
  TC_LOG_shape_histo->ToggleEventStatus();
  gPad->SetLogy();
  
  // Draw
  histo_file_mc_higgs->DrawNormalized("HIST");
  histo_file_mc_had->DrawNormalized("HISTsame");
  histo_file_mc_ph->DrawNormalized("HISTsame");
  histo_file_mc_ele->DrawNormalized("HISTsame");
  
  // Write
  OutputFile->cd();
  TC_shape_histo->Write("COMP_SHAPE_"+name_histo_data);
  TC_LOG_shape_histo->Write("LOG_COMP_SHAPE_"+name_histo_data);
  if(print) { 
    TC_shape_histo->Print("PLOTS/pdf/COMP_SHAPE_"+name_histo_data+".pdf");
    TC_shape_histo->Print("PLOTS/png/COMP_SHAPE_"+name_histo_data+".png");
    TC_LOG_shape_histo->Print("PLOTS/png/LOG_COMP_SHAPE_"+name_histo_data+".png");
    TC_LOG_shape_histo->Print("PLOTS/pdf/LOG_COMP_SHAPE_"+name_histo_data+".pdf");
  } // if print
  

}


// ==================================================================================================================================
void draw_comp_vector_histo(TFile * file, TFile * OutputFile, std::vector<TString> vec_name_histo, int REBIN, double range_min, double range_max, 
			    bool print, bool norm, bool REBIN1, TString * name_legend, TString EXTRA) 
// ==================================================================================================================================
{
  
  //gStyle->SetOptStat(0000); 
  vector<TH1F*> vec_histo;
  TString reduced_name = vec_name_histo[0]; //TString
  //reduced_name.Remove("0","/");
  reduced_name.ReplaceAll("/", ""); 

  cout << "-----------------> Histo for Vec : " << vec_name_histo[0] << endl;//"     and " << vec_name_histo[0] << endl; //Xhisto_pass << endl;
   
  TCanvas * TC_histo = new TCanvas("TC_"+vec_name_histo[0],"TC_"+vec_name_histo[0],800,600);
  TC_histo->ToggleEventStatus();
  gPad->SetGrid();
  
  // colors
  int colors [8] = {kBlack, kRed, kGreen+2, kBlue, kViolet, kOrange+7, kYellow-3, kPink+10 };

  // ----------------
  //  Create Legend
  // ----------------
  TLegend* legend; // = new TLegend(0.70,0.7,0.99,0.99);
  legend = new TLegend(0.4158291,0.701049,0.6356784,0.9213287,NULL,"brNDC");
  if(vec_name_histo[0].Contains("BvsS")>0) legend = new TLegend(0.3429648,0.1923077,0.5628141,0.4125874,NULL,"brNDC");
  legend->SetTextSize(0.02); 
  legend->SetTextFont(42);
  legend->SetFillColor(kWhite);
  legend->SetShadowColor(0);

  // ----------------
  //  Loop on Histos
  // ----------------
  //cout << "size = " << vec_name_histo.size() << endl;
  TH1F * temp_histo; 
  //  TH1F * max_histo; 
  
  // -----------------------------------
  // first loop to find MAX (UGLY !!)
  // -----------------------------------
  double max=0;
  for(unsigned int ii=0;ii<vec_name_histo.size();ii++) { 
    double NB = 0;
    temp_histo = (TH1F*)file->Get(vec_name_histo[ii]);
    if(REBIN1) temp_histo->Rebin(REBIN);

    NB = temp_histo->Integral(0,  temp_histo->GetNbinsX()+1);
    if(NB!=0 && norm==true) temp_histo->Scale(1./NB);

    double max_temp = temp_histo->GetMaximum();
    if (max_temp>max) max = max_temp; //cout << "max_temp = " << max_temp << endl;
  } // for loop
  //cout << "max = " << max << endl;
  
  // -----------------------------------
  // Loop to superimpose histos
  // -----------------------------------
  for(unsigned int ii=0;ii<vec_name_histo.size();ii++) {
    cout << "ii = " << ii << " name = " << vec_name_histo[ii] << endl;
    //vec_histo.at(ii) = (TH1F*)file->Get(vec_name_histo[ii]);
    temp_histo = (TH1F*)file->Get(vec_name_histo[ii]);
      
    //cout << "after" << endl;
    temp_histo->SetFillColor(0); //kRed); //9);
    //temp_histo->SetFillStyle(3003);
    temp_histo->SetMarkerColor(colors[ii]);
    temp_histo->SetMarkerStyle(20);
    temp_histo->SetLineColor(colors[ii]);
    temp_histo->SetLineWidth(2);
    temp_histo->SetLineStyle(1);
    temp_histo->GetXaxis()->SetRangeUser(range_min,range_max);
    //cout << "max histo = " << temp_histo->GetMaximum() << endl;
    if(vec_name_histo[ii].Contains("BvsS")<=0) temp_histo->SetMaximum(1.2*max);
    else temp_histo->GetYaxis()->SetRangeUser(0.3, 1);
    //cout << "max histo after = " << temp_histo->GetMaximum() << endl;
    //
    //    if(ii==0) temp_histo->Draw("HIST");
    //xelse temp_histo->Draw("HISTSAME");
    //
    //if(ii==0) {  temp_histo->DrawNormalized("HIST"); }
    if(ii==0) temp_histo->Draw("HIST");
    //else temp_histo->DrawNormalized("HISTSAME");
    else if (vec_name_histo[ii].Contains("MVA_BDT_Train")>0) temp_histo->Draw("PSAME");
    else temp_histo->Draw("HISTSAME");
    //
    legend->AddEntry(temp_histo, name_legend[ii],"l");
  }

  legend->Draw();

  
  /// -------------------
  // LOG
  // --------------------
  TCanvas * TC_LOG_histo = new TCanvas("LOG_"+vec_name_histo[0],"LOG_"+vec_name_histo[0],800,600);
  TC_LOG_histo->ToggleEventStatus();
  gPad->SetLogy(); 
  for(unsigned int ii=0;ii<vec_name_histo.size();ii++) {
    temp_histo = (TH1F*)file->Get(vec_name_histo[ii]);
    //temp_histo->SetMinimum(0.1);
    if(ii==0) temp_histo->Draw("HIST");
    else if (vec_name_histo[ii].Contains("MVA_BDT_Train")>0) temp_histo->Draw("PSAME");
    else temp_histo->Draw("HISTSAME");
  }
  legend->Draw();
  
  //if(temp_histo->GetMaximum()< histo_simu->GetMaximum()) temp_histo->SetMaximum(1.2*histo_simu->GetMaximum());

  // -----------------------
  //  Print the plots...
  // -----------------------
  if(print) {
    TC_histo->Print("PLOTS/png/VEC_COMP_"+reduced_name+"_"+EXTRA+".png"); //vec_name_histo[0]+".png");
    TC_LOG_histo->Print("PLOTS/png/LOG_VEC_COMP_"+reduced_name+"_"+EXTRA+".png"); //vec_name_histo[0]+".png");
  }
  
  // ----------------------
  //  Write Canvas/Graphs
  // ----------------------
  OutputFile->cd();
  TC_histo->Write("VEC_COMP_"+vec_name_histo[0]);
  TC_LOG_histo->Write("LOG_VEC_COMP_"+vec_name_histo[0]);
 
}


// ==================================================================================================================================
void draw_comp_vector_TH2histo(TFile * file, TFile * OutputFile, std::vector<TString> vec_name_histo, int REBIN, double range_min, double range_max, 
			       bool print, bool norm, bool REBIN1, TString * name_legend) 
// ==================================================================================================================================
{

  //gStyle->SetOptStat(0000); 
  vector<TH1F*> vec_histo;

  // colors
  int colors [8] = {kBlack, kRed, kGreen+2, kBlue, kViolet, kOrange+7, kYellow-3, kPink+10 };

  // ----------------
  //  Create Legend
  // ----------------
  TLegend* legend = new TLegend(0.70,0.7,0.99,0.99);
  legend->SetTextSize(0.02); 
  
  // ----------------
  //  Loop on Histos
  // ----------------
  //cout << "size = " << vec_name_histo.size() << endl;
  TH2F * temp_2Dhisto; 
  TCanvas * TC_histo; //= new TCanvas("TC_"+vec_name_histo[0],"TC_"+vec_name_histo[0],800,600);
 
  for(unsigned int ii=0;ii<vec_name_histo.size();ii++) {
    cout << "ii = " << ii << " name = " << vec_name_histo[ii] << endl;
    //
    //cout << "-----------------> Histo for Vec : " << vec_name_histo[0] << endl;//"     and " << vec_name_histo[0] << endl; //Xhisto_pass << endl;
    // Canvas
    TC_histo = new TCanvas("TC_"+vec_name_histo[ii],"TC_"+vec_name_histo[ii],800,600);
    TC_histo->ToggleEventStatus();
    gPad->SetGrid();
  
    // Histo
    //vec_histo.at(ii) = (TH1F*)file->Get(vec_name_histo[ii]);
    temp_2Dhisto = (TH2F*)file->Get(vec_name_histo[ii]);
      
    temp_2Dhisto->RebinX(REBIN);
    temp_2Dhisto->RebinY(REBIN);
    temp_2Dhisto->GetXaxis()->SetRangeUser(range_min,range_max);
    temp_2Dhisto->GetYaxis()->SetRangeUser(range_min,range_max);
    
    temp_2Dhisto->Draw("COLZ");

    // -----------------------
    //  Print the plots...
    // -----------------------
    if(print) TC_histo->Print("PLOTS/png/TH2_"+vec_name_histo[ii]+".png");
    
    // ----------------------
    //  Write Canvas/Graphs
    // ----------------------
    OutputFile->cd();
    TC_histo->Write("TH2_"+vec_name_histo[ii]);
    // //cout << "after" << endl;
    //     if(REBIN1) temp_2Dhisto->Rebin(REBIN);
    //     temp_2Dhisto->SetFillColor(0); //kRed); //9);
    //     //temp_2Dhisto->SetFillStyle(3003);
    //     temp_2Dhisto->SetLineColor(colors[ii]);
    //     temp_2Dhisto->SetLineWidth(2);
    //     temp_2Dhisto->SetLineStyle(1);
    //     temp_2Dhisto->GetXaxis()->SetRangeUser(range_min,range_max);
    //     //
    //     //    if(ii==0) temp_2Dhisto->Draw("HIST");
    //     //xelse temp_2Dhisto->Draw("HISTSAME");
    //     //
    //     if(ii==0) temp_2Dhisto->DrawNormalized("HIST");
    //     else temp_2Dhisto->DrawNormalized("HISTSAME");
    //     //
    //     //legend->AddEntry(temp_histo, name_legend[ii],"l");
     
  }

  //legend->Draw();

  //if(temp_histo->GetMaximum()< histo_simu->GetMaximum()) temp_histo->SetMaximum(1.2*histo_simu->GetMaximum());


 
}





// ==================================================================================================================================
void draw_comp_vector_graph(TFile * file, TFile * OutputFile, std::vector<TString> vec_name_graph, float range_min, float range_max, 
			    bool print, TString * name_legend) 
// ==================================================================================================================================
{

  //gStyle->SetOptStat(0000); 
  vector<TH1F*> vec_graph;

  cout << "-----------------> Graph for Vec : " << vec_name_graph[0] << "     and " << vec_name_graph[0] << endl; //Xgraph_pass << endl;
   
  TCanvas * TC_graph = new TCanvas("TC_"+vec_name_graph[0],"TC_"+vec_name_graph[0],800,600);
  TC_graph->ToggleEventStatus();
  gPad->SetGrid();

  // colors
  //int colors [6] = {kBlack, kRed, kGreen+2, kBlue, kViolet, kCyan+1};
  int colors [8] = {kBlack, kRed, kGreen+2, kBlue, kViolet, kCyan+1, kYellow-3, kPink+10 };

  // ----------------
  //  Create Legend
  // ----------------
  //TLegend* legend = new TLegend(0.715,0.128,0.889,0.346); 
  //legend->SetTextSize(0.02); 

  // ----------------
  //  Create Legend
  // ----------------
  TLegend* legend;
  // if      (name_histo_truth.Contains("fbrem")) legend = new TLegend(0.6155779,0.1643357,0.8442211,0.4020979,NULL,"brNDC");
  //   else if (name_histo_truth.Contains("sigma") || name_histo_truth.Contains("N_em") )  legend = new TLegend(0.620603,0.6381119,0.8492462,0.8758741,NULL,"brNDC");
  //   else if (name_histo_truth.Contains("he")    || name_histo_truth.Contains("iso"))    legend = new TLegend(0.620603,0.6381119,0.8492462,0.8758741,NULL,"brNDC");
  //   else if (name_histo_truth.Contains("Sig"))  legend = new TLegend(0.4, 0.168, 0.63, 0.4, NULL,"brNDC");
  //   //&& name_histo_truth.Contains("EE")) 
  //else legend = new TLegend(0.1520101,0.6346154,0.3806533,0.8723776,NULL,"brNDC");
  //legend = new TLegend(0.67, 0.16, 0.85, 0.38);
  //legend = new TLegend(0.1407035,0.1608392,0.3203518,0.3811189,NULL,"brNDC");
  legend = new TLegend(0.6331658,0.1730769,0.8643216,0.3933566,NULL,"brNDC");
  //7236181,0.7587413,0.9434673,0.9667832,NULL,"brNDC");

  //(0.6545226,0.1171329,0.8831658,0.3548951);
  //legend->SetTextSize(0.02); 
  legend->SetTextFont(42);
  legend->SetTextSize(0.03496503);
  legend->SetFillColor(kWhite);
  legend->SetShadowColor(0);
 //  legend->SetLineColor(1);
//   legend->SetLineStyle(1);
//   legend->SetLineWidth(1);
  //legend->SetBorderSize(0);

  // ----------------
  //  Loop on Graphs
  // ----------------
  //cout << "size = " << vec_name_graph.size() << endl;
  TGraph * temp_graph; 
  for(unsigned int ii=0;ii<vec_name_graph.size();ii++) {
    cout << "ii = " << ii << " name = " << vec_name_graph[ii] << endl;
    //vec_graph.at(ii) = (TH1F*)file->Get(vec_name_graph[ii]);
    temp_graph = (TGraph*)file->Get(vec_name_graph[ii]);
    
    //cout << "after" << endl;
    //temp_graph->SetFillColor(0); //kRed); //9);
    //temp_graph->SetFillStyle(3003);
    temp_graph->SetMarkerColor(colors[ii]);
    temp_graph->SetLineColor(colors[ii]);
    temp_graph->SetLineWidth(2);
    temp_graph->SetLineStyle(1);
    temp_graph->SetTitle(vec_name_graph[ii]);
    temp_graph->GetXaxis()->SetLimits(range_min,range_max);
    //temp_graph->SetMinimum(range_min); //GetYaxis()->SetLimits(range_min,range_max);
    //temp_graph->SetMaximum(range_max);
    //
    if(ii==0) temp_graph->Draw("AL");
    else temp_graph->Draw("LSAME");
    //
    legend->AddEntry(temp_graph, name_legend[ii],"l");
  }

  legend->Draw();

  //if(temp_graph->GetMaximum()< graph_simu->GetMaximum()) temp_graph->SetMaximum(1.2*graph_simu->GetMaximum());

  // -----------------------
  //  Print the plots...
  // -----------------------
  if(print) TC_graph->Print("PLOTS/png/VEC_COMP_"+vec_name_graph[0]+".png");
  
  // ----------------------
  //  Write Canvas/Graphs
  // ----------------------
  OutputFile->cd();
  TC_graph->Write("VEC_COMP_"+vec_name_graph[0]);
 
}



// ==================================================================================================================================
void draw_comp_vechisto(std::vector<TString> vec_name_file, TFile * OutputFile, TString name_histo_before, TString name_histo_after, 
			int REBIN, int range_min, int range_max, 
			bool print, bool REBIN1, bool do_turnon, TString * name_legend, TString extra_name) 
// ==================================================================================================================================
{

  //gStyle->SetOptStat(0000);
  
  TH1F* histo_before = 0;
  TH1F* histo_after = 0;

  cout << "-----------------> Histo for : " << name_histo_before << "     and " << name_histo_after << " extra = " << extra_name << endl; //Xhisto_pass << endl;

  double xsec[7] = {
    8.159e+08, // 15-30
    5.312e+07, // 30-50
    6.359e+06, // 50-80
    7.843e+05, // 80-120
    1.151e+05, // 120-170
    2.426e+04, // 170-300
    1.168e+03  // 300-470
  }; // 

  double N_input [7] = {
    5420080, // 15-30
    3264660, // 30-50
    3191546, // 50-80
    3190579, // 80-120
    3030480, // 120-170
    3191280, // 170-300
    3121560  // 300-470
  }; //

  // --------------------------
  // Canvas for comparison
  // --------------------------
  TCanvas * TC_comp_mc = new TCanvas("TC_comp_mc"+name_histo_after+"_"+extra_name, "TC_comp_mc"+name_histo_after+"_"+extra_name,800,600);

  // --------------------------
  // Loop on file, scale & add
  // --------------------------
  for(unsigned int ii=0;ii<vec_name_file.size();ii++) {
    TFile * file_temp  = TFile::Open(vec_name_file[ii]);
    
    TH1F* TH_histo_bef_temp = (TH1F*)file_temp->Get(name_histo_before);
    TH1F* TH_histo_aft_temp = (TH1F*)file_temp->Get(name_histo_after);
     
    double weight = 1.; double lumi = 1.;
    if(N_input[ii]!=0) weight = xsec[ii]/N_input[ii]*lumi;
    cout << "N input = " << N_input[ii] << " lumi = " << lumi << " xsec = " << xsec[ii] << " weight = " << weight << endl;
    // Scale
    TH_histo_bef_temp->Scale(weight);
    TH_histo_aft_temp->Scale(weight);

    if(ii==0) {
      histo_before = (TH1F*)TH_histo_bef_temp->Clone();//"new"); 
      histo_after  = (TH1F*)TH_histo_aft_temp->Clone();//"new"); 
    } // ii=0
    else {
      histo_before->Add(TH_histo_bef_temp);
      histo_after->Add(TH_histo_aft_temp);
    } // else

    TH_histo_bef_temp->SetLineColor(ii+1);
    TH_histo_bef_temp->SetFillColor(0);
    if(ii==0) TH_histo_bef_temp->Draw("HIST");
    else TH_histo_bef_temp->Draw("same");
    
  } // for loop on file


 
  // ----------------
  // Build Canvas
  // ----------------
  TCanvas * TC_histo = new TCanvas("TC_"+name_histo_after+"_"+extra_name,"TC_"+name_histo_after+"_"+extra_name,800,600);
  TC_histo->ToggleEventStatus();

  // ----------------
  //  Create Legend
  // ----------------
  //   TLegend* legend = new TLegend(0.70,0.7,0.99,0.99);
  //   legend->SetTextSize(0.02); 
  TLegend* legend = new TLegend(0.1520101,0.6346154,0.3806533,0.8723776,NULL,"brNDC");
  //(0.6545226,0.1171329,0.8831658,0.3548951);
  //legend->SetTextSize(0.02); 
  legend->SetTextFont(62);
  legend->SetTextSize(0.03496503);
  legend->SetFillColor(kWhite);
  legend->SetBorderSize(0);

  double NB_truth = histo_before->Integral();
  double NB_simu  = histo_after->Integral();

  string unit = "GeV";
  if(name_histo_before.Contains("Delta_phi")) unit = "rad";
  else if(name_histo_before.Contains("eta")) unit = "";
  double bin = histo_before->GetBinWidth(1);
  char  tmp_string[500];
  sprintf(tmp_string, "Events/ %.1f", bin); // unit);
  
  //TH_DATA->GetYaxis()->SetTitle(TString(tmp_string)+" "+TString(unit));

  if(REBIN1) histo_before->Rebin(REBIN);
  histo_before->SetFillColor(kRed); //9);
  histo_before->SetFillStyle(0); //3003);
  histo_before->SetLineColor(kRed);
  histo_before->SetLineWidth(2);
  histo_before->GetYaxis()->SetTitle(TString(tmp_string)+" "+TString(unit));
  histo_before->GetXaxis()->SetRangeUser(range_min,range_max);
  legend->AddEntry(histo_before, name_legend[0],"f");
 
  histo_after->Rebin(REBIN);
  histo_after->SetFillColor(kBlue); //2);
  histo_after->SetFillStyle(0); //3003);
  histo_after->SetLineWidth(2);
  histo_after->SetLineColor(kBlue);
  //histo_after->SetLineColor(1); //2);
  //histo_after->SetMarkerColor(1);//2);
  //histo_after->SetMarkerStyle(20);
  legend->AddEntry(histo_after,name_legend[1],"f");

  if(histo_before->GetMaximum()< histo_after->GetMaximum()) histo_before->SetMaximum(1.2*histo_after->GetMaximum());

  //if(norm==true) {
  //histo_before->DrawNormalized("HIST");
  //histo_after->DrawNormalized("PSAME");
  //} // if norm
  //else {
  histo_before->Draw("HIST");
  histo_after->Draw("HISTSAME"); //SAME");
  //} // else norme

  legend->Draw();

  // ----------------------
  //  Write Canvas/Graphs
  // ----------------------
  OutputFile->cd();
  TC_histo->Write("COMP_"+name_histo_after+"_"+extra_name);
  TC_comp_mc->Write(TC_comp_mc->GetName());
  //cout << "TC_comp_mc->GetName() " << TC_comp_mc->GetName() << endl;

  //  Print the plots...
  if(print) TC_histo->Print("PLOTS/png/COMP_"+name_histo_after+"_"+extra_name+".png");

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
    TCanvas * TC_histo_turnon = new TCanvas("TC_Turnon_"+name_histo_after+"_"+extra_name,"TC_Turnon_"+name_histo_after+"_"+extra_name,800,600);
    TC_histo->ToggleEventStatus();
    gPad->SetGrid();  

    //TG_turn = new TGraphAsymmErrors();
    TG_turn_temp->BayesDivide(histo_after, histo_before);
    TG_turn_temp->SetLineColor(9);
    TG_turn_temp->SetMarkerColor(9);
    TG_turn_temp->SetMarkerStyle(20);
    TG_turn_temp->GetXaxis()->SetLimits(range_min, range_max);
    TG_turn_temp->SetMinimum(0.);  // 0.4
    TG_turn_temp->SetMaximum(0.6); // 1.
    TG_turn_temp->GetYaxis()->SetTitle("Efficiency"); //Electron ID efficiency");
    leg4->AddEntry(TG_turn_temp,"H#rightarrowZZ*#rightarrow4e   m_{H}=150 GeV/c^{2}","");
    //
    TString xname =  histo_before->GetXaxis()->GetTitle();
    TG_turn_temp->GetXaxis()->SetTitle(xname);
    //
    TG_turn_temp->Draw("AP");
    //leg4->Draw();
    //
    
    // Simple Divide
    TCanvas * TC_histo_divide = new TCanvas("TC_divide_"+name_histo_after+"_"+extra_name,"TC_divide_"+name_histo_after+"_"+extra_name,800,600);
    histo_after->Divide(histo_before);
    histo_after->SetLineWidth(2);
    histo_after->SetFillColor(9);
    histo_after->SetFillStyle(3003);
    histo_after->SetLineColor(9);
    histo_after->SetTitle("");
    histo_after->GetYaxis()->SetTitle("Electron efficiency");
    histo_after->GetYaxis()->SetRangeUser(0.,1.);
    histo_after->Draw("HIST");
    leg4->Draw();

    // Print the plots
    if(print) {
      TC_histo_turnon->Print("PLOTS/png/Turnon_"+name_histo_after+"_"+extra_name+".png");
      //TC_histo_turnon->Print("PLOTS/Turnon_"+name_histo_after+".eps");
      TC_histo_divide->Print("PLOTS/png/Divide_"+name_histo_after+"_"+extra_name+".png");
      //TC_histo_divide->Print("PLOTS/Divide_"+name_histo_after+".eps");
    }

    // Write the plots
    OutputFile->cd();
    TG_turn_temp->Write("TG_"+name_histo_after+"_"+extra_name);
    TC_histo_turnon->Write("Turnon_"+name_histo_after+"_"+extra_name);
    TC_histo_divide->Write("Divide_"+name_histo_after+"_"+extra_name);
  } // if do turnon

 
  if(do_turnon) {
    cout << " $$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << " NB before = " << NB_truth << endl; //histo_before->Integral() << endl;
    cout << " NB truth  = " << NB_simu << endl; //histo_after->Integral() << endl;
    float RATIO = (float)NB_simu/(float)NB_truth;
    cout << " Ratio     = " << RATIO << endl;
    cout << " $$$$$$$$$$$$$$$$$$$$$$" << endl;
  } // if doturnon
  
  
 
} // end of draw_veccomp


// ==========================================================================================================================================
  void draw_histo_vecfiles(std::vector<TString> vec_name_file, TFile * OutputFile, TString name_histo, int REBIN, double range_min, double range_max, 
			   bool print, bool norm, bool do_reweight, TString * name_legend, bool do_log, TString EXTRA)
// ==========================================================================================================================================
{
  
  cout << "-----------------> Histo for : " << name_histo << endl; 
  TString reduced_name = name_histo; //TString
  //reduced_name.Remove("0","/");
  reduced_name.ReplaceAll("/", ""); //name_histo, "/","");
  //name_histo.Remove("/");
  cout << "-----------------> Histo for : " << reduced_name << endl; 
  cout << "-----------------> Normalize ? : " << norm << endl; 
  //TH1F* histo_file1;
  //TH1F* histo_file2;
 
  // ----------------
  //  Create Legend
  // ----------------
  //  TLegend* legend;
  //   if(do_log) { 
  //     //legend =  new TLegend (0.14, 0.74, 0.36, 0.956,NULL,"brNDC"); //0.671726,0.109871,0.992206,0.609605,NULL,"brNDC"); 
  //     //legend = new TLegend (0.741206,0.743007,0.9610553,0.958042,NULL,"brNDC");
  //     //legend = new TLegend (0.4045226,0.7202797,0.6231156,0.9405594,NULL,"brNDC"); 
  //     legend = new TLegend(0.620603,0.6381119,0.8492462,0.8758741,NULL,"brNDC");
  //     //legend->SetTextSize(0.025); 
  //   } // if
  //   else {
  //     //legend = new TLegend(0.14, 0.74, 0.36, 0.956,NULL,"brNDC"); //(0.7, 0.7, 0.92, 0.92,"","NDC"); ///0.78,0.63,0.99,0.99);
  //     //legend = new TLegend (0.741206,0.743007,0.9610553,0.958042,NULL,"brNDC");
  //     legend = new TLegend(0.4158291,0.701049,0.6356784,0.9213287,NULL,"brNDC");
  //     if(name_histo.Contains("BvsS")>0) legend = new TLegend(0.3429648,0.1923077,0.5628141,0.4125874,NULL,"brNDC");
  //     //legend = new TLegend (0.4045226,0.7202797,0.6231156,0.9405594,NULL,"brNDC"); 
  //     //legend = new TLegend(0.1494975,0.2325175,0.4886935,0.4527972,NULL,"brNDC");
  //     //legend->SetTextSize(0.025); 
  //     //legend->SetFillColor(kWhite);
  //     //legend->SetBorderSize(1);
  //   } // else
  //legend->SetTextSize(0.025); 
  //legend->SetFillColor(kWhite);
  //legend->SetBorderSize(1);

  TLegend *legend;
  if(name_histo.Contains("BvsS")>0) legend = new TLegend(0.1356784,0.1975524,0.3555276,0.4055944,NULL,"brNDC");
  else legend = new TLegend(0.5917085,0.7115385,0.8115578,0.9195804,NULL,"brNDC");
  legend->SetTextSize(0.03811252); //(0.035); 
  legend->SetTextFont(42);
  legend->SetLineColor(0);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);

  // ----------------
  //     Canvas
  // ----------------
  TCanvas * TC_histo = new TCanvas("TC_"+reduced_name+"_"+EXTRA,"TC_"+reduced_name+"_"+EXTRA,800,600);
  if(name_histo.Contains("BvsS")>0) gPad->SetGrid();
  TC_histo->ToggleEventStatus();
 
  TCanvas * TC_LOG_histo = 0;
  if(do_log) {
    TC_LOG_histo = new TCanvas("TC_LOG_"+reduced_name+"_"+EXTRA,"TC_LOG_"+reduced_name+"_"+EXTRA,800,600);
    TC_LOG_histo->ToggleEventStatus();
    gPad->SetLogy();
  } // if do log
    
  // --------------------------
  // Loop on files
  // --------------------------
  //int colors [8] = {kBlue-6, kBlack,kRed,  kGreen+2,kBlue, kViolet, kYellow-3, kOrange+7};
  //int colors[6] = {kBlue-3,  kGreen+3,  kRed+2, kBlue-3, kGreen+3, kRed+2,}; // for TP
  int colors[6] = {kBlack, kRed, kGreen+3,  kRed+2, kBlue-3, kGreen+3}; // for Ph1vs140vs200
  //int colors[6] = {kBlack, kRed, kBlue-3, kGreen+3,  kRed+2,  kGreen+3};  // for Ph1vsTPvsSD
  //int colors[6] = {kBlack, kRed, kGreen+3,  kBlue-3, kMagenta+1, kRed+3 }; //Green+3}; 
  //int marker[6] = {4, , 4, 20, 4, 20, 4}; // 4
  //int line[6]   = {1,  2, 1,  2,  1, 2};  // 2
  
  int scale[3] = {
    2951940, // phase 1
    1966396, // phase 1 aged
    387901   // hgcal
  };

  TString flavor[3] = {"phase1", "phase1aged", "hgcal"};
  
  // -----------------------------------
  // first loop to find MAX (UGLY !!)
  // -----------------------------------
  double max=0; 
  double NB[8];
  for(unsigned int ii=0;ii<vec_name_file.size();ii++) { 
    //double NB = 0;
    TFile * file  = TFile::Open(vec_name_file[ii]);
    TH1F * temp_histo = (TH1F*)file->Get(name_histo); //[ii]);
    temp_histo->Rebin(REBIN);

    NB[ii] = temp_histo->Integral(0,  temp_histo->GetNbinsX()+1);
    //if(ii==0) NB1 = NB;
    if(norm==true && do_reweight==true) temp_histo->Scale(1./scale[ii]); // for HGCAL TP plots
    else if(NB[ii]!=0 && norm==true) temp_histo->Scale(NB[0]/NB[ii]); // normal mode
    
    //cout << "NB = " << NB << " NB1 = " << NB1 << " events = " <<  temp_histo->Integral(0,  temp_histo->GetNbinsX()+1) << endl;

    double max_temp = temp_histo->GetMaximum();
    if (max_temp>max) max = max_temp; 
    //cout << "max_temp = " << max_temp << endl;

  }// for loop
  
  //cout << "max = " << max << endl;

  // -----------------------------------
  // Second loop to Draw...
  // -----------------------------------
  for(unsigned int ii=0;ii<vec_name_file.size();ii++) {
    TFile * file_temp  = TFile::Open(vec_name_file[ii]);
    
    TH1F* TH_histo_file = (TH1F*)file_temp->Get(name_histo);
    
    //  file1->cd();
    //   TH_histo_file = (TH1F*)file1->Get(name_histo); //"JET_PT_1");
    //   file2->cd();
    //   histo_file2  = (TH1F*)file2->Get(name_histo); 
    
    TH_histo_file->Rebin(REBIN);
    TH_histo_file->SetFillColor(0); //kBlue-6);//
    //if(ii==0 & name_histo.Contains("BvsS")<=0) TH_histo_file->SetFillColor(colors[ii]); 
    TH_histo_file->SetLineColor(colors[ii]); //kBlue); //-6); //1); //kBlue-6); //2);
    TH_histo_file->SetLineWidth(2.);
    //if(ii==0) TH_histo_file->SetFillStyle(3001);
    TH_histo_file->SetStats(false);
    TH_histo_file->SetTitle("");
    //TH_histo_file->SetMarkerColor(1);
    //if(ii==2) { TH_histo_file->SetMarkerStyle(20);  TH_histo_file->SetMarkerSize(0.9); } // FOR DATA
    //TH_histo_file->GetXaxis()->SetRangeUser(0.6, 1.); //range_min,range_max);
    //
    if(norm==true && do_reweight==true) TH_histo_file->Scale(1./scale[ii]);
    else if(NB[ii]!=0 && norm==true) TH_histo_file->Scale(NB[0]/NB[ii]);
    //
    TH_histo_file->GetXaxis()->SetRangeUser(range_min,range_max);
    if(name_histo.Contains("BvsS")>0)  { 
      TH_histo_file->GetYaxis()->SetRangeUser(0.8, 1); //range_max);
      TH_histo_file->GetXaxis()->SetTitle("Signal efficiency");
    }
      
    if(name_histo.Contains("BvsS")<=0) TH_histo_file->SetMaximum(1.2*max);
    //TH_histo_file->SetMinimum(0.01);
    
    cout << "NB = " << TH_histo_file->Integral(0,  TH_histo_file->GetNbinsX()+1) << endl;
    
    // ----------------
    //       Units
    // ----------------
    string unit = "GeV";
    if(name_histo.Contains("Delta_phi"))  unit = "rad";
    else if(name_histo.Contains("eta"))   unit = "";
    else if(name_histo.Contains("fbrem")) unit = "";
    else if(name_histo.Contains("sigma")) unit = "";
    else if(name_histo.Contains("Sig"))   unit = "";
    else if(name_histo.Contains("Rel"))   unit = "";
    else if(name_histo.Contains("MVA"))   unit = "";
    double bin = TH_histo_file->GetBinWidth(1);
    char  tmp_string[500];
    sprintf(tmp_string, "Events/ %.3f", bin); // unit);
    
    if(name_histo.Contains("BvsS")<=0) TH_histo_file->GetYaxis()->SetTitle(TString(tmp_string)+" "+TString(unit));
    
    if(do_reweight==true) TH_histo_file->GetYaxis()->SetTitle("Number of Fakes"); //TString(tmp_string)+" "+TString(unit));

    // LEGEND
    legend->AddEntry(TH_histo_file, name_legend[ii],"lp"); //F
    
    // ----------------
    //  Draw Plots
    // ----------------
    TC_histo->cd();
    
    if(ii==0) TH_histo_file->Draw("HIST");
    else TH_histo_file->Draw("HISTSAME");
    
    
//     if(norm==true) {
//       if(ii==0) TH_histo_file->DrawNormalized("HIST");
//       //else if(ii==2) TH_histo_file->DrawNormalized("PSAME"); // for the DATA
//       else TH_histo_file->DrawNormalized("HISTSAME"); //HIST");

//       //if(ii==0) TH_histo_file->DrawNormalized("HIST");
//       //else TH_histo_file->DrawNormalized("HISTSAME");

//       //  double scale = 1;
//       //     if(NB_file1!=0) scale = double(NB_file2)/(double)NB_file1;
//       //     TH_histo_file->Scale(scale);
//       //     TH_histo_file->Draw("HIST");
//       //     histo_file2->Draw("HISTSAME");
//       //     cout << TH_histo_file->Integral(0,NB_bins1+1) << " " << histo_file2->Integral(0,NB_bins2+1) << endl;
//     } // if norm
//     else {
//       if(ii==0) TH_histo_file->Draw("HIST");
//       //else if(ii==2) TH_histo_file->Draw("PSAME");
//       else TH_histo_file->Draw("HISTSAME"); //HIST");
//     } // else norm
    
    // ----------------
    //  Draw Legend
    // ----------------
    legend->Draw();
     
    drawCMS();

    TString pTtext;
    if(EXTRA.Contains("1020")>0)  pTtext = "10 < E_{T} < 20 GeV";
    //}
    else if (EXTRA.Contains("20")>0)  pTtext = "E_{T} > 20 GeV";
      //}
    
    //  TText *text = pt->AddText(0.01,0.5,"");
    //     pt->Draw();
    //TLatex * TL_cms
    TLatex * pttex = new TLatex(0.907,0.157, pTtext); //14 TeV");
    pttex->SetNDC();
    pttex->SetTextAlign(31);
    pttex->SetTextFont(42);
    pttex->SetTextSize(0.04114286);
    pttex->SetLineWidth(2);
    pttex->Draw();

    // ----------------
    // LOG
    // ----------------
    if(do_log) {
      TC_LOG_histo->cd();
      
      if(ii==0) TH_histo_file->Draw("HIST");
      else TH_histo_file->Draw("HISTSAME");
      
      OutputFile->cd();
      TH_histo_file->Write(reduced_name+"_"+flavor[ii]+"_"+EXTRA);
      cout << "---> Writing " << reduced_name+"_"+flavor[ii]+"_"+EXTRA << endl;
      // if(norm==true) {
      //       if(ii==0) { TH_histo_file->DrawNormalized("HIST");  TH_histo_file->SetMinimum(0.001); }
      //       else if(ii==2) TH_histo_file->DrawNormalized("PSAME");
      //       else TH_histo_file->DrawNormalized("HISTSAME");
      //       } // if norm
      //       else {
      // 	if(ii==0) TH_histo_file->Draw("HIST");
      // 	else if(ii==2) TH_histo_file->Draw("PSAME");
      // 	else TH_histo_file->Draw("HISTSAME");
      //       } // else norm
      
      TC_LOG_histo->cd();
      
      //TH_histo_file->Draw("HIST");
      //histo_file2->Draw("HISTSAME");
      legend->Draw();
 
      drawCMS();
    } // if do log
  } // for loop on files
  
  // ----------------
  //  Print Plots
  // ----------------
  //if(print) TC_histo->Print("PLOTS/"+reduced_name+".eps");
  if(print) {
    TString dir_name="";
    //if(TD_dir!=0) dir_name =  TD_dir->GetName();
    TC_histo->Print("PLOTS/"+dir_name+"/"+reduced_name+"_"+EXTRA+".png");
    TC_histo->Print("PLOTS/"+dir_name+"/"+reduced_name+"_"+EXTRA+".root");
    TC_histo->Print("PLOTS/"+dir_name+"/"+reduced_name+"_"+EXTRA+".pdf");
    cout << "PLOTS/"+dir_name+"/"+reduced_name+"_"+EXTRA+".png" << endl;
    if(do_log) TC_LOG_histo->Print("PLOTS/"+dir_name+"/LOG_"+reduced_name+"_"+EXTRA+".png");
  } // print
  
  // -----------------
  //   Write Canvas
  // ----------------
  OutputFile->cd();
  //if(TD_dir!=0) TD_dir->cd(); 
  TC_histo->Write(reduced_name+"_"+EXTRA);
  if(do_log) {
    TC_LOG_histo->Write("LOG_"+reduced_name+"_"+EXTRA);
    
  }
}

 

// ==================================================================================================================================
void draw_comp_train(TFile* OutputFile, std::vector<TString> file_tmva, std::vector<TString> file_stand, 
		     TString histo_name_tmva, std::vector<TString> vec_name_histo_stand,
		     int REBIN, double range_min, double range_max, bool print, TString * name_legend, TString EXTRA) 
// ==================================================================================================================================
{
  
  //gStyle->SetOptStat(0000); 
  //vector<TH1F*> vec_histo;
  //  TString reduced_name = vec_name_histo[0]; //TString
  //reduced_name.Remove("0","/");
  //reduced_name.ReplaceAll("/", ""); 

  //cout << "-----------------> Histo for Vec : " << vec_name_histo[0] << endl;//"     and " << vec_name_histo[0] << endl; //Xhisto_pass << endl;
   
  TCanvas * TC_histo = new TCanvas("TC_COMPTRAIN_"+vec_name_histo_stand[0],"TC_"+vec_name_histo_stand[0],800,600);
  TC_histo->ToggleEventStatus();
  gPad->SetGrid();
  
  // colors
  int colors [8] = {kBlack, kRed, kGreen+2, kBlue, kViolet, kOrange+7, kYellow-3, kPink+10 };

  // ----------------
  //  Create Legend
  // ----------------
  TLegend* legend; // = new TLegend(0.70,0.7,0.99,0.99);
  //legend = new TLegend(0.4158291,0.701049,0.6356784,0.9213287,NULL,"brNDC");
  //if(vec_name_histo[0].Contains("BvsS")>0) 
  legend = new TLegend(0.3429648,0.1923077,0.5628141,0.4125874,NULL,"brNDC");
  legend->SetTextSize(0.02); 
  legend->SetTextFont(42);
  legend->SetFillColor(kWhite);
  legend->SetShadowColor(0);

  // ----------------
  //  Loop on Histos
  // ----------------
  //cout << "size = " << vec_name_histo.size() << endl;
  TH1F * temp_histo = 0; 
  
  // -----------------------------------
  // Loop to superimpose histos from TMVA
  // -----------------------------------
  for(unsigned int ii=0;ii<file_tmva.size();ii++) {
    cout << "ii = " << ii << " name = " << file_tmva[ii] << endl;
    TFile * file = TFile::Open(file_tmva[ii]); //name_filefake[0]);
    //vec_histo.at(ii) = (TH1F*)file->Get(vec_name_histo[ii]);
    cout << "name = " << histo_name_tmva << endl;
    temp_histo = (TH1F*)file->Get(histo_name_tmva); //vec_name_histo_tmva[ii]);
      
    //cout << "after" << endl;
    //  temp_histo->SetFillColor(0); //kRed); //9);
    //     //temp_histo->SetFillStyle(3003);
    //     temp_histo->SetMarkerColor(colors[ii]);
    //     temp_histo->SetMarkerStyle(20);
    //     temp_histo->SetLineColor(colors[ii]);
    //     temp_histo->SetLineWidth(2);
    //     temp_histo->SetLineStyle(1);
   
    temp_histo->GetXaxis()->SetRangeUser(range_min,range_max);
    temp_histo->GetYaxis()->SetRangeUser(0.6, 1); //range_min,range_max);
     
//     //cout << "max histo = " << temp_histo->GetMaximum() << endl;
//     if(vec_name_histo[ii].Contains("BvsS")<=0) temp_histo->SetMaximum(1.2*max);
//     else temp_histo->GetYaxis()->SetRangeUser(0.3, 1);
//     //cout << "max histo after = " << temp_histo->GetMaximum() << endl;
//     //
//     //    if(ii==0) temp_histo->Draw("HIST");
//     //xelse temp_histo->Draw("HISTSAME");
//     //
//     //if(ii==0) {  temp_histo->DrawNormalized("HIST"); }
//     if(ii==0) temp_histo->Draw("HIST");
//     //else temp_histo->DrawNormalized("HISTSAME");
//     else if (vec_name_histo[ii].Contains("MVA_BDT_Train")>0) temp_histo->Draw("PSAME");
//     else temp_histo->Draw("HISTSAME");
    if(ii==0) temp_histo->Draw("HIST");
    else temp_histo->Draw("HISTSAME");
    
    //
    legend->AddEntry(temp_histo, name_legend[ii],"l");
  } // loop on tmva

  // -----------------------------------
  // Loop to superimpose histos from Standalone
  // -----------------------------------
  for(unsigned int ii=0;ii<file_stand.size();ii++) {
    cout << "ii = " << ii << " file name = " << file_stand[ii] << endl;
    TFile * file = TFile::Open(file_stand[ii]); 
    
    for(unsigned int jj=0;jj<vec_name_histo_stand.size();jj++) {
      cout << " histo = " << vec_name_histo_stand.at(jj) << endl;
      TGraph* temp_graph = (TGraph*)file->Get(vec_name_histo_stand[jj]);
      
      temp_graph->Draw("SAME"); 
      //vec_histo.at(ii) = (TH1F*)file->Get(vec_name_histo[ii]);
      //temp_histo = (TH1F*)file->Get(vec_name_histo_tmva[ii]);
      
      legend->AddEntry(temp_histo, name_legend[ii],"l");
    } // vec name histo stand
  } // file stand


  legend->Draw();

  
  // -----------------------
  //  Print the plots...
  // -----------------------
  if(print) {
    TC_histo->Print(TString(TC_histo->GetName())+"_"+EXTRA+".png"); 
  }
  
  // ----------------------
  //  Write Canvas/Graphs
  // ----------------------
  OutputFile->cd();
  TC_histo->Write(TString(TC_histo->GetName())+"_"+EXTRA); //+".png");  //"VEC_COMP_"+vec_name_histo[0]);
  
}


// ==================================================================================================================================
void comp_FRMhits(std::vector<TString> vec_file_name, std::vector<TString> vec_fakename_EBEE, TFile* OutputFile, TString mhitsname, TString file_ZLL, TString mhitsnameZLL)
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

  for(unsigned int i=0;i<vec_file_name.size();i++) {
    TFile *file = TFile::Open(vec_file_name.at(i)); 
    TH1F* h_mhits = (TH1F*)file->Get(mhitsname);
    mhits[i] = h_mhits->GetMean();
    mhitsErr[i] = h_mhits->GetMeanError();
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
  TH1F* zLL_mhits = (TH1F*)f_ZLL->Get(mhitsnameZLL);
  //TH1F* h_mhits = (TH1F*)file->Get(mhitsname);
  cout << " ==============" << endl;
  cout << " pT " << mhitsname << endl;
  cout << " mean = " << zLL_mhits->GetMean() << " error = " << zLL_mhits->GetMeanError() << endl;
  double corr_fake =  f1->Eval(zLL_mhits->GetMean());
  double corr_fakeErr = f1->Eval(zLL_mhits->GetMeanError() + zLL_mhits->GetMean());
  cout << corr_fake << " " << corr_fakeErr << endl;
  cout << " ==============" << endl;
  //mhits[i] = h_mhits->GetMean();

  // -----------------------
  //        Write
  // -----------------------
  OutputFile->cd();
  TC_FRvsMhits->Write();

  TC_FRvsMhits->Print("PLOTS/png/"+TString(TC_FRvsMhits->GetName())+".png");
  TC_FRvsMhits->Print("PLOTS/pdf/"+TString(TC_FRvsMhits->GetName())+".pdf");
 }

 // ==================================================================================================================================
void draw_comp_corrFR(TFile* OutputFile, TString name_FR)
// ==================================================================================================================================
{
  TCanvas * TC_corrFR = new TCanvas("CORRFR_"+name_FR, "CORRFR_"+name_FR, 800, 600);
  gPad->SetGrid();

  TGraph* h_fake = (TGraph*)OutputFile->Get(name_FR); /// vec_fakename_EBEE.at(j));
  h_fake->GetYaxis()->SetRangeUser(0,0.2);
  h_fake->GetXaxis()->SetTitle("Lepton pT"); 
  h_fake->Draw("AP");

  // 
  //7,10,20,30,40,50,80
  double pTbins[6]      = {8.5, 15, 25, 35, 45, 65}; // 7,10,20,30,40,50,80};
  double pTbinsErr[6] = {1.5, 5, 5, 5, 5, 15};
  
  double corrEB[6] = {0.020687,  0.019609, 0.0506095, 0.0280723, 0.0296561, 0.100752 };
  double corrEBErr[6] = {0.0294707 - corrEB[0],  0.0272634- corrEB[1], 0.0658386- corrEB[2], 0.0418654 - corrEB[3], 0.033576- corrEB[4], 0.135549- corrEB[5]};

  double corrEE[6] = {0.0394433 , 0.0465471, 0.0748147, 0.0304773, 0.0475017, 0.141148 };
  double corrEEErr[6] = {0.0543364- corrEE[0], 0.0613032- corrEE[1], 0.0969381- corrEE[2], 0.041634- corrEE[3], 0.0623318- corrEE[4], 0.149169- corrEE[5]};
	
  double * TGpTbins = new double[6];
  double * TGpTbinsErr = new double[6];
  double * TGcorrFR = new double[6];
  double * TGcorrFRErr = new double[6];
  for(int i=0;i<6;i++) {
    TGpTbins[i] = pTbins[i];
    TGpTbinsErr[i] = pTbinsErr[i];

    if(name_FR.Contains("EB")>0) {
	TGcorrFR[i] = corrEB[i];
	TGcorrFRErr[i] = corrEBErr[i];
      }
    else if(name_FR.Contains("EE")>0) {
      TGcorrFR[i] = corrEE[i];
      TGcorrFRErr[i] = corrEEErr[i];
    }
  } // for loop

    TGraph * CorrFR = new TGraphErrors(6, TGpTbins, TGcorrFR, TGpTbinsErr, TGcorrFRErr); // TGcorr vec_file_name.size(), mhits, fakerate, mhitsErr, fakerateErr);
    //FRvsMhits->SetTitle("");
    CorrFR->SetMarkerStyle(20);
    CorrFR->SetMarkerColor(kRed);
    CorrFR->SetLineColor(kRed);
    CorrFR->Draw("PSAME");
  // FRvsMhits->GetXaxis()->SetTitle("Missing Hits");
  //FRvsMhits->GetYaxis()->SetTitle("Fake Rate");
  
 // -----------------------
  //        Write
  // -----------------------
  OutputFile->cd();
  TC_corrFR->Write();
  CorrFR->Write("CorrFR_"+TString(name_FR));

  TC_corrFR->Print("PLOTS/"+TString(TC_corrFR->GetName())+".png");
  TC_corrFR->Print("PLOTS/"+TString(TC_corrFR->GetName())+".pdf");
  
}






 // ==================================================================================================================================
void draw_comp_inclcorrFR(TFile* OutputFile, TString name_FR)
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

    if(name_FR.Contains("EB")>0) {
	TGcorrFR[i] = corrEB[i];
	TGcorrFRErr[i] = corrEBErr[i];
      }
    else if(name_FR.Contains("EE")>0) {
      TGcorrFR[i] = corrEE[i];
      TGcorrFRErr[i] = corrEEErr[i];
    }
  } // for loop

    TGraph * CorrFR = new TGraphErrors(1, TGpTbins, TGcorrFR, TGpTbinsErr, TGcorrFRErr); // TGcorr vec_file_name.size(), mhits, fakerate, mhitsErr, fakerateErr);
    //FRvsMhits->SetTitle("");
    CorrFR->SetMarkerStyle(20);
    CorrFR->SetMarkerColor(kRed);
    CorrFR->SetLineColor(kRed);
    CorrFR->Draw("PSAME");
  // FRvsMhits->GetXaxis()->SetTitle("Missing Hits");
  //FRvsMhits->GetYaxis()->SetTitle("Fake Rate");
  
 // -----------------------
  //        Write
  // -----------------------
  OutputFile->cd();
  TC_corrFR->Write();
  CorrFR->Write("CorrFR_"+TString(name_FR));

  TC_corrFR->Print("PLOTS/png/"+TString(TC_corrFR->GetName())+".png");
  TC_corrFR->Print("PLOTS/pdf/"+TString(TC_corrFR->GetName())+".pdf");
  
}
