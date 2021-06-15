# Hardware-Based Protection in Practice - Hands-on

In this assignment, we protect the given smart electricity meter application via enclave-based security.
You can find the implementation in `smart_meter.cpp`.

The meter's counter shall not be modified by any other processes, but the meter program.
In the lecture, you learned about *enclave-based protection*.
Here, we use the Google [Asylo](https://asylo.dev/) framework for implementing enclave-based security.
Asylo simplifies the development of enclave-based applications by providing a set of intuitive (high-level) functions for creating and using enclaves.
Moreover, the Asylo framework is hardware agnostic, i.e., a program written in Asylo can be compiled to run on arbitrary secure hardware.
As of now, Asylo supports both software simulated enclaves as well as Intel SGX.
To switch between arbitrary hardware, users merely need to configure the backend hardware upon compilation.
You can use the simulated enclave backend to solve this exercise.

1. Bring yourself up to speed with Asylo by following the [getting started guide](https://asylo.dev/docs/guides/quickstart.html).
2. Port the smart meter class into Asylo framework fulfilling the following goals:
    1. The counter value shall be protected all the time
    2. Any functions that manipulate the counter value shall be protected against tampering attacks
3. Implement a client program that uses your protected SmartMeter class by:
    1. Triggering the `meterUsageCycle` function;
    and
    2. Displaying the counter value
4. Explain which attacks **cannot** be implemented anymore, i.e., what enclave protection guarantees in the sample system.
5. Enumerate and briefly discuss possible threats against your enclave-protected smart meter that (for example) jeopardize/undermine/manipulate the reading and represent the steps needed to carry out this attack using an ADT.
