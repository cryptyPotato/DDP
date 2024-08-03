
/*
 * nmos.cpp - dynamically linked component for QucsStudio
 * created from VerilogAMS file by ADMS
 */

#include <qucsstudio_library.h>
#include <qucsstudio_vams.h>

// --------------------------------------------------------------
// component parameter definition
tParameterDef params[] = {
  {"Vth1", "1.2", false, "-"},
  {"alpha1", "3.4", false, "-"},
  {"gain1", "3.15e-6", false, "-"},
  {"dibl1", "0.04", false, "-"},
  {"lambda1", "0.03", false, "-"},
  {"Vth2", "0.95", false, "-"},
  {"alpha2", "1.7", false, "-"},
  {"gain2", "6.93e-7", false, "-"},
  {"dibl2", "0.08", false, "-"},
  {"lambda2", "0.07", false, "-"},
  {"R", "3000", false, "-"},
  {"delta", "1e-30", false, "-"},
  {"m1", "3", false, "-"},
  {"m2", "1.2", false, "-"},
  {"k1", "1", false, "-"},
  {"k2", "1", false, "-"},
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
#undef Di
#define Di Nodes[3]
#undef Si
#define Si Nodes[4]

// -----------------------------------------------------
// VerilogA analog functions


// -----------------------------------------------------
// evaluate VerilogA equations in analog block
void fillMatrix(Component *theComp, Node **Nodes, tParameter *Parameters, tGlobalVar *gVar, EqnSystem *sys, double _freq_, double _time_)
{
  // global variables

  // general variables
  double Ist;
  double Ist_VDi_GND;
  double Ist_VSi_GND;
  double Ist_VG_GND;
  double Ist2;
  double Ist2_VDi_GND;
  double Ist2_VSi_GND;
  double Ist2_VG_GND;
  double Ist1;
  double Ist1_VDi_GND;
  double Ist1_VSi_GND;
  double Ist1_VG_GND;
  double Iss2;
  double Iss2_VDi_GND;
  double Iss2_VSi_GND;
  double Iss2_VG_GND;
  double Iss1;
  double Iss1_VDi_GND;
  double Iss1_VSi_GND;
  double Iss1_VG_GND;
  double Ip2;
  double Ip2_VDi_GND;
  double Ip2_VSi_GND;
  double Ip1;
  double Ip1_VDi_GND;
  double Ip1_VSi_GND;
  double Io2;
  double Io2_VDi_GND;
  double Io2_VSi_GND;
  double Io1;
  double Io1_VDi_GND;
  double Io1_VSi_GND;
  double Vdseffp2;
  double Vdseffp2_VDi_GND;
  double Vdseffp2_VSi_GND;
  double Vdseffp1;
  double Vdseffp1_VDi_GND;
  double Vdseffp1_VSi_GND;
  double Vdseffo2;
  double Vdseffo2_VDi_GND;
  double Vdseffo2_VSi_GND;
  double Vdseffo1;
  double Vdseffo1_VDi_GND;
  double Vdseffo1_VSi_GND;
  double Vdsatp2;
  double Vdsatp2_VDi_GND;
  double Vdsatp2_VSi_GND;
  double Vdsatp1;
  double Vdsatp1_VDi_GND;
  double Vdsatp1_VSi_GND;
  double Vdsato2;
  double Vdsato2_VDi_GND;
  double Vdsato2_VSi_GND;
  double Vdsato1;
  double Vdsato1_VDi_GND;
  double Vdsato1_VSi_GND;
  double Vgp2;
  double Vgp2_VDi_GND;
  double Vgp2_VSi_GND;
  double Vgp1;
  double Vgp1_VDi_GND;
  double Vgp1_VSi_GND;
  double Vgo2;
  double Vgo2_VDi_GND;
  double Vgo2_VSi_GND;
  double Vgo1;
  double Vgo1_VDi_GND;
  double Vgo1_VSi_GND;
  double Iat;
  double Iat_VDi_GND;
  double Iat_VSi_GND;
  double Iat_VG_GND;
  double Iat2;
  double Iat2_VDi_GND;
  double Iat2_VSi_GND;
  double Iat2_VG_GND;
  double Iat1;
  double Iat1_VDi_GND;
  double Iat1_VSi_GND;
  double Iat1_VG_GND;
  double Vdseff2;
  double Vdseff2_VDi_GND;
  double Vdseff2_VSi_GND;
  double Vdseff2_VG_GND;
  double Vdseff1;
  double Vdseff1_VDi_GND;
  double Vdseff1_VSi_GND;
  double Vdseff1_VG_GND;
  double Vdsat2;
  double Vdsat2_VG_GND;
  double Vdsat2_VSi_GND;
  double Vdsat1;
  double Vdsat1_VG_GND;
  double Vdsat1_VSi_GND;
  double Vgst2;
  double Vgst2_VG_GND;
  double Vgst2_VSi_GND;
  double Vgst1;
  double Vgst1_VG_GND;
  double Vgst1_VSi_GND;
  double Vthi2;
  double Vthi2_VDi_GND;
  double Vthi2_VSi_GND;
  double Vthi1;
  double Vthi1_VDi_GND;
  double Vthi1_VSi_GND;
  double Vdsi;
  double Vdsi_VDi_GND;
  double Vdsi_VSi_GND;
  double Vgsi;
  double Vgsi_VG_GND;
  double Vgsi_VSi_GND;

  // load device model input parameters
  double Vth1 = getNumber(Parameters[0]);
  double alpha1 = getNumber(Parameters[1]);
  double gain1 = getNumber(Parameters[2]);
  double dibl1 = getNumber(Parameters[3]);
  double lambda1 = getNumber(Parameters[4]);
  double Vth2 = getNumber(Parameters[5]);
  double alpha2 = getNumber(Parameters[6]);
  double gain2 = getNumber(Parameters[7]);
  double dibl2 = getNumber(Parameters[8]);
  double lambda2 = getNumber(Parameters[9]);
  double R = getNumber(Parameters[10]);
  double delta = getNumber(Parameters[11]);
  double m1 = getNumber(Parameters[12]);
  double m2 = getNumber(Parameters[13]);
  double k1 = getNumber(Parameters[14]);
  double k2 = getNumber(Parameters[15]);


  // evaluate verilog initial model


  // evaluate verilog initial step


  // evaluate verilog initial instance


  // evaluate verilog analog equations

  sys->setG(Si,S,(1/R));

  sys->setG(D,Di,(1/R));
  Vgsi_VG_GND=1.0;
  Vgsi_VSi_GND=(-1.0);
  Vgsi=(sys->getV(G, GND)-sys->getV(Si, GND));
  Vdsi_VDi_GND=1.0;
  Vdsi_VSi_GND=(-1.0);
  Vdsi=(sys->getV(Di, GND)-sys->getV(Si, GND));
  Vthi1_VDi_GND=(-(dibl1*Vdsi_VDi_GND));
  Vthi1_VSi_GND=(-(dibl1*Vdsi_VSi_GND));
  Vthi1=(Vth1-(dibl1*Vdsi));
  Vthi2_VDi_GND=(-(dibl2*Vdsi_VDi_GND));
  Vthi2_VSi_GND=(-(dibl2*Vdsi_VSi_GND));
  Vthi2=(Vth2-(dibl2*Vdsi));
  {
    double d00_pow0 = pow((Vgsi-Vth1),2);
    double d00_sqrt1 = sqrt((d00_pow0+delta));
    double m10_pow(d10_pow0,d00_pow0,(Vgsi-Vth1),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+delta))
    Vgst1_VG_GND=((Vgsi_VG_GND+(d10_pow0*Vgsi_VG_GND)*d10_sqrt1)/2);
    Vgst1_VSi_GND=((Vgsi_VSi_GND+(d10_pow0*Vgsi_VSi_GND)*d10_sqrt1)/2);
    Vgst1=(((Vgsi-Vth1)+d00_sqrt1)/2);
  }
  {
    double d00_pow0 = pow((Vgsi-Vth2),2);
    double d00_sqrt1 = sqrt((d00_pow0+delta));
    double m10_pow(d10_pow0,d00_pow0,(Vgsi-Vth2),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+delta))
    Vgst2_VG_GND=((Vgsi_VG_GND+(d10_pow0*Vgsi_VG_GND)*d10_sqrt1)/2);
    Vgst2_VSi_GND=((Vgsi_VSi_GND+(d10_pow0*Vgsi_VSi_GND)*d10_sqrt1)/2);
    Vgst2=(((Vgsi-Vth2)+d00_sqrt1)/2);
  }
  Vdsat1_VG_GND=(Vgst1_VG_GND/alpha1);
  Vdsat1_VSi_GND=(Vgst1_VSi_GND/alpha1);
  Vdsat1=(Vgst1/alpha1);
  Vdsat2_VG_GND=(Vgst2_VG_GND/alpha2);
  Vdsat2_VSi_GND=(Vgst2_VSi_GND/alpha2);
  Vdsat2=(Vgst2/alpha2);
  {
    double d00_pow0 = pow((Vdsi-Vdsat1),2);
    double d00_sqrt1 = sqrt((d00_pow0+delta));
    double m10_pow(d10_pow0,d00_pow0,(Vdsi-Vdsat1),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+delta))
    Vdseff1_VDi_GND=(Vdsi_VDi_GND-(0.5*(Vdsi_VDi_GND+(d10_pow0*Vdsi_VDi_GND)*d10_sqrt1)));
    Vdseff1_VSi_GND=(Vdsi_VSi_GND-(0.5*((Vdsi_VSi_GND-Vdsat1_VSi_GND)+(d10_pow0*(Vdsi_VSi_GND-Vdsat1_VSi_GND))*d10_sqrt1)));
    Vdseff1_VG_GND=(-(0.5*((-Vdsat1_VG_GND)+(d10_pow0*(-Vdsat1_VG_GND))*d10_sqrt1)));
    Vdseff1=(Vdsi-(0.5*((Vdsi-Vdsat1)+d00_sqrt1)));
  }
  {
    double d00_pow0 = pow((Vdsi-Vdsat2),2);
    double d00_sqrt1 = sqrt((d00_pow0+delta));
    double m10_pow(d10_pow0,d00_pow0,(Vdsi-Vdsat2),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+delta))
    Vdseff2_VDi_GND=(Vdsi_VDi_GND-(0.5*(Vdsi_VDi_GND+(d10_pow0*Vdsi_VDi_GND)*d10_sqrt1)));
    Vdseff2_VSi_GND=(Vdsi_VSi_GND-(0.5*((Vdsi_VSi_GND-Vdsat2_VSi_GND)+(d10_pow0*(Vdsi_VSi_GND-Vdsat2_VSi_GND))*d10_sqrt1)));
    Vdseff2_VG_GND=(-(0.5*((-Vdsat2_VG_GND)+(d10_pow0*(-Vdsat2_VG_GND))*d10_sqrt1)));
    Vdseff2=(Vdsi-(0.5*((Vdsi-Vdsat2)+d00_sqrt1)));
  }
  {
    double d00_pow0 = pow(Vdseff1,2);
    double m10_pow(d10_pow0,d00_pow0,Vdseff1,2)
    Iat1_VDi_GND=(((alpha1*gain1)*((Vdseff1_VDi_GND*Vdsat1)-((d10_pow0*Vdseff1_VDi_GND)/2)))*(1+(lambda1*Vdsi))+((alpha1*gain1)*((Vdseff1*Vdsat1)-(d00_pow0/2)))*(lambda1*Vdsi_VDi_GND));
    Iat1_VSi_GND=(((alpha1*gain1)*((Vdseff1_VSi_GND*Vdsat1+Vdseff1*Vdsat1_VSi_GND)-((d10_pow0*Vdseff1_VSi_GND)/2)))*(1+(lambda1*Vdsi))+((alpha1*gain1)*((Vdseff1*Vdsat1)-(d00_pow0/2)))*(lambda1*Vdsi_VSi_GND));
    Iat1_VG_GND=(((alpha1*gain1)*((Vdseff1_VG_GND*Vdsat1+Vdseff1*Vdsat1_VG_GND)-((d10_pow0*Vdseff1_VG_GND)/2)))*(1+(lambda1*Vdsi)));
    Iat1=(((alpha1*gain1)*((Vdseff1*Vdsat1)-(d00_pow0/2)))*(1+(lambda1*Vdsi)));
  }
  {
    double d00_pow0 = pow(Vdseff2,2);
    double m10_pow(d10_pow0,d00_pow0,Vdseff2,2)
    Iat2_VDi_GND=(((alpha2*gain2)*((Vdseff2_VDi_GND*Vdsat2)-((d10_pow0*Vdseff2_VDi_GND)/2)))*(1+(lambda2*Vdsi))+((alpha2*gain2)*((Vdseff2*Vdsat2)-(d00_pow0/2)))*(lambda2*Vdsi_VDi_GND));
    Iat2_VSi_GND=(((alpha2*gain2)*((Vdseff2_VSi_GND*Vdsat2+Vdseff2*Vdsat2_VSi_GND)-((d10_pow0*Vdseff2_VSi_GND)/2)))*(1+(lambda2*Vdsi))+((alpha2*gain2)*((Vdseff2*Vdsat2)-(d00_pow0/2)))*(lambda2*Vdsi_VSi_GND));
    Iat2_VG_GND=(((alpha2*gain2)*((Vdseff2_VG_GND*Vdsat2+Vdseff2*Vdsat2_VG_GND)-((d10_pow0*Vdseff2_VG_GND)/2)))*(1+(lambda2*Vdsi)));
    Iat2=(((alpha2*gain2)*((Vdseff2*Vdsat2)-(d00_pow0/2)))*(1+(lambda2*Vdsi)));
  }
  Iat_VDi_GND=(Iat1_VDi_GND+Iat2_VDi_GND);
  Iat_VSi_GND=(Iat1_VSi_GND+Iat2_VSi_GND);
  Iat_VG_GND=(Iat1_VG_GND+Iat2_VG_GND);
  Iat=(Iat1+Iat2);
  Vgo1_VDi_GND=(Vthi1_VDi_GND+((Vdsi_VDi_GND*alpha1)/2));
  Vgo1_VSi_GND=(Vthi1_VSi_GND+((Vdsi_VSi_GND*alpha1)/2));
  Vgo1=((Vthi1+(m1*0.026))+((Vdsi*alpha1)/2));
  Vgo2_VDi_GND=(Vthi2_VDi_GND+((Vdsi_VDi_GND*alpha2)/2));
  Vgo2_VSi_GND=(Vthi2_VSi_GND+((Vdsi_VSi_GND*alpha2)/2));
  Vgo2=((Vthi2+(m2*0.026))+((Vdsi*alpha2)/2));
  Vgp1_VDi_GND=Vgo1_VDi_GND;
  Vgp1_VSi_GND=Vgo1_VSi_GND;
  Vgp1=(Vgo1+(k1*0.026));
  Vgp2_VDi_GND=Vgo2_VDi_GND;
  Vgp2_VSi_GND=Vgo2_VSi_GND;
  Vgp2=(Vgo2+(k2*0.026));
  Vdsato1_VDi_GND=((Vgo1_VDi_GND-Vthi1_VDi_GND)/alpha1);
  Vdsato1_VSi_GND=((Vgo1_VSi_GND-Vthi1_VSi_GND)/alpha1);
  Vdsato1=((Vgo1-Vthi1)/alpha1);
  Vdsato2_VDi_GND=((Vgo2_VDi_GND-Vthi2_VDi_GND)/alpha2);
  Vdsato2_VSi_GND=((Vgo2_VSi_GND-Vthi2_VSi_GND)/alpha2);
  Vdsato2=((Vgo2-Vthi2)/alpha2);
  Vdsatp1_VDi_GND=((Vgp1_VDi_GND-Vthi1_VDi_GND)/alpha1);
  Vdsatp1_VSi_GND=((Vgp1_VSi_GND-Vthi1_VSi_GND)/alpha1);
  Vdsatp1=((Vgp1-Vthi1)/alpha1);
  Vdsatp2_VDi_GND=((Vgp2_VDi_GND-Vthi2_VDi_GND)/alpha2);
  Vdsatp2_VSi_GND=((Vgp2_VSi_GND-Vthi2_VSi_GND)/alpha2);
  Vdsatp2=((Vgp2-Vthi2)/alpha2);
  {
    double d00_pow0 = pow((Vdsi-Vdsato1),2);
    double d00_sqrt1 = sqrt((d00_pow0+1e-30));
    double m10_pow(d10_pow0,d00_pow0,(Vdsi-Vdsato1),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+1e-30))
    Vdseffo1_VDi_GND=(Vdsi_VDi_GND-(0.5*((Vdsi_VDi_GND-Vdsato1_VDi_GND)+(d10_pow0*(Vdsi_VDi_GND-Vdsato1_VDi_GND))*d10_sqrt1)));
    Vdseffo1_VSi_GND=(Vdsi_VSi_GND-(0.5*((Vdsi_VSi_GND-Vdsato1_VSi_GND)+(d10_pow0*(Vdsi_VSi_GND-Vdsato1_VSi_GND))*d10_sqrt1)));
    Vdseffo1=(Vdsi-(0.5*((Vdsi-Vdsato1)+d00_sqrt1)));
  }
  {
    double d00_pow0 = pow((Vdsi-Vdsato2),2);
    double d00_sqrt1 = sqrt((d00_pow0+1e-30));
    double m10_pow(d10_pow0,d00_pow0,(Vdsi-Vdsato2),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+1e-30))
    Vdseffo2_VDi_GND=(Vdsi_VDi_GND-(0.5*((Vdsi_VDi_GND-Vdsato2_VDi_GND)+(d10_pow0*(Vdsi_VDi_GND-Vdsato2_VDi_GND))*d10_sqrt1)));
    Vdseffo2_VSi_GND=(Vdsi_VSi_GND-(0.5*((Vdsi_VSi_GND-Vdsato2_VSi_GND)+(d10_pow0*(Vdsi_VSi_GND-Vdsato2_VSi_GND))*d10_sqrt1)));
    Vdseffo2=(Vdsi-(0.5*((Vdsi-Vdsato2)+d00_sqrt1)));
  }
  {
    double d00_pow0 = pow((Vdsi-Vdsatp1),2);
    double d00_sqrt1 = sqrt((d00_pow0+1e-30));
    double m10_pow(d10_pow0,d00_pow0,(Vdsi-Vdsatp1),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+1e-30))
    Vdseffp1_VDi_GND=(Vdsi_VDi_GND-(0.5*((Vdsi_VDi_GND-Vdsatp1_VDi_GND)+(d10_pow0*(Vdsi_VDi_GND-Vdsatp1_VDi_GND))*d10_sqrt1)));
    Vdseffp1_VSi_GND=(Vdsi_VSi_GND-(0.5*((Vdsi_VSi_GND-Vdsatp1_VSi_GND)+(d10_pow0*(Vdsi_VSi_GND-Vdsatp1_VSi_GND))*d10_sqrt1)));
    Vdseffp1=(Vdsi-(0.5*((Vdsi-Vdsatp1)+d00_sqrt1)));
  }
  {
    double d00_pow0 = pow((Vdsi-Vdsatp2),2);
    double d00_sqrt1 = sqrt((d00_pow0+1e-30));
    double m10_pow(d10_pow0,d00_pow0,(Vdsi-Vdsatp2),2)
    double m10_sqrt(d10_sqrt1,d00_sqrt1,(d00_pow0+1e-30))
    Vdseffp2_VDi_GND=(Vdsi_VDi_GND-(0.5*((Vdsi_VDi_GND-Vdsatp2_VDi_GND)+(d10_pow0*(Vdsi_VDi_GND-Vdsatp2_VDi_GND))*d10_sqrt1)));
    Vdseffp2_VSi_GND=(Vdsi_VSi_GND-(0.5*((Vdsi_VSi_GND-Vdsatp2_VSi_GND)+(d10_pow0*(Vdsi_VSi_GND-Vdsatp2_VSi_GND))*d10_sqrt1)));
    Vdseffp2=(Vdsi-(0.5*((Vdsi-Vdsatp2)+d00_sqrt1)));
  }
  {
    double d00_pow0 = pow(Vdseffo1,2);
    double m10_pow(d10_pow0,d00_pow0,Vdseffo1,2)
    Io1_VDi_GND=((gain1*alpha1)*((Vdsato1_VDi_GND*Vdseffo1+Vdsato1*Vdseffo1_VDi_GND)-(0.5*(d10_pow0*Vdseffo1_VDi_GND))));
    Io1_VSi_GND=((gain1*alpha1)*((Vdsato1_VSi_GND*Vdseffo1+Vdsato1*Vdseffo1_VSi_GND)-(0.5*(d10_pow0*Vdseffo1_VSi_GND))));
    Io1=((gain1*alpha1)*((Vdsato1*Vdseffo1)-(0.5*d00_pow0)));
  }
  {
    double d00_pow0 = pow(Vdseffo2,2);
    double m10_pow(d10_pow0,d00_pow0,Vdseffo2,2)
    Io2_VDi_GND=((gain2*alpha2)*((Vdsato2_VDi_GND*Vdseffo2+Vdsato2*Vdseffo2_VDi_GND)-(0.5*(d10_pow0*Vdseffo2_VDi_GND))));
    Io2_VSi_GND=((gain2*alpha2)*((Vdsato2_VSi_GND*Vdseffo2+Vdsato2*Vdseffo2_VSi_GND)-(0.5*(d10_pow0*Vdseffo2_VSi_GND))));
    Io2=((gain2*alpha2)*((Vdsato2*Vdseffo2)-(0.5*d00_pow0)));
  }
  {
    double d00_pow0 = pow(Vdseffp1,2);
    double m10_pow(d10_pow0,d00_pow0,Vdseffp1,2)
    Ip1_VDi_GND=((gain1*alpha1)*((Vdsatp1_VDi_GND*Vdseffp1+Vdsatp1*Vdseffp1_VDi_GND)-(0.5*(d10_pow0*Vdseffp1_VDi_GND))));
    Ip1_VSi_GND=((gain1*alpha1)*((Vdsatp1_VSi_GND*Vdseffp1+Vdsatp1*Vdseffp1_VSi_GND)-(0.5*(d10_pow0*Vdseffp1_VSi_GND))));
    Ip1=((gain1*alpha1)*((Vdsatp1*Vdseffp1)-(0.5*d00_pow0)));
  }
  {
    double d00_pow0 = pow(Vdseffp2,2);
    double m10_pow(d10_pow0,d00_pow0,Vdseffp2,2)
    Ip2_VDi_GND=((gain2*alpha2)*((Vdsatp2_VDi_GND*Vdseffp2+Vdsatp2*Vdseffp2_VDi_GND)-(0.5*(d10_pow0*Vdseffp2_VDi_GND))));
    Ip2_VSi_GND=((gain2*alpha2)*((Vdsatp2_VSi_GND*Vdseffp2+Vdsatp2*Vdseffp2_VSi_GND)-(0.5*(d10_pow0*Vdseffp2_VSi_GND))));
    Ip2=((gain2*alpha2)*((Vdsatp2*Vdseffp2)-(0.5*d00_pow0)));
  }
  {
    double d00_exp0 = exp(((Vgsi-Vthi1)/(m1*0.026)));
  #define d10_exp0 d00_exp0
    Iss1_VDi_GND=(Io1_VDi_GND*d00_exp0+Io1*((-Vthi1_VDi_GND)/(m1*0.026))*d10_exp0);
    Iss1_VSi_GND=(Io1_VSi_GND*d00_exp0+Io1*((Vgsi_VSi_GND-Vthi1_VSi_GND)/(m1*0.026))*d10_exp0);
    Iss1_VG_GND=(Io1*(Vgsi_VG_GND/(m1*0.026))*d10_exp0);
    Iss1=(Io1*d00_exp0);
  }
  {
    double d00_exp0 = exp(((Vgsi-Vthi2)/(m2*0.026)));
  #define d10_exp0 d00_exp0
    Iss2_VDi_GND=(Io2_VDi_GND*d00_exp0+Io2*((-Vthi2_VDi_GND)/(m2*0.026))*d10_exp0);
    Iss2_VSi_GND=(Io2_VSi_GND*d00_exp0+Io2*((Vgsi_VSi_GND-Vthi2_VSi_GND)/(m2*0.026))*d10_exp0);
    Iss2_VG_GND=(Io2*(Vgsi_VG_GND/(m2*0.026))*d10_exp0);
    Iss2=(Io2*d00_exp0);
  }
  Ist1_VDi_GND=(((Iss1_VDi_GND*Ip1+Iss1*Ip1_VDi_GND)-(Iss1*Ip1)/(Iss1+Ip1)*(Iss1_VDi_GND+Ip1_VDi_GND))/(Iss1+Ip1));
  Ist1_VSi_GND=(((Iss1_VSi_GND*Ip1+Iss1*Ip1_VSi_GND)-(Iss1*Ip1)/(Iss1+Ip1)*(Iss1_VSi_GND+Ip1_VSi_GND))/(Iss1+Ip1));
  Ist1_VG_GND=(((Iss1_VG_GND*Ip1)-(Iss1*Ip1)/(Iss1+Ip1)*Iss1_VG_GND)/(Iss1+Ip1));
  Ist1=((Iss1*Ip1)/(Iss1+Ip1));
  Ist2_VDi_GND=(((Iss2_VDi_GND*Ip2+Iss2*Ip2_VDi_GND)-(Iss2*Ip2)/(Iss2+Ip2)*(Iss2_VDi_GND+Ip2_VDi_GND))/(Iss2+Ip2));
  Ist2_VSi_GND=(((Iss2_VSi_GND*Ip2+Iss2*Ip2_VSi_GND)-(Iss2*Ip2)/(Iss2+Ip2)*(Iss2_VSi_GND+Ip2_VSi_GND))/(Iss2+Ip2));
  Ist2_VG_GND=(((Iss2_VG_GND*Ip2)-(Iss2*Ip2)/(Iss2+Ip2)*Iss2_VG_GND)/(Iss2+Ip2));
  Ist2=((Iss2*Ip2)/(Iss2+Ip2));
  Ist_VDi_GND=(Ist1_VDi_GND+Ist2_VDi_GND);
  Ist_VSi_GND=(Ist1_VSi_GND+Ist2_VSi_GND);
  Ist_VG_GND=(Ist1_VG_GND+Ist2_VG_GND);
  Ist=(Ist1+Ist2);

  sys->setIQ(Di,Si,(Iat+Ist),0);
  sys->setGC(Di,Si,G,GND,(Iat_VG_GND+Ist_VG_GND),0);
  sys->setGC(Di,Si,Si,GND,(Iat_VSi_GND+Ist_VSi_GND),0);
  sys->setGC(Di,Si,Di,GND,(Iat_VDi_GND+Ist_VDi_GND),0);
}



// --------------------------------------------------------------
// component definition
EXPORT tComponentInfo compInfo = {
  isNonLinear,                // component type ('isNonLinear' or 'isLinear')
  "nmos",                // model identifier
  "VerilogAMS model of nmos",  // component description
  3,                          // number of external nodes
  2+0,                        // number of internal nodes
  0,                          // number of inputs (system simulations only)
  16,                         // number of parameters
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
