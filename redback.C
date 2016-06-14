//Created by Christophe Orchando
//Modified by Pedro Cipriano

// C/C++ include
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <TFile.h>
#include <TH1.h>
#include <TGraph.h>
#include <TTree.h>
#include <TBranch.h>

#include "ZZAnalysis/AnalysisStep/src/Category.cc"

#include "ZZAnalysis/AnalysisStep/interface/FinalStates.h"
//#include "/home/llr/cms/ochando/CJLST/CMSSW_7416p1_ZX/src/ZZAnalysis/AnalysisStep/interface/bitops.h"

using namespace std;

bool test_bit( int mask, unsigned int iBit ) {
  return (mask >> iBit) & 1; 
}

int findBin(double LepPt, double LepId) {
  int bin = 0;
  if(LepPt > 5 && LepPt<=7) bin = 0;
  else if(LepPt > 7 && LepPt<=10) bin = 1;
  else if(LepPt > 10 && LepPt<=20) bin = 2;
  else if(LepPt > 20 && LepPt<=30) bin = 3;
  else if(LepPt > 30 && LepPt<=40) bin = 4;
  else if(LepPt > 40 && LepPt<=50) bin = 5;
  else if(LepPt > 50 && LepPt<=80) bin = 6;

  if(fabs(LepId)==11) bin = bin - 1; // only 6 bins in e-fake rate...

  return bin;
}

