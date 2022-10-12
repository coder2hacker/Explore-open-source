# Part 1
from pprint import pprint
import numpy as np


def light_on_or_off(messages):
    arr = np.zeros((1000, 1000), dtype=bool)
    for message in messages.split("\n"):
        first, second = list(map(lambda s: s.strip(), message.split("through")))
        a, b = map(lambda x: int(x), (first.split(" ")[-1]).split(","))
        c, d = map(lambda x: int(x), (second.split(",")))

        instructions = " ".join(first.split(" ")[:-1])
        if instructions == 'turn on':
            arr[a:c + 1, b:d + 1] = True
        elif instructions == 'turn off':
            arr[a:c + 1, b:d + 1] = False
        else:
            arr[a:c + 1, b:d + 1] = np.invert(arr[a:c + 1, b:d + 1])
    return np.sum(arr)

# Part 2
def light_on_or_off_2(messages):
    arr = np.zeros((1000, 1000), dtype=int)
    for message in messages.split("\n"):
        first, second = list(map(lambda s: s.strip(), message.split("through")))
        a, b = map(lambda x: int(x), (first.split(" ")[-1]).split(","))
        c, d = map(lambda x: int(x), (second.split(",")))

        instructions = " ".join(first.split(" ")[:-1])
        if instructions == 'turn on':
            arr[a:c + 1, b:d + 1] += 1
        elif instructions == 'turn off':
            arr[a:c + 1, b:d + 1] -= 1
            arr[arr < 0] = 0
        else:
            arr[a:c + 1, b:d + 1] += 2
    return np.sum(arr)