#!/usr/bin/python

import yaml
import sys
import numpy as np
from importlib.abc import Loader
import os
import shutil
loader=yaml.Loader

job_id = sys.argv[1]
path_str = sys.argv[10]
submenu_str = sys.argv[11]

#make new YAML file (copy w jobid)
source = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/input.yaml'
destination = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/input-'+str(job_id)+'.yaml'

shutil.copyfile(source,destination)

length = len(sys.argv)
var_array = np.zeros(5)
Temperature = float(sys.argv[3])
Pressure = float(sys.argv[4])
var_str = str(sys.argv[5])

#Make directory to store output files without overwriting
resultdir = r'/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/APCEMM_out/'+str(job_id)

if not os.path.exists(resultdir):
    os.mkdir(resultdir, 0o755)

#Update YAML file parameters
for i in range(0,4):
    var_str += " "+sys.argv[i+6]

with open('/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/input-'+str(job_id)+'.yaml') as istream:
    ymldoc = yaml.unsafe_load(istream)
    ymldoc['SIMULATION MENU']['OUTPUT SUBMENU']['Output folder (string)'] = str("APCEMM_out/"+str(job_id)+"/")
    ymldoc['PARAMETER MENU']['METEOROLOGICAL PARAMETERS SUBMENU']['Temperature [K] (double)'] = Temperature
    ymldoc['PARAMETER MENU']['METEOROLOGICAL PARAMETERS SUBMENU']['Pressure [hPa] (double)'] = Pressure
    
    if submenu_str=="none":
        ymldoc['PARAMETER MENU'][path_str] = var_str
    else:
        ymldoc['PARAMETER MENU'][submenu_str][path_str] = var_str

with open('/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/input-'+str(job_id)+'.yaml', "w") as ostream:
    yaml.dump(ymldoc, ostream, default_flow_style=False, sort_keys=False)