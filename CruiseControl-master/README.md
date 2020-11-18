## OS and Tools for Assignment
Linux Mint64 on VirtualBox and Visual Studio Code with Matlab,Python linting
## Run instructions for GUI simulator
The instructions to run the simulator are taken from esterelLab1.pdf on canvas
On the terminal do:

1) cd CruiseControl/
2) make cruise.xes
3) ./cruise.xes

or alternatively do:
1) cd CruiseControl/
2) ./command.sh


## Run instructions for CLI simulator
The instructions are taken from the manual found in the installation path for esterel v6
i.e esterelv6_01/doc/manual.pdf and adopted for our use case. (Section 7.2) contains commands for viewing the same information as the GUI simulator

1) cd CruiseControl/autoTester/
2) ./autoTest.sh

## Run instructions for Test Suite
A python script was developed to use the CLI simulator to make testing for our design easier.
### Note:- Python version 3.x is needed. Vectors.in has the test cases provided from canvas as well as our own test cases. Vectors.out contains the expected outputs for the testcases.

1) cd CruiseControl/autoTester/
2) python3 autoTest.py
3) Press 2 for running all tests or 1 for interactive mode(One test at a time)

