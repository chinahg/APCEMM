/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/*     Aircraft Plume Chemistry, Emission and Microphysics Model    */
/*                             (APCEMM)                             */
/*                                                                  */
/* Monitor Header File                                              */
/*                                                                  */
/* Author               : Thibaud M. Fritz                          */
/* Time                 : 7/26/2018                                 */
/* File                 : Monitor.h                                 */
/* Working directory    : /home/fritzt/APCEMM-SourceCode            */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifndef MONITOR_H_INCLUDED
#define MONITOR_H_INCLUDED

#include <string>

/* Names of chemical species */

const char *speciesSet_KPP[] = {\
"CO2","PPN","BrNO2","IEPOX","PMNN","N2O","N","PAN",\
"ALK4","MAP","MPN","Cl2O2","ETP","HNO2","C3H8","RA3P",\
"RB3P","OClO","ClNO2","ISOP","HNO4","MAOP","MP","ClOO",\
"RP","BrCl","PP","PRPN","SO4","Br2","ETHLN","MVKN",\
"R4P","C2H6","RIP","VRP","ATOOH","IAP","DHMOB","MOBA",\
"MRP","N2O5","ISNOHOO","ISNP","ISOPNB","IEPOXOO","MACRNO2","ROH",\
"MOBAOO","DIBOO","PMN","ISNOOB","INPN","H","BrNO3","PRPE",\
"MVKOO","Cl2","ISOPND","HOBr","A3O2","PROPNN","GLYX","MAOPO2",\
"CH4","GAOO","B3O2","ACET","MACRN","CH2OO","MGLYOO","VRO2",\
"MGLOO","MACROO","PO2","CH3CHOO","MAN2","ISNOOA","H2O2","PRN1",\
"ETO2","KO2","RCO3","HC5OO","GLYC","ClNO3","RIO2","R4N1",\
"HOCl","ATO2","HNO3","ISN1","MAO3","MRO2","INO2","HAC",\
"HC5","MGLY","ISOPNBO2","ISOPNDO2","R4O2","R4N2","BrO","RCHO",\
"MEK","ClO","MACR","SO2","MVK","ALD2","MCO3","CH2O",\
"H2O","Br","NO","NO3","Cl","O","O1D","O3",\
"HO2","NO2","OH","HBr","HCl","CO","MO2","ACTA",\
"EOH","H2","HCOOH","MOH","N2","O2","RCOOH"};

/* Names of chemical species in liquid/solid form */

const char *speciesSet_LS[] = {\
"SO4L","H2OL","H2OS","HNO3L","HNO3S","HClL","HOClL","HBrL","HOBrL"};

/* Names of aerosols */

const char *aerosolSet[] = {"Soot","SLA","SPA"};

/* Index declaration for variable species */

#define ind_CO2              0          
#define ind_PPN              1          
#define ind_BrNO2            2          
#define ind_IEPOX            3          
#define ind_PMNN             4          
#define ind_N2O              5          
#define ind_N                6          
#define ind_PAN              7          
#define ind_ALK4             8          
#define ind_MAP              9          
#define ind_MPN              10         
#define ind_Cl2O2            11         
#define ind_ETP              12         
#define ind_HNO2             13         
#define ind_C3H8             14         
#define ind_RA3P             15         
#define ind_RB3P             16         
#define ind_OClO             17         
#define ind_ClNO2            18         
#define ind_ISOP             19         
#define ind_HNO4             20         
#define ind_MAOP             21         
#define ind_MP               22         
#define ind_ClOO             23         
#define ind_RP               24         
#define ind_BrCl             25         
#define ind_PP               26         
#define ind_PRPN             27         
#define ind_SO4              28         
#define ind_Br2              29         
#define ind_ETHLN            30         
#define ind_MVKN             31         
#define ind_R4P              32         
#define ind_C2H6             33         
#define ind_RIP              34         
#define ind_VRP              35         
#define ind_ATOOH            36         
#define ind_IAP              37         
#define ind_DHMOB            38         
#define ind_MOBA             39         
#define ind_MRP              40         
#define ind_N2O5             41         
#define ind_ISNOHOO          42         
#define ind_ISNP             43         
#define ind_ISOPNB           44         
#define ind_IEPOXOO          45         
#define ind_MACRNO2          46         
#define ind_ROH              47         
#define ind_MOBAOO           48         
#define ind_DIBOO            49         
#define ind_PMN              50         
#define ind_ISNOOB           51         
#define ind_INPN             52         
#define ind_H                53         
#define ind_BrNO3            54         
#define ind_PRPE             55         
#define ind_MVKOO            56         
#define ind_Cl2              57         
#define ind_ISOPND           58         
#define ind_HOBr             59         
#define ind_A3O2             60         
#define ind_PROPNN           61         
#define ind_GLYX             62         
#define ind_MAOPO2           63         
#define ind_CH4              64         
#define ind_GAOO             65         
#define ind_B3O2             66         
#define ind_ACET             67         
#define ind_MACRN            68         
#define ind_CH2OO            69         
#define ind_MGLYOO           70         
#define ind_VRO2             71         
#define ind_MGLOO            72         
#define ind_MACROO           73         
#define ind_PO2              74         
#define ind_CH3CHOO          75         
#define ind_MAN2             76         
#define ind_ISNOOA           77         
#define ind_H2O2             78         
#define ind_PRN1             79         
#define ind_ETO2             80         
#define ind_KO2              81         
#define ind_RCO3             82         
#define ind_HC5OO            83         
#define ind_GLYC             84         
#define ind_ClNO3            85         
#define ind_RIO2             86         
#define ind_R4N1             87         
#define ind_HOCl             88         
#define ind_ATO2             89         
#define ind_HNO3             90         
#define ind_ISN1             91         
#define ind_MAO3             92         
#define ind_MRO2             93         
#define ind_INO2             94         
#define ind_HAC              95         
#define ind_HC5              96         
#define ind_MGLY             97         
#define ind_ISOPNBO2         98         
#define ind_ISOPNDO2         99         
#define ind_R4O2             100        
#define ind_R4N2             101        
#define ind_BrO              102        
#define ind_RCHO             103        
#define ind_MEK              104        
#define ind_ClO              105        
#define ind_MACR             106        
#define ind_SO2              107        
#define ind_MVK              108        
#define ind_ALD2             109        
#define ind_MCO3             110        
#define ind_CH2O             111        
#define ind_H2O              112        
#define ind_Br               113        
#define ind_NO               114        
#define ind_NO3              115        
#define ind_Cl               116        
#define ind_O                117        
#define ind_O1D              118        
#define ind_O3               119        
#define ind_HO2              120        
#define ind_NO2              121        
#define ind_OH               122        
#define ind_HBr              123        
#define ind_HCl              124        
#define ind_CO               125        
#define ind_MO2              126        

/* Index declaration for fixed species */

#define ind_ACTA             127        
#define ind_EOH              128        
#define ind_H2               129        
#define ind_HCOOH            130        
#define ind_MOH              131        
#define ind_N2               132        
#define ind_O2               133        
#define ind_RCOOH            134        

/* Index declaration for fixed species in FIX */

#define indf_ACTA            0          
#define indf_EOH             1          
#define indf_H2              2          
#define indf_HCOOH           3          
#define indf_MOH             4          
#define indf_N2              5          
#define indf_O2              6          
#define indf_RCOOH           7          

#endif /* MONITOR_H_INCLUDED */