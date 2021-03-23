# philosophers

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/javrodri/Philosophers)](https://github.com/JaeSeoKim/badge42)

## Common rules: 
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
	* __number-of-philosophers:__ _The number of philosophers and also the number of forks_
	* __time-to-die:__ _In miliseconds, if a philo doesn't start eating 'time-to-die' miliseconds after starting his last meal or the beginning of the simulation, it dies._
	* __time-to-eat:__ _Is in miliseconds, and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks._
	* __time-to-sleep:__ _Miliseconds and is the time the philosopher will spend sleeping._
	* __number-of-times-each-philosopher-must-eat:__ _Argument is optional, if all philosophers eat at least the argument number, the simulation will stop. If not specified, the simulation will stop only ath the dead of a philosopher._
* Each philosopher should given a number from 1 to 'number-of-philosphers'.
* Philosopher number 1 is next to philosopher number ’number-of-philosophers’. Any other philosopher with number N is seated between philosopher N - 1 and philosopher N + 1.
* Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp-in-ms the current timestamp in milliseconds)
	* timestamp-in-ms X has taken a fork
	* timestamp-in-ms X is eating
	* timestamp-in-ms X is sleeping
	* timestamp-in-ms X is thinking
	* timestamp-in-ms X died
* The status printed should not be scrambled or intertwined with another philosopher’s status.
* You can’t have more than 10 ms between the death of a philosopher and when it will print its death.
* Again, philosophers should avoid to die!

### Philo-one
__philosopher with thread and mutex__

* One fork between each philosopher, therefore there will be a fork at the right and at the left of each philosopher.
* To avoid philosophers duplicating forks, you should protect the forks state with a mutex for each of them.
* Each philosopher should be a thread.
