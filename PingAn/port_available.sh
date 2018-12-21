#!/bin/bash
ports=$(netstat -nltp |awk '{print $4}'|awk -F ":" '{print $2}')
env_port=$(echo ${RPC_PORT_LIST})
env_port=${env_port//,/ }
c_echo(){
    RED="\033[0;31m"
    GREEN='\033[0;32m'
    YELLOW='\033[1;33m'
    NC='\033[0m' # No Color

    printf "${!1}${2} ${NC}\n"
}
ENV_PORT_LIST=""

for port in ${env_port[@]}
do
    if printf '%s\n' ${ports[@]}|grep -q -P ${port};then
	ser_str="face_service_cfg_"
	ser_str+="${port}"
	ps_status=$(ps -ef |grep ${ser_str} |grep -v grep|awk '{print $2}')
	if ((${ps_status}));then
	    c_echo "GREEN" "exit this face server :PID::${ps_status}"
	    ((port++))
	else
	    c_echo "RED" "change env port c"
	    #((port++))
		
	fi
	

	c_echo "YELLOW" "error exit port:${port}"
    fi
    ENV_PORT_LIST+="${port},"

done	
#iecho "${x%?}"
ENV_PORT_LIST=$(echo "${ENV_PORT_LIST%?}")
echo ${ENV_PORT_LIST}
export RPC_PORT_LIST="${ENV_PORT_LIST}"
echo "env modify"
echo ${RPC_PORT_LIST}




