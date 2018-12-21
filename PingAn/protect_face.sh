#!/bin/bash
#make up path
current_pth=$(pwd)
current_pth="${current_pth}/rpc_server/build"
while [ 1 ]
do
	#fetch run process
	run_ports=`ps -ef | grep face_server | grep -v grep | \
	    awk '{print $9}'|\
	    awk -F '_' '{print $4}'|\
	    awk -F '.' '{print $1}'`
	echo ${run_ports}

	#fetch envolupmet port
	port_list=`echo $RPC_PORT_LIST`
	port_list=${port_list//,/ }
	echo ${port_list}

	#find miss port 
	for del in ${run_ports[@]}
	do
		port_list=("${port_list[@]/$del}")

		#echo ${del}
	done

	for ele in ${port_list[@]}
	do
		run_script="./start_${ele}.sh"
		cd ${current_pth} && sh ${run_script}
		#echo  $run_script
		sleep 10s
	done
	sleep 15s
done

