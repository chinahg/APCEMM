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

python /home/chinahg/GCresearch/APCEMM/rundirs/SampleRunDir/slurm/slurm_save.py $job_id $var_in