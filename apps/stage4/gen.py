#!/usr/bin/env python3

import random
import sys

flag = "34C3_1_d0_m4th"

for c in flag:
    coefficients = []
    for c2 in flag:
        coefficients.append(random.randint(-100, 100))

    total = 0
    for i, coeff in enumerate(coefficients):
        sys.stdout.write("({} * flag[{}]) ".format(coeff, i))
        total += (ord(flag[i]) * coeff)

        if i != len(flag)-1:
            sys.stdout.write("+ ")
        else:
            sys.stdout.write("== {} &&".format(total))

    sys.stdout.write("\n")

