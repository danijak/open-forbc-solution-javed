####################################################################################################################
#  __     __   __     ______   ______     ______     ______     ______     ______   ______  
# /\ \   /\ "-.\ \   /\__  _\ /\  ___\   /\  == \   /\  ___\   /\  ___\   /\  == \ /\__  _\ 
# \ \ \  \ \ \-.  \  \/_/\ \/ \ \  __\   \ \  __<   \ \___  \  \ \  __\   \ \  _-/ \/_/\ \/ 
#  \ \_\  \ \_\\"\_\    \ \_\  \ \_____\  \ \_\ \_\  \/\_____\  \ \_____\  \ \_\      \ \_\ 
#   \/_/   \/_/ \/_/     \/_/   \/_____/   \/_/ /_/   \/_____/   \/_____/   \/_/       \/_/ 
#
# Create a python script that, given the following inputs (as strings!):
#   1. ["11, 9, 38, 16, 75, 2, 8, 23",  "9, 83, 52, 8, 24, 11, 103"]
#   2. ["5, 78, 23, 4, 9, 0, 36, 1", "77, 33, 26, 0, 5, 19, 44"]
#
# Answers:
#   1. [9, 11, 8]
#   2. [5, 0]
#
# The solution must work for any input generated by the following code (the random_input variable):
#     a = [str(random.randint(0,100)) for i in range(0, random.randint(5, 15))]
#     b = [str(random.randint(0,100)) for i in range(0, random.randint(5, 15))]
#     random_input = '['+'"'+', '.join(a)+'"'+', '+'"'+', '.join(b)+'"'+']'
#
####################################################################################################################
# Dependencies
import random
import numpy as np
import ast

a = [str(random.randint(0,100)) for i in range(0, random.randint(5, 15))]
b = [str(random.randint(0,100)) for i in range(0, random.randint(5, 15))]
random_input = '['+'"'+', '.join(a)+'"'+', '+'"'+', '.join(b)+'"'+']'

random_input=ast.literal_eval(random_input)
print("Input is:" +str(random_input))

input_array1=[ int(n) for n in random_input[0].split(',') if n != ' ' ]
input_array2=[ int(n) for n in random_input[1].split(',') if n != ' ' ]

C = np.array([i for i in input_array1 if i in input_array2])
  
# Common values between two arrays 
if (C.size!=0):
    print("Common elements are :"+str(C))
else:
    print("No common elements")