from itertools import groupby


def look_and_say(data, iterations):
    new_data = "".join(["".join([str(len(list(j))), i]) for i, j in groupby(data)])
    if iterations == 1:
        return len(new_data)
    else:
        return look_and_say(new_data, iterations - 1)


# Part 1
# print(look_and_say('3113322113', 40))  # 329356

# Part 2
print(look_and_say('3113322113', 50))  #
