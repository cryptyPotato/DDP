
/*
 * nmos.cpp - dynamically linked component for QucsStudio
 * created from VerilogAMS file by ADMS
 */

#include <qucsstudio_library.h>
#include <qucsstudio_vams.h>

// --------------------------------------------------------------
// component parameter definition
tParameterDef params[] = {
  {"Vth", "1.2", false, "-"},
  {"alpha", "3.4", false, "-"},
  {"gain", "3.15e-6", false, "-"},
  {"m", "3", false, "-"},
  {"VT", "0.026", false, "-"},
  {"k", "4", false, "-"},
};

// -----------------------------------------------------
// external nodes
#undef D
#define D Nodes[0]
#undef G
#define G Nodes[1]
#undef S
#define S Nodes[2]

// internal nodes

// -----------------------------------------------------
// VerilogA analog functions


// -----------------------------------------------------
// evaluate VerilogA equations in analog block
void fillMatrix(Component *theComp, Node **Nodes, tParameter *Parameters, tGlobalVar *gVar, EqnSystem *sys, double _freq_, double _time_)
{
  // global variables

  // general variables
  double Ist;
  double Ist_VG_GND;
  double Ist_VS_GND;
  double Ips;
  double Iss;
  double Iss_VG_GND;
  double Iss_VS_GND;
  double Io;
  double Vds;
  double Vgs;
  double Vgs_VG_GND;
  double Vgs_VS_GND;

  // load device model input parameters
  double Vth = getNumber(Parameters[0]);
  double alpha = getNumber(Parameters[1]);
  double gain = getNumber(Parameters[2]);
  double m = getNumber(Parameters[3]);
  double VT = getNumber(Parameters[4]);
  double k = getNumber(Parameters[5]);


  // evaluate verilog initial model


  // evaluate verilog initial step


  // evaluate verilog initial instance


  // evaluate verilog analog equations
  Vgs_VG_GND=1.0;
  Vgs_VS_GND=(-1.0);
  Vgs=(sys->getV(G, GND)-sys->getV(S, GND));
  Vds=(sys->getV(D, GND)-sys->getV(S, GND));
  {
    double d00_exp0 = exp((-2));
    Io=(((gain*((((2*m)*m)*VT)*VT))/alpha)*d00_exp0);
  }
  {
    double d00_exp0 = exp(((Vgs-Vth)/(m*VT)));
  #define d10_exp0 d00_exp0
    Iss_VG_GND=(Io*(Vgs_VG_GND/(m*VT))*d10_exp0);
    Iss_VS_GND=(Io*(Vgs_VS_GND/(m*VT))*d10_exp0);
    Iss=(Io*d00_exp0);
  }
  {
    double d00_exp0 = exp(((2*k)/m));
    Ips=(Io*d00_exp0);
  }
  Ist_VG_GND=(((Iss_VG_GND*Ips)-(Iss*Ips)/(Iss+Ips)*Iss_VG_GND)/(Iss+Ips));
  Ist_VS_GND=(((Iss_VS_GND*Ips)-(Iss*Ips)/(Iss+Ips)*Iss_VS_GND)/(Iss+Ips));
  Ist=((Iss*Ips)/(Iss+Ips));

  sys->setIQ(D,S,Ist,0);
  sys->setGC(D,S,S,GND,Ist_VS_GND,0);
  sys->setGC(D,S,G,GND,Ist_VG_GND,0);
}



// --------------------------------------------------------------
// component definition
EXPORT tComponentInfo compInfo = {
  isNonLinear,                // component type ('isNonLinear' or 'isLinear')
  "nmos",                // model identifier
  "VerilogAMS model of nmos",  // component description
  3,                          // number of external nodes
  0+0,                        // number of internal nodes
  0,                          // number of inputs (system simulations only)
  6,                         // number of parameters
  params,                     // pointer to list of parameters
  0,                          // size of global variable buffer in bytes
  0,                          // pointer to component icon (0 = unused)
  0,                          // size of component icon
  -1,                         // index of parameter determining schematic symbol (-1 = unused)
  0,                          // pointer to list of schematic symbols
  (tEvaluate)fillMatrix,      // function calculating analog model (0 = no model exists)
  0,                          // function calculating noise model (0 = noise free)
  0,                          // function calculating system model (0 = no model exists)
  0,                          // string with digital Verilog model (0 = no model exists)
  0                           // string with digital VHDL model (0 = no model exists)
};
