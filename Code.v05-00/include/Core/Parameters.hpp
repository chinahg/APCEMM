/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/*     Aircraft Plume Chemistry, Emission and Microphysics Model    */
/*                             (APCEMM)                             */
/*                                                                  */
/* Parameter Header File                                            */
/*                                                                  */
/* Author               : Thibaud M. Fritz                          */
/* Time                 : 7/26/2018                                 */
/* File                 : Parameters.hpp                            */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifndef PARAMETERS_H_INCLUDED
#define PARAMETERS_H_INCLUDED

/* How to handle multithreading?
 * 1. Each cases are run in parallel (efficient for low-requirement runs)
 * 2. Each case is run one at a time on multiple CPUs (efficient for contrail
 *    simulations) */

extern int PARALLEL_CASES;

/* Grid parameters */

/* Choose grid for simulation */

/* 1. Regular grid for zero shear: */

//#define NX                256         /* Number of grid cells in the x-direction */
//#define NY                256         /* Number of grid cells in the y-direction */
//#define XLIM              6.50E+03    /* x-limits of the domain [m] */
//#define YLIM_UP           6.50E+02    /* Upper y-limit of the domain [m] */
//#define YLIM_DOWN         6.50E+02    /* Lower y-limit of the domain [m] */

/* 2. Reduced regular grid for non-zero shear: */

//#define NX                512         /* Number of grid cells in the x-direction */
//#define NY                256         /* Number of grid cells in the y-direction */
//#define XLIM              3.00E+04    /* x-limits of the domain [m] */
//#define YLIM_UP           6.50E+02    /* Upper y-limit of the domain [m] */
//#define YLIM_DOWN         6.50E+02    /* Lower y-limit of the domain [m] */

/* 3. Fine regular grid for non-zero shear: */

#define NX 2655 //1024 /* Number of grid cells in the x-direction */
#define NY 1937 //256 /* Number of grid cells in the y-direction */
#define XLIM_RIGHT              1.00E+04    /* x-limits of the domain [m] */
#define XLIM_LEFT 1.49e+05 /* x-limits of the domain [m] */
#define YLIM_UP 6.50e+02 /* Upper y-limit of the domain [m] */
#define YLIM_DOWN 9.03e+03 /* Lower y-limit of the domain [m] */

/* 4. Fine and extended grid for contrail simulation: */

//#define NX                1024        /* Number of grid cells in the x-direction */
//#define NY                256         /* Number of grid cells in the y-direction */
//#define XLIM              4.00E+04    /* x-limits of the domain [m] */
//#define YLIM_UP           8.00E+02    /* Upper y-limit of the domain [m] */
//#define YLIM_DOWN         9.00E+02    /* Lower y-limit of the domain [m] */

//#define NX                2048        /* Number of grid cells in the x-direction */
//#define NY                1024        /* Number of grid cells in the y-direction */
//#define XLIM              4.00E+04    /* x-limits of the domain [m] */
//#define YLIM_UP           1.40E+03    /* Upper y-limit of the domain [m] */
//#define YLIM_DOWN         1.50E+03    /* Lower y-limit of the domain [m] */

#define NYH               NY/2 + 1
#define NCELL             NX*NY       /* Number of grid cells */


/* Coarse aerosol representation */
#define LA_VRAT               1.50E+00 // 1.80E+00    /* Size ratio between two consecutive bins */
#define PA_VRAT               1.50E+00 // 1.80E+00    /* Size ratio between two consecutive bins */

/* Fine aerosol representation */
//#define LA_VRAT               1.50E+00    /* Size ratio between two consecutive bins */
//#define PA_VRAT               1.30E+00    /* Size ratio between two consecutive bins */



/* Ring structure */
#define NRING             15          /* Number of rings */

/* Atmospheric parameters */
#define GAMMA            -3.0E+00     /* Ambient temperature lapse rate [K/km] */
#define TROPP             2.0E+04     /* Pressure at the tropopause [Pa] */

/* Diffusion */
/* The following parameters are now passed as user input parameters */
//#define DH                1.5E+01     /* Steady-state horizontal diffusion parameter [m2/s] */
//#define DV                1.5E-01     /* Steady-state vertical diffusion parameter [m2/s] */
//#define DH0               1.7E+01     /* Initial horizontal diffusion parameter [m2/s] */
//#define DV0               1.1E-01     /* Initial vertical diffusion parameter [m2/s] */
#define tH0               7.8E+02     /* Timescale of initial enhanced horizontal diffusion [s] */
#define tV0               7.8E+02     /* Timescale of initial enhanced vertical diffusion [s] */
#define DPROF             1           /* Time profile of the initial diffusion parameter [0,1,2]
                                       * 0: Step
                                       * 1: Linear
                                       * 2: Exponential
                                       */

/* Advection  */
#define VX                0.0E+00     /* Steady-state horizontal advection velocity [m/s] */
#define VY                0.0E+00     /* Steady-state vertical advection velocity [m/s] */
//T_SYN and V_SYN are now defined in the input file
//#define T_SYN             3.6E+03     /* Timescale associated to synoptic lifting */
//#define V_SYN             5.0E-02     /* Velocity magnitude [m/s] */
#define SYNPROF           1           /* Time profile of the initial synoptic lifting [0,1]
                                       * 0: Step
                                       * 1: Exponential
                                       */

/* Chemistry parameters */
#define KPP_RTOLS             1.00E-03    /* Relative tolerances in KPP */
#define KPP_ATOLS             1.00E-03    /* Absolute tolerances in KPP */
#define KPPADJ_RTOLS          1.00E-05    /* Relative tolerances in KPP_Adjoint */
#define KPPADJ_ATOLS          1.00E-04    /* Absolute tolerances in KPP_Adjoint */

/* Aerosol parameters */
#define N_AER                 3           /* Number of aerosols considered */
#define PSC_FULL              1           /* Allow PSC formaiton outsize of Kirner limits? */
#define LHOMNUCNAT            1           /* Allow homogeneous NAT? */
#define T_NAT_SUPERCOOL       3.0         /* NAT supercooling requirement [K] */
#define LSOLIDPSC             1           /* Online solid PSCs? */

/* Microphysics parameters */
#define LA_R_LOW              1.00E-10    /* Sulfates' lower bin radius [m] */
#define LA_R_HIG              5.00E-07    /* Sulfates' larger bin radius [m] */
#define PA_R_LOW              5.00E-08    /* Ice/NAT lower bin radius [m] */
#define PA_R_HIG              8.00E-05    /* Ice/NAT larger bin radius [m] */

/* Early plume integration */
#define VORTEX_SINKING        1           /* Consider vortex sinking? */
#define EPM_RTOLS             1.00E-05    /* Relative tolerances in EPM */
#define EPM_ATOLS             1.00E-07    /* Absolute tolerances in EPM */
#define SO2TOSO4              0.005       /* Percent conversion from SO2 to SO4 */
#define SATDEPTH_MIN          100         /* Minimum depth of saturation depth if loading met [m] */

#endif /* PARAMETERS_H_INCLUDED */
