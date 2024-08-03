
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
  {"k", "4", false, "-"},
  {"VT", "0.026", false, "-"},
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
  double Iat;
  double Iat_VG_GND;
  double Iat_VS_GND;
  double Iat_VD_GND;
  double Vdseff;
  double Vdseff_VD_GND;
  double Vdseff_VS_GND;
  double Vdseff_VG_GND;
  double Vdsat;
  double Vdsat_VG_GND;
  double Vdsat_VS_GND;
  double Vgt;
  double Vgt_VG_GND;
  double Vgt_VS_GND;
  double Vds;
  double Vds_VD_GND;
  double Vds_VS_GND;
  double Vgs;
  double Vgs_VG_GND;
  double Vgs_VS_GND;

  // load device model input parameters
  double Vth = getNumber(Parameters[0]);
  double alpha = getNumber(Parameters[1]);
  double gain = getNumber(Parameters[2]);
  double m = getNumber(Parameters[3]);
  double k = getNumber(Parameters[4]);
  double VT = getNumber(Parameters[5]);


  // evaluate verilog initial model


  // evaluate verilog initial step


  // evaluate verilog initial instance


  // evaluate verilog analog equations
  Vgs_VG_GND=1.0;
  Vgs_VS_GND=(-1.0);
  Vgs=(sys->getV(G, GND)-sys->getV(S, GND));
  Vds_VD_GND=1.0;
  Vds_VS_GND=(-1.0);
  Vds=(sys->getV(D, GND)-sys->getV(S, GND));
  {
    double d00_pow0 = pow((Vgs-Vth),2);
    double d00_sqrt1 = sqrt((d00_pow0+1e-30));
    double m10_pow(d10_pow0,d00_pow0,(Vgs-Vth),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+1e-30))
    Vgt_VG_GND=(0.5*(Vgs_VG_GND+(d10_pow0*Vgs_VG_GND)*d10_sqrt1));
    Vgt_VS_GND=(0.5*(Vgs_VS_GND+(d10_pow0*Vgs_VS_GND)*d10_sqrt1));
    Vgt=(0.5*((Vgs-Vth)+d00_sqrt1));
  }
  Vdsat_VG_GND=(Vgt_VG_GND/alpha);
  Vdsat_VS_GND=(Vgt_VS_GND/alpha);
  Vdsat=(Vgt/alpha);
  {
    double d00_pow0 = pow((Vds-Vdsat),2);
    double d00_sqrt1 = sqrt((d00_pow0+1e-30));
    double m10_pow(d10_pow0,d00_pow0,(Vds-Vdsat),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+1e-30))
    Vdseff_VD_GND=(Vds_VD_GND-(0.5*(Vds_VD_GND+(d10_pow0*Vds_VD_GND)*d10_sqrt1)));
    Vdseff_VS_GND=(Vds_VS_GND-(0.5*((Vds_VS_GND-Vdsat_VS_GND)+(d10_pow0*(Vds_VS_GND-Vdsat_VS_GND))*d10_sqrt1)));
    Vdseff_VG_GND=(-(0.5*((-Vdsat_VG_GND)+(d10_pow0*(-Vdsat_VG_GND))*d10_sqrt1)));
    Vdseff=(Vds-(0.5*((Vds-Vdsat)+d00_sqrt1)));
  }
  {
    double d00_pow0 = pow(Vdseff,2);
    double m10_pow(d10_pow0,d00_pow0,Vdseff,2)
    Iat_VG_GND=((gain*alpha)*((Vdsat_VG_GND*Vdseff+Vdsat*Vdseff_VG_GND)-(0.5*(d10_pow0*Vdseff_VG_GND))));
    Iat_VS_GND=((gain*alpha)*((Vdsat_VS_GND*Vdseff+Vdsat*Vdseff_VS_GND)-(0.5*(d10_pow0*Vdseff_VS_GND))));
    Iat_VD_GND=((gain*alpha)*((Vdsat*Vdseff_VD_GND)-(0.5*(d10_pow0*Vdseff_VD_GND))));
    Iat=((gain*alpha)*((Vdsat*Vdseff)-(0.5*d00_pow0)));
  }
  {
    double d00_exp0 = exp((-2));
    double d00_exp1 = exp((((-2)*k)/m));
    Io=(((gain*((((2*m)*m)*VT)*VT))/alpha)*(d00_exp0+d00_exp1));
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

  sys->setIQ(D,S,(Iat+Ist),0);
  sys->setGC(D,S,D,GND,Iat_VD_GND,0);
  sys->setGC(D,S,S,GND,(Iat_VS_GND+Ist_VS_GND),0);
  sys->setGC(D,S,G,GND,(Iat_VG_GND+Ist_VG_GND),0);
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
