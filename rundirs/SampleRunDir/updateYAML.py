#!/usr/bin/python

import yaml
import sys
import numpy as np
from importlib.abc import Loader
import os
import shutil
loader=yaml.Loader
#sys.path.append('/home/chinahg/GCresearch/contrailuncertainty/exPCE.ipynb')
#import exPCE.ipynb

job_id = sys.argv[1]
soot_EI = sys.argv[2]
sulfur_fc = sys.argv[3]

#make new YAML file (copy w jobid)
source = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/input.yaml'
destination = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/input-'+str(job_id)+'.yaml'

shutil.copyfile(source,destination)

####################################################################
### CAN EDIT FOR EACH RUN, MUST ALSO EDIT IN /home/chinahg/GCresearch/contrailuncertainty/const_area_met_run.ipynb ###
####################################################################
max_RH = 130 #130%
moist_layer_depth = 1 # [km]
shape = "rect" #profile shape
####################################################################

area = str(max_RH*moist_layer_depth) # area above 100% RH
met_name = "met_" + shape + "_" + str(max_RH)
print(met_name)

#Make directory to store output files without overwriting
resultdir = r'/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/APCEMM_out/'+str(job_id)

if not os.path.exists(resultdir):
    os.mkdir(resultdir, 0o755)

#Update YAML file parameters
with open('/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/input-'+str(job_id)+'.yaml') as istream:
    ymldoc = yaml.unsafe_load(istream)
    ymldoc['SIMULATION MENU']['OUTPUT SUBMENU']['Output folder (string)'] = str("APCEMM_out/"+str(job_id)+"/")
    ymldoc['PARAMETER MENU']['Soot [g/kg_fuel] (double)'] = soot_EI
    ymldoc['PARAMETER MENU']['SO2 [g/kg_fuel] (double)'] = sulfur_fc
    ymldoc["METEOROLOGY MENU"]["METEOROLOGICAL INPUT SUBMENU"]["Met input file path (string)"] = '/home/chinahg/GCresearch/APCEMM/examples/Example3_met_input/example_met_file.nc' #'/home/chinahg/GCresearch/contrailuncertainty/APCEMM_results/' + met_name +'.nc'

with open('/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/input-'+str(job_id)+'.yaml', "w") as ostream:
    yaml.dump(ymldoc, ostream, default_flow_style=False, sort_keys=False)