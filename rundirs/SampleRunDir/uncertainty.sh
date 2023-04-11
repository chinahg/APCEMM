#!/bin/bash                                   

#SBATCH --time=24:00:00
#SBATCH --job-name="Horizontal Diffusion Coefficient"
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
var_in="HorizontalDiff"

echo "APCEMM Sensitivity: Horizontal Diffusion Coefficient"
echo "Job ID: $job_id"

#Variable values for run
var1=15
var2=48.75
var3=82.5
var4=116.25
var5=150

echo "Editing YAML file: Temperature and Pressure"
Altitude=37500 #[m]
echo "Altitude: $Altitude m"
Temperature=171.96 #[K]
Pressure=344.5 #[hPa]

#Changing input.yaml file with new inputs
python /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/updateYAML.py $job_id $var_in $Temperature $Pressure $var1 $var2 $var3 $var4 $var5

echo "Ready to start"

now=$(date +"%T")
echo "Start time : $now"

echo "Number of CPUs per task: $SLURM_CPUS_PER_TASK"
./../../Code.v05-00/APCEMM /inputs/input-$job_id.yaml

now=$(date +"%T")
echo "End time : $now"

wait

. /etc/profile.d/conda.sh
conda activate lae2022
python /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/slurm_save.py $job_id $var_in $var1 $var2 $var3 $var4 $var5
