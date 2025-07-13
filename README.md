# Fero on Arduino Demo

This is a set of small demonstration projects to evaluate the feasibility of creating a TASTE Runtime for Arduino using Fero cyclic executive.
The projects are created by:
<li>creating a TASTE project with some features of interest;
<li>generating code for TASTE Leon3 Runtime (which is structurally closest...);
<li>manually porting the generated code from RTEMS to Fero.

Fero has been selected because it is small and does not utilize stack, reducing RAM usage.
The cost is lack of preemption, however, in most cases, this leaves the TASTE system still fully functional.
