#!/bin/bash                                   

#SBATCH --time=24:00:00
#SBATCH --job-name="RH Met Profile"
#SBATCH --mail-user=chinahg@mit.edu
#SBATCH --mail-type=BEGIN,END
#SBATCH -o /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/slurm-%j.out
#xSBATCH -e slurm-%j.err
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=normal
#SBATCH --mem=50000MB
#####################################

job_id=$SLURM_JOBID
var_in=$RHprofile

echo "APCEMM Sensitivity: RH Met Profile"
echo "Job ID: $job_id"


# echo "Editing YAML file: Temperature and Pressure"
# Altitude=$337500 #[m]
# echo "Altitude: $Altitude m"
# Temperature=$4171.96 #[K]
# Pressure=$5344.5 #[hPa]

# #Changing input.yaml file with new inputs
# python /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/updateYAML.py $Temperature $Pressure

echo "Ready to start"

now=$(date +"%T")
echo "Start time : $now"

echo "Number of CPUs per task: $SLURM_CPUS_PER_TASK"

cd /home/chinahg/GCresearch/APCEMM/examples/Example3_met_input

./../../Code.v05-00/APCEMM input.yaml

now=$(date +"%T")
echo "End time : $now"

export var_in
export job_id
sbatch --dependency=afterany:$job_id /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/relocate.sh