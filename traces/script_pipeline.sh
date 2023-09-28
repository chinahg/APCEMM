#!/bin/bash

run_alternatives="true"
yr=2010

trace_dir='traces/'

# Make sure we have the directories we need
for d in APCEMM AFCA $trace_dir; do
    if [[ ! -d $d ]]; then
        echo "Directory $d not present or linked"
        exit 101
    fi
done

expt_id='contrails'

# Run the script generation steps first
source /opt/conda/bin/activate gcpy1.3
python3 AFCA_pipeline.py --AFCA AFCA --APCEMM APCEMM --cases $@ --outdir $trace_dir --steps 4 6 --year ${yr} --combo --exptid=$expt_id

# Need somewhere to store slurm output
if [[ ! -d logs ]]; then
    mkdir logs
fi

ks=kill_script.sh
ks=$( readlink -f $ks )
echo "#!/bin/bash" >> $ks
for casenum in $@; do
   # Data download and merge is agnostic of case/experiment
   jid_preproc=$( sbatch --parsable script_dl.sh $casenum )
   cd AFCA
   jid_AFCA=$( sbatch -J AFCA_y${yr}_c${casenum} --parsable --dependency=afterok:$jid_preproc scripts/run_y${yr}_${expt_id}_c${casenum}.sh )
   cd ..
   jid_trace=$( sbatch --parsable --dependency=afterok:$jid_AFCA script_trace.sh $expt_id $casenum )
   cd APCEMM
   jid_APCEMM=$( sbatch -J APCEMM_y${yr}_c${casenum} --parsable --dependency=afterok:$jid_trace scripts/run_y${yr}_${expt_id}_c${casenum}.sh )
   kline="scancel $jid_preproc $jid_AFCA $jid_trace $jid_APCEMM "
   if [[ "$run_alternatives" == "true" ]]; then
       for APCEMMopts in '_nearest' '_nearest_absshear' '_fixed' '_fixed_nearest' '_fixed_nearest_absshear'; do
           jid_APCEMM=$( sbatch -J APCEMM${APCEMMopts}_y${yr}_c${casenum} --parsable --dependency=afterok:$jid_trace scripts/run_y${yr}_${expt_id}_c${casenum}${APCEMMopts}.sh )
           kline="$kline $jid_APCEMM"
       done
   fi
   cd ..
   echo $kline >> $ks
done
