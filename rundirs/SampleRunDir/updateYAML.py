#!/usr/bin/python

import yaml
import sys
import numpy as np
from importlib.abc import Loader

loader=yaml.Loader

Temperature = float(sys.argv[1])
Pressure = float(sys.argv[2])

with open("input.yaml") as istream:
    ymldoc = yaml.unsafe_load(istream)
    ymldoc['PARAMETER MENU']['METEOROLOGICAL PARAMETERS SUBMENU']['Temperature [K] (double)'] = Temperature
    ymldoc['PARAMETER MENU']['METEOROLOGICAL PARAMETERS SUBMENU']['Pressure [hPa] (double)'] = Pressure

with open("input.yaml", "w") as ostream:
    yaml.dump(ymldoc, ostream, default_flow_style=False, sort_keys=False)