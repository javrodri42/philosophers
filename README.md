# philosophers

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/javrodri/Philosophers)](https://github.com/JaeSeoKim/badge42)

## Conditions
* n philosophers sitting at a round table doing one of three things
	* Eating,
	* Thinking,
	* Sleeping,

* A large bowl of spaghetti in the center of the round table.
* Some forks on the table
* Need 2 forks, one for each hand.
* The philosophers mmust never be starving.
* Every philosopher needs to eat.
* Philosophers dont spea'k each others, and don´t know when another philosopher is about to die.
* Each time a philosopher has finished to eat, he will drop his forks an start sleeping.
* When  a philosopher is done sleeping, he will start thinking.
* The simulations stop when a philosopher dies.
* Each program should have the same options:
	* number-of-philosophers: _The number of philosophers and also the number of forks_
	* time-to-die: _In miliseconds, if a philo doesn't start eating 'time-to-die' miliseconds after starting his last meal or the beginning of the simulation, it dies._
	* time-to-eat: _Is in miliseconds, and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks._
	* time-to-sleep: _Miliseconds and is the time the philosopher will spend sleeping._
	* number-of-times-each-philosopher-must-eat: _Argument is optional, if all philosophers eat at least the argument number, the simulation will stop. If not specified, the simulation will stop only ath the dead of a philosopher.



