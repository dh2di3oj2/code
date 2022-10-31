# write a function roller that takes two inputs:a number of a 6 sided die and an interger of points to meet or exceed it should use 6. simulate rolling and reutnr three items: an array of the vlaue of each die. an interggre with the sume of those values and a boolen indicatin fi the sum  of the values met or excereded the nbumber of points specifed.


def roller(n, points):
    import random

    dice = []
    sum = 0
    for i in range(n):
        dice.append(random.randint(1, 6))
        sum += dice[i]
    if sum >= points:
        return dice, sum, True
    else:
        return dice, sum, False


print(roller(3, 15))