// ========================================================================================================================
void redback(TString FS = "4e", TString dataset = "ALL", TString mode = "estimate", TString cat = "ALL", TString EXTRA="")
// ========================================================================================================================
{
  cout << "---> Working with Final State : " << FS << endl;
  cout << "---> Working with Dataset :     " << dataset << endl;
  cout << "---> Working with Category :    " << cat << endl;
  cout << "---> Working with mode :        " << mode << endl;
  cout << "---> Working with Extra :       " << EXTRA << endl;

  if( (FS!="4e") && (FS!="4mu")  && (FS!="2e2mu") &&  (FS!="2mu2e") )
    { cout << " ERROR ! FinalState should be 4e, 4mu, 2e2mu or 2mu2e" << endl; return; }
  

  if( (cat!="ALL") && (cat != "untagged") && (cat != "VBF-1j") && (cat != "ttH") && (cat != "VH-leptonic") && (cat != "VH-hadronic") && (cat != "VBF-2j"))
    { cout << " ERROR ! The category should be ALL, untagged, VBF-1j, ttH, VH-leptonic, VH-hadronic or VBF-2j" << endl; return; }


  float lumi = 2.6; 
  cout << "---> Working with : " << lumi << " fb-1"  << endl;
  
  //gROOT->ProcessLine(".L /home/llr/cms/ochando/CJLST/CMSSW_7416p1_ZX/src/ZZAnalysis/AnalysisStep/interface/FinalStates.h");
  //gROOT->ProcessLine(".L /home/llr/cms/ochando/CJLST/CMSSW_7416p1_ZX/src/ZZAnalysis/AnalysisStep/src/bitops.cc");

  // ------------------------------------------------
  // Dataset
  // ------------------------------------------------
  bool isMC=true;

  TString dataflag = "";
  if( dataset=="DY50" )      dataflag = "DYJetsToLL_M50";
  else if( dataset=="TT" )   dataflag = "TTTo2L2Nu"; //"TTTo2L2nu";
  else if( dataset=="WZ" )  dataflag = "WZTo3LNu";
  else if( dataset=="ZZ" )   dataflag =  "ZZTo4l";
  else if( dataset=="DEG")  { dataflag= "DoubleEGAll"; isMC=false; }
  else if( dataset=="FEG")  { dataflag= "EGAll"; isMC=false; }
  else if( dataset=="DMU") { dataflag= "DoubleMuAll"; isMC=false; }
  else if( dataset=="ALL")   { dataflag= "AllData"; isMC=false; }
  else  { cout << " ERROR ! dataset should be DY50, TT, WZ, ZZ, DEG" << endl; return; }
  
  // ------------------------------------------------
  // FakeRates
  // ------------------------------------------------
  cout << "---> Open Fake Rates " << endl;
  //TFile* fFakeRates = TFile::Open(inputFileFakeRates.c_str());
 
  cout << "---> Open Electron Fake Rates " << endl;
  TString file_electron ;
  if(EXTRA.Contains("incl")>0) file_electron = "histograms/computed_fakerate/4e/computedfakerate_incl.root"; 
  else file_electron = "histograms/computed_fakerate/4e/computedfakerate_.root"; 
  cout << "Using : " << file_electron << endl;
  TFile * f_electron = TFile::Open(file_electron);
  
  cout << "---> Open Muon Fake Rates " << endl;
  TString file_muon = "histograms/computed_fakerate/4mu/computedfakerate_.root";
  cout << "Using : " << file_muon << endl;
  TFile * f_muon = TFile::Open(file_muon);
  //
  TGraph* h1D_FRmu_EB = (TGraph*)f_muon->Get("TG_Lep3_pT_all_EB_afterMET_76X");
  TGraph* h1D_FRmu_EE = (TGraph*)f_muon->Get("TG_Lep3_pT_all_EE_afterMET_76X"); 
  //cout << "muon" << endl;
  double * fakemu_EB = new double[10]; fakemu_EB = h1D_FRmu_EB->GetY();
  //cout << "ee" << endl;
  double * fakemu_EE = new double[10]; fakemu_EE = h1D_FRmu_EE->GetY();
  //
  cout << "Open Electron" << endl;
  TString fakeEB = "";
  TString fakeEE = "";
  if (mode == "estimate")
	{
  	fakeEB = "TG_Lep3_pT_all_EB_afterMET_76X";
  	fakeEE = "TG_Lep3_pT_all_EE_afterMET_76X";
  	if(EXTRA.Contains("incl")>0)
		{ 
      		fakeEB = "TG_Lep3_pT_all_EB_afterMET_76Xincl";
      		fakeEE = "TG_Lep3_pT_all_EE_afterMET_76Xincl";
    		}
	}
  if (mode == "final")
	{
  	fakeEB = "CorrFR_TG_Lep3_pT_all_EB_afterMET_76X";
  	fakeEE = "CorrFR_TG_Lep3_pT_all_EE_afterMET_76X";
  	if(EXTRA.Contains("incl")>0)
		{ 
      		fakeEB = "CorrFR_TG_Lep3_pT_all_EB_afterMET_76Xincl";
      		fakeEE = "CorrFR_TG_Lep3_pT_all_EE_afterMET_76Xincl";
    		}
	}
  TGraph* h1D_FRel_EB = (TGraph*)f_electron->Get(fakeEB);
  TGraph* h1D_FRel_EE = (TGraph*)f_electron->Get(fakeEE);
  cout << "Tgraphs : " << fakeEB << " " << fakeEE << endl;
  double * fakeele_EB = h1D_FRel_EB->GetY();
  double * fakeele_EE = h1D_FRel_EE->GetY();
  
  // ------------------------------------------------
  // OutPut File
  // ------------------------------------------------
  TString outputfile_name = "histograms/FR/"+FS+"/FR_CRZLL_"+dataset+"_"+EXTRA+".root";
  cout << "---> Output File : " << outputfile_name << endl;
  TFile * OutputFile = new TFile(outputfile_name, "RECREATE"); //, "", 5);
  // ------------------------------------------------
  // load the tree 
  // ------------------------------------------------
  TFile* myfile;

  //myfile = new TFile("/data_CMS/cms/ochando/CJLSTReducedTree/151202/DoubleEG2015D/ZZ4lAnalysis.root");
  //myfile = new TFile("/data_CMS/cms/ochando/CJLSTReducedTree/160111_ggZZincomplete/"+dataflag+"/ZZ4lAnalysis.root");
  TString ntuple = "root://lxcms03//data3/Higgs/160225/"+dataflag+"/ZZ4lAnalysis.root";
  cout << "Reading " << ntuple << "..." << endl;
  myfile = TFile::Open(ntuple);

  TString name_tree;
  //name_tree  = "CRZLTree/crTree";
  name_tree = "CRZLLTree/candTree";

  TTree * mytree = (TTree*)myfile->Get(name_tree);

  // ------------------------------------------------
  //  Load Branches
  // ------------------------------------------------
  Int_t           RunNumber;
  Long64_t        EventNumber;
  Int_t           LumiNumber;
  Short_t         Nvtx;
  Short_t         NObsInt;
  Float_t         NTrueInt;
  Float_t         PUWeight;
  Float_t         PFMET;
  Short_t         nCleanedJets;
  Short_t         nCleanedJetsPt30;
  Short_t         nCleanedJetsPt30BTagged;
  Short_t         nExtraLep;
  Short_t         nExtraZ;
  Short_t         trigWord;
  Float_t         ZZMass;
  Short_t         ZZsel;
  Float_t         ZZPt;
  Float_t         ZZEta;
  Float_t         ZZPhi;
  Int_t           CRflag;
  Float_t         Z1Mass;
  Float_t         Z1Pt;
  Short_t         Z1Flav;
  Float_t         Z2Mass;
  Float_t         Z2Pt;
  Short_t         Z2Flav;
  vector<float>   *LepPt;
  vector<float>   *LepEta;
  vector<float>   *LepPhi;
  vector<short>   *LepLepId;
  vector<float>   *LepSIP;
  vector<float>   *LepTime;
  vector<char>    *LepMissingHit;
  vector<bool>    *LepisID;
  vector<float>   *LepCombRelIsoPF;
  vector<float>   *JetPt;
  vector<float>   *JetEta;
  vector<float>   *JetPhi;
  vector<float>   *JetMass;
  vector<float>   *JetBTagger;
  vector<float>   *JetIsBtagged;
  vector<float>   *JetQGLikelihood;
  vector<float>   *JetSigma;
  Float_t         overallEventWeight;
  Float_t         xsec;
  Float_t         pwh_hadronic_VAJHU;
  Float_t         phj_VAJHU;
  Float_t         phjj_VAJHU_old;
  Float_t         pvbf_VAJHU_old;
  Float_t         pAux_vbf_VAJHU;
  Float_t         pzh_hadronic_VAJHU;

  TBranch        *b_RunNumber;   //!
  TBranch        *b_EventNumber;   //!
  TBranch        *b_LumiNumber;   //!
  TBranch        *b_NRecoMu;   //!
  TBranch        *b_NRecoEle;   //!
  TBranch        *b_Nvtx;   //!
  TBranch        *b_NObsInt;   //!
  TBranch        *b_NTrueInt;   //!
  TBranch        *b_PUWeight;   //!
  TBranch        *b_PFMET;   //!
  TBranch        *b_nCleanedJets;   //!
  TBranch        *b_nCleanedJetsPt30;   //!
  TBranch        *b_nCleanedJetsPt30BTagged;   //!
  TBranch        *b_nExtraLep;   //!
  TBranch        *b_nExtraZ;   //!
  TBranch        *b_trigWord;   //!
  TBranch        *b_ZZMass;   //!
  TBranch        *b_ZZMassErr;   //!
  TBranch        *b_ZZsel;   //!
  TBranch        *b_ZZPt;   //!
  TBranch        *b_ZZEta;   //!
  TBranch        *b_ZZPhi;   //!
  TBranch        *b_CRflag;   //!
  TBranch        *b_Z1Mass;   //!
  TBranch        *b_Z1Pt;   //!
  TBranch        *b_Z1Flav;   //!
  TBranch        *b_Z2Mass;   //!
  TBranch        *b_Z2Pt;   //!
  TBranch        *b_Z2Flav;   //!
  TBranch        *b_LepMissingHit;
  TBranch        *b_LepPt;   //!
  TBranch        *b_LepEta;   //!
  TBranch        *b_LepPhi;   //!
  TBranch        *b_LepLepId;   //!
  TBranch        *b_LepSIP;   //!
  TBranch        *b_LepTime;   //!
  TBranch        *b_LepCombRelIsoPF;   //!
  TBranch        *b_LepisID;   //!
  TBranch        *b_JetPt;   //!
  TBranch        *b_JetEta;   //!
  TBranch        *b_JetPhi;   //!
  TBranch        *b_JetMass;   //!
  TBranch        *b_JetBTagger;   //!
  TBranch        *b_JetIsBtagged;   //!
  TBranch        *b_JetQGLikelihood;   //!
  TBranch        *b_JetSigma;   //!
  TBranch        *b_overallEventWeight;   //!
  TBranch        *b_xsec;   //!
  TBranch        *b_pwh_hadronic_VAJHU; //categories
  TBranch        *b_phj_VAJHU;  //categories
  TBranch        *b_phjj_VAJHU_old;  //categories
  TBranch        *b_pvbf_VAJHU_old;  //categories
  TBranch        *b_pAux_vbf_VAJHU;  //categories
  TBranch        *b_pzh_hadronic_VAJHU;  //categories

  // Set object pointer
  LepPt = 0;
  LepEta = 0;
  LepPhi = 0;
  LepLepId = 0;
  LepSIP = 0;
  LepisID = 0;
  LepTime = 0;
  LepMissingHit = 0;
  LepCombRelIsoPF = 0;
  JetPt = 0;
  JetEta = 0;
  JetPhi = 0;
  JetMass = 0;
  JetBTagger = 0;
  JetIsBtagged = 0;
  JetQGLikelihood = 0;
  JetSigma = 0;
  
  mytree->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
  mytree->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
  mytree->SetBranchAddress("LumiNumber", &LumiNumber, &b_LumiNumber);
  mytree->SetBranchAddress("Nvtx", &Nvtx, &b_Nvtx);
  mytree->SetBranchAddress("NObsInt", &NObsInt, &b_NObsInt);
  mytree->SetBranchAddress("NTrueInt", &NTrueInt, &b_NTrueInt);
  mytree->SetBranchAddress("PUWeight", &PUWeight, &b_PUWeight);
  mytree->SetBranchAddress("PFMET", &PFMET, &b_PFMET);
  mytree->SetBranchAddress("nCleanedJets", &nCleanedJets, &b_nCleanedJets);
  mytree->SetBranchAddress("nCleanedJetsPt30", &nCleanedJetsPt30, &b_nCleanedJetsPt30);
  mytree->SetBranchAddress("nCleanedJetsPt30BTagged", &nCleanedJetsPt30BTagged, &b_nCleanedJetsPt30BTagged);
  mytree->SetBranchAddress("nExtraLep", &nExtraLep, &b_nExtraLep);
  mytree->SetBranchAddress("nExtraZ", &nExtraZ, &b_nExtraZ);
  mytree->SetBranchAddress("trigWord", &trigWord, &b_trigWord);
  mytree->SetBranchAddress("ZZMass", &ZZMass, &b_ZZMass);
  mytree->SetBranchAddress("ZZsel", &ZZsel, &b_ZZsel);
  mytree->SetBranchAddress("ZZPt", &ZZPt, &b_ZZPt);
  mytree->SetBranchAddress("ZZEta", &ZZEta, &b_ZZEta);
  mytree->SetBranchAddress("ZZPhi", &ZZPhi, &b_ZZPhi);
  mytree->SetBranchAddress("CRflag", &CRflag, &b_CRflag);
  mytree->SetBranchAddress("Z1Mass", &Z1Mass, &b_Z1Mass);
  mytree->SetBranchAddress("Z1Pt", &Z1Pt, &b_Z1Pt);
  mytree->SetBranchAddress("Z1Flav", &Z1Flav, &b_Z1Flav);
  mytree->SetBranchAddress("Z2Mass", &Z2Mass, &b_Z2Mass);
  mytree->SetBranchAddress("Z2Pt", &Z2Pt, &b_Z2Pt);
  mytree->SetBranchAddress("Z2Flav", &Z2Flav, &b_Z2Flav);
  mytree->SetBranchAddress("LepPt", &LepPt, &b_LepPt);
  mytree->SetBranchAddress("LepEta", &LepEta, &b_LepEta);
  mytree->SetBranchAddress("LepPhi", &LepPhi, &b_LepPhi);
  mytree->SetBranchAddress("LepLepId", &LepLepId, &b_LepLepId);
  mytree->SetBranchAddress("LepisID", &LepisID, &b_LepisID);
  mytree->SetBranchAddress("LepSIP", &LepSIP, &b_LepSIP);
  mytree->SetBranchAddress("LepTime", &LepTime, &b_LepTime);
  mytree->SetBranchAddress("LepMissingHit", &LepMissingHit, &b_LepMissingHit);
  mytree->SetBranchAddress("LepCombRelIsoPF", &LepCombRelIsoPF, &b_LepCombRelIsoPF);
  mytree->SetBranchAddress("JetPt", &JetPt, &b_JetPt);
  mytree->SetBranchAddress("JetEta", &JetEta, &b_JetEta);
  mytree->SetBranchAddress("JetPhi", &JetPhi, &b_JetPhi);
  mytree->SetBranchAddress("JetMass", &JetMass, &b_JetMass);
  mytree->SetBranchAddress("JetBTagger", &JetBTagger, &b_JetBTagger);
  mytree->SetBranchAddress("JetIsBtagged", &JetIsBtagged, &b_JetIsBtagged);
  mytree->SetBranchAddress("JetQGLikelihood", &JetQGLikelihood, &b_JetQGLikelihood);
  mytree->SetBranchAddress("JetSigma", &JetSigma, &b_JetSigma);
  mytree->SetBranchAddress("overallEventWeight", &overallEventWeight, &b_overallEventWeight);
  mytree->SetBranchAddress("xsec", &xsec, &b_xsec);
  mytree->SetBranchAddress("pwh_hadronic_VAJHU", &pwh_hadronic_VAJHU, &b_pwh_hadronic_VAJHU);
  mytree->SetBranchAddress("phj_VAJHU", &phj_VAJHU, &b_phj_VAJHU);
  mytree->SetBranchAddress("phjj_VAJHU_old", &phjj_VAJHU_old, &b_phjj_VAJHU_old);
  mytree->SetBranchAddress("pvbf_VAJHU_old", &pvbf_VAJHU_old, &b_pvbf_VAJHU_old);
  mytree->SetBranchAddress("pAux_vbf_VAJHU", &pAux_vbf_VAJHU, &b_pAux_vbf_VAJHU);
  mytree->SetBranchAddress("pzh_hadronic_VAJHU", &pzh_hadronic_VAJHU, &b_pzh_hadronic_VAJHU);

  // ===============================================================
  //   Definition of some Histos
  // ===============================================================
  TH1F::SetDefaultSumw2(kTRUE);
  
  TH1F* ICUT 			= new TH1F("ICUT","ICUT",50,0.,50.);  
  
  TH1F* h_ZZ_Mass = new TH1F("ZZmass","ZZmass",1000, 0, 1000);
  TH1F* h_ZZ_MassW = new TH1F("ZZmassW","ZZmassW",1000, 0, 1000);
  TH1F* h_Z1_Mass = new TH1F("Z1mass","Z1mass",200, 0, 200);
  TH1F* h_Z2_Mass = new TH1F("Z2mass","Z2mass",200, 0, 200);
  
  // --------------------------
  // Histos for pT, mhits
  // --------------------------
  Float_t xbins[8] = {5,7,10,20,30,40,50,80};
  TString loc[3] = {"all","EB","EE"};

  TH1F* h_Lep3_pT[3];
  TH1F* h_Lep4_pT[3];
  TH1F* h_Lep34_pT[3];
  TH1F* h_Lep34_inclmhits[3];

  TH1F* h_Lep3_mhits[3][8];
  TH1F* h_Lep4_mhits[3][8];
  TH1F* h_Lep34_mhits[3][8];
 
  for(int iloc=0;iloc<3;iloc++) {
    h_Lep3_pT[iloc] = new TH1F("Lep3_pT_"+loc[iloc],  "Lep3_pT_"+loc[iloc]+";Lepon 3 pT;# events",7, xbins);    
    h_Lep4_pT[iloc] = new TH1F("Lep4_pT_"+loc[iloc],  "Lep4_pT_"+loc[iloc]+";Lepon 4 pT;# events",7, xbins);    
    h_Lep34_pT[iloc] = new TH1F("Lep34_pT_"+loc[iloc],  "Lep34_pT_"+loc[iloc]+";Lepon 34 pT;# events",7, xbins);    
    h_Lep34_inclmhits[iloc] = new TH1F("Lep34_inclmhits_"+loc[iloc], "Lep34_inclmhits_"+loc[iloc], 5, 0, 5);

    for(int ipt=0;ipt<7;ipt++) {
      //char pTbin1[500]; sprintf(pTbin1,"d",xbins[ipt]);
      TString pTbin1 = Form("%.0f",xbins[ipt]);
      TString pTbin2 = Form("%.0f",xbins[ipt+1]);
      
      h_Lep3_mhits[iloc][ipt] = new TH1F("Lep3_mhits_"+loc[iloc]+"_pT"+pTbin1+pTbin2, "Lep3_mhits_"+loc[iloc]+"_pT"+pTbin1+pTbin2, 5, 0, 5);
      h_Lep4_mhits[iloc][ipt] = new TH1F("Lep4_mhits_"+loc[iloc]+"_pT"+pTbin1+pTbin2, "Lep4_mhits_"+loc[iloc]+"_pT"+pTbin1+pTbin2, 5, 0, 5);
      h_Lep34_mhits[iloc][ipt] = new TH1F("Lep34_mhits_"+loc[iloc]+"_pT"+pTbin1+pTbin2, "Lep34_mhits_"+loc[iloc]+"_pT"+pTbin1+pTbin2, 5, 0, 5);
      //cout <<"pt = " << pTbin1 << " " << pTbin2 << endl;
    } // for loop on pT
  } // for loop in iloc
 
  // ===============================================================
  //   Definition of some variables
  // ===============================================================
  Int_t MAX = mytree->GetEntries();
  //Int_t MAX      = 100;
  
  Int_t icut_MAX = 0;
  int nselected = 0;
  
  double expectedNumberOfEvents = 0 ;
  double NumberOfEvents         = 0 ;
  TString cutdes[40];
  float pi = acos(-1.);
  
  double expected_zx = 0;

  float WEIGHT = 1;
  int currentFinalState;
  enum FinalState {fs4mu=0, fs4e=1, fs2e2mu=2, fs2mu2e=3};

  // For weights
  Double_t gen_sumWeights; //[nDatasets];
  Float_t partialSampleWeight = 0.0; //[nDatasets];
  TH1F* hCounters = (TH1F*)myfile->Get("ZZTree/Counters");

  if(isMC) {
    gen_sumWeights = (Long64_t)hCounters->GetBinContent(40);
    partialSampleWeight = lumi * 1000 / gen_sumWeights ;
  } // if isMC

  // --------------------------------------------
  //              Loop on the data 
  // --------------------------------------------
  
  cout << "---> Start the loop on... " << MAX << " events over "<< mytree->GetEntries() << " events." << endl;
  
  //bool loop=true;
  
  //for (Int_t iEvt = 0; iEvt < mytree->GetEntries() ; ++iEvt) {
  for (Int_t iEvt = 0; iEvt < MAX ; ++iEvt) {
    //cout << "i   = " << iEvt << endl;
    //mytree->LoadTree(iEvt);
    float_t percent = iEvt * 100 / MAX; 
    if (iEvt % 10000 == 0 && iEvt > 0) cout<< "Loop: processing event  " << iEvt << " (" << percent << "%)" << endl;    
    
    mytree->GetEntry(iEvt);
    
    // -----------------------------
    // Compute Weight
    // -----------------------------
    double kfactor = 1.;
    // 1.1 for qqZZ
    if(isMC) {
      Double_t eventWeight = partialSampleWeight* xsec * kfactor * overallEventWeight ;
      WEIGHT = eventWeight;
    } // if isMC

    // ===========================================
    // Selection
    // ===========================================
     
    Int_t icut = 0;
    int index = 0;
    //if ( _debug ) {cout<<"-------> Beginning preselection cuts"<<endl;}
    cutdes[icut] = "No cut"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    //cout << "CRflag = " << CRflag << endl;
    if(CRflag==0) continue; cutdes[icut] = "Pass CRflag"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    
    int CRfinalstate=0; 
    CRfinalstate = CRZLLss;
    if(!test_bit(CRflag, CRfinalstate)) continue;  cutdes[icut] = "Pass Bit"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    //CRZLLss == merged AA ss CRs in FinalStates.h
    
    //----- find final state 
    bool pass_flavor = false;
    double OSSS = 1.;
    //Float_t fsROSSS[nFinalStates] = { 1.22, 0.97, 1.30, 0.98 }; 
    if(FS=="4e" && (Z1Flav==-121 && Z2Flav==+121)) { pass_flavor = true; OSSS = 0.97; }
    if(FS=="4mu" && (Z1Flav==-169 && Z2Flav==+169)) { pass_flavor = true; OSSS = 1.22; }
    if(FS=="2mu2e" && (Z1Flav==-169 && Z2Flav==+121)) { pass_flavor = true; OSSS = 0.98;}
    if(FS=="2e2mu" && (Z1Flav==-121 && Z2Flav==+169)) { pass_flavor = true; OSSS = 1.3; }
      // 2e2m = -121 +169
      // 2mu2e = -169 +121
      // 4mu = -169 +169
    //cout << "FS = " << FS << " Z1 = " << Z1Flav << " Z2 = " << Z2Flav << " pass = " << pass_flavor << endl;

    if(pass_flavor==false) continue; cutdes[icut] = "Pass Final State"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 


    // ===========================================
    // Categories
    // ===========================================

    //QGLikelihood vector first has to be converted to a C++ array
    //cout << "nCleanedJetsPt30 = " <<  nCleanedJetsPt30 << endl;
    //cout << "JetQGLikelihood->size() = " <<  JetQGLikelihood->size() << endl;
    //cout << "JetPt->size() = " <<  JetPt->size() << endl;
    //cout << "JetEta->size() = " <<  JetEta->size() << endl;
    //cout << "JetPhi->size() = " <<  JetPhi->size() << endl;

    Float_t jetQGL[nCleanedJetsPt30];
    for(int j=0; j<nCleanedJetsPt30; j++)
	{
	//cout << "j = " << j << endl;
	jetQGL[j] = JetQGLikelihood->at(j);
	}


    int cate = -1;
    //cout << "here - " <<  cate << endl;
    cate = categoryIchep16(nExtraLep, nExtraZ, nCleanedJetsPt30, nCleanedJetsPt30BTagged, jetQGL, phjj_VAJHU_old, phj_VAJHU, pvbf_VAJHU_old, pAux_vbf_VAJHU, pwh_hadronic_VAJHU, pzh_hadronic_VAJHU);


    bool passcat = false;

    if(cat == "ALL")
	{
	if (cate > -1) passcat = true;
	if(passcat == false) continue;
	cutdes[icut] = "All categories";
	ICUT->Fill((Float_t)icut,WEIGHT);
	icut++;  
	}

    if(cat == "VBF-2j")
	{
	if (cate == 2) passcat = true;
	if(passcat == false) continue;
	cutdes[icut] = "VBF-2j category";
	ICUT->Fill((Float_t)icut,WEIGHT);
	icut++;  
	}

    if(cat == "VH-hadronic")
	{
	if (cate == 4) passcat = true;
	if(passcat == false) continue;
	cutdes[icut] = "VH-hadronic category";
	ICUT->Fill((Float_t)icut,WEIGHT);
	icut++;  
	}

    if(cat == "VH-leptonic")
	{
	if (cate == 3) passcat = true;
	if(passcat == false) continue;
	cutdes[icut] = "VH-leptonic category";
	ICUT->Fill((Float_t)icut,WEIGHT);
	icut++;  
	}

    if(cat == "ttH")
	{
	if (cate == 5) passcat = true;
	if(passcat == false) continue;
	cutdes[icut] = "ttH category";
	ICUT->Fill((Float_t)icut,WEIGHT);
	icut++;  
	}

    if(cat == "VBF-1j")
	{
	if (cate == 1) passcat = true;
	if(passcat == false) continue;
	cutdes[icut] = "VBF-1j category";
	ICUT->Fill((Float_t)icut,WEIGHT);
	icut++;  
	}

    if(cat == "untagged")
	{
	if (cate == 0) passcat = true;
	if(passcat == false) continue;
	cutdes[icut] = "untagged category";
	ICUT->Fill((Float_t)icut,WEIGHT);
	icut++;  
	}



    // ===========================================
    // Analysis
    // ===========================================
    if(LepSIP->at(2)>=4) continue; cutdes[icut] = "|SIP(3rd lepton)|<4"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    if(LepSIP->at(3)>=4) continue; cutdes[icut] = "|SIP(4st lepton)|<4"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 

    h_ZZ_Mass->Fill(ZZMass, WEIGHT);
    h_Z1_Mass->Fill(Z1Mass, WEIGHT);
    h_Z2_Mass->Fill(Z2Mass, WEIGHT);

    double eta_cut = 0;
    if(FS=="4e" || FS=="2mu2e") eta_cut = 1.479; 
    if(FS=="4mu" || FS=="2e2mu") eta_cut = 1.2; 
     
    // TH1F* h_Lep3_mhits[3][8];
    // TH1F* h_Lep4_mhits[3][8];
    // TH1F* h_Lep34_mhits[3][8];

    // ===========================================
    // Reducible Background Computation
    // ===========================================
    if(EXTRA.Contains("M70")>0) {
      if(ZZMass <=70) continue; cutdes[icut] = "MZZ>70 GeV"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    }
    else {
      if(ZZMass <=100) continue; cutdes[icut] = "MZZ>100 GeV"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    }
    //cout << 
  
    h_Lep3_pT[0]->Fill(LepPt->at(2), WEIGHT);
    h_Lep4_pT[0]->Fill(LepPt->at(3), WEIGHT);
    
    if( fabs(LepEta->at(2))< eta_cut )   h_Lep3_pT[1]->Fill(LepPt->at(2), WEIGHT);
    else h_Lep3_pT[2]->Fill(LepPt->at(2), WEIGHT);
    
    if( fabs(LepEta->at(3))< eta_cut )   h_Lep4_pT[1]->Fill(LepPt->at(3), WEIGHT);
    else h_Lep4_pT[2]->Fill(LepPt->at(3), WEIGHT);
    
    // -----------------
    // Missings Hits
    // -----------------
    for(int ii=0;ii<2;ii++) {
      //Float_t xbins[8] = {5,7,10,20,30,40,50,80};
      h_Lep34_inclmhits[0]->Fill(LepMissingHit->at(ii+2), WEIGHT); 

      if( fabs(LepEta->at(ii+2))< eta_cut) {
	h_Lep34_inclmhits[1]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	if(LepPt->at(ii+2)>5 && LepPt->at(ii+2)<=7) h_Lep34_mhits[1][0]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>7 && LepPt->at(ii+2)<=10) h_Lep34_mhits[1][1]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>10 && LepPt->at(ii+2)<=20) h_Lep34_mhits[1][2]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>20 && LepPt->at(ii+2)<=30) h_Lep34_mhits[1][3]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>30 && LepPt->at(ii+2)<=40) h_Lep34_mhits[1][4]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>40 && LepPt->at(ii+2)<=50) h_Lep34_mhits[1][5]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>50 && LepPt->at(ii+2)<=80) h_Lep34_mhits[1][6]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
      } // if BARREL
      else {
	h_Lep34_inclmhits[2]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	if(LepPt->at(ii+2)>5 && LepPt->at(ii+2)<=7) h_Lep34_mhits[2][0]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>7 && LepPt->at(ii+2)<=10) h_Lep34_mhits[2][1]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>10 && LepPt->at(ii+2)<=20) h_Lep34_mhits[2][2]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>20 && LepPt->at(ii+2)<=30) h_Lep34_mhits[2][3]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>30 && LepPt->at(ii+2)<=40) h_Lep34_mhits[2][4]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>40 && LepPt->at(ii+2)<=50) h_Lep34_mhits[2][5]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
	else if(LepPt->at(ii+2)>50 && LepPt->at(ii+2)<=80) h_Lep34_mhits[2][6]->Fill(LepMissingHit->at(ii+2), WEIGHT); 
      } // else ENDCAP
    } // for loop on lepton 3 & 4



 
    //OSSS*
    double fakes[2];
    
    for(int i=0;i<2;i++) {
      Float_t myLepPt = LepPt->at(2+i) >=80. ? 79. : LepPt->at(2+i);
      Int_t   myLepID = abs(LepLepId->at(2+i));
      int bin = findBin(myLepPt, myLepID); //double LepPt, double LepId) {
      if(EXTRA.Contains("incl")>0) bin = 0;
      //cout << "pt = " <<  LepPt->at(2+i) << " eta = " << LepEta->at(2+i)  << " id =" << myLepID << " bin = " << bin << endl;
      //cout << "fakeEB = " << fakeele_EB[bin] << " EE = " << fakeele_EE[bin] << endl;
      
      if(fabs(LepEta->at(2+i)) < eta_cut) {
	if(myLepID==11) fakes[i] = fakeele_EB[bin];
	if(myLepID==13) fakes[i] = fakemu_EB[bin];
      } // Barrel
      else {
	if(myLepID==11) fakes[i] = fakeele_EE[bin];
	if(myLepID==13) fakes[i] = fakemu_EE[bin];
      } // else endcap
      
      //cout << "fake = " << fakes[i] << endl;
    } // for loop on leptons
      
    double temp_zx = OSSS * fakes[0]*fakes[1];
    
    expected_zx += temp_zx;

    h_ZZ_MassW->Fill(ZZMass, temp_zx);

    // ===========================================
    // Full cuts
    // ===========================================
    bool isID = false;
    bool isISO = false;
    if(LepisID->at(2)==1 && LepisID->at(3)==1) isID = true;
    if(LepCombRelIsoPF->at(2) < 0.35 && LepCombRelIsoPF->at(3) < 0.35) isISO = true;
    
    if(isID==false) continue; cutdes[icut] = " Pass ID"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    if(isISO==false) continue; cutdes[icut] = "Pass ISO"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
   
    
     
     icut_MAX = icut;
     nselected++;
  } // END of the loop

  cout << "icut_max = " << icut_MAX << endl;
  //if(icut_MAX<2) icut_MAX = 30;
  cout << "======================================================================" << endl;
  for ( Int_t i=0; i<10 ; i++ )
    cout << "Cut " << setw(3) << i << " : " << setw(30) << cutdes[i] << " : " << ICUT->GetBinContent(i+1) << endl;
  //cout << "Cut " << i << " : " << ICUT->GetBinContent(i) << endl;
  cout << "======================================================================" << endl;
  cout << "Total Number of events selected = "  << nselected                       << endl;
  cout << "Total Number of Reducible Back = "  << expected_zx                   << endl;
  //cout << "Total Number of events written  = "  << nwrite                          << endl;
  cout << "======================================================================" << endl;

  // ===============================================================
  //   Output File
  // ===============================================================
  OutputFile->cd();
  h_ZZ_Mass->Write();
  h_ZZ_MassW->Write();
  h_Z1_Mass->Write();
  h_Z2_Mass->Write();
  
  for(int iloc=0;iloc<3;iloc++) {
    h_Lep3_pT[iloc]->Write();
    h_Lep4_pT[iloc]->Write();
    h_Lep34_inclmhits[iloc]->Write();

	for(int ipt=0;ipt<7;ipt++) {
	  h_Lep34_mhits[iloc][ipt]->Write();
	}
  } // for loop in iloc

  

  

  
  OutputFile->Write();
  OutputFile->Close();
  
  cout << "---> OutPut File: "  << outputfile_name << endl;

}
