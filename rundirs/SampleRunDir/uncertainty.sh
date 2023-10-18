#!/bin/bash                                   

#SBATCH --time=24:00:00
#SBATCH --job-name="RH Met Profile"
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
x1=0.009
x2=0.2

echo "APCEMM Sensitivity: RH Met Profile"
echo "Job ID: $job_id"
echo "Soot Particle Number: $x1"
echo "Sulfur Fuel Content: $x2"



echo "Editing YAML file: Meteorological Path"

#Changing input.yaml file with new inputs and saving unique copy
. /etc/profile.d/conda.sh
conda activate contrails
python /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/updateYAML.py $job_id $x1 $x2

echo "Ready to start"

now=$(date +"%T")
echo "Start time : $now"

echo "Number of CPUs per task: $SLURM_CPUS_PER_TASK"

cd /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir

./../../Code.v05-00/APCEMM 'inputs/input-'$job_id'.yaml'

now=$(date +"%T")
echo "End time : $now"

export job_id
sbatch --dependency=afterany:$job_id /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/relocate.sh $job_id