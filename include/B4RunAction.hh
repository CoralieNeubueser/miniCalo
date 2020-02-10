//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B4RunAction.hh 74265 2013-10-02 14:41:20Z gcosmo $
// 
/// \file B4RunAction.hh
/// \brief Definition of the B4RunAction class

#ifndef B4RunAction_h
#define B4RunAction_h 1

#include "defines.h"

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4String.hh"
#include "B4PartGeneratorBase.hh"

class G4Run;
class B4PrimaryGeneratorAction;
class B4aEventAction;
/// Run action class
///
/// It accumulates statistic and computes dispersion of the energy deposit 
/// and track lengths of charged particles with use of analysis tools:
/// H1D histograms are created in BeginOfRunAction() for the following 
/// physics quantities:
/// - Edep in absorber
/// - Edep in gap
/// - Track length in absorber
/// - Track length in gap
/// The same values are also saved in the ntuple.
/// The histograms and ntuple are saved in the output file in a format
/// accoring to a selected technology in B4Analysis.hh.
///
/// In EndOfRunAction(), the accumulated statistic and computed 
/// dispersion is printed.
///

class B4RunAction : public G4UserRunAction
{
  public:
    B4RunAction(B4PartGeneratorBase * gen, B4aEventAction* e, G4String fn);
    virtual ~B4RunAction();

    void linkGenerator(B4PartGeneratorBase* g){
    	generator_=g;
    }
    void linkEventAction(B4aEventAction* e){
    	eventact_=e;
    }

    void setFileName(G4String fname){
    	fname_=fname;
    }

    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);
  private:
    B4PartGeneratorBase * generator_;
    B4aEventAction* eventact_;
    G4String fname_;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

