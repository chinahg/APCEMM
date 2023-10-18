import sys
import os
import numpy as np
import shutil

jobID = sys.argv[1]

original_umask = os.umask(0)

#make new directory for results
newpath = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/'+str(jobID)+'/'

if not os.path.exists(newpath):
    os.mkdir(newpath, 0o755)

#move ts_aerosol_case#_time.nc files to newly created directory
# Source path
source = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/APCEMM_out/'
source_out = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/'

# Destination path 
destination = newpath

# Move the content of source to destination 
for file in sorted(os.listdir(source)):
    if (file.startswith("ts_aerosol_case0") and file.endswith(".nc")):
        print(file)
        shutil.move(source+file, destination)
    
    if (file.startswith("slurm-" + jobID) and file.endswith(".out")):
        print(file)
        shutil.move(source_out+file, destination)