import sys
import os
import numpy as np
import shutil

var = np.zeros(5)

jobID = sys.argv[1]
var_type = sys.argv[2]

var[0] = sys.argv[3]
var[1] = sys.argv[4]
var[2] = sys.argv[5]
var[3] = sys.argv[6]
var[4] = sys.argv[7]

original_umask = os.umask(0)

#make new directory for results
for i in range(len(var)):
    
    newpath = r'/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/'+var_type+'-'+str(jobID)+''
    if not os.path.exists(newpath):
        os.mkdir(newpath, 0o755)

    newpath2 = r'/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/'+var_type+'-'+str(jobID)+'/'+str(int(var[i]))+''
    if not os.path.exists(newpath2):
        os.mkdir(newpath2, 0o755)

    #move ts_aerosol_case#_time.nc files to newly created directory
    # Source path 
    source = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/APCEMM_out/'
    slurm_dir = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/'

    # Destination path 
    destination = '/home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/'+var_type+'-'+str(jobID)+'/'+str(int(var[i]))+'/'
    
    # Move the content of source to destination
    for file in sorted(os.listdir(source)):
        if (file.startswith("ts_aerosol_case"+str(i)) and file.endswith(".nc")):
            shutil.move(source+file, destination)
        if (file.startswith("slurm_"+str(jobID))):
            shutil.move(slurm_dir+file, destination)


