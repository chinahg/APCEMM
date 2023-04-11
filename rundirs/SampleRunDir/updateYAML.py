#!/usr/bin/python

import yaml
import sys
import numpy as np
from importlib.abc import Loader
import os
import shutil
loader=yaml.Loader

job_id = sys.argv[1]
print(sys.argv)
#make new YAML file (copy w jobid)
source = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/input.yaml'
destination = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/input-'+str(job_id)+'.yaml'

shutil.copyfile(source,destination)

length = len(sys.argv)
var_array = np.zeros(5)
Temperature = float(sys.argv[3])
Pressure = float(sys.argv[4])
var_str = str(sys.argv[5])

for i in range(0,4):
    var_str += " "+sys.argv[i+6]

print(var_str)

with open('/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/inputs/input-'+str(job_id)+'.yaml') as istream:
    ymldoc = yaml.unsafe_load(istream)
    ymldoc['PARAMETER MENU']['METEOROLOGICAL PARAMETERS SUBMENU']['Temperature [K] (double)'] = Temperature
    ymldoc['PARAMETER MENU']['METEOROLOGICAL PARAMETERS SUBMENU']['Pressure [hPa] (double)'] = Pressure
    ymldoc['PARAMETER MENU']['METEOROLOGICAL PARAMETERS SUBMENU']['Horiz. diff. coeff. [m^2/s] (double)'] = var_str

with open("input.yaml", "w") as ostream:
    yaml.dump(ymldoc, ostream, default_flow_style=False, sort_keys=False)