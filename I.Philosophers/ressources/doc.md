
eat		200
sleep 	100

E == 100
S == 100
T = ?

P1:	EE|ST|EE|ST ...
P2:	- |EE|ST|EE ...

philo : eat -> sleep -> think

eat == sleep + think
think = eat - sleep.

---------------------------------------

eat		100
sleep 	100

E == 100
S == 100
T =  a une valeur "insignifiante" = 0

P1:	E|S|E|S|
P2:	-|E|S|E
------------------------------------


eat		100
sleep 	200

E == 100
S == 100
T = a une valeur "insignifiante" = 0

P1: ESSESS
P2:	 ESSESS

--------------------------------------
philo : eat -> sleep -> think

philo : checkDeath -> take_fork_1 -> checkDeath -> take_fork_2 -> checkDeath -> S|eat|E -> checkDeath -> S|sleep|E -> think
		 			*							*					        	#######					 *||    |*    