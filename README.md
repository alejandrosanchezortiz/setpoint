# Compile

g++ -o setpoint *.cpp

# Execution

setpoint    -> show a few examples with all the setups  
setpoint 1  -> setup 1, request P and D to calculate the setpoint  
setpoint 2  -> setup 3, request D to calculate the setpoint  
setpoint 3  -> setup 4, request P, G and B to calculate the setpoint  

# Arguments

**P** = Photovoltaics as watts  
**C** = consumption as watts  
**D** = combination of photovoltaics and consumption  
**G** = grid metter as watts  
**B** = output/input power of battery storage as watts  

# Exercice 1: Setup 1

As stated in the exercise description the setpoint value is: P - C  
So the required function needs just two parameters P and C.

# Exercise 2: Setup 3

In this setup we measure P and D, but not C.  
Actually D = P - C, so this time the setpoint is D, no need for calculation. 

# Exercise 3: Setup 4

In this setup we measure P and G, but we also need B for the calculation. B is an available value as stated in the exercise.  

As P - C + G + B = 0, then we can calculate C = P + G + B  

An the setpoint again is P - C, unless G > 0. Because if G is greater than zero means that we are buying from the grid and the battery is empty. We must buy from the grid only if the battery is empty and for consumption only, never to charge the battery.  
On the other side, if B > 0 means that we are not buying from the grid, as we do it only when the battery is empty.  
