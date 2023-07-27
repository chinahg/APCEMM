#!/bin/bash                                   

#SBATCH --time=24:00:00
#SBATCH --job-name="Soot Radius"
#SBATCH --mail-user=chinahg@mit.edu
#SBATCH --mail-type=END
#SBATCH -o /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/slurm-%j.out
#xSBATCH -e slurm-%j.err
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=normal
#SBATCH --mem=5000MB
#####################################

job_id=$SLURM_JOBID
var_in="SootRadius"

#if no submenu (as for soot radius variable) set submenu_str to "none"
submenu_str="none"
varloc_str="Soot Radius [m] (double)"

echo "APCEMM Sensitivity: Soot Radius"
echo "Job ID: $job_id"

#Variable values for run
var1=1.0e-8
var2=3.0e-8
var3=5.0e-8
var4=10.0e-8
var5=20.0e-8

echo "Editing YAML file: Temperature and Pressure"
Altitude=37500 #[m]
Temperature=171.96 #[K]
Pressure=344.5 #[hPa]
echo "Altitude: $Altitude m"

#Changing input.yaml file with new inputs
#Also: create folder for specific job to store output files (so they are not overwritten)
python /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/updateYAML.py $job_id $var_in $Temperature $Pressure $var1 $var2 $var3 $var4 $var5 "$varloc_str" "$submenu_str"

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
