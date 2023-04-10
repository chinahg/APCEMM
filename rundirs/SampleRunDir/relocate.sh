#!/bin/bash                                   

#SBATCH --time=00:10:00
#SBATCH --job-name="relocate"
#SBATCH --mail-type=BEGIN,END
#xSBATCH -e slurm-%j.err
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=normal
#SBATCH --mem=50000MB
#####################################

. /etc/profile.d/conda.sh
conda activate lae2022

var1=$315.0
var2=$448.75
var3=$582.5
var4=$6116.25
var5=$7150.0

python /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/slurm_save.py $job_id $var_in $var1 $var2 $var3 $var4 $var5
