//Created by Christophe Orchando
//Modified by Pedro Cipriano


// C/C++ include
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <TTree.h>
#include <TH1.h>
#include <TFile.h>
#include <TLorentzVector.h>

#include "ZZAnalysis/AnalysisStep/interface/FinalStates.h"
//#include "/home/llr/cms/ochando/CJLST/CMSSW_7416p1_ZX/src/ZZAnalysis/AnalysisStep/interface/bitops.h"

using namespace std;

bool test_bit( int mask, unsigned int iBit ) {
  return (mask >> iBit) & 1; 
}

// ========================================================================================================================
void loopFake(TString FS = "Ze", TString dataset = "ALL", TString branch = "CRZL", TString EXTRA="80XA")
// ========================================================================================================================
{
  cout << "---> Working with Final State:       " << FS << endl;
  cout << "---> Working with Dataset:           " << dataset << endl;
  cout << "---> Working with Branch:            " << branch << endl;
  cout << "---> Working with Extra definitions: " << EXTRA << endl;

  if( (FS!="Ze") && (FS!="Zmu"))
    { cout << " ERROR ! FinalState should be Ze, Zmu" << endl; return; }

  float lumi = 0.0;
  TString path = "";


  if(EXTRA.Contains("76X")>0)
	{ 
	lumi = 2.6;
	path = "160613_76X";
	}

  if(EXTRA.Contains("80XA")>0)
	{ 
	lumi = 2.6;
	path = "160624";
	}

  if(EXTRA.Contains("80XB")>0)
	{ 
	lumi = 6.0;
	path = "160624";
	}

  if (lumi == 0.0 or path == "")
	{ cout << "Data taking era not valid!" << endl; return; }

  cout << "---> Working with : " << lumi << " fb-1"  << endl;
  
  //gROOT->ProcessLine(".L /home/llr/cms/ochando/CJLST/CMSSW_7416p1_ZX/src/ZZAnalysis/AnalysisStep/interface/FinalStates.h");
  //gROOT->ProcessLine(".L /home/llr/cms/ochando/CJLST/CMSSW_7416p1_ZX/src/ZZAnalysis/AnalysisStep/src/bitops.cc");

  // ------------------------------------------------
  // Dataset
  // ------------------------------------------------
  bool isMC=true;

  TString dataflag = "";
  if( dataset=="DY50" )      dataflag = "DYJetsToLL_M50";
  else if( dataset=="TT" )   dataflag = "TTJets"; //"TTTo2L2nu";
  else if( dataset=="WZ" )  dataflag = "WZTo3LNu";
  else if( dataset=="ZZ" )   dataflag =  "ZZTo4l";
  else if( dataset=="ALL")   { dataflag= "AllData"; isMC=false; }
  else  { cout << " ERROR ! dataset should be DY50, TT, WZ, ZZ, ALL" << endl; return; }
  
  // ------------------------------------------------
  // OutPut File
  // ------------------------------------------------
  TString outputfile_name = "histograms/FR/" + FS + "/FR_"+branch+"_"+dataset+"_"+EXTRA+".root";
  TFile * OutputFile;
  OutputFile = new TFile(outputfile_name, "RECREATE"); //, "", 5);
  cout << "Outputing the result to " << outputfile_name << "..." << endl;

  // ------------------------------------------------
  // load the tree 
  // ------------------------------------------------
  TFile *myfile;
  //myfile = TFile::Open("root://lxcms03//data3/Higgs/160225/ggH125/ZZ4lAnalysis.root");
  //cout << "Opening file!" << endl;
  TString ntuple = "root://lxcms03//data3/Higgs/"+path+"/"+dataflag+"/ZZ4lAnalysis.root";
  cout << "Reading " << ntuple << "..." << endl;
  myfile = TFile::Open(ntuple);

  //cout << "Loading Trees!" << endl;
  TString name_tree;
  name_tree  = branch+"Tree/candTree";

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
  Float_t         PFMETNoHF;
  Short_t         nCleanedJets;
  Short_t         nCleanedJetsPt30;
  Short_t         nCleanedJetsPt30BTagged;
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
  Short_t         nExtraLep;
  Short_t	  nExtraZ;
  vector<float>   *LepPt;
  vector<float>   *LepEta;
  vector<float>   *LepPhi;
  vector<short>   *LepLepId;
  vector<bool>    *LepisID;
  vector<float>   *LepSIP;
  vector<float>   *LepTime;
  vector<char>    *LepMissingHit;
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
  TBranch        *b_PFMETNoHF;
  TBranch        *b_nCleanedJets;   //!
  TBranch        *b_nCleanedJetsPt30;   //!
  TBranch        *b_nCleanedJetsPt30BTagged;   //!
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
  TBranch        *b_nExtraLep;   //!
  TBranch        *b_nExtraZ;  //categories
  TBranch        *b_LepPt;   //!
  TBranch        *b_LepEta;   //!
  TBranch        *b_LepPhi;   //!
  TBranch        *b_LepLepId;   //!
  TBranch        *b_LepMissingHit;
  TBranch        *b_LepSIP;   //!
  TBranch        *b_LepisID;   //!
  TBranch        *b_LepTime;   //!
  TBranch        *b_LepCombRelIsoPF;   //!
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
  mytree->SetBranchAddress("PFMETNoHF", &PFMETNoHF, &b_PFMETNoHF);
  mytree->SetBranchAddress("nCleanedJets", &nCleanedJets, &b_nCleanedJets);
  mytree->SetBranchAddress("nCleanedJetsPt30", &nCleanedJetsPt30, &b_nCleanedJetsPt30);
  mytree->SetBranchAddress("nCleanedJetsPt30BTagged", &nCleanedJetsPt30BTagged, &b_nCleanedJetsPt30BTagged);
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
  mytree->SetBranchAddress("nExtraLep", &nExtraLep, &b_nExtraLep);
  mytree->SetBranchAddress("nExtraZ", &nExtraZ, &b_nExtraZ);
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
  
  //TH1F* h_ZZ_Mass = new TH1F("ZZmass","ZZmass",1000, 0, 1000);
  //TH1F* h_Z1_Mass = new TH1F("Z1mass","Z1mass",200, 0, 200);
  //TH1F* h_Z2_Mass = new TH1F("Z2mass","Z2mass",200, 0, 200);
 
  TH1F* h_Lep1_pT   = new TH1F("Lep1_pT","Lep1_pT",200, 0, 200); TH1F* h_Lep2_pT   = new TH1F("Lep2_pT","Lep2_pT",200, 0, 200);
  TH1F* h_Lep1_eta = new TH1F("Lep1_eta","Lep1_eta",600, -3, 3);    TH1F* h_Lep2_eta = new TH1F("Lep2_eta","Lep2_eta",600, -3, 3);
  TH1F* h_Lep1_iso  = new TH1F("Lep1_iso","Lep1_iso",500, 0, 5);      TH1F* h_Lep2_iso  = new TH1F("Lep2_iso","Lep2_iso",500, 0, 5);
  TH1F* h_Lep1_SIP = new TH1F("Lep1_SIP","Lep1_SIP",500, 0, 10); TH1F* h_Lep2_SIP = new TH1F("Lep2_SIP","Lep2_SIP",500, 0, 10);

  //TH1F* PFMET = new TH1F("PFMET","PFMET",200,0,200); 

  // ----------------------
  //   Histo for Lep3
  // ----------------------
  Float_t xbins[8] = {5,7,10,20,30,40,50,80};
  
  TH1F* h_Lep3_Eta[3][3][10]; 
  TH1F* h_Lep3_pT[3][3][10];
  TH1F* h_Lep3_Iso[3][3][10];
  TH1F* h_Lep3_SIP[3][3][10];
  TH1F* h_Lep3_isID[3][3][10];
  
  TH1F* h_Lep3_mhits[3][8];
  TH1F* h_Lep3_inclmhits[3];

  TString flavor[3] = {"all","ee","mumu"};
  TString loc[3] = {"all","EB","EE"};
  TString histo_name[4] = {
    "beforeSIP",
    "afterSIP",
    "afterMET",
    "afterIDISO"
  }; //

  for(int iflavor=0;iflavor<3;iflavor++) {
    for(int iloc=0;iloc<3;iloc++) {
      for(int iname=0;iname<4;iname++) {
	if(EXTRA.Contains("incl")>0) 
	  h_Lep3_pT[iflavor][iloc][iname] = new TH1F("Lep3_pT_"+flavor[iflavor]+"_"+loc[iloc]+"_"+histo_name[iname], "Lep3_pT_"+flavor[iflavor]+"_"+loc[iloc]+"_"+histo_name[iname]+";Lepon 3 pT;# events",1, 0,80);
	else 
	  h_Lep3_pT[iflavor][iloc][iname] = new TH1F("Lep3_pT_"+flavor[iflavor]+"_"+loc[iloc]+"_"+histo_name[iname], "Lep3_pT_"+flavor[iflavor]+"_"+loc[iloc]+"_"+histo_name[iname]+";Lepon 3 pT;# events",7, xbins);
						   //200, 0, 200);
	h_Lep3_isID[iflavor][iloc][iname] = new TH1F("Lep3_isID_"+flavor[iflavor]+"_"+loc[iloc]+"_"+histo_name[iname], "Lep3_isID_"+flavor[iflavor]+"_"+loc[iloc]+"_"+histo_name[iname]+";Lepon 3 isID;# events",2, 0, 2);
      } // for loop on iname
    } // for loop in iloc
  } // for loop on flavor
  
  for(int iloc=0;iloc<3;iloc++) {
    h_Lep3_inclmhits[iloc] = new TH1F("Lep3_inclmhits_"+loc[iloc], "Lep3_inclmhits_"+loc[iloc], 5, 0, 5);
    
    for(int ipt=0;ipt<7;ipt++) {
      //char pTbin1[500]; sprintf(pTbin1,"d",xbins[ipt]);
      TString pTbin1 = Form("%.0f",xbins[ipt]);
      TString pTbin2 = Form("%.0f",xbins[ipt+1]);
			   
      h_Lep3_mhits[iloc][ipt] = new TH1F("Lep3_mhits_"+loc[iloc]+"_pT"+pTbin1+pTbin2, "Lep3_mhits_"+loc[iloc]+"_pT"+pTbin1+pTbin2, 5, 0, 5);
      //cout <<"pt = " << pTbin1 << " " << pTbin2 << endl;
    } // for loop on pT
  } // for loop on location

  // ----------------------
  //    Other Histos
  // ----------------------
  TH1F* h_PFMET[10];
  TH1F* h_Z1_Mass[10];
  TH1F* h_Z1_MassEE[10];
  TH1F* h_Z1_MassMM[10];
  
  for(int iname=0;iname<4;iname++) {
    h_PFMET[iname] = new TH1F("PFMET_"+histo_name[iname], "PFMET_"+histo_name[iname]+";PFMET;# events",200, 0, 200);
    h_Z1_Mass[iname] = new TH1F("Z1Mass_"+histo_name[iname], "Z1Mass_"+histo_name[iname]+";Z1Mass;# events",200, 0, 200);
    h_Z1_MassEE[iname] = new TH1F("Z1MassEE_"+histo_name[iname], "Z1MassEE_"+histo_name[iname]+";Z1Mass(e,e);# events",200, 0, 200);
    h_Z1_MassMM[iname] = new TH1F("Z1MassMM_"+histo_name[iname], "Z1MassMM_"+histo_name[iname]+";Z1Mass(mu,mu);# events",200, 0, 200);
  } // for loop on cuts/names
  
  
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
     
	if (!isMC)
	{
	if (RunNumber > 274443) { continue; }
	else { cutdes[icut] = "Runs between 271036-274443"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; }
	}

    //if ( _debug ) {cout<<"-------> Beginning preselection cuts"<<endl;}
    // cutdes[icut] = "No cut"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    // //cout << "CRflag = " << CRflag << endl;
    // if(CRflag==0) continue; cutdes[icut] = "Pass CRflag"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    //cout << "size = " << LepLepId->size() << endl;
    if(LepLepId->size()<3)  continue; cutdes[icut] = "At least 3 leptons (safety)"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
 
    // int CRfinalstate=0; 
    // CRfinalstate = CRZLLss;
    // if(!test_bit(CRflag, CRfinalstate)) continue;  cutdes[icut] = "Pass Bit"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    // //CRZLLss == merged AA ss CRs in FinalStates.h
    
    //----- find final state 
    bool pass_flavor = false;
    double eta_cut = 0;
    // if(FS=="4e" && (Z1Flav==-121 && Z2Flav==+121)) pass_flavor = true;
    //    if(FS=="4mu" && (Z1Flav==-169 && Z2Flav==+169)) pass_flavor = true;
    if(FS=="Ze"    && fabs(LepLepId->at(2)) == 11) { pass_flavor = true; eta_cut = 1.479; }
    if(FS=="Zmu" && fabs(LepLepId->at(2)) == 13) { pass_flavor = true; eta_cut = 1.2; }
    
    //  bool pass_flavor = false;
    // if(trig == "ee" && (Z1Flav==-121 && (LepLepId->at(2) ==+11 || LepLepId->at(2) == -11))) pass_flavor = true;
    // if(trig == "em" && (Z1Flav==-121 && (LepLepId->at(2) ==+13 || LepLepId->at(2) == -13))) pass_flavor = true;
    // if(trig == "me" && (Z1Flav==-169 && (LepLepId->at(2) ==+11 || LepLepId->at(2) == -11))) pass_flavor = true;
    // if(trig == "mm" && (Z1Flav==-169 && (LepLepId->at(2) ==+13 || LepLepId->at(2) == -13))) pass_flavor = true;
    // 2e2m = -121 +169
    // 2mu2e = -169 +121
    // 4mu = -169 +169
    //cout << "FS = " << FS << " Z1 = " << Z1Flav << " Z2 = " << Z2Flav << " pass = " << pass_flavor << endl;

    if(pass_flavor==false) continue; cutdes[icut] = "Pass 3rd lepton flavor"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 

    // ===========================================
    // PT cuts
    // ===========================================
    bool passpT = false;
    if( (LepPt->at(0) > 20 && LepPt->at(1) > 10) || (LepPt->at(0) > 10 && LepPt->at(1) > 20) ) passpT = true;

    if(passpT==false) continue; cutdes[icut] = "20/10"; ICUT->Fill((Float_t)icut,WEIGHT); icut++;  



    // ===========================================
    // MZ cuts
    // ===========================================
    TLorentzVector Leptons[3]; 
    for (int i=0;i<3;i++) {
      double px=LepPt->at(i)*TMath::Cos(LepPhi->at(i));
      double py=LepPt->at(i)*TMath::Sin(LepPhi->at(i));
      double pz=LepPt->at(i)*TMath::SinH(LepEta->at(i));
      double E = sqrt(px*px + py*py +pz*pz); // p>>m approx
      Leptons[i].SetPxPyPzE(px, py, pz, E);
    } // for loop on leptons
    
    TLorentzVector myZ = Leptons[0] + Leptons[1];
    TLorentzVector m3l = Leptons[0] + Leptons[1] + Leptons[2];
    //cout << "myZ = " << myZ.M() << " " << Z1Mass << endl;

    bool passMZ = false;
    if(EXTRA.Contains("MZ10")>0) { 
      if( fabs(Z1Mass - 91.2) < 10) passMZ = true;
      if(passMZ==false) continue; cutdes[icut] = "|MZ-91.2|<10"; ICUT->Fill((Float_t)icut,WEIGHT); icut++;  
    }
    
    if(EXTRA.Contains("MZ7")>0) { 
      if( fabs(Z1Mass - 91.2) < 7) passMZ = true;
      if(passMZ==false) continue; cutdes[icut] = "|MZ-91.2|<7"; ICUT->Fill((Float_t)icut,WEIGHT); icut++;  
    }

    if(EXTRA.Contains("MZ60")>0) { 
      if(Z1Mass > 60 && Z1Mass < 120) passMZ = true;
      if(passMZ==false) continue; cutdes[icut] = "60<MZ<120"; ICUT->Fill((Float_t)icut,WEIGHT); icut++;  
    }
    
    if(EXTRA.Contains("M3L5")>0) { 
      if( fabs(m3l.M() - 91.2) < 5)  passMZ = true;
      if(passMZ==false) continue; cutdes[icut] = "|M3l-91.2|<5"; ICUT->Fill((Float_t)icut,WEIGHT); icut++;  
    } 


    // ===========================================
    // Analysis
    // ===========================================
    //cout << "iso0 = " << LepCombRelIsoPF->at(0) << " iso1 = " << LepCombRelIsoPF->at(1) << endl;
    //cout << "SIP0 = " << LepSIP->at(0) << " SIP1 = " << LepSIP->at(1) << endl;

    h_Z1_Mass[0]->Fill(Z1Mass, WEIGHT);
    h_PFMET[0]->Fill(PFMET, WEIGHT);
    
    // all, ee, mumu
    //TH1F* h_Lep3_pT[3][3][10]; flavor / loc / cuts
       
    h_Lep3_pT[0][0][0]->Fill(LepPt->at(2), WEIGHT); // all / all / cut0
    if( fabs(LepEta->at(2))< eta_cut) h_Lep3_pT[0][1][0]->Fill(LepPt->at(2), WEIGHT); // all / EB / cut0
    else h_Lep3_pT[0][2][0]->Fill(LepPt->at(2), WEIGHT); // all / EE / cut0
   
    if(Z1Flav==-121) {
      h_Z1_MassEE[0]->Fill(Z1Mass, WEIGHT);
      h_Lep3_pT[1][0][0]->Fill(LepPt->at(2), WEIGHT); // ee / all / cut0
      if( fabs(LepEta->at(2))< eta_cut) h_Lep3_pT[1][1][0]->Fill(LepPt->at(2), WEIGHT); // ee / EB / cut0
      else h_Lep3_pT[1][2][0]->Fill(LepPt->at(2), WEIGHT); // ee / EE / cut0
    } // if Zee
    else if(Z1Flav==-169) {
      h_Z1_MassMM[0]->Fill(Z1Mass, WEIGHT);
      h_Lep3_pT[2][0][0]->Fill(LepPt->at(2), WEIGHT);  // all / all / cut0
      if( fabs(LepEta->at(2))< eta_cut) h_Lep3_pT[2][1][0]->Fill(LepPt->at(2), WEIGHT); // mm / EB / cut0
      else h_Lep3_pT[2][2][0]->Fill(LepPt->at(2), WEIGHT); // mm / EE / cut0
    } // if Zmumu
    
    // =========================
    // Cut on SIP
    // =========================
    if(LepSIP->at(2)>=4) continue; cutdes[icut] = "|SIP(3rd lepton)|<4"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 

    h_Z1_Mass[1]->Fill(Z1Mass, WEIGHT);
    h_PFMET[1]->Fill(PFMET, WEIGHT);

     h_Lep3_pT[0][0][1]->Fill(LepPt->at(2), WEIGHT); // all / all / cut0
    if( fabs(LepEta->at(2))< eta_cut) h_Lep3_pT[0][1][1]->Fill(LepPt->at(2), WEIGHT); // all / EB / cut0
    else h_Lep3_pT[0][2][1]->Fill(LepPt->at(2), WEIGHT); // all / EE / cut0
   
    if(Z1Flav==-121) {
      h_Z1_MassEE[1]->Fill(Z1Mass, WEIGHT);
      h_Lep3_pT[1][0][1]->Fill(LepPt->at(2), WEIGHT); // ee / all / cut0
      if( fabs(LepEta->at(2))< eta_cut) h_Lep3_pT[1][1][1]->Fill(LepPt->at(2), WEIGHT); // ee / EB / cut0
      else h_Lep3_pT[1][2][1]->Fill(LepPt->at(2), WEIGHT); // ee / EE / cut0
    } // if Zee
    else if(Z1Flav==-169) {
      h_Z1_MassMM[1]->Fill(Z1Mass, WEIGHT);
      h_Lep3_pT[2][0][1]->Fill(LepPt->at(2), WEIGHT);  // all / all / cut0
      if( fabs(LepEta->at(2))< eta_cut) h_Lep3_pT[2][1][1]->Fill(LepPt->at(2), WEIGHT); // mm / EB / cut0
      else h_Lep3_pT[2][2][1]->Fill(LepPt->at(2), WEIGHT); // mm / EE / cut0
    } // if Zmumu

    // =========================
    // Cut on MET
    // =========================
    if(PFMET>=25) continue; cutdes[icut] = "PFMET<25"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    //if(PFMETNoHF>=25) continue; cutdes[icut] = "PFMET<25"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 

    h_Z1_Mass[2]->Fill(Z1Mass, WEIGHT);
    h_PFMET[2]->Fill(PFMET, WEIGHT);
    
    h_Lep3_pT[0][0][2]->Fill(LepPt->at(2), WEIGHT); // all / all / cut0
    h_Lep3_isID[0][0][2]->Fill(LepisID->at(2), WEIGHT); 
    if( fabs(LepEta->at(2))< eta_cut) {
      h_Lep3_pT[0][1][2]->Fill(LepPt->at(2), WEIGHT); // all / EB / cut0
      h_Lep3_isID[0][1][2]->Fill(LepisID->at(2), WEIGHT); 
    } // BARREL
    else {
      h_Lep3_pT[0][2][2]->Fill(LepPt->at(2), WEIGHT); // all / EE / cut0
      h_Lep3_isID[0][2][2]->Fill(LepisID->at(2), WEIGHT); 
    } // ENDCAP
   
    if(Z1Flav==-121) {
      h_Z1_MassEE[2]->Fill(Z1Mass, WEIGHT);
      h_Lep3_pT[1][0][2]->Fill(LepPt->at(2), WEIGHT); // ee / all / cut0
      h_Lep3_isID[1][0][2]->Fill(LepisID->at(2), WEIGHT); 
      if( fabs(LepEta->at(2))< eta_cut) {
	h_Lep3_pT[1][1][2]->Fill(LepPt->at(2), WEIGHT); // ee / EB / cut0
	h_Lep3_isID[1][1][2]->Fill(LepisID->at(2), WEIGHT); 
      } // BARREL
      else {
	h_Lep3_pT[1][2][2]->Fill(LepPt->at(2), WEIGHT); // ee / EE / cut0
	h_Lep3_isID[1][2][2]->Fill(LepisID->at(2), WEIGHT); 
      } // ENDCAP
    } // if Zee
    else if(Z1Flav==-169) {
      h_Z1_MassMM[2]->Fill(Z1Mass, WEIGHT);
      h_Lep3_pT[2][0][2]->Fill(LepPt->at(2), WEIGHT);  // all / all / cut0
      h_Lep3_isID[2][0][2]->Fill(LepisID->at(2), WEIGHT); 
      if( fabs(LepEta->at(2))< eta_cut) {
	h_Lep3_pT[2][1][2]->Fill(LepPt->at(2), WEIGHT); // mm / EB / cut0
	h_Lep3_isID[2][1][2]->Fill(LepisID->at(2), WEIGHT); 
      } // BARREL
      else {
	h_Lep3_pT[2][2][2]->Fill(LepPt->at(2), WEIGHT); // mm / EE / cut0
	h_Lep3_isID[2][2][2]->Fill(LepisID->at(2), WEIGHT); 
      } // ENDCAP
    } // if Zmumu

    // -----------------
    // Missings Hits
    // -----------------
    //Float_t xbins[8] = {5,7,10,20,30,40,50,80};    
    h_Lep3_inclmhits[0]->Fill(LepMissingHit->at(2), WEIGHT); 

    if( fabs(LepEta->at(2))< eta_cut) {
      h_Lep3_inclmhits[1]->Fill(LepMissingHit->at(2), WEIGHT); 
      if(LepPt->at(2)>5 && LepPt->at(2)<=7) h_Lep3_mhits[1][0]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>7 && LepPt->at(2)<=10) h_Lep3_mhits[1][1]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>10 && LepPt->at(2)<=20) h_Lep3_mhits[1][2]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>20 && LepPt->at(2)<=30) h_Lep3_mhits[1][3]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>30 && LepPt->at(2)<=40) h_Lep3_mhits[1][4]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>40 && LepPt->at(2)<=50) h_Lep3_mhits[1][5]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>50 && LepPt->at(2)<=80) h_Lep3_mhits[1][6]->Fill(LepMissingHit->at(2), WEIGHT); 
    } // if BARREL
    else {
      h_Lep3_inclmhits[2]->Fill(LepMissingHit->at(2), WEIGHT); 
      if(LepPt->at(2)>5 && LepPt->at(2)<=7) h_Lep3_mhits[2][0]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>7 && LepPt->at(2)<=10) h_Lep3_mhits[2][1]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>10 && LepPt->at(2)<=20) h_Lep3_mhits[2][2]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>20 && LepPt->at(2)<=30) h_Lep3_mhits[2][3]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>30 && LepPt->at(2)<=40) h_Lep3_mhits[2][4]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>40 && LepPt->at(2)<=50) h_Lep3_mhits[2][5]->Fill(LepMissingHit->at(2), WEIGHT); 
      else if(LepPt->at(2)>50 && LepPt->at(2)<=80) h_Lep3_mhits[2][6]->Fill(LepMissingHit->at(2), WEIGHT); 
    } // else ENDCAP
 
   // =========================
    // Cut on ID + Iso
    // =========================
    bool isID = false;
    bool isISO = false;
    if(LepisID->at(2)==1) isID = true;
    if(LepCombRelIsoPF->at(2) < 0.35) isISO = true;

    if(isID==false) continue; cutdes[icut] = "Lep3 Pass ID"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 
    if(isISO==false) continue; cutdes[icut] = "Lep3 Pass ISO"; ICUT->Fill((Float_t)icut,WEIGHT); icut++; 

    h_Z1_Mass[3]->Fill(Z1Mass, WEIGHT);
    h_PFMET[3]->Fill(PFMET, WEIGHT);
    
    h_Lep3_pT[0][0][3]->Fill(LepPt->at(2), WEIGHT); // all / all / cut0
    h_Lep3_isID[0][0][3]->Fill(LepisID->at(2), WEIGHT); 
    if( fabs(LepEta->at(2))< eta_cut) {
      h_Lep3_pT[0][1][3]->Fill(LepPt->at(2), WEIGHT); // all / EB / cut0
      h_Lep3_isID[0][1][3]->Fill(LepisID->at(2), WEIGHT); 
    } // BARREL
    else {
      h_Lep3_pT[0][2][3]->Fill(LepPt->at(2), WEIGHT); // all / EE / cut0
      h_Lep3_isID[0][2][3]->Fill(LepisID->at(2), WEIGHT); 
    } // ENDCAP
   
    if(Z1Flav==-121) {
      h_Z1_MassEE[3]->Fill(Z1Mass, WEIGHT);
      h_Lep3_pT[1][0][3]->Fill(LepPt->at(2), WEIGHT); // ee / all / cut0
      h_Lep3_isID[1][0][3]->Fill(LepisID->at(2), WEIGHT); 
      if( fabs(LepEta->at(2))< eta_cut) {
	h_Lep3_pT[1][1][3]->Fill(LepPt->at(2), WEIGHT); // ee / EB / cut0
	h_Lep3_isID[1][1][3]->Fill(LepisID->at(2), WEIGHT); 
      } // BARREL
      else {
	h_Lep3_pT[1][2][3]->Fill(LepPt->at(2), WEIGHT); // ee / EE / cut0
	h_Lep3_isID[1][2][3]->Fill(LepisID->at(2), WEIGHT); 
      } // ENDCAP
    } // if Zee
    else if(Z1Flav==-169) {
      h_Z1_MassMM[3]->Fill(Z1Mass, WEIGHT);
      h_Lep3_pT[2][0][3]->Fill(LepPt->at(2), WEIGHT);  // all / all / cut0
      h_Lep3_isID[2][0][3]->Fill(LepisID->at(2), WEIGHT); 
      if( fabs(LepEta->at(2))< eta_cut) {
	h_Lep3_pT[2][1][3]->Fill(LepPt->at(2), WEIGHT); // mm / EB / cut0
	h_Lep3_isID[2][1][3]->Fill(LepisID->at(2), WEIGHT); 
      } // BARREL
      else {
	h_Lep3_pT[2][2][3]->Fill(LepPt->at(2), WEIGHT); // mm / EE / cut0
	h_Lep3_isID[2][2][3]->Fill(LepisID->at(2), WEIGHT); 
      } // ENDCAP
    } // if Zmumu
    
    
    
    icut_MAX = icut;
    nselected++;
  } // END of the loop

  cout << "icut_max = " << icut_MAX << endl;
  //if(icut_MAX<2) icut_MAX = 30;
  cout << "======================================================================" << endl;
  for ( Int_t i=0; i<8 ; i++ )
    cout << "Cut " << setw(3) << i << " : " << setw(30) << cutdes[i] << " : " << ICUT->GetBinContent(i+1) << endl;
  //cout << "Cut " << i << " : " << ICUT->GetBinContent(i) << endl;
  cout << "======================================================================" << endl;
  cout << "Total Number of events selected = "  << nselected                       << endl;
  //cout << "Total Number of events written  = "  << nwrite                          << endl;
  cout << "======================================================================" << endl;

  // ===============================================================
  //   Output File
  // ===============================================================
  OutputFile->cd();
  //h_Z1_Mass->Write();

  for(int iflavor=0;iflavor<3;iflavor++) {
    for(int iloc=0;iloc<3;iloc++) {
      h_Lep3_inclmhits[iloc]->Write();
      
      for(int iname=0;iname<4;iname++) {
	h_Lep3_pT[iflavor][iloc][iname]->Write();
	h_Lep3_isID[iflavor][iloc][iname]->Write();
      } // for loop on iname
    } // for loop in iloc
  } // for loop on flavor

  for(int iloc=0;iloc<3;iloc++) {
    for(int ipt=0;ipt<7;ipt++) {
      h_Lep3_mhits[iloc][ipt]->Write();
    }
  } // for loop on loc
  
  for(int iname=0;iname<4;iname++) {
    h_PFMET[iname]->Write(); 
    h_Z1_Mass[iname]->Write(); 
    h_Z1_MassEE[iname]->Write(); 
    h_Z1_MassMM[iname]->Write(); 
  } // for loop on cuts/names
  

  OutputFile->Write();
  OutputFile->Close();
  
  cout << "---> Writing to file: "  << outputfile_name << endl;
  cout << "---> Done! " << endl;
  cout << " " << endl;
}
