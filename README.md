# Numerical_Tools_in_Geophysics
This repository  contains my codes written in the projects and homework for GLG 892 
(Numerical Tools in Earth and Environmental Sciences **recently renamed to** Special Problems 
in Geophysics and Geodynamics).

The repository contains written codes for the Repeated rectangle rule, Repeated Simpson's Rule, Error Function, 
Double Simpson's Rule, Ordinary Differential Equations, and Finite Derivatives.

The course activities were written in C programming language, but I was interested in
*transcribing* from C to Python program, which I completed.

Simpson's rule is efficient in solving any differential equations (or Numerical Integration),
most especially when the differential equation doesn't have an analytical solution or its 
very difficult to solve analytically.


#### Simpson's Equation
![image](https://user-images.githubusercontent.com/97548163/207664523-7882b9fb-4762-4d63-be8b-55ddd71d58fe.png)


#### Error Function
A common integral that comes up in many physical problems including geophysical problems
(e.g., half-space cooling of oceanic lithosphere), is the following:
$$\int e^{-s^2}$$
$e^{-s^2}$ is called the Gaussian function, and when integrated from minus infinity to plus 
infinity, it is called the Gaussian integral.

The **Error Function** therefore is:
$$erf(x) = \frac{2}{\pi} \int_0^x e^{-s^2}$$.

There is no known analytial solution to this important integral, and its solution must hence
be calculated numeriacally.
**Interestingly, the numerical solution to this important formula is presented in C and Python 
Programming Language😇😇**

#### Double Integration Using Simpson's Rule:
![image](https://user-images.githubusercontent.com/97548163/207669384-320fb6c1-0801-41fb-8685-4145361ef71d.png)

##### Also, feel free to Checkout the ODEs 
