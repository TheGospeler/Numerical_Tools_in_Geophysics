import numpy as np

def rk_2nd_order(function, init, no_of_steps, upper_limit, lower_limit):
    """ The function returns the second order derivative and the array that stores
        the xpoint, current_f, and current_g for the iterations"""
    
     
    #initial conditions
    initial_func, initial_gfunc = init
    h = (upper_limit - lower_limit) / (no_of_steps*1.0)
    
    # list to store variables
    current_func = []
    current_gfunc= []
    x_list = []
   
    
    step_points = no_of_steps
    
    for step_point in range(1, step_points+1, 1):
        x = lower_limit+h*(step_point-1)
        xi = lower_limit+h*(step_point)
        mid = h/2
        
        # where L and K represents the stepping methods for the first and second ODE
        Lo = h*function(x, initial_func, initial_gfunc)
        Ko = h*initial_gfunc
        
        L1 = h*function(x+mid, initial_func+Ko/2.0, initial_gfunc+Lo/2.0)
        K1 = h*(initial_gfunc + Lo/2.0)
        
        L2 = h*function(x+mid, initial_func+K1/2.0, initial_gfunc+L1/2.0)
        K2 = h*(initial_gfunc + L1/2.0)
        
        L3 = h*function(xi, initial_func+K2, initial_gfunc+L2)
        K3 = h*(initial_gfunc + L2)
        
        current_g = initial_gfunc + (Lo + 2*L1 +2*L2 + L3)/6.0
        current_f = initial_func + (Ko + 2*K1 +2*K2 + K3)/6.0
        
        x_list.append(x)
        current_func.append(current_f)
        current_gfunc.append(current_g)
        
        #update the initial first and second order function
        initial_func = current_f
        initial_gfunc = current_g
        
    # array that stores the information
    x_list = np.array(x_list).reshape(-1, 1)
    current_func = np.array(current_func).reshape(-1, 1)
    current_gfunc = np.array(current_gfunc).reshape(-1, 1)
    
    # combine the arrays together to get a nrow x 3 array
    curr_array = np.hstack((x_list, current_func, current_gfunc))
    
    return initial_func, curr_array