#!/bin/bash


#dock_snmpd part
docker cp testing_snmpd:/new_snmpd_test/batteryAgentSubagentObject.c dock_snmpd/
docker cp testing_snmpd:/new_snmpd_test/batteryAgentSubagentObject.c dock_snmpd/
docker cp testing_snmpd:/new_snmpd_test/Makefile dock_snmpd/
docker cp testing_snmpd:/new_snmpd_test/example-daemon.c dock_snmpd/
docker cp testing_snmpd:/new_snmpd_test/nstAgentSubagentObject.c dock_snmpd/
docker cp testing_snmpd:/new_snmpd_test/nstAgentSubagentObject.h dock_snmpd/
docker cp testing_snmpd:/usr/share/snmp/mibs/MY-TUTORIAL-MIB.txt dock_snmpd/
docker cp testing_snmpd:/usr/share/snmp/mibs/NET-SNMP-TUTORIAL-MIB.txt dock_snmpd/
docker cp testing_snmpd:/etc/snmp/snmpd.conf dock_snmpd/


#dock_test part
docker cp testing_snmpd:/usr/share/snmp/mibs/MY-TUTORIAL-MIB.txt dock_test/
docker cp testing_snmpd:/usr/share/snmp/mibs/NET-SNMP-TUTORIAL-MIB.txt dock_test/



































echo "Take a rest, it is backed up..."
sleep 3
echo "!WAIT!"
sleep 1.5
echo "What?"
sleep 1.5
echo "What what? WHAT ABOUT GIT BACKUP?!"
sleep 2
echo "HO... the real backup..."
sleep 2
echo "you're right, thanks"
sleep 0.5
echo "OF COURE I'M RIGHT!"
sleep 1.5
echo "and no Problem... :)"
sleep 1
echo "."
sleep 1
echo "."
sleep 1
echo "."
sleep 2.5
echo "Go on now, git backup."

